#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80044540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044540: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044548: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004454C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80044550: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80044554: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80044558: beql        $t6, $zero, L_80044618
    if (ctx->r14 == 0) {
        // 0x8004455C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044618;
    }
    goto skip_0;
    // 0x8004455C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80044560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80044564: jal         0x80036A30
    // 0x80044568: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x80044568: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004456C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80044570: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80044574: beq         $v0, $zero, L_80044614
    if (ctx->r2 == 0) {
        // 0x80044578: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80044614;
    }
    // 0x80044578: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8004457C: lbu         $v1, 0x3B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3B);
    // 0x80044580: bgez        $v1, L_80044594
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044584: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80044594;
    }
    // 0x80044584: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80044588: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8004458C: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x80044590: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80044594:
    // 0x80044594: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80044598: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x8004459C: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x800445A0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800445A4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800445A8: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x800445AC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800445B0: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800445B4: lh          $t3, 0x1A($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1A);
    // 0x800445B8: sh          $t3, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r11;
    // 0x800445BC: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x800445C0: sb          $t4, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r12;
    // 0x800445C4: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x800445C8: sb          $v1, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r3;
    // 0x800445CC: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x800445D0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800445D4: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x800445D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800445DC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800445E0: jal         0x80036928
    // 0x800445E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80036928(rdram, ctx);
        goto after_1;
    // 0x800445E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800445E8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800445EC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800445F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800445F4: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x800445F8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800445FC: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x80044600: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x80044604: lw          $a0, 0xC($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC);
    // 0x80044608: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8004460C: jalr        $t9
    // 0x80044610: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80044610: nop

    after_2:
L_80044614:
    // 0x80044614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044618:
    // 0x80044618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004461C: jr          $ra
    // 0x80044620: nop

    return;
    // 0x80044620: nop

    // 0x80044624: nop

    // 0x80044628: nop

    // 0x8004462C: nop

;}
RECOMP_FUNC void func_8010324C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010324C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80103250: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80103254: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010325C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103260: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103264: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103268: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8010326C: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x80103270: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80103274: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103278: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8010327C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103280: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x80103284: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x80103288: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010328C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103290: ori         $t2, $t2, 0x4240
    ctx->r10 = ctx->r10 | 0X4240;
    // 0x80103294: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x80103298: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8010329C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801032A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801032A4: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x801032A8: lui         $t5, 0xFFFC
    ctx->r13 = S32(0XFFFC << 16);
    // 0x801032AC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801032B0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801032B4: ori         $t5, $t5, 0xFA7D
    ctx->r13 = ctx->r13 | 0XFA7D;
    // 0x801032B8: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x801032BC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801032C0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801032C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801032C8: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x801032CC: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x801032D0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801032D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801032D8: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x801032DC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801032E0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801032E4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801032E8: jal         0x80103954
    // 0x801032EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    func_80103954_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x801032EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x801032F0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x801032F4: addiu       $v1, $v1, 0x6200
    ctx->r3 = ADD32(ctx->r3, 0X6200);
    // 0x801032F8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801032FC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80103300: addiu       $a1, $a1, 0x6224
    ctx->r5 = ADD32(ctx->r5, 0X6224);
    // 0x80103304: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80103308: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8010330C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80103310: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x80103314: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80103318: beq         $a0, $zero, L_8010333C
    if (ctx->r4 == 0) {
        // 0x8010331C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8010333C;
    }
    // 0x8010331C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80103320: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80103324: beq         $v0, $at, L_8010336C
    if (ctx->r2 == ctx->r1) {
        // 0x80103328: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8010336C;
    }
    // 0x80103328: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010332C: beql        $v0, $at, L_80103390
    if (ctx->r2 == ctx->r1) {
        // 0x80103330: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_80103390;
    }
    goto skip_0;
    // 0x80103330: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x80103334: b           L_801033AC
    // 0x80103338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801033AC;
    // 0x80103338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010333C:
    // 0x8010333C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80103340: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80103344: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x80103348: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8010334C: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x80103350: bne         $at, $zero, L_801033A8
    if (ctx->r1 != 0) {
        // 0x80103354: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_801033A8;
    }
    // 0x80103354: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80103358: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8010335C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80103360: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80103364: b           L_801033A8
    // 0x80103368: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_801033A8;
    // 0x80103368: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8010336C:
    // 0x8010336C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80103370: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x80103374: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80103378: bnel        $t9, $zero, L_801033AC
    if (ctx->r25 != 0) {
        // 0x8010337C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801033AC;
    }
    goto skip_1;
    // 0x8010337C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80103380: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80103384: b           L_801033A8
    // 0x80103388: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_801033A8;
    // 0x80103388: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8010338C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_80103390:
    // 0x80103390: addiu       $t4, $t3, -0x8
    ctx->r12 = ADD32(ctx->r11, -0X8);
    // 0x80103394: bgez        $t4, L_801033A8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80103398: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_801033A8;
    }
    // 0x80103398: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x8010339C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x801033A0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801033A4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801033A8:
    // 0x801033A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801033AC:
    // 0x801033AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801033B0: jr          $ra
    // 0x801033B4: nop

    return;
    // 0x801033B4: nop

;}
RECOMP_FUNC void func_8000E224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E224: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000E228: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x8000E22C: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8000E230: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8000E234: lwc1        $f0, 0x34($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8000E238: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8000E23C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000E240: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8000E244: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8000E248: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8000E24C: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x8000E250: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000E254: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8000E258: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x8000E25C: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x8000E260: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8000E264: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x8000E268: ldc1        $f10, 0x1230($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1230);
    // 0x8000E26C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8000E270: sub.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d - ctx->f10.d;
    // 0x8000E274: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8000E278: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x8000E27C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000E280: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8000E284: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000E288: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000E28C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8000E290: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000E294: lhu         $t8, 0x4ED0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X4ED0);
    // 0x8000E298: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8000E29C: beq         $t9, $zero, L_8000E2AC
    if (ctx->r25 == 0) {
        // 0x8000E2A0: nop
    
            goto L_8000E2AC;
    }
    // 0x8000E2A0: nop

    // 0x8000E2A4: b           L_8000E2AC
    // 0x8000E2A8: addiu       $v1, $zero, 0xDC
    ctx->r3 = ADD32(0, 0XDC);
        goto L_8000E2AC;
    // 0x8000E2A8: addiu       $v1, $zero, 0xDC
    ctx->r3 = ADD32(0, 0XDC);
L_8000E2AC:
    // 0x8000E2AC: andi        $t0, $v1, 0xFF
    ctx->r8 = ctx->r3 & 0XFF;
    // 0x8000E2B0: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8000E2B4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8000E2B8: jr          $ra
    // 0x8000E2BC: nop

    return;
    // 0x8000E2BC: nop

;}
RECOMP_FUNC void func_8001C5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C5F4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001C5F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C5FC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001C600: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x8001C604: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8001C608: bne         $t6, $zero, L_8001C8B4
    if (ctx->r14 != 0) {
        // 0x8001C60C: andi        $t7, $v0, 0x8000
        ctx->r15 = ctx->r2 & 0X8000;
            goto L_8001C8B4;
    }
    // 0x8001C60C: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8001C610: bne         $t7, $zero, L_8001C8B4
    if (ctx->r15 != 0) {
        // 0x8001C614: lui         $t8, 0x8008
        ctx->r24 = S32(0X8008 << 16);
            goto L_8001C8B4;
    }
    // 0x8001C614: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8001C618: lhu         $t8, -0x44D4($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X44D4);
    // 0x8001C61C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001C620: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8001C624: bnel        $t9, $zero, L_8001C8B8
    if (ctx->r25 != 0) {
        // 0x8001C628: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001C8B8;
    }
    goto skip_0;
    // 0x8001C628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001C62C: lwc1        $f0, -0x45A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X45A4);
    // 0x8001C630: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001C634: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001C638: addiu       $v1, $v1, -0x3A8C
    ctx->r3 = ADD32(ctx->r3, -0X3A8C);
    // 0x8001C63C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8001C640: nop

    // 0x8001C644: bc1tl       L_8001C8B8
    if (c1cs) {
        // 0x8001C648: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001C8B8;
    }
    goto skip_1;
    // 0x8001C648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8001C64C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001C650: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x8001C654: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8001C658: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8001C65C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001C660: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001C664: addiu       $v0, $v0, -0x3A88
    ctx->r2 = ADD32(ctx->r2, -0X3A88);
    // 0x8001C668: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8001C66C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8001C670: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001C674: c.le.d      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.d <= ctx->f16.d;
    // 0x8001C678: nop

    // 0x8001C67C: bc1fl       L_8001C8B8
    if (!c1cs) {
        // 0x8001C680: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001C8B8;
    }
    goto skip_2;
    // 0x8001C680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8001C684: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x8001C688: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    // 0x8001C68C: addiu       $t1, $t0, 0x32
    ctx->r9 = ADD32(ctx->r8, 0X32);
    // 0x8001C690: jal         0x80022FD0
    // 0x8001C694: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    get_rand(rdram, ctx);
        goto after_0;
    // 0x8001C694: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    after_0:
    // 0x8001C698: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x8001C69C: lhu         $t2, -0x3A88($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X3A88);
    // 0x8001C6A0: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x8001C6A4: beq         $at, $zero, L_8001C8A8
    if (ctx->r1 == 0) {
        // 0x8001C6A8: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_8001C8A8;
    }
    // 0x8001C6A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C6AC: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8001C6B0: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C6B4: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001C6B8: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x8001C6BC: jal         0x8001D538
    // 0x8001C6C0: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_8001D538(rdram, ctx);
        goto after_1;
    // 0x8001C6C0: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8001C6C4: beq         $v0, $zero, L_8001C8A8
    if (ctx->r2 == 0) {
        // 0x8001C6C8: lwc1        $f12, 0x3C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8001C8A8;
    }
    // 0x8001C6C8: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001C6CC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8001C6D0: lw          $a2, -0x3AA0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3AA0);
    // 0x8001C6D4: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001C6D8: jal         0x8001D474
    // 0x8001C6DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8001D474(rdram, ctx);
        goto after_2;
    // 0x8001C6DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x8001C6E0: beq         $v0, $zero, L_8001C8A8
    if (ctx->r2 == 0) {
        // 0x8001C6E4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8001C8A8;
    }
    // 0x8001C6E4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8001C6E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C6EC: sh          $zero, -0x3A88($at)
    MEM_H(-0X3A88, ctx->r1) = 0;
    // 0x8001C6F0: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x8001C6F4: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x8001C6F8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001C6FC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8001C700: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8001C704: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001C708: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001C70C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8001C710: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8001C714: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001C718: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8001C71C: jal         0x80023210
    // 0x8001C720: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    func_80023210(rdram, ctx);
        goto after_3;
    // 0x8001C720: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    after_3:
    // 0x8001C724: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8001C728: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001C72C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001C730: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8001C734: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x8001C738: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x8001C73C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8001C740: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001C744: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001C748: jal         0x8001D640
    // 0x8001C74C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_8001D640(rdram, ctx);
        goto after_4;
    // 0x8001C74C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x8001C750: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8001C754: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C758: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001C75C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x8001C760: addiu       $v0, $v0, -0x3A6E
    ctx->r2 = ADD32(ctx->r2, -0X3A6E);
    // 0x8001C764: addiu       $t9, $zero, 0x205
    ctx->r25 = ADD32(0, 0X205);
    // 0x8001C768: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8001C76C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001C770: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8001C774: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001C778: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001C77C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8001C780: swc1        $f16, -0x3A64($at)
    MEM_W(-0X3A64, ctx->r1) = ctx->f16.u32l;
    // 0x8001C784: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x8001C788: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C78C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8001C790: nop

    // 0x8001C794: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001C798: swc1        $f18, -0x3A60($at)
    MEM_W(-0X3A60, ctx->r1) = ctx->f18.u32l;
    // 0x8001C79C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8001C7A0: lhu         $t3, -0x2F50($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2F50);
    // 0x8001C7A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C7A8: sh          $zero, -0x3A6A($at)
    MEM_H(-0X3A6A, ctx->r1) = 0;
    // 0x8001C7AC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8001C7B0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001C7B4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001C7B8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001C7BC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8001C7C0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8001C7C4: lw          $t5, -0x3648($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3648);
    // 0x8001C7C8: lw          $t1, -0x4538($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4538);
    // 0x8001C7CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C7D0: sh          $t0, -0x3A6C($at)
    MEM_H(-0X3A6C, ctx->r1) = ctx->r8;
    // 0x8001C7D4: lhu         $t6, 0xC($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0XC);
    // 0x8001C7D8: lhu         $t2, 0xC($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XC);
    // 0x8001C7DC: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001C7E0: beq         $at, $zero, L_8001C7FC
    if (ctx->r1 == 0) {
        // 0x8001C7E4: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_8001C7FC;
    }
    // 0x8001C7E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C7E8: sh          $zero, -0x3A68($at)
    MEM_H(-0X3A68, ctx->r1) = 0;
    // 0x8001C7EC: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8001C7F0: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8001C7F4: b           L_8001C810
    // 0x8001C7F8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
        goto L_8001C810;
    // 0x8001C7F8: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
L_8001C7FC:
    // 0x8001C7FC: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8001C800: lhu         $t9, -0x3A66($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X3A66);
    // 0x8001C804: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C808: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8001C80C: sh          $t0, -0x3A68($at)
    MEM_H(-0X3A68, ctx->r1) = ctx->r8;
L_8001C810:
    // 0x8001C810: jal         0x80003A1C
    // 0x8001C814: nop

    func_80003A1C(rdram, ctx);
        goto after_5;
    // 0x8001C814: nop

    after_5:
    // 0x8001C818: jal         0x80020888
    // 0x8001C81C: nop

    func_80020888(rdram, ctx);
        goto after_6;
    // 0x8001C81C: nop

    after_6:
    // 0x8001C820: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8001C824: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001C828: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001C82C: addiu       $v0, $v0, -0x3BCC
    ctx->r2 = ADD32(ctx->r2, -0X3BCC);
    // 0x8001C830: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8001C834: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001C838: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001C83C: ldc1        $f16, 0x1610($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1610);
    // 0x8001C840: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8001C844: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001C848: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8001C84C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001C850: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8001C854: lw          $a3, -0x3A60($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3A60);
    // 0x8001C858: lw          $a2, -0x4530($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4530);
    // 0x8001C85C: lw          $a1, -0x3A64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A64);
    // 0x8001C860: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001C864: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8001C868: jal         0x80019A98
    // 0x8001C86C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80019A98(rdram, ctx);
        goto after_7;
    // 0x8001C86C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x8001C870: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C874: sh          $v0, -0x3AA4($at)
    MEM_H(-0X3AA4, ctx->r1) = ctx->r2;
    // 0x8001C878: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C87C: sh          $zero, -0x3A74($at)
    MEM_H(-0X3A74, ctx->r1) = 0;
    // 0x8001C880: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C884: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001C888: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C88C: sh          $t1, -0x3A72($at)
    MEM_H(-0X3A72, ctx->r1) = ctx->r9;
    // 0x8001C890: jal         0x80022FD0
    // 0x8001C894: lw          $a0, -0x3670($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3670);
    get_rand(rdram, ctx);
        goto after_8;
    // 0x8001C894: lw          $a0, -0x3670($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3670);
    after_8:
    // 0x8001C898: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C89C: sh          $v0, -0x3A70($at)
    MEM_H(-0X3A70, ctx->r1) = ctx->r2;
    // 0x8001C8A0: jal         0x800267B8
    // 0x8001C8A4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    UpdateBGM(rdram, ctx);
        goto after_9;
    // 0x8001C8A4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_9:
L_8001C8A8:
    // 0x8001C8A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001C8AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001C8B0: swc1        $f6, -0x3A8C($at)
    MEM_W(-0X3A8C, ctx->r1) = ctx->f6.u32l;
L_8001C8B4:
    // 0x8001C8B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001C8B8:
    // 0x8001C8B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8001C8BC: jr          $ra
    // 0x8001C8C0: nop

    return;
    // 0x8001C8C0: nop

;}
RECOMP_FUNC void func_800236CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800236CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800236D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800236D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800236D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800236DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800236E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800236E4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800236E8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800236EC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800236F0: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x800236F4: jal         0x80023570
    // 0x800236F8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80023570(rdram, ctx);
        goto after_0;
    // 0x800236F8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x800236FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80023700: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x80023704: jal         0x80035200
    // 0x80023708: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80023708: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002370C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80023714: jr          $ra
    // 0x80023718: nop

    return;
    // 0x80023718: nop

;}
RECOMP_FUNC void func_80004040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80004048: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000404C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80004050: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004054: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80004058: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x8000405C: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80004060: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x80004064: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80004068: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000406C: bne         $t8, $zero, L_800041A0
    if (ctx->r24 != 0) {
        // 0x80004070: sh          $t7, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r15;
            goto L_800041A0;
    }
    // 0x80004070: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80004074: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80004078: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x8000407C: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80004080: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x80004084: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80004088: addiu       $t1, $zero, 0xE6
    ctx->r9 = ADD32(0, 0XE6);
    // 0x8000408C: bne         $t9, $zero, L_80004190
    if (ctx->r25 != 0) {
        // 0x80004090: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_80004190;
    }
    // 0x80004090: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80004094: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80004098: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x8000409C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800040A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800040A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800040A8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800040AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800040B0: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x800040B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800040B8: jal         0x8001D8B0
    // 0x800040BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x800040BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800040C0: jal         0x800202E4
    // 0x800040C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800202E4(rdram, ctx);
        goto after_1;
    // 0x800040C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800040C8: jal         0x800267B8
    // 0x800040CC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    UpdateBGM(rdram, ctx);
        goto after_2;
    // 0x800040CC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x800040D0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800040D4: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x800040D8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800040DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800040E0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800040E4: ori         $t5, $t4, 0x880
    ctx->r13 = ctx->r12 | 0X880;
    // 0x800040E8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800040EC: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x800040F0: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x800040F4: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x800040F8: sw          $t6, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r14;
    // 0x800040FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004100: sh          $t7, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = ctx->r15;
    // 0x80004104: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004108: sh          $t8, -0x4D0E($at)
    MEM_H(-0X4D0E, ctx->r1) = ctx->r24;
    // 0x8000410C: sh          $t9, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r25;
    // 0x80004110: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80004114: lhu         $t0, -0x45A0($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X45A0);
    // 0x80004118: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000411C: addiu       $v0, $v0, 0x5368
    ctx->r2 = ADD32(ctx->r2, 0X5368);
    // 0x80004120: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80004124: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80004128: lhu         $t1, -0x459E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X459E);
    // 0x8000412C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80004130: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80004134: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80004138: lhu         $t2, -0x459C($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X459C);
    // 0x8000413C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004140: addiu       $t3, $zero, 0x108
    ctx->r11 = ADD32(0, 0X108);
    // 0x80004144: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x80004148: swc1        $f0, -0x45C0($at)
    MEM_W(-0X45C0, ctx->r1) = ctx->f0.u32l;
    // 0x8000414C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004150: swc1        $f0, -0x45BC($at)
    MEM_W(-0X45BC, ctx->r1) = ctx->f0.u32l;
    // 0x80004154: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004158: swc1        $f0, -0x45B8($at)
    MEM_W(-0X45B8, ctx->r1) = ctx->f0.u32l;
    // 0x8000415C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004160: sw          $t3, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r11;
    // 0x80004164: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80004168: sh          $zero, -0x4542($at)
    MEM_H(-0X4542, ctx->r1) = 0;
    // 0x8000416C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80004170: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80004174: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80004178: sb          $t4, -0x2D4C($at)
    MEM_B(-0X2D4C, ctx->r1) = ctx->r12;
    // 0x8000417C: addiu       $a0, $a0, -0x2D44
    ctx->r4 = ADD32(ctx->r4, -0X2D44);
    // 0x80004180: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80004184: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80004188: b           L_800041A0
    // 0x8000418C: sw          $zero, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = 0;
        goto L_800041A0;
    // 0x8000418C: sw          $zero, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = 0;
L_80004190:
    // 0x80004190: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80004194: lhu         $t6, 0x60($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X60);
    // 0x80004198: andi        $t7, $t6, 0xFFFC
    ctx->r15 = ctx->r14 & 0XFFFC;
    // 0x8000419C: sh          $t7, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r15;
L_800041A0:
    // 0x800041A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800041A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800041A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800041AC: jr          $ra
    // 0x800041B0: nop

    return;
    // 0x800041B0: nop

;}
RECOMP_FUNC void func_800231B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800231B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800231B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800231B8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800231BC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800231C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800231C4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800231C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800231CC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800231D0: jal         0x80034F60
    // 0x800231D4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x800231D4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800231D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800231DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800231E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800231E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800231E8: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800231EC: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800231F0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800231F4: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800231F8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800231FC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80023200: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80023204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023208: jr          $ra
    // 0x8002320C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002320C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001D358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D360: jal         0x8001817C
    // 0x8001D364: nop

    func_8001817C(rdram, ctx);
        goto after_0;
    // 0x8001D364: nop

    after_0:
    // 0x8001D368: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001D36C: addiu       $t5, $t5, -0x3A6E
    ctx->r13 = ADD32(ctx->r13, -0X3A6E);
    // 0x8001D370: lhu         $t4, 0x0($t5)
    ctx->r12 = MEM_HU(ctx->r13, 0X0);
    // 0x8001D374: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x8001D378: beq         $t6, $zero, L_8001D464
    if (ctx->r14 == 0) {
        // 0x8001D37C: andi        $t7, $t4, 0x2
        ctx->r15 = ctx->r12 & 0X2;
            goto L_8001D464;
    }
    // 0x8001D37C: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x8001D380: bne         $t7, $zero, L_8001D438
    if (ctx->r15 != 0) {
        // 0x8001D384: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_8001D438;
    }
    // 0x8001D384: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001D388: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001D38C: lhu         $v0, -0x3A66($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A66);
    // 0x8001D390: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001D394: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8001D398: beq         $v0, $zero, L_8001D41C
    if (ctx->r2 == 0) {
        // 0x8001D39C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8001D41C;
    }
    // 0x8001D39C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8001D3A0: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001D3A4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001D3A8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001D3AC: addiu       $a1, $a1, -0x3A68
    ctx->r5 = ADD32(ctx->r5, -0X3A68);
    // 0x8001D3B0: addiu       $a3, $a3, -0x2F50
    ctx->r7 = ADD32(ctx->r7, -0X2F50);
    // 0x8001D3B4: addiu       $t0, $t0, -0x3668
    ctx->r8 = ADD32(ctx->r8, -0X3668);
    // 0x8001D3B8: lhu         $v1, -0x3A68($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X3A68);
    // 0x8001D3BC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8001D3C0: addiu       $t1, $zero, 0x128
    ctx->r9 = ADD32(0, 0X128);
    // 0x8001D3C4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
L_8001D3C8:
    // 0x8001D3C8: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
    // 0x8001D3CC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001D3D0: bne         $at, $zero, L_8001D3E0
    if (ctx->r1 != 0) {
        // 0x8001D3D4: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_8001D3E0;
    }
    // 0x8001D3D4: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8001D3D8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8001D3DC: andi        $v1, $zero, 0xFFFF
    ctx->r3 = 0 & 0XFFFF;
L_8001D3E0:
    // 0x8001D3E0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8001D3E4: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x8001D3E8: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x8001D3EC: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D3F0: mflo        $t7
    ctx->r15 = lo;
    // 0x8001D3F4: addu        $a0, $t0, $t7
    ctx->r4 = ADD32(ctx->r8, ctx->r15);
    // 0x8001D3F8: lhu         $t8, 0xA($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XA);
    // 0x8001D3FC: beql        $t8, $zero, L_8001D414
    if (ctx->r24 == 0) {
        // 0x8001D400: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001D414;
    }
    goto skip_0;
    // 0x8001D400: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    skip_0:
    // 0x8001D404: lh          $t9, 0x74($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X74);
    // 0x8001D408: bne         $t2, $t9, L_8001D41C
    if (ctx->r10 != ctx->r25) {
        // 0x8001D40C: nop
    
            goto L_8001D41C;
    }
    // 0x8001D40C: nop

    // 0x8001D410: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001D414:
    // 0x8001D414: bnel        $a2, $zero, L_8001D3C8
    if (ctx->r6 != 0) {
        // 0x8001D418: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8001D3C8;
    }
    goto skip_1;
    // 0x8001D418: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    skip_1:
L_8001D41C:
    // 0x8001D41C: bne         $a2, $zero, L_8001D42C
    if (ctx->r6 != 0) {
        // 0x8001D420: addiu       $t7, $zero, 0x14
        ctx->r15 = ADD32(0, 0X14);
            goto L_8001D42C;
    }
    // 0x8001D420: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8001D424: ori         $t6, $t4, 0x400
    ctx->r14 = ctx->r12 | 0X400;
    // 0x8001D428: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_8001D42C:
    // 0x8001D42C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001D430: b           L_8001D43C
    // 0x8001D434: sh          $t7, -0x3A6C($at)
    MEM_H(-0X3A6C, ctx->r1) = ctx->r15;
        goto L_8001D43C;
    // 0x8001D434: sh          $t7, -0x3A6C($at)
    MEM_H(-0X3A6C, ctx->r1) = ctx->r15;
L_8001D438:
    // 0x8001D438: sh          $zero, -0x3A6C($at)
    MEM_H(-0X3A6C, ctx->r1) = 0;
L_8001D43C:
    // 0x8001D43C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001D440: jal         0x80019CA4
    // 0x8001D444: lhu         $a0, -0x3AA2($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3AA2);
    func_80019CA4(rdram, ctx);
        goto after_1;
    // 0x8001D444: lhu         $a0, -0x3AA2($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3AA2);
    after_1:
    // 0x8001D448: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8001D44C: addiu       $t5, $t5, -0x3A6E
    ctx->r13 = ADD32(ctx->r13, -0X3A6E);
    // 0x8001D450: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8001D454: xori        $t6, $t8, 0x2
    ctx->r14 = ctx->r24 ^ 0X2;
    // 0x8001D458: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
    // 0x8001D45C: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8001D460: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
L_8001D464:
    // 0x8001D464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D46C: jr          $ra
    // 0x8001D470: nop

    return;
    // 0x8001D470: nop

;}
RECOMP_FUNC void func_800252D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800252D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800252DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800252E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800252E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800252E8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800252EC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800252F0: lw          $t6, 0x38F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X38F0);
    // 0x800252F4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800252F8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800252FC: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80025300: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80025304: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80025308: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002530C: andi        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 & 0X1;
    // 0x80025310: beq         $t9, $zero, L_8002531C
    if (ctx->r25 == 0) {
        // 0x80025314: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8002531C;
    }
    // 0x80025314: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80025318: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8002531C:
    // 0x8002531C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80025320: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80025324: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80025328: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002532C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80025330: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80025334: addiu       $t2, $t2, -0x688
    ctx->r10 = ADD32(ctx->r10, -0X688);
    // 0x80025338: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002533C: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80025340: lw          $a1, 0x190($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X190);
    // 0x80025344: jal         0x80024690
    // 0x80025348: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80024690(rdram, ctx);
        goto after_0;
    // 0x80025348: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002534C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80025350: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80025354: sw          $t3, 0x194($v0)
    MEM_W(0X194, ctx->r2) = ctx->r11;
    // 0x80025358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002535C: jr          $ra
    // 0x80025360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80025360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001D474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D474: beq         $a2, $zero, L_8001D52C
    if (ctx->r6 == 0) {
        // 0x8001D478: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001D52C;
    }
    // 0x8001D478: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001D47C: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x8001D480: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8001D484: beq         $v0, $zero, L_8001D520
    if (ctx->r2 == 0) {
        // 0x8001D488: nop
    
            goto L_8001D520;
    }
    // 0x8001D488: nop

L_8001D48C:
    // 0x8001D48C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8001D490: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001D494: nop

    // 0x8001D498: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D49C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8001D4A0: nop

    // 0x8001D4A4: bc1fl       L_8001D518
    if (!c1cs) {
        // 0x8001D4A8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001D518;
    }
    goto skip_0;
    // 0x8001D4A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x8001D4AC: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x8001D4B0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001D4B4: nop

    // 0x8001D4B8: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001D4BC: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x8001D4C0: nop

    // 0x8001D4C4: bc1fl       L_8001D518
    if (!c1cs) {
        // 0x8001D4C8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001D518;
    }
    goto skip_1;
    // 0x8001D4C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_1:
    // 0x8001D4CC: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x8001D4D0: sub.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8001D4D4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8001D4D8: nop

    // 0x8001D4DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001D4E0: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8001D4E4: nop

    // 0x8001D4E8: bc1fl       L_8001D518
    if (!c1cs) {
        // 0x8001D4EC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001D518;
    }
    goto skip_2;
    // 0x8001D4EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_2:
    // 0x8001D4F0: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x8001D4F4: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8001D4F8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001D4FC: nop

    // 0x8001D500: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001D504: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8001D508: nop

    // 0x8001D50C: bc1t        L_8001D520
    if (c1cs) {
        // 0x8001D510: nop
    
            goto L_8001D520;
    }
    // 0x8001D510: nop

    // 0x8001D514: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001D518:
    // 0x8001D518: bne         $v0, $zero, L_8001D48C
    if (ctx->r2 != 0) {
        // 0x8001D51C: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_8001D48C;
    }
    // 0x8001D51C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_8001D520:
    // 0x8001D520: bnel        $v0, $zero, L_8001D530
    if (ctx->r2 != 0) {
        // 0x8001D524: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8001D530;
    }
    goto skip_3;
    // 0x8001D524: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_3:
    // 0x8001D528: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001D52C:
    // 0x8001D52C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001D530:
    // 0x8001D530: jr          $ra
    // 0x8001D534: nop

    return;
    // 0x8001D534: nop

