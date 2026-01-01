#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8003C530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80044630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004463C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80044640: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80044644: beql        $t6, $zero, L_800446A8
    if (ctx->r14 == 0) {
        // 0x80044648: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800446A8;
    }
    goto skip_0;
    // 0x80044648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004464C: jal         0x80036A30
    // 0x80044650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x80044650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80044654: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044658: beq         $v0, $zero, L_800446A4
    if (ctx->r2 == 0) {
        // 0x8004465C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800446A4;
    }
    // 0x8004465C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80044660: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80044664: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80044668: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8004466C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80044670: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80044674: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80044678: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8004467C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80044680: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80044684: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x80044688: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004468C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80044690: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x80044694: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x80044698: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8004469C: jalr        $t9
    // 0x800446A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800446A0: nop

    after_1:
L_800446A4:
    // 0x800446A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800446A8:
    // 0x800446A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800446AC: jr          $ra
    // 0x800446B0: nop

    return;
    // 0x800446B0: nop

    // 0x800446B4: nop

    // 0x800446B8: nop

    // 0x800446BC: nop

;}
RECOMP_FUNC void func_80026434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026434: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80026438: addiu       $v1, $v1, 0x398C
    ctx->r3 = ADD32(ctx->r3, 0X398C);
    // 0x8002643C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80026440: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80026444: bne         $t6, $zero, L_80026460
    if (ctx->r14 != 0) {
        // 0x80026448: nop
    
            goto L_80026460;
    }
    // 0x80026448: nop

    // 0x8002644C: lw          $t7, 0x3990($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3990);
    // 0x80026450: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x80026454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026458: beq         $t7, $zero, L_80026468
    if (ctx->r15 == 0) {
        // 0x8002645C: nop
    
            goto L_80026468;
    }
    // 0x8002645C: nop

L_80026460:
    // 0x80026460: jr          $ra
    // 0x80026464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80026464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80026468:
    // 0x80026468: divu        $zero, $t8, $a0
    lo = S32(U32(ctx->r24) / U32(ctx->r4)); hi = S32(U32(ctx->r24) % U32(ctx->r4));
    // 0x8002646C: mflo        $t9
    ctx->r25 = lo;
    // 0x80026470: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80026474: bne         $a0, $zero, L_80026480
    if (ctx->r4 != 0) {
        // 0x80026478: nop
    
            goto L_80026480;
    }
    // 0x80026478: nop

    // 0x8002647C: break       7
    do_break(2147640444);
L_80026480:
    // 0x80026480: jr          $ra
    // 0x80026484: nop

    return;
    // 0x80026484: nop

;}
RECOMP_FUNC void func_800174B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800174B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800174BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800174C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800174C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800174C8: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x800174CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800174D0: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x800174D4: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800174D8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800174DC: ori         $t7, $t6, 0x400
    ctx->r15 = ctx->r14 | 0X400;
    // 0x800174E0: beq         $a0, $at, L_8001750C
    if (ctx->r4 == ctx->r1) {
        // 0x800174E4: sh          $t7, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r15;
            goto L_8001750C;
    }
    // 0x800174E4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800174E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800174EC: beq         $a0, $at, L_80017524
    if (ctx->r4 == ctx->r1) {
        // 0x800174F0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80017524;
    }
    // 0x800174F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800174F4: beq         $a0, $at, L_80017540
    if (ctx->r4 == ctx->r1) {
        // 0x800174F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80017540;
    }
    // 0x800174F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800174FC: beql        $a0, $at, L_80017560
    if (ctx->r4 == ctx->r1) {
        // 0x80017500: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_80017560;
    }
    goto skip_0;
    // 0x80017500: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80017504: b           L_80017574
    // 0x80017508: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
        goto L_80017574;
    // 0x80017508: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_8001750C:
    // 0x8001750C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80017510: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x80017514: lhu         $t9, 0xE($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XE);
    // 0x80017518: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8001751C: b           L_80017570
    // 0x80017520: sh          $t0, 0x88($t1)
    MEM_H(0X88, ctx->r9) = ctx->r8;
        goto L_80017570;
    // 0x80017520: sh          $t0, 0x88($t1)
    MEM_H(0X88, ctx->r9) = ctx->r8;
L_80017524:
    // 0x80017524: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80017528: lw          $t5, 0x68($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X68);
    // 0x8001752C: lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XE);
    // 0x80017530: sra         $t3, $v0, 2
    ctx->r11 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80017534: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x80017538: b           L_80017570
    // 0x8001753C: sh          $t4, 0x88($t5)
    MEM_H(0X88, ctx->r13) = ctx->r12;
        goto L_80017570;
    // 0x8001753C: sh          $t4, 0x88($t5)
    MEM_H(0X88, ctx->r13) = ctx->r12;
L_80017540:
    // 0x80017540: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80017544: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80017548: lhu         $v0, 0xE($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XE);
    // 0x8001754C: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80017550: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80017554: b           L_80017570
    // 0x80017558: sh          $t8, 0x88($t9)
    MEM_H(0X88, ctx->r25) = ctx->r24;
        goto L_80017570;
    // 0x80017558: sh          $t8, 0x88($t9)
    MEM_H(0X88, ctx->r25) = ctx->r24;
    // 0x8001755C: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_80017560:
    // 0x80017560: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x80017564: lhu         $t1, 0xE($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XE);
    // 0x80017568: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8001756C: sh          $t2, 0x88($t3)
    MEM_H(0X88, ctx->r11) = ctx->r10;
L_80017570:
    // 0x80017570: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_80017574:
    // 0x80017574: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x80017578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001757C: lhu         $t5, 0xE($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0XE);
    // 0x80017580: lhu         $t7, 0x88($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X88);
    // 0x80017584: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80017588: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001758C: beq         $at, $zero, L_8001759C
    if (ctx->r1 == 0) {
        // 0x80017590: nop
    
            goto L_8001759C;
    }
    // 0x80017590: nop

    // 0x80017594: b           L_8001759C
    // 0x80017598: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8001759C;
    // 0x80017598: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8001759C:
    // 0x8001759C: jal         0x8001FCF8
    // 0x800175A0: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x800175A0: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    after_0:
    // 0x800175A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800175A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800175AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800175B0: jr          $ra
    // 0x800175B4: nop

    return;
    // 0x800175B4: nop

;}
RECOMP_FUNC void func_800368E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800368E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800368E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800368E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800368EC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800368F0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800368F4: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800368F8: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800368FC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80036900: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80036904: jal         0x8003FE6C
    // 0x80036908: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80036908: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8003690C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036910: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80036914: jr          $ra
    // 0x80036918: nop

    return;
    // 0x80036918: nop

    // 0x8003691C: nop

;}
RECOMP_FUNC void func_8000600C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000600C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006014: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80006018: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000601C: lhu         $v0, 0x62($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X62);
    // 0x80006020: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006024: sra         $t7, $v0, 6
    ctx->r15 = S32(SIGNED(ctx->r2) >> 6);
    // 0x80006028: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8000602C: beql        $t8, $zero, L_800060C8
    if (ctx->r24 == 0) {
        // 0x80006030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800060C8;
    }
    goto skip_0;
    // 0x80006030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80006034: beq         $t8, $at, L_8000604C
    if (ctx->r24 == ctx->r1) {
        // 0x80006038: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000604C;
    }
    // 0x80006038: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000603C: beql        $t8, $at, L_80006080
    if (ctx->r24 == ctx->r1) {
        // 0x80006040: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80006080;
    }
    goto skip_1;
    // 0x80006040: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_1:
    // 0x80006044: b           L_800060C8
    // 0x80006048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800060C8;
    // 0x80006048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000604C:
    // 0x8000604C: lhu         $v0, 0x124($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X124);
    // 0x80006050: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006054: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80006058: bnel        $v0, $zero, L_80006074
    if (ctx->r2 != 0) {
        // 0x8000605C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80006074;
    }
    goto skip_2;
    // 0x8000605C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    skip_2:
    // 0x80006060: jal         0x80006BEC
    // 0x80006064: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80006BEC(rdram, ctx);
        goto after_0;
    // 0x80006064: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80006068: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000606C: lhu         $v0, 0x124($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X124);
    // 0x80006070: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_80006074:
    // 0x80006074: b           L_800060C4
    // 0x80006078: sh          $t9, 0x124($a3)
    MEM_H(0X124, ctx->r7) = ctx->r25;
        goto L_800060C4;
    // 0x80006078: sh          $t9, 0x124($a3)
    MEM_H(0X124, ctx->r7) = ctx->r25;
    // 0x8000607C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80006080:
    // 0x80006080: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80006084: lwc1        $f4, 0x2C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x80006088: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8000608C: lwc1        $f10, 0x34($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80006090: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80006094: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80006098: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8000609C: mul.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800060A0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800060A4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800060A8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800060AC: lwc1        $f8, 0x20($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X20);
    // 0x800060B0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800060B4: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    // 0x800060B8: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800060BC: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
    // 0x800060C0: swc1        $f10, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f10.u32l;
L_800060C4:
    // 0x800060C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800060C8:
    // 0x800060C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800060CC: jr          $ra
    // 0x800060D0: nop

    return;
    // 0x800060D0: nop

;}
RECOMP_FUNC void func_80018B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018B14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80018B18: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018B1C: addiu       $v0, $v0, 0x7208
    ctx->r2 = ADD32(ctx->r2, 0X7208);
    // 0x80018B20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80018B24: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80018B28: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80018B2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80018B30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80018B34: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80018B38: lw          $t6, 0x7200($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7200);
    // 0x80018B3C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80018B40: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80018B44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80018B48: lw          $t7, -0x4D0C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D0C);
    // 0x80018B4C: addiu       $s0, $s0, 0x7310
    ctx->r16 = ADD32(ctx->r16, 0X7310);
    // 0x80018B50: addiu       $s3, $zero, 0x19
    ctx->r19 = ADD32(0, 0X19);
    // 0x80018B54: beq         $t7, $zero, L_80018B68
    if (ctx->r15 == 0) {
        // 0x80018B58: lui         $s2, 0x8005
        ctx->r18 = S32(0X8005 << 16);
            goto L_80018B68;
    }
    // 0x80018B58: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x80018B5C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80018B60: b           L_80018B68
    // 0x80018B64: addiu       $s0, $s0, 0x7250
    ctx->r16 = ADD32(ctx->r16, 0X7250);
        goto L_80018B68;
    // 0x80018B64: addiu       $s0, $s0, 0x7250
    ctx->r16 = ADD32(ctx->r16, 0X7250);
L_80018B68:
    // 0x80018B68: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x80018B6C: addiu       $s2, $s2, -0x3154
    ctx->r18 = ADD32(ctx->r18, -0X3154);
    // 0x80018B70: beql        $s1, $zero, L_80018BD8
    if (ctx->r17 == 0) {
        // 0x80018B74: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80018BD8;
    }
    goto skip_0;
    // 0x80018B74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80018B78:
    // 0x80018B78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80018B7C: beq         $v0, $zero, L_80018BC8
    if (ctx->r2 == 0) {
        // 0x80018B80: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80018BC8;
    }
    // 0x80018B80: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80018B84: bne         $t8, $zero, L_80018BC8
    if (ctx->r24 != 0) {
        // 0x80018B88: sw          $t8, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r24;
            goto L_80018BC8;
    }
    // 0x80018B88: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80018B8C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80018B90: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80018B94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80018B98: swc1        $f4, -0x313C($at)
    MEM_W(-0X313C, ctx->r1) = ctx->f4.u32l;
    // 0x80018B9C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80018BA0: swc1        $f6, -0x3138($at)
    MEM_W(-0X3138, ctx->r1) = ctx->f6.u32l;
    // 0x80018BA4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018BA8: swc1        $f8, -0x3134($at)
    MEM_W(-0X3134, ctx->r1) = ctx->f8.u32l;
    // 0x80018BAC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018BB0: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80018BB4: swc1        $f10, -0x3128($at)
    MEM_W(-0X3128, ctx->r1) = ctx->f10.u32l;
    // 0x80018BB8: lwc1        $f16, -0x3128($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3128);
    // 0x80018BBC: jal         0x8001B108
    // 0x80018BC0: swc1        $f16, -0x312C($at)
    MEM_W(-0X312C, ctx->r1) = ctx->f16.u32l;
    func_8001B108(rdram, ctx);
        goto after_0;
    // 0x80018BC0: swc1        $f16, -0x312C($at)
    MEM_W(-0X312C, ctx->r1) = ctx->f16.u32l;
    after_0:
    // 0x80018BC4: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
L_80018BC8:
    // 0x80018BC8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80018BCC: bne         $s1, $zero, L_80018B78
    if (ctx->r17 != 0) {
        // 0x80018BD0: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80018B78;
    }
    // 0x80018BD0: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80018BD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80018BD8:
    // 0x80018BD8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80018BDC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80018BE0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80018BE4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80018BE8: jr          $ra
    // 0x80018BEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80018BEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80036384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036384: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036388: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003638C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036390: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80036394: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80036398: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8003639C: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x800363A0: addiu       $a0, $a0, 0x6360
    ctx->r4 = ADD32(ctx->r4, 0X6360);
    // 0x800363A4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800363A8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800363AC: jal         0x8003F4D0
    // 0x800363B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x800363B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x800363B4: bltz        $v0, L_800363C8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800363B8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800363C8;
    }
    // 0x800363B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800363BC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800363C0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800363C4: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_800363C8:
    // 0x800363C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800363CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800363D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800363D4: jr          $ra
    // 0x800363D8: nop

    return;
    // 0x800363D8: nop

    // 0x800363DC: nop

;}
RECOMP_FUNC void func_80025B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B8C: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80025B90: addiu       $a3, $a3, 0x3970
    ctx->r7 = ADD32(ctx->r7, 0X3970);
    // 0x80025B94: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80025B98: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025B9C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80025BA0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80025BA4: sw          $a0, 0x390C($at)
    MEM_W(0X390C, ctx->r1) = ctx->r4;
    // 0x80025BA8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025BAC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80025BB0: sw          $a1, 0x392C($at)
    MEM_W(0X392C, ctx->r1) = ctx->r5;
    // 0x80025BB4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025BB8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80025BBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80025BC0: sw          $a2, 0x394C($at)
    MEM_W(0X394C, ctx->r1) = ctx->r6;
    // 0x80025BC4: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x80025BC8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80025BCC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80025BD0: jr          $ra
    // 0x80025BD4: sw          $v0, -0x34C($at)
    MEM_W(-0X34C, ctx->r1) = ctx->r2;
    return;
    // 0x80025BD4: sw          $v0, -0x34C($at)
    MEM_W(-0X34C, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80030668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030668: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x8003066C: addiu       $t2, $t2, -0x608
    ctx->r10 = ADD32(ctx->r10, -0X608);
    // 0x80030670: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80030674: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80030678: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003067C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80030680: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030684: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030688: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003068C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80030690: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80030694: lh          $v1, 0x618($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X618);
    // 0x80030698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003069C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800306A0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800306A4: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x800306A8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800306AC: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x800306B0: blez        $v1, L_80030740
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800306B4: sh          $t8, 0x6($t2)
        MEM_H(0X6, ctx->r10) = ctx->r24;
            goto L_80030740;
    }
    // 0x800306B4: sh          $t8, 0x6($t2)
    MEM_H(0X6, ctx->r10) = ctx->r24;
    // 0x800306B8: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x800306BC: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800306C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800306C4: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800306C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800306CC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800306D0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x800306D4: addiu       $t4, $t4, 0x5E0
    ctx->r12 = ADD32(ctx->r12, 0X5E0);
    // 0x800306D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800306DC: addu        $a3, $t9, $t4
    ctx->r7 = ADD32(ctx->r25, ctx->r12);
    // 0x800306E0: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800306E4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800306E8:
    // 0x800306E8: lbu         $t5, 0x3C($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X3C);
    // 0x800306EC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800306F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800306F4: beq         $t3, $t5, L_80030728
    if (ctx->r11 == ctx->r13) {
        // 0x800306F8: subu        $t6, $t6, $a1
        ctx->r14 = SUB32(ctx->r14, ctx->r5);
            goto L_80030728;
    }
    // 0x800306F8: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800306FC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030700: addu        $a0, $a3, $t6
    ctx->r4 = ADD32(ctx->r7, ctx->r14);
    // 0x80030704: lbu         $t1, 0x3C($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3C);
    // 0x80030708: slti        $at, $t1, 0x80
    ctx->r1 = SIGNED(ctx->r9) < 0X80 ? 1 : 0;
L_8003070C:
    // 0x8003070C: beql        $at, $zero, L_8003071C
    if (ctx->r1 == 0) {
        // 0x80030710: lbu         $t1, 0x3D($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X3D);
            goto L_8003071C;
    }
    goto skip_0;
    // 0x80030710: lbu         $t1, 0x3D($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3D);
    skip_0:
    // 0x80030714: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80030718: lbu         $t1, 0x3D($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3D);
L_8003071C:
    // 0x8003071C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80030720: bnel        $t3, $t1, L_8003070C
    if (ctx->r11 != ctx->r9) {
        // 0x80030724: slti        $at, $t1, 0x80
        ctx->r1 = SIGNED(ctx->r9) < 0X80 ? 1 : 0;
            goto L_8003070C;
    }
    goto skip_1;
    // 0x80030724: slti        $at, $t1, 0x80
    ctx->r1 = SIGNED(ctx->r9) < 0X80 ? 1 : 0;
    skip_1:
L_80030728:
    // 0x80030728: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8003072C: beq         $at, $zero, L_80030738
    if (ctx->r1 == 0) {
        // 0x80030730: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80030738;
    }
    // 0x80030730: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80030734: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80030738:
    // 0x80030738: bne         $a1, $v1, L_800306E8
    if (ctx->r5 != ctx->r3) {
        // 0x8003073C: addiu       $t0, $t0, 0x18
        ctx->r8 = ADD32(ctx->r8, 0X18);
            goto L_800306E8;
    }
    // 0x8003073C: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
L_80030740:
    // 0x80030740: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80030744: addiu       $t8, $t7, 0x1C
    ctx->r24 = ADD32(ctx->r15, 0X1C);
    // 0x80030748: sh          $t8, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r24;
    // 0x8003074C: jr          $ra
    // 0x80030750: nop

    return;
    // 0x80030750: nop

;}
RECOMP_FUNC void func_8001A398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A398: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001A39C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001A3A0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001A3A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001A3A8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001A3AC: addiu       $s1, $s1, -0x4D04
    ctx->r17 = ADD32(ctx->r17, -0X4D04);
    // 0x8001A3B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A3B4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001A3B8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001A3BC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001A3C0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001A3C4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001A3C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001A3CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A3D0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A3D4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8001A3D8: addiu       $t8, $t8, -0x41F8
    ctx->r24 = ADD32(ctx->r24, -0X41F8);
    // 0x8001A3DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001A3E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8001A3E4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8001A3E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001A3EC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001A3F0: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x8001A3F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A3F8: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001A3FC: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x8001A400: sh          $t9, -0x7C18($at)
    MEM_H(-0X7C18, ctx->r1) = ctx->r25;
    // 0x8001A404: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x8001A408: addiu       $s0, $s0, 0x75A8
    ctx->r16 = ADD32(ctx->r16, 0X75A8);
    // 0x8001A40C: addiu       $s5, $s5, -0x42E4
    ctx->r21 = ADD32(ctx->r21, -0X42E4);
    // 0x8001A410: lui         $fp, 0xB600
    ctx->r30 = S32(0XB600 << 16);
    // 0x8001A414: lui         $s7, 0xB700
    ctx->r23 = S32(0XB700 << 16);
    // 0x8001A418: lui         $s6, 0xFB00
    ctx->r22 = S32(0XFB00 << 16);
    // 0x8001A41C: addiu       $s3, $zero, 0x2000
    ctx->r19 = ADD32(0, 0X2000);
L_8001A420:
    // 0x8001A420: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x8001A424: beql        $t0, $zero, L_8001A5A0
    if (ctx->r8 == 0) {
        // 0x8001A428: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8001A5A0;
    }
    goto skip_0;
    // 0x8001A428: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x8001A42C: jal         0x8001A834
    // 0x8001A430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001A834(rdram, ctx);
        goto after_0;
    // 0x8001A430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001A434: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x8001A438: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8001A43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A440: andi        $t1, $v1, 0x2
    ctx->r9 = ctx->r3 & 0X2;
    // 0x8001A444: beq         $t1, $zero, L_8001A470
    if (ctx->r9 == 0) {
        // 0x8001A448: andi        $t4, $v1, 0x1
        ctx->r12 = ctx->r3 & 0X1;
            goto L_8001A470;
    }
    // 0x8001A448: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x8001A44C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8001A450: lhu         $t2, 0x7204($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X7204);
    // 0x8001A454: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8001A458: beq         $t3, $zero, L_8001A468
    if (ctx->r11 == 0) {
        // 0x8001A45C: nop
    
            goto L_8001A468;
    }
    // 0x8001A45C: nop

    // 0x8001A460: b           L_8001A470
    // 0x8001A464: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
        goto L_8001A470;
    // 0x8001A464: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
L_8001A468:
    // 0x8001A468: b           L_8001A470
    // 0x8001A46C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
        goto L_8001A470;
    // 0x8001A46C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
L_8001A470:
    // 0x8001A470: bne         $t4, $zero, L_8001A49C
    if (ctx->r12 != 0) {
        // 0x8001A474: andi        $t6, $v1, 0x80
        ctx->r14 = ctx->r3 & 0X80;
            goto L_8001A49C;
    }
    // 0x8001A474: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x8001A478: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8001A47C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8001A480: beq         $at, $zero, L_8001A49C
    if (ctx->r1 == 0) {
        // 0x8001A484: nop
    
            goto L_8001A49C;
    }
    // 0x8001A484: nop

    // 0x8001A488: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A48C: mflo        $a1
    ctx->r5 = lo;
    // 0x8001A490: srl         $t5, $a1, 3
    ctx->r13 = S32(U32(ctx->r5) >> 3);
    // 0x8001A494: b           L_8001A4C4
    // 0x8001A498: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
        goto L_8001A4C4;
    // 0x8001A498: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_8001A49C:
    // 0x8001A49C: beql        $t6, $zero, L_8001A4C8
    if (ctx->r14 == 0) {
        // 0x8001A4A0: lhu         $t8, 0x6($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X6);
            goto L_8001A4C8;
    }
    goto skip_1;
    // 0x8001A4A0: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
    skip_1:
    // 0x8001A4A4: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x8001A4A8: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8001A4AC: beql        $at, $zero, L_8001A4C8
    if (ctx->r1 == 0) {
        // 0x8001A4B0: lhu         $t8, 0x6($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X6);
            goto L_8001A4C8;
    }
    goto skip_2;
    // 0x8001A4B0: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
    skip_2:
    // 0x8001A4B4: multu       $v0, $a1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A4B8: mflo        $a1
    ctx->r5 = lo;
    // 0x8001A4BC: srl         $t7, $a1, 3
    ctx->r15 = S32(U32(ctx->r5) >> 3);
    // 0x8001A4C0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8001A4C4:
    // 0x8001A4C4: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
L_8001A4C8:
    // 0x8001A4C8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8001A4CC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001A4D0: addu        $v1, $s5, $t0
    ctx->r3 = ADD32(ctx->r21, ctx->r8);
    // 0x8001A4D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A4D8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8001A4DC: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8001A4E0: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8001A4E4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001A4E8: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x8001A4EC: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x8001A4F0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8001A4F4: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8001A4F8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8001A4FC: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8001A500: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8001A504: andi        $t3, $a1, 0xFF
    ctx->r11 = ctx->r5 & 0XFF;
    // 0x8001A508: or          $t5, $t2, $t3
    ctx->r13 = ctx->r10 | ctx->r11;
    // 0x8001A50C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8001A510: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x8001A514: andi        $t4, $t6, 0x8
    ctx->r12 = ctx->r14 & 0X8;
    // 0x8001A518: beql        $t4, $zero, L_8001A540
    if (ctx->r12 == 0) {
        // 0x8001A51C: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_8001A540;
    }
    goto skip_3;
    // 0x8001A51C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x8001A520: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A524: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001A528: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001A52C: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x8001A530: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8001A534: b           L_8001A550
    // 0x8001A538: nop

        goto L_8001A550;
    // 0x8001A538: nop

    // 0x8001A53C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8001A540:
    // 0x8001A540: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001A544: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8001A548: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x8001A54C: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
L_8001A550:
    // 0x8001A550: jal         0x8001A620
    // 0x8001A554: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_8001A620(rdram, ctx);
        goto after_1;
    // 0x8001A554: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x8001A558: lhu         $t1, 0x0($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X0);
    // 0x8001A55C: lw          $t0, 0x34($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X34);
    // 0x8001A560: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8001A564: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8001A568: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8001A56C: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x8001A570: bne         $t3, $zero, L_8001A590
    if (ctx->r11 != 0) {
        // 0x8001A574: sh          $t2, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r10;
            goto L_8001A590;
    }
    // 0x8001A574: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x8001A578: lhu         $t5, 0x8($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X8);
    // 0x8001A57C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8001A580: beql        $t6, $zero, L_8001A594
    if (ctx->r14 == 0) {
        // 0x8001A584: lhu         $t7, 0x4($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X4);
            goto L_8001A594;
    }
    goto skip_4;
    // 0x8001A584: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    skip_4:
    // 0x8001A588: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x8001A58C: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
L_8001A590:
    // 0x8001A590: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
L_8001A594:
    // 0x8001A594: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8001A598: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x8001A59C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8001A5A0:
    // 0x8001A5A0: bne         $s2, $zero, L_8001A420
    if (ctx->r18 != 0) {
        // 0x8001A5A4: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_8001A420;
    }
    // 0x8001A5A4: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x8001A5A8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A5AC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8001A5B0: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001A5B4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8001A5B8: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x8001A5BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001A5C0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001A5C4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A5C8: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8001A5CC: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x8001A5D0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8001A5D4: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8001A5D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001A5DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8001A5E0: lhu         $t3, 0x7204($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7204);
    // 0x8001A5E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A5E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A5EC: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x8001A5F0: sh          $t5, 0x7204($at)
    MEM_H(0X7204, ctx->r1) = ctx->r13;
    // 0x8001A5F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A5F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A5FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A600: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A604: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A608: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A60C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A610: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A614: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A618: jr          $ra
    // 0x8001A61C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001A61C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80101310_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101310: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80101314: lw          $t6, 0x6250($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6250);
    // 0x80101318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010131C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80101320: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x80101324: bltz        $t7, L_80101330
    if (SIGNED(ctx->r15) < 0) {
        // 0x80101328: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_80101330;
    }
    // 0x80101328: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8010132C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80101330:
    // 0x80101330: addiu       $v0, $v0, 0x62A0
    ctx->r2 = ADD32(ctx->r2, 0X62A0);
    // 0x80101334: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80101338: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x8010133C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80101340: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x80101344: bne         $t9, $zero, L_80101350
    if (ctx->r25 != 0) {
        // 0x80101348: addiu       $a2, $zero, 0x96
        ctx->r6 = ADD32(0, 0X96);
            goto L_80101350;
    }
    // 0x80101348: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8010134C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80101350:
    // 0x80101350: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80101354: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80101358: and         $t1, $t0, $a1
    ctx->r9 = ctx->r8 & ctx->r5;
    // 0x8010135C: bnel        $t1, $zero, L_8010136C
    if (ctx->r9 != 0) {
        // 0x80101360: lw          $t2, 0x50($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X50);
            goto L_8010136C;
    }
    goto skip_0;
    // 0x80101360: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
    skip_0:
    // 0x80101364: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80101368: lw          $t2, 0x50($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X50);
L_8010136C:
    // 0x8010136C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101370: and         $t3, $t2, $a1
    ctx->r11 = ctx->r10 & ctx->r5;
    // 0x80101374: bnel        $t3, $zero, L_80101384
    if (ctx->r11 != 0) {
        // 0x80101378: lw          $t4, 0x50($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X50);
            goto L_80101384;
    }
    goto skip_1;
    // 0x80101378: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
    skip_1:
    // 0x8010137C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80101380: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
L_80101384:
    // 0x80101384: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80101388: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x8010138C: bnel        $t5, $zero, L_8010139C
    if (ctx->r13 != 0) {
        // 0x80101390: lw          $t6, 0x50($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X50);
            goto L_8010139C;
    }
    goto skip_2;
    // 0x80101390: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    skip_2:
    // 0x80101394: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80101398: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
L_8010139C:
    // 0x8010139C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x801013A0: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x801013A4: bne         $t7, $zero, L_801013B0
    if (ctx->r15 != 0) {
        // 0x801013A8: nop
    
            goto L_801013B0;
    }
    // 0x801013A8: nop

    // 0x801013AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_801013B0:
    // 0x801013B0: bne         $v1, $a2, L_80101350
    if (ctx->r3 != ctx->r6) {
        // 0x801013B4: addiu       $v0, $v0, 0x50
        ctx->r2 = ADD32(ctx->r2, 0X50);
            goto L_80101350;
    }
    // 0x801013B4: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x801013B8: jr          $ra
    // 0x801013BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x801013BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8001A834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A834: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8001A838: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8001A83C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A844: beq         $t6, $zero, L_8001B028
    if (ctx->r14 == 0) {
        // 0x8001A848: addiu       $v1, $v1, -0x4D04
        ctx->r3 = ADD32(ctx->r3, -0X4D04);
            goto L_8001B028;
    }
    // 0x8001A848: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8001A84C: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x8001A850: addiu       $t3, $a0, 0x44
    ctx->r11 = ADD32(ctx->r4, 0X44);
    // 0x8001A854: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8001A858: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x8001A85C: beql        $t8, $zero, L_8001A86C
    if (ctx->r24 == 0) {
        // 0x8001A860: lh          $t9, 0xC($t3)
        ctx->r25 = MEM_H(ctx->r11, 0XC);
            goto L_8001A86C;
    }
    goto skip_0;
    // 0x8001A860: lh          $t9, 0xC($t3)
    ctx->r25 = MEM_H(ctx->r11, 0XC);
    skip_0:
    // 0x8001A864: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x8001A868: lh          $t9, 0xC($t3)
    ctx->r25 = MEM_H(ctx->r11, 0XC);
L_8001A86C:
    // 0x8001A86C: lh          $t6, 0x10($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X10);
    // 0x8001A870: lh          $t8, 0xE($t3)
    ctx->r24 = MEM_H(ctx->r11, 0XE);
    // 0x8001A874: lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X0);
    // 0x8001A878: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8001A87C: lh          $t9, 0x12($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X12);
    // 0x8001A880: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
    // 0x8001A884: sh          $t7, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r15;
    // 0x8001A888: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8001A88C: sh          $t6, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r14;
    // 0x8001A890: beq         $v1, $zero, L_8001A8A0
    if (ctx->r3 == 0) {
        // 0x8001A894: lw          $t4, 0x8($t3)
        ctx->r12 = MEM_W(ctx->r11, 0X8);
            goto L_8001A8A0;
    }
    // 0x8001A894: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8001A898: b           L_8001A8A0
    // 0x8001A89C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
        goto L_8001A8A0;
    // 0x8001A89C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
L_8001A8A0:
    // 0x8001A8A0: beq         $v1, $zero, L_8001A8B4
    if (ctx->r3 == 0) {
        // 0x8001A8A4: andi        $t9, $v0, 0x4
        ctx->r25 = ctx->r2 & 0X4;
            goto L_8001A8B4;
    }
    // 0x8001A8A4: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8001A8A8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8001A8AC: b           L_8001A8BC
    // 0x8001A8B0: sw          $t7, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r15;
        goto L_8001A8BC;
    // 0x8001A8B0: sw          $t7, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r15;
L_8001A8B4:
    // 0x8001A8B4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8001A8B8: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
L_8001A8BC:
    // 0x8001A8BC: beq         $t9, $zero, L_8001A8F4
    if (ctx->r25 == 0) {
        // 0x8001A8C0: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_8001A8F4;
    }
    // 0x8001A8C0: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x8001A8C4: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x8001A8C8: lhu         $t7, 0x4($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X4);
    // 0x8001A8CC: srav        $t8, $t6, $t7
    ctx->r24 = S32(SIGNED(ctx->r14) >> (ctx->r15 & 31));
    // 0x8001A8D0: multu       $t8, $t5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A8D4: mflo        $t9
    ctx->r25 = lo;
    // 0x8001A8D8: nop

    // 0x8001A8DC: nop

    // 0x8001A8E0: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A8E4: mflo        $t6
    ctx->r14 = lo;
    // 0x8001A8E8: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8001A8EC: b           L_8001A934
    // 0x8001A8F0: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
        goto L_8001A934;
    // 0x8001A8F0: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
L_8001A8F4:
    // 0x8001A8F4: beql        $t7, $zero, L_8001A934
    if (ctx->r15 == 0) {
        // 0x8001A8F8: andi        $t7, $v0, 0x10
        ctx->r15 = ctx->r2 & 0X10;
            goto L_8001A934;
    }
    goto skip_1;
    // 0x8001A8F8: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    skip_1:
    // 0x8001A8FC: lhu         $t8, 0x4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X4);
    // 0x8001A900: lhu         $t9, 0x4($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X4);
    // 0x8001A904: lhu         $t7, 0x2($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X2);
    // 0x8001A908: srav        $t6, $t8, $t9
    ctx->r14 = S32(SIGNED(ctx->r24) >> (ctx->r25 & 31));
    // 0x8001A90C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8001A910: multu       $t8, $t5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A914: mflo        $t9
    ctx->r25 = lo;
    // 0x8001A918: nop

    // 0x8001A91C: nop

    // 0x8001A920: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A924: mflo        $t6
    ctx->r14 = lo;
    // 0x8001A928: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8001A92C: nop

    // 0x8001A930: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
L_8001A934:
    // 0x8001A934: beq         $t7, $zero, L_8001A944
    if (ctx->r15 == 0) {
        // 0x8001A938: andi        $t8, $v0, 0x2
        ctx->r24 = ctx->r2 & 0X2;
            goto L_8001A944;
    }
    // 0x8001A938: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x8001A93C: b           L_8001A948
    // 0x8001A940: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8001A948;
    // 0x8001A940: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8001A944:
    // 0x8001A944: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001A948:
    // 0x8001A948: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x8001A94C: beq         $t8, $zero, L_8001AC2C
    if (ctx->r24 == 0) {
        // 0x8001A950: sw          $a1, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = ctx->r5;
            goto L_8001AC2C;
    }
    // 0x8001A950: sw          $a1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r5;
    // 0x8001A954: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A958: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8001A95C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001A960: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x8001A964: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8001A968: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x8001A96C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001A970: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x8001A974: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001A978: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8001A97C: andi        $a2, $t2, 0x3
    ctx->r6 = ctx->r10 & 0X3;
    // 0x8001A980: sll         $t9, $a2, 18
    ctx->r25 = S32(ctx->r6 << 18);
    // 0x8001A984: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8001A988: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001A98C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8001A990: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x8001A994: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8001A998: sll         $t8, $a2, 8
    ctx->r24 = S32(ctx->r6 << 8);
    // 0x8001A99C: andi        $t6, $a3, 0xF
    ctx->r14 = ctx->r7 & 0XF;
    // 0x8001A9A0: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8001A9A4: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x8001A9A8: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x8001A9AC: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8001A9B0: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8001A9B4: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8001A9B8: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8001A9BC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001A9C0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8001A9C4: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x8001A9C8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8001A9CC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8001A9D0: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8001A9D4: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8001A9D8: srl         $v0, $t5, 3
    ctx->r2 = S32(U32(ctx->r13) >> 3);
    // 0x8001A9DC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8001A9E0: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8001A9E4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8001A9E8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8001A9EC: addiu       $a3, $t5, -0x1
    ctx->r7 = ADD32(ctx->r13, -0X1);
    // 0x8001A9F0: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x8001A9F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001A9F8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8001A9FC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001AA00: multu       $t5, $t5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AA04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001AA08: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8001AA0C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8001AA10: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8001AA14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001AA18: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x8001AA1C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8001AA20: mflo        $t1
    ctx->r9 = lo;
    // 0x8001AA24: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001AA28: srl         $t7, $t1, 1
    ctx->r15 = S32(U32(ctx->r9) >> 1);
    // 0x8001AA2C: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x8001AA30: sltiu       $at, $t1, 0x7FF
    ctx->r1 = ctx->r9 < 0X7FF ? 1 : 0;
    // 0x8001AA34: beql        $at, $zero, L_8001AA48
    if (ctx->r1 == 0) {
        // 0x8001AA38: addiu       $t8, $zero, 0x7FF
        ctx->r24 = ADD32(0, 0X7FF);
            goto L_8001AA48;
    }
    goto skip_2;
    // 0x8001AA38: addiu       $t8, $zero, 0x7FF
    ctx->r24 = ADD32(0, 0X7FF);
    skip_2:
    // 0x8001AA3C: b           L_8001AA4C
    // 0x8001AA40: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
        goto L_8001AA4C;
    // 0x8001AA40: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8001AA44: addiu       $t8, $zero, 0x7FF
    ctx->r24 = ADD32(0, 0X7FF);