;}
RECOMP_FUNC void alFilterNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048AC0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80048AC4: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80048AC8: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80048ACC: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80048AD0: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80048AD4: jr          $ra
    // 0x80048AD8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x80048AD8: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_80018638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001863C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80018644: jal         0x800186F8
    // 0x80018648: nop

    func_800186F8(rdram, ctx);
        goto after_0;
    // 0x80018648: nop

    after_0:
    // 0x8001864C: jal         0x80018B14
    // 0x80018650: nop

    func_80018B14(rdram, ctx);
        goto after_1;
    // 0x80018650: nop

    after_1:
    // 0x80018654: jal         0x800193B4
    // 0x80018658: nop

    func_800193B4(rdram, ctx);
        goto after_2;
    // 0x80018658: nop

    after_2:
    // 0x8001865C: jal         0x80019CCC
    // 0x80018660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80019CCC(rdram, ctx);
        goto after_3;
    // 0x80018660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80018664: jal         0x8001A398
    // 0x80018668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8001A398(rdram, ctx);
        goto after_4;
    // 0x80018668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8001866C: jal         0x80018F60
    // 0x80018670: nop

    func_80018F60(rdram, ctx);
        goto after_5;
    // 0x80018670: nop

    after_5:
    // 0x80018674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001867C: jr          $ra
    // 0x80018680: nop

    return;
    // 0x80018680: nop

;}
RECOMP_FUNC void calc_arctan_in_radians(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002302C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80023030: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80023034: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80023038: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002303C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80023040: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80023044: bc1f        L_80023058
    if (!c1cs) {
        // 0x80023048: addiu       $t0, $zero, 0x15
        ctx->r8 = ADD32(0, 0X15);
            goto L_80023058;
    }
    // 0x80023048: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x8002304C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023050: b           L_80023080
    // 0x80023054: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
        goto L_80023080;
    // 0x80023054: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
L_80023058:
    // 0x80023058: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8002305C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80023060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80023064: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80023068: nop

    // 0x8002306C: bc1f        L_80023080
    if (!c1cs) {
        // 0x80023070: nop
    
            goto L_80023080;
    }
    // 0x80023070: nop

    // 0x80023074: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80023078: b           L_80023080
    // 0x8002307C: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
        goto L_80023080;
    // 0x8002307C: div.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
L_80023080:
    // 0x80023080: addiu       $t2, $zero, 0x13
    ctx->r10 = ADD32(0, 0X13);
L_80023084:
    // 0x80023084: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023088: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    // 0x8002308C: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x80023090: addiu       $a3, $v1, -0x2
    ctx->r7 = ADD32(ctx->r3, -0X2);
    // 0x80023094: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80023098: addiu       $t1, $v1, -0x3
    ctx->r9 = ADD32(ctx->r3, -0X3);
    // 0x8002309C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800230A0: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x800230A4: mflo        $t6
    ctx->r14 = lo;
    // 0x800230A8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800230AC: nop

    // 0x800230B0: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800230B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800230B8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800230BC: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800230C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800230C4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800230C8: nop

    // 0x800230CC: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800230D0: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800230D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800230D8: mflo        $t8
    ctx->r24 = lo;
    // 0x800230DC: div.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800230E0: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800230E4: multu       $t1, $t1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800230E8: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    // 0x800230EC: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800230F0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800230F4: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800230F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800230FC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80023100: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80023104: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80023108: div.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002310C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80023110: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x80023114: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80023118: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8002311C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80023120: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80023124: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80023128: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002312C: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80023130: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80023134: addiu       $t2, $t2, -0x8
    ctx->r10 = ADD32(ctx->r10, -0X8);
    // 0x80023138: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8002313C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80023140: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80023144: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80023148: bne         $v1, $zero, L_80023084
    if (ctx->r3 != 0) {
        // 0x8002314C: div.s       $f2, $f8, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
            goto L_80023084;
    }
    // 0x8002314C: div.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80023150: blez        $v0, L_80023178
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80023154: nop
    
            goto L_80023178;
    }
    // 0x80023154: nop

    // 0x80023158: add.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8002315C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80023160: ldc1        $f16, 0x16D0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X16D0);
    // 0x80023164: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80023168: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8002316C: sub.d       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f16.d - ctx->f10.d;
    // 0x80023170: jr          $ra
    // 0x80023174: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    return;
    // 0x80023174: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80023178:
    // 0x80023178: bgezl       $v0, L_800231A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002317C: add.s       $f8, $f14, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
            goto L_800231A4;
    }
    goto skip_0;
    // 0x8002317C: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    skip_0:
    // 0x80023180: add.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80023184: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80023188: ldc1        $f18, 0x16D8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X16D8);
    // 0x8002318C: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80023190: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x80023194: sub.d       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f18.d - ctx->f16.d;
    // 0x80023198: jr          $ra
    // 0x8002319C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x8002319C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800231A0: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
L_800231A4:
    // 0x800231A4: div.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800231A8: jr          $ra
    // 0x800231AC: nop

    return;
    // 0x800231AC: nop

;}
RECOMP_FUNC void func_8002513C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002513C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025140: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80025144: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80025148: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002514C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80025150: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80025154: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80025158: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8002515C: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80025160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80025164: addiu       $a2, $a2, -0xDC0
    ctx->r6 = ADD32(ctx->r6, -0XDC0);
    // 0x80025168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002516C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80025170: jal         0x80036660
    // 0x80025174: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80025174: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80025178: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8002517C: addiu       $s0, $s0, -0x688
    ctx->r16 = ADD32(ctx->r16, -0X688);
    // 0x80025180: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80025184: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80025188: sw          $v0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->r2;
    // 0x8002518C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80025190: addiu       $a2, $a2, -0xDC0
    ctx->r6 = ADD32(ctx->r6, -0XDC0);
    // 0x80025194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80025198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002519C: jal         0x80036660
    // 0x800251A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800251A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800251A4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x800251A8: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x800251AC: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800251B0: addiu       $t9, $t9, -0xDC0
    ctx->r25 = ADD32(ctx->r25, -0XDC0);
    // 0x800251B4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800251B8: sw          $v0, 0x32C($s0)
    MEM_W(0X32C, ctx->r16) = ctx->r2;
    // 0x800251BC: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x800251C0: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x800251C4: sb          $t8, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r24;
    // 0x800251C8: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800251CC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800251D0: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800251D4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800251D8: sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
    // 0x800251DC: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    // 0x800251E0: jal         0x80038190
    // 0x800251E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alCSPNew(rdram, ctx);
        goto after_2;
    // 0x800251E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800251E8: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x800251EC: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x800251F0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800251F4: addiu       $t1, $t1, -0xDC0
    ctx->r9 = ADD32(ctx->r9, -0XDC0);
    // 0x800251F8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800251FC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80025200: sw          $v1, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->r3;
    // 0x80025204: sw          $v1, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r3;
    // 0x80025208: sb          $t0, 0x1A4($s0)
    MEM_B(0X1A4, ctx->r16) = ctx->r8;
    // 0x8002520C: sw          $t1, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->r9;
    // 0x80025210: sw          $zero, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = 0;
    // 0x80025214: sw          $zero, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = 0;
    // 0x80025218: sw          $zero, 0x1B4($s0)
    MEM_W(0X1B4, ctx->r16) = 0;
    // 0x8002521C: sb          $zero, 0x1A5($s0)
    MEM_B(0X1A5, ctx->r16) = 0;
    // 0x80025220: addiu       $a1, $a1, -0x4EC
    ctx->r5 = ADD32(ctx->r5, -0X4EC);
    // 0x80025224: jal         0x80038190
    // 0x80025228: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    alCSPNew(rdram, ctx);
        goto after_3;
    // 0x80025228: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    after_3:
    // 0x8002522C: jal         0x80025040
    // 0x80025230: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80025040(rdram, ctx);
        goto after_4;
    // 0x80025230: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x80025234: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80025238: lw          $a0, 0x38F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38F0);
    // 0x8002523C: jal         0x80038508
    // 0x80025240: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    alSeqFileNew(rdram, ctx);
        goto after_5;
    // 0x80025240: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80025244: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80025248: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002524C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80025250: addiu       $a2, $a2, -0xDC0
    ctx->r6 = ADD32(ctx->r6, -0XDC0);
    // 0x80025254: subu        $s0, $t2, $t3
    ctx->r16 = SUB32(ctx->r10, ctx->r11);
    // 0x80025258: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002525C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80025260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80025264: jal         0x80036660
    // 0x80025268: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x80025268: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x8002526C: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80025270: addiu       $v1, $v1, 0x38E8
    ctx->r3 = ADD32(ctx->r3, 0X38E8);
    // 0x80025274: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80025278: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8002527C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80025280: jal         0x80024690
    // 0x80025284: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80024690(rdram, ctx);
        goto after_7;
    // 0x80025284: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80025288: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8002528C: lw          $a0, 0x38E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38E8);
    // 0x80025290: jal         0x80038404
    // 0x80025294: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    alBnkfNew(rdram, ctx);
        goto after_8;
    // 0x80025294: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80025298: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x8002529C: lw          $t4, 0x38E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X38E8);
    // 0x800252A0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800252A4: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    // 0x800252A8: lw          $s0, 0x4($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X4);
    // 0x800252AC: jal         0x80038550
    // 0x800252B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSeqpSetBank(rdram, ctx);
        goto after_9;
    // 0x800252B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800252B4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800252B8: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    // 0x800252BC: jal         0x80038550
    // 0x800252C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    alSeqpSetBank(rdram, ctx);
        goto after_10;
    // 0x800252C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800252C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800252C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800252CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800252D0: jr          $ra
    // 0x800252D4: nop

    return;
    // 0x800252D4: nop

;}
RECOMP_FUNC void func_8001E1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E1F0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001E1F4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001E1F8: addiu       $v1, $v1, -0x39AC
    ctx->r3 = ADD32(ctx->r3, -0X39AC);
    // 0x8001E1FC: addiu       $v0, $v0, -0x39B4
    ctx->r2 = ADD32(ctx->r2, -0X39B4);
    // 0x8001E200: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E204: sw          $zero, -0x39C8($at)
    MEM_W(-0X39C8, ctx->r1) = 0;
    // 0x8001E208: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E20C: sw          $zero, -0x39C4($at)
    MEM_W(-0X39C4, ctx->r1) = 0;
    // 0x8001E210: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E214: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001E218: sw          $t6, -0x39C0($at)
    MEM_W(-0X39C0, ctx->r1) = ctx->r14;
    // 0x8001E21C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001E220: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E224: sw          $zero, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = 0;
    // 0x8001E228: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8001E22C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E230: sw          $zero, -0x39B0($at)
    MEM_W(-0X39B0, ctx->r1) = 0;
    // 0x8001E234: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E238: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x8001E23C: sw          $t9, -0x39A8($at)
    MEM_W(-0X39A8, ctx->r1) = ctx->r25;
    // 0x8001E240: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E244: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x8001E248: sw          $t0, -0x39A4($at)
    MEM_W(-0X39A4, ctx->r1) = ctx->r8;
    // 0x8001E24C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001E250: sh          $zero, -0x39D0($at)
    MEM_H(-0X39D0, ctx->r1) = 0;
    // 0x8001E254: jr          $ra
    // 0x8001E258: nop

    return;
    // 0x8001E258: nop

;}
RECOMP_FUNC void func_80049BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049BF8: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x80049BFC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80049C00: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x80049C04: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80049C08: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80049C0C: sll         $t6, $v1, 24
    ctx->r14 = S32(ctx->r3 << 24);
    // 0x80049C10: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80049C14: or          $v1, $t6, $t9
    ctx->r3 = ctx->r14 | ctx->r25;
    // 0x80049C18: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80049C1C: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80049C20: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80049C24: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80049C28: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80049C2C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80049C30: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80049C34: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x80049C38: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80049C3C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80049C40: jr          $ra
    // 0x80049C44: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
    return;
    // 0x80049C44: or          $v0, $v1, $t6
    ctx->r2 = ctx->r3 | ctx->r14;
;}
RECOMP_FUNC void func_80000FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000FEC: lui         $a0, 0x7
    ctx->r4 = S32(0X7 << 16);
    // 0x80000FF0: addiu       $a0, $a0, 0x3A90
    ctx->r4 = ADD32(ctx->r4, 0X3A90);
    // 0x80000FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000FF8: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x80000FFC: addiu       $t6, $t6, 0x7560
    ctx->r14 = ADD32(ctx->r14, 0X7560);
    // 0x80001000: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80001004: addiu       $a1, $a1, 0x6850
    ctx->r5 = ADD32(ctx->r5, 0X6850);
    // 0x80001008: jal         0x80024260
    // 0x8000100C: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x8000100C: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x80001010: lui         $a0, 0xD5
    ctx->r4 = S32(0XD5 << 16);
    // 0x80001014: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80001018: lui         $t8, 0xD7
    ctx->r24 = S32(0XD7 << 16);
    // 0x8000101C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80001020: addiu       $t7, $t7, 0x6850
    ctx->r15 = ADD32(ctx->r15, 0X6850);
    // 0x80001024: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001028: addiu       $t8, $t8, 0x7380
    ctx->r24 = ADD32(ctx->r24, 0X7380);
    // 0x8000102C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80001030: sw          $t7, -0x4CB0($at)
    MEM_W(-0X4CB0, ctx->r1) = ctx->r15;
    // 0x80001034: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80001038: jal         0x80024260
    // 0x8000103C: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    dma_write(rdram, ctx);
        goto after_1;
    // 0x8000103C: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    after_1:
    // 0x80001040: lui         $a0, 0xD7
    ctx->r4 = S32(0XD7 << 16);
    // 0x80001044: lui         $t9, 0xD9
    ctx->r25 = S32(0XD9 << 16);
    // 0x80001048: addiu       $a0, $a0, 0x7380
    ctx->r4 = ADD32(ctx->r4, 0X7380);
    // 0x8000104C: addiu       $t9, $t9, -0x7B10
    ctx->r25 = ADD32(ctx->r25, -0X7B10);
    // 0x80001050: lui         $a1, 0x803A
    ctx->r5 = S32(0X803A << 16);
    // 0x80001054: addiu       $a1, $a1, -0x6550
    ctx->r5 = ADD32(ctx->r5, -0X6550);
    // 0x80001058: jal         0x80024260
    // 0x8000105C: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    dma_write(rdram, ctx);
        goto after_2;
    // 0x8000105C: subu        $a2, $t9, $a0
    ctx->r6 = SUB32(ctx->r25, ctx->r4);
    after_2:
    // 0x80001060: lui         $a0, 0x8030
    ctx->r4 = S32(0X8030 << 16);
    // 0x80001064: addiu       $a0, $a0, 0x1000
    ctx->r4 = ADD32(ctx->r4, 0X1000);
    // 0x80001068: lui         $t1, 0x803B
    ctx->r9 = S32(0X803B << 16);
    // 0x8000106C: addiu       $at, $a0, 0x7FFF
    ctx->r1 = ADD32(ctx->r4, 0X7FFF);
    // 0x80001070: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80001074: addiu       $t1, $t1, 0x5000
    ctx->r9 = ADD32(ctx->r9, 0X5000);
    // 0x80001078: sh          $t0, 0x5149($at)
    MEM_H(0X5149, ctx->r1) = ctx->r8;
    // 0x8000107C: jal         0x8000111C
    // 0x80001080: sw          $t1, 0x514D($at)
    MEM_W(0X514D, ctx->r1) = ctx->r9;
    func_8000111C(rdram, ctx);
        goto after_3;
    // 0x80001080: sw          $t1, 0x514D($at)
    MEM_W(0X514D, ctx->r1) = ctx->r9;
    after_3:
    // 0x80001084: lui         $v0, 0x8031
    ctx->r2 = S32(0X8031 << 16);
    // 0x80001088: addiu       $v0, $v0, -0x7000
    ctx->r2 = ADD32(ctx->r2, -0X7000);
    // 0x8000108C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80001090: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80001094: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80001098: sh          $t2, 0x2298($at)
    MEM_H(0X2298, ctx->r1) = ctx->r10;
    // 0x8000109C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800010A0: lui         $t3, 0x803E
    ctx->r11 = S32(0X803E << 16);
    // 0x800010A4: addiu       $t3, $t3, -0x5800
    ctx->r11 = ADD32(ctx->r11, -0X5800);
    // 0x800010A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800010AC: lui         $a0, 0x8031
    ctx->r4 = S32(0X8031 << 16);
    // 0x800010B0: sw          $t3, 0x229C($at)
    MEM_W(0X229C, ctx->r1) = ctx->r11;
    // 0x800010B4: jal         0x8000111C
    // 0x800010B8: addiu       $a0, $a0, -0x1EB0
    ctx->r4 = ADD32(ctx->r4, -0X1EB0);
    func_8000111C(rdram, ctx);
        goto after_4;
    // 0x800010B8: addiu       $a0, $a0, -0x1EB0
    ctx->r4 = ADD32(ctx->r4, -0X1EB0);
    after_4:
    // 0x800010BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800010C0: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x800010C4: lui         $v1, 0x803B
    ctx->r3 = S32(0X803B << 16);
    // 0x800010C8: lui         $v0, 0x803E
    ctx->r2 = S32(0X803E << 16);
    // 0x800010CC: sw          $zero, -0x4D0C($at)
    MEM_W(-0X4D0C, ctx->r1) = 0;
    // 0x800010D0: ori         $a0, $a0, 0x2C00
    ctx->r4 = ctx->r4 | 0X2C00;
    // 0x800010D4: addiu       $v1, $v1, 0x5000
    ctx->r3 = ADD32(ctx->r3, 0X5000);
    // 0x800010D8: addiu       $v0, $v0, -0x5800
    ctx->r2 = ADD32(ctx->r2, -0X5800);
L_800010DC:
    // 0x800010DC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800010E0: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800010E4: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x800010E8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800010EC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800010F0: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800010F4: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x800010F8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800010FC: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x80001100: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80001104: bne         $a0, $zero, L_800010DC
    if (ctx->r4 != 0) {
        // 0x80001108: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800010DC;
    }
    // 0x80001108: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001114: jr          $ra
    // 0x80001118: nop

    return;
    // 0x80001118: nop

;}
RECOMP_FUNC void func_800440E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800440E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800440E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800440E8: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x800440EC: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800440F0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800440F4: beql        $a2, $zero, L_80044184
    if (ctx->r6 == 0) {
        // 0x800440F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044184;
    }
    goto skip_0;
    // 0x800440F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800440FC: lw          $t6, 0xD8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XD8);
    // 0x80044100: beql        $t6, $zero, L_8004416C
    if (ctx->r14 == 0) {
        // 0x80044104: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_8004416C;
    }
    goto skip_1;
    // 0x80044104: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    skip_1:
    // 0x80044108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004410C: jal         0x80036A30
    // 0x80044110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x80044110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80044114: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044118: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8004411C: beq         $v0, $zero, L_80044180
    if (ctx->r2 == 0) {
        // 0x80044120: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80044180;
    }
    // 0x80044120: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80044124: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x80044128: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x8004412C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80044130: lw          $t9, 0xD8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XD8);
    // 0x80044134: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80044138: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8004413C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80044140: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x80044144: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80044148: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x8004414C: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80044150: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80044154: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80044158: jalr        $t9
    // 0x8004415C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8004415C: nop

    after_1:
    // 0x80044160: b           L_8004417C
    // 0x80044164: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_8004417C;
    // 0x80044164: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044168: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8004416C:
    // 0x8004416C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80044170: jal         0x80036980
    // 0x80044174: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80036980(rdram, ctx);
        goto after_2;
    // 0x80044174: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80044178: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_8004417C:
    // 0x8004417C: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_80044180:
    // 0x80044180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044184:
    // 0x80044184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044188: jr          $ra
    // 0x8004418C: nop

    return;
    // 0x8004418C: nop

;}
RECOMP_FUNC void func_80100C98_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100C98: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x80100C9C: lw          $t6, 0x6FE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FE8);
    // 0x80100CA0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80100CA4: addiu       $v0, $v0, 0x7038
    ctx->r2 = ADD32(ctx->r2, 0X7038);
    // 0x80100CA8: sll         $t7, $t6, 0
    ctx->r15 = S32(ctx->r14 << 0);
    // 0x80100CAC: bltz        $t7, L_80100CBC
    if (SIGNED(ctx->r15) < 0) {
        // 0x80100CB0: lui         $a0, 0x8000
        ctx->r4 = S32(0X8000 << 16);
            goto L_80100CBC;
    }
    // 0x80100CB0: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80100CB4: jr          $ra
    // 0x80100CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80100CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100CBC:
    // 0x80100CBC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80100CC0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80100CC4: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100CC8: and         $t9, $t8, $a0
    ctx->r25 = ctx->r24 & ctx->r4;
    // 0x80100CCC: bne         $t9, $zero, L_80100CDC
    if (ctx->r25 != 0) {
        // 0x80100CD0: addiu       $a1, $zero, 0x96
        ctx->r5 = ADD32(0, 0X96);
            goto L_80100CDC;
    }
    // 0x80100CD0: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80100CD4: jr          $ra
    // 0x80100CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80100CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80100CDC:
    // 0x80100CDC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80100CE0: and         $t1, $t0, $a0
    ctx->r9 = ctx->r8 & ctx->r4;
    // 0x80100CE4: bnel        $t1, $zero, L_80100D00
    if (ctx->r9 != 0) {
        // 0x80100CE8: lw          $t3, 0x50($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X50);
            goto L_80100D00;
    }
    goto skip_0;
    // 0x80100CE8: lw          $t3, 0x50($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X50);
    skip_0:
    // 0x80100CEC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80100CF0: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80100CF4: jr          $ra
    // 0x80100CF8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x80100CF8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80100CFC: lw          $t3, 0x50($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X50);
L_80100D00:
    // 0x80100D00: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100D04: and         $t4, $t3, $a0
    ctx->r12 = ctx->r11 & ctx->r4;
    // 0x80100D08: bnel        $t4, $zero, L_80100D24
    if (ctx->r12 != 0) {
        // 0x80100D0C: lw          $t7, 0x50($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X50);
            goto L_80100D24;
    }
    goto skip_1;
    // 0x80100D0C: lw          $t7, 0x50($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X50);
    skip_1:
    // 0x80100D10: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80100D14: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80100D18: jr          $ra
    // 0x80100D1C: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    return;
    // 0x80100D1C: sra         $v0, $t5, 16
    ctx->r2 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80100D20: lw          $t7, 0x50($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X50);
L_80100D24:
    // 0x80100D24: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100D28: and         $t8, $t7, $a0
    ctx->r24 = ctx->r15 & ctx->r4;
    // 0x80100D2C: bnel        $t8, $zero, L_80100D48
    if (ctx->r24 != 0) {
        // 0x80100D30: lw          $t1, 0x50($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X50);
            goto L_80100D48;
    }
    goto skip_2;
    // 0x80100D30: lw          $t1, 0x50($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X50);
    skip_2:
    // 0x80100D34: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80100D38: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80100D3C: jr          $ra
    // 0x80100D40: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    return;
    // 0x80100D40: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80100D44: lw          $t1, 0x50($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X50);
L_80100D48:
    // 0x80100D48: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100D4C: and         $t2, $t1, $a0
    ctx->r10 = ctx->r9 & ctx->r4;
    // 0x80100D50: bnel        $t2, $zero, L_80100D6C
    if (ctx->r10 != 0) {
        // 0x80100D54: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80100D6C;
    }
    goto skip_3;
    // 0x80100D54: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x80100D58: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80100D5C: sll         $t3, $v0, 16
    ctx->r11 = S32(ctx->r2 << 16);
    // 0x80100D60: jr          $ra
    // 0x80100D64: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    return;
    // 0x80100D64: sra         $v0, $t3, 16
    ctx->r2 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80100D68: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80100D6C:
    // 0x80100D6C: bne         $v1, $a1, L_80100CDC
    if (ctx->r3 != ctx->r5) {
        // 0x80100D70: addiu       $v0, $v0, 0x50
        ctx->r2 = ADD32(ctx->r2, 0X50);
            goto L_80100CDC;
    }
    // 0x80100D70: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // 0x80100D74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80100D78: jr          $ra
    // 0x80100D7C: nop

    return;
    // 0x80100D7C: nop

;}
RECOMP_FUNC void func_800045F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800045F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800045F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800045F8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800045FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80004600: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80004604: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80004608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000460C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80004610: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x80004614: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80004618: lhu         $v0, 0x120($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X120);
    // 0x8000461C: beq         $v0, $zero, L_8000464C
    if (ctx->r2 == 0) {
        // 0x80004620: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8000464C;
    }
    // 0x80004620: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80004624: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80004628: bne         $t7, $zero, L_800046F4
    if (ctx->r15 != 0) {
        // 0x8000462C: sh          $t6, 0x120($s0)
        MEM_H(0X120, ctx->r16) = ctx->r14;
            goto L_800046F4;
    }
    // 0x8000462C: sh          $t6, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r14;
    // 0x80004630: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004634: lhu         $a1, 0x11E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X11E);
    // 0x80004638: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000463C: jal         0x80014A98
    // 0x80004640: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80014A98(rdram, ctx);
        goto after_0;
    // 0x80004640: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80004644: b           L_800046F8
    // 0x80004648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800046F8;
    // 0x80004648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000464C:
    // 0x8000464C: lhu         $t8, 0x4($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X4);
    // 0x80004650: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80004654: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80004658: bne         $t0, $zero, L_800046F4
    if (ctx->r8 != 0) {
        // 0x8000465C: sh          $t9, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r25;
            goto L_800046F4;
    }
    // 0x8000465C: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80004660: jal         0x80015B50
    // 0x80004664: nop

    func_80015B50(rdram, ctx);
        goto after_1;
    // 0x80004664: nop

    after_1:
    // 0x80004668: beq         $v0, $zero, L_80004678
    if (ctx->r2 == 0) {
        // 0x8000466C: addiu       $t1, $zero, 0x8
        ctx->r9 = ADD32(0, 0X8);
            goto L_80004678;
    }
    // 0x8000466C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80004670: b           L_800046F4
    // 0x80004674: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
        goto L_800046F4;
    // 0x80004674: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
L_80004678:
    // 0x80004678: lhu         $t2, 0x60($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X60);
    // 0x8000467C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80004680: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004684: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80004688: sh          $t3, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r11;
    // 0x8000468C: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80004690: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80004694: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004698: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x8000469C: beq         $t4, $zero, L_800046DC
    if (ctx->r12 == 0) {
        // 0x800046A0: andi        $t8, $v0, 0xFFFB
        ctx->r24 = ctx->r2 & 0XFFFB;
            goto L_800046DC;
    }
    // 0x800046A0: andi        $t8, $v0, 0xFFFB
    ctx->r24 = ctx->r2 & 0XFFFB;
    // 0x800046A4: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x800046A8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800046AC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800046B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800046B4: lh          $t7, 0x122($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X122);
    // 0x800046B8: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    // 0x800046BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800046C0: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x800046C4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800046C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800046CC: jal         0x8001D8B0
    // 0x800046D0: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    func_8001D8B0(rdram, ctx);
        goto after_2;
    // 0x800046D0: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    after_2:
    // 0x800046D4: b           L_800046E0
    // 0x800046D8: nop

        goto L_800046E0;
    // 0x800046D8: nop

L_800046DC:
    // 0x800046DC: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800046E0:
    // 0x800046E0: jal         0x800073CC
    // 0x800046E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800073CC(rdram, ctx);
        goto after_3;
    // 0x800046E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800046E8: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800046EC: jal         0x8001D358
    // 0x800046F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001D358(rdram, ctx);
        goto after_4;
    // 0x800046F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_800046F4:
    // 0x800046F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800046F8:
    // 0x800046F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800046FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80004700: jr          $ra
    // 0x80004704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8000DB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB38: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000DB3C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8000DB40: addiu       $v0, $v0, 0x4E60
    ctx->r2 = ADD32(ctx->r2, 0X4E60);
L_8000DB44:
    // 0x8000DB44: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000DB48: beql        $t6, $zero, L_8000DB68
    if (ctx->r14 == 0) {
        // 0x8000DB4C: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8000DB68;
    }
    goto skip_0;
    // 0x8000DB4C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8000DB50: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x8000DB54: bne         $a0, $t7, L_8000DB64
    if (ctx->r4 != ctx->r15) {
        // 0x8000DB58: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_8000DB64;
    }
    // 0x8000DB58: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8000DB5C: b           L_8000DB70
    // 0x8000DB60: subu        $v1, $t8, $v1
    ctx->r3 = SUB32(ctx->r24, ctx->r3);
        goto L_8000DB70;
    // 0x8000DB60: subu        $v1, $t8, $v1
    ctx->r3 = SUB32(ctx->r24, ctx->r3);
L_8000DB64:
    // 0x8000DB64: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_8000DB68:
    // 0x8000DB68: bne         $v1, $zero, L_8000DB44
    if (ctx->r3 != 0) {
        // 0x8000DB6C: addiu       $v0, $v0, 0x1C
        ctx->r2 = ADD32(ctx->r2, 0X1C);
            goto L_8000DB44;
    }
    // 0x8000DB6C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_8000DB70:
    // 0x8000DB70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000DB74: jr          $ra
    // 0x8000DB78: nop

    return;
    // 0x8000DB78: nop