L_8001AA48:
    // 0x8001AA48: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
L_8001AA4C:
    // 0x8001AA4C: bne         $v0, $zero, L_8001AA5C
    if (ctx->r2 != 0) {
        // 0x8001AA50: or          $t4, $t5, $zero
        ctx->r12 = ctx->r13 | 0;
            goto L_8001AA5C;
    }
    // 0x8001AA50: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8001AA54: b           L_8001AA5C
    // 0x8001AA58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8001AA5C;
    // 0x8001AA58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8001AA5C:
    // 0x8001AA5C: bne         $v0, $zero, L_8001AA6C
    if (ctx->r2 != 0) {
        // 0x8001AA60: addiu       $t9, $t2, 0x7FF
        ctx->r25 = ADD32(ctx->r10, 0X7FF);
            goto L_8001AA6C;
    }
    // 0x8001AA60: addiu       $t9, $t2, 0x7FF
    ctx->r25 = ADD32(ctx->r10, 0X7FF);
    // 0x8001AA64: b           L_8001AA70
    // 0x8001AA68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001AA70;
    // 0x8001AA68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001AA6C:
    // 0x8001AA6C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8001AA70:
    // 0x8001AA70: divu        $zero, $t9, $t1
    lo = S32(U32(ctx->r25) / U32(ctx->r9)); hi = S32(U32(ctx->r25) % U32(ctx->r9));
    // 0x8001AA74: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x8001AA78: mflo        $t6
    ctx->r14 = lo;
    // 0x8001AA7C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8001AA80: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001AA84: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8001AA88: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8001AA8C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8001AA90: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8001AA94: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8001AA98: bne         $t1, $zero, L_8001AAA4
    if (ctx->r9 != 0) {
        // 0x8001AA9C: nop
    
            goto L_8001AAA4;
    }
    // 0x8001AA9C: nop

    // 0x8001AAA0: break       7
    do_break(2147592864);
L_8001AAA4:
    // 0x8001AAA4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8001AAA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AAAC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8001AAB0: addiu       $t6, $t4, 0x7
    ctx->r14 = ADD32(ctx->r12, 0X7);
    // 0x8001AAB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001AAB8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001AABC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001AAC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001AAC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AAC8: srl         $t8, $t6, 3
    ctx->r24 = S32(U32(ctx->r14) >> 3);
    // 0x8001AACC: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x8001AAD0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001AAD4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001AAD8: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8001AADC: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8001AAE0: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8001AAE4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001AAE8: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8001AAEC: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8001AAF0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8001AAF4: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8001AAF8: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8001AAFC: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8001AB00: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8001AB04: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001AB08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AB0C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8001AB10: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8001AB14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001AB18: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001AB1C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8001AB20: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8001AB24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001AB28: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8001AB2C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001AB30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AB34: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8001AB38: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x8001AB3C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001AB40: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001AB44: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001AB48: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001AB4C: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x8001AB50: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x8001AB54: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8001AB58: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x8001AB5C: beql        $t8, $zero, L_8001ABCC
    if (ctx->r24 == 0) {
        // 0x8001AB60: lhu         $t6, 0x8($t9)
        ctx->r14 = MEM_HU(ctx->r25, 0X8);
            goto L_8001ABCC;
    }
    goto skip_3;
    // 0x8001AB60: lhu         $t6, 0x8($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X8);
    skip_3:
    // 0x8001AB64: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x8001AB68: lui         $t8, 0xFC62
    ctx->r24 = S32(0XFC62 << 16);
    // 0x8001AB6C: lui         $t7, 0xFC62
    ctx->r15 = S32(0XFC62 << 16);
    // 0x8001AB70: andi        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 & 0X20;
    // 0x8001AB74: beq         $t6, $zero, L_8001ABA4
    if (ctx->r14 == 0) {
        // 0x8001AB78: ori         $t8, $t8, 0x9BFF
        ctx->r24 = ctx->r24 | 0X9BFF;
            goto L_8001ABA4;
    }
    // 0x8001AB78: ori         $t8, $t8, 0x9BFF
    ctx->r24 = ctx->r24 | 0X9BFF;
    // 0x8001AB7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AB80: lui         $t9, 0x1F10
    ctx->r25 = S32(0X1F10 << 16);
    // 0x8001AB84: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8001AB88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001AB8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001AB90: ori         $t7, $t7, 0x9A04
    ctx->r15 = ctx->r15 | 0X9A04;
    // 0x8001AB94: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001AB98: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001AB9C: b           L_8001AF60
    // 0x8001ABA0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_8001AF60;
    // 0x8001ABA0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8001ABA4:
    // 0x8001ABA4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001ABA8: lui         $t7, 0x1F10
    ctx->r15 = S32(0X1F10 << 16);
    // 0x8001ABAC: ori         $t7, $t7, 0xFE3F
    ctx->r15 = ctx->r15 | 0XFE3F;
    // 0x8001ABB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001ABB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001ABB8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001ABBC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001ABC0: b           L_8001AF60
    // 0x8001ABC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_8001AF60;
    // 0x8001ABC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001ABC8: lhu         $t6, 0x8($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X8);
L_8001ABCC:
    // 0x8001ABCC: lui         $t7, 0xFC62
    ctx->r15 = S32(0XFC62 << 16);
    // 0x8001ABD0: lui         $t9, 0xFC62
    ctx->r25 = S32(0XFC62 << 16);
    // 0x8001ABD4: andi        $t8, $t6, 0x20
    ctx->r24 = ctx->r14 & 0X20;
    // 0x8001ABD8: beq         $t8, $zero, L_8001AC08
    if (ctx->r24 == 0) {
        // 0x8001ABDC: ori         $t7, $t7, 0xFFFF
        ctx->r15 = ctx->r15 | 0XFFFF;
            goto L_8001AC08;
    }
    // 0x8001ABDC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8001ABE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001ABE4: lui         $t6, 0x1F10
    ctx->r14 = S32(0X1F10 << 16);
    // 0x8001ABE8: ori         $t6, $t6, 0xFBFF
    ctx->r14 = ctx->r14 | 0XFBFF;
    // 0x8001ABEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001ABF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001ABF4: ori         $t9, $t9, 0xFE04
    ctx->r25 = ctx->r25 | 0XFE04;
    // 0x8001ABF8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001ABFC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001AC00: b           L_8001AF60
    // 0x8001AC04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_8001AF60;
    // 0x8001AC04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8001AC08:
    // 0x8001AC08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AC0C: lui         $t9, 0x1F10
    ctx->r25 = S32(0X1F10 << 16);
    // 0x8001AC10: ori         $t9, $t9, 0xFA3F
    ctx->r25 = ctx->r25 | 0XFA3F;
    // 0x8001AC14: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001AC18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001AC1C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001AC20: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001AC24: b           L_8001AF60
    // 0x8001AC28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_8001AF60;
    // 0x8001AC28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8001AC2C:
    // 0x8001AC2C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001AC30: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8001AC34: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001AC38: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8001AC3C: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8001AC40: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8001AC44: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001AC48: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x8001AC4C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8001AC50: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8001AC54: andi        $a2, $t2, 0x3
    ctx->r6 = ctx->r10 & 0X3;
    // 0x8001AC58: sll         $t6, $a2, 18
    ctx->r14 = S32(ctx->r6 << 18);
    // 0x8001AC5C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x8001AC60: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001AC64: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8001AC68: lw          $a3, 0xC0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC0);
    // 0x8001AC6C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x8001AC70: sll         $t9, $a2, 8
    ctx->r25 = S32(ctx->r6 << 8);
    // 0x8001AC74: andi        $t8, $a3, 0xF
    ctx->r24 = ctx->r7 & 0XF;
    // 0x8001AC78: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8001AC7C: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x8001AC80: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8001AC84: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8001AC88: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8001AC8C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8001AC90: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8001AC94: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001AC98: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8001AC9C: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x8001ACA0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8001ACA4: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8001ACA8: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8001ACAC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8001ACB0: srl         $v0, $t5, 3
    ctx->r2 = S32(U32(ctx->r13) >> 3);
    // 0x8001ACB4: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8001ACB8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8001ACBC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8001ACC0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8001ACC4: addiu       $a3, $t5, -0x1
    ctx->r7 = ADD32(ctx->r13, -0X1);
    // 0x8001ACC8: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x8001ACCC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001ACD0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8001ACD4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001ACD8: multu       $t5, $t5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001ACDC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001ACE0: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8001ACE4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8001ACE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001ACEC: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x8001ACF0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8001ACF4: mflo        $t1
    ctx->r9 = lo;
    // 0x8001ACF8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001ACFC: srl         $t7, $t1, 1
    ctx->r15 = S32(U32(ctx->r9) >> 1);
    // 0x8001AD00: addiu       $t1, $t7, -0x1
    ctx->r9 = ADD32(ctx->r15, -0X1);
    // 0x8001AD04: sltiu       $at, $t1, 0x7FF
    ctx->r1 = ctx->r9 < 0X7FF ? 1 : 0;
    // 0x8001AD08: beql        $at, $zero, L_8001AD1C
    if (ctx->r1 == 0) {
        // 0x8001AD0C: addiu       $t9, $zero, 0x7FF
        ctx->r25 = ADD32(0, 0X7FF);
            goto L_8001AD1C;
    }
    goto skip_4;
    // 0x8001AD0C: addiu       $t9, $zero, 0x7FF
    ctx->r25 = ADD32(0, 0X7FF);
    skip_4:
    // 0x8001AD10: b           L_8001AD20
    // 0x8001AD14: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
        goto L_8001AD20;
    // 0x8001AD14: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8001AD18: addiu       $t9, $zero, 0x7FF
    ctx->r25 = ADD32(0, 0X7FF);
L_8001AD1C:
    // 0x8001AD1C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_8001AD20:
    // 0x8001AD20: bne         $v0, $zero, L_8001AD30
    if (ctx->r2 != 0) {
        // 0x8001AD24: or          $t4, $t5, $zero
        ctx->r12 = ctx->r13 | 0;
            goto L_8001AD30;
    }
    // 0x8001AD24: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8001AD28: b           L_8001AD34
    // 0x8001AD2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8001AD34;
    // 0x8001AD2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8001AD30:
    // 0x8001AD30: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8001AD34:
    // 0x8001AD34: bne         $v0, $zero, L_8001AD44
    if (ctx->r2 != 0) {
        // 0x8001AD38: addiu       $t6, $t2, 0x7FF
        ctx->r14 = ADD32(ctx->r10, 0X7FF);
            goto L_8001AD44;
    }
    // 0x8001AD38: addiu       $t6, $t2, 0x7FF
    ctx->r14 = ADD32(ctx->r10, 0X7FF);
    // 0x8001AD3C: b           L_8001AD48
    // 0x8001AD40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8001AD48;
    // 0x8001AD40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001AD44:
    // 0x8001AD44: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8001AD48:
    // 0x8001AD48: divu        $zero, $t6, $t1
    lo = S32(U32(ctx->r14) / U32(ctx->r9)); hi = S32(U32(ctx->r14) % U32(ctx->r9));
    // 0x8001AD4C: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x8001AD50: mflo        $t8
    ctx->r24 = lo;
    // 0x8001AD54: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001AD58: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8001AD5C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8001AD60: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8001AD64: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8001AD68: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8001AD6C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8001AD70: bne         $t1, $zero, L_8001AD7C
    if (ctx->r9 != 0) {
        // 0x8001AD74: nop
    
            goto L_8001AD7C;
    }
    // 0x8001AD74: nop

    // 0x8001AD78: break       7
    do_break(2147593592);
L_8001AD7C:
    // 0x8001AD7C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8001AD80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AD84: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8001AD88: addiu       $t8, $t4, 0x7
    ctx->r24 = ADD32(ctx->r12, 0X7);
    // 0x8001AD8C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001AD90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001AD94: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001AD98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001AD9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001ADA0: srl         $t9, $t8, 3
    ctx->r25 = S32(U32(ctx->r24) >> 3);
    // 0x8001ADA4: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8001ADA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001ADAC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001ADB0: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8001ADB4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8001ADB8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8001ADBC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001ADC0: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8001ADC4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8001ADC8: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8001ADCC: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8001ADD0: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8001ADD4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8001ADD8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8001ADDC: addiu       $t4, $t4, -0x7C18
    ctx->r12 = ADD32(ctx->r12, -0X7C18);
    // 0x8001ADE0: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8001ADE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001ADE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001ADEC: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8001ADF0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8001ADF4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001ADF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001ADFC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8001AE00: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8001AE04: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001AE08: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8001AE0C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001AE10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AE14: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8001AE18: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x8001AE1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001AE20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001AE24: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8001AE28: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001AE2C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001AE30: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8001AE34: lui         $t8, 0xFC12
    ctx->r24 = S32(0XFC12 << 16);
    // 0x8001AE38: ori         $t8, $t8, 0x99FF
    ctx->r24 = ctx->r24 | 0X99FF;
    // 0x8001AE3C: lhu         $t7, 0x8($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X8);
    // 0x8001AE40: lui         $t9, 0xFC12
    ctx->r25 = S32(0XFC12 << 16);
    // 0x8001AE44: ori         $t9, $t9, 0x9804
    ctx->r25 = ctx->r25 | 0X9804;
    // 0x8001AE48: andi        $t6, $t7, 0x20
    ctx->r14 = ctx->r15 & 0X20;
    // 0x8001AE4C: beq         $t6, $zero, L_8001AE78
    if (ctx->r14 == 0) {
        // 0x8001AE50: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_8001AE78;
    }
    // 0x8001AE50: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001AE54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AE58: lui         $t7, 0xFF17
    ctx->r15 = S32(0XFF17 << 16);
    // 0x8001AE5C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8001AE60: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001AE64: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001AE68: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001AE6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001AE70: b           L_8001AE98
    // 0x8001AE74: lhu         $t2, 0x6($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X6);
        goto L_8001AE98;
    // 0x8001AE74: lhu         $t2, 0x6($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X6);
L_8001AE78:
    // 0x8001AE78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AE7C: lui         $t9, 0xFF17
    ctx->r25 = S32(0XFF17 << 16);
    // 0x8001AE80: ori         $t9, $t9, 0xFE3F
    ctx->r25 = ctx->r25 | 0XFE3F;
    // 0x8001AE84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001AE88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001AE8C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001AE90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001AE94: lhu         $t2, 0x6($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X6);
L_8001AE98:
    // 0x8001AE98: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x8001AE9C: beql        $t2, $t7, L_8001AF60
    if (ctx->r10 == ctx->r15) {
        // 0x8001AEA0: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_8001AF60;
    }
    goto skip_5;
    // 0x8001AEA0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x8001AEA4: sh          $t2, -0x7C18($at)
    MEM_H(-0X7C18, ctx->r1) = ctx->r10;
    // 0x8001AEA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AEAC: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8001AEB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001AEB4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001AEB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001AEBC: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x8001AEC0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8001AEC4: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8001AEC8: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8001AECC: lw          $t6, -0x2FC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2FC0);
    // 0x8001AED0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001AED4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AED8: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8001AEDC: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8001AEE0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001AEE4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001AEE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001AEEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001AEF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AEF4: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8001AEF8: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8001AEFC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001AF00: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001AF04: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001AF08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001AF0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AF10: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8001AF14: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8001AF18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001AF1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001AF20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001AF24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001AF28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AF2C: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8001AF30: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8001AF34: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001AF38: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001AF3C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001AF40: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001AF44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AF48: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8001AF4C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001AF50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001AF54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001AF58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001AF5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8001AF60:
    // 0x8001AF60: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8001AF64: sll         $a1, $t5, 6
    ctx->r5 = S32(ctx->r13 << 6);
    // 0x8001AF68: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001AF6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001AF70: lh          $t9, 0xC($t3)
    ctx->r25 = MEM_H(ctx->r11, 0XC);
    // 0x8001AF74: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8001AF78: lh          $t9, 0xE($t3)
    ctx->r25 = MEM_H(ctx->r11, 0XE);
    // 0x8001AF7C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8001AF80: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8001AF84: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8001AF88: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x8001AF8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001AF90: lh          $t9, 0xC($t3)
    ctx->r25 = MEM_H(ctx->r11, 0XC);
    // 0x8001AF94: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x8001AF98: lh          $t9, 0xE($t3)
    ctx->r25 = MEM_H(ctx->r11, 0XE);
    // 0x8001AF9C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001AFA0: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8001AFA4: addu        $t8, $t9, $t5
    ctx->r24 = ADD32(ctx->r25, ctx->r13);
    // 0x8001AFA8: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8001AFAC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8001AFB0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001AFB4: lhu         $t8, 0x0($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X0);
    // 0x8001AFB8: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x8001AFBC: lui         $t9, 0xBB00
    ctx->r25 = S32(0XBB00 << 16);
    // 0x8001AFC0: andi        $t6, $t8, 0x20
    ctx->r14 = ctx->r24 & 0X20;
    // 0x8001AFC4: beq         $t6, $zero, L_8001B004
    if (ctx->r14 == 0) {
        // 0x8001AFC8: ori         $t7, $t7, 0x1
        ctx->r15 = ctx->r15 | 0X1;
            goto L_8001B004;
    }
    // 0x8001AFC8: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x8001AFCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001AFD0: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x8001AFD4: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8001AFD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001AFDC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001AFE0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8001AFE4: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x8001AFE8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001AFEC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001AFF0: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8001AFF4: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x8001AFF8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8001AFFC: b           L_8001B020
    // 0x8001B000: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
        goto L_8001B020;
    // 0x8001B000: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
L_8001B004:
    // 0x8001B004: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001B008: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8001B00C: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x8001B010: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001B014: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001B018: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001B01C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8001B020:
    // 0x8001B020: b           L_8001B084
    // 0x8001B024: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
        goto L_8001B084;
    // 0x8001B024: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
L_8001B028:
    // 0x8001B028: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001B02C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8001B030: lui         $t9, 0xFC62
    ctx->r25 = S32(0XFC62 << 16);
    // 0x8001B034: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001B038: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001B03C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001B040: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001B044: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001B048: lui         $t8, 0x4FFE
    ctx->r24 = S32(0X4FFE << 16);
    // 0x8001B04C: ori         $t8, $t8, 0x7E38
    ctx->r24 = ctx->r24 | 0X7E38;
    // 0x8001B050: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001B054: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001B058: ori         $t9, $t9, 0xCBFF
    ctx->r25 = ctx->r25 | 0XCBFF;
    // 0x8001B05C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001B060: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001B064: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001B068: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8001B06C: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x8001B070: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001B074: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001B078: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x8001B07C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001B080: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8001B084:
    // 0x8001B084: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001B088: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x8001B08C: lui         $t7, 0x6
    ctx->r15 = S32(0X6 << 16);
    // 0x8001B090: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001B094: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001B098: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001B09C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001B0A0: beq         $a1, $zero, L_8001B0C0
    if (ctx->r5 == 0) {
        // 0x8001B0A4: nop
    
            goto L_8001B0C0;
    }
    // 0x8001B0A4: nop

    // 0x8001B0A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001B0AC: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8001B0B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001B0B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001B0B8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8001B0BC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8001B0C0:
    // 0x8001B0C0: jr          $ra
    // 0x8001B0C4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8001B0C4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x8001B0C8: nop

    // 0x8001B0CC: nop

;}
RECOMP_FUNC void func_800011DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011DC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800011E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800011E4: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800011E8: addiu       $s0, $s0, -0x4D04
    ctx->r16 = ADD32(ctx->r16, -0X4D04);
    // 0x800011EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800011F0: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x800011F4: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800011F8: ori         $at, $zero, 0x8148
    ctx->r1 = 0 | 0X8148;
    // 0x800011FC: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x80001200: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80001204: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80001208: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000120C: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x80001210: ori         $t9, $t9, 0x6
    ctx->r25 = ctx->r25 | 0X6;
    // 0x80001214: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80001218: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000121C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80001220: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80001224: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001228: ori         $t5, $t5, 0x406
    ctx->r13 = ctx->r13 | 0X406;
    // 0x8000122C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001230: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80001234: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80001238: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8000123C: lw          $a0, -0x4CB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CB0);
    // 0x80001240: jal         0x80034DD0
    // 0x80001244: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80001244: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_0:
    // 0x80001248: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8000124C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80001250: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001254: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80001258: ori         $t7, $t7, 0x806
    ctx->r15 = ctx->r15 | 0X806;
    // 0x8000125C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80001260: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80001264: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80001268: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8000126C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x80001270: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x80001274: jal         0x80034DD0
    // 0x80001278: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80001278: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8000127C: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80001280: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80001284: lui         $t6, 0xFE00
    ctx->r14 = S32(0XFE00 << 16);
    // 0x80001288: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8000128C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001290: lui         $t4, 0x100
    ctx->r12 = S32(0X100 << 16);
    // 0x80001294: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
    // 0x80001298: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000129C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800012A0: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800012A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800012A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800012AC: lui         $a0, 0x802E
    ctx->r4 = S32(0X802E << 16);
    // 0x800012B0: addiu       $a0, $a0, -0x5800
    ctx->r4 = ADD32(ctx->r4, -0X5800);
    // 0x800012B4: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800012B8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800012BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800012C0: jal         0x80034DD0
    // 0x800012C4: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800012C4: sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    after_2:
    // 0x800012C8: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800012CC: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x800012D0: lui         $a0, 0x802E
    ctx->r4 = S32(0X802E << 16);
    // 0x800012D4: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x800012D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800012DC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800012E0: addiu       $a0, $a0, -0x5800
    ctx->r4 = ADD32(ctx->r4, -0X5800);
    // 0x800012E4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800012E8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800012EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800012F0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800012F4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800012F8: ori         $t4, $t4, 0x1402
    ctx->r12 = ctx->r12 | 0X1402;
    // 0x800012FC: lui         $t5, 0x30
    ctx->r13 = S32(0X30 << 16);
    // 0x80001300: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80001304: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80001308: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8000130C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80001310: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001314: lui         $t7, 0xFF10
    ctx->r15 = S32(0XFF10 << 16);
    // 0x80001318: ori         $t7, $t7, 0x13F
    ctx->r15 = ctx->r15 | 0X13F;
    // 0x8000131C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80001320: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80001324: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80001328: jal         0x80034DD0
    // 0x8000132C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8000132C: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80001330: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80001334: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x80001338: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x8000133C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80001340: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001344: lui         $t4, 0xFFFC
    ctx->r12 = S32(0XFFFC << 16);
    // 0x80001348: ori         $t4, $t4, 0xFFFC
    ctx->r12 = ctx->r12 | 0XFFFC;
    // 0x8000134C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80001350: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80001354: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80001358: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000135C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001360: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80001364: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x80001368: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8000136C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80001370: ori         $t6, $t6, 0xC39C
    ctx->r14 = ctx->r14 | 0XC39C;
    // 0x80001374: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80001378: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000137C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001380: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80001384: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80001388: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000138C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80001390: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80001394: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001398: lui         $t5, 0xFF10
    ctx->r13 = S32(0XFF10 << 16);
    // 0x8000139C: ori         $t5, $t5, 0x13F
    ctx->r13 = ctx->r13 | 0X13F;
    // 0x800013A0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800013A4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800013A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800013AC: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800013B0: addiu       $a0, $t6, 0x7FFF
    ctx->r4 = ADD32(ctx->r14, 0X7FFF);
    // 0x800013B4: lw          $a0, 0x514D($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X514D);
    // 0x800013B8: jal         0x80034DD0
    // 0x800013BC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800013BC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_4:
    // 0x800013C0: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800013C4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800013C8: lui         $t2, 0xF64D
    ctx->r10 = S32(0XF64D << 16);
    // 0x800013CC: lui         $t3, 0x2
    ctx->r11 = S32(0X2 << 16);
    // 0x800013D0: ori         $t3, $t3, 0x20
    ctx->r11 = ctx->r11 | 0X20;
    // 0x800013D4: ori         $t2, $t2, 0xC39C
    ctx->r10 = ctx->r10 | 0XC39C;
    // 0x800013D8: addiu       $a2, $a2, -0x4D20
    ctx->r6 = ADD32(ctx->r6, -0X4D20);
    // 0x800013DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800013E0: lui         $t0, 0xF700
    ctx->r8 = S32(0XF700 << 16);
    // 0x800013E4: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800013E8: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x800013EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800013F0: bnel        $a3, $t7, L_80001470
    if (ctx->r7 != ctx->r15) {
        // 0x800013F4: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80001470;
    }
    goto skip_0;
    // 0x800013F4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800013F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800013FC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80001400: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80001404: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80001408: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000140C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80001410: lw          $t9, -0x4D00($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D00);
    // 0x80001414: lw          $t6, -0x4CFC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4CFC);
    // 0x80001418: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x8000141C: andi        $t5, $t4, 0xF800
    ctx->r13 = ctx->r12 & 0XF800;
    // 0x80001420: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80001424: lw          $t4, -0x4CF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4CF8);
    // 0x80001428: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8000142C: andi        $t8, $t7, 0x7C0
    ctx->r24 = ctx->r15 & 0X7C0;
    // 0x80001430: srl         $t6, $t4, 2
    ctx->r14 = S32(U32(ctx->r12) >> 2);
    // 0x80001434: andi        $t7, $t6, 0x3E
    ctx->r15 = ctx->r14 & 0X3E;
    // 0x80001438: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x8000143C: or          $a0, $t9, $t7
    ctx->r4 = ctx->r25 | ctx->r15;
    // 0x80001440: ori         $t5, $a0, 0x1
    ctx->r13 = ctx->r4 | 0X1;
    // 0x80001444: sll         $t8, $t5, 16
    ctx->r24 = S32(ctx->r13 << 16);
    // 0x80001448: or          $t4, $t8, $t5
    ctx->r12 = ctx->r24 | ctx->r13;
    // 0x8000144C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80001450: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001454: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80001458: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000145C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80001460: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80001464: b           L_800014A0
    // 0x80001468: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_800014A0;
    // 0x80001468: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000146C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80001470:
    // 0x80001470: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80001474: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x80001478: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000147C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80001480: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80001484: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80001488: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000148C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80001490: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80001494: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80001498: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8000149C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800014A0:
    // 0x800014A0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x800014A4: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x800014A8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800014AC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800014B0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800014B4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800014B8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800014BC: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x800014C0: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x800014C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800014C8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800014CC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800014D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800014D4: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800014D8: bne         $a3, $v0, L_800015F8
    if (ctx->r7 != ctx->r2) {
        // 0x800014DC: nop
    
            goto L_800015F8;
    }
    // 0x800014DC: nop

    // 0x800014E0: jal         0x80012BE0
    // 0x800014E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80012BE0(rdram, ctx);
        goto after_5;
    // 0x800014E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x800014E8: jal         0x80010B58
    // 0x800014EC: nop

    func_80010B58(rdram, ctx);
        goto after_6;
    // 0x800014EC: nop

    after_6:
    // 0x800014F0: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x800014F4: lhu         $t5, 0x4F12($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X4F12);
    // 0x800014F8: andi        $t8, $t5, 0x4
    ctx->r24 = ctx->r13 & 0X4;
    // 0x800014FC: beq         $t8, $zero, L_80001514
    if (ctx->r24 == 0) {
        // 0x80001500: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80001514;
    }
    // 0x80001500: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001504: jal         0x800111F8
    // 0x80001508: lw          $a0, -0x4CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CC0);
    func_800111F8(rdram, ctx);
        goto after_7;
    // 0x80001508: lw          $a0, -0x4CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CC0);
    after_7:
    // 0x8000150C: jal         0x8000D9BC
    // 0x80001510: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8000D9BC(rdram, ctx);
        goto after_8;
    // 0x80001510: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
L_80001514:
    // 0x80001514: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001518: jal         0x800111F8
    // 0x8000151C: lw          $a0, -0x4CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CC0);
    func_800111F8(rdram, ctx);
        goto after_9;
    // 0x8000151C: lw          $a0, -0x4CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CC0);
    after_9:
    // 0x80001520: jal         0x8000C4C4
    // 0x80001524: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8000C4C4(rdram, ctx);
        goto after_10;
    // 0x80001524: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80001528: jal         0x80003870
    // 0x8000152C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80003870(rdram, ctx);
        goto after_11;
    // 0x8000152C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80001530: jal         0x80007F18
    // 0x80001534: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80007F18(rdram, ctx);
        goto after_12;
    // 0x80001534: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x80001538: jal         0x80011D28
    // 0x8000153C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80011D28(rdram, ctx);
        goto after_13;
    // 0x8000153C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x80001540: jal         0x8000CE8C
    // 0x80001544: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8000CE8C(rdram, ctx);
        goto after_14;
    // 0x80001544: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x80001548: jal         0x80008CF4
    // 0x8000154C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80008CF4(rdram, ctx);
        goto after_15;
    // 0x8000154C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x80001550: jal         0x8000B618
    // 0x80001554: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8000B618(rdram, ctx);
        goto after_16;
    // 0x80001554: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x80001558: jal         0x8001249C
    // 0x8000155C: nop

    func_8001249C(rdram, ctx);
        goto after_17;
    // 0x8000155C: nop

    after_17:
    // 0x80001560: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001564: jal         0x800111F8
    // 0x80001568: lw          $a0, -0x43F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43F8);
    func_800111F8(rdram, ctx);
        goto after_18;
    // 0x80001568: lw          $a0, -0x43F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43F8);
    after_18:
    // 0x8000156C: jal         0x800118D4
    // 0x80001570: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800118D4(rdram, ctx);
        goto after_19;
    // 0x80001570: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x80001574: jal         0x8001B19C
    // 0x80001578: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8001B19C(rdram, ctx);
        goto after_20;
    // 0x80001578: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x8000157C: jal         0x80018638
    // 0x80001580: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80018638(rdram, ctx);
        goto after_21;
    // 0x80001580: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x80001584: jal         0x800228F8
    // 0x80001588: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800228F8(rdram, ctx);
        goto after_22;
    // 0x80001588: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_22:
    // 0x8000158C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80001590: lw          $v0, -0x4D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D1C);
    // 0x80001594: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x80001598: beq         $t4, $zero, L_800015B4
    if (ctx->r12 == 0) {
        // 0x8000159C: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_800015B4;
    }
    // 0x8000159C: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x800015A0: jal         0x8002EAA0
    // 0x800015A4: nop

    func_8002EAA0(rdram, ctx);
        goto after_23;
    // 0x800015A4: nop

    after_23:
    // 0x800015A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800015AC: b           L_800015DC
    // 0x800015B0: lw          $v0, -0x4D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D1C);
        goto L_800015DC;
    // 0x800015B0: lw          $v0, -0x4D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D1C);
L_800015B4:
    // 0x800015B4: bne         $t6, $zero, L_800015DC
    if (ctx->r14 != 0) {
        // 0x800015B8: lui         $t9, 0x8008
        ctx->r25 = S32(0X8008 << 16);
            goto L_800015DC;
    }
    // 0x800015B8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800015BC: lhu         $t9, -0x4D18($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4D18);
    // 0x800015C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800015C4: beql        $t9, $at, L_800015E0
    if (ctx->r25 == ctx->r1) {
        // 0x800015C8: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800015E0;
    }
    goto skip_1;
    // 0x800015C8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    skip_1:
    // 0x800015CC: jal         0x8001E25C
    // 0x800015D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8001E25C(rdram, ctx);
        goto after_24;
    // 0x800015D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_24:
    // 0x800015D4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800015D8: lw          $v0, -0x4D1C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D1C);
L_800015DC:
    // 0x800015DC: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
L_800015E0:
    // 0x800015E0: beql        $t7, $zero, L_8000173C
    if (ctx->r15 == 0) {
        // 0x800015E4: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8000173C;
    }
    goto skip_2;
    // 0x800015E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x800015E8: jal         0x80021524
    // 0x800015EC: nop

    func_80021524(rdram, ctx);
        goto after_25;
    // 0x800015EC: nop

    after_25:
    // 0x800015F0: b           L_8000173C
    // 0x800015F4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_8000173C;
    // 0x800015F4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800015F8:
    // 0x800015F8: bnel        $v0, $at, L_80001614
    if (ctx->r2 != ctx->r1) {
        // 0x800015FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80001614;
    }
    goto skip_3;
    // 0x800015FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_3:
    // 0x80001600: jal         0x80026A7C
    // 0x80001604: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80026A7C(rdram, ctx);
        goto after_26;
    // 0x80001604: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_26:
    // 0x80001608: b           L_8000173C
    // 0x8000160C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_8000173C;
    // 0x8000160C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001610: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80001614:
    // 0x80001614: bnel        $v0, $at, L_800016AC
    if (ctx->r2 != ctx->r1) {
        // 0x80001618: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800016AC;
    }
    goto skip_4;
    // 0x80001618: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_4:
    // 0x8000161C: jal         0x8010004C
    // 0x80001620: nop

    func_8010004C_DA693C_ovl_title(rdram, ctx);
        goto after_27;
    // 0x80001620: nop

    after_27:
    // 0x80001624: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80001628: addiu       $a2, $a2, -0x4D20
    ctx->r6 = ADD32(ctx->r6, -0X4D20);
    // 0x8000162C: beq         $v0, $zero, L_80001644
    if (ctx->r2 == 0) {
        // 0x80001630: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80001644;
    }
    // 0x80001630: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80001634: beq         $v0, $a3, L_800016A0
    if (ctx->r2 == ctx->r7) {
        // 0x80001638: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_800016A0;
    }
    // 0x80001638: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8000163C: b           L_8000173C
    // 0x80001640: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_8000173C;
    // 0x80001640: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80001644:
    // 0x80001644: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80001648: lbu         $v0, -0x4CBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4CBC);
    // 0x8000164C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80001650: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80001654: andi        $t5, $v0, 0xF0
    ctx->r13 = ctx->r2 & 0XF0;
    // 0x80001658: beq         $t5, $at, L_80001678
    if (ctx->r13 == ctx->r1) {
        // 0x8000165C: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_80001678;
    }
    // 0x8000165C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80001660: beq         $t5, $at, L_80001680
    if (ctx->r13 == ctx->r1) {
        // 0x80001664: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_80001680;
    }
    // 0x80001664: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80001668: beq         $t5, $at, L_80001690
    if (ctx->r13 == ctx->r1) {
        // 0x8000166C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80001690;
    }
    // 0x8000166C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80001670: b           L_80001738
    // 0x80001674: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
        goto L_80001738;
    // 0x80001674: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80001678:
    // 0x80001678: b           L_80001738
    // 0x8000167C: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
        goto L_80001738;
    // 0x8000167C: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
L_80001680:
    // 0x80001680: jal         0x8002B510
    // 0x80001684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002B510(rdram, ctx);
        goto after_28;
    // 0x80001684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_28:
    // 0x80001688: b           L_8000173C
    // 0x8000168C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_8000173C;
    // 0x8000168C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80001690:
    // 0x80001690: jal         0x8002B510
    // 0x80001694: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8002B510(rdram, ctx);
        goto after_29;
    // 0x80001694: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_29:
    // 0x80001698: b           L_8000173C
    // 0x8000169C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
        goto L_8000173C;
    // 0x8000169C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800016A0:
    // 0x800016A0: b           L_80001738
    // 0x800016A4: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_80001738;
    // 0x800016A4: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x800016A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800016AC:
    // 0x800016AC: bnel        $v0, $at, L_80001714
    if (ctx->r2 != ctx->r1) {
        // 0x800016B0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80001714;
    }
    goto skip_5;
    // 0x800016B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_5:
    // 0x800016B4: jal         0x8010009C
    // 0x800016B8: nop

    func_8010009C_DC16BC_ovl_intro(rdram, ctx);
        goto after_30;
    // 0x800016B8: nop

    after_30:
    // 0x800016BC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800016C0: addiu       $a2, $a2, -0x4D20
    ctx->r6 = ADD32(ctx->r6, -0X4D20);
    // 0x800016C4: beq         $v0, $zero, L_800016DC
    if (ctx->r2 == 0) {
        // 0x800016C8: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800016DC;
    }
    // 0x800016C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800016CC: beq         $v0, $a3, L_800016F0
    if (ctx->r2 == ctx->r7) {
        // 0x800016D0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800016F0;
    }
    // 0x800016D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800016D4: b           L_80001704
    // 0x800016D8: nop

        goto L_80001704;
    // 0x800016D8: nop

L_800016DC:
    // 0x800016DC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800016E0: sb          $zero, -0x53A0($at)
    MEM_B(-0X53A0, ctx->r1) = 0;
    // 0x800016E4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800016E8: b           L_80001738
    // 0x800016EC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
        goto L_80001738;
    // 0x800016EC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