;}
RECOMP_FUNC void func_800070C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800070C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800070C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800070C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800070CC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800070D0: lhu         $a3, 0x11C($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X11C);
    // 0x800070D4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800070D8: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800070DC: beq         $at, $zero, L_800071DC
    if (ctx->r1 == 0) {
        // 0x800070E0: nop
    
            goto L_800071DC;
    }
    // 0x800070E0: nop

    // 0x800070E4: lhu         $v0, 0x2876($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2876);
    // 0x800070E8: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800070EC: beq         $t6, $zero, L_800071DC
    if (ctx->r14 == 0) {
        // 0x800070F0: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_800071DC;
    }
    // 0x800070F0: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x800070F4: beq         $t7, $zero, L_80007104
    if (ctx->r15 == 0) {
        // 0x800070F8: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_80007104;
    }
    // 0x800070F8: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x800070FC: b           L_80007138
    // 0x80007100: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
        goto L_80007138;
    // 0x80007100: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80007104:
    // 0x80007104: beq         $t8, $zero, L_80007118
    if (ctx->r24 == 0) {
        // 0x80007108: andi        $t0, $v0, 0x2
        ctx->r8 = ctx->r2 & 0X2;
            goto L_80007118;
    }
    // 0x80007108: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x8000710C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80007110: b           L_80007138
    // 0x80007114: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_80007138;
    // 0x80007114: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80007118:
    // 0x80007118: beq         $t0, $zero, L_8000712C
    if (ctx->r8 == 0) {
        // 0x8000711C: andi        $t2, $v0, 0x1
        ctx->r10 = ctx->r2 & 0X1;
            goto L_8000712C;
    }
    // 0x8000711C: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80007120: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80007124: b           L_80007138
    // 0x80007128: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
        goto L_80007138;
    // 0x80007128: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_8000712C:
    // 0x8000712C: beq         $t2, $zero, L_80007138
    if (ctx->r10 == 0) {
        // 0x80007130: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_80007138;
    }
    // 0x80007130: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80007134: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80007138:
    // 0x80007138: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8000713C: addu        $t5, $a2, $a3
    ctx->r13 = ADD32(ctx->r6, ctx->r7);
    // 0x80007140: addiu       $a1, $a2, 0x119
    ctx->r5 = ADD32(ctx->r6, 0X119);
    // 0x80007144: sb          $t4, 0x119($t5)
    MEM_B(0X119, ctx->r13) = ctx->r12;
    // 0x80007148: lhu         $t6, 0x11C($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X11C);
    // 0x8000714C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80007150: sh          $t7, 0x11C($a2)
    MEM_H(0X11C, ctx->r6) = ctx->r15;
    // 0x80007154: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80007158: jal         0x80014890
    // 0x8000715C: andi        $a0, $t7, 0xFFFF
    ctx->r4 = ctx->r15 & 0XFFFF;
    func_80014890(rdram, ctx);
        goto after_0;
    // 0x8000715C: andi        $a0, $t7, 0xFFFF
    ctx->r4 = ctx->r15 & 0XFFFF;
    after_0:
    // 0x80007160: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80007164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80007168: lw          $t8, 0x10($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X10);
    // 0x8000716C: jal         0x800149D0
    // 0x80007170: lhu         $a1, 0x8($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X8);
    func_800149D0(rdram, ctx);
        goto after_1;
    // 0x80007170: lhu         $a1, 0x8($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X8);
    after_1:
    // 0x80007174: andi        $t9, $v0, 0x5
    ctx->r25 = ctx->r2 & 0X5;
    // 0x80007178: beq         $t9, $zero, L_80007194
    if (ctx->r25 == 0) {
        // 0x8000717C: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80007194;
    }
    // 0x8000717C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80007180: lhu         $t0, 0x11C($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X11C);
    // 0x80007184: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80007188: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8000718C: b           L_800071BC
    // 0x80007190: sh          $t1, 0x11C($a2)
    MEM_H(0X11C, ctx->r6) = ctx->r9;
        goto L_800071BC;
    // 0x80007190: sh          $t1, 0x11C($a2)
    MEM_H(0X11C, ctx->r6) = ctx->r9;
L_80007194:
    // 0x80007194: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80007198: addiu       $a0, $a0, -0x4D1C
    ctx->r4 = ADD32(ctx->r4, -0X4D1C);
    // 0x8000719C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800071A0: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // 0x800071A4: andi        $t2, $v1, 0x4
    ctx->r10 = ctx->r3 & 0X4;
    // 0x800071A8: bne         $t2, $zero, L_800071B8
    if (ctx->r10 != 0) {
        // 0x800071AC: ori         $t3, $v1, 0x4
        ctx->r11 = ctx->r3 | 0X4;
            goto L_800071B8;
    }
    // 0x800071AC: ori         $t3, $v1, 0x4
    ctx->r11 = ctx->r3 | 0X4;
    // 0x800071B0: b           L_800071BC
    // 0x800071B4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
        goto L_800071BC;
    // 0x800071B4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_800071B8:
    // 0x800071B8: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_800071BC:
    // 0x800071BC: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x800071C0: sra         $t4, $a1, 24
    ctx->r12 = S32(SIGNED(ctx->r5) >> 24);
    // 0x800071C4: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800071C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800071CC: jal         0x800268D4
    // 0x800071D0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_2;
    // 0x800071D0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_2:
    // 0x800071D4: b           L_80007298
    // 0x800071D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80007298;
    // 0x800071D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800071DC:
    // 0x800071DC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800071E0: beq         $a3, $zero, L_80007240
    if (ctx->r7 == 0) {
        // 0x800071E4: lhu         $v0, 0x2876($v0)
        ctx->r2 = MEM_HU(ctx->r2, 0X2876);
            goto L_80007240;
    }
    // 0x800071E4: lhu         $v0, 0x2876($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2876);
    // 0x800071E8: andi        $t5, $v0, 0xA000
    ctx->r13 = ctx->r2 & 0XA000;
    // 0x800071EC: beq         $t5, $zero, L_80007240
    if (ctx->r13 == 0) {
        // 0x800071F0: andi        $a0, $a3, 0xFFFF
        ctx->r4 = ctx->r7 & 0XFFFF;
            goto L_80007240;
    }
    // 0x800071F0: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x800071F4: addiu       $a1, $a2, 0x119
    ctx->r5 = ADD32(ctx->r6, 0X119);
    // 0x800071F8: jal         0x80014890
    // 0x800071FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80014890(rdram, ctx);
        goto after_3;
    // 0x800071FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x80007200: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80007204: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80007208: lw          $t6, 0x10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X10);
    // 0x8000720C: sh          $v0, 0x11E($a2)
    MEM_H(0X11E, ctx->r6) = ctx->r2;
    // 0x80007210: jal         0x800149D0
    // 0x80007214: lhu         $a1, 0x8($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X8);
    func_800149D0(rdram, ctx);
        goto after_4;
    // 0x80007214: lhu         $a1, 0x8($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X8);
    after_4:
    // 0x80007218: bne         $v0, $zero, L_80007294
    if (ctx->r2 != 0) {
        // 0x8000721C: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80007294;
    }
    // 0x8000721C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80007220: addiu       $a0, $a0, -0x4D1C
    ctx->r4 = ADD32(ctx->r4, -0X4D1C);
    // 0x80007224: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80007228: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8000722C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80007230: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80007234: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80007238: b           L_80007294
    // 0x8000723C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_80007294;
    // 0x8000723C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80007240:
    // 0x80007240: andi        $t0, $v0, 0x4000
    ctx->r8 = ctx->r2 & 0X4000;
    // 0x80007244: beq         $t0, $zero, L_80007294
    if (ctx->r8 == 0) {
        // 0x80007248: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80007294;
    }
    // 0x80007248: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000724C: addiu       $a0, $a0, -0x4D1C
    ctx->r4 = ADD32(ctx->r4, -0X4D1C);
    // 0x80007250: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80007254: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80007258: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x8000725C: beql        $t2, $zero, L_80007298
    if (ctx->r10 == 0) {
        // 0x80007260: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_80007298;
    }
    goto skip_0;
    // 0x80007260: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80007264: beq         $a3, $zero, L_80007274
    if (ctx->r7 == 0) {
        // 0x80007268: addiu       $t3, $a3, -0x1
        ctx->r11 = ADD32(ctx->r7, -0X1);
            goto L_80007274;
    }
    // 0x80007268: addiu       $t3, $a3, -0x1
    ctx->r11 = ADD32(ctx->r7, -0X1);
    // 0x8000726C: sh          $t3, 0x11C($a2)
    MEM_H(0X11C, ctx->r6) = ctx->r11;
    // 0x80007270: andi        $a3, $t3, 0xFFFF
    ctx->r7 = ctx->r11 & 0XFFFF;
L_80007274:
    // 0x80007274: bne         $a3, $zero, L_8000728C
    if (ctx->r7 != 0) {
        // 0x80007278: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_8000728C;
    }
    // 0x80007278: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8000727C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80007280: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80007284: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80007288: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8000728C:
    // 0x8000728C: jal         0x800268D4
    // 0x80007290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800268D4(rdram, ctx);
        goto after_5;
    // 0x80007290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_80007294:
    // 0x80007294: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80007298:
    // 0x80007298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000729C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800072A0: jr          $ra
    // 0x800072A4: nop

    return;
    // 0x800072A4: nop

;}
RECOMP_FUNC void func_80100000_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100004: sw          $zero, -0x52D0($at)
    MEM_W(-0X52D0, ctx->r1) = 0;
    // 0x80100008: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010000C: sw          $zero, -0x52BC($at)
    MEM_W(-0X52BC, ctx->r1) = 0;
    // 0x80100010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80100014: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100018: sw          $v0, 0x3424($at)
    MEM_W(0X3424, ctx->r1) = ctx->r2;
    // 0x8010001C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100020: sw          $zero, 0x3420($at)
    MEM_W(0X3420, ctx->r1) = 0;
    // 0x80100024: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100028: sw          $v0, -0x52CC($at)
    MEM_W(-0X52CC, ctx->r1) = ctx->r2;
    // 0x8010002C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100030: sw          $zero, -0x52C4($at)
    MEM_W(-0X52C4, ctx->r1) = 0;
    // 0x80100034: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100038: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8010003C: sw          $t6, -0x52C0($at)
    MEM_W(-0X52C0, ctx->r1) = ctx->r14;
    // 0x80100040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100044: jr          $ra
    // 0x80100048: sw          $zero, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = 0;
    return;
    // 0x80100048: sw          $zero, -0x52C8($at)
    MEM_W(-0X52C8, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80022300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022300: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80022304: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80022308: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x8002230C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80022310: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80022314: beql        $t7, $zero, L_80022334
    if (ctx->r15 == 0) {
        // 0x80022318: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80022334;
    }
    goto skip_0;
    // 0x80022318: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8002231C: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    // 0x80022320: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x80022324: beql        $t9, $zero, L_80022334
    if (ctx->r25 == 0) {
        // 0x80022328: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80022334;
    }
    goto skip_1;
    // 0x80022328: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x8002232C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80022330: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80022334:
    // 0x80022334: jr          $ra
    // 0x80022338: nop

    return;
    // 0x80022338: nop

;}
RECOMP_FUNC void func_80031A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031A44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80031A48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031A4C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80031A50: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80031A54: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80031A58: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80031A5C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80031A60: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80031A64: addiu       $t8, $t8, 0x2898
    ctx->r24 = ADD32(ctx->r24, 0X2898);
    // 0x80031A68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031A6C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031A70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031A74: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80031A78: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80031A7C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80031A80: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80031A84: jal         0x8003B120
    // 0x80031A88: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_0;
    // 0x80031A88: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80031A8C: beq         $v0, $zero, L_80031A9C
    if (ctx->r2 == 0) {
        // 0x80031A90: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80031A9C;
    }
    // 0x80031A90: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80031A94: b           L_80031AC0
    // 0x80031A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80031AC0;
    // 0x80031A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031A9C:
    // 0x80031A9C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80031AA0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80031AA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80031AA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80031AAC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80031AB0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80031AB4: jal         0x8003C12C
    // 0x80031AB8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_1;
    // 0x80031AB8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_1:
    // 0x80031ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031AC0:
    // 0x80031AC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80031AC4: jr          $ra
    // 0x80031AC8: nop

    return;
    // 0x80031AC8: nop

;}
RECOMP_FUNC void func_8001715C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001715C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80017160: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017164: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80017168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001716C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80017170: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80017174: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x80017178: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x8001717C: bne         $t7, $zero, L_800171C8
    if (ctx->r15 != 0) {
        // 0x80017180: nop
    
            goto L_800171C8;
    }
    // 0x80017180: nop

    // 0x80017184: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x80017188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001718C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80017190: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80017194: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80017198: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8001719C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x800171A0: lhu         $t0, 0x60($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X60);
    // 0x800171A4: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x800171A8: sh          $t1, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r9;
    // 0x800171AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800171B0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800171B4: andi        $t2, $a2, 0xFFFF
    ctx->r10 = ctx->r6 & 0XFFFF;
    // 0x800171B8: jal         0x8001FCF8
    // 0x800171BC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x800171BC: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800171C0: b           L_800171D4
    // 0x800171C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800171D4;
    // 0x800171C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800171C8:
    // 0x800171C8: jal         0x800208B8
    // 0x800171CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800208B8(rdram, ctx);
        goto after_1;
    // 0x800171CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800171D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800171D4:
    // 0x800171D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800171D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800171DC: jr          $ra
    // 0x800171E0: nop

    return;
    // 0x800171E0: nop

;}
RECOMP_FUNC void func_8000534C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000534C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80005350: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80005354: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80005358: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000535C: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x80005360: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80005364: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80005368: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8000536C: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x80005370: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80005374: nop

    // 0x80005378: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000537C: jal         0x80034F60
    // 0x80005380: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80005380: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80005384: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80005388: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000538C: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80005390: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80005394: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    // 0x80005398: nop

    // 0x8000539C: bc1f        L_800053BC
    if (!c1cs) {
        // 0x800053A0: nop
    
            goto L_800053BC;
    }
    // 0x800053A0: nop

    // 0x800053A4: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800053A8: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x800053AC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800053B0: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x800053B4: bc1t        L_80005600
    if (c1cs) {
        // 0x800053B8: lui         $a3, 0x8008
        ctx->r7 = S32(0X8008 << 16);
            goto L_80005600;
    }
    // 0x800053B8: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
L_800053BC:
    // 0x800053BC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800053C0: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x800053C4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800053C8: jal         0x80034F60
    // 0x800053CC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x800053CC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x800053D0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800053D4: ldc1        $f6, 0x1068($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1068);
    // 0x800053D8: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800053DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800053E0: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800053E4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800053E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800053EC: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800053F0: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800053F4: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800053F8: cvt.d.s     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f12.d = CVT_D_S(ctx->f16.fl);
    // 0x800053FC: c.lt.d      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.d < ctx->f12.d;
    // 0x80005400: nop

    // 0x80005404: bc1fl       L_8000543C
    if (!c1cs) {
        // 0x80005408: lwc1        $f12, 0x60($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
            goto L_8000543C;
    }
    goto skip_0;
    // 0x80005408: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    skip_0:
    // 0x8000540C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80005410: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x80005414: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x80005418: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000541C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80005420: add.d       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f2.d + ctx->f2.d;
    // 0x80005424: div.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x80005428: div.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f12.d);
    // 0x8000542C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80005430: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80005434: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80005438: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
L_8000543C:
    // 0x8000543C: jal         0x80023210
    // 0x80005440: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    func_80023210(rdram, ctx);
        goto after_2;
    // 0x80005440: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80005444: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80005448: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000544C: ldc1        $f18, 0x1070($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1070);
    // 0x80005450: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80005454: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80005458: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000545C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80005460: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80005464: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80005468: nop

    // 0x8000546C: bc1f        L_8000548C
    if (!c1cs) {
        // 0x80005470: nop
    
            goto L_8000548C;
    }
    // 0x80005470: nop

    // 0x80005474: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005478: ldc1        $f8, 0x1078($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1078);
    // 0x8000547C: sub.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d - ctx->f8.d;
    // 0x80005480: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x80005484: b           L_800054B4
    // 0x80005488: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
        goto L_800054B4;
    // 0x80005488: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_8000548C:
    // 0x8000548C: ldc1        $f4, 0x1080($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1080);
    // 0x80005490: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005494: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x80005498: nop

    // 0x8000549C: bc1f        L_800054B4
    if (!c1cs) {
        // 0x800054A0: nop
    
            goto L_800054B4;
    }
    // 0x800054A0: nop

    // 0x800054A4: ldc1        $f6, 0x1088($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1088);
    // 0x800054A8: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x800054AC: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x800054B0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_800054B4:
    // 0x800054B4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800054B8: ldc1        $f4, 0x1090($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1090);
    // 0x800054BC: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x800054C0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800054C4: mul.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x800054C8: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800054CC: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x800054D0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800054D4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800054D8: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800054DC: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x800054E0: nop

    // 0x800054E4: bc1f        L_80005504
    if (!c1cs) {
        // 0x800054E8: nop
    
            goto L_80005504;
    }
    // 0x800054E8: nop

    // 0x800054EC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800054F0: ldc1        $f6, 0x1098($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1098);
    // 0x800054F4: sub.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d - ctx->f6.d;
    // 0x800054F8: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x800054FC: b           L_8000552C
    // 0x80005500: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
        goto L_8000552C;
    // 0x80005500: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_80005504:
    // 0x80005504: ldc1        $f10, 0x10A0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X10A0);
    // 0x80005508: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000550C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80005510: nop

    // 0x80005514: bc1fl       L_80005530
    if (!c1cs) {
        // 0x80005518: lwc1        $f2, 0x3C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80005530;
    }
    goto skip_1;
    // 0x80005518: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x8000551C: ldc1        $f6, 0x10A8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X10A8);
    // 0x80005520: add.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d + ctx->f6.d;
    // 0x80005524: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80005528: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_8000552C:
    // 0x8000552C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
L_80005530:
    // 0x80005530: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005534: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x80005538: sub.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8000553C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005540: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x80005544: ldc1        $f4, 0x10B0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X10B0);
    // 0x80005548: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8000554C: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80005550: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80005554: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80005558: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x8000555C: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80005560: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80005564: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80005568: jal         0x800232F4
    // 0x8000556C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_3;
    // 0x8000556C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80005570: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80005574: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80005578: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8000557C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80005580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005584: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80005588: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x8000558C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005590: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80005594: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80005598: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x8000559C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800055A0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800055A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800055A8: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800055AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800055B0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800055B4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800055B8: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x800055BC: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800055C0: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800055C4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800055C8: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800055CC: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x800055D0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800055D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800055D8: bc1fl       L_80005680
    if (!c1cs) {
        // 0x800055DC: lw          $t4, 0x5C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X5C);
            goto L_80005680;
    }
    goto skip_2;
    // 0x800055DC: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x800055E0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800055E4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800055E8: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x800055EC: nop

    // 0x800055F0: bc1f        L_8000567C
    if (!c1cs) {
        // 0x800055F4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8000567C;
    }
    // 0x800055F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800055F8: b           L_8000567C
    // 0x800055FC: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
        goto L_8000567C;
    // 0x800055FC: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
L_80005600:
    // 0x80005600: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80005604: ldc1        $f0, 0x10B8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X10B8);
    // 0x80005608: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x8000560C: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x80005610: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80005614: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80005618: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8000561C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80005620: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x80005624: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80005628: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8000562C: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x80005630: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80005634: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80005638: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x8000563C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80005640: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80005644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80005648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000564C: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80005650: mul.d       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80005654: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80005658: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8000565C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x80005660: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80005664: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80005668: jal         0x800186B4
    // 0x8000566C: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    func_800186B4(rdram, ctx);
        goto after_4;
    // 0x8000566C: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_4:
    // 0x80005670: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80005674: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80005678: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
L_8000567C:
    // 0x8000567C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
L_80005680:
    // 0x80005680: lh          $t5, 0x52($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X52);
    // 0x80005684: beql        $t4, $t5, L_800056BC
    if (ctx->r12 == ctx->r13) {
        // 0x80005688: sh          $a2, 0x58($s0)
        MEM_H(0X58, ctx->r16) = ctx->r6;
            goto L_800056BC;
    }
    goto skip_3;
    // 0x80005688: sh          $a2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r6;
    skip_3:
    // 0x8000568C: lh          $t6, 0x5A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5A);
    // 0x80005690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80005694: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80005698: beql        $t4, $t6, L_800056BC
    if (ctx->r12 == ctx->r14) {
        // 0x8000569C: sh          $a2, 0x58($s0)
        MEM_H(0X58, ctx->r16) = ctx->r6;
            goto L_800056BC;
    }
    goto skip_4;
    // 0x8000569C: sh          $a2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r6;
    skip_4:
    // 0x800056A0: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x800056A4: jal         0x8001D8B0
    // 0x800056A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8001D8B0(rdram, ctx);
        goto after_5;
    // 0x800056A8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_5:
    // 0x800056AC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800056B0: b           L_800056BC
    // 0x800056B4: sh          $t7, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r15;
        goto L_800056BC;
    // 0x800056B4: sh          $t7, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r15;
    // 0x800056B8: sh          $a2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r6;
L_800056BC:
    // 0x800056BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800056C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800056C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800056C8: jr          $ra
    // 0x800056CC: nop

    return;
    // 0x800056CC: nop

;}
RECOMP_FUNC void func_8000EE60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EE60: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000EE64: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000EE68: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8000EE6C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8000EE70: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000EE74: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8000EE78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000EE7C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8000EE80: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8000EE84: andi        $s3, $a3, 0xFFFF
    ctx->r19 = ctx->r7 & 0XFFFF;
    // 0x8000EE88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000EE8C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8000EE90: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8000EE94: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8000EE98: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8000EE9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000EEA0: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8000EEA4: swc1        $f4, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->f4.u32l;
    // 0x8000EEA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000EEAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000EEB0: andi        $t7, $s3, 0x1
    ctx->r15 = ctx->r19 & 0X1;
    // 0x8000EEB4: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x8000EEB8: swc1        $f14, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f14.u32l;
    // 0x8000EEBC: swc1        $f22, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f22.u32l;
    // 0x8000EEC0: sh          $t6, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r14;
    // 0x8000EEC4: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x8000EEC8: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x8000EECC: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8000EED0: beq         $t7, $zero, L_8000EF1C
    if (ctx->r15 == 0) {
        // 0x8000EED4: swc1        $f6, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->f6.u32l;
            goto L_8000EF1C;
    }
    // 0x8000EED4: swc1        $f6, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f6.u32l;
    // 0x8000EED8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EEDC: lw          $v0, 0x4F2C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4F2C);
    // 0x8000EEE0: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000EEE4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8000EEE8: beq         $v0, $zero, L_8000EF64
    if (ctx->r2 == 0) {
        // 0x8000EEEC: nop
    
            goto L_8000EF64;
    }
    // 0x8000EEEC: nop

    // 0x8000EEF0: lw          $t8, 0x4EE8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4EE8);
    // 0x8000EEF4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000EEF8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8000EEFC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8000EF00: jal         0x8000FCBC
    // 0x8000EF04: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    func_8000FCBC(rdram, ctx);
        goto after_0;
    // 0x8000EF04: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    after_0:
    // 0x8000EF08: beq         $v0, $zero, L_8000EF64
    if (ctx->r2 == 0) {
        // 0x8000EF0C: nop
    
            goto L_8000EF64;
    }
    // 0x8000EF0C: nop

    // 0x8000EF10: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8000EF14: b           L_8000EF64
    // 0x8000EF18: lwc1        $f22, 0x8($s2)
    ctx->f22.u32l = MEM_W(ctx->r18, 0X8);
        goto L_8000EF64;
    // 0x8000EF18: lwc1        $f22, 0x8($s2)
    ctx->f22.u32l = MEM_W(ctx->r18, 0X8);
L_8000EF1C:
    // 0x8000EF1C: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x8000EF20: beq         $t0, $zero, L_8000EF64
    if (ctx->r8 == 0) {
        // 0x8000EF24: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_8000EF64;
    }
    // 0x8000EF24: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EF28: lw          $v0, 0x4F30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4F30);
    // 0x8000EF2C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000EF30: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8000EF34: beq         $v0, $zero, L_8000EF64
    if (ctx->r2 == 0) {
        // 0x8000EF38: nop
    
            goto L_8000EF64;
    }
    // 0x8000EF38: nop

    // 0x8000EF3C: lw          $t1, 0x4EE8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4EE8);
    // 0x8000EF40: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000EF44: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8000EF48: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8000EF4C: jal         0x8000FCBC
    // 0x8000EF50: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    func_8000FCBC(rdram, ctx);
        goto after_1;
    // 0x8000EF50: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    after_1:
    // 0x8000EF54: beq         $v0, $zero, L_8000EF64
    if (ctx->r2 == 0) {
        // 0x8000EF58: nop
    
            goto L_8000EF64;
    }
    // 0x8000EF58: nop

    // 0x8000EF5C: lwc1        $f20, 0x0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8000EF60: lwc1        $f22, 0x8($s2)
    ctx->f22.u32l = MEM_W(ctx->r18, 0X8);
L_8000EF64:
    // 0x8000EF64: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000EF68: lw          $v0, 0x4F20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4F20);
    // 0x8000EF6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000EF70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000EF74: lhu         $t3, 0x28($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X28);
    // 0x8000EF78: bnel        $t3, $zero, L_8000EF8C
    if (ctx->r11 != 0) {
        // 0x8000EF7C: lwc1        $f8, 0x8($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
            goto L_8000EF8C;
    }
    goto skip_0;
    // 0x8000EF7C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x8000EF80: b           L_8000EFE8
    // 0x8000EF84: lw          $s1, 0x20($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X20);
        goto L_8000EFE8;
    // 0x8000EF84: lw          $s1, 0x20($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X20);
    // 0x8000EF88: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
L_8000EF8C:
    // 0x8000EF8C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000EF90: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000EF94: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8000EF98: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8000EF9C: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x8000EFA0: sub.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f6.fl;
    // 0x8000EFA4: lw          $t3, 0x20($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X20);
    // 0x8000EFA8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000EFAC: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000EFB0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000EFB4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8000EFB8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8000EFBC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8000EFC0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8000EFC4: nop

    // 0x8000EFC8: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EFCC: mflo        $t7
    ctx->r15 = lo;
    // 0x8000EFD0: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    // 0x8000EFD4: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8000EFD8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000EFDC: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8000EFE0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8000EFE4: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
L_8000EFE8:
    // 0x8000EFE8: bltzl       $v1, L_8000F060
    if (SIGNED(ctx->r3) < 0) {
        // 0x8000EFEC: lhu         $s0, 0x2($v0)
        ctx->r16 = MEM_HU(ctx->r2, 0X2);
            goto L_8000F060;
    }
    goto skip_1;
    // 0x8000EFEC: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
    skip_1:
    // 0x8000EFF0: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x8000EFF4: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000EFF8: beql        $at, $zero, L_8000F060
    if (ctx->r1 == 0) {
        // 0x8000EFFC: lhu         $s0, 0x2($v0)
        ctx->r16 = MEM_HU(ctx->r2, 0X2);
            goto L_8000F060;
    }
    goto skip_2;
    // 0x8000EFFC: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
    skip_2:
    // 0x8000F000: bltzl       $a1, L_8000F060
    if (SIGNED(ctx->r5) < 0) {
        // 0x8000F004: lhu         $s0, 0x2($v0)
        ctx->r16 = MEM_HU(ctx->r2, 0X2);
            goto L_8000F060;
    }
    goto skip_3;
    // 0x8000F004: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
    skip_3:
    // 0x8000F008: lh          $t5, 0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X6);
    // 0x8000F00C: slt         $at, $a1, $t5
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000F010: beql        $at, $zero, L_8000F060
    if (ctx->r1 == 0) {
        // 0x8000F014: lhu         $s0, 0x2($v0)
        ctx->r16 = MEM_HU(ctx->r2, 0X2);
            goto L_8000F060;
    }
    goto skip_4;
    // 0x8000F014: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
    skip_4:
    // 0x8000F018: lhu         $s0, 0x0($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X0);
    // 0x8000F01C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8000F020: beql        $s0, $zero, L_8000F060
    if (ctx->r16 == 0) {
        // 0x8000F024: lhu         $s0, 0x2($v0)
        ctx->r16 = MEM_HU(ctx->r2, 0X2);
            goto L_8000F060;
    }
    goto skip_5;
    // 0x8000F024: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
    skip_5:
    // 0x8000F028: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
L_8000F02C:
    // 0x8000F02C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8000F030: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000F034: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8000F038: andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    // 0x8000F03C: jal         0x8000F0BC
    // 0x8000F040: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    func_8000F0BC(rdram, ctx);
        goto after_2;
    // 0x8000F040: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    after_2:
    // 0x8000F044: bne         $v0, $zero, L_8000F098
    if (ctx->r2 != 0) {
        // 0x8000F048: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8000F098;
    }
    // 0x8000F048: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8000F04C: bnel        $s0, $zero, L_8000F02C
    if (ctx->r16 != 0) {
        // 0x8000F050: lhu         $a3, 0x0($s1)
        ctx->r7 = MEM_HU(ctx->r17, 0X0);
            goto L_8000F02C;
    }
    goto skip_6;
    // 0x8000F050: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
    skip_6:
    // 0x8000F054: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000F058: lw          $v0, 0x4F20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4F20);
    // 0x8000F05C: lhu         $s0, 0x2($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X2);
L_8000F060:
    // 0x8000F060: lw          $s1, 0x24($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X24);
    // 0x8000F064: beql        $s0, $zero, L_8000F09C
    if (ctx->r16 == 0) {
        // 0x8000F068: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8000F09C;
    }
    goto skip_7;
    // 0x8000F068: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x8000F06C: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
L_8000F070:
    // 0x8000F070: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8000F074: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000F078: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8000F07C: andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    // 0x8000F080: jal         0x8000F0BC
    // 0x8000F084: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    func_8000F0BC(rdram, ctx);
        goto after_3;
    // 0x8000F084: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    after_3:
    // 0x8000F088: bne         $v0, $zero, L_8000F098
    if (ctx->r2 != 0) {
        // 0x8000F08C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8000F098;
    }
    // 0x8000F08C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8000F090: bnel        $s0, $zero, L_8000F070
    if (ctx->r16 != 0) {
        // 0x8000F094: lhu         $a3, 0x0($s1)
        ctx->r7 = MEM_HU(ctx->r17, 0X0);
            goto L_8000F070;
    }
    goto skip_8;
    // 0x8000F094: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
    skip_8:
L_8000F098:
    // 0x8000F098: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000F09C:
    // 0x8000F09C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000F0A0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000F0A4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F0A8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8000F0AC: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8000F0B0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x8000F0B4: jr          $ra
    // 0x8000F0B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000F0B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8003FD40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FD40: jr          $ra
    // 0x8003FD44: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x8003FD44: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8003FD48: nop

    // 0x8003FD4C: nop

;}
RECOMP_FUNC void func_8001D828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D830: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001D834: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x8001D838: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x8001D83C: bne         $t7, $zero, L_8001D854
    if (ctx->r15 != 0) {
        // 0x8001D840: nop
    
            goto L_8001D854;
    }
    // 0x8001D840: nop

    // 0x8001D844: jal         0x80022FD0
    // 0x8001D848: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    get_rand(rdram, ctx);
        goto after_0;
    // 0x8001D848: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8001D84C: bne         $v0, $zero, L_8001D888
    if (ctx->r2 != 0) {
        // 0x8001D850: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_8001D888;
    }
    // 0x8001D850: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_8001D854:
    // 0x8001D854: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001D858: jal         0x80022FD0
    // 0x8001D85C: lhu         $a0, -0x3A66($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3A66);
    get_rand(rdram, ctx);
        goto after_1;
    // 0x8001D85C: lhu         $a0, -0x3A66($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3A66);
    after_1:
    // 0x8001D860: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8001D864: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001D868: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001D86C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001D870: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001D874: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8001D878: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8001D87C: lw          $t9, -0x3648($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3648);
    // 0x8001D880: b           L_8001D888
    // 0x8001D884: lbu         $v1, 0x34($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X34);
        goto L_8001D888;
    // 0x8001D884: lbu         $v1, 0x34($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X34);
L_8001D888:
    // 0x8001D888: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001D88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D894: jr          $ra
    // 0x8001D898: nop

    return;
    // 0x8001D898: nop

    // 0x8001D89C: jr          $ra
    // 0x8001D8A0: nop

    return;
    // 0x8001D8A0: nop

    // 0x8001D8A4: nop

    // 0x8001D8A8: nop

    // 0x8001D8AC: nop

;}
RECOMP_FUNC void func_80020D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020D4C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80020D50: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80020D54: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80020D58: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80020D5C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80020D60: andi        $s3, $a0, 0xFFFF
    ctx->r19 = ctx->r4 & 0XFFFF;
    // 0x80020D64: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80020D68: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80020D6C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80020D70: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80020D74: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80020D78: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80020D7C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80020D80: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80020D84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80020D88: jal         0x80024330
    // 0x80020D8C: andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    count_digits(rdram, ctx);
        goto after_0;
    // 0x80020D8C: andi        $a2, $s3, 0xFFFF
    ctx->r6 = ctx->r19 & 0XFFFF;
    after_0:
    // 0x80020D90: beq         $v0, $zero, L_80020E00
    if (ctx->r2 == 0) {
        // 0x80020D94: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80020E00;
    }
    // 0x80020D94: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80020D98: addiu       $s5, $zero, 0x20
    ctx->r21 = ADD32(0, 0X20);
L_80020D9C:
    // 0x80020D9C: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80020DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80020DA4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80020DA8: beq         $s5, $v0, L_80020DE8
    if (ctx->r21 == ctx->r2) {
        // 0x80020DAC: andi        $t1, $s3, 0x6
        ctx->r9 = ctx->r19 & 0X6;
            goto L_80020DE8;
    }
    // 0x80020DAC: andi        $t1, $s3, 0x6
    ctx->r9 = ctx->r19 & 0X6;
    // 0x80020DB0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80020DB4: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x80020DB8: addiu       $t8, $zero, 0x1D
    ctx->r24 = ADD32(0, 0X1D);
    // 0x80020DBC: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80020DC0: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x80020DC4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80020DC8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80020DCC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80020DD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80020DD4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80020DD8: jal         0x80020F8C
    // 0x80020DDC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_80020F8C(rdram, ctx);
        goto after_1;
    // 0x80020DDC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_1:
    // 0x80020DE0: b           L_80020DF4
    // 0x80020DE4: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
        goto L_80020DF4;
    // 0x80020DE4: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
L_80020DE8:
    // 0x80020DE8: beql        $t1, $zero, L_80020DF8
    if (ctx->r9 == 0) {
        // 0x80020DEC: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_80020DF8;
    }
    goto skip_0;
    // 0x80020DEC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x80020DF0: addiu       $s0, $s0, 0x7
    ctx->r16 = ADD32(ctx->r16, 0X7);
L_80020DF4:
    // 0x80020DF4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80020DF8:
    // 0x80020DF8: bne         $s2, $zero, L_80020D9C
    if (ctx->r18 != 0) {
        // 0x80020DFC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80020D9C;
    }
    // 0x80020DFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80020E00:
    // 0x80020E00: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80020E04: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80020E08: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80020E0C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80020E10: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80020E14: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80020E18: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80020E1C: jr          $ra
    // 0x80020E20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80020E20: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80001800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001800: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80001804: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80001808: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x8000180C: addiu       $s6, $s6, -0x4D1C
    ctx->r22 = ADD32(ctx->r22, -0X4D1C);
    // 0x80001810: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80001814: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80001818: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000181C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80001820: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80001824: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80001828: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000182C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80001830: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80001834: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001838: sw          $zero, -0x4CB8($at)
    MEM_W(-0X4CB8, ctx->r1) = 0;
    // 0x8000183C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001840: sw          $zero, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = 0;
    // 0x80001844: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x80001848: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8000184C: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x80001850: beq         $t6, $zero, L_80001958
    if (ctx->r14 == 0) {
        // 0x80001854: andi        $t7, $v1, 0x800
        ctx->r15 = ctx->r3 & 0X800;
            goto L_80001958;
    }
    // 0x80001854: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
    // 0x80001858: beq         $t7, $zero, L_80001880
    if (ctx->r15 == 0) {
        // 0x8000185C: lui         $t8, 0x8008
        ctx->r24 = S32(0X8008 << 16);
            goto L_80001880;
    }
    // 0x8000185C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80001860: lhu         $t8, -0x45A0($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X45A0);
    // 0x80001864: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001868: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000186C: lhu         $t9, -0x459E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X459E);
    // 0x80001870: sw          $t8, 0x4EE4($at)
    MEM_W(0X4EE4, ctx->r1) = ctx->r24;
    // 0x80001874: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001878: jal         0x80002EA0
    // 0x8000187C: sw          $t9, 0x4EE8($at)
    MEM_W(0X4EE8, ctx->r1) = ctx->r25;
    func_80002EA0(rdram, ctx);
        goto after_0;
    // 0x8000187C: sw          $t9, 0x4EE8($at)
    MEM_W(0X4EE8, ctx->r1) = ctx->r25;
    after_0:
L_80001880:
    // 0x80001880: jal         0x8002E5E0
    // 0x80001884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002E5E0(rdram, ctx);
        goto after_1;
    // 0x80001884: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80001888: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000188C: jal         0x8000BD10
    // 0x80001890: sw          $zero, 0x5C0($at)
    MEM_W(0X5C0, ctx->r1) = 0;
    func_8000BD10(rdram, ctx);
        goto after_2;
    // 0x80001890: sw          $zero, 0x5C0($at)
    MEM_W(0X5C0, ctx->r1) = 0;
    after_2:
    // 0x80001894: jal         0x80011B70
    // 0x80001898: nop

    func_80011B70(rdram, ctx);
        goto after_3;
    // 0x80001898: nop

    after_3:
    // 0x8000189C: jal         0x80012220
    // 0x800018A0: nop

    func_80012220(rdram, ctx);
        goto after_4;
    // 0x800018A0: nop

    after_4:
    // 0x800018A4: jal         0x80002918
    // 0x800018A8: nop

    func_80002918(rdram, ctx);
        goto after_5;
    // 0x800018A8: nop

    after_5:
    // 0x800018AC: jal         0x80007A50
    // 0x800018B0: nop

    func_80007A50(rdram, ctx);
        goto after_6;
    // 0x800018B0: nop

    after_6:
    // 0x800018B4: jal         0x80008BB0
    // 0x800018B8: nop

    func_80008BB0(rdram, ctx);
        goto after_7;
    // 0x800018B8: nop

    after_7:
    // 0x800018BC: jal         0x8000B530
    // 0x800018C0: nop

    func_8000B530(rdram, ctx);
        goto after_8;
    // 0x800018C0: nop

    after_8:
    // 0x800018C4: jal         0x80012780
    // 0x800018C8: nop

    func_80012780(rdram, ctx);
        goto after_9;
    // 0x800018C8: nop

    after_9:
    // 0x800018CC: jal         0x80010150
    // 0x800018D0: nop

    func_80010150(rdram, ctx);
        goto after_10;
    // 0x800018D0: nop

    after_10:
    // 0x800018D4: jal         0x80011100
    // 0x800018D8: nop

    func_80011100(rdram, ctx);
        goto after_11;
    // 0x800018D8: nop

    after_11:
    // 0x800018DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800018E0: jal         0x80011100
    // 0x800018E4: sw          $v0, -0x4CC0($at)
    MEM_W(-0X4CC0, ctx->r1) = ctx->r2;
    func_80011100(rdram, ctx);
        goto after_12;
    // 0x800018E4: sw          $v0, -0x4CC0($at)
    MEM_W(-0X4CC0, ctx->r1) = ctx->r2;
    after_12:
    // 0x800018E8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800018EC: jal         0x80011100
    // 0x800018F0: sw          $v0, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r2;
    func_80011100(rdram, ctx);
        goto after_13;
    // 0x800018F0: sw          $v0, -0x4CC4($at)
    MEM_W(-0X4CC4, ctx->r1) = ctx->r2;
    after_13:
    // 0x800018F4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800018F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800018FC: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80001900: addiu       $a0, $a0, -0x43F8
    ctx->r4 = ADD32(ctx->r4, -0X43F8);
    // 0x80001904: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80001908: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000190C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80001910: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80001914: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80001918: jal         0x8001C560
    // 0x8000191C: sw          $s4, 0x59E8($at)
    MEM_W(0X59E8, ctx->r1) = ctx->r20;
    func_8001C560(rdram, ctx);
        goto after_14;
    // 0x8000191C: sw          $s4, 0x59E8($at)
    MEM_W(0X59E8, ctx->r1) = ctx->r20;
    after_14:
    // 0x80001920: jal         0x80014840
    // 0x80001924: nop

    func_80014840(rdram, ctx);
        goto after_15;
    // 0x80001924: nop

    after_15:
    // 0x80001928: jal         0x800185F0
    // 0x8000192C: nop

    func_800185F0(rdram, ctx);
        goto after_16;
    // 0x8000192C: nop

    after_16:
    // 0x80001930: jal         0x8001B0D0
    // 0x80001934: nop

    func_8001B0D0(rdram, ctx);
        goto after_17;
    // 0x80001934: nop

    after_17:
    // 0x80001938: jal         0x800228E0
    // 0x8000193C: nop

    func_800228E0(rdram, ctx);
        goto after_18;
    // 0x8000193C: nop

    after_18:
    // 0x80001940: jal         0x8001E1F0
    // 0x80001944: nop

    func_8001E1F0(rdram, ctx);
        goto after_19;
    // 0x80001944: nop

    after_19:
    // 0x80001948: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x8000194C: addiu       $at, $zero, -0x841
    ctx->r1 = ADD32(0, -0X841);
    // 0x80001950: and         $v1, $t2, $at
    ctx->r3 = ctx->r10 & ctx->r1;
    // 0x80001954: sw          $v1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r3;
L_80001958:
    // 0x80001958: andi        $t4, $v1, 0x400
    ctx->r12 = ctx->r3 & 0X400;
    // 0x8000195C: beq         $t4, $zero, L_80001990
    if (ctx->r12 == 0) {
        // 0x80001960: addiu       $s4, $zero, 0x2
        ctx->r20 = ADD32(0, 0X2);
            goto L_80001990;
    }
    // 0x80001960: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x80001964: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001968: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000196C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80001970: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80001974: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80001978: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x8000197C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80001980: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80001984: jal         0x8001D8B0
    // 0x80001988: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_20;
    // 0x80001988: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_20:
    // 0x8000198C: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_80001990:
    // 0x80001990: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x80001994: beq         $t7, $zero, L_80001A38
    if (ctx->r15 == 0) {
        // 0x80001998: addiu       $at, $zero, -0x21
        ctx->r1 = ADD32(0, -0X21);
            goto L_80001A38;
    }
    // 0x80001998: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x8000199C: and         $t8, $v1, $at
    ctx->r24 = ctx->r3 & ctx->r1;
    // 0x800019A0: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x800019A4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800019A8: lhu         $v0, -0x4D10($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4D10);
    // 0x800019AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800019B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800019B4: beq         $v0, $zero, L_800019E4
    if (ctx->r2 == 0) {
        // 0x800019B8: lui         $a2, 0x8005
        ctx->r6 = S32(0X8005 << 16);
            goto L_800019E4;
    }
    // 0x800019B8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x800019BC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800019C0: beq         $v0, $s3, L_800019F4
    if (ctx->r2 == ctx->r19) {
        // 0x800019C4: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_800019F4;
    }
    // 0x800019C4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800019C8: beq         $v0, $s4, L_80001A0C
    if (ctx->r2 == ctx->r20) {
        // 0x800019CC: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_80001A0C;
    }
    // 0x800019CC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800019D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800019D4: beq         $v0, $at, L_80001A24
    if (ctx->r2 == ctx->r1) {
        // 0x800019D8: addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
            goto L_80001A24;
    }
    // 0x800019D8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800019DC: b           L_80001A38
    // 0x800019E0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_80001A38;
    // 0x800019E0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800019E4:
    // 0x800019E4: jal         0x80022B08
    // 0x800019E8: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    func_80022B08(rdram, ctx);
        goto after_21;
    // 0x800019E8: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    after_21:
    // 0x800019EC: b           L_80001A38
    // 0x800019F0: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
        goto L_80001A38;
    // 0x800019F0: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_800019F4:
    // 0x800019F4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x800019F8: addiu       $a2, $a2, -0x2A54
    ctx->r6 = ADD32(ctx->r6, -0X2A54);
    // 0x800019FC: jal         0x80022B08
    // 0x80001A00: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80022B08(rdram, ctx);
        goto after_22;
    // 0x80001A00: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_22:
    // 0x80001A04: b           L_80001A38
    // 0x80001A08: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
        goto L_80001A38;
    // 0x80001A08: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_80001A0C:
    // 0x80001A0C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80001A10: addiu       $a2, $a2, -0x298C
    ctx->r6 = ADD32(ctx->r6, -0X298C);
    // 0x80001A14: jal         0x80022B08
    // 0x80001A18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80022B08(rdram, ctx);
        goto after_23;
    // 0x80001A18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_23:
    // 0x80001A1C: b           L_80001A38
    // 0x80001A20: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
        goto L_80001A38;
    // 0x80001A20: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_80001A24:
    // 0x80001A24: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80001A28: addiu       $a2, $a2, -0x28EC
    ctx->r6 = ADD32(ctx->r6, -0X28EC);
    // 0x80001A2C: jal         0x80022B08
    // 0x80001A30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80022B08(rdram, ctx);
        goto after_24;
    // 0x80001A30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_24:
    // 0x80001A34: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_80001A38:
    // 0x80001A38: andi        $t9, $v1, 0x100
    ctx->r25 = ctx->r3 & 0X100;
    // 0x80001A3C: beq         $t9, $zero, L_80001A6C
    if (ctx->r25 == 0) {
        // 0x80001A40: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_80001A6C;
    }
    // 0x80001A40: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80001A44: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001A48: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80001A4C: lw          $a1, 0x4EE8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4EE8);
    // 0x80001A50: lw          $a0, 0x4EE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EE4);
    // 0x80001A54: jal         0x8002684C
    // 0x80001A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8002684C(rdram, ctx);
        goto after_25;
    // 0x80001A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x80001A5C: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x80001A60: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x80001A64: and         $v1, $t0, $at
    ctx->r3 = ctx->r8 & ctx->r1;
    // 0x80001A68: sw          $v1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r3;
L_80001A6C:
    // 0x80001A6C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80001A70: addiu       $v0, $v0, -0x4D18
    ctx->r2 = ADD32(ctx->r2, -0X4D18);
    // 0x80001A74: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x80001A78: addiu       $at, $zero, -0x481
    ctx->r1 = ADD32(0, -0X481);
    // 0x80001A7C: and         $t2, $v1, $at
    ctx->r10 = ctx->r3 & ctx->r1;
    // 0x80001A80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80001A84: bne         $t3, $at, L_80001ABC
    if (ctx->r11 != ctx->r1) {
        // 0x80001A88: sw          $t2, 0x0($s6)
        MEM_W(0X0, ctx->r22) = ctx->r10;
            goto L_80001ABC;
    }
    // 0x80001A88: sw          $t2, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r10;
    // 0x80001A8C: ori         $t5, $t2, 0x4080
    ctx->r13 = ctx->r10 | 0X4080;
    // 0x80001A90: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x80001A94: addiu       $t6, $zero, 0x31
    ctx->r14 = ADD32(0, 0X31);
    // 0x80001A98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001A9C: sw          $t6, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r14;
    // 0x80001AA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001AA4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80001AA8: sh          $t7, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = ctx->r15;
    // 0x80001AAC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001AB0: addiu       $t8, $zero, 0x2F
    ctx->r24 = ADD32(0, 0X2F);
    // 0x80001AB4: b           L_80001AD0
    // 0x80001AB8: sh          $t8, -0x4D0E($at)
    MEM_H(-0X4D0E, ctx->r1) = ctx->r24;
        goto L_80001AD0;
    // 0x80001AB8: sh          $t8, -0x4D0E($at)
    MEM_H(-0X4D0E, ctx->r1) = ctx->r24;
L_80001ABC:
    // 0x80001ABC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001AC0: sh          $zero, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = 0;
    // 0x80001AC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001AC8: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x80001ACC: sh          $t9, -0x4D0E($at)
    MEM_H(-0X4D0E, ctx->r1) = ctx->r25;
L_80001AD0:
    // 0x80001AD0: lui         $s7, 0x8008
    ctx->r23 = S32(0X8008 << 16);
    // 0x80001AD4: addiu       $s7, $s7, -0x4D20
    ctx->r23 = ADD32(ctx->r23, -0X4D20);
    // 0x80001AD8: lhu         $t0, 0x0($s7)
    ctx->r8 = MEM_HU(ctx->r23, 0X0);
    // 0x80001ADC: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x80001AE0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80001AE4: bne         $s3, $t0, L_80001FF4
    if (ctx->r19 != ctx->r8) {
        // 0x80001AE8: addiu       $s5, $s5, -0x4548
        ctx->r21 = ADD32(ctx->r21, -0X4548);
            goto L_80001FF4;
    }
    // 0x80001AE8: addiu       $s5, $s5, -0x4548
    ctx->r21 = ADD32(ctx->r21, -0X4548);
    // 0x80001AEC: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x80001AF0: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80001AF4: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80001AF8: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x80001AFC: addiu       $s2, $s2, -0x4D30
    ctx->r18 = ADD32(ctx->r18, -0X4D30);
    // 0x80001B00: addiu       $fp, $fp, -0x4D0C
    ctx->r30 = ADD32(ctx->r30, -0X4D0C);
    // 0x80001B04: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
L_80001B08:
    // 0x80001B08: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80001B0C: jal         0x800314C0
    // 0x80001B10: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    func_800314C0(rdram, ctx);
        goto after_26;
    // 0x80001B10: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    after_26:
    // 0x80001B14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001B18: sw          $zero, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = 0;
    // 0x80001B1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001B20: jal         0x80011850
    // 0x80001B24: sw          $zero, 0x7200($at)
    MEM_W(0X7200, ctx->r1) = 0;
    func_80011850(rdram, ctx);
        goto after_27;
    // 0x80001B24: sw          $zero, 0x7200($at)
    MEM_W(0X7200, ctx->r1) = 0;
    after_27:
    // 0x80001B28: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80001B2C: lhu         $t1, 0x4F10($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X4F10);
    // 0x80001B30: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80001B34: beq         $t2, $zero, L_80001B44
    if (ctx->r10 == 0) {
        // 0x80001B38: nop
    
            goto L_80001B44;
    }
    // 0x80001B38: nop

    // 0x80001B3C: jal         0x8001C5F4
    // 0x80001B40: nop

    func_8001C5F4(rdram, ctx);
        goto after_28;
    // 0x80001B40: nop

    after_28:
L_80001B44:
    // 0x80001B44: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80001B48: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x80001B4C: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x80001B50: beq         $t3, $zero, L_80001B80
    if (ctx->r11 == 0) {
        // 0x80001B54: andi        $t4, $v0, 0x200
        ctx->r12 = ctx->r2 & 0X200;
            goto L_80001B80;
    }
    // 0x80001B54: andi        $t4, $v0, 0x200
    ctx->r12 = ctx->r2 & 0X200;
    // 0x80001B58: beq         $t4, $zero, L_80001B70
    if (ctx->r12 == 0) {
        // 0x80001B5C: nop
    
            goto L_80001B70;
    }
    // 0x80001B5C: nop

    // 0x80001B60: jal         0x8001CACC
    // 0x80001B64: nop

    func_8001CACC(rdram, ctx);
        goto after_29;
    // 0x80001B64: nop

    after_29:
    // 0x80001B68: b           L_80001B80
    // 0x80001B6C: nop

        goto L_80001B80;
    // 0x80001B6C: nop

L_80001B70:
    // 0x80001B70: jal         0x8001CFE8
    // 0x80001B74: nop

    func_8001CFE8(rdram, ctx);
        goto after_30;
    // 0x80001B74: nop

    after_30:
    // 0x80001B78: jal         0x80008C20
    // 0x80001B7C: nop

    func_80008C20(rdram, ctx);
        goto after_31;
    // 0x80001B7C: nop

    after_31:
L_80001B80:
    // 0x80001B80: jal         0x80002F60
    // 0x80001B84: nop

    func_80002F60(rdram, ctx);
        goto after_32;
    // 0x80001B84: nop

    after_32:
    // 0x80001B88: jal         0x80007B64
    // 0x80001B8C: nop

    func_80007B64(rdram, ctx);
        goto after_33;
    // 0x80001B8C: nop

    after_33:
    // 0x80001B90: jal         0x800156D0
    // 0x80001B94: nop

    func_800156D0(rdram, ctx);
        goto after_34;
    // 0x80001B94: nop

    after_34:
    // 0x80001B98: jal         0x800102D0
    // 0x80001B9C: nop

    func_800102D0(rdram, ctx);
        goto after_35;
    // 0x80001B9C: nop

    after_35:
    // 0x80001BA0: jal         0x8000C42C
    // 0x80001BA4: nop

    func_8000C42C(rdram, ctx);
        goto after_36;
    // 0x80001BA4: nop

    after_36:
    // 0x80001BA8: jal         0x8000DC4C
    // 0x80001BAC: nop

    func_8000DC4C(rdram, ctx);
        goto after_37;
    // 0x80001BAC: nop

    after_37:
    // 0x80001BB0: lw          $t5, 0x0($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X0);
    // 0x80001BB4: ori         $at, $zero, 0xD150
    ctx->r1 = 0 | 0XD150;
    // 0x80001BB8: lui         $t7, 0x8030
    ctx->r15 = S32(0X8030 << 16);
    // 0x80001BBC: multu       $t5, $at
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001BC0: addiu       $t7, $t7, 0x1000
    ctx->r15 = ADD32(ctx->r15, 0X1000);
    // 0x80001BC4: mflo        $t6
    ctx->r14 = lo;
    // 0x80001BC8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80001BCC: jal         0x800011DC
    // 0x80001BD0: nop

    func_800011DC(rdram, ctx);
        goto after_38;
    // 0x80001BD0: nop

    after_38:
    // 0x80001BD4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x80001BD8: ori         $at, $zero, 0xD150
    ctx->r1 = 0 | 0XD150;
    // 0x80001BDC: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x80001BE0: multu       $t8, $at
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001BE4: lui         $t0, 0x8030
    ctx->r8 = S32(0X8030 << 16);
    // 0x80001BE8: addiu       $t0, $t0, 0x1000
    ctx->r8 = ADD32(ctx->r8, 0X1000);
    // 0x80001BEC: andi        $t2, $v1, 0x87
    ctx->r10 = ctx->r3 & 0X87;
    // 0x80001BF0: mflo        $t9
    ctx->r25 = lo;
    // 0x80001BF4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80001BF8: bne         $t2, $zero, L_80001CD8
    if (ctx->r10 != 0) {
        // 0x80001BFC: sw          $t1, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r9;
            goto L_80001CD8;
    }
    // 0x80001BFC: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x80001C00: lhu         $t3, 0x74($s5)
    ctx->r11 = MEM_HU(ctx->r21, 0X74);
    // 0x80001C04: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80001C08: bnel        $t4, $zero, L_80001C50
    if (ctx->r12 != 0) {
        // 0x80001C0C: lw          $v1, 0x0($s6)
        ctx->r3 = MEM_W(ctx->r22, 0X0);
            goto L_80001C50;
    }
    goto skip_0;
    // 0x80001C0C: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    skip_0:
    // 0x80001C10: lwc1        $f12, 0x14($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X14);
    // 0x80001C14: lwc1        $f14, 0x1C($s5)
    ctx->f14.u32l = MEM_W(ctx->r21, 0X1C);
    // 0x80001C18: jal         0x8000FDE0
    // 0x80001C1C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    func_8000FDE0(rdram, ctx);
        goto after_39;
    // 0x80001C1C: lw          $a2, 0x24($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X24);
    after_39:
    // 0x80001C20: beql        $v0, $zero, L_80001C50
    if (ctx->r2 == 0) {
        // 0x80001C24: lw          $v1, 0x0($s6)
        ctx->r3 = MEM_W(ctx->r22, 0X0);
            goto L_80001C50;
    }
    goto skip_1;
    // 0x80001C24: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x80001C28: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x80001C2C: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80001C30: jal         0x8001459C
    // 0x80001C34: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    func_8001459C(rdram, ctx);
        goto after_40;
    // 0x80001C34: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    after_40:
    // 0x80001C38: jal         0x800060D4
    // 0x80001C3C: nop

    func_800060D4(rdram, ctx);
        goto after_41;
    // 0x80001C3C: nop

    after_41:
    // 0x80001C40: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001C44: b           L_80001E88
    // 0x80001C48: sh          $zero, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = 0;
        goto L_80001E88;
    // 0x80001C48: sh          $zero, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = 0;
    // 0x80001C4C: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_80001C50:
    // 0x80001C50: andi        $t7, $v1, 0x1000
    ctx->r15 = ctx->r3 & 0X1000;
    // 0x80001C54: bne         $t7, $zero, L_80001E88
    if (ctx->r15 != 0) {
        // 0x80001C58: nop
    
            goto L_80001E88;
    }
    // 0x80001C58: nop

    // 0x80001C5C: lhu         $t8, 0x74($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X74);
    // 0x80001C60: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80001C64: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80001C68: bne         $t9, $zero, L_80001E88
    if (ctx->r25 != 0) {
        // 0x80001C6C: nop
    
            goto L_80001E88;
    }
    // 0x80001C6C: nop

    // 0x80001C70: lhu         $t0, 0x2876($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X2876);
    // 0x80001C74: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80001C78: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x80001C7C: beq         $t1, $zero, L_80001E88
    if (ctx->r9 == 0) {
        // 0x80001C80: nop
    
            goto L_80001E88;
    }
    // 0x80001C80: nop

    // 0x80001C84: lhu         $t2, -0x3A6E($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X3A6E);
    // 0x80001C88: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80001C8C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80001C90: bne         $t3, $zero, L_80001E88
    if (ctx->r11 != 0) {
        // 0x80001C94: nop
    
            goto L_80001E88;
    }
    // 0x80001C94: nop

    // 0x80001C98: lhu         $t4, 0x2874($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X2874);
    // 0x80001C9C: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x80001CA0: andi        $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 & 0X2000;
    // 0x80001CA4: bne         $t5, $zero, L_80001E88
    if (ctx->r13 != 0) {
        // 0x80001CA8: nop
    
            goto L_80001E88;
    }
    // 0x80001CA8: nop

    // 0x80001CAC: bne         $t6, $zero, L_80001E88
    if (ctx->r14 != 0) {
        // 0x80001CB0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80001E88;
    }
    // 0x80001CB0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80001CB4: sll         $a1, $s3, 24
    ctx->r5 = S32(ctx->r19 << 24);
    // 0x80001CB8: sra         $t8, $a1, 24
    ctx->r24 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80001CBC: sh          $t7, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r15;
    // 0x80001CC0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80001CC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80001CC8: jal         0x800268D4
    // 0x80001CCC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_42;
    // 0x80001CCC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_42:
    // 0x80001CD0: b           L_80001E88
    // 0x80001CD4: nop

        goto L_80001E88;
    // 0x80001CD4: nop