L_800016F0:
    // 0x800016F0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800016F4: sb          $t7, -0x53A0($at)
    MEM_B(-0X53A0, ctx->r1) = ctx->r15;
    // 0x800016F8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800016FC: b           L_80001738
    // 0x80001700: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
        goto L_80001738;
    // 0x80001700: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
L_80001704:
    // 0x80001704: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80001708: b           L_80001738
    // 0x8000170C: sb          $zero, -0x53A0($at)
    MEM_B(-0X53A0, ctx->r1) = 0;
        goto L_80001738;
    // 0x8000170C: sb          $zero, -0x53A0($at)
    MEM_B(-0X53A0, ctx->r1) = 0;
    // 0x80001710: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80001714:
    // 0x80001714: bnel        $v0, $at, L_8000173C
    if (ctx->r2 != ctx->r1) {
        // 0x80001718: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8000173C;
    }
    goto skip_6;
    // 0x80001718: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x8000171C: jal         0x8010008C
    // 0x80001720: nop

    func_8010008C_E278CC_ovl_ending(rdram, ctx);
        goto after_31;
    // 0x80001720: nop

    after_31:
    // 0x80001724: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80001728: bne         $v0, $zero, L_80001738
    if (ctx->r2 != 0) {
        // 0x8000172C: addiu       $a2, $a2, -0x4D20
        ctx->r6 = ADD32(ctx->r6, -0X4D20);
            goto L_80001738;
    }
    // 0x8000172C: addiu       $a2, $a2, -0x4D20
    ctx->r6 = ADD32(ctx->r6, -0X4D20);
    // 0x80001730: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80001734: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80001738:
    // 0x80001738: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8000173C:
    // 0x8000173C: lui         $t6, 0xE900
    ctx->r14 = S32(0XE900 << 16);
    // 0x80001740: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80001744: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80001748: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8000174C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80001750: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80001754: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80001758: lui         $t7, 0xB800
    ctx->r15 = S32(0XB800 << 16);
    // 0x8000175C: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    // 0x80001760: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80001764: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80001768: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8000176C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80001770: jal         0x80034E50
    // 0x80001774: ori         $a1, $zero, 0xD0F0
    ctx->r5 = 0 | 0XD0F0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_32;
    // 0x80001774: ori         $a1, $zero, 0xD0F0
    ctx->r5 = 0 | 0XD0F0;
    after_32:
    // 0x80001778: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8000177C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80001780: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80001784: addiu       $v1, $v1, -0x4CB4
    ctx->r3 = ADD32(ctx->r3, -0X4CB4);
    // 0x80001788: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8000178C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80001790: ori         $at, $at, 0x7EB8
    ctx->r1 = ctx->r1 | 0X7EB8;
    // 0x80001794: subu        $v0, $t5, $a0
    ctx->r2 = SUB32(ctx->r13, ctx->r4);
    // 0x80001798: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x8000179C: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800017A0: slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800017A4: beq         $at, $zero, L_800017B0
    if (ctx->r1 == 0) {
        // 0x800017A8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800017B0;
    }
    // 0x800017A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800017AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800017B0:
    // 0x800017B0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800017B4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x800017B8: sw          $v0, -0x3DF0($at)
    MEM_W(-0X3DF0, ctx->r1) = ctx->r2;
    // 0x800017BC: ori         $at, $zero, 0x80F0
    ctx->r1 = 0 | 0X80F0;
    // 0x800017C0: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x800017C4: sw          $t9, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r25;
    // 0x800017C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800017CC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800017D0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800017D4: ori         $at, $at, 0x7F10
    ctx->r1 = ctx->r1 | 0X7F10;
    // 0x800017D8: subu        $t8, $t7, $t5
    ctx->r24 = SUB32(ctx->r15, ctx->r13);
    // 0x800017DC: addu        $t4, $t8, $at
    ctx->r12 = ADD32(ctx->r24, ctx->r1);
    // 0x800017E0: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800017E4: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x800017E8: sw          $t9, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r25;
    // 0x800017EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800017F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800017F4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800017F8: jr          $ra
    // 0x800017FC: nop

    return;
    // 0x800017FC: nop

;}
RECOMP_FUNC void func_80018484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001848C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80018490: lhu         $t6, 0xA($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA);
    // 0x80018494: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x80018498: beql        $t7, $zero, L_800184AC
    if (ctx->r15 == 0) {
        // 0x8001849C: lw          $v0, 0x2C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X2C);
            goto L_800184AC;
    }
    goto skip_0;
    // 0x8001849C: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    skip_0:
    // 0x800184A0: b           L_80018510
    // 0x800184A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80018510;
    // 0x800184A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800184A8: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
L_800184AC:
    // 0x800184AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800184B0: lhu         $t8, 0x18($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X18);
    // 0x800184B4: bnel        $t8, $at, L_800184C8
    if (ctx->r24 != ctx->r1) {
        // 0x800184B8: lhu         $t9, 0x5E($a1)
        ctx->r25 = MEM_HU(ctx->r5, 0X5E);
            goto L_800184C8;
    }
    goto skip_1;
    // 0x800184B8: lhu         $t9, 0x5E($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X5E);
    skip_1:
    // 0x800184BC: b           L_80018510
    // 0x800184C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80018510;
    // 0x800184C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800184C4: lhu         $t9, 0x5E($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X5E);
L_800184C8:
    // 0x800184C8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800184CC: beq         $t0, $zero, L_800184F4
    if (ctx->r8 == 0) {
        // 0x800184D0: nop
    
            goto L_800184F4;
    }
    // 0x800184D0: nop

    // 0x800184D4: jal         0x80022FD0
    // 0x800184D8: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    get_rand(rdram, ctx);
        goto after_0;
    // 0x800184D8: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    after_0:
    // 0x800184DC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800184E0: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x800184E4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800184E8: lbu         $t2, -0x3210($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X3210);
    // 0x800184EC: b           L_80018510
    // 0x800184F0: sltu        $v1, $v0, $t2
    ctx->r3 = ctx->r2 < ctx->r10 ? 1 : 0;
        goto L_80018510;
    // 0x800184F0: sltu        $v1, $v0, $t2
    ctx->r3 = ctx->r2 < ctx->r10 ? 1 : 0;
L_800184F4:
    // 0x800184F4: jal         0x80022FD0
    // 0x800184F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    get_rand(rdram, ctx);
        goto after_1;
    // 0x800184F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x800184FC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80018500: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x80018504: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80018508: lbu         $t4, -0x3210($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X3210);
    // 0x8001850C: sltu        $v1, $v0, $t4
    ctx->r3 = ctx->r2 < ctx->r12 ? 1 : 0;
L_80018510:
    // 0x80018510: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80018514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001851C: jr          $ra
    // 0x80018520: nop

    return;
    // 0x80018520: nop

;}
RECOMP_FUNC void func_80020B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020B4C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80020B50: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80020B54: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80020B58: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80020B5C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80020B60: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80020B64: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x80020B68: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80020B6C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80020B70: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80020B74: lui         $s4, 0xE700
    ctx->r20 = S32(0XE700 << 16);
    // 0x80020B78: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80020B7C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80020B80: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80020B84: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80020B88: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80020B8C: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80020B90: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80020B94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80020B98: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80020B9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020BA0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80020BA4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80020BA8: lui         $t6, 0x803A
    ctx->r14 = S32(0X803A << 16);
    // 0x80020BAC: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80020BB0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80020BB4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80020BB8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80020BBC: lw          $t6, 0x6FB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FB0);
    // 0x80020BC0: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
    // 0x80020BC4: lui         $s5, 0x803A
    ctx->r21 = S32(0X803A << 16);
    // 0x80020BC8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80020BCC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80020BD0: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80020BD4: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80020BD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80020BDC: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80020BE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020BE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80020BE8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80020BEC: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80020BF0: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80020BF4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80020BF8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80020BFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80020C00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80020C04: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80020C08: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80020C0C: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80020C10: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80020C14: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80020C18: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020C1C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80020C20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80020C24: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x80020C28: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80020C2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80020C30: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80020C34: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80020C38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80020C3C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80020C40: addiu       $s5, $s5, 0x6F80
    ctx->r21 = ADD32(ctx->r21, 0X6F80);
    // 0x80020C44: addiu       $s0, $zero, 0x2C
    ctx->r16 = ADD32(0, 0X2C);
    // 0x80020C48: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80020C4C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80020C50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020C54: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80020C58: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80020C5C: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
    // 0x80020C60: beql        $v1, $zero, L_80020CF4
    if (ctx->r3 == 0) {
        // 0x80020C64: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80020CF4;
    }
    goto skip_0;
    // 0x80020C64: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_80020C68:
    // 0x80020C68: bne         $s4, $v1, L_80020C7C
    if (ctx->r20 != ctx->r3) {
        // 0x80020C6C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80020C7C;
    }
    // 0x80020C6C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80020C70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80020C74: b           L_80020CE4
    // 0x80020C78: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
        goto L_80020CE4;
    // 0x80020C78: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
L_80020C7C:
    // 0x80020C7C: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80020C80: addiu       $v0, $v0, -0x2BB4
    ctx->r2 = ADD32(ctx->r2, -0X2BB4);
    // 0x80020C84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80020C88:
    // 0x80020C88: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80020C8C: beq         $t6, $a0, L_80020CA0
    if (ctx->r14 == ctx->r4) {
        // 0x80020C90: nop
    
            goto L_80020CA0;
    }
    // 0x80020C90: nop

    // 0x80020C94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80020C98: bne         $v1, $s0, L_80020C88
    if (ctx->r3 != ctx->r16) {
        // 0x80020C9C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80020C88;
    }
    // 0x80020C9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80020CA0:
    // 0x80020CA0: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80020CA4: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80020CA8: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80020CAC: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80020CB0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80020CB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80020CB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80020CBC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80020CC0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020CC4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80020CC8: mflo        $t8
    ctx->r24 = lo;
    // 0x80020CCC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80020CD0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x80020CD4: jal         0x800210FC
    // 0x80020CD8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_0;
    // 0x80020CD8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x80020CDC: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x80020CE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80020CE4:
    // 0x80020CE4: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x80020CE8: bne         $v1, $zero, L_80020C68
    if (ctx->r3 != 0) {
        // 0x80020CEC: nop
    
            goto L_80020C68;
    }
    // 0x80020CEC: nop

    // 0x80020CF0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80020CF4:
    // 0x80020CF4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80020CF8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80020CFC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80020D00: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80020D04: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80020D08: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80020D0C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80020D10: jr          $ra
    // 0x80020D14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80020D14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80025BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025BD8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80025BDC: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80025BE0: addiu       $a3, $a3, 0x396C
    ctx->r7 = ADD32(ctx->r7, 0X396C);
    // 0x80025BE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80025BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80025BEC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80025BF0: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80025BF4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80025BF8: addiu       $t6, $t6, 0x390C
    ctx->r14 = ADD32(ctx->r14, 0X390C);
    // 0x80025BFC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80025C00: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x80025C04: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x80025C08: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80025C0C: addiu       $t0, $t0, -0x6CC
    ctx->r8 = ADD32(ctx->r8, -0X6CC);
    // 0x80025C10: beq         $t1, $a2, L_80025DF0
    if (ctx->r9 == ctx->r6) {
        // 0x80025C14: lui         $t5, 0x8005
        ctx->r13 = S32(0X8005 << 16);
            goto L_80025DF0;
    }
    // 0x80025C14: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80025C18: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80025C1C: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80025C20: andi        $t2, $t8, 0x3
    ctx->r10 = ctx->r24 & 0X3;
    // 0x80025C24: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80025C28: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80025C2C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80025C30: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80025C34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80025C38: jal         0x800258F8
    // 0x80025C3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800258F8(rdram, ctx);
        goto after_0;
    // 0x80025C3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80025C40: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80025C44: lw          $t3, -0x6D4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6D4);
    // 0x80025C48: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80025C4C: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80025C50: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80025C54: addiu       $t0, $t0, -0x6CC
    ctx->r8 = ADD32(ctx->r8, -0X6CC);
    // 0x80025C58: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80025C5C: beq         $t4, $zero, L_80025CFC
    if (ctx->r12 == 0) {
        // 0x80025C60: addiu       $a1, $a1, 0x39A8
        ctx->r5 = ADD32(ctx->r5, 0X39A8);
            goto L_80025CFC;
    }
    // 0x80025C60: addiu       $a1, $a1, 0x39A8
    ctx->r5 = ADD32(ctx->r5, 0X39A8);
    // 0x80025C64: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80025C68: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80025C6C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80025C70: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80025C74: lw          $t7, 0x392C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X392C);
    // 0x80025C78: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80025C7C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025C80: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80025C84: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80025C88: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80025C8C: lw          $a1, 0x39A4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X39A4);
    // 0x80025C90: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80025C94: sw          $t7, 0x39BC($at)
    MEM_W(0X39BC, ctx->r1) = ctx->r15;
    // 0x80025C98: lw          $t8, 0x394C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X394C);
    // 0x80025C9C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025CA0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80025CA4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80025CA8: beq         $s0, $a1, L_80025CDC
    if (ctx->r16 == ctx->r5) {
        // 0x80025CAC: sw          $t8, 0x39D0($at)
        MEM_W(0X39D0, ctx->r1) = ctx->r24;
            goto L_80025CDC;
    }
    // 0x80025CAC: sw          $t8, 0x39D0($at)
    MEM_W(0X39D0, ctx->r1) = ctx->r24;
    // 0x80025CB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80025CB4: beql        $a2, $a1, L_80025CE0
    if (ctx->r6 == ctx->r5) {
        // 0x80025CB8: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80025CE0;
    }
    goto skip_0;
    // 0x80025CB8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    skip_0:
    // 0x80025CBC: jal         0x8002568C
    // 0x80025CC0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8002568C(rdram, ctx);
        goto after_1;
    // 0x80025CC0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80025CC4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025CC8: sw          $s0, 0x39A4($at)
    MEM_W(0X39A4, ctx->r1) = ctx->r16;
    // 0x80025CCC: jal         0x80025634
    // 0x80025CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80025634(rdram, ctx);
        goto after_2;
    // 0x80025CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80025CD4: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80025CD8: lw          $a1, 0x39A4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X39A4);
L_80025CDC:
    // 0x80025CDC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_80025CE0:
    // 0x80025CE0: bne         $a2, $a1, L_80025DC4
    if (ctx->r6 != ctx->r5) {
        // 0x80025CE4: lui         $at, 0x8005
        ctx->r1 = S32(0X8005 << 16);
            goto L_80025DC4;
    }
    // 0x80025CE4: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025CE8: sw          $s0, 0x39A4($at)
    MEM_W(0X39A4, ctx->r1) = ctx->r16;
    // 0x80025CEC: jal         0x80025634
    // 0x80025CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80025634(rdram, ctx);
        goto after_3;
    // 0x80025CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80025CF4: b           L_80025DC8
    // 0x80025CF8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
        goto L_80025DC8;
    // 0x80025CF8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_80025CFC:
    // 0x80025CFC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80025D00: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x80025D04: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80025D08: lw          $t2, 0x392C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X392C);
    // 0x80025D0C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025D10: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x80025D14: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80025D18: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80025D1C: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x80025D20: lw          $t3, 0x394C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X394C);
    // 0x80025D24: sw          $t2, 0x39BC($at)
    MEM_W(0X39BC, ctx->r1) = ctx->r10;
    // 0x80025D28: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025D2C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80025D30: addu        $t4, $a1, $t9
    ctx->r12 = ADD32(ctx->r5, ctx->r25);
    // 0x80025D34: sw          $t3, 0x39D0($at)
    MEM_W(0X39D0, ctx->r1) = ctx->r11;
    // 0x80025D38: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80025D3C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80025D40: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80025D44: beq         $t5, $zero, L_80025D78
    if (ctx->r13 == 0) {
        // 0x80025D48: addu        $a2, $a2, $t9
        ctx->r6 = ADD32(ctx->r6, ctx->r25);
            goto L_80025D78;
    }
    // 0x80025D48: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80025D4C: lw          $a2, 0x3994($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3994);
    // 0x80025D50: beq         $s0, $a2, L_80025D78
    if (ctx->r16 == ctx->r6) {
        // 0x80025D54: nop
    
            goto L_80025D78;
    }
    // 0x80025D54: nop

    // 0x80025D58: jal         0x8002568C
    // 0x80025D5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8002568C(rdram, ctx);
        goto after_4;
    // 0x80025D5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80025D60: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025D64: lw          $a0, -0x6CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6CC);
    // 0x80025D68: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80025D6C: addiu       $a1, $a1, 0x39A8
    ctx->r5 = ADD32(ctx->r5, 0X39A8);
    // 0x80025D70: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80025D74: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80025D78:
    // 0x80025D78: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80025D7C: addiu       $v0, $t7, 0x3994
    ctx->r2 = ADD32(ctx->r15, 0X3994);
    // 0x80025D80: addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
    // 0x80025D84: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80025D88: addiu       $a0, $a0, 0x39A4
    ctx->r4 = ADD32(ctx->r4, 0X39A4);
    // 0x80025D8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80025D90: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_80025D94:
    // 0x80025D94: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80025D98: addu        $t9, $a1, $v1
    ctx->r25 = ADD32(ctx->r5, ctx->r3);
    // 0x80025D9C: bnel        $s0, $t8, L_80025DB0
    if (ctx->r16 != ctx->r24) {
        // 0x80025DA0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80025DB0;
    }
    goto skip_1;
    // 0x80025DA0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x80025DA4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x80025DA8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80025DAC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80025DB0:
    // 0x80025DB0: bne         $v0, $a0, L_80025D94
    if (ctx->r2 != ctx->r4) {
        // 0x80025DB4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80025D94;
    }
    // 0x80025DB4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80025DB8: sw          $s0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r16;
    // 0x80025DBC: jal         0x80025634
    // 0x80025DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80025634(rdram, ctx);
        goto after_5;
    // 0x80025DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80025DC4:
    // 0x80025DC4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_80025DC8:
    // 0x80025DC8: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80025DCC: beql        $t2, $s0, L_80025DFC
    if (ctx->r10 == ctx->r16) {
        // 0x80025DD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80025DFC;
    }
    goto skip_2;
    // 0x80025DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80025DD4: lw          $t3, -0x6D4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6D4);
    // 0x80025DD8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80025DDC: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80025DE0: jal         0x80025E0C
    // 0x80025DE4: sw          $t4, -0x6D4($at)
    MEM_W(-0X6D4, ctx->r1) = ctx->r12;
    func_80025E0C(rdram, ctx);
        goto after_6;
    // 0x80025DE4: sw          $t4, -0x6D4($at)
    MEM_W(-0X6D4, ctx->r1) = ctx->r12;
    after_6:
    // 0x80025DE8: b           L_80025DFC
    // 0x80025DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80025DFC;
    // 0x80025DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80025DF0:
    // 0x80025DF0: lw          $t5, 0x3970($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3970);
    // 0x80025DF4: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x80025DF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80025DFC:
    // 0x80025DFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80025E00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80025E04: jr          $ra
    // 0x80025E08: nop

    return;
    // 0x80025E08: nop

;}
RECOMP_FUNC void alLoadNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040204: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80040208: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004020C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80040210: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80040214: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80040218: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8004021C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80040220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80040224: addiu       $a1, $a1, 0x10CC
    ctx->r5 = ADD32(ctx->r5, 0X10CC);
    // 0x80040228: addiu       $a2, $a2, 0xA20
    ctx->r6 = ADD32(ctx->r6, 0XA20);
    // 0x8004022C: jal         0x80048AC0
    // 0x80040230: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80040230: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80040234: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80040238: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8004023C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040244: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80040248: jal         0x80036660
    // 0x8004024C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x8004024C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80040250: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80040254: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80040258: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8004025C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80040260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80040264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80040268: jal         0x80036660
    // 0x8004026C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8004026C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80040270: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80040274: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80040278: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8004027C: jalr        $t9
    // 0x80040280: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80040280: nop

    after_3:
    // 0x80040284: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80040288: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8004028C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80040290: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x80040294: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80040298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004029C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800402A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800402A4: jr          $ra
    // 0x800402A8: nop

    return;
    // 0x800402A8: nop

;}
RECOMP_FUNC void func_801000A8_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801000A8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801000AC: lbu         $v0, 0x3120($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3120);
    // 0x801000B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801000B8: bne         $v0, $zero, L_801000FC
    if (ctx->r2 != 0) {
        // 0x801000BC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_801000FC;
    }
    // 0x801000BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801000C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801000C4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801000C8: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x801000CC: addiu       $a2, $a2, -0x52BC
    ctx->r6 = ADD32(ctx->r6, -0X52BC);
    // 0x801000D0: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x801000D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801000D8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x801000DC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x801000E0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801000E4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801000E8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x801000EC: sb          $zero, -0x53A0($at)
    MEM_B(-0X53A0, ctx->r1) = 0;
    // 0x801000F0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801000F4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801000F8: sb          $t7, 0x3120($at)
    MEM_B(0X3120, ctx->r1) = ctx->r15;
L_801000FC:
    // 0x801000FC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80100100: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x80100104: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80100108: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8010010C: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x80100110: addiu       $t8, $v0, -0x3
    ctx->r24 = ADD32(ctx->r2, -0X3);
    // 0x80100114: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80100118: beq         $at, $zero, L_801006AC
    if (ctx->r1 == 0) {
        // 0x8010011C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_801006AC;
    }
    // 0x8010011C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80100120: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100124: addu        $at, $at, $t8
    gpr jr_addend_8010012C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80100128: lw          $t8, -0x5330($at)
    ctx->r24 = ADD32(ctx->r1, -0X5330);
    // 0x8010012C: jr          $t8
    // 0x80100130: nop

    switch (jr_addend_8010012C >> 2) {
        case 0: goto L_80100134; break;
        case 1: goto L_80100170; break;
        case 2: goto L_801002B8; break;
        case 3: goto L_8010049C; break;
        case 4: goto L_8010052C; break;
        case 5: goto L_80100694; break;
        default: switch_error(__func__, 0x8010012C, 0x8011ACD0);
    }
    // 0x80100130: nop

L_80100134:
    // 0x80100134: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80100138: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x8010013C: bne         $t5, $zero, L_801006AC
    if (ctx->r13 != 0) {
        // 0x80100140: sw          $t5, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r13;
            goto L_801006AC;
    }
    // 0x80100140: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80100144: addiu       $t7, $zero, 0x1518
    ctx->r15 = ADD32(0, 0X1518);
    // 0x80100148: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8010014C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80100150: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80100154: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80100158: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010015C: sw          $t9, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r25;
    // 0x80100160: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80100164: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100168: b           L_801006AC
    // 0x8010016C: sw          $t3, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r11;
        goto L_801006AC;
    // 0x8010016C: sw          $t3, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r11;
L_80100170:
    // 0x80100170: jal         0x801006D8
    // 0x80100174: nop

    func_801006D8_ovl_title(rdram, ctx);
        goto after_0;
    // 0x80100174: nop

    after_0:
    // 0x80100178: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8010017C: lw          $t5, 0x3420($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3420);
    // 0x80100180: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80100184: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80100188: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8010018C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80100190: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x80100194: addiu       $a2, $a2, -0x52BC
    ctx->r6 = ADD32(ctx->r6, -0X52BC);
    // 0x80100198: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x8010019C: bne         $t3, $t5, L_801001CC
    if (ctx->r11 != ctx->r13) {
        // 0x801001A0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_801001CC;
    }
    // 0x801001A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801001A4: jal         0x80102E30
    // 0x801001A8: nop

    func_80102E30_ovl_title(rdram, ctx);
        goto after_1;
    // 0x801001A8: nop

    after_1:
    // 0x801001AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801001B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801001B4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801001B8: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x801001BC: addiu       $a2, $a2, -0x52BC
    ctx->r6 = ADD32(ctx->r6, -0X52BC);
    // 0x801001C0: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x801001C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801001C8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
L_801001CC:
    // 0x801001CC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801001D0: bne         $t6, $zero, L_80100214
    if (ctx->r14 != 0) {
        // 0x801001D4: nop
    
            goto L_80100214;
    }
    // 0x801001D4: nop

    // 0x801001D8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801001DC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x801001E0: addiu       $v1, $v1, 0x3110
    ctx->r3 = ADD32(ctx->r3, 0X3110);
    // 0x801001E4: bne         $t7, $zero, L_80100214
    if (ctx->r15 != 0) {
        // 0x801001E8: nop
    
            goto L_80100214;
    }
    // 0x801001E8: nop

    // 0x801001EC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801001F0: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801001F4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801001F8: bne         $t8, $zero, L_80100214
    if (ctx->r24 != 0) {
        // 0x801001FC: nop
    
            goto L_80100214;
    }
    // 0x801001FC: nop

    // 0x80100200: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80100204: sw          $t0, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r8;
    // 0x80100208: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010020C: sw          $t2, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r10;
    // 0x80100210: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_80100214:
    // 0x80100214: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80100218: addiu       $v1, $v1, 0x3110
    ctx->r3 = ADD32(ctx->r3, 0X3110);
    // 0x8010021C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80100220: bnel        $t2, $t9, L_8010028C
    if (ctx->r10 != ctx->r25) {
        // 0x80100224: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_8010028C;
    }
    goto skip_0;
    // 0x80100224: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80100228: jal         0x80102E30
    // 0x8010022C: nop

    func_80102E30_ovl_title(rdram, ctx);
        goto after_2;
    // 0x8010022C: nop

    after_2:
    // 0x80100230: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x80100234: lw          $t5, 0x3420($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3420);
    // 0x80100238: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8010023C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80100240: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80100244: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80100248: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x8010024C: addiu       $a2, $a2, -0x52BC
    ctx->r6 = ADD32(ctx->r6, -0X52BC);
    // 0x80100250: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x80100254: addiu       $v1, $v1, 0x3110
    ctx->r3 = ADD32(ctx->r3, 0X3110);
    // 0x80100258: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8010025C: bne         $t5, $zero, L_80100288
    if (ctx->r13 != 0) {
        // 0x80100260: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80100288;
    }
    // 0x80100260: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80100264: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100268: sw          $zero, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = 0;
    // 0x8010026C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100270: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80100274: sw          $t6, -0x52C0($at)
    MEM_W(-0X52C0, ctx->r1) = ctx->r14;
    // 0x80100278: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8010027C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80100280: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80100284: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80100288:
    // 0x80100288: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_8010028C:
    // 0x8010028C: bnel        $t7, $zero, L_801006B0
    if (ctx->r15 != 0) {
        // 0x80100290: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_801006B0;
    }
    goto skip_1;
    // 0x80100290: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80100294: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80100298: bnel        $t2, $t8, L_801006B0
    if (ctx->r10 != ctx->r24) {
        // 0x8010029C: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_801006B0;
    }
    goto skip_2;
    // 0x8010029C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x801002A0: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x801002A4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x801002A8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x801002AC: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x801002B0: b           L_801006AC
    // 0x801002B4: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
        goto L_801006AC;
    // 0x801002B4: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_801002B8:
    // 0x801002B8: jal         0x801006D8
    // 0x801002BC: nop

    func_801006D8_ovl_title(rdram, ctx);
        goto after_3;
    // 0x801002BC: nop

    after_3:
    // 0x801002C0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x801002C4: lhu         $t6, 0x311C($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X311C);
    // 0x801002C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801002CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801002D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801002D4: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x801002D8: addiu       $a2, $a2, -0x52BC
    ctx->r6 = ADD32(ctx->r6, -0X52BC);
    // 0x801002DC: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x801002E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801002E4: bne         $t6, $zero, L_801002FC
    if (ctx->r14 != 0) {
        // 0x801002E8: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_801002FC;
    }
    // 0x801002E8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801002EC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801002F0: lw          $a1, 0x3118($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3118);
    // 0x801002F4: b           L_80100300
    // 0x801002F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80100300;
    // 0x801002F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_801002FC:
    // 0x801002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80100300:
    // 0x80100300: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80100304: lhu         $t7, 0x2876($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2876);
    // 0x80100308: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8010030C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80100310: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x80100314: bne         $t8, $zero, L_80100354
    if (ctx->r24 != 0) {
        // 0x80100318: lui         $v1, 0x8010
        ctx->r3 = S32(0X8010 << 16);
            goto L_80100354;
    }
    // 0x80100318: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8010031C: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x80100320: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80100324: bne         $at, $zero, L_80100354
    if (ctx->r1 != 0) {
        // 0x80100328: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80100354;
    }
    // 0x80100328: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8010032C: beq         $at, $zero, L_80100354
    if (ctx->r1 == 0) {
        // 0x80100330: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80100354;
    }
    // 0x80100330: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80100334: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x80100338: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8010033C: bne         $at, $zero, L_80100354
    if (ctx->r1 != 0) {
        // 0x80100340: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80100354;
    }
    // 0x80100340: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80100344: beq         $at, $zero, L_80100354
    if (ctx->r1 == 0) {
        // 0x80100348: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80100354;
    }
    // 0x80100348: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010034C: b           L_8010035C
    // 0x80100350: sh          $zero, 0x311C($at)
    MEM_H(0X311C, ctx->r1) = 0;
        goto L_8010035C;
    // 0x80100350: sh          $zero, 0x311C($at)
    MEM_H(0X311C, ctx->r1) = 0;
L_80100354:
    // 0x80100354: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100358: sh          $t9, 0x311C($at)
    MEM_H(0X311C, ctx->r1) = ctx->r25;
L_8010035C:
    // 0x8010035C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100360: sw          $a1, 0x3118($at)
    MEM_W(0X3118, ctx->r1) = ctx->r5;
    // 0x80100364: sltiu       $at, $a1, 0x1C21
    ctx->r1 = ctx->r5 < 0X1C21 ? 1 : 0;
    // 0x80100368: bne         $at, $zero, L_80100394
    if (ctx->r1 != 0) {
        // 0x8010036C: addiu       $v1, $v1, 0x3110
        ctx->r3 = ADD32(ctx->r3, 0X3110);
            goto L_80100394;
    }
    // 0x8010036C: addiu       $v1, $v1, 0x3110
    ctx->r3 = ADD32(ctx->r3, 0X3110);
    // 0x80100370: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100374: sh          $zero, 0x311C($at)
    MEM_H(0X311C, ctx->r1) = 0;
    // 0x80100378: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8010037C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80100380: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80100384: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80100388: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8010038C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100390: sw          $zero, 0x3118($at)
    MEM_W(0X3118, ctx->r1) = 0;
L_80100394:
    // 0x80100394: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80100398: addiu       $v1, $v1, 0x3110
    ctx->r3 = ADD32(ctx->r3, 0X3110);
    // 0x8010039C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801003A0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801003A4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801003A8: bne         $t5, $zero, L_801003B4
    if (ctx->r13 != 0) {
        // 0x801003AC: addiu       $t6, $zero, 0x14
        ctx->r14 = ADD32(0, 0X14);
            goto L_801003B4;
    }
    // 0x801003AC: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x801003B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_801003B4:
    // 0x801003B4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801003B8: bnel        $t7, $zero, L_8010042C
    if (ctx->r15 != 0) {
        // 0x801003BC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8010042C;
    }
    goto skip_3;
    // 0x801003BC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x801003C0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801003C4: beq         $t4, $v0, L_801003D4
    if (ctx->r12 == ctx->r2) {
        // 0x801003C8: nop
    
            goto L_801003D4;
    }
    // 0x801003C8: nop

    // 0x801003CC: bnel        $t0, $v0, L_8010042C
    if (ctx->r8 != ctx->r2) {
        // 0x801003D0: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8010042C;
    }
    goto skip_4;
    // 0x801003D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_4:
L_801003D4:
    // 0x801003D4: bne         $t0, $v0, L_801003F0
    if (ctx->r8 != ctx->r2) {
        // 0x801003D8: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_801003F0;
    }
    // 0x801003D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801003DC: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801003E0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801003E4: sw          $t0, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r8;
    // 0x801003E8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801003EC: sw          $t2, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r10;
L_801003F0:
    // 0x801003F0: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801003F4: bne         $t4, $v0, L_80100428
    if (ctx->r12 != ctx->r2) {
        // 0x801003F8: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_80100428;
    }
    // 0x801003F8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x801003FC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80100400: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80100404: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80100408: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8010040C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80100410: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80100414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100418: sw          $t5, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = ctx->r13;
    // 0x8010041C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100420: sw          $zero, -0x52C0($at)
    MEM_W(-0X52C0, ctx->r1) = 0;
    // 0x80100424: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80100428:
    // 0x80100428: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8010042C:
    // 0x8010042C: bnel        $t3, $t6, L_801006B0
    if (ctx->r11 != ctx->r14) {
        // 0x80100430: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_801006B0;
    }
    goto skip_5;
    // 0x80100430: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_5:
    // 0x80100434: jal         0x80102E30
    // 0x80100438: nop

    func_80102E30_ovl_title(rdram, ctx);
        goto after_4;
    // 0x80100438: nop

    after_4:
    // 0x8010043C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80100440: lw          $t7, 0x3420($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3420);
    // 0x80100444: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80100448: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8010044C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80100450: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80100454: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x80100458: addiu       $a2, $a2, -0x52BC
    ctx->r6 = ADD32(ctx->r6, -0X52BC);
    // 0x8010045C: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x80100460: addiu       $v1, $v1, 0x3110
    ctx->r3 = ADD32(ctx->r3, 0X3110);
    // 0x80100464: bne         $t7, $zero, L_801006AC
    if (ctx->r15 != 0) {
        // 0x80100468: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_801006AC;
    }
    // 0x80100468: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8010046C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100470: sw          $zero, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = 0;
    // 0x80100474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100478: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8010047C: sw          $t8, -0x52C0($at)
    MEM_W(-0X52C0, ctx->r1) = ctx->r24;
    // 0x80100480: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80100484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100488: sw          $zero, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = 0;
    // 0x8010048C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80100490: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80100494: b           L_801006AC
    // 0x80100498: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_801006AC;
    // 0x80100498: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8010049C:
    // 0x8010049C: jal         0x801006D8
    // 0x801004A0: nop

    func_801006D8_ovl_title(rdram, ctx);
        goto after_5;
    // 0x801004A0: nop

    after_5:
    // 0x801004A4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x801004A8: lbu         $v0, 0x3114($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3114);
    // 0x801004AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801004B0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801004B4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x801004B8: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x801004BC: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x801004C0: beq         $at, $zero, L_801004D8
    if (ctx->r1 == 0) {
        // 0x801004C4: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_801004D8;
    }
    // 0x801004C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801004C8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801004CC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801004D0: b           L_801006AC
    // 0x801004D4: sb          $t9, 0x3114($at)
    MEM_B(0X3114, ctx->r1) = ctx->r25;
        goto L_801006AC;
    // 0x801004D4: sb          $t9, 0x3114($at)
    MEM_B(0X3114, ctx->r1) = ctx->r25;
L_801004D8:
    // 0x801004D8: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x801004DC: lbu         $t5, -0x4CBC($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4CBC);
    // 0x801004E0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x801004E4: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801004E8: andi        $t6, $t5, 0xF0
    ctx->r14 = ctx->r13 & 0XF0;
    // 0x801004EC: bne         $t6, $at, L_80100514
    if (ctx->r14 != ctx->r1) {
        // 0x801004F0: addiu       $t8, $zero, 0x8
        ctx->r24 = ADD32(0, 0X8);
            goto L_80100514;
    }
    // 0x801004F0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x801004F4: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801004F8: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801004FC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80100500: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100504: sw          $t0, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r8;
    // 0x80100508: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010050C: b           L_801006AC
    // 0x80100510: sw          $t2, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r10;
        goto L_801006AC;
    // 0x80100510: sw          $t2, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r10;
L_80100514:
    // 0x80100514: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80100518: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010051C: sw          $t0, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r8;
    // 0x80100520: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100524: b           L_801006AC
    // 0x80100528: sw          $t2, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r10;
        goto L_801006AC;
    // 0x80100528: sw          $t2, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r10;
L_8010052C:
    // 0x8010052C: jal         0x801006D8
    // 0x80100530: nop

    func_801006D8_ovl_title(rdram, ctx);
        goto after_6;
    // 0x80100530: nop

    after_6:
    // 0x80100534: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80100538: addiu       $v1, $v1, 0x3110
    ctx->r3 = ADD32(ctx->r3, 0X3110);
    // 0x8010053C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80100540: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80100544: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80100548: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8010054C: addiu       $a3, $a3, -0x52D0
    ctx->r7 = ADD32(ctx->r7, -0X52D0);
    // 0x80100550: addiu       $a2, $a2, -0x52BC
    ctx->r6 = ADD32(ctx->r6, -0X52BC);
    // 0x80100554: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
    // 0x80100558: bne         $t9, $zero, L_80100568
    if (ctx->r25 != 0) {
        // 0x8010055C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80100568;
    }
    // 0x8010055C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80100560: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80100564: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_80100568:
    // 0x80100568: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8010056C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80100570: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80100574: bne         $t3, $v0, L_80100580
    if (ctx->r11 != ctx->r2) {
        // 0x80100578: addiu       $t4, $zero, 0xB
        ctx->r12 = ADD32(0, 0XB);
            goto L_80100580;
    }
    // 0x80100578: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x8010057C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
L_80100580:
    // 0x80100580: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80100584: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80100588: bnel        $t6, $zero, L_801006B0
    if (ctx->r14 != 0) {
        // 0x8010058C: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_801006B0;
    }
    goto skip_6;
    // 0x8010058C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_6:
    // 0x80100590: beq         $t4, $v0, L_801005BC
    if (ctx->r12 == ctx->r2) {
        // 0x80100594: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_801005BC;
    }
    // 0x80100594: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80100598: beq         $v0, $at, L_801005BC
    if (ctx->r2 == ctx->r1) {
        // 0x8010059C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_801005BC;
    }
    // 0x8010059C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801005A0: beq         $v0, $at, L_801005BC
    if (ctx->r2 == ctx->r1) {
        // 0x801005A4: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_801005BC;
    }
    // 0x801005A4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801005A8: beq         $v0, $at, L_801005BC
    if (ctx->r2 == ctx->r1) {
        // 0x801005AC: addiu       $t0, $zero, 0x9
        ctx->r8 = ADD32(0, 0X9);
            goto L_801005BC;
    }
    // 0x801005AC: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x801005B0: beq         $t0, $v0, L_801005BC
    if (ctx->r8 == ctx->r2) {
        // 0x801005B4: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_801005BC;
    }
    // 0x801005B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801005B8: bne         $a1, $v0, L_801006AC
    if (ctx->r5 != ctx->r2) {
        // 0x801005BC: addiu       $t0, $zero, 0x9
        ctx->r8 = ADD32(0, 0X9);
            goto L_801006AC;
    }
L_801005BC:
    // 0x801005BC: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x801005C0: bne         $t0, $v0, L_801005DC
    if (ctx->r8 != ctx->r2) {
        // 0x801005C4: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_801005DC;
    }
    // 0x801005C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801005C8: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x801005CC: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x801005D0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801005D4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x801005D8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_801005DC:
    // 0x801005DC: bne         $a1, $v0, L_801005F8
    if (ctx->r5 != ctx->r2) {
        // 0x801005E0: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_801005F8;
    }
    // 0x801005E0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801005E4: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x801005E8: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x801005EC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801005F0: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x801005F4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_801005F8:
    // 0x801005F8: bne         $v0, $at, L_80100610
    if (ctx->r2 != ctx->r1) {
        // 0x801005FC: addiu       $t9, $zero, 0xF
        ctx->r25 = ADD32(0, 0XF);
            goto L_80100610;
    }
    // 0x801005FC: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80100600: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80100604: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80100608: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8010060C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80100610:
    // 0x80100610: bne         $t4, $v0, L_80100658
    if (ctx->r12 != ctx->r2) {
        // 0x80100614: addiu       $t0, $zero, 0x3C
        ctx->r8 = ADD32(0, 0X3C);
            goto L_80100658;
    }
    // 0x80100614: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80100618: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8010061C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80100620: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80100624: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80100628: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8010062C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100630: sw          $zero, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = 0;
    // 0x80100634: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100638: addiu       $t5, $zero, 0x100
    ctx->r13 = ADD32(0, 0X100);
    // 0x8010063C: sw          $t5, -0x52C0($at)
    MEM_W(-0X52C0, ctx->r1) = ctx->r13;
    // 0x80100640: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100644: sw          $t0, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r8;
    // 0x80100648: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010064C: sw          $t2, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = ctx->r10;
    // 0x80100650: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80100654: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80100658:
    // 0x80100658: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8010065C: bnel        $v0, $at, L_80100678
    if (ctx->r2 != ctx->r1) {
        // 0x80100660: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80100678;
    }
    goto skip_7;
    // 0x80100660: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_7:
    // 0x80100664: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80100668: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x8010066C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80100670: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80100674: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_80100678:
    // 0x80100678: bnel        $v0, $at, L_801006B0
    if (ctx->r2 != ctx->r1) {
        // 0x8010067C: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_801006B0;
    }
    goto skip_8;
    // 0x8010067C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_8:
    // 0x80100680: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80100684: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80100688: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8010068C: b           L_801006AC
    // 0x80100690: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_801006AC;
    // 0x80100690: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80100694:
    // 0x80100694: jal         0x80100B14
    // 0x80100698: nop

    func_80100B14_ovl_title(rdram, ctx);
        goto after_7;
    // 0x80100698: nop

    after_7:
    // 0x8010069C: jal         0x80102E30
    // 0x801006A0: nop

    func_80102E30_ovl_title(rdram, ctx);
        goto after_8;
    // 0x801006A0: nop

    after_8:
    // 0x801006A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801006A8: addiu       $a0, $a0, -0x52CC
    ctx->r4 = ADD32(ctx->r4, -0X52CC);
L_801006AC:
    // 0x801006AC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_801006B0:
    // 0x801006B0: bne         $v1, $zero, L_801006C4
    if (ctx->r3 != 0) {
        // 0x801006B4: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_801006C4;
    }
    // 0x801006B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801006B8: sh          $zero, 0x311C($at)
    MEM_H(0X311C, ctx->r1) = 0;
    // 0x801006BC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801006C0: sw          $zero, 0x3118($at)
    MEM_W(0X3118, ctx->r1) = 0;
L_801006C4:
    // 0x801006C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801006C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801006CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801006D0: jr          $ra
    // 0x801006D4: nop

    return;
    // 0x801006D4: nop

;}
RECOMP_FUNC void func_8002263C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002263C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80022640: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80022644: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80022648: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002264C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80022650: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022654: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80022658: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8002265C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80022660: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80022664: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80022668: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002266C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022670: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x80022674: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x80022678: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002267C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80022680: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80022684: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80022688: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002268C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80022690: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80022694: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80022698: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002269C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800226A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800226A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800226A8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x800226AC: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x800226B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800226B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800226B8: lui         $t6, 0xF700
    ctx->r14 = S32(0XF700 << 16);
    // 0x800226BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800226C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800226C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800226C8: addu        $s0, $a0, $a2
    ctx->r16 = ADD32(ctx->r4, ctx->r6);
    // 0x800226CC: andi        $t9, $s0, 0x3FF
    ctx->r25 = ctx->r16 & 0X3FF;
    // 0x800226D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800226D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800226D8: sll         $t6, $t9, 14
    ctx->r14 = S32(ctx->r25 << 14);
    // 0x800226DC: andi        $t7, $a1, 0x3FF
    ctx->r15 = ctx->r5 & 0X3FF;
    // 0x800226E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800226E4: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800226E8: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x800226EC: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x800226F0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800226F4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800226F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800226FC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80022700: andi        $t6, $a0, 0x3FF
    ctx->r14 = ctx->r4 & 0X3FF;
    // 0x80022704: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80022708: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8002270C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80022710: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80022714: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80022718: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002271C: addu        $s1, $a1, $a3
    ctx->r17 = ADD32(ctx->r5, ctx->r7);
    // 0x80022720: andi        $t7, $s1, 0x3FF
    ctx->r15 = ctx->r17 & 0X3FF;
    // 0x80022724: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x80022728: or          $t9, $t5, $t2
    ctx->r25 = ctx->r13 | ctx->r10;
    // 0x8002272C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80022730: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80022734: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80022738: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8002273C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80022740: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80022744: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80022748: lui         $a2, 0xF600
    ctx->r6 = S32(0XF600 << 16);
    // 0x8002274C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80022750: or          $t9, $t1, $t2
    ctx->r25 = ctx->r9 | ctx->r10;
    // 0x80022754: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80022758: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002275C: or          $t8, $t1, $a2
    ctx->r24 = ctx->r9 | ctx->r6;
    // 0x80022760: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x80022764: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80022768: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002276C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80022770: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80022774: addiu       $t1, $s1, 0x1
    ctx->r9 = ADD32(ctx->r17, 0X1);
    // 0x80022778: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002277C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022780: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x80022784: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80022788: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002278C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80022790: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80022794: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80022798: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8002279C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800227A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800227A4: addiu       $t9, $s0, 0x2
    ctx->r25 = ADD32(ctx->r16, 0X2);
    // 0x800227A8: andi        $t7, $t9, 0x3FF
    ctx->r15 = ctx->r25 & 0X3FF;
    // 0x800227AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800227B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800227B4: addiu       $t8, $s1, 0x2
    ctx->r24 = ADD32(ctx->r17, 0X2);
    // 0x800227B8: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x800227BC: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x800227C0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800227C4: or          $t0, $t6, $a2
    ctx->r8 = ctx->r14 | ctx->r6;
    // 0x800227C8: or          $t6, $t0, $t7
    ctx->r14 = ctx->r8 | ctx->r15;
    // 0x800227CC: addiu       $t7, $a0, 0x3
    ctx->r15 = ADD32(ctx->r4, 0X3);
    // 0x800227D0: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x800227D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800227D8: andi        $t6, $t7, 0x3FF
    ctx->r14 = ctx->r15 & 0X3FF;
    // 0x800227DC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x800227E0: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x800227E4: or          $t9, $t8, $t1
    ctx->r25 = ctx->r24 | ctx->r9;
    // 0x800227E8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800227EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800227F0: or          $t6, $t0, $t1
    ctx->r14 = ctx->r8 | ctx->r9;
    // 0x800227F4: addiu       $t8, $s0, 0x1
    ctx->r24 = ADD32(ctx->r16, 0X1);
    // 0x800227F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800227FC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80022800: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x80022804: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80022808: addiu       $t6, $a1, 0x3
    ctx->r14 = ADD32(ctx->r5, 0X3);
    // 0x8002280C: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80022810: sll         $t7, $t9, 14
    ctx->r15 = S32(ctx->r25 << 14);
    // 0x80022814: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80022818: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8002281C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80022820: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022824: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x80022828: addiu       $t9, $t9, -0x7008
    ctx->r25 = ADD32(ctx->r25, -0X7008);
    // 0x8002282C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80022830: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80022834: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80022838: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002283C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80022840: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022844: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80022848: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8002284C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80022850: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80022854: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80022858: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002285C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80022860: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80022864: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80022868: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x8002286C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80022870: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80022874: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x80022878: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002287C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80022880: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80022884: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80022888: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8002288C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80022890: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80022894: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80022898: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8002289C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800228A0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800228A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800228A8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800228AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800228B0: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x800228B4: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x800228B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800228BC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800228C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800228C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800228C8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800228CC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800228D0: jr          $ra
    // 0x800228D4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800228D4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800228D8: nop

    // 0x800228DC: nop

;}
RECOMP_FUNC void initPFSPaks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80101CD8_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101CD8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101CDC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101CE0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80101CE4: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x80101CE8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101CEC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101CF0: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80101CF4: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80101CF8: sh          $a1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r5;
    // 0x80101CFC: sh          $a2, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r6;
    // 0x80101D00: sh          $t8, 0x26($v0)
    MEM_H(0X26, ctx->r2) = ctx->r24;
    // 0x80101D04: jr          $ra
    // 0x80101D08: sh          $t9, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r25;
    return;
    // 0x80101D08: sh          $t9, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_800140EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800140EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800140F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800140F4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800140F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800140FC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80014100: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x80014104: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014108: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8001410C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80014110: beql        $t7, $zero, L_800143B4
    if (ctx->r15 == 0) {
        // 0x80014114: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800143B4;
    }
    goto skip_0;
    // 0x80014114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80014118: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    // 0x8001411C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80014120: addiu       $t9, $t9, 0x6B00
    ctx->r25 = ADD32(ctx->r25, 0X6B00);
    // 0x80014124: andi        $t8, $a1, 0x40
    ctx->r24 = ctx->r5 & 0X40;
    // 0x80014128: bne         $t8, $zero, L_80014160
    if (ctx->r24 != 0) {
        // 0x8001412C: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_80014160;
    }
    // 0x8001412C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80014130: addiu       $t2, $v0, 0x84
    ctx->r10 = ADD32(ctx->r2, 0X84);
L_80014134:
    // 0x80014134: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80014138: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8001413C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80014140: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x80014144: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x80014148: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x8001414C: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x80014150: bne         $t3, $t2, L_80014134
    if (ctx->r11 != ctx->r10) {
        // 0x80014154: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_80014134;
    }
    // 0x80014154: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x80014158: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8001415C: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
L_80014160:
    // 0x80014160: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80014164: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014168: addiu       $a0, $a0, 0x6BC0
    ctx->r4 = ADD32(ctx->r4, 0X6BC0);
    // 0x8001416C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80014170: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80014174: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014178: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8001417C: lhu         $t4, 0x5E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X5E);
    // 0x80014180: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x80014184: beq         $t5, $zero, L_80014198
    if (ctx->r13 == 0) {
        // 0x80014188: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_80014198;
    }
    // 0x80014188: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001418C: lwc1        $f8, -0x4530($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x80014190: b           L_800141C4
    // 0x80014194: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
        goto L_800141C4;
    // 0x80014194: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
L_80014198:
    // 0x80014198: lw          $t6, 0x64($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X64);
    // 0x8001419C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800141A0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800141A4: bnel        $t7, $at, L_800141C0
    if (ctx->r15 != ctx->r1) {
        // 0x800141A8: lwc1        $f16, 0x4($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
            goto L_800141C0;
    }
    goto skip_1;
    // 0x800141A8: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    skip_1:
    // 0x800141AC: lw          $t8, 0x68($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X68);
    // 0x800141B0: lwc1        $f10, 0x94($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X94);
    // 0x800141B4: b           L_800141C4
    // 0x800141B8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
        goto L_800141C4;
    // 0x800141B8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800141BC: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
L_800141C0:
    // 0x800141C0: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
L_800141C4:
    // 0x800141C4: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
    // 0x800141C8: ori         $t5, $a1, 0x40
    ctx->r13 = ctx->r5 | 0X40;
    // 0x800141CC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800141D0: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x800141D4: lw          $t1, 0x64($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X64);
    // 0x800141D8: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x800141DC: sw          $t1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r9;
    // 0x800141E0: lw          $t0, 0x68($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X68);
    // 0x800141E4: sw          $t0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r8;
    // 0x800141E8: lhu         $t2, 0x5E($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X5E);
    // 0x800141EC: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x800141F0: beql        $t3, $zero, L_80014228
    if (ctx->r11 == 0) {
        // 0x800141F4: lw          $v1, 0x64($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X64);
            goto L_80014228;
    }
    goto skip_2;
    // 0x800141F4: lw          $v1, 0x64($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X64);
    skip_2:
    // 0x800141F8: lw          $t9, 0x64($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X64);
    // 0x800141FC: lwc1        $f6, 0x24($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80014200: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x80014204: lwc1        $f4, 0x1C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80014208: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8001420C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80014210: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80014214: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80014218: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8001421C: b           L_8001428C
    // 0x80014220: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
        goto L_8001428C;
    // 0x80014220: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80014224: lw          $v1, 0x64($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X64);
L_80014228:
    // 0x80014228: lwc1        $f12, 0x1C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8001422C: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80014230: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80014234: nop

    // 0x80014238: bc1fl       L_8001426C
    if (!c1cs) {
        // 0x8001423C: lwc1        $f18, 0x24($a2)
        ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
            goto L_8001426C;
    }
    goto skip_3;
    // 0x8001423C: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
    skip_3:
    // 0x80014240: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80014244: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x80014248: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001424C: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80014250: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80014254: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80014258: add.d       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f0.d + ctx->f0.d;
    // 0x8001425C: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x80014260: b           L_8001428C
    // 0x80014264: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
        goto L_8001428C;
    // 0x80014264: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80014268: lwc1        $f18, 0x24($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X24);
L_8001426C:
    // 0x8001426C: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x80014270: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80014274: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80014278: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001427C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80014280: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x80014284: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x80014288: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8001428C:
    // 0x8001428C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80014290: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80014294: sw          $a0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r4;
    // 0x80014298: lhu         $t6, 0x5E($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X5E);
    // 0x8001429C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800142A0: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x800142A4: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800142A8: beql        $t7, $zero, L_800142D0
    if (ctx->r15 == 0) {
        // 0x800142AC: mtc1        $at, $f5
        ctx->f_odd[(5 - 1) * 2] = ctx->r1;
            goto L_800142D0;
    }
    goto skip_4;
    // 0x800142AC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    skip_4:
    // 0x800142B0: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x800142B4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800142B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800142BC: nop

    // 0x800142C0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800142C4: b           L_800142E0
    // 0x800142C8: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
        goto L_800142E0;
    // 0x800142C8: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x800142CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
L_800142D0:
    // 0x800142D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800142D4: nop

    // 0x800142D8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800142DC: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_800142E0:
    // 0x800142E0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800142E4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800142E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800142EC: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x800142F0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x800142F4: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800142F8: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800142FC: swc1        $f2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f2.u32l;
    // 0x80014300: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80014304: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80014308: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x8001430C: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80014310: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x80014314: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x80014318: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8001431C: lwc1        $f12, 0x54($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80014320: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80014324: jal         0x800232F4
    // 0x80014328: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80014328: swc1        $f10, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f10.u32l;
    after_0:
    // 0x8001432C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80014330: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014334: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x80014338: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8001433C: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80014340: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014344: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80014348: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001434C: lwc1        $f18, 0x58($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80014350: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80014354: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014358: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8001435C: ldc1        $f6, 0x1420($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1420);
    // 0x80014360: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80014364: addiu       $a0, $a0, 0x6BC0
    ctx->r4 = ADD32(ctx->r4, 0X6BC0);
    // 0x80014368: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8001436C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80014370: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014374: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80014378: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001437C: add.d       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f16.d + ctx->f8.d;
    // 0x80014380: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80014384: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80014388: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001438C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80014390: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80014394: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x80014398: lwc1        $f0, -0x4530($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x8001439C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800143A0: nop

    // 0x800143A4: bc1fl       L_800143B4
    if (!c1cs) {
        // 0x800143A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800143B4;
    }
    goto skip_5;
    // 0x800143A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800143AC: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x800143B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800143B4:
    // 0x800143B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800143B8: jr          $ra
    // 0x800143BC: nop

    return;
    // 0x800143BC: nop

;}
RECOMP_FUNC void func_80003870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003870: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80003874: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003878: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x8000387C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80003880: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80003884: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80003888: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x8000388C: addiu       $t8, $t8, 0xA0
    ctx->r24 = ADD32(ctx->r24, 0XA0);
    // 0x80003890: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80003894: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80003898: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8000389C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800038A0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800038A4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800038A8: jal         0x800111F8
    // 0x800038AC: lw          $a0, -0x43F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43F8);
    func_800111F8(rdram, ctx);
        goto after_0;
    // 0x800038AC: lw          $a0, -0x43F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43F8);
    after_0:
    // 0x800038B0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800038B4: lhu         $t9, -0x4548($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4548);
    // 0x800038B8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800038BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800038C0: beq         $t9, $at, L_800038D4
    if (ctx->r25 == ctx->r1) {
        // 0x800038C4: lui         $t1, 0x8008
        ctx->r9 = S32(0X8008 << 16);
            goto L_800038D4;
    }
    // 0x800038C4: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x800038C8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800038CC: bnel        $t9, $at, L_800038E0
    if (ctx->r25 != ctx->r1) {
        // 0x800038D0: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_800038E0;
    }
    goto skip_0;
    // 0x800038D0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    skip_0:
L_800038D4:
    // 0x800038D4: b           L_800038E0
    // 0x800038D8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_800038E0;
    // 0x800038D8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800038DC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800038E0:
    // 0x800038E0: lh          $t1, -0x44E4($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X44E4);
    // 0x800038E4: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x800038E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800038EC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800038F0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800038F4: lw          $t3, 0x3D00($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3D00);
    // 0x800038F8: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x800038FC: jal         0x80006720
    // 0x80003900: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    func_80006720(rdram, ctx);
        goto after_1;
    // 0x80003900: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_1:
    // 0x80003904: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80003908: lh          $t4, -0x44E2($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X44E2);
    // 0x8000390C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80003910: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003914: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80003918: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8000391C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80003920: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x80003924: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80003928: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8000392C: jal         0x8001DB38
    // 0x80003930: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    func_8001DB38(rdram, ctx);
        goto after_2;
    // 0x80003930: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x80003934: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80003938: lh          $t7, -0x44E2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X44E2);
    // 0x8000393C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80003940: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003944: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80003948: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8000394C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80003950: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003954: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x80003958: lhu         $a0, -0x44DC($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X44DC);
    // 0x8000395C: jal         0x8001E0AC
    // 0x80003960: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    func_8001E0AC(rdram, ctx);
        goto after_3;
    // 0x80003960: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80003964: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003968: jal         0x80006720
    // 0x8000396C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_80006720(rdram, ctx);
        goto after_4;
    // 0x8000396C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_4:
    // 0x80003970: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80003974: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80003978: addiu       $v1, $v1, -0x3A50
    ctx->r3 = ADD32(ctx->r3, -0X3A50);
    // 0x8000397C: addiu       $t0, $t0, -0x43C0
    ctx->r8 = ADD32(ctx->r8, -0X43C0);
    // 0x80003980: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003984: lwc1        $f14, -0x4530($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x80003988: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8000398C: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80003990: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x80003994: jal         0x8000EE60
    // 0x80003998: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    func_8000EE60(rdram, ctx);
        goto after_5;
    // 0x80003998: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    after_5:
    // 0x8000399C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800039A0: addiu       $v1, $v1, -0x3A50
    ctx->r3 = ADD32(ctx->r3, -0X3A50);
    // 0x800039A4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800039A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800039AC: addiu       $v0, $v0, -0x4410
    ctx->r2 = ADD32(ctx->r2, -0X4410);
    // 0x800039B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800039B4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800039B8: lwc1        $f6, -0x43BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X43BC);
    // 0x800039BC: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800039C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800039C4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800039C8: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800039CC: lwc1        $f10, -0x4504($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4504);
    // 0x800039D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800039D4: lwc1        $f16, -0x4500($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4500);
    // 0x800039D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800039DC: lwc1        $f18, -0x450C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X450C);
    // 0x800039E0: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x800039E4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800039E8: lw          $a3, -0x4508($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4508);
    // 0x800039EC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800039F0: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x800039F4: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800039F8: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800039FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80003A00: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80003A04: jal         0x80011860
    // 0x80003A08: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_80011860(rdram, ctx);
        goto after_6;
    // 0x80003A08: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80003A0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80003A10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80003A14: jr          $ra
    // 0x80003A18: nop

    return;
    // 0x80003A18: nop

;}
RECOMP_FUNC void func_80038D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038D74: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80038D78: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80038D7C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80038D80: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80038D84: ldc1        $f6, 0x1E50($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1E50);
    // 0x80038D88: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80038D8C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80038D90: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80038D94: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80038D98: bgez        $t7, L_80038DB0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80038D9C: cvt.d.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
            goto L_80038DB0;
    }
    // 0x80038D9C: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80038DA0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80038DA4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038DA8: nop

    // 0x80038DAC: add.d       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = ctx->f16.d + ctx->f18.d;
L_80038DB0:
    // 0x80038DB0: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80038DB4: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80038DB8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80038DBC: bgez        $a2, L_80038DD4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80038DC0: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_80038DD4;
    }
    // 0x80038DC0: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80038DC4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80038DC8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038DCC: nop

    // 0x80038DD0: add.d       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f10.d + ctx->f18.d;
L_80038DD4:
    // 0x80038DD4: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80038DD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80038DDC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80038DE0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80038DE4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80038DE8: nop

    // 0x80038DEC: cvt.w.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_D(ctx->f8.d);
    // 0x80038DF0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80038DF4: nop

    // 0x80038DF8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80038DFC: beql        $v0, $zero, L_80038E58
    if (ctx->r2 == 0) {
        // 0x80038E00: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_80038E58;
    }
    goto skip_0;
    // 0x80038E00: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80038E04: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80038E08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80038E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80038E10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80038E14: sub.d       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f16.d = ctx->f8.d - ctx->f16.d;
    // 0x80038E18: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80038E1C: nop

    // 0x80038E20: cvt.w.d     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_D(ctx->f16.d);
    // 0x80038E24: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80038E28: nop

    // 0x80038E2C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80038E30: bnel        $v0, $zero, L_80038E4C
    if (ctx->r2 != 0) {
        // 0x80038E34: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_80038E4C;
    }
    goto skip_1;
    // 0x80038E34: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_1:
    // 0x80038E38: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80038E3C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80038E40: jr          $ra
    // 0x80038E44: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    return;
    // 0x80038E44: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80038E48: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
L_80038E4C:
    // 0x80038E4C: jr          $ra
    // 0x80038E50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80038E50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80038E54: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_80038E58:
    // 0x80038E58: nop

    // 0x80038E5C: bltzl       $v0, L_80038E4C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80038E60: ctc1        $t8, $FpcCsr
        set_cop1_cs(ctx->r24);
            goto L_80038E4C;
    }
    goto skip_2;
    // 0x80038E60: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    skip_2:
    // 0x80038E64: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80038E68: jr          $ra
    // 0x80038E6C: nop

    return;
    // 0x80038E6C: nop

;}
RECOMP_FUNC void func_8000D9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D9BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000D9C0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D9C4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000D9C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000D9CC: addiu       $t0, $t0, -0x4D08
    ctx->r8 = ADD32(ctx->r8, -0X4D08);
    // 0x8000D9D0: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x8000D9D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000D9D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000D9DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D9E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000D9E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8000D9E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000D9EC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000D9F0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8000D9F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8000D9F8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000D9FC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000DA00: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000DA04: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x8000DA08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8000DA0C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8000DA10: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8000DA14: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x8000DA18: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8000DA1C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8000DA20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000DA24: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8000DA28: jal         0x80023500
    // 0x8000DA2C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_80023500(rdram, ctx);
        goto after_0;
    // 0x8000DA2C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8000DA30: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DA34: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000DA38: addiu       $t0, $t0, -0x4D08
    ctx->r8 = ADD32(ctx->r8, -0X4D08);
    // 0x8000DA3C: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8000DA40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000DA44: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8000DA48: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8000DA4C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000DA50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000DA54: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8000DA58: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8000DA5C: lui         $t5, 0x200
    ctx->r13 = S32(0X200 << 16);
    // 0x8000DA60: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x8000DA64: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8000DA68: addiu       $t4, $t3, 0xC0
    ctx->r12 = ADD32(ctx->r11, 0XC0);
    // 0x8000DA6C: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8000DA70: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000DA74: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8000DA78: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x8000DA7C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8000DA80: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8000DA84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000DA88: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8000DA8C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8000DA90: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000DA94: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000DA98: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8000DA9C: lw          $t5, 0x5BB4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5BB4);
    // 0x8000DAA0: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000DAA4: lw          $t9, 0x5BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5BB8);
    // 0x8000DAA8: lw          $t3, 0x5BB0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X5BB0);
    // 0x8000DAAC: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x8000DAB0: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8000DAB4: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8000DAB8: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8000DABC: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x8000DAC0: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8000DAC4: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8000DAC8: ori         $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 | 0XFF;
    // 0x8000DACC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8000DAD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000DAD4: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8000DAD8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000DADC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000DAE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000DAE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000DAE8: lw          $t6, 0x59E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X59E4);
    // 0x8000DAEC: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8000DAF0: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x8000DAF4: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8000DAF8: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8000DAFC: lw          $t8, -0x1054($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1054);
    // 0x8000DB00: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000DB04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000DB08: jr          $ra
    // 0x8000DB0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000DB0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80041F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041F7C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80041F80: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80041F84: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80041F88: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80041F8C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80041F90: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80041F94: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80041F98: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80041F9C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80041FA0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80041FA4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80041FA8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80041FAC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80041FB0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80041FB4: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x80041FB8: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x80041FBC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x80041FC0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80041FC4: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80041FC8: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x80041FCC: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x80041FD0: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x80041FD4: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x80041FD8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80041FDC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80041FE0: beql        $t8, $zero, L_80042454
    if (ctx->r24 == 0) {
        // 0x80041FE4: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_80042454;
    }
    goto skip_0;
    // 0x80041FE4: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    skip_0:
    // 0x80041FE8: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_80041FEC:
    // 0x80041FEC: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80041FF0: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x80041FF4: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80041FF8: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x80041FFC: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80042000: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x80042004: bne         $at, $zero, L_80042450
    if (ctx->r1 != 0) {
        // 0x80042008: sw          $t9, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r25;
            goto L_80042450;
    }
    // 0x80042008: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x8004200C: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x80042010: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x80042014: beq         $at, $zero, L_800423C8
    if (ctx->r1 == 0) {
        // 0x80042018: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800423C8;
    }
    // 0x80042018: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8004201C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80042020: addu        $at, $at, $t9
    gpr jr_addend_80042028 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80042024: lw          $t9, 0x2090($at)
    ctx->r25 = ADD32(ctx->r1, 0X2090);
    // 0x80042028: jr          $t9
    // 0x8004202C: nop

    switch (jr_addend_80042028 >> 2) {
        case 0: goto L_800423A8; break;
        case 1: goto L_800423C8; break;
        case 2: goto L_800423C8; break;
        case 3: goto L_800423C8; break;
        case 4: goto L_800423C8; break;
        case 5: goto L_800423C8; break;
        case 6: goto L_800423C8; break;
        case 7: goto L_800423C8; break;
        case 8: goto L_800423C8; break;
        case 9: goto L_800423C8; break;
        case 10: goto L_800423C8; break;
        case 11: goto L_80042170; break;
        case 12: goto L_80042170; break;
        case 13: goto L_80042030; break;
        case 14: goto L_80042314; break;
        case 15: goto L_80042368; break;
        case 16: goto L_80042170; break;
        default: switch_error(__func__, 0x80042028, 0x80072090);
    }
    // 0x8004202C: nop

L_80042030:
    // 0x80042030: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x80042034: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80042038: beql        $t6, $zero, L_80042058
    if (ctx->r14 == 0) {
        // 0x8004203C: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_80042058;
    }
    goto skip_1;
    // 0x8004203C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_1:
    // 0x80042040: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x80042044: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80042048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8004204C: jalr        $t9
    // 0x80042050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80042050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80042054: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_80042058:
    // 0x80042058: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8004205C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80042060: jalr        $t9
    // 0x80042064: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80042064: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x80042068: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8004206C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80042070: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80042074: jalr        $t9
    // 0x80042078: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80042078: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8004207C: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
    // 0x80042080: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x80042084: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80042088: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x8004208C: lh          $v1, 0x10($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X10);
    // 0x80042090: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042094: mflo        $a0
    ctx->r4 = lo;
    // 0x80042098: sra         $t7, $a0, 15
    ctx->r15 = S32(SIGNED(ctx->r4) >> 15);
    // 0x8004209C: sh          $t7, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r15;
    // 0x800420A0: lbu         $t6, 0x12($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X12);
    // 0x800420A4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800420A8: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800420AC: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800420B0: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800420B4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800420B8: lh          $t7, 0xC80($t7)
    ctx->r15 = MEM_H(ctx->r15, 0XC80);
    // 0x800420BC: sh          $t7, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r15;
    // 0x800420C0: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x800420C4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800420C8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800420CC: negu        $t8, $t9
    ctx->r24 = SUB32(0, ctx->r25);
    // 0x800420D0: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800420D4: lh          $t7, 0xD7E($t7)
    ctx->r15 = MEM_H(ctx->r15, 0XD7E);
    // 0x800420D8: sh          $t7, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r15;
    // 0x800420DC: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800420E0: beql        $t6, $zero, L_800420F8
    if (ctx->r14 == 0) {
        // 0x800420E4: lh          $v0, 0x18($fp)
        ctx->r2 = MEM_H(ctx->r30, 0X18);
            goto L_800420F8;
    }
    goto skip_2;
    // 0x800420E4: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    skip_2:
    // 0x800420E8: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800420EC: b           L_8004213C
    // 0x800420F0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
        goto L_8004213C;
    // 0x800420F0: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800420F4: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
L_800420F8:
    // 0x800420F8: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x800420FC: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x80042100: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80042104: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80042108: lh          $t8, 0xC80($t8)
    ctx->r24 = MEM_H(ctx->r24, 0XC80);
    // 0x8004210C: negu        $t9, $t9
    ctx->r25 = SUB32(0, ctx->r25);
    // 0x80042110: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042114: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80042118: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8004211C: mflo        $t7
    ctx->r15 = lo;
    // 0x80042120: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x80042124: sh          $t6, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r14;
    // 0x80042128: lh          $t8, 0xD7E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0XD7E);
    // 0x8004212C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042130: mflo        $t7
    ctx->r15 = lo;
    // 0x80042134: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x80042138: sh          $t6, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r14;
L_8004213C:
    // 0x8004213C: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x80042140: beql        $t9, $zero, L_80042408
    if (ctx->r25 == 0) {
        // 0x80042144: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_80042408;
    }
    goto skip_3;
    // 0x80042144: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_3:
    // 0x80042148: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004214C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80042150: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x80042154: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80042158: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8004215C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80042160: jalr        $t9
    // 0x80042164: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80042164: nop

    after_3:
    // 0x80042168: b           L_80042408
    // 0x8004216C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_80042408;
    // 0x8004216C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_80042170:
    // 0x80042170: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x80042174: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x80042178: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x8004217C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80042180: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80042184: jal         0x80041C34
    // 0x80042188: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_80041C34(rdram, ctx);
        goto after_4;
    // 0x80042188: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_4:
    // 0x8004218C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x80042190: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x80042194: lw          $a3, 0x30($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X30);
    // 0x80042198: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8004219C: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800421A0: bnel        $at, $zero, L_8004220C
    if (ctx->r1 != 0) {
        // 0x800421A4: lh          $t6, 0x1C($fp)
        ctx->r14 = MEM_H(ctx->r30, 0X1C);
            goto L_8004220C;
    }
    goto skip_4;
    // 0x800421A4: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
    skip_4:
    // 0x800421A8: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    // 0x800421AC: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800421B0: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x800421B4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800421B8: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800421BC: lh          $t7, 0xC80($t7)
    ctx->r15 = MEM_H(ctx->r15, 0XC80);
    // 0x800421C0: negu        $t8, $t8
    ctx->r24 = SUB32(0, ctx->r24);
    // 0x800421C4: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800421C8: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800421CC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800421D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800421D4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800421D8: sh          $t9, 0x28($fp)
    MEM_H(0X28, ctx->r30) = ctx->r25;
    // 0x800421DC: lh          $t7, 0xD7E($t7)
    ctx->r15 = MEM_H(ctx->r15, 0XD7E);
    // 0x800421E0: lh          $t8, 0x28($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X28);
    // 0x800421E4: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800421E8: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800421EC: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800421F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800421F4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800421F8: sh          $t9, 0x2E($fp)
    MEM_H(0X2E, ctx->r30) = ctx->r25;
    // 0x800421FC: lh          $t7, 0x2E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X2E);
    // 0x80042200: b           L_8004225C
    // 0x80042204: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
        goto L_8004225C;
    // 0x80042204: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
    // 0x80042208: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
L_8004220C:
    // 0x8004220C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80042210: lh          $a1, 0x26($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X26);
    // 0x80042214: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80042218: lhu         $a2, 0x24($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X24);
    // 0x8004221C: jal         0x80041ECC
    // 0x80042220: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_80041ECC(rdram, ctx);
        goto after_5;
    // 0x80042220: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x80042224: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042228: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    // 0x8004222C: lw          $a0, 0x30($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X30);
    // 0x80042230: lh          $a1, 0x2C($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X2C);
    // 0x80042234: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80042238: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8004223C: lhu         $a2, 0x2A($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X2A);
    // 0x80042240: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x80042244: jal         0x80041ECC
    // 0x80042248: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    func_80041ECC(rdram, ctx);
        goto after_6;
    // 0x80042248: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_6:
    // 0x8004224C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80042250: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80042254: nop

    // 0x80042258: sh          $t9, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r25;
L_8004225C:
    // 0x8004225C: lh          $t8, 0x1C($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X1C);
    // 0x80042260: bnel        $t8, $zero, L_80042270
    if (ctx->r24 != 0) {
        // 0x80042264: lh          $t7, 0x1E($fp)
        ctx->r15 = MEM_H(ctx->r30, 0X1E);
            goto L_80042270;
    }
    goto skip_5;
    // 0x80042264: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    skip_5:
    // 0x80042268: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x8004226C: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