L_80001CD8:
    // 0x80001CD8: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x80001CDC: beq         $t9, $zero, L_80001E88
    if (ctx->r25 == 0) {
        // 0x80001CE0: andi        $t0, $v1, 0x2
        ctx->r8 = ctx->r3 & 0X2;
            goto L_80001E88;
    }
    // 0x80001CE0: andi        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 & 0X2;
    // 0x80001CE4: bne         $t0, $zero, L_80001E88
    if (ctx->r8 != 0) {
        // 0x80001CE8: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80001E88;
    }
    // 0x80001CE8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001CEC: addiu       $a0, $a0, -0x4D14
    ctx->r4 = ADD32(ctx->r4, -0X4D14);
    // 0x80001CF0: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80001CF4: andi        $t3, $v1, 0x4000
    ctx->r11 = ctx->r3 & 0X4000;
    // 0x80001CF8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80001CFC: addiu       $v0, $t1, -0x1
    ctx->r2 = ADD32(ctx->r9, -0X1);
    // 0x80001D00: bne         $v0, $zero, L_80001DF4
    if (ctx->r2 != 0) {
        // 0x80001D04: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80001DF4;
    }
    // 0x80001D04: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80001D08: beq         $t3, $zero, L_80001D2C
    if (ctx->r11 == 0) {
        // 0x80001D0C: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80001D2C;
    }
    // 0x80001D0C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001D10: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x80001D14: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80001D18: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x80001D1C: sh          $t4, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r12;
    // 0x80001D20: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x80001D24: b           L_80001D30
    // 0x80001D28: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
        goto L_80001D30;
    // 0x80001D28: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_80001D2C:
    // 0x80001D2C: sh          $zero, 0x0($s7)
    MEM_H(0X0, ctx->r23) = 0;
L_80001D30:
    // 0x80001D30: ori         $t6, $v1, 0x20
    ctx->r14 = ctx->r3 | 0X20;
    // 0x80001D34: andi        $v0, $t6, 0x400
    ctx->r2 = ctx->r14 & 0X400;
    // 0x80001D38: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x80001D3C: bne         $v0, $zero, L_80001D50
    if (ctx->r2 != 0) {
        // 0x80001D40: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80001D50;
    }
    // 0x80001D40: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80001D44: ori         $v1, $t6, 0x40
    ctx->r3 = ctx->r14 | 0X40;
    // 0x80001D48: sw          $v1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r3;
    // 0x80001D4C: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
L_80001D50:
    // 0x80001D50: addiu       $a0, $a0, 0x5368
    ctx->r4 = ADD32(ctx->r4, 0X5368);
    // 0x80001D54: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80001D58: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001D5C: sw          $t8, 0x4EEC($at)
    MEM_W(0X4EEC, ctx->r1) = ctx->r24;
    // 0x80001D60: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80001D64: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001D68: beq         $v0, $zero, L_80001DE0
    if (ctx->r2 == 0) {
        // 0x80001D6C: sw          $t9, 0x4EF0($at)
        MEM_W(0X4EF0, ctx->r1) = ctx->r25;
            goto L_80001DE0;
    }
    // 0x80001D6C: sw          $t9, 0x4EF0($at)
    MEM_W(0X4EF0, ctx->r1) = ctx->r25;
    // 0x80001D70: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x80001D74: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80001D78: addiu       $v1, $v1, 0x59D0
    ctx->r3 = ADD32(ctx->r3, 0X59D0);
    // 0x80001D7C: lhu         $t0, 0x6($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X6);
    // 0x80001D80: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x80001D84: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x80001D88: lhu         $t1, 0xA($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XA);
    // 0x80001D8C: sh          $t1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r9;
    // 0x80001D90: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80001D94: addiu       $a0, $t2, 0x2328
    ctx->r4 = ADD32(ctx->r10, 0X2328);
    // 0x80001D98: jal         0x80010510
    // 0x80001D9C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    func_80010510(rdram, ctx);
        goto after_43;
    // 0x80001D9C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_43:
    // 0x80001DA0: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80001DA4: lw          $t4, 0x4EE4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4EE4);
    // 0x80001DA8: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80001DAC: lw          $t5, 0x4EE8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4EE8);
    // 0x80001DB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001DB4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80001DB8: sh          $t4, -0x45A0($at)
    MEM_H(-0X45A0, ctx->r1) = ctx->r12;
    // 0x80001DBC: lw          $t6, 0x5370($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5370);
    // 0x80001DC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001DC4: sh          $t5, -0x459E($at)
    MEM_H(-0X459E, ctx->r1) = ctx->r13;
    // 0x80001DC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001DCC: sh          $t6, -0x459C($at)
    MEM_H(-0X459C, ctx->r1) = ctx->r14;
    // 0x80001DD0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001DD4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80001DD8: sh          $t7, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = ctx->r15;
    // 0x80001DDC: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_80001DE0:
    // 0x80001DE0: ori         $t8, $v1, 0x100
    ctx->r24 = ctx->r3 | 0X100;
    // 0x80001DE4: jal         0x80026488
    // 0x80001DE8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    func_80026488(rdram, ctx);
        goto after_44;
    // 0x80001DE8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    after_44:
    // 0x80001DEC: b           L_80001E88
    // 0x80001DF0: nop

        goto L_80001E88;
    // 0x80001DF0: nop

L_80001DF4:
    // 0x80001DF4: lhu         $t9, -0x4D0E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4D0E);
    // 0x80001DF8: bne         $v0, $t9, L_80001E88
    if (ctx->r2 != ctx->r25) {
        // 0x80001DFC: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_80001E88;
    }
    // 0x80001DFC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80001E00: lhu         $v0, -0x4D10($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4D10);
    // 0x80001E04: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80001E08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80001E0C: beq         $v0, $zero, L_80001E38
    if (ctx->r2 == 0) {
        // 0x80001E10: lui         $a2, 0x8005
        ctx->r6 = S32(0X8005 << 16);
            goto L_80001E38;
    }
    // 0x80001E10: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80001E14: beq         $v0, $s3, L_80001E48
    if (ctx->r2 == ctx->r19) {
        // 0x80001E18: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80001E48;
    }
    // 0x80001E18: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80001E1C: beq         $v0, $s4, L_80001E60
    if (ctx->r2 == ctx->r20) {
        // 0x80001E20: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_80001E60;
    }
    // 0x80001E20: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80001E24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80001E28: beq         $v0, $at, L_80001E78
    if (ctx->r2 == ctx->r1) {
        // 0x80001E2C: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_80001E78;
    }
    // 0x80001E2C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80001E30: b           L_80001E88
    // 0x80001E34: nop

        goto L_80001E88;
    // 0x80001E34: nop

L_80001E38:
    // 0x80001E38: jal         0x80022B08
    // 0x80001E3C: addiu       $a2, $a2, -0x2AD0
    ctx->r6 = ADD32(ctx->r6, -0X2AD0);
    func_80022B08(rdram, ctx);
        goto after_45;
    // 0x80001E3C: addiu       $a2, $a2, -0x2AD0
    ctx->r6 = ADD32(ctx->r6, -0X2AD0);
    after_45:
    // 0x80001E40: b           L_80001E88
    // 0x80001E44: nop

        goto L_80001E88;
    // 0x80001E44: nop

L_80001E48:
    // 0x80001E48: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80001E4C: addiu       $a2, $a2, -0x2A90
    ctx->r6 = ADD32(ctx->r6, -0X2A90);
    // 0x80001E50: jal         0x80022B08
    // 0x80001E54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80022B08(rdram, ctx);
        goto after_46;
    // 0x80001E54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_46:
    // 0x80001E58: b           L_80001E88
    // 0x80001E5C: nop

        goto L_80001E88;
    // 0x80001E5C: nop

L_80001E60:
    // 0x80001E60: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80001E64: addiu       $a2, $a2, -0x2A08
    ctx->r6 = ADD32(ctx->r6, -0X2A08);
    // 0x80001E68: jal         0x80022B08
    // 0x80001E6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80022B08(rdram, ctx);
        goto after_47;
    // 0x80001E6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_47:
    // 0x80001E70: b           L_80001E88
    // 0x80001E74: nop

        goto L_80001E88;
    // 0x80001E74: nop

L_80001E78:
    // 0x80001E78: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80001E7C: addiu       $a2, $a2, -0x2968
    ctx->r6 = ADD32(ctx->r6, -0X2968);
    // 0x80001E80: jal         0x80022B08
    // 0x80001E84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80022B08(rdram, ctx);
        goto after_48;
    // 0x80001E84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_48:
L_80001E88:
    // 0x80001E88: jal         0x80026658
    // 0x80001E8C: nop

    func_80026658(rdram, ctx);
        goto after_49;
    // 0x80001E8C: nop

    after_49:
    // 0x80001E90: jal         0x80034ED0
    // 0x80001E94: nop

    osGetTime_recomp(rdram, ctx);
        goto after_50;
    // 0x80001E94: nop

    after_50:
    // 0x80001E98: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001E9C: addiu       $a0, $a0, -0x45D8
    ctx->r4 = ADD32(ctx->r4, -0X45D8);
    // 0x80001EA0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80001EA4: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80001EA8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80001EAC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80001EB0: lw          $t3, -0x45DC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X45DC);
    // 0x80001EB4: lw          $t2, -0x45E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X45E0);
    // 0x80001EB8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80001EBC: addiu       $a1, $a1, -0x45D0
    ctx->r5 = ADD32(ctx->r5, -0X45D0);
    // 0x80001EC0: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x80001EC4: subu        $t4, $v0, $t2
    ctx->r12 = SUB32(ctx->r2, ctx->r10);
    // 0x80001EC8: subu        $t4, $t4, $at
    ctx->r12 = SUB32(ctx->r12, ctx->r1);
    // 0x80001ECC: subu        $t5, $v1, $t3
    ctx->r13 = SUB32(ctx->r3, ctx->r11);
    // 0x80001ED0: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80001ED4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80001ED8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001EDC: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80001EE0: lw          $t8, -0x39C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39C0);
    // 0x80001EE4: sw          $t4, -0x45C8($at)
    MEM_W(-0X45C8, ctx->r1) = ctx->r12;
    // 0x80001EE8: sw          $t5, -0x45C4($at)
    MEM_W(-0X45C4, ctx->r1) = ctx->r13;
    // 0x80001EEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80001EF0: beq         $t8, $at, L_80001F28
    if (ctx->r24 == ctx->r1) {
        // 0x80001EF4: nop
    
            goto L_80001F28;
    }
    // 0x80001EF4: nop

    // 0x80001EF8: jal         0x8002543C
    // 0x80001EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002543C(rdram, ctx);
        goto after_51;
    // 0x80001EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_51:
    // 0x80001F00: bne         $v0, $zero, L_80001F28
    if (ctx->r2 != 0) {
        // 0x80001F04: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80001F28;
    }
    // 0x80001F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80001F08: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80001F0C: jal         0x800252D8
    // 0x80001F10: lw          $a1, -0x39C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X39C0);
    func_800252D8(rdram, ctx);
        goto after_52;
    // 0x80001F10: lw          $a1, -0x39C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X39C0);
    after_52:
    // 0x80001F14: jal         0x80025364
    // 0x80001F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80025364(rdram, ctx);
        goto after_53;
    // 0x80001F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_53:
    // 0x80001F1C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80001F20: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80001F24: sw          $t9, -0x39C0($at)
    MEM_W(-0X39C0, ctx->r1) = ctx->r25;
L_80001F28:
    // 0x80001F28: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80001F2C: addiu       $v1, $v1, -0x4CB8
    ctx->r3 = ADD32(ctx->r3, -0X4CB8);
    // 0x80001F30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80001F34: bne         $v0, $zero, L_80001F68
    if (ctx->r2 != 0) {
        // 0x80001F38: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80001F68;
    }
    // 0x80001F38: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80001F3C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80001F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80001F44:
    // 0x80001F44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80001F48: jal         0x80034020
    // 0x80001F4C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_54;
    // 0x80001F4C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_54:
    // 0x80001F50: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80001F54: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80001F58: bnel        $s3, $t2, L_80001F44
    if (ctx->r19 != ctx->r10) {
        // 0x80001F5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80001F44;
    }
    goto skip_2;
    // 0x80001F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80001F60: b           L_80001FB4
    // 0x80001F64: nop

        goto L_80001FB4;
    // 0x80001F64: nop

L_80001F68:
    // 0x80001F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80001F6C:
    // 0x80001F6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80001F70: jal         0x80034020
    // 0x80001F74: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_55;
    // 0x80001F74: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_55:
    // 0x80001F78: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80001F7C: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80001F80: bnel        $s4, $t4, L_80001F6C
    if (ctx->r20 != ctx->r12) {
        // 0x80001F84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80001F6C;
    }
    goto skip_3;
    // 0x80001F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80001F88: lhu         $t5, 0x0($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X0);
    // 0x80001F8C: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80001F90: beq         $at, $zero, L_80001FB4
    if (ctx->r1 == 0) {
        // 0x80001F94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80001FB4;
    }
    // 0x80001F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80001F98:
    // 0x80001F98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80001F9C: jal         0x80034020
    // 0x80001FA0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_56;
    // 0x80001FA0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_56:
    // 0x80001FA4: lhu         $t6, 0x0($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X0);
    // 0x80001FA8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80001FAC: bnel        $at, $zero, L_80001F98
    if (ctx->r1 != 0) {
        // 0x80001FB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80001F98;
    }
    goto skip_4;
    // 0x80001FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
L_80001FB4:
    // 0x80001FB4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80001FB8: lw          $a0, -0x4628($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4628);
    // 0x80001FBC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80001FC0: jal         0x80034200
    // 0x80001FC4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_57;
    // 0x80001FC4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_57:
    // 0x80001FC8: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x80001FCC: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x80001FD0: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x80001FD4: jal         0x80034ED0
    // 0x80001FD8: sw          $t8, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r24;
    osGetTime_recomp(rdram, ctx);
        goto after_58;
    // 0x80001FD8: sw          $t8, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r24;
    after_58:
    // 0x80001FDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80001FE0: sw          $v0, -0x45E0($at)
    MEM_W(-0X45E0, ctx->r1) = ctx->r2;
    // 0x80001FE4: sw          $v1, -0x45DC($at)
    MEM_W(-0X45DC, ctx->r1) = ctx->r3;
    // 0x80001FE8: lhu         $t9, 0x0($s7)
    ctx->r25 = MEM_HU(ctx->r23, 0X0);
    // 0x80001FEC: beq         $s3, $t9, L_80001B08
    if (ctx->r19 == ctx->r25) {
        // 0x80001FF0: nop
    
            goto L_80001B08;
    }
    // 0x80001FF0: nop

L_80001FF4:
    // 0x80001FF4: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x80001FF8: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80001FFC: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x80002000: andi        $t1, $t0, 0x200
    ctx->r9 = ctx->r8 & 0X200;
    // 0x80002004: beq         $t1, $zero, L_80002014
    if (ctx->r9 == 0) {
        // 0x80002008: addiu       $s1, $sp, 0x5C
        ctx->r17 = ADD32(ctx->r29, 0X5C);
            goto L_80002014;
    }
    // 0x80002008: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x8000200C: jal         0x800253F0
    // 0x80002010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800253F0(rdram, ctx);
        goto after_59;
    // 0x80002010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_59:
L_80002014:
    // 0x80002014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002018:
    // 0x80002018: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000201C: jal         0x80034020
    // 0x80002020: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_60;
    // 0x80002020: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_60:
    // 0x80002024: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80002028: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8000202C: bnel        $s4, $t3, L_80002018
    if (ctx->r20 != ctx->r11) {
        // 0x80002030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002018;
    }
    goto skip_5;
    // 0x80002030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80002034: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x80002038: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x8000203C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80002040: andi        $t4, $v1, 0x200
    ctx->r12 = ctx->r3 & 0X200;
    // 0x80002044: beq         $t4, $zero, L_8000206C
    if (ctx->r12 == 0) {
        // 0x80002048: and         $t5, $v1, $at
        ctx->r13 = ctx->r3 & ctx->r1;
            goto L_8000206C;
    }
    // 0x80002048: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x8000204C: jal         0x8002543C
    // 0x80002050: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    func_8002543C(rdram, ctx);
        goto after_61;
    // 0x80002050: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    after_61:
    // 0x80002054: beql        $v0, $zero, L_80002070
    if (ctx->r2 == 0) {
        // 0x80002058: lw          $t6, 0x0($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X0);
            goto L_80002070;
    }
    goto skip_6;
    // 0x80002058: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    skip_6:
L_8000205C:
    // 0x8000205C: jal         0x8002543C
    // 0x80002060: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002543C(rdram, ctx);
        goto after_62;
    // 0x80002060: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_62:
    // 0x80002064: bne         $v0, $zero, L_8000205C
    if (ctx->r2 != 0) {
        // 0x80002068: nop
    
            goto L_8000205C;
    }
    // 0x80002068: nop

L_8000206C:
    // 0x8000206C: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
L_80002070:
    // 0x80002070: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x80002074: beql        $t7, $zero, L_80002088
    if (ctx->r15 == 0) {
        // 0x80002078: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80002088;
    }
    goto skip_7;
    // 0x80002078: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_7:
    // 0x8000207C: jal         0x8002B510
    // 0x80002080: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8002B510(rdram, ctx);
        goto after_63;
    // 0x80002080: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_63:
    // 0x80002084: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80002088:
    // 0x80002088: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000208C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80002090: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80002094: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80002098: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000209C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800020A0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800020A4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800020A8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800020AC: jr          $ra
    // 0x800020B0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800020B0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void guLookAtReflectF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035C90: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80035C94: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80035C98: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80035C9C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80035CA0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80035CA4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80035CA8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80035CAC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80035CB0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80035CB4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80035CB8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80035CBC: jal         0x80035300
    // 0x80035CC0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80035CC0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80035CC4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80035CC8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80035CCC: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80035CD0: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80035CD4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035CD8: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035CDC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80035CE0: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035CE4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035CE8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80035CEC: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035CF0: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80035CF4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80035CF8: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80035CFC: jal         0x80034F60
    // 0x80035D00: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80035D00: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80035D04: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80035D08: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80035D0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80035D10: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80035D14: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80035D18: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80035D1C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80035D20: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80035D24: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80035D28: nop

    // 0x80035D2C: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80035D30: nop

    // 0x80035D34: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80035D38: nop

    // 0x80035D3C: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80035D40: nop

    // 0x80035D44: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80035D48: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80035D4C: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80035D50: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80035D54: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80035D58: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035D5C: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80035D60: nop

    // 0x80035D64: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80035D68: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035D6C: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80035D70: nop

    // 0x80035D74: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80035D78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035D7C: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80035D80: jal         0x80034F60
    // 0x80035D84: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x80035D84: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80035D88: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80035D8C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80035D90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80035D94: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80035D98: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80035D9C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80035DA0: mul.s       $f26, $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x80035DA4: nop

    // 0x80035DA8: mul.s       $f28, $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f14.fl);
    // 0x80035DAC: nop

    // 0x80035DB0: mul.s       $f30, $f30, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f14.fl);
    // 0x80035DB4: nop

    // 0x80035DB8: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x80035DBC: nop

    // 0x80035DC0: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x80035DC4: nop

    // 0x80035DC8: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x80035DCC: nop

    // 0x80035DD0: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80035DD4: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80035DD8: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80035DDC: nop

    // 0x80035DE0: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80035DE4: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80035DE8: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80035DEC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035DF0: nop

    // 0x80035DF4: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80035DF8: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x80035DFC: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80035E00: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80035E04: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80035E08: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x80035E0C: jal         0x80034F60
    // 0x80035E10: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_3;
    // 0x80035E10: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x80035E14: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80035E18: ldc1        $f2, 0x1BA0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X1BA0);
    // 0x80035E1C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80035E20: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80035E24: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80035E28: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80035E2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80035E30: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80035E34: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80035E38: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80035E3C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80035E40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80035E44: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80035E48: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80035E4C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80035E50: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x80035E54: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80035E58: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80035E5C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80035E60: cvt.d.s     $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f8.d = CVT_D_S(ctx->f26.fl);
    // 0x80035E64: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x80035E68: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80035E6C: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80035E70: mul.d       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80035E74: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80035E78: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80035E7C: nop

    // 0x80035E80: bc1fl       L_80035E94
    if (!c1cs) {
        // 0x80035E84: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80035E94;
    }
    goto skip_0;
    // 0x80035E84: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_0:
    // 0x80035E88: b           L_80035E94
    // 0x80035E8C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80035E94;
    // 0x80035E8C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80035E90: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80035E94:
    // 0x80035E94: cvt.d.s     $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f4.d = CVT_D_S(ctx->f28.fl);
    // 0x80035E98: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80035E9C: mul.d       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80035EA0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80035EA4: nop

    // 0x80035EA8: sb          $t8, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r24;
    // 0x80035EAC: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80035EB0: nop

    // 0x80035EB4: bc1fl       L_80035EC8
    if (!c1cs) {
        // 0x80035EB8: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80035EC8;
    }
    goto skip_1;
    // 0x80035EB8: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_1:
    // 0x80035EBC: b           L_80035EC8
    // 0x80035EC0: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80035EC8;
    // 0x80035EC0: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80035EC4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80035EC8:
    // 0x80035EC8: cvt.d.s     $f8, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f8.d = CVT_D_S(ctx->f30.fl);
    // 0x80035ECC: trunc.w.d   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80035ED0: mul.d       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80035ED4: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80035ED8: nop

    // 0x80035EDC: sb          $t1, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r9;
    // 0x80035EE0: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80035EE4: nop

    // 0x80035EE8: bc1fl       L_80035EFC
    if (!c1cs) {
        // 0x80035EEC: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80035EFC;
    }
    goto skip_2;
    // 0x80035EEC: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_2:
    // 0x80035EF0: b           L_80035EFC
    // 0x80035EF4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80035EFC;
    // 0x80035EF4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80035EF8: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80035EFC:
    // 0x80035EFC: trunc.w.d   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80035F00: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80035F04: nop

    // 0x80035F08: sb          $t4, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r12;
    // 0x80035F0C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80035F10: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80035F14: mul.d       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80035F18: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80035F1C: nop

    // 0x80035F20: bc1fl       L_80035F34
    if (!c1cs) {
        // 0x80035F24: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80035F34;
    }
    goto skip_3;
    // 0x80035F24: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_3:
    // 0x80035F28: b           L_80035F34
    // 0x80035F2C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80035F34;
    // 0x80035F2C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80035F30: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80035F34:
    // 0x80035F34: trunc.w.d   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80035F38: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80035F3C: nop

    // 0x80035F40: sb          $t7, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r15;
    // 0x80035F44: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80035F48: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80035F4C: mul.d       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x80035F50: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80035F54: nop

    // 0x80035F58: bc1fl       L_80035F6C
    if (!c1cs) {
        // 0x80035F5C: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80035F6C;
    }
    goto skip_4;
    // 0x80035F5C: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_4:
    // 0x80035F60: b           L_80035F6C
    // 0x80035F64: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80035F6C;
    // 0x80035F64: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80035F68: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80035F6C:
    // 0x80035F6C: trunc.w.d   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80035F70: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80035F74: nop

    // 0x80035F78: sb          $t0, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r8;
    // 0x80035F7C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80035F80: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80035F84: mul.d       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80035F88: c.lt.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d < ctx->f2.d;
    // 0x80035F8C: nop

    // 0x80035F90: bc1fl       L_80035FA4
    if (!c1cs) {
        // 0x80035F94: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80035FA4;
    }
    goto skip_5;
    // 0x80035F94: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    skip_5:
    // 0x80035F98: b           L_80035FA4
    // 0x80035F9C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80035FA4;
    // 0x80035F9C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x80035FA0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_80035FA4:
    // 0x80035FA4: trunc.w.d   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80035FA8: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80035FAC: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x80035FB0: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x80035FB4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80035FB8: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x80035FBC: sb          $zero, 0x4($a1)
    MEM_B(0X4, ctx->r5) = 0;
    // 0x80035FC0: sb          $zero, 0x5($a1)
    MEM_B(0X5, ctx->r5) = 0;
    // 0x80035FC4: sb          $zero, 0x6($a1)
    MEM_B(0X6, ctx->r5) = 0;
    // 0x80035FC8: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x80035FCC: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
    // 0x80035FD0: sb          $v0, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r2;
    // 0x80035FD4: sb          $zero, 0x12($a1)
    MEM_B(0X12, ctx->r5) = 0;
    // 0x80035FD8: sb          $zero, 0x13($a1)
    MEM_B(0X13, ctx->r5) = 0;
    // 0x80035FDC: sb          $zero, 0x14($a1)
    MEM_B(0X14, ctx->r5) = 0;
    // 0x80035FE0: sb          $v0, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r2;
    // 0x80035FE4: sb          $zero, 0x16($a1)
    MEM_B(0X16, ctx->r5) = 0;
    // 0x80035FE8: sb          $zero, 0x17($a1)
    MEM_B(0X17, ctx->r5) = 0;
    // 0x80035FEC: sb          $t3, 0x1A($a1)
    MEM_B(0X1A, ctx->r5) = ctx->r11;
    // 0x80035FF0: swc1        $f26, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f26.u32l;
    // 0x80035FF4: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80035FF8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80035FFC: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80036000: mul.s       $f6, $f18, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80036004: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80036008: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8003600C: mul.s       $f8, $f16, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x80036010: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80036014: swc1        $f28, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f28.u32l;
    // 0x80036018: mul.s       $f4, $f14, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8003601C: swc1        $f30, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f30.u32l;
    // 0x80036020: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x80036024: swc1        $f22, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f22.u32l;
    // 0x80036028: swc1        $f24, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f24.u32l;
    // 0x8003602C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80036030: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80036034: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80036038: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x8003603C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80036040: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80036044: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036048: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003604C: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80036050: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80036054: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80036058: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8003605C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80036060: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80036064: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80036068: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8003606C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80036070: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80036074: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80036078: nop

    // 0x8003607C: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80036080: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80036084: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80036088: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8003608C: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80036090: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80036094: mul.s       $f8, $f10, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80036098: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003609C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800360A0: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x800360A4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x800360A8: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x800360AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800360B0: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x800360B4: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x800360B8: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800360BC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800360C0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800360C4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800360C8: jr          $ra
    // 0x800360CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800360CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80100000_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100008: jal         0x80101148
    // 0x8010000C: nop

    func_80101148_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x8010000C: nop

    after_0:
    // 0x80100010: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80100014: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100018: sw          $t6, 0x6220($at)
    MEM_W(0X6220, ctx->r1) = ctx->r14;
    // 0x8010001C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100020: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80100024: sw          $t7, 0x6224($at)
    MEM_W(0X6224, ctx->r1) = ctx->r15;
    // 0x80100028: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8010002C: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x80100030: sw          $t8, 0x6228($at)
    MEM_W(0X6228, ctx->r1) = ctx->r24;
    // 0x80100034: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100038: addiu       $t9, $zero, 0xDF
    ctx->r25 = ADD32(0, 0XDF);
    // 0x8010003C: sw          $t9, 0x622C($at)
    MEM_W(0X622C, ctx->r1) = ctx->r25;
    // 0x80100040: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100044: sw          $zero, 0x623C($at)
    MEM_W(0X623C, ctx->r1) = 0;
    // 0x80100048: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8010004C: sw          $zero, 0x6240($at)
    MEM_W(0X6240, ctx->r1) = 0;
    // 0x80100050: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100054: sw          $zero, 0x6230($at)
    MEM_W(0X6230, ctx->r1) = 0;
    // 0x80100058: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8010005C: sw          $zero, 0x6234($at)
    MEM_W(0X6234, ctx->r1) = 0;
    // 0x80100060: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100064: sw          $zero, 0x6244($at)
    MEM_W(0X6244, ctx->r1) = 0;
    // 0x80100068: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8010006C: sw          $zero, 0x6248($at)
    MEM_W(0X6248, ctx->r1) = 0;
    // 0x80100070: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100074: sw          $zero, 0x624C($at)
    MEM_W(0X624C, ctx->r1) = 0;
    // 0x80100078: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010007C: sw          $zero, 0x6200($at)
    MEM_W(0X6200, ctx->r1) = 0;
    // 0x80100080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100084: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100088: sw          $zero, 0x6220($at)
    MEM_W(0X6220, ctx->r1) = 0;
    // 0x8010008C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100090: sw          $zero, 0x6238($at)
    MEM_W(0X6238, ctx->r1) = 0;
    // 0x80100094: jr          $ra
    // 0x80100098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80100098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002B6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B6F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002B6F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002B6F8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8002B6FC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8002B700: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8002B704: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002B708: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002B70C: lbu         $t6, -0x2DD($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2DD);
    // 0x8002B710: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x8002B714: addiu       $t8, $t8, -0x5FEC
    ctx->r24 = ADD32(ctx->r24, -0X5FEC);
    // 0x8002B718: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8002B71C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002B720: lh          $s2, 0x0($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X0);
    // 0x8002B724: lh          $s0, 0x2($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X2);
    // 0x8002B728: lh          $s3, 0x4($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X4);
    // 0x8002B72C: lh          $s1, 0x6($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X6);
    // 0x8002B730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002B734: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002B738: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002B73C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8002B740: jal         0x80029B58
    // 0x8002B744: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80029B58(rdram, ctx);
        goto after_0;
    // 0x8002B744: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_0:
    // 0x8002B748: addu        $a2, $s0, $s1
    ctx->r6 = ADD32(ctx->r16, ctx->r17);
    // 0x8002B74C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8002B750: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002B754: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x8002B758: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002B75C: addiu       $a1, $s2, 0x3
    ctx->r5 = ADD32(ctx->r18, 0X3);
    // 0x8002B760: jal         0x80029B58
    // 0x8002B764: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80029B58(rdram, ctx);
        goto after_1;
    // 0x8002B764: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x8002B768: addu        $a1, $s2, $s3
    ctx->r5 = ADD32(ctx->r18, ctx->r19);
    // 0x8002B76C: addiu       $a2, $s0, 0x6
    ctx->r6 = ADD32(ctx->r16, 0X6);
    // 0x8002B770: addiu       $t0, $s1, -0x5
    ctx->r8 = ADD32(ctx->r17, -0X5);
    // 0x8002B774: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002B778: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8002B77C: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x8002B780: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002B784: jal         0x80029B58
    // 0x8002B788: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x8002B788: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8002B78C: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    // 0x8002B790: addiu       $a3, $s3, 0x2
    ctx->r7 = ADD32(ctx->r19, 0X2);
    // 0x8002B794: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002B798: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002B79C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8002B7A0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8002B7A4: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002B7A8: jal         0x80029B58
    // 0x8002B7AC: addiu       $a2, $s0, -0x1
    ctx->r6 = ADD32(ctx->r16, -0X1);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x8002B7AC: addiu       $a2, $s0, -0x1
    ctx->r6 = ADD32(ctx->r16, -0X1);
    after_3:
    // 0x8002B7B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002B7B4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8002B7B8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002B7BC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002B7C0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002B7C4: jal         0x80029B58
    // 0x8002B7C8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_80029B58(rdram, ctx);
        goto after_4;
    // 0x8002B7C8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x8002B7CC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002B7D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002B7D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002B7D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002B7DC: jal         0x80029B58
    // 0x8002B7E0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x8002B7E0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_5:
    // 0x8002B7E4: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002B7E8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002B7EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002B7F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002B7F4: jal         0x80029B58
    // 0x8002B7F8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x8002B7F8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_6:
    // 0x8002B7FC: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    // 0x8002B800: addiu       $a2, $s0, 0x1
    ctx->r6 = ADD32(ctx->r16, 0X1);
    // 0x8002B804: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002B808: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002B80C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8002B810: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8002B814: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002B818: jal         0x80029B58
    // 0x8002B81C: addiu       $a3, $s3, -0x3
    ctx->r7 = ADD32(ctx->r19, -0X3);
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x8002B81C: addiu       $a3, $s3, -0x3
    ctx->r7 = ADD32(ctx->r19, -0X3);
    after_7:
    // 0x8002B820: addiu       $t4, $s1, -0x4
    ctx->r12 = ADD32(ctx->r17, -0X4);
    // 0x8002B824: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002B828: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002B82C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002B830: addiu       $a2, $s0, 0x2
    ctx->r6 = ADD32(ctx->r16, 0X2);
    // 0x8002B834: jal         0x80029B58
    // 0x8002B838: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_8;
    // 0x8002B838: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8002B83C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8002B840: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002B844: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002B848: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002B84C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8002B850: addiu       $a3, $s3, -0x2
    ctx->r7 = ADD32(ctx->r19, -0X2);
    // 0x8002B854: jal         0x80029B58
    // 0x8002B858: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    func_80029B58(rdram, ctx);
        goto after_9;
    // 0x8002B858: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    after_9:
    // 0x8002B85C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002B860: addiu       $t6, $s1, -0x3
    ctx->r14 = ADD32(ctx->r17, -0X3);
    // 0x8002B864: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002B868: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002B86C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8002B870: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002B874: jal         0x80029B58
    // 0x8002B878: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    func_80029B58(rdram, ctx);
        goto after_10;
    // 0x8002B878: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    after_10:
    // 0x8002B87C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002B880: lbu         $t7, -0x2DD($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2DD);
    // 0x8002B884: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8002B888: addiu       $a0, $s2, 0x6
    ctx->r4 = ADD32(ctx->r18, 0X6);
    // 0x8002B88C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002B890: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8002B894: lw          $a2, -0x6000($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6000);
    // 0x8002B898: jal         0x80030EA0
    // 0x8002B89C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80030EA0(rdram, ctx);
        goto after_11;
    // 0x8002B89C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x8002B8A0: jal         0x8002DF6C
    // 0x8002B8A4: nop

    func_8002DF6C(rdram, ctx);
        goto after_12;
    // 0x8002B8A4: nop

    after_12:
    // 0x8002B8A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B8AC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B8B0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8002B8B4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8002B8B8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8002B8BC: jr          $ra
    // 0x8002B8C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002B8C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80023DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023DF4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80023DF8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80023DFC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80023E00: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80023E04: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80023E08: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80023E0C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80023E10: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80023E14: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80023E18: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80023E1C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80023E20: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80023E24: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80023E28: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80023E2C: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80023E30: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80023E34: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80023E38: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80023E3C: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80023E40: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80023E44: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80023E48: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80023E4C: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x80023E50: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80023E54: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80023E58: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80023E5C: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x80023E60: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80023E64: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023E68: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80023E6C: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80023E70: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80023E74: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x80023E78: jr          $ra
    // 0x80023E7C: nop

    return;
    // 0x80023E7C: nop

;}
RECOMP_FUNC void func_80011860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011860: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80011864: addiu       $a0, $a0, 0x62D0
    ctx->r4 = ADD32(ctx->r4, 0X62D0);
    // 0x80011868: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001186C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80011870: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80011874: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80011878: addiu       $t7, $t7, 0x5BD0
    ctx->r15 = ADD32(ctx->r15, 0X5BD0);
    // 0x8001187C: sltiu       $at, $v0, 0x40
    ctx->r1 = ctx->r2 < 0X40 ? 1 : 0;
    // 0x80011880: beq         $at, $zero, L_800118CC
    if (ctx->r1 == 0) {
        // 0x80011884: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_800118CC;
    }
    // 0x80011884: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80011888: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8001188C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80011890: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80011894: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80011898: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8001189C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x800118A0: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x800118A4: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800118A8: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800118AC: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800118B0: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800118B4: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800118B8: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
    // 0x800118BC: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800118C0: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
    // 0x800118C4: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800118C8: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
L_800118CC:
    // 0x800118CC: jr          $ra
    // 0x800118D0: nop

    return;
    // 0x800118D0: nop

;}
RECOMP_FUNC void func_8001D820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D820: jr          $ra
    // 0x8001D824: nop

    return;
    // 0x8001D824: nop

;}
RECOMP_FUNC void func_80100EE4_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100EE4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80100EE8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80100EEC: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80100EF0: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x80100EF4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80100EF8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80100EFC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80100F00: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x80100F04: bltzl       $t9, L_80100F18
    if (SIGNED(ctx->r25) < 0) {
        // 0x80100F08: lhu         $t0, 0x4C($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X4C);
            goto L_80100F18;
    }
    goto skip_0;
    // 0x80100F08: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
    skip_0:
    // 0x80100F0C: jr          $ra
    // 0x80100F10: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80100F10: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80100F14: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
L_80100F18:
    // 0x80100F18: andi        $a0, $a1, 0x400
    ctx->r4 = ctx->r5 & 0X400;
    // 0x80100F1C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80100F20: beq         $a0, $zero, L_80100F90
    if (ctx->r4 == 0) {
        // 0x80100F24: sh          $t1, 0x4C($v1)
        MEM_H(0X4C, ctx->r3) = ctx->r9;
            goto L_80100F90;
    }
    // 0x80100F24: sh          $t1, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r9;
    // 0x80100F28: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x80100F2C: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80100F30: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80100F34: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80100F38: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80100F3C: andi        $t4, $t1, 0xFFFF
    ctx->r12 = ctx->r9 & 0XFFFF;
    // 0x80100F40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80100F44: slt         $at, $t4, $a3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80100F48: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80100F4C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80100F50: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80100F54: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x80100F58: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80100F5C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80100F60: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80100F64: nop

    // 0x80100F68: subu        $v0, $a1, $t3
    ctx->r2 = SUB32(ctx->r5, ctx->r11);
    // 0x80100F6C: blezl       $v0, L_80100F80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80100F70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80100F80;
    }
    goto skip_1;
    // 0x80100F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80100F74: bnel        $at, $zero, L_80100F84
    if (ctx->r1 != 0) {
        // 0x80100F78: lh          $t5, 0x2E($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X2E);
            goto L_80100F84;
    }
    goto skip_2;
    // 0x80100F78: lh          $t5, 0x2E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2E);
    skip_2:
    // 0x80100F7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100F80:
    // 0x80100F80: lh          $t5, 0x2E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2E);
L_80100F84:
    // 0x80100F84: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80100F88: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80100F8C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_80100F90:
    // 0x80100F90: bnel        $a0, $zero, L_80101004
    if (ctx->r4 != 0) {
        // 0x80100F94: lhu         $t2, 0x4C($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X4C);
            goto L_80101004;
    }
    goto skip_3;
    // 0x80100F94: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
    skip_3:
    // 0x80100F98: lh          $a0, 0xA($v1)
    ctx->r4 = MEM_H(ctx->r3, 0XA);
    // 0x80100F9C: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80100FA0: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80100FA4: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x80100FA8: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80100FAC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80100FB0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80100FB4: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80100FB8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80100FBC: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
    // 0x80100FC0: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80100FC4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80100FC8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80100FCC: nop

    // 0x80100FD0: subu        $v0, $a0, $t8
    ctx->r2 = SUB32(ctx->r4, ctx->r24);
    // 0x80100FD4: blezl       $v0, L_80100FF0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80100FD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80100FF0;
    }
    goto skip_4;
    // 0x80100FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80100FDC: lhu         $t9, 0x4C($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4C);
    // 0x80100FE0: slt         $at, $t9, $a3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80100FE4: bnel        $at, $zero, L_80100FF4
    if (ctx->r1 != 0) {
        // 0x80100FE8: lh          $t0, 0x30($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X30);
            goto L_80100FF4;
    }
    goto skip_5;
    // 0x80100FE8: lh          $t0, 0x30($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X30);
    skip_5:
    // 0x80100FEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100FF0:
    // 0x80100FF0: lh          $t0, 0x30($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X30);
L_80100FF4:
    // 0x80100FF4: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x80100FF8: subu        $t1, $t0, $v0
    ctx->r9 = SUB32(ctx->r8, ctx->r2);
    // 0x80100FFC: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80101000: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
L_80101004:
    // 0x80101004: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80101008: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010100C: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80101010: bne         $at, $zero, L_80101038
    if (ctx->r1 != 0) {
        // 0x80101014: nop
    
            goto L_80101038;
    }
    // 0x80101014: nop

    // 0x80101018: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010101C: sh          $zero, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = 0;
    // 0x80101020: sh          $zero, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = 0;
    // 0x80101024: sh          $zero, 0x30($v1)
    MEM_H(0X30, ctx->r3) = 0;
    // 0x80101028: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8010102C: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80101030: jr          $ra
    // 0x80101034: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80101034: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
L_80101038:
    // 0x80101038: jr          $ra
    // 0x8010103C: nop

    return;
    // 0x8010103C: nop

;}
RECOMP_FUNC void func_80016B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B18: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80016B1C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80016B20: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80016B24: lhu         $t6, 0x4EE0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4EE0);
    // 0x80016B28: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016B2C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80016B30: beq         $t7, $zero, L_80016BE4
    if (ctx->r15 == 0) {
        // 0x80016B34: nop
    
            goto L_80016BE4;
    }
    // 0x80016B34: nop

    // 0x80016B38: lw          $v0, 0x4F04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4F04);
    // 0x80016B3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80016B40: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80016B44: beq         $v0, $at, L_80016BE4
    if (ctx->r2 == ctx->r1) {
        // 0x80016B48: nop
    
            goto L_80016BE4;
    }
    // 0x80016B48: nop

    // 0x80016B4C: lw          $t8, 0x4F1C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F1C);
    // 0x80016B50: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016B54: lhu         $t9, 0x14($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X14);
    // 0x80016B58: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x80016B5C: bne         $t0, $zero, L_80016BE4
    if (ctx->r8 != 0) {
        // 0x80016B60: nop
    
            goto L_80016BE4;
    }
    // 0x80016B60: nop

    // 0x80016B64: lw          $v1, 0x4EE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4EE4);
    // 0x80016B68: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80016B6C: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80016B70: beq         $a0, $v1, L_80016BE4
    if (ctx->r4 == ctx->r3) {
        // 0x80016B74: nop
    
            goto L_80016BE4;
    }
    // 0x80016B74: nop

    // 0x80016B78: beq         $v1, $at, L_80016BE4
    if (ctx->r3 == ctx->r1) {
        // 0x80016B7C: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_80016BE4;
    }
    // 0x80016B7C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80016B80: addiu       $a1, $a1, 0x5368
    ctx->r5 = ADD32(ctx->r5, 0X5368);
    // 0x80016B84: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80016B88: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80016B8C: lw          $t1, 0x4F08($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4F08);
    // 0x80016B90: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80016B94: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80016B98: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x80016B9C: lw          $t2, 0x4F0C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4F0C);
    // 0x80016BA0: addiu       $t3, $zero, 0x108
    ctx->r11 = ADD32(0, 0X108);
    // 0x80016BA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016BA8: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    // 0x80016BAC: addiu       $a2, $a2, -0x4548
    ctx->r6 = ADD32(ctx->r6, -0X4548);
    // 0x80016BB0: sw          $t3, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r11;
    // 0x80016BB4: lw          $v1, 0x10($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X10);
    // 0x80016BB8: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80016BBC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80016BC0: lhu         $t4, 0x2A($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X2A);
    // 0x80016BC4: addiu       $a3, $a3, -0x4D1C
    ctx->r7 = ADD32(ctx->r7, -0X4D1C);
    // 0x80016BC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016BCC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80016BD0: sh          $t5, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r13;
    // 0x80016BD4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80016BD8: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80016BDC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80016BE0: sw          $a0, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r4;
L_80016BE4:
    // 0x80016BE4: jr          $ra
    // 0x80016BE8: nop

    return;
    // 0x80016BE8: nop

;}
RECOMP_FUNC void func_80042884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042884: lbu         $t6, 0x36($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X36);
    // 0x80042888: lbu         $t7, 0x33($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X33);
    // 0x8004288C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x80042890: lbu         $t2, 0x31($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X31);
    // 0x80042894: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80042898: lw          $t1, 0x60($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X60);
    // 0x8004289C: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800428A0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800428A4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800428A8: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x800428AC: lbu         $t7, 0xD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XD);
    // 0x800428B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800428B4: nop

    // 0x800428B8: nop

    // 0x800428BC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800428C0: lh          $t9, 0x32($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X32);
    // 0x800428C4: mflo        $v1
    ctx->r3 = lo;
    // 0x800428C8: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800428CC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800428D0: multu       $t5, $t7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800428D4: mflo        $t8
    ctx->r24 = lo;
    // 0x800428D8: nop

    // 0x800428DC: nop

    // 0x800428E0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800428E4: mflo        $a2
    ctx->r6 = lo;
    // 0x800428E8: sra         $t0, $a2, 14
    ctx->r8 = S32(SIGNED(ctx->r6) >> 14);
    // 0x800428EC: nop

    // 0x800428F0: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800428F4: mflo        $v1
    ctx->r3 = lo;
    // 0x800428F8: srl         $t2, $v1, 15
    ctx->r10 = S32(U32(ctx->r3) >> 15);
    // 0x800428FC: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80042900: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80042904: jr          $ra
    // 0x80042908: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x80042908: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void func_8000835C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000835C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80008360: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80008364: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80008368: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8000836C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80008370: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80008374: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80008378: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8000837C: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80008380: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80008384: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80008388: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8000838C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80008390: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80008394: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80008398: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8000839C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800083A0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800083A4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800083A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800083AC: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800083B0: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800083B4: lwc1        $f16, 0x28($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X28);
    // 0x800083B8: lwc1        $f18, 0x24($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X24);
    // 0x800083BC: add.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800083C0: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800083C4: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800083C8: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x800083CC: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800083D0: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800083D4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800083D8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800083DC: add.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800083E0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800083E4: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800083E8: sub.s       $f20, $f28, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x800083EC: add.s       $f24, $f16, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x800083F0: sub.s       $f22, $f30, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f6.fl;
    // 0x800083F4: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x800083F8: nop

    // 0x800083FC: bc1f        L_8000849C
    if (!c1cs) {
        // 0x80008400: nop
    
            goto L_8000849C;
    }
    // 0x80008400: nop

    // 0x80008404: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x80008408: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8000840C: nop

    // 0x80008410: bc1f        L_8000849C
    if (!c1cs) {
        // 0x80008414: nop
    
            goto L_8000849C;
    }
    // 0x80008414: nop

    // 0x80008418: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x8000841C: nop

    // 0x80008420: bc1f        L_8000849C
    if (!c1cs) {
        // 0x80008424: nop
    
            goto L_8000849C;
    }
    // 0x80008424: nop

    // 0x80008428: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8000842C: nop

    // 0x80008430: bc1f        L_8000849C
    if (!c1cs) {
        // 0x80008434: nop
    
            goto L_8000849C;
    }
    // 0x80008434: nop

    // 0x80008438: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8000843C: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x80008440: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80008444: jal         0x80034F60
    // 0x80008448: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80008448: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x8000844C: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80008450: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80008454: bc1f        L_8000849C
    if (!c1cs) {
        // 0x80008458: nop
    
            goto L_8000849C;
    }
    // 0x80008458: nop

    // 0x8000845C: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80008460: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008464: lwc1        $f6, -0x4534($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x80008468: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8000846C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008470: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80008474: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008478: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8000847C: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80008480: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80008484: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
    // 0x80008488: lwc1        $f18, -0x452C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X452C);
    // 0x8000848C: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80008490: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x80008494: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008498: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
L_8000849C:
    // 0x8000849C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800084A0: lw          $s1, -0x4318($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4318);
    // 0x800084A4: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x800084A8: beq         $s1, $zero, L_800085A0
    if (ctx->r17 == 0) {
        // 0x800084AC: nop
    
            goto L_800085A0;
    }
    // 0x800084AC: nop

    // 0x800084B0: bne         $s4, $zero, L_800085A0
    if (ctx->r20 != 0) {
        // 0x800084B4: addiu       $s2, $s2, -0x4310
        ctx->r18 = ADD32(ctx->r18, -0X4310);
            goto L_800085A0;
    }
    // 0x800084B4: addiu       $s2, $s2, -0x4310
    ctx->r18 = ADD32(ctx->r18, -0X4310);
    // 0x800084B8: beq         $s1, $zero, L_800085A0
    if (ctx->r17 == 0) {
        // 0x800084BC: nop
    
            goto L_800085A0;
    }
    // 0x800084BC: nop

    // 0x800084C0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_800084C4:
    // 0x800084C4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800084C8: beq         $s0, $s3, L_80008590
    if (ctx->r16 == ctx->r19) {
        // 0x800084CC: nop
    
            goto L_80008590;
    }
    // 0x800084CC: nop

    // 0x800084D0: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800084D4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800084D8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800084DC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800084E0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800084E4: sub.s       $f20, $f28, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f10.fl;
    // 0x800084E8: sub.s       $f22, $f30, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x800084EC: add.s       $f24, $f6, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800084F0: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x800084F4: nop

    // 0x800084F8: bc1f        L_80008590
    if (!c1cs) {
        // 0x800084FC: nop
    
            goto L_80008590;
    }
    // 0x800084FC: nop

    // 0x80008500: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x80008504: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80008508: nop

    // 0x8000850C: bc1f        L_80008590
    if (!c1cs) {
        // 0x80008510: nop
    
            goto L_80008590;
    }
    // 0x80008510: nop

    // 0x80008514: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x80008518: nop

    // 0x8000851C: bc1f        L_80008590
    if (!c1cs) {
        // 0x80008520: nop
    
            goto L_80008590;
    }
    // 0x80008520: nop

    // 0x80008524: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80008528: nop

    // 0x8000852C: bc1f        L_80008590
    if (!c1cs) {
        // 0x80008530: nop
    
            goto L_80008590;
    }
    // 0x80008530: nop

    // 0x80008534: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80008538: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x8000853C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80008540: jal         0x80034F60
    // 0x80008544: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80008544: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80008548: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8000854C: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80008550: bc1f        L_80008590
    if (!c1cs) {
        // 0x80008554: nop
    
            goto L_80008590;
    }
    // 0x80008554: nop

    // 0x80008558: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8000855C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80008560: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80008564: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80008568: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8000856C: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80008570: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80008574: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80008578: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    // 0x8000857C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80008580: lwc1        $f16, 0x8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80008584: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80008588: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000858C: swc1        $f18, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f18.u32l;
L_80008590:
    // 0x80008590: bne         $s4, $zero, L_800085A0
    if (ctx->r20 != 0) {
        // 0x80008594: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800085A0;
    }
    // 0x80008594: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80008598: bnel        $s1, $zero, L_800084C4
    if (ctx->r17 != 0) {
        // 0x8000859C: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_800084C4;
    }
    goto skip_0;
    // 0x8000859C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_800085A0:
    // 0x800085A0: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800085A4: lw          $s1, 0x4F38($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4F38);
    // 0x800085A8: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x800085AC: beql        $s1, $zero, L_800086A8
    if (ctx->r17 == 0) {
        // 0x800085B0: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_800086A8;
    }
    goto skip_1;
    // 0x800085B0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x800085B4: bne         $s4, $zero, L_800086A4
    if (ctx->r20 != 0) {
        // 0x800085B8: addiu       $s2, $s2, 0x4F40
        ctx->r18 = ADD32(ctx->r18, 0X4F40);
            goto L_800086A4;
    }
    // 0x800085B8: addiu       $s2, $s2, 0x4F40
    ctx->r18 = ADD32(ctx->r18, 0X4F40);
    // 0x800085BC: beql        $s1, $zero, L_800086A8
    if (ctx->r17 == 0) {
        // 0x800085C0: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_800086A8;
    }
    goto skip_2;
    // 0x800085C0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x800085C4: cvt.d.s     $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f26.d = CVT_D_S(ctx->f14.fl);
    // 0x800085C8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_800085CC:
    // 0x800085CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800085D0: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800085D4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800085D8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800085DC: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800085E0: sub.s       $f20, $f28, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x800085E4: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800085E8: sub.s       $f22, $f30, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f6.fl;
    // 0x800085EC: add.d       $f16, $f26, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f26.d + ctx->f10.d;
    // 0x800085F0: cvt.s.d     $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f24.fl = CVT_S_D(ctx->f16.d);
    // 0x800085F4: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x800085F8: nop

    // 0x800085FC: bc1f        L_80008694
    if (!c1cs) {
        // 0x80008600: nop
    
            goto L_80008694;
    }
    // 0x80008600: nop

    // 0x80008604: neg.s       $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = -ctx->f24.fl;
    // 0x80008608: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8000860C: nop

    // 0x80008610: bc1f        L_80008694
    if (!c1cs) {
        // 0x80008614: nop
    
            goto L_80008694;
    }
    // 0x80008614: nop

    // 0x80008618: c.lt.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl < ctx->f24.fl;
    // 0x8000861C: nop

    // 0x80008620: bc1f        L_80008694
    if (!c1cs) {
        // 0x80008624: nop
    
            goto L_80008694;
    }
    // 0x80008624: nop

    // 0x80008628: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8000862C: nop

    // 0x80008630: bc1f        L_80008694
    if (!c1cs) {
        // 0x80008634: nop
    
            goto L_80008694;
    }
    // 0x80008634: nop

    // 0x80008638: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8000863C: nop

    // 0x80008640: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80008644: jal         0x80034F60
    // 0x80008648: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x80008648: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_2:
    // 0x8000864C: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80008650: nop

    // 0x80008654: bc1f        L_80008694
    if (!c1cs) {
        // 0x80008658: nop
    
            goto L_80008694;
    }
    // 0x80008658: nop

    // 0x8000865C: div.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80008660: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80008664: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80008668: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000866C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008670: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80008674: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80008678: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000867C: swc1        $f16, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f16.u32l;
    // 0x80008680: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80008684: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80008688: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x8000868C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008690: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
L_80008694:
    // 0x80008694: bne         $s4, $zero, L_800086A4
    if (ctx->r20 != 0) {
        // 0x80008698: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800086A4;
    }
    // 0x80008698: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000869C: bnel        $s1, $zero, L_800085CC
    if (ctx->r17 != 0) {
        // 0x800086A0: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_800085CC;
    }
    goto skip_3;
    // 0x800086A0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_800086A4:
    // 0x800086A4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_800086A8:
    // 0x800086A8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800086AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800086B0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800086B4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800086B8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800086BC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800086C0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800086C4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800086C8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800086CC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800086D0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800086D4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800086D8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800086DC: jr          $ra
    // 0x800086E0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800086E0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800074A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800074A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800074A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800074A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800074AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800074B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800074B4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800074B8: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x800074BC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800074C0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800074C4: bnel        $t7, $zero, L_80007618
    if (ctx->r15 != 0) {
        // 0x800074C8: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80007618;
    }
    goto skip_0;
    // 0x800074C8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800074CC: lhu         $t8, 0x4F10($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X4F10);
    // 0x800074D0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800074D4: addiu       $v0, $v0, -0x43EC
    ctx->r2 = ADD32(ctx->r2, -0X43EC);
    // 0x800074D8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800074DC: beq         $t9, $zero, L_80007584
    if (ctx->r25 == 0) {
        // 0x800074E0: lui         $at, 0x4089
        ctx->r1 = S32(0X4089 << 16);
            goto L_80007584;
    }
    // 0x800074E0: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x800074E4: lui         $at, 0x4069
    ctx->r1 = S32(0X4069 << 16);
    // 0x800074E8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800074EC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800074F0: addiu       $v0, $v0, -0x43F0
    ctx->r2 = ADD32(ctx->r2, -0X43F0);
    // 0x800074F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800074F8: lwc1        $f2, -0x45A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X45A4);
    // 0x800074FC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80007500: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80007504: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80007508: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8000750C: addiu       $v1, $v1, -0x43E8
    ctx->r3 = ADD32(ctx->r3, -0X43E8);
    // 0x80007510: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80007514: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80007518: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8000751C: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80007520: nop

    // 0x80007524: bc1fl       L_8000753C
    if (!c1cs) {
        // 0x80007528: lwc1        $f18, 0x0($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8000753C;
    }
    goto skip_1;
    // 0x80007528: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8000752C: sub.d       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f10.d = ctx->f0.d - ctx->f12.d;
    // 0x80007530: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80007534: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80007538: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
L_8000753C:
    // 0x8000753C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80007540: ldc1        $f12, 0x10F8($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X10F8);
    // 0x80007544: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80007548: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8000754C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80007550: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80007554: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80007558: nop

    // 0x8000755C: bc1fl       L_80007618
    if (!c1cs) {
        // 0x80007560: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80007618;
    }
    goto skip_2;
    // 0x80007560: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80007564: sub.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = ctx->f0.d - ctx->f12.d;
    // 0x80007568: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8000756C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80007570: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80007574: lhu         $t1, 0x2C($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X2C);
    // 0x80007578: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000757C: b           L_80007614
    // 0x80007580: sh          $t2, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r10;
        goto L_80007614;
    // 0x80007580: sh          $t2, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r10;
L_80007584:
    // 0x80007584: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80007588: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000758C: lwc1        $f2, -0x45A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X45A4);
    // 0x80007590: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80007594: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80007598: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000759C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800075A0: addiu       $v1, $v1, -0x43E4
    ctx->r3 = ADD32(ctx->r3, -0X43E4);
    // 0x800075A4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800075A8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800075AC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800075B0: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x800075B4: nop

    // 0x800075B8: bc1fl       L_800075D0
    if (!c1cs) {
        // 0x800075BC: lwc1        $f10, 0x0($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800075D0;
    }
    goto skip_3;
    // 0x800075BC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800075C0: sub.d       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = ctx->f0.d - ctx->f12.d;
    // 0x800075C4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800075C8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800075CC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
L_800075D0:
    // 0x800075D0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800075D4: ldc1        $f12, 0x1100($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1100);
    // 0x800075D8: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800075DC: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x800075E0: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800075E4: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x800075E8: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x800075EC: nop

    // 0x800075F0: bc1fl       L_80007618
    if (!c1cs) {
        // 0x800075F4: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80007618;
    }
    goto skip_4;
    // 0x800075F4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800075F8: sub.d       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f0.d - ctx->f12.d;
    // 0x800075FC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80007600: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80007604: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80007608: lhu         $t3, 0x2C($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2C);
    // 0x8000760C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80007610: sh          $t4, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r12;