L_80042270:
    // 0x80042270: bnel        $t7, $zero, L_80042280
    if (ctx->r15 != 0) {
        // 0x80042274: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_80042280;
    }
    goto skip_6;
    // 0x80042274: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_6:
    // 0x80042278: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x8004227C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_80042280:
    // 0x80042280: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80042284: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x80042288: bnel        $a0, $at, L_800422A0
    if (ctx->r4 != ctx->r1) {
        // 0x8004228C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800422A0;
    }
    goto skip_7;
    // 0x8004228C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_7:
    // 0x80042290: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80042294: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x80042298: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x8004229C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_800422A0:
    // 0x800422A0: bnel        $a0, $at, L_800422D0
    if (ctx->r4 != ctx->r1) {
        // 0x800422A4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800422D0;
    }
    goto skip_8;
    // 0x800422A4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x800422A8: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800422AC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800422B0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800422B4: mflo        $v0
    ctx->r2 = lo;
    // 0x800422B8: sra         $t9, $v0, 15
    ctx->r25 = S32(SIGNED(ctx->r2) >> 15);
    // 0x800422BC: sh          $t9, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r25;
    // 0x800422C0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x800422C4: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800422C8: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800422CC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_800422D0:
    // 0x800422D0: bne         $a0, $at, L_8004230C
    if (ctx->r4 != ctx->r1) {
        // 0x800422D4: nop
    
            goto L_8004230C;
    }
    // 0x800422D4: nop

    // 0x800422D8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800422DC: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x800422E0: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800422E4: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800422E8: lh          $t9, 0xC80($t9)
    ctx->r25 = MEM_H(ctx->r25, 0XC80);
    // 0x800422EC: sh          $t9, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r25;
    // 0x800422F0: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800422F4: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x800422F8: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800422FC: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x80042300: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80042304: lh          $t9, 0xD7E($t9)
    ctx->r25 = MEM_H(ctx->r25, 0XD7E);
    // 0x80042308: sh          $t9, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r25;
L_8004230C:
    // 0x8004230C: b           L_80042404
    // 0x80042310: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
        goto L_80042404;
    // 0x80042310: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
L_80042314:
    // 0x80042314: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x80042318: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8004231C: beql        $t8, $zero, L_8004233C
    if (ctx->r24 == 0) {
        // 0x80042320: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_8004233C;
    }
    goto skip_9;
    // 0x80042320: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_9:
    // 0x80042324: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x80042328: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8004232C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80042330: jalr        $t9
    // 0x80042334: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80042334: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80042338: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_8004233C:
    // 0x8004233C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80042340: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80042344: jalr        $t9
    // 0x80042348: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x80042348: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x8004234C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x80042350: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80042354: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80042358: jalr        $t9
    // 0x8004235C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8004235C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80042360: b           L_80042408
    // 0x80042364: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_80042408;
    // 0x80042364: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_80042368:
    // 0x80042368: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x8004236C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x80042370: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x80042374: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80042378: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x8004237C: jal         0x80041C34
    // 0x80042380: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_80041C34(rdram, ctx);
        goto after_10;
    // 0x80042380: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_10:
    // 0x80042384: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x80042388: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x8004238C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80042390: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80042394: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80042398: jalr        $t9
    // 0x8004239C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x8004239C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800423A0: b           L_80042408
    // 0x800423A4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_80042408;
    // 0x800423A4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800423A8:
    // 0x800423A8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800423AC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800423B0: lw          $a0, 0x990($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X990);
    // 0x800423B4: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x800423B8: jal         0x80036980
    // 0x800423BC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    func_80036980(rdram, ctx);
        goto after_12;
    // 0x800423BC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_12:
    // 0x800423C0: b           L_80042408
    // 0x800423C4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_80042408;
    // 0x800423C4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800423C8:
    // 0x800423C8: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800423CC: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800423D0: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800423D4: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800423D8: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800423DC: jal         0x80041C34
    // 0x800423E0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_80041C34(rdram, ctx);
        goto after_13;
    // 0x800423E0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_13:
    // 0x800423E4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800423E8: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800423EC: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    // 0x800423F0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800423F4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800423F8: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x800423FC: jalr        $t9
    // 0x80042400: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x80042400: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_14:
L_80042404:
    // 0x80042404: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_80042408:
    // 0x80042408: lh          $t6, 0x8E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8E);
    // 0x8004240C: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80042410: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80042414: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80042418: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
    // 0x8004241C: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x80042420: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x80042424: lw          $a0, 0x3C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X3C);
    // 0x80042428: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8004242C: bne         $t9, $zero, L_80042438
    if (ctx->r25 != 0) {
        // 0x80042430: sw          $t9, 0x3C($fp)
        MEM_W(0X3C, ctx->r30) = ctx->r25;
            goto L_80042438;
    }
    // 0x80042430: sw          $t9, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r25;
    // 0x80042434: sw          $zero, 0x40($fp)
    MEM_W(0X40, ctx->r30) = 0;
L_80042438:
    // 0x80042438: jal         0x80036A18
    // 0x8004243C: nop

    func_80036A18(rdram, ctx);
        goto after_15;
    // 0x8004243C: nop

    after_15:
    // 0x80042440: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x80042444: lw          $t7, 0x3C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X3C);
    // 0x80042448: bnel        $t7, $zero, L_80041FEC
    if (ctx->r15 != 0) {
        // 0x8004244C: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_80041FEC;
    }
    goto skip_10;
    // 0x8004244C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_10:
L_80042450:
    // 0x80042450: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
L_80042454:
    // 0x80042454: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x80042458: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x8004245C: lw          $s5, 0xB0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB0);
    // 0x80042460: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x80042464: jal         0x80041C34
    // 0x80042468: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_80041C34(rdram, ctx);
        goto after_16;
    // 0x80042468: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_16:
    // 0x8004246C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x80042470: lw          $t9, 0x30($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X30);
    // 0x80042474: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x80042478: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8004247C: beql        $at, $zero, L_8004248C
    if (ctx->r1 == 0) {
        // 0x80042480: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8004248C;
    }
    goto skip_11;
    // 0x80042480: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_11:
    // 0x80042484: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x80042488: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8004248C:
    // 0x8004248C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x80042490: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80042494: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80042498: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8004249C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800424A0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800424A4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800424A8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800424AC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800424B0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800424B4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800424B8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800424BC: jr          $ra
    // 0x800424C0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800424C0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800424C4: nop

    // 0x800424C8: nop

    // 0x800424CC: nop

;}
RECOMP_FUNC void func_80016940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016948: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001694C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016950: lhu         $t6, 0x5E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X5E);
    // 0x80016954: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016958: addiu       $v0, $v0, -0x3670
    ctx->r2 = ADD32(ctx->r2, -0X3670);
    // 0x8001695C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016960: beq         $t7, $zero, L_8001697C
    if (ctx->r15 == 0) {
        // 0x80016964: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8001697C;
    }
    // 0x80016964: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80016968: sh          $t8, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r24;
    // 0x8001696C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80016970: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80016974: b           L_800169B8
    // 0x80016978: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_800169B8;
    // 0x80016978: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_8001697C:
    // 0x8001697C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80016980: addiu       $a1, $a1, -0x3A6E
    ctx->r5 = ADD32(ctx->r5, -0X3A6E);
    // 0x80016984: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80016988: andi        $t1, $v1, 0x100
    ctx->r9 = ctx->r3 & 0X100;
    // 0x8001698C: bne         $t1, $zero, L_800169B0
    if (ctx->r9 != 0) {
        // 0x80016990: ori         $t2, $v1, 0x10
        ctx->r10 = ctx->r3 | 0X10;
            goto L_800169B0;
    }
    // 0x80016990: ori         $t2, $v1, 0x10
    ctx->r10 = ctx->r3 | 0X10;
    // 0x80016994: sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
    // 0x80016998: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001699C: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
    // 0x800169A0: lhu         $t3, 0x2A($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2A);
    // 0x800169A4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800169A8: b           L_800169B8
    // 0x800169AC: sh          $t4, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r12;
        goto L_800169B8;
    // 0x800169AC: sh          $t4, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r12;
L_800169B0:
    // 0x800169B0: jal         0x800208B8
    // 0x800169B4: nop

    func_800208B8(rdram, ctx);
        goto after_0;
    // 0x800169B4: nop

    after_0:
L_800169B8:
    // 0x800169B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800169BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800169C0: jr          $ra
    // 0x800169C4: nop

    return;
    // 0x800169C4: nop

;}
RECOMP_FUNC void alSaveNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040098: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8004009C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800400A0: addiu       $a2, $a2, 0x25E0
    ctx->r6 = ADD32(ctx->r6, 0X25E0);
    // 0x800400A4: addiu       $a1, $a1, 0x2614
    ctx->r5 = ADD32(ctx->r5, 0X2614);
    // 0x800400A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800400AC: jal         0x80048AC0
    // 0x800400B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800400B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x800400B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800400B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800400BC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800400C0: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800400C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800400C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800400CC: jr          $ra
    // 0x800400D0: nop

    return;
    // 0x800400D0: nop

;}
RECOMP_FUNC void func_80101880_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101880: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101884: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101888: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8010188C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80101890: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80101894: jr          $ra
    // 0x80101898: sh          $zero, 0x701C($at)
    MEM_H(0X701C, ctx->r1) = 0;
    return;
    // 0x80101898: sh          $zero, 0x701C($at)
    MEM_H(0X701C, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80042C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042C2C: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x80042C30: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80042C34: bne         $t6, $at, L_80042C9C
    if (ctx->r14 != ctx->r1) {
        // 0x80042C38: nop
    
            goto L_80042C9C;
    }
    // 0x80042C38: nop

    // 0x80042C3C: lbu         $t7, 0x9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9);
    // 0x80042C40: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80042C44: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80042C48: bne         $t7, $at, L_80042C9C
    if (ctx->r15 != ctx->r1) {
        // 0x80042C4C: nop
    
            goto L_80042C9C;
    }
    // 0x80042C4C: nop

    // 0x80042C50: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80042C54: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x80042C58: lw          $a2, 0x18($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X18);
    // 0x80042C5C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80042C60: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x80042C64: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80042C68: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80042C6C: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x80042C70: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80042C74: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80042C78: beq         $a2, $zero, L_80042C98
    if (ctx->r6 == 0) {
        // 0x80042C7C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80042C98;
    }
    // 0x80042C7C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80042C80: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80042C84: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80042C88: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80042C8C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80042C90: jr          $ra
    // 0x80042C94: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    return;
    // 0x80042C94: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
L_80042C98:
    // 0x80042C98: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
L_80042C9C:
    // 0x80042C9C: jr          $ra
    // 0x80042CA0: nop

    return;
    // 0x80042CA0: nop

;}
RECOMP_FUNC void func_800099DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800099DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800099E0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800099E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800099E8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800099EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800099F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800099F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800099F8: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800099FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009A00: beql        $v0, $zero, L_80009A24
    if (ctx->r2 == 0) {
        // 0x80009A04: lw          $t6, 0x1C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1C);
            goto L_80009A24;
    }
    goto skip_0;
    // 0x80009A04: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x80009A08: beq         $v0, $at, L_80009A98
    if (ctx->r2 == ctx->r1) {
        // 0x80009A0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80009A98;
    }
    // 0x80009A0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80009A10: beq         $v0, $at, L_80009D10
    if (ctx->r2 == ctx->r1) {
        // 0x80009A14: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80009D10;
    }
    // 0x80009A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009A18: b           L_80009D68
    // 0x80009A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009D68;
    // 0x80009A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009A20: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
L_80009A24:
    // 0x80009A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009A28: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009A2C: lhu         $v0, 0x2($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X2);
    // 0x80009A30: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80009A34: beql        $t7, $zero, L_80009A68
    if (ctx->r15 == 0) {
        // 0x80009A38: lh          $t8, 0x2($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X2);
            goto L_80009A68;
    }
    goto skip_1;
    // 0x80009A38: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    skip_1:
    // 0x80009A3C: jal         0x8000A7D8
    // 0x80009A40: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    func_8000A7D8(rdram, ctx);
        goto after_0;
    // 0x80009A40: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    after_0:
    // 0x80009A44: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009A48: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80009A4C: lw          $a2, -0x2F2C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2F2C);
    // 0x80009A50: lw          $a1, -0x2F30($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2F30);
    // 0x80009A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009A58: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80009A5C: jal         0x8000A508
    // 0x80009A60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_1;
    // 0x80009A60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x80009A64: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
L_80009A68:
    // 0x80009A68: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80009A6C: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x80009A70: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80009A74: bnel        $t0, $zero, L_80009D68
    if (ctx->r8 != 0) {
        // 0x80009A78: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009D68;
    }
    goto skip_2;
    // 0x80009A78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80009A7C: lhu         $t1, 0x6($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6);
    // 0x80009A80: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    // 0x80009A84: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80009A88: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x80009A8C: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x80009A90: b           L_80009D64
    // 0x80009A94: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
        goto L_80009D64;
    // 0x80009A94: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
L_80009A98:
    // 0x80009A98: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x80009A9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009AA0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009AA4: lhu         $v0, 0x2($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X2);
    // 0x80009AA8: andi        $t6, $v0, 0xA
    ctx->r14 = ctx->r2 & 0XA;
    // 0x80009AAC: beq         $t6, $zero, L_80009ADC
    if (ctx->r14 == 0) {
        // 0x80009AB0: nop
    
            goto L_80009ADC;
    }
    // 0x80009AB0: nop

    // 0x80009AB4: jal         0x8000A7D8
    // 0x80009AB8: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    func_8000A7D8(rdram, ctx);
        goto after_2;
    // 0x80009AB8: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    after_2:
    // 0x80009ABC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009AC0: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x80009AC4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009AC8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009ACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009AD0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80009AD4: jal         0x8000A508
    // 0x80009AD8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_3;
    // 0x80009AD8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
L_80009ADC:
    // 0x80009ADC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80009AE0: addiu       $v1, $v1, -0x4548
    ctx->r3 = ADD32(ctx->r3, -0X4548);
    // 0x80009AE4: lhu         $t7, 0x74($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X74);
    // 0x80009AE8: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80009AEC: bnel        $t8, $zero, L_80009C38
    if (ctx->r24 != 0) {
        // 0x80009AF0: lh          $t5, 0x2($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X2);
            goto L_80009C38;
    }
    goto skip_3;
    // 0x80009AF0: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    skip_3:
    // 0x80009AF4: lhu         $t9, 0x8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X8);
    // 0x80009AF8: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80009AFC: bnel        $t0, $zero, L_80009C38
    if (ctx->r8 != 0) {
        // 0x80009B00: lh          $t5, 0x2($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X2);
            goto L_80009C38;
    }
    goto skip_4;
    // 0x80009B00: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    skip_4:
    // 0x80009B04: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80009B08: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80009B0C: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80009B10: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80009B14: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80009B18: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80009B1C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80009B20: nop

    // 0x80009B24: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009B28: jal         0x80034F60
    // 0x80009B2C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_4;
    // 0x80009B2C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x80009B30: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80009B34: addiu       $v1, $v1, -0x4548
    ctx->r3 = ADD32(ctx->r3, -0X4548);
    // 0x80009B38: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x80009B3C: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x80009B40: lw          $t2, 0x1C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C);
    // 0x80009B44: lwc1        $f6, 0x18($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80009B48: lwc1        $f16, 0x24($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80009B4C: lwc1        $f10, 0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80009B50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80009B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009B58: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80009B5C: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80009B60: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80009B64: nop

    // 0x80009B68: bc1fl       L_80009C38
    if (!c1cs) {
        // 0x80009B6C: lh          $t5, 0x2($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X2);
            goto L_80009C38;
    }
    goto skip_5;
    // 0x80009B6C: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    skip_5:
    // 0x80009B70: jal         0x8000ABF4
    // 0x80009B74: nop

    func_8000ABF4(rdram, ctx);
        goto after_5;
    // 0x80009B74: nop

    after_5:
    // 0x80009B78: beq         $v0, $zero, L_80009C08
    if (ctx->r2 == 0) {
        // 0x80009B7C: nop
    
            goto L_80009C08;
    }
    // 0x80009B7C: nop

    // 0x80009B80: jal         0x8000AC84
    // 0x80009B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000AC84(rdram, ctx);
        goto after_6;
    // 0x80009B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80009B88: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80009B8C: ori         $a1, $zero, 0x8004
    ctx->r5 = 0 | 0X8004;
    // 0x80009B90: jal         0x80006BEC
    // 0x80009B94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80006BEC(rdram, ctx);
        goto after_7;
    // 0x80009B94: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_7:
    // 0x80009B98: lhu         $t3, 0x90($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X90);
    // 0x80009B9C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80009BA0: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x80009BA4: andi        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 & 0X2;
    // 0x80009BA8: beq         $t4, $zero, L_80009C28
    if (ctx->r12 == 0) {
        // 0x80009BAC: sra         $t5, $v1, 2
        ctx->r13 = S32(SIGNED(ctx->r3) >> 2);
            goto L_80009C28;
    }
    // 0x80009BAC: sra         $t5, $v1, 2
    ctx->r13 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80009BB0: lhu         $t7, 0xA($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XA);
    // 0x80009BB4: addiu       $v1, $t5, 0x1
    ctx->r3 = ADD32(ctx->r13, 0X1);
    // 0x80009BB8: andi        $a2, $v1, 0xFFFF
    ctx->r6 = ctx->r3 & 0XFFFF;
    // 0x80009BBC: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x80009BC0: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
    // 0x80009BC4: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x80009BC8: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x80009BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80009BD0: lhu         $a0, 0x6($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X6);
    // 0x80009BD4: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80009BD8: beq         $at, $zero, L_80009BE4
    if (ctx->r1 == 0) {
        // 0x80009BDC: nop
    
            goto L_80009BE4;
    }
    // 0x80009BDC: nop

    // 0x80009BE0: sh          $a0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r4;
L_80009BE4:
    // 0x80009BE4: jal         0x80018DF4
    // 0x80009BE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80018DF4(rdram, ctx);
        goto after_8;
    // 0x80009BE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80009BEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009BF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80009BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009BF8: jal         0x8001FCF8
    // 0x80009BFC: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_8001FCF8(rdram, ctx);
        goto after_9;
    // 0x80009BFC: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_9:
    // 0x80009C00: b           L_80009C2C
    // 0x80009C04: lhu         $t3, 0x8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X8);
        goto L_80009C2C;
    // 0x80009C04: lhu         $t3, 0x8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X8);
L_80009C08:
    // 0x80009C08: jal         0x80006F6C
    // 0x80009C0C: nop

    func_80006F6C(rdram, ctx);
        goto after_10;
    // 0x80009C0C: nop

    after_10:
    // 0x80009C10: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80009C14: addiu       $v1, $v1, -0x4548
    ctx->r3 = ADD32(ctx->r3, -0X4548);
    // 0x80009C18: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x80009C1C: lhu         $t1, 0x2C($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X2C);
    // 0x80009C20: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80009C24: sh          $t2, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r10;
L_80009C28:
    // 0x80009C28: lhu         $t3, 0x8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X8);
L_80009C2C:
    // 0x80009C2C: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x80009C30: sh          $t4, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r12;
    // 0x80009C34: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
L_80009C38:
    // 0x80009C38: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80009C3C: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x80009C40: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x80009C44: bnel        $t7, $zero, L_80009D68
    if (ctx->r15 != 0) {
        // 0x80009C48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009D68;
    }
    goto skip_6;
    // 0x80009C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80009C4C: lhu         $t8, 0x6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6);
    // 0x80009C50: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80009C54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009C58: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80009C5C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x80009C60: lh          $t0, 0xA($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XA);
    // 0x80009C64: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80009C68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80009C6C: bnel        $t0, $at, L_80009CA4
    if (ctx->r8 != ctx->r1) {
        // 0x80009C70: lh          $t9, 0xC($v0)
        ctx->r25 = MEM_H(ctx->r2, 0XC);
            goto L_80009CA4;
    }
    goto skip_7;
    // 0x80009C70: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    skip_7:
    // 0x80009C74: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x80009C78: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80009C7C: lhu         $t6, 0x4($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X4);
    // 0x80009C80: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80009C84: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80009C88: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80009C8C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80009C90: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x80009C94: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80009C98: b           L_80009CEC
    // 0x80009C9C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
        goto L_80009CEC;
    // 0x80009C9C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80009CA0: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
L_80009CA4:
    // 0x80009CA4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80009CA8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80009CAC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80009CB0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80009CB4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80009CB8: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x80009CBC: lh          $t1, 0x2($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X2);
    // 0x80009CC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80009CC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80009CC8: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x80009CCC: lh          $a1, 0xC($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XC);
    // 0x80009CD0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80009CD4: jal         0x8001D8B0
    // 0x80009CD8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8001D8B0(rdram, ctx);
        goto after_11;
    // 0x80009CD8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_11:
    // 0x80009CDC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009CE0: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    // 0x80009CE4: jal         0x8000A7D8
    // 0x80009CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000A7D8(rdram, ctx);
        goto after_12;
    // 0x80009CE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
L_80009CEC:
    // 0x80009CEC: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x80009CF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80009CF4: bgtz        $t5, L_80009D00
    if (SIGNED(ctx->r13) > 0) {
        // 0x80009CF8: nop
    
            goto L_80009D00;
    }
    // 0x80009CF8: nop

    // 0x80009CFC: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
L_80009D00:
    // 0x80009D00: jal         0x8001D358
    // 0x80009D04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001D358(rdram, ctx);
        goto after_13;
    // 0x80009D04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80009D08: b           L_80009D68
    // 0x80009D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80009D68;
    // 0x80009D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009D10:
    // 0x80009D10: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009D14: jal         0x8000A7D8
    // 0x80009D18: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    func_8000A7D8(rdram, ctx);
        goto after_14;
    // 0x80009D18: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    after_14:
    // 0x80009D1C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009D20: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x80009D24: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009D28: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009D2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80009D30: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80009D34: jal         0x8000A508
    // 0x80009D38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000A508(rdram, ctx);
        goto after_15;
    // 0x80009D38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_15:
    // 0x80009D3C: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x80009D40: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80009D44: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x80009D48: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80009D4C: bnel        $t8, $zero, L_80009D68
    if (ctx->r24 != 0) {
        // 0x80009D50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80009D68;
    }
    goto skip_8;
    // 0x80009D50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80009D54: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80009D58: lhu         $t0, 0x60($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X60);
    // 0x80009D5C: andi        $t2, $t0, 0xFFFE
    ctx->r10 = ctx->r8 & 0XFFFE;
    // 0x80009D60: sh          $t2, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r10;
L_80009D64:
    // 0x80009D64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80009D68:
    // 0x80009D68: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80009D6C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80009D70: jr          $ra
    // 0x80009D74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009D74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80002428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002428: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000242C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80002430: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x80002434: addiu       $fp, $fp, -0x4CB8
    ctx->r30 = ADD32(ctx->r30, -0X4CB8);
    // 0x80002438: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000243C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002440: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002444: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002448: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000244C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002450: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002454: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002458: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000245C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80002460: jal         0x80031C78
    // 0x80002464: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    func_80031C78(rdram, ctx);
        goto after_0;
    // 0x80002464: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    after_0:
    // 0x80002468: jal         0x80100000
    // 0x8000246C: nop

    LOOKUP_FUNC(0x80100000)(rdram, ctx);
        goto after_1;
    // 0x8000246C: nop

    after_1:
    // 0x80002470: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80002474: lhu         $t6, -0x4D20($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4D20);
    // 0x80002478: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000247C: ori         $s7, $zero, 0xD150
    ctx->r23 = 0 | 0XD150;
    // 0x80002480: bne         $t6, $at, L_80002578
    if (ctx->r14 != ctx->r1) {
        // 0x80002484: lui         $s6, 0x8030
        ctx->r22 = S32(0X8030 << 16);
            goto L_80002578;
    }
    // 0x80002484: lui         $s6, 0x8030
    ctx->r22 = S32(0X8030 << 16);
    // 0x80002488: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x8000248C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80002490: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x80002494: addiu       $s4, $s4, -0x4D0C
    ctx->r20 = ADD32(ctx->r20, -0X4D0C);
    // 0x80002498: addiu       $s6, $s6, 0x1000
    ctx->r22 = ADD32(ctx->r22, 0X1000);
    // 0x8000249C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800024A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800024A4: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
L_800024A8:
    // 0x800024A8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800024AC: jal         0x800314C0
    // 0x800024B0: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    func_800314C0(rdram, ctx);
        goto after_2;
    // 0x800024B0: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    after_2:
    // 0x800024B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800024B8: jal         0x80026658
    // 0x800024BC: sw          $zero, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = 0;
    func_80026658(rdram, ctx);
        goto after_3;
    // 0x800024BC: sw          $zero, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = 0;
    after_3:
    // 0x800024C0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800024C4: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800024C8: mflo        $t8
    ctx->r24 = lo;
    // 0x800024CC: addu        $a0, $s6, $t8
    ctx->r4 = ADD32(ctx->r22, ctx->r24);
    // 0x800024D0: jal         0x800011DC
    // 0x800024D4: nop

    func_800011DC(rdram, ctx);
        goto after_4;
    // 0x800024D4: nop

    after_4:
    // 0x800024D8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800024DC: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800024E0: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800024E4: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x800024E8: mflo        $t0
    ctx->r8 = lo;
    // 0x800024EC: addu        $s5, $s6, $t0
    ctx->r21 = ADD32(ctx->r22, ctx->r8);
    // 0x800024F0: bnel        $v0, $zero, L_80002528
    if (ctx->r2 != 0) {
        // 0x800024F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002528;
    }
    goto skip_0;
    // 0x800024F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800024F8: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
    // 0x800024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002500:
    // 0x80002500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80002504: jal         0x80034020
    // 0x80002508: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80002508: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x8000250C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80002510: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80002514: bnel        $s2, $t3, L_80002500
    if (ctx->r18 != ctx->r11) {
        // 0x80002518: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002500;
    }
    goto skip_1;
    // 0x80002518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8000251C: b           L_80002544
    // 0x80002520: nop

        goto L_80002544;
    // 0x80002520: nop

    // 0x80002524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002528:
    // 0x80002528: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000252C: jal         0x80034020
    // 0x80002530: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80002530: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x80002534: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80002538: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8000253C: bnel        $s3, $t5, L_80002528
    if (ctx->r19 != ctx->r13) {
        // 0x80002540: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002528;
    }
    goto skip_2;
    // 0x80002540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_80002544:
    // 0x80002544: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002548: lw          $a0, -0x4628($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4628);
    // 0x8000254C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80002550: jal         0x80034200
    // 0x80002554: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80002554: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_7:
    // 0x80002558: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8000255C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80002560: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80002564: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80002568: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x8000256C: lhu         $t8, -0x4D20($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4D20);
    // 0x80002570: beq         $t8, $at, L_800024A8
    if (ctx->r24 == ctx->r1) {
        // 0x80002574: nop
    
            goto L_800024A8;
    }
    // 0x80002574: nop

L_80002578:
    // 0x80002578: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000257C: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x80002580: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80002584: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80002588: jal         0x800267B8
    // 0x8000258C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    UpdateBGM(rdram, ctx);
        goto after_8;
    // 0x8000258C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_8:
    // 0x80002590: jal         0x80026658
    // 0x80002594: nop

    func_80026658(rdram, ctx);
        goto after_9;
    // 0x80002594: nop

    after_9:
    // 0x80002598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8000259C:
    // 0x8000259C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800025A0: jal         0x80034020
    // 0x800025A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x800025A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800025A8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800025AC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800025B0: bnel        $s3, $t0, L_8000259C
    if (ctx->r19 != ctx->r8) {
        // 0x800025B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000259C;
    }
    goto skip_3;
    // 0x800025B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x800025B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800025BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800025C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800025C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800025C8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800025CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800025D0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800025D4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800025D8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800025DC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800025E0: jr          $ra
    // 0x800025E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800025E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8003228C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003228C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032294: jal         0x80034350
    // 0x80032298: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80032298: nop

    after_0:
    // 0x8003229C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800322A0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800322A4: addiu       $a1, $a1, 0x2D2C
    ctx->r5 = ADD32(ctx->r5, 0X2D2C);
    // 0x800322A8: lw          $a0, 0x2D28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2D28);
    // 0x800322AC: jal         0x80034020
    // 0x800322B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800322B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800322B4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800322B8: lw          $t6, 0x2D1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2D1C);
    // 0x800322BC: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x800322C0: beql        $t6, $zero, L_80032320
    if (ctx->r14 == 0) {
        // 0x800322C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032320;
    }
    goto skip_0;
    // 0x800322C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800322C8: lw          $t7, -0x1B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1B4C);
    // 0x800322CC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800322D0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800322D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800322D8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800322DC: jal         0x80034750
    // 0x800322E0: lw          $a0, -0x1B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B48);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x800322E0: lw          $a0, -0x1B48($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B48);
    after_2:
    // 0x800322E4: lui         $v1, 0x8007
    ctx->r3 = S32(0X8007 << 16);
    // 0x800322E8: addiu       $v1, $v1, -0x1B4C
    ctx->r3 = ADD32(ctx->r3, -0X1B4C);
    // 0x800322EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800322F0: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x800322F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800322F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800322FC: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80032300: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80032304: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80032308: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8003230C: lw          $t2, -0x1B48($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1B48);
    // 0x80032310: sw          $t2, 0x2D20($at)
    MEM_W(0X2D20, ctx->r1) = ctx->r10;
    // 0x80032314: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032318: sw          $zero, 0x2D1C($at)
    MEM_W(0X2D1C, ctx->r1) = 0;
    // 0x8003231C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032320:
    // 0x80032320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032324: jr          $ra
    // 0x80032328: nop

    return;
    // 0x80032328: nop

;}
RECOMP_FUNC void alSndpSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039A10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80039A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039A18: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80039A1C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80039A20: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80039A24: sh          $t7, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r15;
    // 0x80039A28: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x80039A2C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x80039A30: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x80039A34: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80039A38: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80039A3C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80039A40: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80039A44: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80039A48: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80039A4C: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80039A50: jal         0x8003FE6C
    // 0x80039A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80039A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80039A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039A5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80039A60: jr          $ra
    // 0x80039A64: nop

    return;
    // 0x80039A64: nop

;}
RECOMP_FUNC void func_80100184_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100184: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80100188: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8010018C: addiu       $v0, $v0, 0x6FD8
    ctx->r2 = ADD32(ctx->r2, 0X6FD8);
    // 0x80100190: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80100194: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80100198: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8010019C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x801001A0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x801001A4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x801001A8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x801001AC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x801001B0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x801001B4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x801001B8: bne         $t6, $zero, L_801001D8
    if (ctx->r14 != 0) {
        // 0x801001BC: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_801001D8;
    }
    // 0x801001BC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x801001C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801001C4: sw          $zero, 0x3B0C($at)
    MEM_W(0X3B0C, ctx->r1) = 0;
    // 0x801001C8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x801001CC: sw          $zero, 0x6FD0($at)
    MEM_W(0X6FD0, ctx->r1) = 0;
    // 0x801001D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801001D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_801001D8:
    // 0x801001D8: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x801001DC: lw          $t8, 0x6FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FD0);
    // 0x801001E0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x801001E4: lw          $t2, 0x3B0C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3B0C);
    // 0x801001E8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x801001EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801001F0: sw          $t9, 0x6FD0($at)
    MEM_W(0X6FD0, ctx->r1) = ctx->r25;
    // 0x801001F4: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x801001F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801001FC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80100200: addiu       $s4, $s4, 0x6FDC
    ctx->r20 = ADD32(ctx->r20, 0X6FDC);
    // 0x80100204: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80100208: sw          $t3, 0x3B0C($at)
    MEM_W(0X3B0C, ctx->r1) = ctx->r11;
    // 0x8010020C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80100210: addiu       $v1, $v1, 0x6FE4
    ctx->r3 = ADD32(ctx->r3, 0X6FE4);
    // 0x80100214: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80100218: addiu       $s6, $zero, 0x28
    ctx->r22 = ADD32(0, 0X28);
    // 0x8010021C: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100220: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80100224: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80100228: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8010022C: lw          $t6, 0x35A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X35A0);
    // 0x80100230: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80100234: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80100238: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8010023C: lw          $t8, 0x61B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X61B0);
    // 0x80100240: mflo        $t2
    ctx->r10 = lo;
    // 0x80100244: addu        $v0, $t8, $t2
    ctx->r2 = ADD32(ctx->r24, ctx->r10);
    // 0x80100248: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8010024C: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80100250: bnel        $at, $zero, L_80100548
    if (ctx->r1 != 0) {
        // 0x80100254: addiu       $s7, $zero, 0xC
        ctx->r23 = ADD32(0, 0XC);
            goto L_80100548;
    }
    goto skip_0;
    // 0x80100254: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    skip_0:
    // 0x80100258: lh          $t5, 0x22($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X22);
    // 0x8010025C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80100260: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80100264: bnel        $t5, $at, L_80100548
    if (ctx->r13 != ctx->r1) {
        // 0x80100268: addiu       $s7, $zero, 0xC
        ctx->r23 = ADD32(0, 0XC);
            goto L_80100548;
    }
    goto skip_1;
    // 0x80100268: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    skip_1:
    // 0x8010026C: lw          $t6, 0x35A4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X35A4);
    // 0x80100270: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x80100274: addiu       $s5, $s5, 0x6FD4
    ctx->r21 = ADD32(ctx->r21, 0X6FD4);
    // 0x80100278: bne         $t6, $zero, L_80100544
    if (ctx->r14 != 0) {
        // 0x8010027C: addiu       $s7, $zero, 0xC
        ctx->r23 = ADD32(0, 0XC);
            goto L_80100544;
    }
    // 0x8010027C: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x80100280: lui         $fp, 0x8015
    ctx->r30 = S32(0X8015 << 16);
    // 0x80100284: addiu       $fp, $fp, 0x6FE0
    ctx->r30 = ADD32(ctx->r30, 0X6FE0);
L_80100288:
    // 0x80100288: jal         0x80100C98
    // 0x8010028C: nop

    func_80100C98_ovl_ending(rdram, ctx);
        goto after_0;
    // 0x8010028C: nop

    after_0:
    // 0x80100290: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80100294: beq         $v0, $at, L_80100544
    if (ctx->r2 == ctx->r1) {
        // 0x80100298: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80100544;
    }
    // 0x80100298: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8010029C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x801002A0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x801002A4: lw          $t7, 0x35A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X35A0);
    // 0x801002A8: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801002AC: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x801002B0: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x801002B4: addu        $s1, $s1, $t9
    ctx->r17 = ADD32(ctx->r17, ctx->r25);
    // 0x801002B8: lw          $s1, 0x61B0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X61B0);
    // 0x801002BC: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x801002C0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x801002C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801002C8: mflo        $t2
    ctx->r10 = lo;
    // 0x801002CC: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x801002D0: sh          $zero, 0x20($t3)
    MEM_H(0X20, ctx->r11) = 0;
    // 0x801002D4: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x801002D8: sra         $t3, $a0, 16
    ctx->r11 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801002DC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x801002E0: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801002E4: mflo        $t5
    ctx->r13 = lo;
    // 0x801002E8: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x801002EC: sh          $v0, 0x22($t6)
    MEM_H(0X22, ctx->r14) = ctx->r2;
    // 0x801002F0: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x801002F4: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801002F8: mflo        $t9
    ctx->r25 = lo;
    // 0x801002FC: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
    // 0x80100300: lh          $t4, 0x20($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X20);
    // 0x80100304: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x80100308: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8010030C: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100310: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x80100314: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x80100318: lw          $s2, 0x3784($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3784);
    // 0x8010031C: lh          $t8, 0x10($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X10);
    // 0x80100320: lh          $a2, 0x8($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X8);
    // 0x80100324: lh          $a3, 0xA($s0)
    ctx->r7 = MEM_H(ctx->r16, 0XA);
    // 0x80100328: mflo        $t5
    ctx->r13 = lo;
    // 0x8010032C: addu        $t0, $s2, $t5
    ctx->r8 = ADD32(ctx->r18, ctx->r13);
    // 0x80100330: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80100334: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80100338: lh          $t2, 0x12($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X12);
    // 0x8010033C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80100340: or          $a1, $t7, $t9
    ctx->r5 = ctx->r15 | ctx->r25;
    // 0x80100344: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80100348: lh          $t3, 0xC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XC);
    // 0x8010034C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80100350: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80100354: lh          $t4, 0xE($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XE);
    // 0x80100358: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8010035C: lh          $t5, 0x14($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X14);
    // 0x80100360: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80100364: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x80100368: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8010036C: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x80100370: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80100374: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80100378: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8010037C: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x80100380: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80100384: jal         0x801008A8
    // 0x80100388: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    func_801008A8_ovl_ending(rdram, ctx);
        goto after_1;
    // 0x80100388: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    after_1:
    // 0x8010038C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80100390: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80100394: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100398: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8010039C: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x801003A0: mflo        $t5
    ctx->r13 = lo;
    // 0x801003A4: addu        $s0, $s1, $t5
    ctx->r16 = ADD32(ctx->r17, ctx->r13);
    // 0x801003A8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x801003AC: bnel        $t6, $zero, L_801003D8
    if (ctx->r14 != 0) {
        // 0x801003B0: sw          $v0, 0x0($fp)
        MEM_W(0X0, ctx->r30) = ctx->r2;
            goto L_801003D8;
    }
    goto skip_2;
    // 0x801003B0: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    skip_2:
    // 0x801003B4: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x801003B8: sh          $t7, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r15;
    // 0x801003BC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x801003C0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801003C4: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x801003C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801003CC: b           L_801003D8
    // 0x801003D0: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
        goto L_801003D8;
    // 0x801003D0: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
    // 0x801003D4: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
L_801003D8:
    // 0x801003D8: lh          $t8, 0x20($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X20);
    // 0x801003DC: multu       $t8, $s7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801003E0: mflo        $t2
    ctx->r10 = lo;
    // 0x801003E4: addu        $t0, $s2, $t2
    ctx->r8 = ADD32(ctx->r18, ctx->r10);
    // 0x801003E8: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x801003EC: andi        $t3, $v1, 0xC800
    ctx->r11 = ctx->r3 & 0XC800;
    // 0x801003F0: beql        $t3, $zero, L_80100480
    if (ctx->r11 == 0) {
        // 0x801003F4: andi        $t2, $v1, 0x1000
        ctx->r10 = ctx->r3 & 0X1000;
            goto L_80100480;
    }
    goto skip_3;
    // 0x801003F4: andi        $t2, $v1, 0x1000
    ctx->r10 = ctx->r3 & 0X1000;
    skip_3:
    // 0x801003F8: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x801003FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80100400: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80100404: bne         $t4, $zero, L_80100438
    if (ctx->r12 != 0) {
        // 0x80100408: nop
    
            goto L_80100438;
    }
    // 0x80100408: nop

    // 0x8010040C: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x80100410: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x80100414: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x80100418: multu       $t5, $s6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010041C: mflo        $t6
    ctx->r14 = lo;
    // 0x80100420: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80100424: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80100428: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x8010042C: subu        $a3, $t7, $t9
    ctx->r7 = SUB32(ctx->r15, ctx->r25);
    // 0x80100430: b           L_80100438
    // 0x80100434: subu        $t1, $t8, $t2
    ctx->r9 = SUB32(ctx->r24, ctx->r10);
        goto L_80100438;
    // 0x80100434: subu        $t1, $t8, $t2
    ctx->r9 = SUB32(ctx->r24, ctx->r10);
L_80100438:
    // 0x80100438: lh          $t3, 0x4($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X4);
    // 0x8010043C: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x80100440: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80100444: addu        $a1, $t3, $a3
    ctx->r5 = ADD32(ctx->r11, ctx->r7);
    // 0x80100448: jal         0x80101500
    // 0x8010044C: addu        $a2, $t4, $t1
    ctx->r6 = ADD32(ctx->r12, ctx->r9);
    func_80101500_ovl_ending(rdram, ctx);
        goto after_2;
    // 0x8010044C: addu        $a2, $t4, $t1
    ctx->r6 = ADD32(ctx->r12, ctx->r9);
    after_2:
    // 0x80100450: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80100454: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80100458: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x8010045C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80100460: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x80100464: lh          $t7, 0x20($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X20);
    // 0x80100468: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8010046C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80100470: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80100474: addu        $t8, $s2, $t9
    ctx->r24 = ADD32(ctx->r18, ctx->r25);
    // 0x80100478: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8010047C: andi        $t2, $v1, 0x1000
    ctx->r10 = ctx->r3 & 0X1000;
L_80100480:
    // 0x80100480: beql        $t2, $zero, L_801004C0
    if (ctx->r10 == 0) {
        // 0x80100484: lui         $at, 0x6000
        ctx->r1 = S32(0X6000 << 16);
            goto L_801004C0;
    }
    goto skip_4;
    // 0x80100484: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
    skip_4:
    // 0x80100488: jal         0x80101880
    // 0x8010048C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101880_ovl_ending(rdram, ctx);
        goto after_3;
    // 0x8010048C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80100490: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80100494: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80100498: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x8010049C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801004A0: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x801004A4: lh          $t5, 0x20($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X20);
    // 0x801004A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801004AC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801004B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801004B4: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x801004B8: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x801004BC: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
L_801004C0:
    // 0x801004C0: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x801004C4: beql        $t9, $zero, L_801004DC
    if (ctx->r25 == 0) {
        // 0x801004C8: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_801004DC;
    }
    goto skip_5;
    // 0x801004C8: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    skip_5:
    // 0x801004CC: jal         0x80101040
    // 0x801004D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101040_ovl_ending(rdram, ctx);
        goto after_4;
    // 0x801004D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x801004D4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x801004D8: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
L_801004DC:
    // 0x801004DC: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x801004E0: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x801004E4: lw          $t2, 0x35A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X35A0);
    // 0x801004E8: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x801004EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x801004F0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x801004F4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801004F8: lw          $t4, 0x61B4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X61B4);
    // 0x801004FC: sltu        $at, $t8, $t4
    ctx->r1 = ctx->r24 < ctx->r12 ? 1 : 0;
    // 0x80100500: bne         $at, $zero, L_80100524
    if (ctx->r1 != 0) {
        // 0x80100504: nop
    
            goto L_80100524;
    }
    // 0x80100504: nop

    // 0x80100508: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x8010050C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80100510: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100514: sw          $t5, 0x35A4($at)
    MEM_W(0X35A4, ctx->r1) = ctx->r13;
    // 0x80100518: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8010051C: b           L_80100544
    // 0x80100520: sw          $zero, 0x6FE4($at)
    MEM_W(0X6FE4, ctx->r1) = 0;
        goto L_80100544;
    // 0x80100520: sw          $zero, 0x6FE4($at)
    MEM_W(0X6FE4, ctx->r1) = 0;
L_80100524:
    // 0x80100524: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100528: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8010052C: sw          $zero, 0x6FE4($at)
    MEM_W(0X6FE4, ctx->r1) = 0;
    // 0x80100530: mflo        $t6
    ctx->r14 = lo;
    // 0x80100534: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80100538: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x8010053C: beq         $t9, $zero, L_80100288
    if (ctx->r25 == 0) {
        // 0x80100540: nop
    
            goto L_80100288;
    }
    // 0x80100540: nop

L_80100544:
    // 0x80100544: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
L_80100548:
    // 0x80100548: jal         0x8010189C
    // 0x8010054C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8010189C_ovl_ending(rdram, ctx);
        goto after_5;
    // 0x8010054C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80100550: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80100554: lw          $t8, 0x6FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FD0);
    // 0x80100558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8010055C: sltiu       $at, $t8, 0xF78
    ctx->r1 = ctx->r24 < 0XF78 ? 1 : 0;
    // 0x80100560: bne         $at, $zero, L_80100570
    if (ctx->r1 != 0) {
        // 0x80100564: nop
    
            goto L_80100570;
    }
    // 0x80100564: nop

    // 0x80100568: jal         0x801028DC
    // 0x8010056C: addiu       $a1, $zero, 0x4C2
    ctx->r5 = ADD32(0, 0X4C2);
    func_801028DC_ovl_ending(rdram, ctx);
        goto after_6;
    // 0x8010056C: addiu       $a1, $zero, 0x4C2
    ctx->r5 = ADD32(0, 0X4C2);
    after_6:
L_80100570:
    // 0x80100570: jal         0x8010189C
    // 0x80100574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8010189C_ovl_ending(rdram, ctx);
        goto after_7;
    // 0x80100574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80100578: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x8010057C: lui         $fp, 0xFF7F
    ctx->r30 = S32(0XFF7F << 16);
    // 0x80100580: ori         $fp, $fp, 0xFFFF
    ctx->r30 = ctx->r30 | 0XFFFF;
    // 0x80100584: addiu       $s4, $s4, 0x6FE8
    ctx->r20 = ADD32(ctx->r20, 0X6FE8);
    // 0x80100588: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8010058C:
    // 0x8010058C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80100590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80100594: sll         $t3, $t2, 0
    ctx->r11 = S32(ctx->r10 << 0);
    // 0x80100598: bgezl       $t3, L_80100798
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8010059C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80100798;
    }
    goto skip_6;
    // 0x8010059C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_6:
    // 0x801005A0: jal         0x8010082C
    // 0x801005A4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    func_8010082C_ovl_ending(rdram, ctx);
        goto after_8;
    // 0x801005A4: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_8:
    // 0x801005A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801005AC: beq         $v0, $at, L_80100794
    if (ctx->r2 == ctx->r1) {
        // 0x801005B0: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_80100794;
    }
    // 0x801005B0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x801005B4: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801005B8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x801005BC: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x801005C0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801005C4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x801005C8: addu        $s1, $s1, $t5
    ctx->r17 = ADD32(ctx->r17, ctx->r13);
    // 0x801005CC: lw          $s1, 0x61B0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X61B0);
    // 0x801005D0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801005D4: addiu       $t8, $t8, 0x3784
    ctx->r24 = ADD32(ctx->r24, 0X3784);
    // 0x801005D8: sll         $t2, $a0, 8
    ctx->r10 = S32(ctx->r4 << 8);
    // 0x801005DC: mflo        $t6
    ctx->r14 = lo;
    // 0x801005E0: addu        $v1, $s1, $t6
    ctx->r3 = ADD32(ctx->r17, ctx->r14);
    // 0x801005E4: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x801005E8: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x801005EC: addu        $a2, $t9, $t8
    ctx->r6 = ADD32(ctx->r25, ctx->r24);
    // 0x801005F0: bgez        $t2, L_801005FC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801005F4: lw          $s2, 0x0($a2)
        ctx->r18 = MEM_W(ctx->r6, 0X0);
            goto L_801005FC;
    }
    // 0x801005F4: lw          $s2, 0x0($a2)
    ctx->r18 = MEM_W(ctx->r6, 0X0);
    // 0x801005F8: and         $a0, $a0, $fp
    ctx->r4 = ctx->r4 & ctx->r30;
L_801005FC:
    // 0x801005FC: lh          $a1, 0x20($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X20);
    // 0x80100600: multu       $a1, $s7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100604: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x80100608: mflo        $t3
    ctx->r11 = lo;
    // 0x8010060C: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80100610: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80100614: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    // 0x80100618: bnel        $t6, $zero, L_80100798
    if (ctx->r14 != 0) {
        // 0x8010061C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80100798;
    }
    goto skip_7;
    // 0x8010061C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_7:
    // 0x80100620: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    // 0x80100624: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80100628: lh          $t9, 0x20($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X20);
    // 0x8010062C: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x80100630: bnel        $at, $zero, L_8010065C
    if (ctx->r1 != 0) {
        // 0x80100634: lw          $t5, 0x0($s4)
        ctx->r13 = MEM_W(ctx->r20, 0X0);
            goto L_8010065C;
    }
    goto skip_8;
    // 0x80100634: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    skip_8:
    // 0x80100638: jal         0x80100A94
    // 0x8010063C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80100A94_ovl_ending(rdram, ctx);
        goto after_9;
    // 0x8010063C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x80100640: multu       $s5, $s6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100644: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80100648: mflo        $t3
    ctx->r11 = lo;
    // 0x8010064C: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x80100650: b           L_80100794
    // 0x80100654: sh          $t2, 0x22($t4)
    MEM_H(0X22, ctx->r12) = ctx->r10;
        goto L_80100794;
    // 0x80100654: sh          $t2, 0x22($t4)
    MEM_H(0X22, ctx->r12) = ctx->r10;
    // 0x80100658: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
L_8010065C:
    // 0x8010065C: and         $t6, $t5, $fp
    ctx->r14 = ctx->r13 & ctx->r30;
    // 0x80100660: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x80100664: lh          $t9, 0x20($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X20);
    // 0x80100668: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8010066C: mflo        $t8
    ctx->r24 = lo;
    // 0x80100670: addu        $t3, $s2, $t8
    ctx->r11 = ADD32(ctx->r18, ctx->r24);
    // 0x80100674: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x80100678: or          $t4, $t6, $t2
    ctx->r12 = ctx->r14 | ctx->r10;
    // 0x8010067C: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x80100680: lh          $t5, 0x20($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X20);
    // 0x80100684: multu       $t5, $s7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100688: mflo        $t6
    ctx->r14 = lo;
    // 0x8010068C: addu        $t9, $s2, $t6
    ctx->r25 = ADD32(ctx->r18, ctx->r14);
    // 0x80100690: lw          $t8, 0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X8);
    // 0x80100694: sw          $t8, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->r24;
    // 0x80100698: lh          $t3, 0x20($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X20);
    // 0x8010069C: multu       $t3, $s7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801006A0: mflo        $t7
    ctx->r15 = lo;
    // 0x801006A4: addu        $t2, $s2, $t7
    ctx->r10 = ADD32(ctx->r18, ctx->r15);
    // 0x801006A8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801006AC: andi        $t5, $t4, 0xC800
    ctx->r13 = ctx->r12 & 0XC800;
    // 0x801006B0: beq         $t5, $zero, L_80100730
    if (ctx->r13 == 0) {
        // 0x801006B4: nop
    
            goto L_80100730;
    }
    // 0x801006B4: nop

    // 0x801006B8: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x801006BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801006C0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x801006C4: bne         $t6, $zero, L_801006FC
    if (ctx->r14 != 0) {
        // 0x801006C8: nop
    
            goto L_801006FC;
    }
    // 0x801006C8: nop

    // 0x801006CC: lhu         $t9, 0x24($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X24);
    // 0x801006D0: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x801006D4: lh          $t2, 0xA($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XA);
    // 0x801006D8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801006DC: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x801006E0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801006E4: addu        $a0, $s1, $t8
    ctx->r4 = ADD32(ctx->r17, ctx->r24);
    // 0x801006E8: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x801006EC: lh          $t4, 0xA($a0)
    ctx->r12 = MEM_H(ctx->r4, 0XA);
    // 0x801006F0: subu        $a3, $t3, $t7
    ctx->r7 = SUB32(ctx->r11, ctx->r15);
    // 0x801006F4: b           L_801006FC
    // 0x801006F8: subu        $t1, $t2, $t4
    ctx->r9 = SUB32(ctx->r10, ctx->r12);
        goto L_801006FC;
    // 0x801006F8: subu        $t1, $t2, $t4
    ctx->r9 = SUB32(ctx->r10, ctx->r12);
L_801006FC:
    // 0x801006FC: multu       $s5, $s6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100700: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80100704: mflo        $t5
    ctx->r13 = lo;
    // 0x80100708: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x8010070C: lh          $t9, 0x20($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X20);
    // 0x80100710: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100714: mflo        $t8
    ctx->r24 = lo;
    // 0x80100718: addu        $v0, $s2, $t8
    ctx->r2 = ADD32(ctx->r18, ctx->r24);
    // 0x8010071C: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80100720: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x80100724: addu        $a1, $t3, $a3
    ctx->r5 = ADD32(ctx->r11, ctx->r7);
    // 0x80100728: jal         0x80101500
    // 0x8010072C: addu        $a2, $t7, $t1
    ctx->r6 = ADD32(ctx->r15, ctx->r9);
    func_80101500_ovl_ending(rdram, ctx);
        goto after_10;
    // 0x8010072C: addu        $a2, $t7, $t1
    ctx->r6 = ADD32(ctx->r15, ctx->r9);
    after_10:
L_80100730:
    // 0x80100730: multu       $s5, $s6
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100734: mflo        $t2
    ctx->r10 = lo;
    // 0x80100738: addu        $s0, $s1, $t2
    ctx->r16 = ADD32(ctx->r17, ctx->r10);
    // 0x8010073C: lh          $t4, 0x20($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X20);
    // 0x80100740: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100744: mflo        $t5
    ctx->r13 = lo;
    // 0x80100748: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x8010074C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80100750: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x80100754: beql        $t9, $zero, L_80100780
    if (ctx->r25 == 0) {
        // 0x80100758: lui         $at, 0x6000
        ctx->r1 = S32(0X6000 << 16);
            goto L_80100780;
    }
    goto skip_9;
    // 0x80100758: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
    skip_9:
    // 0x8010075C: jal         0x80101880
    // 0x80100760: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101880_ovl_ending(rdram, ctx);
        goto after_11;
    // 0x80100760: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80100764: lh          $t8, 0x20($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X20);
    // 0x80100768: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8010076C: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80100770: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80100774: addu        $t7, $s2, $t3
    ctx->r15 = ADD32(ctx->r18, ctx->r11);
    // 0x80100778: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8010077C: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
L_80100780:
    // 0x80100780: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x80100784: beql        $t2, $zero, L_80100798
    if (ctx->r10 == 0) {
        // 0x80100788: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80100798;
    }
    goto skip_10;
    // 0x80100788: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_10:
    // 0x8010078C: jal         0x80101040
    // 0x80100790: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80101040_ovl_ending(rdram, ctx);
        goto after_12;
    // 0x80100790: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
L_80100794:
    // 0x80100794: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80100798:
    // 0x80100798: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x8010079C: bne         $s3, $at, L_8010058C
    if (ctx->r19 != ctx->r1) {
        // 0x801007A0: addiu       $s4, $s4, 0x50
        ctx->r20 = ADD32(ctx->r20, 0X50);
            goto L_8010058C;
    }
    // 0x801007A0: addiu       $s4, $s4, 0x50
    ctx->r20 = ADD32(ctx->r20, 0X50);
    // 0x801007A4: jal         0x80100BE8
    // 0x801007A8: nop

    func_80100BE8_ovl_ending(rdram, ctx);
        goto after_13;
    // 0x801007A8: nop

    after_13:
    // 0x801007AC: bne         $v0, $zero, L_801007F8
    if (ctx->r2 != 0) {
        // 0x801007B0: lui         $t4, 0x8010
        ctx->r12 = S32(0X8010 << 16);
            goto L_801007F8;
    }
    // 0x801007B0: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x801007B4: lw          $t4, 0x35A4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X35A4);
    // 0x801007B8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801007BC: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x801007C0: beq         $t4, $zero, L_801007F8
    if (ctx->r12 == 0) {
        // 0x801007C4: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_801007F8;
    }
    // 0x801007C4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x801007C8: lw          $t5, 0x35A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X35A0);
    // 0x801007CC: lw          $t9, 0x61B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X61B8);
    // 0x801007D0: sw          $zero, 0x35A4($at)
    MEM_W(0X35A4, ctx->r1) = 0;
    // 0x801007D4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801007D8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801007DC: sw          $t6, 0x35A0($at)
    MEM_W(0X35A0, ctx->r1) = ctx->r14;
    // 0x801007E0: sltu        $at, $t6, $t9
    ctx->r1 = ctx->r14 < ctx->r25 ? 1 : 0;
    // 0x801007E4: bne         $at, $zero, L_801007F8
    if (ctx->r1 != 0) {
        // 0x801007E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801007F8;
    }
    // 0x801007E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801007EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801007F0: b           L_801007FC
    // 0x801007F4: sw          $zero, 0x35A0($at)
    MEM_W(0X35A0, ctx->r1) = 0;
        goto L_801007FC;
    // 0x801007F4: sw          $zero, 0x35A0($at)
    MEM_W(0X35A0, ctx->r1) = 0;
L_801007F8:
    // 0x801007F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801007FC:
    // 0x801007FC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80100800: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80100804: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80100808: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8010080C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80100810: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80100814: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80100818: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8010081C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80100820: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80100824: jr          $ra
    // 0x80100828: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80100828: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8000C4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C4C4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000C4C8: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8000C4CC: lui         $s7, 0x8008
    ctx->r23 = S32(0X8008 << 16);
    // 0x8000C4D0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000C4D4: addiu       $v1, $v1, -0x4548
    ctx->r3 = ADD32(ctx->r3, -0X4548);
    // 0x8000C4D8: addiu       $s7, $s7, 0x28D8
    ctx->r23 = ADD32(ctx->r23, 0X28D8);
    // 0x8000C4DC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8000C4E0: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8000C4E4: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8000C4E8: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8000C4EC: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8000C4F0: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8000C4F4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8000C4F8: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8000C4FC: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8000C500: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x8000C504: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8000C508: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8000C50C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8000C510: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8000C514: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000C518: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8000C51C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C520: sw          $zero, 0x28DC($at)
    MEM_W(0X28DC, ctx->r1) = 0;
    // 0x8000C524: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
    // 0x8000C528: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C52C: sw          $zero, 0x28E0($at)
    MEM_W(0X28E0, ctx->r1) = 0;
    // 0x8000C530: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C534: sw          $zero, 0x28E4($at)
    MEM_W(0X28E4, ctx->r1) = 0;
    // 0x8000C538: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C53C: sw          $zero, 0x28E8($at)
    MEM_W(0X28E8, ctx->r1) = 0;
    // 0x8000C540: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C544: sw          $zero, 0x28EC($at)
    MEM_W(0X28EC, ctx->r1) = 0;
    // 0x8000C548: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C54C: sw          $zero, 0x4F38($at)
    MEM_W(0X4F38, ctx->r1) = 0;
    // 0x8000C550: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000C554: addiu       $t6, $t6, 0x2C80
    ctx->r14 = ADD32(ctx->r14, 0X2C80);
    // 0x8000C558: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C55C: sw          $t6, 0x28F0($at)
    MEM_W(0X28F0, ctx->r1) = ctx->r14;
    // 0x8000C560: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8000C564: addiu       $t7, $t7, 0x3080
    ctx->r15 = ADD32(ctx->r15, 0X3080);
    // 0x8000C568: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C56C: sw          $t7, 0x28F4($at)
    MEM_W(0X28F4, ctx->r1) = ctx->r15;
    // 0x8000C570: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000C574: addiu       $t8, $t8, 0x4F40
    ctx->r24 = ADD32(ctx->r24, 0X4F40);
    // 0x8000C578: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C57C: sw          $t8, 0x28F8($at)
    MEM_W(0X28F8, ctx->r1) = ctx->r24;
    // 0x8000C580: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000C584: addiu       $t9, $t9, 0x3488
    ctx->r25 = ADD32(ctx->r25, 0X3488);
    // 0x8000C588: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C58C: sw          $t9, 0x28FC($at)
    MEM_W(0X28FC, ctx->r1) = ctx->r25;
    // 0x8000C590: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000C594: addiu       $t1, $t1, 0x3888
    ctx->r9 = ADD32(ctx->r9, 0X3888);
    // 0x8000C598: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C59C: sw          $t1, 0x2900($at)
    MEM_W(0X2900, ctx->r1) = ctx->r9;
    // 0x8000C5A0: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8000C5A4: addiu       $t2, $t2, 0x3C90
    ctx->r10 = ADD32(ctx->r10, 0X3C90);
    // 0x8000C5A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C5AC: sw          $t2, 0x2904($at)
    MEM_W(0X2904, ctx->r1) = ctx->r10;
    // 0x8000C5B0: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8000C5B4: addiu       $t3, $t3, 0x2910
    ctx->r11 = ADD32(ctx->r11, 0X2910);
    // 0x8000C5B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C5BC: sw          $t3, 0x2C10($at)
    MEM_W(0X2C10, ctx->r1) = ctx->r11;
    // 0x8000C5C0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8000C5C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000C5C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C5CC: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000C5D0: lw          $s2, 0x4F20($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4F20);
    // 0x8000C5D4: swc1        $f4, 0x4ED4($at)
    MEM_W(0X4ED4, ctx->r1) = ctx->f4.u32l;
    // 0x8000C5D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C5DC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8000C5E0: sw          $t4, 0x4ED8($at)
    MEM_W(0X4ED8, ctx->r1) = ctx->r12;
    // 0x8000C5E4: lhu         $v0, 0x28($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X28);
    // 0x8000C5E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000C5EC: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000C5F0: beq         $v0, $at, L_8000C630
    if (ctx->r2 == ctx->r1) {
        // 0x8000C5F4: lwc1        $f2, 0x1C($v1)
        ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_8000C630;
    }
    // 0x8000C5F4: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000C5F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000C5FC: beql        $v0, $at, L_8000C678
    if (ctx->r2 == ctx->r1) {
        // 0x8000C600: lwc1        $f18, 0x8($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
            goto L_8000C678;
    }
    goto skip_0;
    // 0x8000C600: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    skip_0:
    // 0x8000C604: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000C608: beql        $v0, $at, L_8000C6BC
    if (ctx->r2 == ctx->r1) {
        // 0x8000C60C: lwc1        $f10, 0x8($s2)
        ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
            goto L_8000C6BC;
    }
    goto skip_1;
    // 0x8000C60C: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    skip_1:
    // 0x8000C610: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000C614: beq         $v0, $at, L_8000C6FC
    if (ctx->r2 == ctx->r1) {
        // 0x8000C618: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000C6FC;
    }
    // 0x8000C618: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000C61C: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x8000C620: addiu       $s1, $s1, 0x58E8
    ctx->r17 = ADD32(ctx->r17, 0X58E8);
    // 0x8000C624: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000C628: b           L_8000C73C
    // 0x8000C62C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_8000C73C;
    // 0x8000C62C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_8000C630:
    // 0x8000C630: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8000C634: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000C638: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000C63C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8000C640: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x8000C644: addiu       $s1, $s1, 0x58EC
    ctx->r17 = ADD32(ctx->r17, 0X58EC);
    // 0x8000C648: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8000C64C: addiu       $s6, $zero, 0x9D
    ctx->r22 = ADD32(0, 0X9D);
    // 0x8000C650: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000C654: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8000C658: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000C65C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000C660: mfc1        $s3, $f18
    ctx->r19 = (int32_t)ctx->f18.u32l;
    // 0x8000C664: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000C668: mfc1        $s4, $f16
    ctx->r20 = (int32_t)ctx->f16.u32l;
    // 0x8000C66C: b           L_8000C73C
    // 0x8000C670: nop

        goto L_8000C73C;
    // 0x8000C670: nop

    // 0x8000C674: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
L_8000C678:
    // 0x8000C678: lwc1        $f6, 0x10($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000C67C: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000C680: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8000C684: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x8000C688: addiu       $s1, $s1, 0x5A28
    ctx->r17 = ADD32(ctx->r17, 0X5A28);
    // 0x8000C68C: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8000C690: addiu       $s6, $zero, 0x59
    ctx->r22 = ADD32(0, 0X59);
    // 0x8000C694: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000C698: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8000C69C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000C6A0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000C6A4: mfc1        $s3, $f10
    ctx->r19 = (int32_t)ctx->f10.u32l;
    // 0x8000C6A8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8000C6AC: mfc1        $s4, $f8
    ctx->r20 = (int32_t)ctx->f8.u32l;
    // 0x8000C6B0: b           L_8000C73C
    // 0x8000C6B4: nop

        goto L_8000C73C;
    // 0x8000C6B4: nop

    // 0x8000C6B8: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
L_8000C6BC:
    // 0x8000C6BC: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000C6C0: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000C6C4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8000C6C8: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x8000C6CC: addiu       $s1, $s1, 0x5ADC
    ctx->r17 = ADD32(ctx->r17, 0X5ADC);
    // 0x8000C6D0: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8000C6D4: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x8000C6D8: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8000C6DC: lwc1        $f16, 0x14($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8000C6E0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000C6E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000C6E8: mfc1        $s3, $f6
    ctx->r19 = (int32_t)ctx->f6.u32l;
    // 0x8000C6EC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8000C6F0: mfc1        $s4, $f4
    ctx->r20 = (int32_t)ctx->f4.u32l;
    // 0x8000C6F4: b           L_8000C73C
    // 0x8000C6F8: nop

        goto L_8000C73C;
    // 0x8000C6F8: nop

L_8000C6FC:
    // 0x8000C6FC: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8000C700: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000C704: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000C708: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8000C70C: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x8000C710: addiu       $s1, $s1, 0x5AF0
    ctx->r17 = ADD32(ctx->r17, 0X5AF0);
    // 0x8000C714: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8000C718: addiu       $s6, $zero, 0x15
    ctx->r22 = ADD32(0, 0X15);
    // 0x8000C71C: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000C720: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8000C724: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000C728: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000C72C: mfc1        $s3, $f18
    ctx->r19 = (int32_t)ctx->f18.u32l;
    // 0x8000C730: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000C734: mfc1        $s4, $f16
    ctx->r20 = (int32_t)ctx->f16.u32l;
    // 0x8000C738: nop

L_8000C73C:
    // 0x8000C73C: beql        $s6, $zero, L_8000C7D4
    if (ctx->r22 == 0) {
        // 0x8000C740: lhu         $v0, 0x2($s2)
        ctx->r2 = MEM_HU(ctx->r18, 0X2);
            goto L_8000C7D4;
    }
    goto skip_2;
    // 0x8000C740: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    skip_2:
    // 0x8000C744: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
L_8000C748:
    // 0x8000C748: lb          $t5, 0x1($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1);
    // 0x8000C74C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000C750: addu        $v0, $t4, $s3
    ctx->r2 = ADD32(ctx->r12, ctx->r19);
    // 0x8000C754: bltz        $v0, L_8000C7C4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000C758: addu        $v1, $t5, $s4
        ctx->r3 = ADD32(ctx->r13, ctx->r20);
            goto L_8000C7C4;
    }
    // 0x8000C758: addu        $v1, $t5, $s4
    ctx->r3 = ADD32(ctx->r13, ctx->r20);
    // 0x8000C75C: bltzl       $v1, L_8000C7C8
    if (SIGNED(ctx->r3) < 0) {
        // 0x8000C760: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_8000C7C8;
    }
    goto skip_3;
    // 0x8000C760: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    skip_3:
    // 0x8000C764: lh          $a3, 0x4($s2)
    ctx->r7 = MEM_H(ctx->r18, 0X4);
    // 0x8000C768: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000C76C: beql        $at, $zero, L_8000C7C8
    if (ctx->r1 == 0) {
        // 0x8000C770: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_8000C7C8;
    }
    goto skip_4;
    // 0x8000C770: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    skip_4:
    // 0x8000C774: lh          $t6, 0x6($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X6);
    // 0x8000C778: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000C77C: beql        $at, $zero, L_8000C7C8
    if (ctx->r1 == 0) {
        // 0x8000C780: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_8000C7C8;
    }
    goto skip_5;
    // 0x8000C780: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    skip_5:
    // 0x8000C784: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C788: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x8000C78C: lw          $t4, 0x20($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X20);
    // 0x8000C790: mflo        $t7
    ctx->r15 = lo;
    // 0x8000C794: addu        $a2, $t7, $v0
    ctx->r6 = ADD32(ctx->r15, ctx->r2);
    // 0x8000C798: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x8000C79C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8000C7A0: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8000C7A4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8000C7A8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8000C7AC: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
    // 0x8000C7B0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8000C7B4: jal         0x8000D518
    // 0x8000C7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000D518(rdram, ctx);
        goto after_0;
    // 0x8000C7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000C7BC: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000C7C0: lw          $s2, 0x4F20($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X4F20);
L_8000C7C4:
    // 0x8000C7C4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
L_8000C7C8:
    // 0x8000C7C8: bnel        $s6, $zero, L_8000C748
    if (ctx->r22 != 0) {
        // 0x8000C7CC: lb          $t4, 0x0($s1)
        ctx->r12 = MEM_B(ctx->r17, 0X0);
            goto L_8000C748;
    }
    goto skip_6;
    // 0x8000C7CC: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    skip_6:
    // 0x8000C7D0: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
L_8000C7D4:
    // 0x8000C7D4: beq         $v0, $zero, L_8000C7EC
    if (ctx->r2 == 0) {
        // 0x8000C7D8: nop
    
            goto L_8000C7EC;
    }
    // 0x8000C7D8: nop

    // 0x8000C7DC: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8000C7E0: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x8000C7E4: jal         0x8000D518
    // 0x8000C7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000D518(rdram, ctx);
        goto after_1;
    // 0x8000C7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8000C7EC:
    // 0x8000C7EC: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x8000C7F0: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x8000C7F4: addiu       $fp, $fp, 0x4F34
    ctx->r30 = ADD32(ctx->r30, 0X4F34);
    // 0x8000C7F8: addiu       $s5, $s5, -0x4D04
    ctx->r21 = ADD32(ctx->r21, -0X4D04);
    // 0x8000C7FC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x8000C800: lui         $t7, 0x100
    ctx->r15 = S32(0X100 << 16);
    // 0x8000C804: addiu       $t7, $t7, 0xE8
    ctx->r15 = ADD32(ctx->r15, 0XE8);
    // 0x8000C808: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8000C80C: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x8000C810: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8000C814: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000C818: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000C81C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000C820: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x8000C824: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x8000C828: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000C82C: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x8000C830: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000C834: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000C838: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000C83C: lh          $t1, -0x4CE6($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4CE6);
    // 0x8000C840: lh          $a1, -0x4CE8($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4CE8);
    // 0x8000C844: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x8000C848: ori         $t2, $t2, 0xF400
    ctx->r10 = ctx->r10 | 0XF400;
    // 0x8000C84C: subu        $a2, $t1, $a1
    ctx->r6 = SUB32(ctx->r9, ctx->r5);
    // 0x8000C850: div         $zero, $t2, $a2
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r6)));
    // 0x8000C854: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x8000C858: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8000C85C: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8000C860: mflo        $t3
    ctx->r11 = lo;
    // 0x8000C864: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8000C868: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8000C86C: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8000C870: mflo        $t9
    ctx->r25 = lo;
    // 0x8000C874: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x8000C878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000C87C: bne         $a2, $zero, L_8000C888
    if (ctx->r6 != 0) {
        // 0x8000C880: nop
    
            goto L_8000C888;
    }
    // 0x8000C880: nop

    // 0x8000C884: break       7
    do_break(2147534980);
L_8000C888:
    // 0x8000C888: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C88C: bne         $a2, $at, L_8000C8A0
    if (ctx->r6 != ctx->r1) {
        // 0x8000C890: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000C8A0;
    }
    // 0x8000C890: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C894: bne         $t2, $at, L_8000C8A0
    if (ctx->r10 != ctx->r1) {
        // 0x8000C898: nop
    
            goto L_8000C8A0;
    }
    // 0x8000C898: nop

    // 0x8000C89C: break       6
    do_break(2147535004);
L_8000C8A0:
    // 0x8000C8A0: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x8000C8A4: or          $t2, $t5, $t1
    ctx->r10 = ctx->r13 | ctx->r9;
    // 0x8000C8A8: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x8000C8AC: bne         $a2, $zero, L_8000C8B8
    if (ctx->r6 != 0) {
        // 0x8000C8B0: nop
    
            goto L_8000C8B8;
    }
    // 0x8000C8B0: nop

    // 0x8000C8B4: break       7
    do_break(2147535028);
L_8000C8B8:
    // 0x8000C8B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C8BC: bne         $a2, $at, L_8000C8D0
    if (ctx->r6 != ctx->r1) {
        // 0x8000C8C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000C8D0;
    }
    // 0x8000C8C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000C8C4: bne         $t8, $at, L_8000C8D0
    if (ctx->r24 != ctx->r1) {
        // 0x8000C8C8: nop
    
            goto L_8000C8D0;
    }
    // 0x8000C8C8: nop

    // 0x8000C8CC: break       6
    do_break(2147535052);
L_8000C8D0:
    // 0x8000C8D0: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8000C8D4: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x8000C8D8: addiu       $t3, $t3, 0x2C80
    ctx->r11 = ADD32(ctx->r11, 0X2C80);
    // 0x8000C8DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C8E0: sw          $t3, 0x28F0($at)
    MEM_W(0X28F0, ctx->r1) = ctx->r11;
    // 0x8000C8E4: lw          $s6, 0x0($s7)
    ctx->r22 = MEM_W(ctx->r23, 0X0);
    // 0x8000C8E8: lui         $s7, 0x8008
    ctx->r23 = S32(0X8008 << 16);
    // 0x8000C8EC: addiu       $s7, $s7, 0x2C48
    ctx->r23 = ADD32(ctx->r23, 0X2C48);
    // 0x8000C8F0: beq         $s6, $zero, L_8000CAF4
    if (ctx->r22 == 0) {
        // 0x8000C8F4: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8000CAF4;
    }
    // 0x8000C8F4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000C8F8: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x8000C8FC: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000C900: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8000C904: addiu       $s2, $s2, -0x4D08
    ctx->r18 = ADD32(ctx->r18, -0X4D08);
    // 0x8000C908: addiu       $s4, $s4, 0x2C18
    ctx->r20 = ADD32(ctx->r20, 0X2C18);
    // 0x8000C90C: ldc1        $f30, 0x11F0($at)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r1, 0X11F0);