L_80007614:
    // 0x80007614: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80007618:
    // 0x80007618: lw          $t6, 0x64($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X64);
    // 0x8000761C: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x80007620: slti        $at, $t7, 0x1F4
    ctx->r1 = SIGNED(ctx->r15) < 0X1F4 ? 1 : 0;
    // 0x80007624: beql        $at, $zero, L_800076D4
    if (ctx->r1 == 0) {
        // 0x80007628: lw          $t4, 0x10($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X10);
            goto L_800076D4;
    }
    goto skip_5;
    // 0x80007628: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    skip_5:
    // 0x8000762C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80007630: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80007634: addiu       $t0, $t0, 0x3ECC
    ctx->r8 = ADD32(ctx->r8, 0X3ECC);
    // 0x80007638: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
    // 0x8000763C: lhu         $a1, 0x28($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X28);
    // 0x80007640: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80007644: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x80007648: lhu         $a3, 0x0($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X0);
    // 0x8000764C: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80007650: bne         $at, $zero, L_800076C4
    if (ctx->r1 != 0) {
        // 0x80007654: subu        $t2, $a1, $a3
        ctx->r10 = SUB32(ctx->r5, ctx->r7);
            goto L_800076C4;
    }
    // 0x80007654: subu        $t2, $a1, $a3
    ctx->r10 = SUB32(ctx->r5, ctx->r7);
    // 0x80007658: sh          $t2, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r10;
    // 0x8000765C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80007660: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80007664: addiu       $t5, $zero, 0x1F4
    ctx->r13 = ADD32(0, 0X1F4);
    // 0x80007668: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x8000766C: lhu         $a2, 0x6($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X6);
    // 0x80007670: addiu       $t4, $a2, 0x1
    ctx->r12 = ADD32(ctx->r6, 0X1);
    // 0x80007674: slti        $at, $t4, 0x1F5
    ctx->r1 = SIGNED(ctx->r12) < 0X1F5 ? 1 : 0;
    // 0x80007678: bnel        $at, $zero, L_80007690
    if (ctx->r1 != 0) {
        // 0x8000767C: addu        $t7, $a2, $a0
        ctx->r15 = ADD32(ctx->r6, ctx->r4);
            goto L_80007690;
    }
    goto skip_6;
    // 0x8000767C: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
    skip_6:
    // 0x80007680: subu        $a0, $t5, $a2
    ctx->r4 = SUB32(ctx->r13, ctx->r6);
    // 0x80007684: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80007688: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8000768C: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
L_80007690:
    // 0x80007690: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x80007694: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80007698: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x8000769C: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x800076A0: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x800076A4: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x800076A8: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800076AC: lbu         $a3, 0x30($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X30);
    // 0x800076B0: slti        $at, $a3, 0x36
    ctx->r1 = SIGNED(ctx->r7) < 0X36 ? 1 : 0;
    // 0x800076B4: beq         $at, $zero, L_800076C4
    if (ctx->r1 == 0) {
        // 0x800076B8: addiu       $t2, $a3, 0x1
        ctx->r10 = ADD32(ctx->r7, 0X1);
            goto L_800076C4;
    }
    // 0x800076B8: addiu       $t2, $a3, 0x1
    ctx->r10 = ADD32(ctx->r7, 0X1);
    // 0x800076BC: sb          $t2, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r10;
    // 0x800076C0: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_800076C4:
    // 0x800076C4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800076C8: b           L_800076EC
    // 0x800076CC: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
        goto L_800076EC;
    // 0x800076CC: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x800076D0: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
L_800076D4:
    // 0x800076D4: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x800076D8: addiu       $t0, $t0, 0x3ECC
    ctx->r8 = ADD32(ctx->r8, 0X3ECC);
    // 0x800076DC: sh          $zero, 0x28($t4)
    MEM_H(0X28, ctx->r12) = 0;
    // 0x800076E0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800076E4: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800076E8: lw          $v1, 0x64($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X64);
L_800076EC:
    // 0x800076EC: lhu         $t6, 0xA($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XA);
    // 0x800076F0: slti        $at, $t6, 0x1F4
    ctx->r1 = SIGNED(ctx->r14) < 0X1F4 ? 1 : 0;
    // 0x800076F4: beql        $at, $zero, L_8000779C
    if (ctx->r1 == 0) {
        // 0x800076F8: sh          $zero, 0x2A($v0)
        MEM_H(0X2A, ctx->r2) = 0;
            goto L_8000779C;
    }
    goto skip_7;
    // 0x800076F8: sh          $zero, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = 0;
    skip_7:
    // 0x800076FC: lbu         $t7, 0x31($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X31);
    // 0x80007700: lhu         $a1, 0x2A($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2A);
    // 0x80007704: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80007708: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8000770C: lhu         $a3, 0x0($t9)
    ctx->r7 = MEM_HU(ctx->r25, 0X0);
    // 0x80007710: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x80007714: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80007718: bne         $at, $zero, L_8000778C
    if (ctx->r1 != 0) {
        // 0x8000771C: subu        $t2, $a1, $t1
        ctx->r10 = SUB32(ctx->r5, ctx->r9);
            goto L_8000778C;
    }
    // 0x8000771C: subu        $t2, $a1, $t1
    ctx->r10 = SUB32(ctx->r5, ctx->r9);
    // 0x80007720: sh          $t2, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r10;
    // 0x80007724: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80007728: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000772C: addiu       $t5, $zero, 0x1F4
    ctx->r13 = ADD32(0, 0X1F4);
    // 0x80007730: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x80007734: lhu         $a2, 0xA($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XA);
    // 0x80007738: addiu       $t4, $a2, 0x1
    ctx->r12 = ADD32(ctx->r6, 0X1);
    // 0x8000773C: slti        $at, $t4, 0x1F5
    ctx->r1 = SIGNED(ctx->r12) < 0X1F5 ? 1 : 0;
    // 0x80007740: bnel        $at, $zero, L_80007758
    if (ctx->r1 != 0) {
        // 0x80007744: addu        $t7, $a2, $a0
        ctx->r15 = ADD32(ctx->r6, ctx->r4);
            goto L_80007758;
    }
    goto skip_8;
    // 0x80007744: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
    skip_8:
    // 0x80007748: subu        $a0, $t5, $a2
    ctx->r4 = SUB32(ctx->r13, ctx->r6);
    // 0x8000774C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80007750: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80007754: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
L_80007758:
    // 0x80007758: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x8000775C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80007760: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x80007764: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x80007768: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x8000776C: sh          $t1, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r9;
    // 0x80007770: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80007774: lbu         $a3, 0x31($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X31);
    // 0x80007778: slti        $at, $a3, 0x36
    ctx->r1 = SIGNED(ctx->r7) < 0X36 ? 1 : 0;
    // 0x8000777C: beq         $at, $zero, L_8000778C
    if (ctx->r1 == 0) {
        // 0x80007780: addiu       $t2, $a3, 0x1
        ctx->r10 = ADD32(ctx->r7, 0X1);
            goto L_8000778C;
    }
    // 0x80007780: addiu       $t2, $a3, 0x1
    ctx->r10 = ADD32(ctx->r7, 0X1);
    // 0x80007784: sb          $t2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r10;
    // 0x80007788: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_8000778C:
    // 0x8000778C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80007790: b           L_800077A8
    // 0x80007794: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
        goto L_800077A8;
    // 0x80007794: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x80007798: sh          $zero, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = 0;
L_8000779C:
    // 0x8000779C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800077A0: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800077A4: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
L_800077A8:
    // 0x800077A8: lhu         $t5, 0xC($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XC);
    // 0x800077AC: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x800077B0: beql        $at, $zero, L_80007840
    if (ctx->r1 == 0) {
        // 0x800077B4: sh          $zero, 0x2C($v0)
        MEM_H(0X2C, ctx->r2) = 0;
            goto L_80007840;
    }
    goto skip_9;
    // 0x800077B4: sh          $zero, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = 0;
    skip_9:
    // 0x800077B8: lbu         $t6, 0x32($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X32);
    // 0x800077BC: lhu         $a2, 0x2C($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X2C);
    // 0x800077C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800077C4: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x800077C8: lhu         $a3, 0x0($t8)
    ctx->r7 = MEM_HU(ctx->r24, 0X0);
    // 0x800077CC: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800077D0: bne         $at, $zero, L_80007830
    if (ctx->r1 != 0) {
        // 0x800077D4: subu        $t9, $a2, $a3
        ctx->r25 = SUB32(ctx->r6, ctx->r7);
            goto L_80007830;
    }
    // 0x800077D4: subu        $t9, $a2, $a3
    ctx->r25 = SUB32(ctx->r6, ctx->r7);
    // 0x800077D8: sh          $t9, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r25;
    // 0x800077DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800077E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800077E4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800077E8: lw          $v1, 0x64($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X64);
    // 0x800077EC: lhu         $a1, 0xC($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XC);
    // 0x800077F0: addiu       $t2, $a1, 0x1
    ctx->r10 = ADD32(ctx->r5, 0X1);
    // 0x800077F4: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x800077F8: bnel        $at, $zero, L_80007810
    if (ctx->r1 != 0) {
        // 0x800077FC: addu        $t5, $a1, $a0
        ctx->r13 = ADD32(ctx->r5, ctx->r4);
            goto L_80007810;
    }
    goto skip_10;
    // 0x800077FC: addu        $t5, $a1, $a0
    ctx->r13 = ADD32(ctx->r5, ctx->r4);
    skip_10:
    // 0x80007800: subu        $a0, $t3, $a1
    ctx->r4 = SUB32(ctx->r11, ctx->r5);
    // 0x80007804: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80007808: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8000780C: addu        $t5, $a1, $a0
    ctx->r13 = ADD32(ctx->r5, ctx->r4);
L_80007810:
    // 0x80007810: sh          $t5, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r13;
    // 0x80007814: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80007818: lbu         $a2, 0x32($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X32);
    // 0x8000781C: slti        $at, $a2, 0x36
    ctx->r1 = SIGNED(ctx->r6) < 0X36 ? 1 : 0;
    // 0x80007820: beq         $at, $zero, L_80007830
    if (ctx->r1 == 0) {
        // 0x80007824: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_80007830;
    }
    // 0x80007824: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x80007828: sb          $t6, 0x32($v0)
    MEM_B(0X32, ctx->r2) = ctx->r14;
    // 0x8000782C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_80007830:
    // 0x80007830: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80007834: b           L_8000784C
    // 0x80007838: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
        goto L_8000784C;
    // 0x80007838: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x8000783C: sh          $zero, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = 0;
L_80007840:
    // 0x80007840: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80007844: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80007848: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
L_8000784C:
    // 0x8000784C: lhu         $t9, 0xE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XE);
    // 0x80007850: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x80007854: beql        $at, $zero, L_800078DC
    if (ctx->r1 == 0) {
        // 0x80007858: sh          $zero, 0x2E($v0)
        MEM_H(0X2E, ctx->r2) = 0;
            goto L_800078DC;
    }
    goto skip_11;
    // 0x80007858: sh          $zero, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = 0;
    skip_11:
    // 0x8000785C: lbu         $t1, 0x33($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X33);
    // 0x80007860: lhu         $a2, 0x2E($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X2E);
    // 0x80007864: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80007868: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8000786C: lhu         $a3, 0x0($t3)
    ctx->r7 = MEM_HU(ctx->r11, 0X0);
    // 0x80007870: sll         $t4, $a3, 1
    ctx->r12 = S32(ctx->r7 << 1);
    // 0x80007874: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80007878: bne         $at, $zero, L_800078DC
    if (ctx->r1 != 0) {
        // 0x8000787C: subu        $t5, $a2, $t4
        ctx->r13 = SUB32(ctx->r6, ctx->r12);
            goto L_800078DC;
    }
    // 0x8000787C: subu        $t5, $a2, $t4
    ctx->r13 = SUB32(ctx->r6, ctx->r12);
    // 0x80007880: sh          $t5, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r13;
    // 0x80007884: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80007888: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000788C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80007890: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x80007894: lhu         $a1, 0xE($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0XE);
    // 0x80007898: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8000789C: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x800078A0: bnel        $at, $zero, L_800078B8
    if (ctx->r1 != 0) {
        // 0x800078A4: addu        $t1, $a1, $a0
        ctx->r9 = ADD32(ctx->r5, ctx->r4);
            goto L_800078B8;
    }
    goto skip_12;
    // 0x800078A4: addu        $t1, $a1, $a0
    ctx->r9 = ADD32(ctx->r5, ctx->r4);
    skip_12:
    // 0x800078A8: subu        $a0, $t8, $a1
    ctx->r4 = SUB32(ctx->r24, ctx->r5);
    // 0x800078AC: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x800078B0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800078B4: addu        $t1, $a1, $a0
    ctx->r9 = ADD32(ctx->r5, ctx->r4);
L_800078B8:
    // 0x800078B8: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
    // 0x800078BC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800078C0: lbu         $a2, 0x33($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X33);
    // 0x800078C4: slti        $at, $a2, 0x36
    ctx->r1 = SIGNED(ctx->r6) < 0X36 ? 1 : 0;
    // 0x800078C8: beq         $at, $zero, L_800078DC
    if (ctx->r1 == 0) {
        // 0x800078CC: addiu       $t2, $a2, 0x1
        ctx->r10 = ADD32(ctx->r6, 0X1);
            goto L_800078DC;
    }
    // 0x800078CC: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
    // 0x800078D0: b           L_800078DC
    // 0x800078D4: sb          $t2, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r10;
        goto L_800078DC;
    // 0x800078D4: sb          $t2, 0x33($v0)
    MEM_B(0X33, ctx->r2) = ctx->r10;
    // 0x800078D8: sh          $zero, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = 0;
L_800078DC:
    // 0x800078DC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800078E0: addiu       $a3, $a3, -0x4D1C
    ctx->r7 = ADD32(ctx->r7, -0X4D1C);
    // 0x800078E4: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800078E8: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x800078EC: bnel        $t4, $zero, L_800079B8
    if (ctx->r12 != 0) {
        // 0x800078F0: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_800079B8;
    }
    goto skip_13;
    // 0x800078F0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_13:
    // 0x800078F4: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x800078F8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800078FC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80007900: lbu         $a0, 0x34($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X34);
    // 0x80007904: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x80007908: slti        $at, $a0, 0x62
    ctx->r1 = SIGNED(ctx->r4) < 0X62 ? 1 : 0;
    // 0x8000790C: bne         $at, $zero, L_8000791C
    if (ctx->r1 != 0) {
        // 0x80007910: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8000791C;
    }
    // 0x80007910: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80007914: b           L_800079B4
    // 0x80007918: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
        goto L_800079B4;
    // 0x80007918: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
L_8000791C:
    // 0x8000791C: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80007920: lw          $a2, 0x3D3C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3D3C);
    // 0x80007924: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    // 0x80007928: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x8000792C: bne         $at, $zero, L_800079B4
    if (ctx->r1 != 0) {
        // 0x80007930: subu        $t8, $a1, $a2
        ctx->r24 = SUB32(ctx->r5, ctx->r6);
            goto L_800079B4;
    }
    // 0x80007930: subu        $t8, $a1, $a2
    ctx->r24 = SUB32(ctx->r5, ctx->r6);
    // 0x80007934: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x80007938: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8000793C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80007940: lbu         $a0, 0x34($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X34);
    // 0x80007944: slti        $at, $a0, 0x62
    ctx->r1 = SIGNED(ctx->r4) < 0X62 ? 1 : 0;
    // 0x80007948: beq         $at, $zero, L_80007958
    if (ctx->r1 == 0) {
        // 0x8000794C: addiu       $t9, $a0, 0x1
        ctx->r25 = ADD32(ctx->r4, 0X1);
            goto L_80007958;
    }
    // 0x8000794C: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x80007950: sb          $t9, 0x34($v0)
    MEM_B(0X34, ctx->r2) = ctx->r25;
    // 0x80007954: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_80007958:
    // 0x80007958: addiu       $v1, $v0, 0x24
    ctx->r3 = ADD32(ctx->r2, 0X24);
    // 0x8000795C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80007960: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80007964: bnel        $a0, $t1, L_80007994
    if (ctx->r4 != ctx->r9) {
        // 0x80007968: lw          $t5, 0x0($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X0);
            goto L_80007994;
    }
    goto skip_14;
    // 0x80007968: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    skip_14:
    // 0x8000796C: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x80007970: bnel        $a0, $t2, L_80007994
    if (ctx->r4 != ctx->r10) {
        // 0x80007974: lw          $t5, 0x0($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X0);
            goto L_80007994;
    }
    goto skip_15;
    // 0x80007974: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    skip_15:
    // 0x80007978: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x8000797C: bnel        $a0, $t3, L_80007994
    if (ctx->r4 != ctx->r11) {
        // 0x80007980: lw          $t5, 0x0($a3)
        ctx->r13 = MEM_W(ctx->r7, 0X0);
            goto L_80007994;
    }
    goto skip_16;
    // 0x80007980: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    skip_16:
    // 0x80007984: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x80007988: beql        $a0, $t4, L_800079B8
    if (ctx->r4 == ctx->r12) {
        // 0x8000798C: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_800079B8;
    }
    goto skip_17;
    // 0x8000798C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_17:
    // 0x80007990: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
L_80007994:
    // 0x80007994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80007998: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8000799C: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x800079A0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800079A4: jal         0x800268D4
    // 0x800079A8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    func_800268D4(rdram, ctx);
        goto after_0;
    // 0x800079A8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    after_0:
    // 0x800079AC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800079B0: addiu       $a3, $a3, -0x4D1C
    ctx->r7 = ADD32(ctx->r7, -0X4D1C);
L_800079B4:
    // 0x800079B4: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
L_800079B8:
    // 0x800079B8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800079BC: andi        $t8, $t7, 0xA
    ctx->r24 = ctx->r15 & 0XA;
    // 0x800079C0: bnel        $t8, $zero, L_80007A34
    if (ctx->r24 != 0) {
        // 0x800079C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80007A34;
    }
    goto skip_18;
    // 0x800079C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x800079C8: lw          $a0, -0x4590($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4590);
    // 0x800079CC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800079D0: beql        $a0, $at, L_80007A34
    if (ctx->r4 == ctx->r1) {
        // 0x800079D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80007A34;
    }
    goto skip_19;
    // 0x800079D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_19:
    // 0x800079D8: jal         0x800120C0
    // 0x800079DC: nop

    func_800120C0(rdram, ctx);
        goto after_1;
    // 0x800079DC: nop

    after_1:
    // 0x800079E0: jal         0x8002E768
    // 0x800079E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002E768(rdram, ctx);
        goto after_2;
    // 0x800079E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800079E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800079EC: jal         0x800212A0
    // 0x800079F0: lbu         $a0, -0x458D($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X458D);
    func_800212A0(rdram, ctx);
        goto after_3;
    // 0x800079F0: lbu         $a0, -0x458D($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X458D);
    after_3:
    // 0x800079F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800079F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800079FC: sw          $t9, -0x4590($at)
    MEM_W(-0X4590, ctx->r1) = ctx->r25;
    // 0x80007A00: lhu         $t1, 0x8($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X8);
    // 0x80007A04: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80007A08: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80007A0C: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x80007A10: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x80007A14: lw          $t3, -0x4D1C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4D1C);
    // 0x80007A18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80007A1C: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80007A20: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x80007A24: sw          $t4, -0x4D1C($at)
    MEM_W(-0X4D1C, ctx->r1) = ctx->r12;
    // 0x80007A28: jal         0x800268D4
    // 0x80007A2C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_4;
    // 0x80007A2C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_4:
    // 0x80007A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80007A34:
    // 0x80007A34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80007A38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80007A3C: jr          $ra
    // 0x80007A40: nop

    return;
    // 0x80007A40: nop

    // 0x80007A44: nop

    // 0x80007A48: nop

    // 0x80007A4C: nop

;}
RECOMP_FUNC void func_800152E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800152E4: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x800152E8: beql        $v0, $zero, L_800152F8
    if (ctx->r2 == 0) {
        // 0x800152EC: lwc1        $f4, 0x0($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
            goto L_800152F8;
    }
    goto skip_0;
    // 0x800152EC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x800152F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800152F4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
L_800152F8:
    // 0x800152F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800152FC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80015300: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80015304: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80015308: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x8001530C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80015310: bnel        $v1, $at, L_8001533C
    if (ctx->r3 != ctx->r1) {
        // 0x80015314: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001533C;
    }
    goto skip_1;
    // 0x80015314: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x80015318: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001531C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80015320: lw          $t6, 0x68($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X68);
    // 0x80015324: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80015328: lwc1        $f18, 0x94($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X94);
    // 0x8001532C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80015330: jr          $ra
    // 0x80015334: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80015334: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80015338: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8001533C:
    // 0x8001533C: bne         $v1, $at, L_80015360
    if (ctx->r3 != ctx->r1) {
        // 0x80015340: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80015360;
    }
    // 0x80015340: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80015344: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015348: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8001534C: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80015350: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80015354: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80015358: jr          $ra
    // 0x8001535C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8001535C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
L_80015360:
    // 0x80015360: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80015364: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80015368: jr          $ra
    // 0x8001536C: nop

    return;
    // 0x8001536C: nop

;}
RECOMP_FUNC void func_8000DB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB7C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000DB80: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000DB84: lw          $t6, 0x4E60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4E60);
    // 0x8000DB88: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000DB8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000DB90: beq         $t6, $zero, L_8000DBB0
    if (ctx->r14 == 0) {
        // 0x8000DB94: addiu       $v1, $v1, 0x4E60
        ctx->r3 = ADD32(ctx->r3, 0X4E60);
            goto L_8000DBB0;
    }
    // 0x8000DB94: addiu       $v1, $v1, 0x4E60
    ctx->r3 = ADD32(ctx->r3, 0X4E60);
    // 0x8000DB98: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8000DB9C:
    // 0x8000DB9C: beq         $v0, $zero, L_8000DBB0
    if (ctx->r2 == 0) {
        // 0x8000DBA0: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_8000DBB0;
    }
    // 0x8000DBA0: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8000DBA4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000DBA8: bnel        $t7, $zero, L_8000DB9C
    if (ctx->r15 != 0) {
        // 0x8000DBAC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8000DB9C;
    }
    goto skip_0;
    // 0x8000DBAC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
L_8000DBB0:
    // 0x8000DBB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000DBB4: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8000DBB8: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8000DBBC: sw          $a2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r6;
    // 0x8000DBC0: sw          $a3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r7;
    // 0x8000DBC4: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x8000DBC8: beq         $a0, $zero, L_8000DC3C
    if (ctx->r4 == 0) {
        // 0x8000DBCC: swc1        $f0, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
            goto L_8000DC3C;
    }
    // 0x8000DBCC: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8000DBD0: sra         $v0, $a2, 8
    ctx->r2 = S32(SIGNED(ctx->r6) >> 8);
    // 0x8000DBD4: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x8000DBD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000DBDC: beq         $t8, $at, L_8000DBFC
    if (ctx->r24 == ctx->r1) {
        // 0x8000DBE0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8000DBFC;
    }
    // 0x8000DBE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000DBE4: beq         $t8, $at, L_8000DBFC
    if (ctx->r24 == ctx->r1) {
        // 0x8000DBE8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8000DBFC;
    }
    // 0x8000DBE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000DBEC: beq         $t8, $at, L_8000DC24
    if (ctx->r24 == ctx->r1) {
        // 0x8000DBF0: lui         $v0, 0x8005
        ctx->r2 = S32(0X8005 << 16);
            goto L_8000DC24;
    }
    // 0x8000DBF0: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000DBF4: b           L_8000DC28
    // 0x8000DBF8: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
        goto L_8000DC28;
    // 0x8000DBF8: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
L_8000DBFC:
    // 0x8000DBFC: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8000DC00: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000DC04: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8000DC08: beq         $t0, $zero, L_8000DC1C
    if (ctx->r8 == 0) {
        // 0x8000DC0C: nop
    
            goto L_8000DC1C;
    }
    // 0x8000DC0C: nop

    // 0x8000DC10: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000DC14: b           L_8000DC28
    // 0x8000DC18: addiu       $v0, $v0, 0x62E0
    ctx->r2 = ADD32(ctx->r2, 0X62E0);
        goto L_8000DC28;
    // 0x8000DC18: addiu       $v0, $v0, 0x62E0
    ctx->r2 = ADD32(ctx->r2, 0X62E0);
L_8000DC1C:
    // 0x8000DC1C: b           L_8000DC28
    // 0x8000DC20: addiu       $v0, $v0, 0x5D58
    ctx->r2 = ADD32(ctx->r2, 0X5D58);
        goto L_8000DC28;
    // 0x8000DC20: addiu       $v0, $v0, 0x5D58
    ctx->r2 = ADD32(ctx->r2, 0X5D58);
L_8000DC24:
    // 0x8000DC24: addiu       $v0, $v0, 0x6368
    ctx->r2 = ADD32(ctx->r2, 0X6368);
L_8000DC28:
    // 0x8000DC28: lhu         $t1, 0x6($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X6);
    // 0x8000DC2C: subu        $t2, $t1, $a1
    ctx->r10 = SUB32(ctx->r9, ctx->r5);
    // 0x8000DC30: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000DC34: b           L_8000DC44
    // 0x8000DC38: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_8000DC44;
    // 0x8000DC38: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_8000DC3C:
    // 0x8000DC3C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x8000DC40: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_8000DC44:
    // 0x8000DC44: jr          $ra
    // 0x8000DC48: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000DC48: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8001FCF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FCF8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001FCFC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8001FD00: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8001FD04: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8001FD08: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8001FD0C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8001FD10: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x8001FD14: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001FD18: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001FD1C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8001FD20: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8001FD24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001FD28: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001FD2C: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x8001FD30: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x8001FD34: addiu       $v1, $v1, -0x2D34
    ctx->r3 = ADD32(ctx->r3, -0X2D34);
    // 0x8001FD38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FD3C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8001FD40:
    // 0x8001FD40: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x8001FD44: and         $t5, $t4, $t0
    ctx->r13 = ctx->r12 & ctx->r8;
    // 0x8001FD48: beql        $t5, $zero, L_8001FD68
    if (ctx->r13 == 0) {
        // 0x8001FD4C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FD68;
    }
    goto skip_0;
    // 0x8001FD4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8001FD50: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8001FD54: sb          $a2, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r6;
    // 0x8001FD58: sb          $a3, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r7;
    // 0x8001FD5C: b           L_8001FD78
    // 0x8001FD60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FD78;
    // 0x8001FD60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FD64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FD68:
    // 0x8001FD68: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x8001FD6C: bne         $at, $zero, L_8001FD40
    if (ctx->r1 != 0) {
        // 0x8001FD70: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8001FD40;
    }
    // 0x8001FD70: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8001FD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FD78:
    // 0x8001FD78: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x8001FD7C: addiu       $v1, $v1, -0x2D24
    ctx->r3 = ADD32(ctx->r3, -0X2D24);
    // 0x8001FD80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8001FD84:
    // 0x8001FD84: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8001FD88: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001FD8C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x8001FD90: and         $t7, $t6, $t0
    ctx->r15 = ctx->r14 & ctx->r8;
    // 0x8001FD94: beql        $t7, $zero, L_8001FED0
    if (ctx->r15 == 0) {
        // 0x8001FD98: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FED0;
    }
    goto skip_1;
    // 0x8001FD98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x8001FD9C: lw          $t9, 0x44($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X44);
    // 0x8001FDA0: bne         $t9, $zero, L_8001FECC
    if (ctx->r25 != 0) {
        // 0x8001FDA4: addu        $t4, $t2, $v0
        ctx->r12 = ADD32(ctx->r10, ctx->r2);
            goto L_8001FECC;
    }
    // 0x8001FDA4: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x8001FDA8: lui         $t6, 0x803B
    ctx->r14 = S32(0X803B << 16);
    // 0x8001FDAC: sb          $a3, 0x32($t4)
    MEM_B(0X32, ctx->r12) = ctx->r7;
    // 0x8001FDB0: addiu       $t6, $t6, -0x71F4
    ctx->r14 = ADD32(ctx->r14, -0X71F4);
    // 0x8001FDB4: sll         $t5, $a2, 4
    ctx->r13 = S32(ctx->r6 << 4);
    // 0x8001FDB8: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8001FDBC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8001FDC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FDC4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8001FDC8: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8001FDCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001FDD0: addiu       $t0, $t0, -0x38B8
    ctx->r8 = ADD32(ctx->r8, -0X38B8);
    // 0x8001FDD4: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x8001FDD8: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x8001FDDC: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x8001FDE0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x8001FDE4: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x8001FDE8: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x8001FDEC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001FDF0: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x8001FDF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001FDF8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8001FDFC: addiu       $t9, $t9, -0x7228
    ctx->r25 = ADD32(ctx->r25, -0X7228);
    // 0x8001FE00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FE04: bne         $t4, $at, L_8001FE44
    if (ctx->r12 != ctx->r1) {
        // 0x8001FE08: addu        $t3, $t8, $t9
        ctx->r11 = ADD32(ctx->r24, ctx->r25);
            goto L_8001FE44;
    }
    // 0x8001FE08: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8001FE0C: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8001FE10: andi        $t5, $a1, 0x100
    ctx->r13 = ctx->r5 & 0X100;
    // 0x8001FE14: beql        $t5, $zero, L_8001FE2C
    if (ctx->r13 == 0) {
        // 0x8001FE18: lwc1        $f10, 0x18($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
            goto L_8001FE2C;
    }
    goto skip_2;
    // 0x8001FE18: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    skip_2:
    // 0x8001FE1C: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x8001FE20: b           L_8001FE90
    // 0x8001FE24: lwc1        $f0, 0x94($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X94);
        goto L_8001FE90;
    // 0x8001FE24: lwc1        $f0, 0x94($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X94);
    // 0x8001FE28: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
L_8001FE2C:
    // 0x8001FE2C: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001FE30: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x8001FE34: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001FE38: lwc1        $f4, 0x94($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X94);
    // 0x8001FE3C: b           L_8001FE90
    // 0x8001FE40: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
        goto L_8001FE90;
    // 0x8001FE40: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