L_8000C910:
    // 0x8000C910: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000C914: addiu       $a0, $a0, 0x28F0
    ctx->r4 = ADD32(ctx->r4, 0X28F0);
    // 0x8000C918: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000C91C: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x8000C920: addiu       $t5, $t5, 0x66FC
    ctx->r13 = ADD32(ctx->r13, 0X66FC);
    // 0x8000C924: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x8000C928: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x8000C92C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8000C930: lhu         $v1, 0x16($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X16);
    // 0x8000C934: lwc1        $f20, 0x0($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000C938: lwc1        $f24, 0x4($s1)
    ctx->f24.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8000C93C: andi        $t6, $v1, 0x2000
    ctx->r14 = ctx->r3 & 0X2000;
    // 0x8000C940: lwc1        $f22, 0x8($s1)
    ctx->f22.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000C944: beq         $t6, $zero, L_8000C9CC
    if (ctx->r14 == 0) {
        // 0x8000C948: lwc1        $f26, 0xC($s1)
        ctx->f26.u32l = MEM_W(ctx->r17, 0XC);
            goto L_8000C9CC;
    }
    // 0x8000C948: lwc1        $f26, 0xC($s1)
    ctx->f26.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000C94C: andi        $a3, $v1, 0xF00
    ctx->r7 = ctx->r3 & 0XF00;
    // 0x8000C950: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8000C954: sra         $t7, $a3, 8
    ctx->r15 = S32(SIGNED(ctx->r7) >> 8);
    // 0x8000C958: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    // 0x8000C95C: addiu       $s0, $a2, 0x1
    ctx->r16 = ADD32(ctx->r6, 0X1);
    // 0x8000C960: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x8000C964: addu        $s3, $t9, $t5
    ctx->r19 = ADD32(ctx->r25, ctx->r13);
    // 0x8000C968: andi        $t1, $s0, 0xFFFF
    ctx->r9 = ctx->r16 & 0XFFFF;
    // 0x8000C96C: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x8000C970: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000C974: jal         0x80022B40
    // 0x8000C978: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_80022B40(rdram, ctx);
        goto after_2;
    // 0x8000C978: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_2:
    // 0x8000C97C: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000C980: lwc1        $f18, 0x0($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8000C984: lwc1        $f6, 0x4($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X4);
    // 0x8000C988: lwc1        $f10, 0x8($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X8);
    // 0x8000C98C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8000C990: lhu         $t2, 0x6($s3)
    ctx->r10 = MEM_HU(ctx->r19, 0X6);
    // 0x8000C994: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000C998: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000C99C: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000C9A0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000C9A4: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x8000C9A8: add.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x8000C9AC: bne         $at, $zero, L_8000C9B8
    if (ctx->r1 != 0) {
        // 0x8000C9B0: add.s       $f22, $f22, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
            goto L_8000C9B8;
    }
    // 0x8000C9B0: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8000C9B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C9B8:
    // 0x8000C9B8: lhu         $t3, 0x16($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X16);
    // 0x8000C9BC: andi        $t4, $t3, 0xFF00
    ctx->r12 = ctx->r11 & 0XFF00;
    // 0x8000C9C0: or          $t6, $t4, $v0
    ctx->r14 = ctx->r12 | ctx->r2;
    // 0x8000C9C4: b           L_8000CA38
    // 0x8000C9C8: sh          $t6, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r14;
        goto L_8000CA38;
    // 0x8000C9C8: sh          $t6, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r14;
L_8000C9CC:
    // 0x8000C9CC: andi        $t7, $v1, 0x100
    ctx->r15 = ctx->r3 & 0X100;
    // 0x8000C9D0: beql        $t7, $zero, L_8000CA3C
    if (ctx->r15 == 0) {
        // 0x8000C9D4: lw          $t1, 0x0($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X0);
            goto L_8000CA3C;
    }
    goto skip_7;
    // 0x8000C9D4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    skip_7:
    // 0x8000C9D8: jal         0x8000DB38
    // 0x8000C9DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8000DB38(rdram, ctx);
        goto after_3;
    // 0x8000C9DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8000C9E0: beq         $v0, $zero, L_8000CA38
    if (ctx->r2 == 0) {
        // 0x8000C9E4: sll         $t8, $v0, 3
        ctx->r24 = S32(ctx->r2 << 3);
            goto L_8000CA38;
    }
    // 0x8000C9E4: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8000C9E8: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8000C9EC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000C9F0: addiu       $t9, $t9, 0x4E60
    ctx->r25 = ADD32(ctx->r25, 0X4E60);
    // 0x8000C9F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000C9F8: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8000C9FC: lwc1        $f18, -0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, -0X8);
    // 0x8000CA00: swc1        $f28, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f28.u32l;
    // 0x8000CA04: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000CA08: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    // 0x8000CA0C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000CA10: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8000CA14: mul.d       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f30.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f30.d);
    // 0x8000CA18: jal         0x800232F4
    // 0x8000CA1C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_4;
    // 0x8000CA1C: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    after_4:
    // 0x8000CA20: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8000CA24: lwc1        $f16, 0x4($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8000CA28: lwc1        $f18, -0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8000CA2C: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x8000CA30: sub.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x8000CA34: add.s       $f26, $f26, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f18.fl;
L_8000CA38:
    // 0x8000CA38: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_8000CA3C:
    // 0x8000CA3C: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x8000CA40: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000CA44: sll         $t2, $t1, 6
    ctx->r10 = S32(ctx->r9 << 6);
    // 0x8000CA48: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x8000CA4C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8000CA50: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8000CA54: addu        $a0, $t5, $t2
    ctx->r4 = ADD32(ctx->r13, ctx->r10);
    // 0x8000CA58: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8000CA5C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8000CA60: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x8000CA64: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8000CA68: jal         0x80035120
    // 0x8000CA6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    guPosition(rdram, ctx);
        goto after_5;
    // 0x8000CA6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8000CA70: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CA74: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x8000CA78: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x8000CA7C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8000CA80: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x8000CA84: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000CA88: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8000CA8C: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x8000CA90: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x8000CA94: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8000CA98: addiu       $t8, $t7, 0xC0
    ctx->r24 = ADD32(ctx->r15, 0XC0);
    // 0x8000CA9C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8000CAA0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8000CAA4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8000CAA8: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x8000CAAC: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x8000CAB0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CAB4: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8000CAB8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000CABC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8000CAC0: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x8000CAC4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000CAC8: lh          $t7, 0x14($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X14);
    // 0x8000CACC: lw          $t6, 0x4F28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F28);
    // 0x8000CAD0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8000CAD4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000CAD8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8000CADC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8000CAE0: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x8000CAE4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000CAE8: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x8000CAEC: bne         $s6, $zero, L_8000C910
    if (ctx->r22 != 0) {
        // 0x8000CAF0: sw          $t2, 0x0($fp)
        MEM_W(0X0, ctx->r30) = ctx->r10;
            goto L_8000C910;
    }
    // 0x8000CAF0: sw          $t2, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r10;
L_8000CAF4:
    // 0x8000CAF4: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x8000CAF8: lw          $s6, 0x28DC($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X28DC);
    // 0x8000CAFC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8000CB00: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000CB04: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x8000CB08: addiu       $t3, $t3, 0x3080
    ctx->r11 = ADD32(ctx->r11, 0X3080);
    // 0x8000CB0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CB10: addiu       $s2, $s2, -0x4D08
    ctx->r18 = ADD32(ctx->r18, -0X4D08);
    // 0x8000CB14: beq         $s6, $zero, L_8000CBFC
    if (ctx->r22 == 0) {
        // 0x8000CB18: sw          $t3, 0x28F0($at)
        MEM_W(0X28F0, ctx->r1) = ctx->r11;
            goto L_8000CBFC;
    }
    // 0x8000CB18: sw          $t3, 0x28F0($at)
    MEM_W(0X28F0, ctx->r1) = ctx->r11;
L_8000CB1C:
    // 0x8000CB1C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000CB20: lw          $v0, 0x28F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X28F0);
    // 0x8000CB24: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CB28: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x8000CB2C: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x8000CB30: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x8000CB34: sw          $t4, 0x28F0($at)
    MEM_W(0X28F0, ctx->r1) = ctx->r12;
    // 0x8000CB38: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000CB3C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8000CB40: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB44: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8000CB48: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000CB4C: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x8000CB50: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x8000CB54: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8000CB58: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8000CB5C: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8000CB60: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8000CB64: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8000CB68: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000CB6C: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8000CB70: jal         0x80035120
    // 0x8000CB74: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    guPosition(rdram, ctx);
        goto after_6;
    // 0x8000CB74: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x8000CB78: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CB7C: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8000CB80: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x8000CB84: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000CB88: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8000CB8C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8000CB90: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB94: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x8000CB98: addiu       $t4, $t4, 0x0
    ctx->r12 = ADD32(ctx->r12, 0X0);
    // 0x8000CB9C: sll         $t2, $t5, 6
    ctx->r10 = S32(ctx->r13 << 6);
    // 0x8000CBA0: addiu       $t3, $t2, 0xC0
    ctx->r11 = ADD32(ctx->r10, 0XC0);
    // 0x8000CBA4: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8000CBA8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000CBAC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8000CBB0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000CBB4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8000CBB8: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CBBC: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8000CBC0: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8000CBC4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000CBC8: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8000CBCC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8000CBD0: lh          $t2, 0x14($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X14);
    // 0x8000CBD4: lw          $t5, 0x4F28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4F28);
    // 0x8000CBD8: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x8000CBDC: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x8000CBE0: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8000CBE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000CBE8: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8000CBEC: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000CBF0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8000CBF4: bne         $s6, $zero, L_8000CB1C
    if (ctx->r22 != 0) {
        // 0x8000CBF8: sw          $t8, 0x0($fp)
        MEM_W(0X0, ctx->r30) = ctx->r24;
            goto L_8000CB1C;
    }
    // 0x8000CBF8: sw          $t8, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r24;
L_8000CBFC:
    // 0x8000CBFC: jal         0x8000E588
    // 0x8000CC00: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    func_8000E588(rdram, ctx);
        goto after_7;
    // 0x8000CC00: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_7:
    // 0x8000CC04: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000CC08: lw          $t9, 0x28E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X28E0);
    // 0x8000CC0C: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x8000CC10: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x8000CC14: beq         $t9, $zero, L_8000CCC4
    if (ctx->r25 == 0) {
        // 0x8000CC18: lui         $t6, 0x8008
        ctx->r14 = S32(0X8008 << 16);
            goto L_8000CCC4;
    }
    // 0x8000CC18: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000CC1C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CC20: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8000CC24: addiu       $a3, $t6, 0x4F40
    ctx->r7 = ADD32(ctx->r14, 0X4F40);
    // 0x8000CC28: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8000CC2C: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x8000CC30: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000CC34: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8000CC38: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CC3C: lui         $t4, 0xC811
    ctx->r12 = S32(0XC811 << 16);
    // 0x8000CC40: ori         $t4, $t4, 0x3078
    ctx->r12 = ctx->r12 | 0X3078;
    // 0x8000CC44: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8000CC48: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x8000CC4C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000CC50: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000CC54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CC58: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000CC5C: sw          $a3, 0x28F8($at)
    MEM_W(0X28F8, ctx->r1) = ctx->r7;
    // 0x8000CC60: lw          $a1, 0x28E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X28E0);
    // 0x8000CC64: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000CC68: jal         0x8000DDB0
    // 0x8000CC6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8000DDB0(rdram, ctx);
        goto after_8;
    // 0x8000CC6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8000CC70: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000CC74: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000CC78: lw          $a3, 0x28F8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X28F8);
    // 0x8000CC7C: lw          $a1, 0x28E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X28E0);
    // 0x8000CC80: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000CC84: jal         0x8000DDB0
    // 0x8000CC88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8000DDB0(rdram, ctx);
        goto after_9;
    // 0x8000CC88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8000CC8C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000CC90: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000CC94: lw          $a3, 0x28F8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X28F8);
    // 0x8000CC98: lw          $a1, 0x28E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X28E0);
    // 0x8000CC9C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000CCA0: jal         0x8000DDB0
    // 0x8000CCA4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8000DDB0(rdram, ctx);
        goto after_10;
    // 0x8000CCA4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x8000CCA8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000CCAC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8000CCB0: lw          $a3, 0x28F8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X28F8);
    // 0x8000CCB4: lw          $a1, 0x28E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X28E0);
    // 0x8000CCB8: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000CCBC: jal         0x8000DDB0
    // 0x8000CCC0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8000DDB0(rdram, ctx);
        goto after_11;
    // 0x8000CCC0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_11:
L_8000CCC4:
    // 0x8000CCC4: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CCC8: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8000CCCC: ori         $t8, $t8, 0xC02
    ctx->r24 = ctx->r24 | 0XC02;
    // 0x8000CCD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000CCD4: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x8000CCD8: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x8000CCDC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000CCE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000CCE4: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8000CCE8: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8000CCEC: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x8000CCF0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8000CCF4: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x8000CCF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000CCFC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8000CD00: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000CD04: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000CD08: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000CD0C: addiu       $v0, $v0, -0x3D1C
    ctx->r2 = ADD32(ctx->r2, -0X3D1C);
    // 0x8000CD10: addiu       $a0, $a0, -0x3D2C
    ctx->r4 = ADD32(ctx->r4, -0X3D2C);
    // 0x8000CD14: addiu       $v1, $v1, 0x2C70
    ctx->r3 = ADD32(ctx->r3, 0X2C70);
L_8000CD18:
    // 0x8000CD18: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x8000CD1C: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x8000CD20: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x8000CD24: lhu         $t7, 0x2($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X2);
    // 0x8000CD28: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CD2C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8000CD30: addu        $t4, $t5, $t3
    ctx->r12 = ADD32(ctx->r13, ctx->r11);
    // 0x8000CD34: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8000CD38: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000CD3C: sh          $t4, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r12;
    // 0x8000CD40: bne         $at, $zero, L_8000CD18
    if (ctx->r1 != 0) {
        // 0x8000CD44: sh          $t8, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r24;
            goto L_8000CD18;
    }
    // 0x8000CD44: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
    // 0x8000CD48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CD4C: jal         0x8000EB30
    // 0x8000CD50: sw          $zero, 0x2908($at)
    MEM_W(0X2908, ctx->r1) = 0;
    func_8000EB30(rdram, ctx);
        goto after_12;
    // 0x8000CD50: sw          $zero, 0x2908($at)
    MEM_W(0X2908, ctx->r1) = 0;
    after_12:
    // 0x8000CD54: jal         0x8000EDD8
    // 0x8000CD58: nop

    func_8000EDD8(rdram, ctx);
        goto after_13;
    // 0x8000CD58: nop

    after_13:
    // 0x8000CD5C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000CD60: lw          $s0, 0x4ED8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4ED8);
    // 0x8000CD64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CD68: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000CD6C: bne         $s0, $at, L_8000CD94
    if (ctx->r16 != ctx->r1) {
        // 0x8000CD70: addiu       $s1, $s1, 0x4EDC
        ctx->r17 = ADD32(ctx->r17, 0X4EDC);
            goto L_8000CD94;
    }
    // 0x8000CD70: addiu       $s1, $s1, 0x4EDC
    ctx->r17 = ADD32(ctx->r17, 0X4EDC);
    // 0x8000CD74: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8000CD78: beql        $s0, $t9, L_8000CE44
    if (ctx->r16 == ctx->r25) {
        // 0x8000CD7C: sw          $s0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r16;
            goto L_8000CE44;
    }
    goto skip_8;
    // 0x8000CD7C: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    skip_8:
    // 0x8000CD80: jal         0x8002650C
    // 0x8000CD84: nop

    func_8002650C(rdram, ctx);
        goto after_14;
    // 0x8000CD84: nop

    after_14:
    // 0x8000CD88: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000CD8C: b           L_8000CE40
    // 0x8000CD90: lw          $s0, 0x4ED8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4ED8);
        goto L_8000CE40;
    // 0x8000CD90: lw          $s0, 0x4ED8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4ED8);
L_8000CD94:
    // 0x8000CD94: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CD98: lwc1        $f18, 0x4ED4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4ED4);
    // 0x8000CD9C: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x8000CDA0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8000CDA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000CDA8: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8000CDAC: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8000CDB0: nop

    // 0x8000CDB4: bc1f        L_8000CDE0
    if (!c1cs) {
        // 0x8000CDB8: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8000CDE0;
    }
    // 0x8000CDB8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000CDBC: ldc1        $f6, 0x11F8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X11F8);
    // 0x8000CDC0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000CDC4: ldc1        $f10, 0x1200($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1200);
    // 0x8000CDC8: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x8000CDCC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8000CDD0: trunc.w.d   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_D(ctx->f16.d);
    // 0x8000CDD4: mfc1        $s6, $f18
    ctx->r22 = (int32_t)ctx->f18.u32l;
    // 0x8000CDD8: b           L_8000CDE8
    // 0x8000CDDC: slti        $at, $s6, 0x2
    ctx->r1 = SIGNED(ctx->r22) < 0X2 ? 1 : 0;
        goto L_8000CDE8;
    // 0x8000CDDC: slti        $at, $s6, 0x2
    ctx->r1 = SIGNED(ctx->r22) < 0X2 ? 1 : 0;
L_8000CDE0:
    // 0x8000CDE0: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8000CDE4: slti        $at, $s6, 0x2
    ctx->r1 = SIGNED(ctx->r22) < 0X2 ? 1 : 0;
L_8000CDE8:
    // 0x8000CDE8: bne         $at, $zero, L_8000CE18
    if (ctx->r1 != 0) {
        // 0x8000CDEC: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_8000CE18;
    }
    // 0x8000CDEC: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8000CDF0: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000CDF4: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8000CDF8: lb          $a0, -0x3D15($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X3D15);
    // 0x8000CDFC: jal         0x8002699C
    // 0x8000CE00: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    func_8002699C(rdram, ctx);
        goto after_15;
    // 0x8000CE00: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    after_15:
    // 0x8000CE04: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000CE08: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000CE0C: addiu       $s1, $s1, 0x4EDC
    ctx->r17 = ADD32(ctx->r17, 0X4EDC);
    // 0x8000CE10: b           L_8000CE40
    // 0x8000CE14: lw          $s0, 0x4ED8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4ED8);
        goto L_8000CE40;
    // 0x8000CE14: lw          $s0, 0x4ED8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4ED8);
L_8000CE18:
    // 0x8000CE18: jal         0x8002650C
    // 0x8000CE1C: nop

    func_8002650C(rdram, ctx);
        goto after_16;
    // 0x8000CE1C: nop

    after_16:
    // 0x8000CE20: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000CE24: addiu       $s1, $s1, 0x4EDC
    ctx->r17 = ADD32(ctx->r17, 0X4EDC);
    // 0x8000CE28: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8000CE2C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8000CE30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000CE34: sw          $t5, 0x4ED8($at)
    MEM_W(0X4ED8, ctx->r1) = ctx->r13;
    // 0x8000CE38: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000CE3C: lw          $s0, 0x4ED8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4ED8);
L_8000CE40:
    // 0x8000CE40: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
L_8000CE44:
    // 0x8000CE44: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8000CE48: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000CE4C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8000CE50: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8000CE54: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8000CE58: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8000CE5C: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8000CE60: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8000CE64: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8000CE68: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8000CE6C: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8000CE70: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8000CE74: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8000CE78: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8000CE7C: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8000CE80: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8000CE84: jr          $ra
    // 0x8000CE88: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8000CE88: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800398B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800398B0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800398B4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800398B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800398BC: jr          $ra
    // 0x800398C0: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    return;
    // 0x800398C0: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    // 0x800398C4: nop

    // 0x800398C8: nop

    // 0x800398CC: nop

;}
RECOMP_FUNC void func_800398F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800398F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800398F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800398F8: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800398FC: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x80039900: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80039904: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039908: mflo        $t7
    ctx->r15 = lo;
    // 0x8003990C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80039910: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x80039914: bnel        $t9, $zero, L_80039948
    if (ctx->r25 != 0) {
        // 0x80039918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80039948;
    }
    goto skip_0;
    // 0x80039918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003991C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80039920: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x80039924: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80039928: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8003992C: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039930: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80039934: mflo        $t1
    ctx->r9 = lo;
    // 0x80039938: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8003993C: jal         0x8003FE6C
    // 0x80039940: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80039940: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_0:
    // 0x80039944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80039948:
    // 0x80039948: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8003994C: jr          $ra
    // 0x80039950: nop

    return;
    // 0x80039950: nop

    // 0x80039954: nop

    // 0x80039958: nop

    // 0x8003995C: nop

;}
RECOMP_FUNC void func_8000E774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E774: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8000E778: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8000E77C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8000E780: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000E784: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000E788: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x8000E78C: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x8000E790: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8000E794: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8000E798: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8000E79C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000E7A0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000E7A4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000E7A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000E7AC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000E7B0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8000E7B4: addiu       $t6, $s7, -0x11
    ctx->r14 = ADD32(ctx->r23, -0X11);
    // 0x8000E7B8: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x8000E7BC: sll         $t7, $s7, 3
    ctx->r15 = S32(ctx->r23 << 3);
    // 0x8000E7C0: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8000E7C4: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8000E7C8: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x8000E7CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000E7D0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8000E7D4: lw          $t8, -0x3784($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3784);
    // 0x8000E7D8: lw          $t6, -0x36F4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36F4);
    // 0x8000E7DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000E7E0: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8000E7E4: beq         $s5, $zero, L_8000EAFC
    if (ctx->r21 == 0) {
        // 0x8000E7E8: sw          $t6, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r14;
            goto L_8000EAFC;
    }
    // 0x8000E7E8: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x8000E7EC: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000E7F0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000E7F4: lui         $ra, 0x8008
    ctx->r31 = S32(0X8008 << 16);
    // 0x8000E7F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000E7FC: addiu       $ra, $ra, 0x4F34
    ctx->r31 = ADD32(ctx->r31, 0X4F34);
    // 0x8000E800: addiu       $s1, $s1, -0x4D04
    ctx->r17 = ADD32(ctx->r17, -0X4D04);
    // 0x8000E804: addiu       $s3, $s3, -0x4D08
    ctx->r19 = ADD32(ctx->r19, -0X4D08);
    // 0x8000E808: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
    // 0x8000E80C: lw          $s2, 0x0($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X0);
L_8000E810:
    // 0x8000E810: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8000E814: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8000E818: lhu         $t7, 0x16($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X16);
    // 0x8000E81C: addiu       $t6, $t6, -0x3C1C
    ctx->r14 = ADD32(ctx->r14, -0X3C1C);
    // 0x8000E820: sll         $t9, $s7, 1
    ctx->r25 = S32(ctx->r23 << 1);
    // 0x8000E824: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8000E828: bnel        $s7, $t8, L_8000EAF4
    if (ctx->r23 != ctx->r24) {
        // 0x8000E82C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_8000EAF4;
    }
    goto skip_0;
    // 0x8000E82C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_0:
    // 0x8000E830: bne         $s4, $zero, L_8000E864
    if (ctx->r20 != 0) {
        // 0x8000E834: addu        $t2, $t9, $t6
        ctx->r10 = ADD32(ctx->r25, ctx->r14);
            goto L_8000E864;
    }
    // 0x8000E834: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8000E838: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000E83C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8000E840: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000E844: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x8000E848: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8000E84C: sw          $fp, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r30;
    // 0x8000E850: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000E854: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8000E858: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8000E85C: lw          $t6, -0x3700($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3700);
    // 0x8000E860: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_8000E864:
    // 0x8000E864: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000E868: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8000E86C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8000E870: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x8000E874: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8000E878: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000E87C: lh          $t6, 0x14($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X14);
    // 0x8000E880: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8000E884: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x8000E888: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000E88C: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8000E890: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000E894: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8000E898: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000E89C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8000E8A0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000E8A4: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8000E8A8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8000E8AC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8000E8B0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000E8B4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8000E8B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000E8BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000E8C0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8000E8C4: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8000E8C8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000E8CC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8000E8D0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000E8D4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000E8D8: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8000E8DC: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x8000E8E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000E8E4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000E8E8: lhu         $a1, -0x22($t2)
    ctx->r5 = MEM_HU(ctx->r10, -0X22);
    // 0x8000E8EC: or          $t5, $s0, $zero
    ctx->r13 = ctx->r16 | 0;
    // 0x8000E8F0: sll         $a2, $a1, 5
    ctx->r6 = S32(ctx->r5 << 5);
    // 0x8000E8F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E8F8: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x8000E8FC: addiu       $a2, $t8, -0x1
    ctx->r6 = ADD32(ctx->r24, -0X1);
    // 0x8000E900: slti        $at, $a2, 0x7FF
    ctx->r1 = SIGNED(ctx->r6) < 0X7FF ? 1 : 0;
    // 0x8000E904: beq         $at, $zero, L_8000E914
    if (ctx->r1 == 0) {
        // 0x8000E908: nop
    
            goto L_8000E914;
    }
    // 0x8000E908: nop

    // 0x8000E90C: b           L_8000E914
    // 0x8000E910: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
        goto L_8000E914;
    // 0x8000E910: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
L_8000E914:
    // 0x8000E914: bgez        $a1, L_8000E924
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8000E918: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8000E924;
    }
    // 0x8000E918: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8000E91C: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8000E920: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8000E924:
    // 0x8000E924: bgtz        $v0, L_8000E934
    if (SIGNED(ctx->r2) > 0) {
        // 0x8000E928: lui         $a2, 0x8008
        ctx->r6 = S32(0X8008 << 16);
            goto L_8000E934;
    }
    // 0x8000E928: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000E92C: b           L_8000E938
    // 0x8000E930: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8000E938;
    // 0x8000E930: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8000E934:
    // 0x8000E934: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8000E938:
    // 0x8000E938: bgtz        $v0, L_8000E948
    if (SIGNED(ctx->r2) > 0) {
        // 0x8000E93C: addiu       $t9, $t4, 0x7FF
        ctx->r25 = ADD32(ctx->r12, 0X7FF);
            goto L_8000E948;
    }
    // 0x8000E93C: addiu       $t9, $t4, 0x7FF
    ctx->r25 = ADD32(ctx->r12, 0X7FF);
    // 0x8000E940: b           L_8000E94C
    // 0x8000E944: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8000E94C;
    // 0x8000E944: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8000E948:
    // 0x8000E948: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8000E94C:
    // 0x8000E94C: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x8000E950: bne         $t1, $zero, L_8000E95C
    if (ctx->r9 != 0) {
        // 0x8000E954: nop
    
            goto L_8000E95C;
    }
    // 0x8000E954: nop

    // 0x8000E958: break       7
    do_break(2147543384);
L_8000E95C:
    // 0x8000E95C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000E960: bne         $t1, $at, L_8000E974
    if (ctx->r9 != ctx->r1) {
        // 0x8000E964: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000E974;
    }
    // 0x8000E964: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000E968: bne         $t9, $at, L_8000E974
    if (ctx->r25 != ctx->r1) {
        // 0x8000E96C: nop
    
            goto L_8000E974;
    }
    // 0x8000E96C: nop

    // 0x8000E970: break       6
    do_break(2147543408);
L_8000E974:
    // 0x8000E974: mflo        $t6
    ctx->r14 = lo;
    // 0x8000E978: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8000E97C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8000E980: andi        $t9, $t3, 0xFFF
    ctx->r25 = ctx->r11 & 0XFFF;
    // 0x8000E984: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8000E988: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8000E98C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8000E990: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8000E994: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000E998: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8000E99C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8000E9A0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000E9A4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000E9A8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000E9AC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000E9B0: lhu         $t7, -0x22($t2)
    ctx->r15 = MEM_HU(ctx->r10, -0X22);
    // 0x8000E9B4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8000E9B8: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x8000E9BC: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x8000E9C0: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8000E9C4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000E9C8: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x8000E9CC: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x8000E9D0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8000E9D4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000E9D8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000E9DC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000E9E0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8000E9E4: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x8000E9E8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000E9EC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000E9F0: lhu         $t7, -0x22($t2)
    ctx->r15 = MEM_HU(ctx->r10, -0X22);
    // 0x8000E9F4: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8000E9F8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8000E9FC: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8000EA00: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8000EA04: ori         $t9, $t7, 0x7C
    ctx->r25 = ctx->r15 | 0X7C;
    // 0x8000EA08: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8000EA0C: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000EA10: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8000EA14: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8000EA18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000EA1C: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8000EA20: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8000EA24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000EA28: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8000EA2C: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8000EA30: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x8000EA34: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8000EA38: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8000EA3C: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8000EA40: lw          $a2, 0x6DEC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6DEC);
    // 0x8000EA44: jal         0x80023500
    // 0x8000EA48: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_80023500(rdram, ctx);
        goto after_0;
    // 0x8000EA48: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8000EA4C: lui         $ra, 0x8008
    ctx->r31 = S32(0X8008 << 16);
    // 0x8000EA50: addiu       $ra, $ra, 0x4F34
    ctx->r31 = ADD32(ctx->r31, 0X4F34);
    // 0x8000EA54: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000EA58: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x8000EA5C: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x8000EA60: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8000EA64: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000EA68: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000EA6C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8000EA70: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8000EA74: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8000EA78: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x8000EA7C: addiu       $t9, $t7, 0xC0
    ctx->r25 = ADD32(ctx->r15, 0XC0);
    // 0x8000EA80: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8000EA84: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8000EA88: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8000EA8C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000EA90: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8000EA94: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000EA98: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8000EA9C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x8000EAA0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000EAA4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000EAA8: lh          $t7, 0x14($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X14);
    // 0x8000EAAC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8000EAB0: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x8000EAB4: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8000EAB8: lbu         $t8, -0x3C18($t6)
    ctx->r24 = MEM_BU(ctx->r14, -0X3C18);
    // 0x8000EABC: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8000EAC0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8000EAC4: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x8000EAC8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8000EACC: sw          $fp, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r30;
    // 0x8000EAD0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EAD4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8000EAD8: lh          $t6, 0x14($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X14);
    // 0x8000EADC: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8000EAE0: sh          $t8, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r24;
    // 0x8000EAE4: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    // 0x8000EAE8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000EAEC: sw          $t9, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r25;
    // 0x8000EAF0: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_8000EAF4:
    // 0x8000EAF4: bnel        $s5, $zero, L_8000E810
    if (ctx->r21 != 0) {
        // 0x8000EAF8: lw          $s2, 0x0($s6)
        ctx->r18 = MEM_W(ctx->r22, 0X0);
            goto L_8000E810;
    }
    goto skip_1;
    // 0x8000EAF8: lw          $s2, 0x0($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X0);
    skip_1:
L_8000EAFC:
    // 0x8000EAFC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8000EB00: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000EB04: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000EB08: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000EB0C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000EB10: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8000EB14: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8000EB18: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8000EB1C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8000EB20: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8000EB24: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8000EB28: jr          $ra
    // 0x8000EB2C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8000EB2C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80010080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010080: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010084: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80010088: addiu       $a1, $a1, 0x5368
    ctx->r5 = ADD32(ctx->r5, 0X5368);
    // 0x8001008C: addiu       $v1, $v1, 0x5350
    ctx->r3 = ADD32(ctx->r3, 0X5350);
    // 0x80010090: addiu       $t6, $a0, 0x1E
    ctx->r14 = ADD32(ctx->r4, 0X1E);
    // 0x80010094: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80010098: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8001009C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800100A0: lhu         $t8, 0x2($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X2);
    // 0x800100A4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800100A8: lhu         $t9, 0x4($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X4);
    // 0x800100AC: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800100B0: lhu         $t0, 0x14($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X14);
    // 0x800100B4: sh          $t0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r8;
    // 0x800100B8: lhu         $t1, 0x1A($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X1A);
    // 0x800100BC: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800100C0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800100C4: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    // 0x800100C8: jr          $ra
    // 0x800100CC: nop

    return;
    // 0x800100CC: nop

;}
RECOMP_FUNC void func_80006340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006340: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80006344: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006348: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000634C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80006350: addiu       $v0, $v0, 0x5368
    ctx->r2 = ADD32(ctx->r2, 0X5368);
    // 0x80006354: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80006358: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000635C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80006360: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80006364: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80006368: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000636C: lw          $t8, 0x4F24($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F24);
    // 0x80006370: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80006374: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80006378: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000637C: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x80006380: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80006384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80006388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000638C: jal         0x8000DB7C
    // 0x80006390: lhu         $a2, 0xC($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0XC);
    func_8000DB7C(rdram, ctx);
        goto after_0;
    // 0x80006390: lhu         $a2, 0xC($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0XC);
    after_0:
    // 0x80006394: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80006398: lhu         $v0, 0x5374($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5374);
    // 0x8000639C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800063A0: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x800063A4: sra         $t0, $v0, 8
    ctx->r8 = S32(SIGNED(ctx->r2) >> 8);
    // 0x800063A8: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x800063AC: bne         $t1, $at, L_80006418
    if (ctx->r9 != ctx->r1) {
        // 0x800063B0: addiu       $t7, $zero, 0x8
        ctx->r15 = ADD32(0, 0X8);
            goto L_80006418;
    }
    // 0x800063B0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800063B4: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // 0x800063B8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800063BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800063C0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800063C4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800063C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800063CC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x800063D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800063D4: jal         0x8001D8B0
    // 0x800063D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x800063D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800063DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800063E0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800063E4: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x800063E8: sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
    // 0x800063EC: sh          $t5, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r13;
    // 0x800063F0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800063F4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800063F8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800063FC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80006400: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80006404: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80006408: jal         0x800268D4
    // 0x8000640C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    func_800268D4(rdram, ctx);
        goto after_2;
    // 0x8000640C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80006410: b           L_800065E4
    // 0x80006414: lhu         $t3, 0x60($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X60);
        goto L_800065E4;
    // 0x80006414: lhu         $t3, 0x60($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X60);
L_80006418:
    // 0x80006418: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x8000641C: sh          $t7, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r15;
    // 0x80006420: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80006424: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80006428: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000642C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80006430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80006438: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8000643C: jal         0x8001D8B0
    // 0x80006440: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_3;
    // 0x80006440: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80006444: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80006448: lhu         $t0, 0x5374($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X5374);
    // 0x8000644C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006450: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x80006454: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80006458: beq         $t1, $zero, L_80006494
    if (ctx->r9 == 0) {
        // 0x8000645C: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_80006494;
    }
    // 0x8000645C: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80006460: lui         $at, 0xC305
    ctx->r1 = S32(0XC305 << 16);
    // 0x80006464: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006468: lui         $at, 0xC2B8
    ctx->r1 = S32(0XC2B8 << 16);
    // 0x8000646C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80006470: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006474: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80006478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000647C: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x80006480: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x80006484: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80006488: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8000648C: b           L_800064B8
    // 0x80006490: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
        goto L_800064B8;
    // 0x80006490: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
L_80006494:
    // 0x80006494: lui         $at, 0xC2EE
    ctx->r1 = S32(0XC2EE << 16);
    // 0x80006498: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000649C: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x800064A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800064A4: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x800064A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800064AC: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800064B0: swc1        $f16, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f16.u32l;
    // 0x800064B4: swc1        $f18, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f18.u32l;
L_800064B8:
    // 0x800064B8: sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // 0x800064BC: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800064C0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800064C4: ldc1        $f8, 0x10C8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X10C8);
    // 0x800064C8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800064CC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800064D0: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800064D4: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x800064D8: jal         0x800232F4
    // 0x800064DC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_4;
    // 0x800064DC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x800064E0: lhu         $t2, 0x4($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X4);
    // 0x800064E4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800064E8: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x800064EC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800064F0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800064F4: bgez        $t2, L_8000650C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800064F8: cvt.s.w     $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8000650C;
    }
    // 0x800064F8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800064FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006500: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80006504: nop

    // 0x80006508: add.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f18.fl;
L_8000650C:
    // 0x8000650C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80006510: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80006514: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80006518: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000651C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80006520: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80006524: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80006528: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000652C: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80006530: swc1        $f6, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f6.u32l;
    // 0x80006534: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80006538: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000653C: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80006540: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80006544: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80006548: swc1        $f2, 0x134($s1)
    MEM_W(0X134, ctx->r17) = ctx->f2.u32l;
    // 0x8000654C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80006550: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80006554: div.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80006558: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x8000655C: swc1        $f8, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f8.u32l;
    // 0x80006560: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80006564: ldc1        $f4, 0x10D0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X10D0);
    // 0x80006568: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000656C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80006570: ldc1        $f18, 0x10D8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X10D8);
    // 0x80006574: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80006578: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000657C: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x80006580: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80006584: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80006588: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x8000658C: nop

    // 0x80006590: bc1f        L_800065AC
    if (!c1cs) {
        // 0x80006594: nop
    
            goto L_800065AC;
    }
    // 0x80006594: nop

    // 0x80006598: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000659C: ldc1        $f16, 0x10E0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X10E0);
    // 0x800065A0: sub.d       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f0.d - ctx->f16.d;
    // 0x800065A4: b           L_800065D0
    // 0x800065A8: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
        goto L_800065D0;
    // 0x800065A8: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_800065AC:
    // 0x800065AC: ldc1        $f10, 0x10E8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X10E8);
    // 0x800065B0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800065B4: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x800065B8: nop

    // 0x800065BC: bc1fl       L_800065D4
    if (!c1cs) {
        // 0x800065C0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800065D4;
    }
    goto skip_0;
    // 0x800065C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800065C4: ldc1        $f6, 0x10F0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X10F0);
    // 0x800065C8: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x800065CC: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
L_800065D0:
    // 0x800065D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800065D4:
    // 0x800065D4: swc1        $f2, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f2.u32l;
    // 0x800065D8: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800065DC: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x800065E0: lhu         $t3, 0x60($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X60);
L_800065E4:
    // 0x800065E4: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x800065E8: sh          $t4, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r12;
    // 0x800065EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800065F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800065F4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800065F8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800065FC: jr          $ra
    // 0x80006600: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80006600: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800268D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800268D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800268D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800268DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800268E0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800268E4: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x800268E8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800268EC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800268F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800268F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800268F8: lb          $t8, 0x1F($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X1F);
    // 0x800268FC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80026900: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026904: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80026908: lbu         $t9, 0x3CAC($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X3CAC);
    // 0x8002690C: lbu         $t1, -0x33A($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X33A);
    // 0x80026910: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80026914: multu       $t9, $a2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80026918: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8002691C: mflo        $t0
    ctx->r8 = lo;
    // 0x80026920: nop

    // 0x80026924: nop

    // 0x80026928: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002692C: mflo        $a3
    ctx->r7 = lo;
    // 0x80026930: srl         $t2, $a3, 16
    ctx->r10 = S32(U32(ctx->r7) >> 16);
    // 0x80026934: bne         $a0, $zero, L_80026950
    if (ctx->r4 != 0) {
        // 0x80026938: or          $a3, $t2, $zero
        ctx->r7 = ctx->r10 | 0;
            goto L_80026950;
    }
    // 0x80026938: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8002693C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80026940: jal         0x80025B8C
    // 0x80026944: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80025B8C(rdram, ctx);
        goto after_0;
    // 0x80026944: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_0:
    // 0x80026948: b           L_80026990
    // 0x8002694C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80026990;
    // 0x8002694C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80026950:
    // 0x80026950: lbu         $t3, -0x338($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X338);
    // 0x80026954: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026958: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8002695C: beq         $t3, $zero, L_8002697C
    if (ctx->r11 == 0) {
        // 0x80026960: addiu       $v1, $v1, -0x338
        ctx->r3 = ADD32(ctx->r3, -0X338);
            goto L_8002697C;
    }
    // 0x80026960: addiu       $v1, $v1, -0x338
    ctx->r3 = ADD32(ctx->r3, -0X338);
    // 0x80026964: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80026968:
    // 0x80026968: beq         $v0, $zero, L_8002697C
    if (ctx->r2 == 0) {
        // 0x8002696C: addiu       $v1, $v1, 0x3
        ctx->r3 = ADD32(ctx->r3, 0X3);
            goto L_8002697C;
    }
    // 0x8002696C: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x80026970: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x80026974: bnel        $t4, $zero, L_80026968
    if (ctx->r12 != 0) {
        // 0x80026978: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80026968;
    }
    goto skip_0;
    // 0x80026978: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
L_8002697C:
    // 0x8002697C: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80026980: lb          $t5, 0x1F($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X1F);
    // 0x80026984: sb          $a3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r7;
    // 0x80026988: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
    // 0x8002698C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80026990:
    // 0x80026990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026994: jr          $ra
    // 0x80026998: nop

    return;
    // 0x80026998: nop

;}
RECOMP_FUNC void func_800111F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800111F8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800111FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011200: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80011204: lw          $t6, -0x4D0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D0C);
    // 0x80011208: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8001120C: addiu       $t2, $t2, -0x4D04
    ctx->r10 = ADD32(ctx->r10, -0X4D04);
    // 0x80011210: beq         $t6, $zero, L_80011234
    if (ctx->r14 == 0) {
        // 0x80011214: sll         $t7, $a0, 3
        ctx->r15 = S32(ctx->r4 << 3);
            goto L_80011234;
    }
    // 0x80011214: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80011218: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8001121C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80011220: addiu       $t8, $t8, 0x5810
    ctx->r24 = ADD32(ctx->r24, 0X5810);
    // 0x80011224: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80011228: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001122C: b           L_80011250
    // 0x80011230: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
        goto L_80011250;
    // 0x80011230: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
L_80011234:
    // 0x80011234: sll         $t4, $a0, 3
    ctx->r12 = S32(ctx->r4 << 3);
    // 0x80011238: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8001123C: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80011240: addiu       $t5, $t5, 0x5650
    ctx->r13 = ADD32(ctx->r13, 0X5650);
    // 0x80011244: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80011248: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x8001124C: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
L_80011250:
    // 0x80011250: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80011254: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80011258: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001125C: addiu       $t7, $t7, 0x59E8
    ctx->r15 = ADD32(ctx->r15, 0X59E8);
    // 0x80011260: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80011264: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x80011268: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x8001126C: beql        $a2, $zero, L_80011324
    if (ctx->r6 == 0) {
        // 0x80011270: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80011324;
    }
    goto skip_0;
    // 0x80011270: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    skip_0:
    // 0x80011274: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
    // 0x80011278: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001127C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80011280: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80011284: beq         $a2, $at, L_800112A8
    if (ctx->r6 == ctx->r1) {
        // 0x80011288: lw          $t1, 0x8($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X8);
            goto L_800112A8;
    }
    // 0x80011288: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x8001128C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80011290: beq         $a2, $at, L_800112C8
    if (ctx->r6 == ctx->r1) {
        // 0x80011294: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800112C8;
    }
    // 0x80011294: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80011298: beql        $a2, $at, L_800112F0
    if (ctx->r6 == ctx->r1) {
        // 0x8001129C: lw          $t4, 0x8($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X8);
            goto L_800112F0;
    }
    goto skip_1;
    // 0x8001129C: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
    skip_1:
    // 0x800112A0: b           L_8001132C
    // 0x800112A4: nop

        goto L_8001132C;
    // 0x800112A4: nop

L_800112A8:
    // 0x800112A8: lw          $t9, 0x8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X8);
    // 0x800112AC: addiu       $t8, $v1, 0xC
    ctx->r24 = ADD32(ctx->r3, 0XC);
    // 0x800112B0: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x800112B4: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x800112B8: bne         $t4, $zero, L_8001132C
    if (ctx->r12 != 0) {
        // 0x800112BC: sw          $t4, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->r12;
            goto L_8001132C;
    }
    // 0x800112BC: sw          $t4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r12;
    // 0x800112C0: b           L_8001132C
    // 0x800112C4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_8001132C;
    // 0x800112C4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_800112C8:
    // 0x800112C8: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800112CC: beq         $v0, $zero, L_8001132C
    if (ctx->r2 == 0) {
        // 0x800112D0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8001132C;
    }
    // 0x800112D0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800112D4: beq         $t6, $zero, L_8001132C
    if (ctx->r14 == 0) {
        // 0x800112D8: sw          $t6, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->r14;
            goto L_8001132C;
    }
    // 0x800112D8: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x800112DC: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x800112E0: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x800112E4: b           L_8001132C
    // 0x800112E8: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
        goto L_8001132C;
    // 0x800112E8: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    // 0x800112EC: lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X8);
L_800112F0:
    // 0x800112F0: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800112F4: bne         $t5, $zero, L_80011310
    if (ctx->r13 != 0) {
        // 0x800112F8: sw          $t5, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->r13;
            goto L_80011310;
    }
    // 0x800112F8: sw          $t5, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r13;
    // 0x800112FC: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x80011300: lw          $t8, 0x14($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14);
    // 0x80011304: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x80011308: b           L_8001132C
    // 0x8001130C: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
        goto L_8001132C;
    // 0x8001130C: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
L_80011310:
    // 0x80011310: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x80011314: addiu       $t4, $t9, 0xC
    ctx->r12 = ADD32(ctx->r25, 0XC);
    // 0x80011318: b           L_8001132C
    // 0x8001131C: sw          $t4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r12;
        goto L_8001132C;
    // 0x8001131C: sw          $t4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r12;
    // 0x80011320: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80011324:
    // 0x80011324: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80011328: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8001132C:
    // 0x8001132C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80011330: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80011334: andi        $t9, $t0, 0xFF
    ctx->r25 = ctx->r8 & 0XFF;
    // 0x80011338: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001133C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80011340: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80011344: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x80011348: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x8001134C: sll         $t8, $a0, 24
    ctx->r24 = S32(ctx->r4 << 24);
    // 0x80011350: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x80011354: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80011358: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8001135C: ori         $t8, $t9, 0xB4
    ctx->r24 = ctx->r25 | 0XB4;
    // 0x80011360: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80011364: lw          $t4, 0x18($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X18);
    // 0x80011368: beq         $t4, $zero, L_80011508
    if (ctx->r12 == 0) {
        // 0x8001136C: nop
    
            goto L_80011508;
    }
    // 0x8001136C: nop

    // 0x80011370: lw          $a0, 0x24($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24);
    // 0x80011374: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80011378: addiu       $a2, $a2, 0x5B68
    ctx->r6 = ADD32(ctx->r6, 0X5B68);
    // 0x8001137C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80011380: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80011384: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80011388: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001138C: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011390: addiu       $v0, $v0, 0x5B74
    ctx->r2 = ADD32(ctx->r2, 0X5B74);
    // 0x80011394: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x80011398: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8001139C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800113A0: mflo        $t7
    ctx->r15 = lo;
    // 0x800113A4: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800113A8: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x800113AC: lw          $t4, -0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X8);
    // 0x800113B0: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800113B4: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800113B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800113BC: sra         $t5, $t6, 8
    ctx->r13 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800113C0: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800113C4: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x800113C8: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800113CC: mflo        $t8
    ctx->r24 = lo;
    // 0x800113D0: sra         $t4, $t8, 8
    ctx->r12 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800113D4: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
L_800113D8:
    // 0x800113D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800113DC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800113E0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800113E4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800113E8: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800113EC: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x800113F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800113F4: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800113F8: sw          $t9, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->r25;
    // 0x800113FC: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x80011400: lw          $t8, -0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X8);
    // 0x80011404: multu       $t8, $t4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011408: mflo        $t6
    ctx->r14 = lo;
    // 0x8001140C: sra         $t5, $t6, 8
    ctx->r13 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80011410: sw          $t5, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->r13;
    // 0x80011414: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80011418: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x8001141C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011420: mflo        $t8
    ctx->r24 = lo;
    // 0x80011424: sra         $t4, $t8, 8
    ctx->r12 = S32(SIGNED(ctx->r24) >> 8);
    // 0x80011428: bne         $v1, $zero, L_800113D8
    if (ctx->r3 != 0) {
        // 0x8001142C: sw          $t4, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->r12;
            goto L_800113D8;
    }
    // 0x8001142C: sw          $t4, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r12;
    // 0x80011430: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80011434: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011438: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001143C: sw          $t6, 0x5BB0($at)
    MEM_W(0X5BB0, ctx->r1) = ctx->r14;
    // 0x80011440: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x80011444: addiu       $v1, $v1, 0x5BB4
    ctx->r3 = ADD32(ctx->r3, 0X5BB4);
    // 0x80011448: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001144C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80011450: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80011454: addiu       $t0, $t0, 0x5BB8
    ctx->r8 = ADD32(ctx->r8, 0X5BB8);
    // 0x80011458: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x8001145C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80011460: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80011464: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011468: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8001146C: beq         $v0, $at, L_8001148C
    if (ctx->r2 == ctx->r1) {
        // 0x80011470: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001148C;
    }
    // 0x80011470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80011474: beq         $v0, $at, L_800114B0
    if (ctx->r2 == ctx->r1) {
        // 0x80011478: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800114B0;
    }
    // 0x80011478: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001147C: beql        $v0, $at, L_800114D8
    if (ctx->r2 == ctx->r1) {
        // 0x80011480: lw          $t6, 0x20($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X20);
            goto L_800114D8;
    }
    goto skip_2;
    // 0x80011480: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    skip_2:
    // 0x80011484: b           L_8001153C
    // 0x80011488: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
        goto L_8001153C;
    // 0x80011488: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
L_8001148C:
    // 0x8001148C: lw          $t9, 0x24($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X24);
    // 0x80011490: lw          $t4, 0x20($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X20);
    // 0x80011494: addiu       $t8, $t9, 0x18
    ctx->r24 = ADD32(ctx->r25, 0X18);
    // 0x80011498: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8001149C: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
    // 0x800114A0: bne         $t6, $zero, L_80011538
    if (ctx->r14 != 0) {
        // 0x800114A4: sw          $t6, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r14;
            goto L_80011538;
    }
    // 0x800114A4: sw          $t6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r14;
    // 0x800114A8: b           L_80011538
    // 0x800114AC: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
        goto L_80011538;
    // 0x800114AC: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
L_800114B0:
    // 0x800114B0: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
    // 0x800114B4: beq         $v0, $zero, L_80011538
    if (ctx->r2 == 0) {
        // 0x800114B8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80011538;
    }
    // 0x800114B8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800114BC: beq         $t7, $zero, L_80011538
    if (ctx->r15 == 0) {
        // 0x800114C0: sw          $t7, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r15;
            goto L_80011538;
    }
    // 0x800114C0: sw          $t7, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r15;
    // 0x800114C4: lw          $t8, 0x24($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X24);
    // 0x800114C8: addiu       $t4, $t8, 0x18
    ctx->r12 = ADD32(ctx->r24, 0X18);
    // 0x800114CC: b           L_80011538
    // 0x800114D0: sw          $t4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r12;
        goto L_80011538;
    // 0x800114D0: sw          $t4, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r12;
    // 0x800114D4: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
L_800114D8:
    // 0x800114D8: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x800114DC: bne         $t5, $zero, L_800114F8
    if (ctx->r13 != 0) {
        // 0x800114E0: sw          $t5, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r13;
            goto L_800114F8;
    }
    // 0x800114E0: sw          $t5, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r13;
    // 0x800114E4: lw          $t9, 0x1C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1C);
    // 0x800114E8: lw          $t8, 0x28($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X28);
    // 0x800114EC: sw          $t9, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r25;
    // 0x800114F0: b           L_80011538
    // 0x800114F4: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
        goto L_80011538;
    // 0x800114F4: sw          $t8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r24;
L_800114F8:
    // 0x800114F8: lw          $t4, 0x24($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X24);
    // 0x800114FC: addiu       $t6, $t4, 0x18
    ctx->r14 = ADD32(ctx->r12, 0X18);
    // 0x80011500: b           L_80011538
    // 0x80011504: sw          $t6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r14;
        goto L_80011538;
    // 0x80011504: sw          $t6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r14;
L_80011508:
    // 0x80011508: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001150C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80011510: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80011514: addiu       $t0, $t0, 0x5BB8
    ctx->r8 = ADD32(ctx->r8, 0X5BB8);
    // 0x80011518: addiu       $v1, $v1, 0x5BB4
    ctx->r3 = ADD32(ctx->r3, 0X5BB4);
    // 0x8001151C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80011520: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80011524: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80011528: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001152C: addiu       $a3, $a2, 0x5B68
    ctx->r7 = ADD32(ctx->r6, 0X5B68);
    // 0x80011530: sw          $t5, 0x5BB0($at)
    MEM_W(0X5BB0, ctx->r1) = ctx->r13;
    // 0x80011534: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
L_80011538:
    // 0x80011538: lw          $t8, 0x2C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X2C);
L_8001153C:
    // 0x8001153C: bne         $t8, $zero, L_80011550
    if (ctx->r24 != 0) {
        // 0x80011540: sw          $t8, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r24;
            goto L_80011550;
    }
    // 0x80011540: sw          $t8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r24;
    // 0x80011544: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80011548: addiu       $t6, $t6, 0x5B98
    ctx->r14 = ADD32(ctx->r14, 0X5B98);
    // 0x8001154C: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
L_80011550:
    // 0x80011550: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80011554: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80011558: bne         $t5, $at, L_800115D0
    if (ctx->r13 != ctx->r1) {
        // 0x8001155C: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_800115D0;
    }
    // 0x8001155C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80011560: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80011564: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80011568:
    // 0x80011568: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001156C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80011570: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    // 0x80011574: sra         $t7, $a0, 2
    ctx->r15 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80011578: subu        $t9, $a0, $t7
    ctx->r25 = SUB32(ctx->r4, ctx->r15);
    // 0x8001157C: addiu       $t8, $t9, 0x3F
    ctx->r24 = ADD32(ctx->r25, 0X3F);
    // 0x80011580: sw          $t8, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->r24;
    // 0x80011584: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80011588: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8001158C: sra         $t4, $a1, 2
    ctx->r12 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80011590: subu        $t6, $a1, $t4
    ctx->r14 = SUB32(ctx->r5, ctx->r12);
    // 0x80011594: addiu       $t5, $t6, 0x3F
    ctx->r13 = ADD32(ctx->r14, 0X3F);
    // 0x80011598: sw          $t5, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->r13;
    // 0x8001159C: lw          $a2, -0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X4);
    // 0x800115A0: sra         $t7, $a2, 2
    ctx->r15 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800115A4: subu        $t9, $a2, $t7
    ctx->r25 = SUB32(ctx->r6, ctx->r15);
    // 0x800115A8: addiu       $t8, $t9, 0x3F
    ctx->r24 = ADD32(ctx->r25, 0X3F);
    // 0x800115AC: bne         $v1, $zero, L_80011568
    if (ctx->r3 != 0) {
        // 0x800115B0: sw          $t8, -0x4($a3)
        MEM_W(-0X4, ctx->r7) = ctx->r24;
            goto L_80011568;
    }
    // 0x800115B0: sw          $t8, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->r24;
    // 0x800115B4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800115B8: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x800115BC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800115C0: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800115C4: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800115C8: sw          $t5, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r13;
    // 0x800115CC: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
L_800115D0:
    // 0x800115D0: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x800115D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800115D8: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x800115DC: jal         0x80011768
    // 0x800115E0: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    func_80011768(rdram, ctx);
        goto after_0;
    // 0x800115E0: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    after_0:
    // 0x800115E4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800115E8: addiu       $t2, $t2, -0x4D04
    ctx->r10 = ADD32(ctx->r10, -0X4D04);
    // 0x800115EC: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x800115F0: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800115F4: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800115F8: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800115FC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80011600: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011604: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80011608: ori         $t8, $t8, 0x80
    ctx->r24 = ctx->r24 | 0X80;
    // 0x8001160C: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x80011610: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80011614: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80011618: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8001161C: lui         $t6, 0x386
    ctx->r14 = S32(0X386 << 16);
    // 0x80011620: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80011624: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80011628: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8001162C: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x80011630: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80011634: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80011638: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8001163C: lui         $t9, 0x388
    ctx->r25 = S32(0X388 << 16);
    // 0x80011640: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x80011644: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011648: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8001164C: addiu       $t8, $t3, 0x18
    ctx->r24 = ADD32(ctx->r11, 0X18);
    // 0x80011650: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80011654: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80011658: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8001165C: lui         $t6, 0x38A
    ctx->r14 = S32(0X38A << 16);
    // 0x80011660: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x80011664: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80011668: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8001166C: addiu       $t5, $t3, 0x28
    ctx->r13 = ADD32(ctx->r11, 0X28);
    // 0x80011670: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80011674: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80011678: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8001167C: lui         $t9, 0x38C
    ctx->r25 = S32(0X38C << 16);
    // 0x80011680: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x80011684: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011688: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8001168C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80011690: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80011694: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80011698: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x8001169C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800116A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800116A4: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x800116A8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800116AC: lw          $t6, 0x2C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X2C);
    // 0x800116B0: lw          $t8, 0x24($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X24);
    // 0x800116B4: addiu       $v1, $v1, -0x4CF8
    ctx->r3 = ADD32(ctx->r3, -0X4CF8);
    // 0x800116B8: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x800116BC: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x800116C0: lw          $t5, 0x28($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X28);
    // 0x800116C4: sll         $t4, $t8, 24
    ctx->r12 = S32(ctx->r24 << 24);
    // 0x800116C8: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x800116CC: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x800116D0: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800116D4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800116D8: ori         $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 | 0XFF;
    // 0x800116DC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800116E0: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x800116E4: lhu         $t5, 0x4EE0($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X4EE0);
    // 0x800116E8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800116EC: addiu       $v0, $v0, -0x4CFC
    ctx->r2 = ADD32(ctx->r2, -0X4CFC);
    // 0x800116F0: andi        $t9, $t5, 0x80
    ctx->r25 = ctx->r13 & 0X80;
    // 0x800116F4: beq         $t9, $zero, L_8001172C
    if (ctx->r25 == 0) {
        // 0x800116F8: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_8001172C;
    }
    // 0x800116F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800116FC: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x80011700: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011704: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80011708: sw          $t6, -0x4D00($at)
    MEM_W(-0X4D00, ctx->r1) = ctx->r14;
    // 0x8001170C: lw          $t8, 0x28($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X28);
    // 0x80011710: addiu       $v0, $v0, -0x4CFC
    ctx->r2 = ADD32(ctx->r2, -0X4CFC);
    // 0x80011714: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011718: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001171C: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    // 0x80011720: addiu       $v1, $v1, -0x4CF8
    ctx->r3 = ADD32(ctx->r3, -0X4CF8);
    // 0x80011724: b           L_80011738
    // 0x80011728: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_80011738;
    // 0x80011728: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8001172C:
    // 0x8001172C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80011730: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80011734: sw          $zero, -0x4D00($at)
    MEM_W(-0X4D00, ctx->r1) = 0;
L_80011738:
    // 0x80011738: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x8001173C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011744: sw          $t9, 0x5BBC($at)
    MEM_W(0X5BBC, ctx->r1) = ctx->r25;
    // 0x80011748: lw          $t6, 0x28($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X28);
    // 0x8001174C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80011750: sw          $t6, 0x5BC0($at)
    MEM_W(0X5BC0, ctx->r1) = ctx->r14;
    // 0x80011754: lw          $t8, 0x2C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X2C);
    // 0x80011758: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001175C: sw          $t8, 0x5BC4($at)
    MEM_W(0X5BC4, ctx->r1) = ctx->r24;
    // 0x80011760: jr          $ra
    // 0x80011764: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80011764: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8001C560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C560: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001C564: addiu       $v0, $v0, -0x3A6E
    ctx->r2 = ADD32(ctx->r2, -0X3A6E);
    // 0x8001C568: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8001C56C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001C570: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001C574: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8001C578: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001C57C: lhu         $t8, 0x4F10($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X4F10);
    // 0x8001C580: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C584: swc1        $f4, -0x3A8C($at)
    MEM_W(-0X3A8C, ctx->r1) = ctx->f4.u32l;
    // 0x8001C588: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C58C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001C590: beq         $t9, $zero, L_8001C5EC
    if (ctx->r25 == 0) {
        // 0x8001C594: sh          $zero, -0x3A88($at)
        MEM_H(-0X3A88, ctx->r1) = 0;
            goto L_8001C5EC;
    }
    // 0x8001C594: sh          $zero, -0x3A88($at)
    MEM_H(-0X3A88, ctx->r1) = 0;
    // 0x8001C598: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C59C: lw          $v0, 0x4F18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4F18);
    // 0x8001C5A0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C5A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C5A8: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8001C5AC: beq         $v1, $zero, L_8001C5E0
    if (ctx->r3 == 0) {
        // 0x8001C5B0: nop
    
            goto L_8001C5E0;
    }
    // 0x8001C5B0: nop

    // 0x8001C5B4: lw          $a0, 0x4EE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EE8);
    // 0x8001C5B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C5BC: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x8001C5C0: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8001C5C4: sw          $t1, -0x3AA0($at)
    MEM_W(-0X3AA0, ctx->r1) = ctx->r9;
    // 0x8001C5C8: lw          $t2, 0x34($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X34);
    // 0x8001C5CC: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x8001C5D0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C5D4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8001C5D8: jr          $ra
    // 0x8001C5DC: sw          $t4, -0x3A9C($at)
    MEM_W(-0X3A9C, ctx->r1) = ctx->r12;
    return;
    // 0x8001C5DC: sw          $t4, -0x3A9C($at)
    MEM_W(-0X3A9C, ctx->r1) = ctx->r12;
L_8001C5E0:
    // 0x8001C5E0: sw          $zero, -0x3AA0($at)
    MEM_W(-0X3AA0, ctx->r1) = 0;
    // 0x8001C5E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C5E8: sw          $zero, -0x3A9C($at)
    MEM_W(-0X3A9C, ctx->r1) = 0;
L_8001C5EC:
    // 0x8001C5EC: jr          $ra
    // 0x8001C5F0: nop

    return;
    // 0x8001C5F0: nop

;}
RECOMP_FUNC void func_8000E3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E3C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000E3C8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000E3CC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000E3D0: sw          $zero, -0x2D30($at)
    MEM_W(-0X2D30, ctx->r1) = 0;
    // 0x8000E3D4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8000E3D8: addiu       $v1, $v1, 0x4098
    ctx->r3 = ADD32(ctx->r3, 0X4098);
    // 0x8000E3DC: addiu       $a0, $a0, 0x4180
    ctx->r4 = ADD32(ctx->r4, 0X4180);
L_8000E3E0:
    // 0x8000E3E0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000E3E4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000E3E8: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x8000E3EC: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x8000E3F0: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x8000E3F4: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x8000E3F8: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    // 0x8000E3FC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000E400: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x8000E404: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x8000E408: bne         $v0, $zero, L_8000E3E0
    if (ctx->r2 != 0) {
        // 0x8000E40C: addiu       $a0, $a0, 0x70
        ctx->r4 = ADD32(ctx->r4, 0X70);
            goto L_8000E3E0;
    }
    // 0x8000E40C: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    // 0x8000E410: jr          $ra
    // 0x8000E414: nop

    return;
    // 0x8000E414: nop

;}
RECOMP_FUNC void func_800183C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800183C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800183C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800183CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800183D0: lhu         $t6, 0xA($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XA);
    // 0x800183D4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x800183D8: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800183DC: beql        $t7, $zero, L_800183F0
    if (ctx->r15 == 0) {
        // 0x800183E0: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800183F0;
    }
    goto skip_0;
    // 0x800183E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_0:
    // 0x800183E4: b           L_80018464
    // 0x800183E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80018464;
    // 0x800183E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800183EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_800183F0:
    // 0x800183F0: jal         0x80022FD0
    // 0x800183F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    get_rand(rdram, ctx);
        goto after_0;
    // 0x800183F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800183F8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800183FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80018400: lw          $t8, 0x2C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X2C);
    // 0x80018404: lhu         $t9, 0xE($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XE);
    // 0x80018408: sltu        $v1, $v0, $t9
    ctx->r3 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8001840C: beql        $v1, $zero, L_80018468
    if (ctx->r3 == 0) {
        // 0x80018410: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_80018468;
    }
    goto skip_1;
    // 0x80018410: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    skip_1:
    // 0x80018414: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x80018418: beql        $a1, $a0, L_80018464
    if (ctx->r5 == ctx->r4) {
        // 0x8001841C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80018464;
    }
    goto skip_2;
    // 0x8001841C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80018420: lhu         $t0, 0x5E($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X5E);
    // 0x80018424: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80018428: beq         $t1, $zero, L_80018454
    if (ctx->r9 == 0) {
        // 0x8001842C: nop
    
            goto L_80018454;
    }
    // 0x8001842C: nop

    // 0x80018430: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80018434: jal         0x8000B140
    // 0x80018438: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8000B140(rdram, ctx);
        goto after_1;
    // 0x80018438: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8001843C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80018440: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80018444: jal         0x80006A74
    // 0x80018448: lw          $a1, 0x24($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X24);
    func_80006A74(rdram, ctx);
        goto after_2;
    // 0x80018448: lw          $a1, 0x24($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X24);
    after_2:
    // 0x8001844C: b           L_80018460
    // 0x80018450: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80018460;
    // 0x80018450: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80018454:
    // 0x80018454: jal         0x8000ABF4
    // 0x80018458: nop

    func_8000ABF4(rdram, ctx);
        goto after_3;
    // 0x80018458: nop

    after_3:
    // 0x8001845C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80018460:
    // 0x80018460: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80018464:
    // 0x80018464: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
L_80018468:
    // 0x80018468: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8001846C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80018470: lw          $v0, -0x321C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X321C);
    // 0x80018474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001847C: jr          $ra
    // 0x80018480: nop

    return;
    // 0x80018480: nop

;}
RECOMP_FUNC void guOrthoF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035848: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003584C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80035850: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80035854: jal         0x80035300
    // 0x80035858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80035858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003585C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80035860: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80035864: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035868: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003586C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035870: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80035874: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80035878: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003587C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035880: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80035884: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035888: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8003588C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035890: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80035894: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80035898: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8003589C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800358A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800358A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800358A8: sub.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800358AC: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800358B0: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800358B4: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x800358B8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x800358BC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800358C0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800358C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800358C8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800358CC: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800358D0: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x800358D4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800358D8: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800358DC: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800358E0: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800358E4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800358E8: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800358EC: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800358F0: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x800358F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800358F8: nop

    // 0x800358FC: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x80035900: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x80035904: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80035908: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003590C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80035910: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80035914: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035918: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003591C: beq         $v1, $a0, L_80035960
    if (ctx->r3 == ctx->r4) {
        // 0x80035920: lwc1        $f16, 0xC($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80035960;
    }
    // 0x80035920: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
L_80035924:
    // 0x80035924: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80035928: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003592C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80035930: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80035934: lwc1        $f14, 0x18($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80035938: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003593C: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035940: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80035944: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x80035948: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003594C: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80035950: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80035954: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80035958: bne         $v1, $a0, L_80035924
    if (ctx->r3 != ctx->r4) {
        // 0x8003595C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80035924;
    }
    // 0x8003595C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
L_80035960:
    // 0x80035960: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80035964: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80035968: swc1        $f12, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
    // 0x8003596C: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80035970: nop

    // 0x80035974: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035978: swc1        $f10, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003597C: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80035980: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80035984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003598C: jr          $ra
    // 0x80035990: nop

    return;
    // 0x80035990: nop

;}
RECOMP_FUNC void func_8003717C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003717C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037184: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x80037188: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003718C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80037190: bne         $t6, $at, L_8003733C
    if (ctx->r14 != ctx->r1) {
        // 0x80037194: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8003733C;
    }
    // 0x80037194: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80037198: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x8003719C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800371A0: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800371A4: bnel        $t7, $at, L_80037340
    if (ctx->r15 != ctx->r1) {
        // 0x800371A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80037340;
    }
    goto skip_0;
    // 0x800371A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800371AC: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800371B0: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800371B4: lw          $fp, 0x24($s7)
    ctx->r30 = MEM_W(ctx->r23, 0X24);
    // 0x800371B8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800371BC: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800371C0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800371C4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800371C8: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800371CC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800371D0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800371D4: jal         0x80037140
    // 0x800371D8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80037140(rdram, ctx);
        goto after_0;
    // 0x800371D8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x800371DC: lw          $s1, 0x50($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X50);
    // 0x800371E0: beq         $s1, $zero, L_80037258
    if (ctx->r17 == 0) {
        // 0x800371E4: nop
    
            goto L_80037258;
    }
    // 0x800371E4: nop

    // 0x800371E8: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_800371EC:
    // 0x800371EC: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
    // 0x800371F0: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x800371F4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800371F8: bne         $s4, $t7, L_80037250
    if (ctx->r20 != ctx->r15) {
        // 0x800371FC: addu        $s0, $s0, $t9
        ctx->r16 = ADD32(ctx->r16, ctx->r25);
            goto L_80037250;
    }
    // 0x800371FC: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80037200: jal         0x80036820
    // 0x80037204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80036820(rdram, ctx);
        goto after_1;
    // 0x80037204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80037208: beql        $s3, $zero, L_80037228
    if (ctx->r19 == 0) {
        // 0x8003720C: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80037228;
    }
    goto skip_1;
    // 0x8003720C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_1:
    // 0x80037210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80037214: jal         0x80036850
    // 0x80037218: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80036850(rdram, ctx);
        goto after_2;
    // 0x80037218: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8003721C: b           L_80037230
    // 0x80037220: nop

        goto L_80037230;
    // 0x80037220: nop

    // 0x80037224: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80037228:
    // 0x80037228: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8003722C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
L_80037230:
    // 0x80037230: beq         $s2, $zero, L_8003724C
    if (ctx->r18 == 0) {
        // 0x80037234: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8003724C;
    }
    // 0x80037234: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80037238: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8003723C: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x80037240: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80037244: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80037248: sw          $t6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r14;
L_8003724C:
    // 0x8003724C: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_80037250:
    // 0x80037250: bne         $s2, $zero, L_800371EC
    if (ctx->r18 != 0) {
        // 0x80037254: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800371EC;
    }
    // 0x80037254: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80037258:
    // 0x80037258: beq         $s3, $zero, L_8003733C
    if (ctx->r19 == 0) {
        // 0x8003725C: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_8003733C;
    }
    // 0x8003725C: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x80037260: addiu       $s4, $s7, 0x48
    ctx->r20 = ADD32(ctx->r23, 0X48);
    // 0x80037264: addiu       $s5, $s4, 0x8
    ctx->r21 = ADD32(ctx->r20, 0X8);
    // 0x80037268: addiu       $s6, $zero, -0x8
    ctx->r22 = ADD32(0, -0X8);
L_8003726C:
    // 0x8003726C: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80037270: lw          $t7, 0x24($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X24);
    // 0x80037274: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80037278: div         $zero, $t9, $fp
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r30)));
    // 0x8003727C: mflo        $v0
    ctx->r2 = lo;
    // 0x80037280: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80037284: bne         $fp, $zero, L_80037290
    if (ctx->r30 != 0) {
        // 0x80037288: nop
    
            goto L_80037290;
    }
    // 0x80037288: nop

    // 0x8003728C: break       7
    do_break(2147709580);
L_80037290:
    // 0x80037290: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037294: bne         $fp, $at, L_800372A8
    if (ctx->r30 != ctx->r1) {
        // 0x80037298: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800372A8;
    }
    // 0x80037298: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003729C: bne         $t9, $at, L_800372A8
    if (ctx->r25 != ctx->r1) {
        // 0x800372A0: nop
    
            goto L_800372A8;
    }
    // 0x800372A0: nop

    // 0x800372A4: break       6
    do_break(2147709604);
L_800372A8:
    // 0x800372A8: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800372AC: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x800372B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800372B4: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x800372B8: jal         0x80034160
    // 0x800372BC: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800372BC: nop

    after_3:
    // 0x800372C0: beq         $s4, $s6, L_8003732C
    if (ctx->r20 == ctx->r22) {
        // 0x800372C4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003732C;
    }
    // 0x800372C4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800372C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800372CC:
    // 0x800372CC: bnel        $a0, $zero, L_800372EC
    if (ctx->r4 != 0) {
        // 0x800372D0: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_800372EC;
    }
    goto skip_2;
    // 0x800372D0: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
    // 0x800372D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800372D8: jal         0x80036850
    // 0x800372DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80036850(rdram, ctx);
        goto after_4;
    // 0x800372DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800372E0: b           L_8003732C
    // 0x800372E4: nop

        goto L_8003732C;
    // 0x800372E4: nop

    // 0x800372E8: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_800372EC:
    // 0x800372EC: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800372F0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800372F4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800372F8: beq         $at, $zero, L_8003731C
    if (ctx->r1 == 0) {
        // 0x800372FC: subu        $t9, $v0, $v1
        ctx->r25 = SUB32(ctx->r2, ctx->r3);
            goto L_8003731C;
    }
    // 0x800372FC: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x80037300: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x80037304: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80037308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003730C: jal         0x80036850
    // 0x80037310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80036850(rdram, ctx);
        goto after_5;
    // 0x80037310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80037314: b           L_8003732C
    // 0x80037318: nop

        goto L_8003732C;
    // 0x80037318: nop

L_8003731C:
    // 0x8003731C: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
    // 0x80037320: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80037324: bnel        $s0, $zero, L_800372CC
    if (ctx->r16 != 0) {
        // 0x80037328: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800372CC;
    }
    goto skip_3;
    // 0x80037328: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_8003732C:
    // 0x8003732C: jal         0x80034160
    // 0x80037330: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x80037330: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x80037334: bne         $s2, $zero, L_8003726C
    if (ctx->r18 != 0) {
        // 0x80037338: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_8003726C;
    }
    // 0x80037338: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_8003733C:
    // 0x8003733C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037340:
    // 0x80037340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037344: jr          $ra
    // 0x80037348: nop

    return;
    // 0x80037348: nop

;}
RECOMP_FUNC void alMainBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800400D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800400D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800400DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800400E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800400E4: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800400E8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800400EC: addiu       $a1, $a1, 0x900
    ctx->r5 = ADD32(ctx->r5, 0X900);
    // 0x800400F0: addiu       $a2, $a2, 0x8D0
    ctx->r6 = ADD32(ctx->r6, 0X8D0);
    // 0x800400F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800400F8: jal         0x80048AC0
    // 0x800400FC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800400FC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x80040100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80040104: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80040108: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8004010C: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80040110: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80040114: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x80040118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004011C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040120: jr          $ra
    // 0x80040124: nop

    return;
    // 0x80040124: nop

;}