L_8001FE44:
    // 0x8001FE44: lhu         $a1, 0x4($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X4);
    // 0x8001FE48: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001FE4C: andi        $t8, $a1, 0x100
    ctx->r24 = ctx->r5 & 0X100;
    // 0x8001FE50: beql        $t8, $zero, L_8001FE90
    if (ctx->r24 == 0) {
        // 0x8001FE54: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8001FE90;
    }
    goto skip_3;
    // 0x8001FE54: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x8001FE58: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001FE5C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001FE60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001FE64: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FE68: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001FE6C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8001FE70: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001FE74: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8001FE78: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8001FE7C: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8001FE80: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x8001FE84: b           L_8001FE90
    // 0x8001FE88: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
        goto L_8001FE90;
    // 0x8001FE88: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8001FE8C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_8001FE90:
    // 0x8001FE90: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001FE94: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8001FE98: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001FE9C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001FEA0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8001FEA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001FEA8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8001FEAC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8001FEB0: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x8001FEB4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8001FEB8: jal         0x800177F8
    // 0x8001FEBC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800177F8(rdram, ctx);
        goto after_0;
    // 0x8001FEBC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8001FEC0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8001FEC4: b           L_8001FED8
    // 0x8001FEC8: sw          $v0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r2;
        goto L_8001FED8;
    // 0x8001FEC8: sw          $v0, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->r2;
L_8001FECC:
    // 0x8001FECC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FED0:
    // 0x8001FED0: bne         $v0, $a0, L_8001FD84
    if (ctx->r2 != ctx->r4) {
        // 0x8001FED4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8001FD84;
    }
    // 0x8001FED4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8001FED8:
    // 0x8001FED8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001FEDC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001FEE0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001FEE4: jr          $ra
    // 0x8001FEE8: nop

    return;
    // 0x8001FEE8: nop

;}
RECOMP_FUNC void func_80017D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017D04: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80017D08: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80017D0C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80017D10: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80017D14: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80017D18: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80017D1C: lw          $t0, 0x30($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X30);
    // 0x80017D20: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x80017D24: lh          $v0, 0x30($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X30);
    // 0x80017D28: bltzl       $v0, L_80017E54
    if (SIGNED(ctx->r2) < 0) {
        // 0x80017D2C: sw          $zero, 0x38($s1)
        MEM_W(0X38, ctx->r17) = 0;
            goto L_80017E54;
    }
    goto skip_0;
    // 0x80017D2C: sw          $zero, 0x38($s1)
    MEM_W(0X38, ctx->r17) = 0;
    skip_0:
    // 0x80017D30: lwc1        $f4, 0x38($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X38);
    // 0x80017D34: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80017D38: addiu       $t1, $t1, 0x71D0
    ctx->r9 = ADD32(ctx->r9, 0X71D0);
    // 0x80017D3C: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x80017D40: lwc1        $f6, 0x3C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80017D44: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80017D48: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80017D4C: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x80017D50: lwc1        $f8, 0x1C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80017D54: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80017D58: addiu       $t7, $t7, 0x1B90
    ctx->r15 = ADD32(ctx->r15, 0X1B90);
    // 0x80017D5C: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x80017D60: lhu         $a1, 0x34($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X34);
    // 0x80017D64: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80017D68: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80017D6C: andi        $t8, $a1, 0x40
    ctx->r24 = ctx->r5 & 0X40;
    // 0x80017D70: beq         $t8, $zero, L_80017D7C
    if (ctx->r24 == 0) {
        // 0x80017D74: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80017D7C;
    }
    // 0x80017D74: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80017D78: lw          $s0, 0x24($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X24);
L_80017D7C:
    // 0x80017D7C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80017D80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017D84: andi        $t3, $v1, 0x100
    ctx->r11 = ctx->r3 & 0X100;
    // 0x80017D88: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x80017D8C: andi        $t5, $v1, 0x100
    ctx->r13 = ctx->r3 & 0X100;
    // 0x80017D90: bne         $t9, $at, L_80017DB4
    if (ctx->r25 != ctx->r1) {
        // 0x80017D94: nop
    
            goto L_80017DB4;
    }
    // 0x80017D94: nop

    // 0x80017D98: beq         $t3, $zero, L_80017DAC
    if (ctx->r11 == 0) {
        // 0x80017D9C: nop
    
            goto L_80017DAC;
    }
    // 0x80017D9C: nop

    // 0x80017DA0: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x80017DA4: b           L_80017DF4
    // 0x80017DA8: lwc1        $f12, 0x94($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X94);
        goto L_80017DF4;
    // 0x80017DA8: lwc1        $f12, 0x94($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X94);
L_80017DAC:
    // 0x80017DAC: b           L_80017DF4
    // 0x80017DB0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
        goto L_80017DF4;
    // 0x80017DB0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
L_80017DB4:
    // 0x80017DB4: beq         $t5, $zero, L_80017DF0
    if (ctx->r13 == 0) {
        // 0x80017DB8: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80017DF0;
    }
    // 0x80017DB8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80017DBC: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80017DC0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80017DC4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80017DC8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80017DCC: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80017DD0: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80017DD4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80017DD8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80017DDC: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80017DE0: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80017DE4: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x80017DE8: b           L_80017DF4
    // 0x80017DEC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
        goto L_80017DF4;
    // 0x80017DEC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_80017DF0:
    // 0x80017DF0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
L_80017DF4:
    // 0x80017DF4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80017DF8: lhu         $a0, 0x32($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X32);
    // 0x80017DFC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80017E00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80017E04: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80017E08: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80017E0C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80017E10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80017E14: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80017E18: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80017E1C: jal         0x800177F8
    // 0x80017E20: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_800177F8(rdram, ctx);
        goto after_0;
    // 0x80017E20: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80017E24: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80017E28: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80017E2C: sw          $v0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r2;
    // 0x80017E30: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x80017E34: lw          $t6, 0x38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X38);
    // 0x80017E38: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80017E3C: swc1        $f18, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f18.u32l;
    // 0x80017E40: lw          $t7, 0x38($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X38);
    // 0x80017E44: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80017E48: b           L_80017E54
    // 0x80017E4C: swc1        $f10, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f10.u32l;
        goto L_80017E54;
    // 0x80017E4C: swc1        $f10, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f10.u32l;
    // 0x80017E50: sw          $zero, 0x38($s1)
    MEM_W(0X38, ctx->r17) = 0;
L_80017E54:
    // 0x80017E54: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x80017E58: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
    // 0x80017E5C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80017E60: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80017E64: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x80017E68: lw          $t3, 0x38F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X38F4);
    // 0x80017E6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80017E70: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80017E74: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80017E78: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80017E7C: lhu         $a0, 0x8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X8);
    // 0x80017E80: beql        $a0, $zero, L_80017F50
    if (ctx->r4 == 0) {
        // 0x80017E84: lb          $a1, 0x42($t0)
        ctx->r5 = MEM_B(ctx->r8, 0X42);
            goto L_80017F50;
    }
    goto skip_1;
    // 0x80017E84: lb          $a1, 0x42($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X42);
    skip_1:
    // 0x80017E88: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80017E8C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80017E90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80017E94: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80017E98: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80017E9C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80017EA0: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80017EA4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80017EA8: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80017EAC: mul.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80017EB0: nop

    // 0x80017EB4: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80017EB8: cvt.s.d     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f14.fl = CVT_S_D(ctx->f16.d);
    // 0x80017EBC: beq         $a0, $at, L_80017ED8
    if (ctx->r4 == ctx->r1) {
        // 0x80017EC0: add.s       $f12, $f18, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
            goto L_80017ED8;
    }
    // 0x80017EC0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80017EC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80017EC8: beq         $a0, $at, L_80017F18
    if (ctx->r4 == ctx->r1) {
        // 0x80017ECC: nop
    
            goto L_80017F18;
    }
    // 0x80017ECC: nop

    // 0x80017ED0: b           L_80017F50
    // 0x80017ED4: lb          $a1, 0x42($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X42);
        goto L_80017F50;
    // 0x80017ED4: lb          $a1, 0x42($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X42);
L_80017ED8:
    // 0x80017ED8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80017EDC: ldc1        $f16, 0x1508($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1508);
    // 0x80017EE0: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80017EE4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80017EE8: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80017EEC: lhu         $a0, 0xA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XA);
    // 0x80017EF0: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80017EF4: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80017EF8: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80017EFC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80017F00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80017F04: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80017F08: jal         0x80019354
    // 0x80017F0C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80019354(rdram, ctx);
        goto after_1;
    // 0x80017F0C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80017F10: b           L_80017F4C
    // 0x80017F14: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
        goto L_80017F4C;
    // 0x80017F14: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_80017F18:
    // 0x80017F18: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80017F1C: ldc1        $f4, 0x1510($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1510);
    // 0x80017F20: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80017F24: lhu         $a0, 0xA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XA);
    // 0x80017F28: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80017F2C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80017F30: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80017F34: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80017F38: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80017F3C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80017F40: jal         0x80019738
    // 0x80017F44: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80019738(rdram, ctx);
        goto after_2;
    // 0x80017F44: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80017F48: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
L_80017F4C:
    // 0x80017F4C: lb          $a1, 0x42($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X42);
L_80017F50:
    // 0x80017F50: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80017F54: bltzl       $a1, L_80017F70
    if (SIGNED(ctx->r5) < 0) {
        // 0x80017F58: lw          $t6, 0x28($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X28);
            goto L_80017F70;
    }
    goto skip_2;
    // 0x80017F58: lw          $t6, 0x28($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X28);
    skip_2:
    // 0x80017F5C: jal         0x800268D4
    // 0x80017F60: lbu         $a0, 0x43($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X43);
    func_800268D4(rdram, ctx);
        goto after_3;
    // 0x80017F60: lbu         $a0, 0x43($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X43);
    after_3:
    // 0x80017F64: b           L_80017F90
    // 0x80017F68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80017F90;
    // 0x80017F68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80017F6C: lw          $t6, 0x28($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X28);
L_80017F70:
    // 0x80017F70: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x80017F74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80017F78: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80017F7C: beql        $t6, $t7, L_80017F90
    if (ctx->r14 == ctx->r15) {
        // 0x80017F80: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80017F90;
    }
    goto skip_3;
    // 0x80017F80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x80017F84: jal         0x800268D4
    // 0x80017F88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_4;
    // 0x80017F88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_4:
    // 0x80017F8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80017F90:
    // 0x80017F90: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80017F94: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80017F98: jr          $ra
    // 0x80017F9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80017F9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80036850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036850: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80036854: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80036858: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8003685C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80036860: beq         $v0, $zero, L_8003686C
    if (ctx->r2 == 0) {
        // 0x80036864: nop
    
            goto L_8003686C;
    }
    // 0x80036864: nop

    // 0x80036868: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_8003686C:
    // 0x8003686C: jr          $ra
    // 0x80036870: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x80036870: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void func_80013008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013008: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001300C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013010: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x80013014: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80013018: jal         0x80013D30
    // 0x8001301C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80013D30(rdram, ctx);
        goto after_0;
    // 0x8001301C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80013020: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80013024: lw          $t7, -0x4D1C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D1C);
    // 0x80013028: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8001302C: andi        $t8, $t7, 0x82
    ctx->r24 = ctx->r15 & 0X82;
    // 0x80013030: bne         $t8, $zero, L_80013094
    if (ctx->r24 != 0) {
        // 0x80013034: lui         $t9, 0x8009
        ctx->r25 = S32(0X8009 << 16);
            goto L_80013094;
    }
    // 0x80013034: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80013038: lhu         $t9, -0x3A6E($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X3A6E);
    // 0x8001303C: andi        $t0, $t9, 0x200
    ctx->r8 = ctx->r25 & 0X200;
    // 0x80013040: bnel        $t0, $zero, L_80013098
    if (ctx->r8 != 0) {
        // 0x80013044: lhu         $t7, 0x8($a0)
        ctx->r15 = MEM_HU(ctx->r4, 0X8);
            goto L_80013098;
    }
    goto skip_0;
    // 0x80013044: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    skip_0:
    // 0x80013048: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    // 0x8001304C: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x80013050: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    // 0x80013054: bnel        $t1, $zero, L_80013098
    if (ctx->r9 != 0) {
        // 0x80013058: lhu         $t7, 0x8($a0)
        ctx->r15 = MEM_HU(ctx->r4, 0X8);
            goto L_80013098;
    }
    goto skip_1;
    // 0x80013058: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    skip_1:
    // 0x8001305C: lhu         $t2, 0x2874($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2874);
    // 0x80013060: ori         $t5, $v0, 0x24
    ctx->r13 = ctx->r2 | 0X24;
    // 0x80013064: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80013068: bne         $t3, $zero, L_80013084
    if (ctx->r11 != 0) {
        // 0x8001306C: nop
    
            goto L_80013084;
    }
    // 0x8001306C: nop

    // 0x80013070: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80013074: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80013078: andi        $t6, $v0, 0xFFDB
    ctx->r14 = ctx->r2 & 0XFFDB;
    // 0x8001307C: bne         $t4, $at, L_8001308C
    if (ctx->r12 != ctx->r1) {
        // 0x80013080: nop
    
            goto L_8001308C;
    }
    // 0x80013080: nop

L_80013084:
    // 0x80013084: b           L_800130A0
    // 0x80013088: sh          $t5, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r13;
        goto L_800130A0;
    // 0x80013088: sh          $t5, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r13;
L_8001308C:
    // 0x8001308C: b           L_800130A0
    // 0x80013090: sh          $t6, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r14;
        goto L_800130A0;
    // 0x80013090: sh          $t6, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r14;
L_80013094:
    // 0x80013094: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
L_80013098:
    // 0x80013098: andi        $t8, $t7, 0xFFDB
    ctx->r24 = ctx->r15 & 0XFFDB;
    // 0x8001309C: sh          $t8, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r24;
L_800130A0:
    // 0x800130A0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800130A4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800130A8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800130AC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800130B0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800130B4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800130B8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800130BC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800130C0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800130C4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800130C8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800130CC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x800130D0: jal         0x80034F60
    // 0x800130D4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x800130D4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800130D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800130DC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800130E0: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800130E4: nop

    // 0x800130E8: bc1tl       L_800131B0
    if (c1cs) {
        // 0x800130EC: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_800131B0;
    }
    goto skip_2;
    // 0x800130EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x800130F0: lwc1        $f14, 0x4C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800130F4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800130F8: nop

    // 0x800130FC: bc1fl       L_80013140
    if (!c1cs) {
        // 0x80013100: c.le.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
            goto L_80013140;
    }
    goto skip_3;
    // 0x80013100: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    skip_3:
    // 0x80013104: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80013108: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001310C: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80013110: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80013114: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80013118: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8001311C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80013120: nop

    // 0x80013124: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80013128: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8001312C: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80013130: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80013134: b           L_800131BC
    // 0x80013138: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
        goto L_800131BC;
    // 0x80013138: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8001313C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
L_80013140:
    // 0x80013140: nop

    // 0x80013144: bc1fl       L_800131C0
    if (!c1cs) {
        // 0x80013148: lwc1        $f10, 0x40($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
            goto L_800131C0;
    }
    goto skip_4;
    // 0x80013148: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    skip_4:
    // 0x8001314C: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80013150: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80013154: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80013158: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001315C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80013160: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80013164: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80013168: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001316C: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80013170: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80013174: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80013178: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001317C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80013180: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80013184: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80013188: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001318C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80013190: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80013194: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80013198: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001319C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800131A0: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800131A4: b           L_800131BC
    // 0x800131A8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
        goto L_800131BC;
    // 0x800131A8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800131AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_800131B0:
    // 0x800131B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800131B4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800131B8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_800131BC:
    // 0x800131BC: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
L_800131C0:
    // 0x800131C0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800131C4: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800131C8: lwc1        $f14, 0x74($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800131CC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800131D0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800131D4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x800131D8: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800131DC: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800131E0: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800131E4: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800131E8: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800131EC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800131F0: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x800131F4: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800131F8: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800131FC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80013200: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80013204: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80013208: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001320C: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x80013210: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80013214: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80013218: swc1        $f8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f8.u32l;
    // 0x8001321C: sb          $zero, 0x47($sp)
    MEM_B(0X47, ctx->r29) = 0;
    // 0x80013220: bc1f        L_80013320
    if (!c1cs) {
        // 0x80013224: lui         $t9, 0x8008
        ctx->r25 = S32(0X8008 << 16);
            goto L_80013320;
    }
    // 0x80013224: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80013228: lw          $t9, -0x4D1C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4D1C);
    // 0x8001322C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80013230: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x80013234: bnel        $t0, $zero, L_80013324
    if (ctx->r8 != 0) {
        // 0x80013238: lhu         $t5, 0x8($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X8);
            goto L_80013324;
    }
    goto skip_5;
    // 0x80013238: lhu         $t5, 0x8($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X8);
    skip_5:
    // 0x8001323C: lwc1        $f16, 0x10($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80013240: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80013244: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013248: ldc1        $f12, 0x1350($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1350);
    // 0x8001324C: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80013250: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013254: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80013258: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x8001325C: nop

    // 0x80013260: bc1f        L_80013280
    if (!c1cs) {
        // 0x80013264: nop
    
            goto L_80013280;
    }
    // 0x80013264: nop

    // 0x80013268: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001326C: ldc1        $f6, 0x1358($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1358);
    // 0x80013270: sub.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d - ctx->f6.d;
    // 0x80013274: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80013278: b           L_800132A8
    // 0x8001327C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
        goto L_800132A8;
    // 0x8001327C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80013280:
    // 0x80013280: ldc1        $f10, 0x1360($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1360);
    // 0x80013284: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013288: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8001328C: nop

    // 0x80013290: bc1f        L_800132A8
    if (!c1cs) {
        // 0x80013294: nop
    
            goto L_800132A8;
    }
    // 0x80013294: nop

    // 0x80013298: ldc1        $f4, 0x1368($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1368);
    // 0x8001329C: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x800132A0: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800132A4: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_800132A8:
    // 0x800132A8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800132AC: ldc1        $f12, 0x1370($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1370);
    // 0x800132B0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800132B4: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x800132B8: nop

    // 0x800132BC: bc1fl       L_8001330C
    if (!c1cs) {
        // 0x800132C0: lhu         $t2, 0x8($a0)
        ctx->r10 = MEM_HU(ctx->r4, 0X8);
            goto L_8001330C;
    }
    goto skip_6;
    // 0x800132C0: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
    skip_6:
    // 0x800132C4: ldc1        $f14, 0x1378($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X1378);
    // 0x800132C8: c.lt.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d < ctx->f0.d;
    // 0x800132CC: nop

    // 0x800132D0: bc1fl       L_8001330C
    if (!c1cs) {
        // 0x800132D4: lhu         $t2, 0x8($a0)
        ctx->r10 = MEM_HU(ctx->r4, 0X8);
            goto L_8001330C;
    }
    goto skip_7;
    // 0x800132D4: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
    skip_7:
    // 0x800132D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800132DC: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800132E0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800132E4: nop

    // 0x800132E8: bc1fl       L_800132FC
    if (!c1cs) {
        // 0x800132EC: mov.d       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
            goto L_800132FC;
    }
    goto skip_8;
    // 0x800132EC: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
    skip_8:
    // 0x800132F0: b           L_800132FC
    // 0x800132F4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800132FC;
    // 0x800132F4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800132F8: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
L_800132FC:
    // 0x800132FC: add.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d + ctx->f10.d;
    // 0x80013300: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80013304: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80013308: lhu         $t2, 0x8($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X8);
L_8001330C:
    // 0x8001330C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80013310: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80013314: sh          $t3, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r11;
    // 0x80013318: b           L_800133AC
    // 0x8001331C: sb          $t4, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r12;
        goto L_800133AC;
    // 0x8001331C: sb          $t4, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r12;
L_80013320:
    // 0x80013320: lhu         $t5, 0x8($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X8);
L_80013324:
    // 0x80013324: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80013328: andi        $t6, $t5, 0x20
    ctx->r14 = ctx->r13 & 0X20;
    // 0x8001332C: beql        $t6, $zero, L_800133B0
    if (ctx->r14 == 0) {
        // 0x80013330: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_800133B0;
    }
    goto skip_9;
    // 0x80013330: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    skip_9:
    // 0x80013334: lwc1        $f8, 0x10($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80013338: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001333C: ldc1        $f12, 0x1380($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1380);
    // 0x80013340: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80013344: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013348: add.d       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f10.d + ctx->f12.d;
    // 0x8001334C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80013350: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80013354: lwc1        $f8, 0x54($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80013358: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8001335C: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80013360: nop

    // 0x80013364: bc1f        L_80013384
    if (!c1cs) {
        // 0x80013368: nop
    
            goto L_80013384;
    }
    // 0x80013368: nop

    // 0x8001336C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013370: ldc1        $f10, 0x1388($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1388);
    // 0x80013374: sub.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d - ctx->f10.d;
    // 0x80013378: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8001337C: b           L_800133AC
    // 0x80013380: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
        goto L_800133AC;
    // 0x80013380: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
L_80013384:
    // 0x80013384: ldc1        $f8, 0x1390($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1390);
    // 0x80013388: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001338C: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x80013390: nop

    // 0x80013394: bc1fl       L_800133B0
    if (!c1cs) {
        // 0x80013398: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_800133B0;
    }
    goto skip_10;
    // 0x80013398: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    skip_10:
    // 0x8001339C: ldc1        $f10, 0x1398($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1398);
    // 0x800133A0: add.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f0.d + ctx->f10.d;
    // 0x800133A4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800133A8: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
L_800133AC:
    // 0x800133AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_800133B0:
    // 0x800133B0: jal         0x80013DE0
    // 0x800133B4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80013DE0(rdram, ctx);
        goto after_2;
    // 0x800133B4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_2:
    // 0x800133B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800133BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800133C0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800133C4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800133C8: addiu       $v0, $v0, 0x6BA0
    ctx->r2 = ADD32(ctx->r2, 0X6BA0);
    // 0x800133CC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800133D0: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x800133D4: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800133D8: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800133DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800133E0: jal         0x8000EE60
    // 0x800133E4: addiu       $a3, $zero, 0x602
    ctx->r7 = ADD32(0, 0X602);
    func_8000EE60(rdram, ctx);
        goto after_3;
    // 0x800133E4: addiu       $a3, $zero, 0x602
    ctx->r7 = ADD32(0, 0X602);
    after_3:
    // 0x800133E8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800133EC: addiu       $v0, $v0, 0x6BA0
    ctx->r2 = ADD32(ctx->r2, 0X6BA0);
    // 0x800133F0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800133F4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800133F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800133FC: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x80013400: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80013404: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x80013408: lhu         $v1, 0x18($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X18);
    // 0x8001340C: andi        $t8, $v1, 0x8000
    ctx->r24 = ctx->r3 & 0X8000;
    // 0x80013410: beql        $t8, $zero, L_80013428
    if (ctx->r24 == 0) {
        // 0x80013414: lwc1        $f12, 0x4($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80013428;
    }
    goto skip_11;
    // 0x80013414: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    skip_11:
    // 0x80013418: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8001341C: b           L_80013430
    // 0x80013420: lwc1        $f2, 0x4($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X4);
        goto L_80013430;
    // 0x80013420: lwc1        $f2, 0x4($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80013424: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
L_80013428:
    // 0x80013428: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x8001342C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
L_80013430:
    // 0x80013430: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80013434: sh          $v1, 0x6BBC($at)
    MEM_H(0X6BBC, ctx->r1) = ctx->r3;
    // 0x80013438: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8001343C: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80013440: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013444: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80013448: nop

    // 0x8001344C: bc1fl       L_8001345C
    if (!c1cs) {
        // 0x80013450: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_8001345C;
    }
    goto skip_12;
    // 0x80013450: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_12:
    // 0x80013454: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80013458: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8001345C:
    // 0x8001345C: jal         0x80014720
    // 0x80013460: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80014720(rdram, ctx);
        goto after_4;
    // 0x80013460: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_4:
    // 0x80013464: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80013468: lhu         $t1, -0x3A6E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X3A6E);
    // 0x8001346C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80013470: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80013474: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80013478: beq         $t2, $zero, L_80013498
    if (ctx->r10 == 0) {
        // 0x8001347C: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80013498;
    }
    // 0x8001347C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013480: lwc1        $f2, -0x4530($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X4530);
    // 0x80013484: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80013488: nop

    // 0x8001348C: bc1fl       L_8001349C
    if (!c1cs) {
        // 0x80013490: lwc1        $f14, 0x10($a0)
        ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
            goto L_8001349C;
    }
    goto skip_13;
    // 0x80013490: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    skip_13:
    // 0x80013494: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80013498:
    // 0x80013498: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
L_8001349C:
    // 0x8001349C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800134A0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800134A4: sub.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x800134A8: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800134AC: nop

    // 0x800134B0: bc1f        L_800134C4
    if (!c1cs) {
        // 0x800134B4: nop
    
            goto L_800134C4;
    }
    // 0x800134B4: nop

    // 0x800134B8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800134BC: b           L_800134C8
    // 0x800134C0: ldc1        $f0, 0x13A0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X13A0);
        goto L_800134C8;
    // 0x800134C0: ldc1        $f0, 0x13A0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X13A0);
L_800134C4:
    // 0x800134C4: ldc1        $f0, 0x13A8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X13A8);
L_800134C8:
    // 0x800134C8: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800134CC: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800134D0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800134D4: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800134D8: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800134DC: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800134E0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800134E4: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800134E8: add.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800134EC: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x800134F0: lwc1        $f2, 0x44($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800134F4: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800134F8: add.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x800134FC: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x80013500: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    // 0x80013504: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80013508: jal         0x80013D3C
    // 0x8001350C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80013D3C(rdram, ctx);
        goto after_5;
    // 0x8001350C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80013510: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80013514: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80013518: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8001351C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80013520: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80013524: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80013528: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8001352C: sub.s       $f16, $f2, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80013530: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80013534: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80013538: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001353C: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80013540: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80013544: c.lt.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d < ctx->f0.d;
    // 0x80013548: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8001354C: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013550: bc1f        L_800135D8
    if (!c1cs) {
        // 0x80013554: sub.s       $f18, $f12, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f4.fl;
            goto L_800135D8;
    }
    // 0x80013554: sub.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80013558: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001355C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80013560: nop

    // 0x80013564: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80013568: nop

    // 0x8001356C: bc1f        L_800135D8
    if (!c1cs) {
        // 0x80013570: nop
    
            goto L_800135D8;
    }
    // 0x80013570: nop

    // 0x80013574: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80013578: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001357C: c.lt.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d < ctx->f0.d;
    // 0x80013580: nop

    // 0x80013584: bc1f        L_800135D8
    if (!c1cs) {
        // 0x80013588: nop
    
            goto L_800135D8;
    }
    // 0x80013588: nop

    // 0x8001358C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80013590: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80013594: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80013598: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x8001359C: nop

    // 0x800135A0: bc1f        L_800135D8
    if (!c1cs) {
        // 0x800135A4: nop
    
            goto L_800135D8;
    }
    // 0x800135A4: nop

    // 0x800135A8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800135AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800135B0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800135B4: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800135B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800135BC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800135C0: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x800135C4: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800135C8: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800135CC: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800135D0: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800135D4: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
L_800135D8:
    // 0x800135D8: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800135DC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800135E0: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800135E4: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800135E8: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x800135EC: jal         0x80034F60
    // 0x800135F0: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_6;
    // 0x800135F0: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_6:
    // 0x800135F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800135F8: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800135FC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80013600: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80013604: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80013608: nop

    // 0x8001360C: bc1f        L_80013624
    if (!c1cs) {
        // 0x80013610: nop
    
            goto L_80013624;
    }
    // 0x80013610: nop

    // 0x80013614: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80013618: nop

    // 0x8001361C: bc1tl       L_8001363C
    if (c1cs) {
        // 0x80013620: lwc1        $f12, 0x40($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
            goto L_8001363C;
    }
    goto skip_14;
    // 0x80013620: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    skip_14:
L_80013624:
    // 0x80013624: jal         0x80023210
    // 0x80013628: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80023210(rdram, ctx);
        goto after_7;
    // 0x80013628: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_7:
    // 0x8001362C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80013630: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80013634: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80013638: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
L_8001363C:
    // 0x8001363C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80013640: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80013644: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80013648: nop

    // 0x8001364C: bc1f        L_80013664
    if (!c1cs) {
        // 0x80013650: nop
    
            goto L_80013664;
    }
    // 0x80013650: nop

    // 0x80013654: c.eq.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl == ctx->f2.fl;
    // 0x80013658: nop

    // 0x8001365C: bc1tl       L_8001368C
    if (c1cs) {
        // 0x80013660: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001368C;
    }
    goto skip_15;
    // 0x80013660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
L_80013664:
    // 0x80013664: jal         0x80023210
    // 0x80013668: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80023210(rdram, ctx);
        goto after_8;
    // 0x80013668: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_8:
    // 0x8001366C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80013670: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80013674: lbu         $t3, 0x47($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X47);
    // 0x80013678: bnel        $t3, $zero, L_8001368C
    if (ctx->r11 != 0) {
        // 0x8001367C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001368C;
    }
    goto skip_16;
    // 0x8001367C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x80013680: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80013684: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x80013688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001368C:
    // 0x8001368C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80013690: jr          $ra
    // 0x80013694: nop

    return;
    // 0x80013694: nop

;}
RECOMP_FUNC void func_80039A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039A70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80039A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039A78: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80039A7C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80039A80: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80039A84: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80039A88: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x80039A8C: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    // 0x80039A90: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80039A94: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80039A98: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80039A9C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80039AA0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80039AA4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80039AA8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80039AAC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80039AB0: jal         0x8003FE6C
    // 0x80039AB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80039AB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80039AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80039AC0: jr          $ra
    // 0x80039AC4: nop

    return;
    // 0x80039AC4: nop

    // 0x80039AC8: nop

    // 0x80039ACC: nop

;}
