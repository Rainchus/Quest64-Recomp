#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80023974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023974: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80023978: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8002397C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80023980: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80023984: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80023988: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002398C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80023990: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80023994: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80023998: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002399C: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800239A0: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800239A4: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800239A8: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x800239AC: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800239B0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800239B4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800239B8: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800239BC: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800239C0: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800239C4: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800239C8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800239CC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800239D0: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800239D4: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800239D8: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800239DC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800239E0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800239E4: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800239E8: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800239EC: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800239F0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800239F4: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800239F8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800239FC: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x80023A00: jr          $ra
    // 0x80023A04: nop

    return;
    // 0x80023A04: nop

;}
RECOMP_FUNC void func_800048D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800048D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800048D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800048D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800048DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800048E0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800048E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800048E8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800048EC: addiu       $a2, $a2, -0x43D0
    ctx->r6 = ADD32(ctx->r6, -0X43D0);
    // 0x800048F0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800048F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800048F8: jal         0x800056D0
    // 0x800048FC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800056D0(rdram, ctx);
        goto after_0;
    // 0x800048FC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80004900: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80004904: addiu       $v0, $v0, -0x43D0
    ctx->r2 = ADD32(ctx->r2, -0X43D0);
    // 0x80004908: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8000490C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80004910: addiu       $a0, $zero, 0xA00
    ctx->r4 = ADD32(0, 0XA00);
    // 0x80004914: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80004918: swc1        $f4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f4.u32l;
    // 0x8000491C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80004920: jal         0x80005748
    // 0x80004924: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    func_80005748(rdram, ctx);
        goto after_1;
    // 0x80004924: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    after_1:
    // 0x80004928: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x8000492C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80004930: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80004934: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80004938: bne         $t8, $zero, L_80004958
    if (ctx->r24 != 0) {
        // 0x8000493C: sh          $t7, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r15;
            goto L_80004958;
    }
    // 0x8000493C: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80004940: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80004944: lhu         $t9, 0x60($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X60);
    // 0x80004948: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x8000494C: sh          $t0, 0x60($a3)
    MEM_H(0X60, ctx->r7) = ctx->r8;
    // 0x80004950: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80004954: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
L_80004958:
    // 0x80004958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000495C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004964: jr          $ra
    // 0x80004968: nop

    return;
    // 0x80004968: nop

;}
RECOMP_FUNC void func_80023500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023500: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80023504: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80023508: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002350C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80023510: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80023514: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80023518: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8002351C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80023520: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80023524: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80023528: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002352C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80023530: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80023534: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x80023538: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8002353C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80023540: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80023544: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80023548: jal         0x80023360
    // 0x8002354C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_80023360(rdram, ctx);
        goto after_0;
    // 0x8002354C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80023550: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80023554: addiu       $a0, $a0, -0x2FD0
    ctx->r4 = ADD32(ctx->r4, -0X2FD0);
    // 0x80023558: jal         0x80035200
    // 0x8002355C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8002355C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80023560: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023564: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80023568: jr          $ra
    // 0x8002356C: nop

    return;
    // 0x8002356C: nop

;}
RECOMP_FUNC void func_80031C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_80031C0C:
    // 0x80031C0C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80031C10: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x80031C14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80031C18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80031C1C: bne         $t6, $t7, L_80031C2C
    if (ctx->r14 != ctx->r15) {
        // 0x80031C20: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80031C2C;
    }
    // 0x80031C20: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80031C24: bne         $a2, $zero, L_80031C0C
    if (ctx->r6 != 0) {
        // 0x80031C28: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80031C0C;
    }
    // 0x80031C28: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80031C2C:
    // 0x80031C2C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80031C30: jr          $ra
    // 0x80031C34: nop

    return;
    // 0x80031C34: nop

;}
RECOMP_FUNC void func_8000B140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B140: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B144: addiu       $v0, $v0, -0x3644
    ctx->r2 = ADD32(ctx->r2, -0X3644);
    // 0x8000B148: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000B14C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_8000B150:
    // 0x8000B150: beql        $a0, $v0, L_8000B168
    if (ctx->r4 == ctx->r2) {
        // 0x8000B154: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000B168;
    }
    goto skip_0;
    // 0x8000B154: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8000B158: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000B15C: bne         $v1, $a1, L_8000B150
    if (ctx->r3 != ctx->r5) {
        // 0x8000B160: addiu       $v0, $v0, 0x128
        ctx->r2 = ADD32(ctx->r2, 0X128);
            goto L_8000B150;
    }
    // 0x8000B160: addiu       $v0, $v0, 0x128
    ctx->r2 = ADD32(ctx->r2, 0X128);
    // 0x8000B164: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000B168:
    // 0x8000B168: jr          $ra
    // 0x8000B16C: nop

    return;
    // 0x8000B16C: nop

;}
RECOMP_FUNC void func_80040A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040A24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80040A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040A2C: beq         $a1, $at, L_80040B84
    if (ctx->r5 == ctx->r1) {
        // 0x80040A30: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80040B84;
    }
    // 0x80040A30: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80040A34: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80040A38: bnel        $a1, $at, L_80040BE8
    if (ctx->r5 != ctx->r1) {
        // 0x80040A3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040BE8;
    }
    goto skip_0;
    // 0x80040A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80040A40: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x80040A44: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80040A48: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x80040A4C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80040A50: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x80040A54: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x80040A58: beql        $v0, $zero, L_80040A78
    if (ctx->r2 == 0) {
        // 0x80040A5C: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_80040A78;
    }
    goto skip_1;
    // 0x80040A5C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x80040A60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80040A64: beq         $v0, $a0, L_80040B38
    if (ctx->r2 == ctx->r4) {
        // 0x80040A68: lui         $t0, 0x8004
        ctx->r8 = S32(0X8004 << 16);
            goto L_80040B38;
    }
    // 0x80040A68: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80040A6C: b           L_80040BE8
    // 0x80040A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80040BE8;
    // 0x80040A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040A74: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_80040A78:
    // 0x80040A78: addiu       $t7, $t7, 0x10CC
    ctx->r15 = ADD32(ctx->r15, 0X10CC);
    // 0x80040A7C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80040A80: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80040A84: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80040A88: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80040A8C: mflo        $t9
    ctx->r25 = lo;
    // 0x80040A90: bne         $a1, $zero, L_80040A9C
    if (ctx->r5 != 0) {
        // 0x80040A94: nop
    
            goto L_80040A9C;
    }
    // 0x80040A94: nop

    // 0x80040A98: break       7
    do_break(2147748504);
L_80040A9C:
    // 0x80040A9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80040AA0: bne         $a1, $at, L_80040AB4
    if (ctx->r5 != ctx->r1) {
        // 0x80040AA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80040AB4;
    }
    // 0x80040AA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80040AA8: bne         $t8, $at, L_80040AB4
    if (ctx->r24 != ctx->r1) {
        // 0x80040AAC: nop
    
            goto L_80040AB4;
    }
    // 0x80040AAC: nop

    // 0x80040AB0: break       6
    do_break(2147748528);
L_80040AB4:
    // 0x80040AB4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040AB8: mflo        $t0
    ctx->r8 = lo;
    // 0x80040ABC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80040AC0: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x80040AC4: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80040AC8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80040ACC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x80040AD0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80040AD4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040AD8: mflo        $t4
    ctx->r12 = lo;
    // 0x80040ADC: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x80040AE0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80040AE4: beql        $v1, $zero, L_80040B2C
    if (ctx->r3 == 0) {
        // 0x80040AE8: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_80040B2C;
    }
    goto skip_2;
    // 0x80040AE8: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x80040AEC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80040AF0: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x80040AF4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80040AF8: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x80040AFC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80040B00: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80040B04: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80040B08: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80040B0C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80040B10: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x80040B14: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80040B18: jal         0x80048A40
    // 0x80040B1C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x80040B1C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x80040B20: b           L_80040BE8
    // 0x80040B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80040BE8;
    // 0x80040B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040B28: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_80040B2C:
    // 0x80040B2C: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x80040B30: b           L_80040BE4
    // 0x80040B34: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_80040BE4;
    // 0x80040B34: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_80040B38:
    // 0x80040B38: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x80040B3C: addiu       $t0, $t0, 0xBF4
    ctx->r8 = ADD32(ctx->r8, 0XBF4);
    // 0x80040B40: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80040B44: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80040B48: beql        $v1, $zero, L_80040B78
    if (ctx->r3 == 0) {
        // 0x80040B4C: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_80040B78;
    }
    goto skip_3;
    // 0x80040B4C: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x80040B50: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80040B54: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x80040B58: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80040B5C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80040B60: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x80040B64: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x80040B68: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80040B6C: b           L_80040BE4
    // 0x80040B70: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_80040BE4;
    // 0x80040B70: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x80040B74: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_80040B78:
    // 0x80040B78: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x80040B7C: b           L_80040BE4
    // 0x80040B80: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_80040BE4;
    // 0x80040B80: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_80040B84:
    // 0x80040B84: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x80040B88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80040B8C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80040B90: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80040B94: beq         $v0, $zero, L_80040BE4
    if (ctx->r2 == 0) {
        // 0x80040B98: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_80040BE4;
    }
    // 0x80040B98: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x80040B9C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80040BA0: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x80040BA4: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x80040BA8: bne         $v1, $zero, L_80040BC8
    if (ctx->r3 != 0) {
        // 0x80040BAC: nop
    
            goto L_80040BC8;
    }
    // 0x80040BAC: nop

    // 0x80040BB0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80040BB4: beql        $v1, $zero, L_80040BE8
    if (ctx->r3 == 0) {
        // 0x80040BB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040BE8;
    }
    goto skip_4;
    // 0x80040BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80040BBC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80040BC0: b           L_80040BE4
    // 0x80040BC4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_80040BE4;
    // 0x80040BC4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_80040BC8:
    // 0x80040BC8: bnel        $a0, $v1, L_80040BE8
    if (ctx->r4 != ctx->r3) {
        // 0x80040BCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040BE8;
    }
    goto skip_5;
    // 0x80040BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80040BD0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80040BD4: beql        $v1, $zero, L_80040BE8
    if (ctx->r3 == 0) {
        // 0x80040BD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040BE8;
    }
    goto skip_6;
    // 0x80040BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80040BDC: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80040BE0: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_80040BE4:
    // 0x80040BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80040BE8:
    // 0x80040BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040BEC: jr          $ra
    // 0x80040BF0: nop

    return;
    // 0x80040BF0: nop

;}
RECOMP_FUNC void func_8001F9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F9B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001F9B4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001F9B8: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8001F9BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001F9C0: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001F9C4: lui         $at, 0x4026
    ctx->r1 = S32(0X4026 << 16);
    // 0x8001F9C8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001F9CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001F9D0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001F9D4: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8001F9D8: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8001F9DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001F9E0: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001F9E4: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8001F9E8: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8001F9EC: jal         0x8002413C
    // 0x8001F9F0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x8001F9F0: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8001F9F4: beq         $v0, $zero, L_8001FA50
    if (ctx->r2 == 0) {
        // 0x8001F9F8: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_8001FA50;
    }
    // 0x8001F9F8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001F9FC: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x8001FA00: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001FA04: lui         $t9, 0x803B
    ctx->r25 = S32(0X803B << 16);
    // 0x8001FA08: addiu       $t9, $t9, -0x73F8
    ctx->r25 = ADD32(ctx->r25, -0X73F8);
    // 0x8001FA0C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8001FA10: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8001FA14: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8001FA18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001FA1C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8001FA20: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001FA24: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x8001FA28: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8001FA2C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8001FA30: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8001FA34: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001FA38: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8001FA3C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8001FA40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001FA44: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001FA48: jal         0x80020F8C
    // 0x8001FA4C: addiu       $a1, $a1, -0x1E
    ctx->r5 = ADD32(ctx->r5, -0X1E);
    func_80020F8C(rdram, ctx);
        goto after_1;
    // 0x8001FA4C: addiu       $a1, $a1, -0x1E
    ctx->r5 = ADD32(ctx->r5, -0X1E);
    after_1:
L_8001FA50:
    // 0x8001FA50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001FA54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001FA58: jr          $ra
    // 0x8001FA5C: nop

    return;
    // 0x8001FA5C: nop

;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035200: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80035204: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80035208: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8003520C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x80035210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80035214: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80035218: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003521C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80035220: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_80035224:
    // 0x80035224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80035228: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8003522C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80035230: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80035234: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80035238: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8003523C: beq         $a0, $t3, L_800352A4
    if (ctx->r4 == ctx->r11) {
        // 0x80035240: nop
    
            goto L_800352A4;
    }
    // 0x80035240: nop

L_80035244:
    // 0x80035244: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80035248: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003524C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80035250: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80035254: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80035258: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8003525C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80035260: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x80035264: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80035268: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8003526C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80035270: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x80035274: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80035278: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8003527C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80035280: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x80035284: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x80035288: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8003528C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x80035290: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80035294: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80035298: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8003529C: bne         $a0, $t3, L_80035244
    if (ctx->r4 != ctx->r11) {
        // 0x800352A0: nop
    
            goto L_80035244;
    }
    // 0x800352A0: nop

L_800352A4:
    // 0x800352A4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800352A8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800352AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800352B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800352B4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800352B8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800352BC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800352C0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800352C4: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800352C8: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800352CC: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800352D0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800352D4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800352D8: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800352DC: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800352E0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800352E4: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800352E8: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800352EC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800352F0: bne         $a2, $t4, L_80035224
    if (ctx->r6 != ctx->r12) {
        // 0x800352F4: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80035224;
    }
    // 0x800352F4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800352F8: jr          $ra
    // 0x800352FC: nop

    return;
    // 0x800352FC: nop

;}
RECOMP_FUNC void func_80032020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032020: lui         $t8, 0x8007
    ctx->r24 = S32(0X8007 << 16);
    // 0x80032024: addiu       $t8, $t8, -0xC40
    ctx->r24 = ADD32(ctx->r24, -0XC40);
    // 0x80032028: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8003202C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80032030: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80032034: sw          $t9, -0xC08($at)
    MEM_W(-0XC08, ctx->r1) = ctx->r25;
    // 0x80032038: jr          $ra
    // 0x8003203C: nop

    return;
    // 0x8003203C: nop

;}
RECOMP_FUNC void func_8001E0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E0AC: lhu         $t6, 0x54($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X54);
    // 0x8001E0B0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E0B4: sh          $t7, 0x54($a1)
    MEM_H(0X54, ctx->r5) = ctx->r15;
    // 0x8001E0B8: lh          $v1, 0x2($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X2);
    // 0x8001E0BC: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x8001E0C0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E0C4: bnel        $at, $zero, L_8001E11C
    if (ctx->r1 != 0) {
        // 0x8001E0C8: lhu         $t5, 0x60($a1)
        ctx->r13 = MEM_HU(ctx->r5, 0X60);
            goto L_8001E11C;
    }
    goto skip_0;
    // 0x8001E0C8: lhu         $t5, 0x60($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X60);
    skip_0:
    // 0x8001E0CC: lh          $a0, 0x5A($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X5A);
    // 0x8001E0D0: lh          $t8, 0x52($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X52);
    // 0x8001E0D4: beql        $a0, $t8, L_8001E104
    if (ctx->r4 == ctx->r24) {
        // 0x8001E0D8: lhu         $t3, 0x60($a1)
        ctx->r11 = MEM_HU(ctx->r5, 0X60);
            goto L_8001E104;
    }
    goto skip_1;
    // 0x8001E0D8: lhu         $t3, 0x60($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X60);
    skip_1:
    // 0x8001E0DC: lhu         $t0, 0x60($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X60);
    // 0x8001E0E0: lhu         $t9, 0x5C($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X5C);
    // 0x8001E0E4: sh          $a0, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r4;
    // 0x8001E0E8: ori         $t1, $t0, 0x400
    ctx->r9 = ctx->r8 | 0X400;
    // 0x8001E0EC: sh          $zero, 0x54($a1)
    MEM_H(0X54, ctx->r5) = 0;
    // 0x8001E0F0: sh          $zero, 0x56($a1)
    MEM_H(0X56, ctx->r5) = 0;
    // 0x8001E0F4: sh          $t1, 0x60($a1)
    MEM_H(0X60, ctx->r5) = ctx->r9;
    // 0x8001E0F8: b           L_8001E124
    // 0x8001E0FC: sh          $t9, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r25;
        goto L_8001E124;
    // 0x8001E0FC: sh          $t9, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r25;
    // 0x8001E100: lhu         $t3, 0x60($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X60);
L_8001E104:
    // 0x8001E104: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x8001E108: sh          $t2, 0x54($a1)
    MEM_H(0X54, ctx->r5) = ctx->r10;
    // 0x8001E10C: ori         $t4, $t3, 0x200
    ctx->r12 = ctx->r11 | 0X200;
    // 0x8001E110: b           L_8001E124
    // 0x8001E114: sh          $t4, 0x60($a1)
    MEM_H(0X60, ctx->r5) = ctx->r12;
        goto L_8001E124;
    // 0x8001E114: sh          $t4, 0x60($a1)
    MEM_H(0X60, ctx->r5) = ctx->r12;
    // 0x8001E118: lhu         $t5, 0x60($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X60);
L_8001E11C:
    // 0x8001E11C: andi        $t6, $t5, 0xF9FF
    ctx->r14 = ctx->r13 & 0XF9FF;
    // 0x8001E120: sh          $t6, 0x60($a1)
    MEM_H(0X60, ctx->r5) = ctx->r14;
L_8001E124:
    // 0x8001E124: lhu         $t7, 0x56($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X56);
    // 0x8001E128: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001E12C: sh          $t8, 0x56($a1)
    MEM_H(0X56, ctx->r5) = ctx->r24;
    // 0x8001E130: jr          $ra
    // 0x8001E134: nop

    return;
    // 0x8001E134: nop

;}
RECOMP_FUNC void func_80022490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022490: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80022494: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80022498: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x8002249C: lui         $v1, 0x803B
    ctx->r3 = S32(0X803B << 16);
    // 0x800224A0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800224A4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800224A8: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800224AC: addiu       $t3, $t3, -0x4D1C
    ctx->r11 = ADD32(ctx->r11, -0X4D1C);
    // 0x800224B0: addiu       $t2, $t2, 0x5368
    ctx->r10 = ADD32(ctx->r10, 0X5368);
    // 0x800224B4: addiu       $t0, $t0, -0x2FF0
    ctx->r8 = ADD32(ctx->r8, -0X2FF0);
    // 0x800224B8: addiu       $v1, $v1, -0x6598
    ctx->r3 = ADD32(ctx->r3, -0X6598);
    // 0x800224BC: addiu       $v0, $v0, -0x6E70
    ctx->r2 = ADD32(ctx->r2, -0X6E70);
    // 0x800224C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800224C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800224C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800224CC: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800224D0: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800224D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800224D8: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800224DC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x800224E0: sw          $t8, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r24;
    // 0x800224E4: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x800224E8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800224EC: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x800224F0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800224F4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800224F8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800224FC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80022500: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80022504: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80022508: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8002250C: lhu         $t4, 0x2($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X2);
    // 0x80022510: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
    // 0x80022514: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80022518: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8002251C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80022520: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80022524: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80022528: swc1        $f4, -0x45C0($at)
    MEM_W(-0X45C0, ctx->r1) = ctx->f4.u32l;
    // 0x8002252C: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    // 0x80022530: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022534: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x80022538: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8002253C: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80022540: addiu       $t9, $zero, 0x108
    ctx->r25 = ADD32(0, 0X108);
    // 0x80022544: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80022548: swc1        $f6, -0x45BC($at)
    MEM_W(-0X45BC, ctx->r1) = ctx->f6.u32l;
    // 0x8002254C: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x80022550: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022554: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022558: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8002255C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80022560: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80022564: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80022568: lui         $t7, 0x803B
    ctx->r15 = S32(0X803B << 16);
    // 0x8002256C: swc1        $f8, -0x45B8($at)
    MEM_W(-0X45B8, ctx->r1) = ctx->f8.u32l;
    // 0x80022570: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022574: sw          $t9, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r25;
    // 0x80022578: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002257C: sh          $zero, -0x4542($at)
    MEM_H(-0X4542, ctx->r1) = 0;
    // 0x80022580: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022584: sh          $t4, -0x4D10($at)
    MEM_H(-0X4D10, ctx->r1) = ctx->r12;
    // 0x80022588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002258C: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80022590: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80022594: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80022598: lh          $t5, 0x10($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X10);
    // 0x8002259C: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800225A0: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x800225A4: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x800225A8: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800225AC: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x800225B0: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x800225B4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800225B8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800225BC: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800225C0: addiu       $t7, $t7, -0x65AC
    ctx->r15 = ADD32(ctx->r15, -0X65AC);
    // 0x800225C4: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x800225C8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800225CC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800225D0: lhu         $a1, 0x14($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X14);
    // 0x800225D4: lhu         $a0, 0x12($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X12);
    // 0x800225D8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800225DC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800225E0: jal         0x800177F8
    // 0x800225E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800177F8(rdram, ctx);
        goto after_0;
    // 0x800225E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800225E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800225EC: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x800225F0: jal         0x800268D4
    // 0x800225F4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_1;
    // 0x800225F4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_1:
    // 0x800225F8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800225FC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80022600: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80022604: jr          $ra
    // 0x80022608: nop

    return;
    // 0x80022608: nop

;}
RECOMP_FUNC void func_80031C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031C44: lui         $a0, 0xDA
    ctx->r4 = S32(0XDA << 16);
    // 0x80031C48: addiu       $a0, $a0, 0x68F0
    ctx->r4 = ADD32(ctx->r4, 0X68F0);
    // 0x80031C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031C50: lui         $t6, 0xDC
    ctx->r14 = S32(0XDC << 16);
    // 0x80031C54: addiu       $t6, $t6, 0x1620
    ctx->r14 = ADD32(ctx->r14, 0X1620);
    // 0x80031C58: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80031C5C: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80031C60: jal         0x80024260
    // 0x80031C64: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80031C64: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x80031C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031C6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031C70: jr          $ra
    // 0x80031C74: nop

    return;
    // 0x80031C74: nop

;}
RECOMP_FUNC void func_800399B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800399B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800399B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800399B8: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800399BC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800399C0: sh          $t6, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r14;
    // 0x800399C4: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x800399C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800399CC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800399D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800399D4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800399D8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800399DC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800399E0: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x800399E4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x800399E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800399EC: jal         0x8003FE6C
    // 0x800399F0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800399F0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800399F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800399F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800399FC: jr          $ra
    // 0x80039A00: nop

    return;
    // 0x80039A00: nop

    // 0x80039A04: nop

    // 0x80039A08: nop

    // 0x80039A0C: nop

;}
RECOMP_FUNC void func_80038C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038C00: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x80038C04: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80038C08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80038C0C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80038C10: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x80038C14: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038C18: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80038C1C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80038C20: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80038C24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80038C28: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80038C2C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80038C30: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80038C34: jal         0x80038AEC
    // 0x80038C38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80038AEC(rdram, ctx);
        goto after_0;
    // 0x80038C38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80038C3C: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80038C40: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x80038C44: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80038C48: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_80038C4C:
    // 0x80038C4C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80038C50: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80038C54: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80038C58: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80038C5C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80038C60: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80038C64: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x80038C68: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80038C6C: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_80038C70:
    // 0x80038C70: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x80038C74: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80038C78: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80038C7C: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x80038C80: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x80038C84: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80038C88: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80038C8C: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x80038C90: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x80038C94: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x80038C98: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x80038C9C: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x80038CA0: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x80038CA4: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x80038CA8: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x80038CAC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80038CB0: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x80038CB4: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x80038CB8: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x80038CBC: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x80038CC0: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x80038CC4: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x80038CC8: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x80038CCC: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x80038CD0: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x80038CD4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80038CD8: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x80038CDC: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x80038CE0: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x80038CE4: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x80038CE8: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x80038CEC: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x80038CF0: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x80038CF4: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x80038CF8: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x80038CFC: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x80038D00: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x80038D04: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x80038D08: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x80038D0C: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x80038D10: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x80038D14: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x80038D18: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x80038D1C: bne         $a0, $s0, L_80038C70
    if (ctx->r4 != ctx->r16) {
        // 0x80038D20: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_80038C70;
    }
    // 0x80038D20: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x80038D24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80038D28: jal         0x800387F4
    // 0x80038D2C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800387F4(rdram, ctx);
        goto after_1;
    // 0x80038D2C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80038D30: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x80038D34: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80038D38: beq         $t0, $s5, L_80038D48
    if (ctx->r8 == ctx->r21) {
        // 0x80038D3C: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_80038D48;
    }
    // 0x80038D3C: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x80038D40: bnel        $at, $zero, L_80038C4C
    if (ctx->r1 != 0) {
        // 0x80038D44: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_80038C4C;
    }
    goto skip_0;
    // 0x80038D44: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_80038D48:
    // 0x80038D48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80038D4C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80038D50: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80038D54: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80038D58: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80038D5C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80038D60: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80038D64: jr          $ra
    // 0x80038D68: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x80038D68: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void func_80008BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008BB8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008BBC: sw          $zero, -0x3670($at)
    MEM_W(-0X3670, ctx->r1) = 0;
    // 0x80008BC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008BC4: sw          $zero, -0x2F74($at)
    MEM_W(-0X2F74, ctx->r1) = 0;
    // 0x80008BC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008BCC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80008BD0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80008BD4: addiu       $v0, $v0, -0x3540
    ctx->r2 = ADD32(ctx->r2, -0X3540);
    // 0x80008BD8: sh          $v1, -0x35F4($at)
    MEM_H(-0X35F4, ctx->r1) = ctx->r3;
    // 0x80008BDC: sh          $v1, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r3;
    // 0x80008BE0: sh          $v1, 0x19C($v0)
    MEM_H(0X19C, ctx->r2) = ctx->r3;
    // 0x80008BE4: sh          $v1, 0x514($v0)
    MEM_H(0X514, ctx->r2) = ctx->r3;
    // 0x80008BE8: sh          $v1, 0x3EC($v0)
    MEM_H(0X3EC, ctx->r2) = ctx->r3;
    // 0x80008BEC: sh          $v1, 0x2C4($v0)
    MEM_H(0X2C4, ctx->r2) = ctx->r3;
    // 0x80008BF0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80008BF4: lhu         $t6, 0x4F10($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4F10);
    // 0x80008BF8: addiu       $v0, $v0, 0x4A0
    ctx->r2 = ADD32(ctx->r2, 0X4A0);
    // 0x80008BFC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80008C00: beql        $t7, $zero, L_80008C14
    if (ctx->r15 == 0) {
        // 0x80008C04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80008C14;
    }
    goto skip_0;
    // 0x80008C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80008C08: jal         0x80008EF4
    // 0x80008C0C: nop

    func_80008EF4(rdram, ctx);
        goto after_0;
    // 0x80008C0C: nop

    after_0:
    // 0x80008C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80008C14:
    // 0x80008C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008C18: jr          $ra
    // 0x80008C1C: nop

    return;
    // 0x80008C1C: nop

;}
RECOMP_FUNC void func_8000F238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F238: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8000F23C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8000F240: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x8000F244: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x8000F248: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x8000F24C: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x8000F250: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8000F254: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x8000F258: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8000F25C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8000F260: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8000F264: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8000F268: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8000F26C: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8000F270: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8000F274: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8000F278: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8000F27C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8000F280: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8000F284: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8000F288: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8000F28C: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x8000F290: lw          $s1, 0x14($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X14);
    // 0x8000F294: lw          $s4, 0x1C($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1C);
    // 0x8000F298: beql        $s1, $zero, L_8000F564
    if (ctx->r17 == 0) {
        // 0x8000F29C: lw          $v0, 0x88($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X88);
            goto L_8000F564;
    }
    goto skip_0;
    // 0x8000F29C: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    skip_0:
    // 0x8000F2A0: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8000F2A4: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x8000F2A8: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x8000F2AC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8000F2B0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8000F2B4: lh          $t0, 0xA($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XA);
    // 0x8000F2B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000F2BC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8000F2C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000F2C4: mul.s       $f0, $f6, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8000F2C8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8000F2CC: mul.s       $f20, $f10, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8000F2D0: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
    // 0x8000F2D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000F2D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F2DC: mul.s       $f2, $f4, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8000F2E0: nop

    // 0x8000F2E4: mul.s       $f22, $f8, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8000F2E8: bc1t        L_8000F320
    if (c1cs) {
        // 0x8000F2EC: nop
    
            goto L_8000F320;
    }
    // 0x8000F2EC: nop

    // 0x8000F2F0: c.lt.s      $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f20.fl < ctx->f30.fl;
    // 0x8000F2F4: nop

    // 0x8000F2F8: bc1t        L_8000F320
    if (c1cs) {
        // 0x8000F2FC: nop
    
            goto L_8000F320;
    }
    // 0x8000F2FC: nop

    // 0x8000F300: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8000F304: nop

    // 0x8000F308: bc1t        L_8000F320
    if (c1cs) {
        // 0x8000F30C: nop
    
            goto L_8000F320;
    }
    // 0x8000F30C: nop

    // 0x8000F310: c.lt.s      $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f22.fl < ctx->f14.fl;
    // 0x8000F314: nop

    // 0x8000F318: bc1fl       L_8000F32C
    if (!c1cs) {
        // 0x8000F31C: lhu         $s3, 0x18($a0)
        ctx->r19 = MEM_HU(ctx->r4, 0X18);
            goto L_8000F32C;
    }
    goto skip_1;
    // 0x8000F31C: lhu         $s3, 0x18($a0)
    ctx->r19 = MEM_HU(ctx->r4, 0X18);
    skip_1:
L_8000F320:
    // 0x8000F320: b           L_8000F564
    // 0x8000F324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F564;
    // 0x8000F324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000F328: lhu         $s3, 0x18($a0)
    ctx->r19 = MEM_HU(ctx->r4, 0X18);
L_8000F32C:
    // 0x8000F32C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x8000F330: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8000F334: beql        $s3, $zero, L_8000F564
    if (ctx->r19 == 0) {
        // 0x8000F338: lw          $v0, 0x88($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X88);
            goto L_8000F564;
    }
    goto skip_2;
    // 0x8000F338: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    skip_2:
L_8000F33C:
    // 0x8000F33C: lhu         $t1, 0x6($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0X6);
    // 0x8000F340: and         $t2, $t1, $s6
    ctx->r10 = ctx->r9 & ctx->r22;
    // 0x8000F344: beql        $t2, $zero, L_8000F558
    if (ctx->r10 == 0) {
        // 0x8000F348: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_8000F558;
    }
    goto skip_3;
    // 0x8000F348: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_3:
    // 0x8000F34C: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8000F350: lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X2);
    // 0x8000F354: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    // 0x8000F358: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x8000F35C: addu        $s2, $s4, $t3
    ctx->r18 = ADD32(ctx->r20, ctx->r11);
    // 0x8000F360: lh          $t4, 0x0($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X0);
    // 0x8000F364: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8000F368: addu        $v0, $s4, $t6
    ctx->r2 = ADD32(ctx->r20, ctx->r14);
    // 0x8000F36C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8000F370: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x8000F374: addu        $v1, $s4, $t9
    ctx->r3 = ADD32(ctx->r20, ctx->r25);
    // 0x8000F378: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000F37C: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8000F380: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8000F384: lh          $t5, 0x4($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X4);
    // 0x8000F388: c.eq.s      $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f30.fl == ctx->f4.fl;
    // 0x8000F38C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8000F390: nop

    // 0x8000F394: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F398: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8000F39C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x8000F3A0: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8000F3A4: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8000F3A8: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x8000F3AC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8000F3B0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8000F3B4: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x8000F3B8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000F3BC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000F3C0: mul.s       $f20, $f6, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8000F3C4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8000F3C8: mul.s       $f22, $f18, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8000F3CC: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8000F3D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000F3D4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000F3D8: mul.s       $f24, $f8, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8000F3DC: nop

    // 0x8000F3E0: mul.s       $f26, $f6, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8000F3E4: bc1f        L_8000F404
    if (!c1cs) {
        // 0x8000F3E8: nop
    
            goto L_8000F404;
    }
    // 0x8000F3E8: nop

    // 0x8000F3EC: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
    // 0x8000F3F0: nop

    // 0x8000F3F4: bc1fl       L_8000F408
    if (!c1cs) {
        // 0x8000F3F8: c.eq.s      $f30, $f20
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl == ctx->f20.fl;
            goto L_8000F408;
    }
    goto skip_4;
    // 0x8000F3F8: c.eq.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl == ctx->f20.fl;
    skip_4:
    // 0x8000F3FC: b           L_8000F4B4
    // 0x8000F400: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
        goto L_8000F4B4;
    // 0x8000F400: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_8000F404:
    // 0x8000F404: c.eq.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl == ctx->f20.fl;
L_8000F408:
    // 0x8000F408: nop

    // 0x8000F40C: bc1fl       L_8000F430
    if (!c1cs) {
        // 0x8000F410: c.eq.s      $f30, $f24
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f30.fl == ctx->f24.fl;
            goto L_8000F430;
    }
    goto skip_5;
    // 0x8000F410: c.eq.s      $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f30.fl == ctx->f24.fl;
    skip_5:
    // 0x8000F414: c.eq.s      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.fl == ctx->f22.fl;
    // 0x8000F418: nop

    // 0x8000F41C: bc1fl       L_8000F430
    if (!c1cs) {
        // 0x8000F420: c.eq.s      $f30, $f24
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f30.fl == ctx->f24.fl;
            goto L_8000F430;
    }
    goto skip_6;
    // 0x8000F420: c.eq.s      $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f30.fl == ctx->f24.fl;
    skip_6:
    // 0x8000F424: b           L_8000F4B4
    // 0x8000F428: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
        goto L_8000F4B4;
    // 0x8000F428: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x8000F42C: c.eq.s      $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f30.fl == ctx->f24.fl;
L_8000F430:
    // 0x8000F430: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8000F434: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8000F438: bc1fl       L_8000F45C
    if (!c1cs) {
        // 0x8000F43C: mov.s       $f12, $f30
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
            goto L_8000F45C;
    }
    goto skip_7;
    // 0x8000F43C: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    skip_7:
    // 0x8000F440: c.eq.s      $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f14.fl == ctx->f26.fl;
    // 0x8000F444: nop

    // 0x8000F448: bc1fl       L_8000F45C
    if (!c1cs) {
        // 0x8000F44C: mov.s       $f12, $f30
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
            goto L_8000F45C;
    }
    goto skip_8;
    // 0x8000F44C: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    skip_8:
    // 0x8000F450: b           L_8000F4B4
    // 0x8000F454: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
        goto L_8000F4B4;
    // 0x8000F454: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x8000F458: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
L_8000F45C:
    // 0x8000F45C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8000F460: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8000F464: jal         0x8000F5A4
    // 0x8000F468: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    func_8000F5A4(rdram, ctx);
        goto after_0;
    // 0x8000F468: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8000F46C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8000F470: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8000F474: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8000F478: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000F47C: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    // 0x8000F480: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8000F484: jal         0x8000F5A4
    // 0x8000F488: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_8000F5A4(rdram, ctx);
        goto after_1;
    // 0x8000F488: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_1:
    // 0x8000F48C: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8000F490: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8000F494: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    // 0x8000F498: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8000F49C: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8000F4A0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8000F4A4: jal         0x8000F5A4
    // 0x8000F4A8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_8000F5A4(rdram, ctx);
        goto after_2;
    // 0x8000F4A8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_2:
    // 0x8000F4AC: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8000F4B0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_8000F4B4:
    // 0x8000F4B4: bnel        $s0, $s5, L_8000F558
    if (ctx->r16 != ctx->r21) {
        // 0x8000F4B8: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_8000F558;
    }
    goto skip_9;
    // 0x8000F4B8: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_9:
    // 0x8000F4BC: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x8000F4C0: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000F4C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000F4C8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8000F4CC: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000F4D0: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8000F4D4: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000F4D8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000F4DC: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8000F4E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000F4E4: mul.s       $f16, $f18, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8000F4E8: bc1tl       L_8000F53C
    if (c1cs) {
        // 0x8000F4EC: lhu         $t4, 0x6($s1)
        ctx->r12 = MEM_HU(ctx->r17, 0X6);
            goto L_8000F53C;
    }
    goto skip_10;
    // 0x8000F4EC: lhu         $t4, 0x6($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X6);
    skip_10:
    // 0x8000F4F0: mul.s       $f4, $f2, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f30.fl);
    // 0x8000F4F4: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F4F8: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8000F4FC: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8000F500: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8000F504: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000F508: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8000F50C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8000F510: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000F514: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8000F518: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000F51C: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8000F520: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x8000F524: div.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8000F528: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8000F52C: lhu         $t3, 0x6($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X6);
    // 0x8000F530: b           L_8000F540
    // 0x8000F534: sh          $t3, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r11;
        goto L_8000F540;
    // 0x8000F534: sh          $t3, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r11;
    // 0x8000F538: lhu         $t4, 0x6($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X6);
L_8000F53C:
    // 0x8000F53C: sh          $t4, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r12;
L_8000F540:
    // 0x8000F540: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x8000F544: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8000F548: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x8000F54C: b           L_8000F560
    // 0x8000F550: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
        goto L_8000F560;
    // 0x8000F550: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    // 0x8000F554: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_8000F558:
    // 0x8000F558: bne         $s3, $zero, L_8000F33C
    if (ctx->r19 != 0) {
        // 0x8000F55C: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_8000F33C;
    }
    // 0x8000F55C: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_8000F560:
    // 0x8000F560: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
L_8000F564:
    // 0x8000F564: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8000F568: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8000F56C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8000F570: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8000F574: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8000F578: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8000F57C: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8000F580: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8000F584: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8000F588: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8000F58C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8000F590: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8000F594: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8000F598: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8000F59C: jr          $ra
    // 0x8000F5A0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8000F5A0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80100BA0_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100BA0: addiu       $sp, $sp, -0x3F0
    ctx->r29 = ADD32(ctx->r29, -0X3F0);
    // 0x80100BA4: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80100BA8: addiu       $v1, $v1, 0x3130
    ctx->r3 = ADD32(ctx->r3, 0X3130);
    // 0x80100BAC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80100BB0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80100BB4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80100BB8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80100BBC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80100BC0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80100BC4: bne         $t6, $zero, L_80100C24
    if (ctx->r14 != 0) {
        // 0x80100BC8: sw          $a0, 0x3F0($sp)
        MEM_W(0X3F0, ctx->r29) = ctx->r4;
            goto L_80100C24;
    }
    // 0x80100BC8: sw          $a0, 0x3F0($sp)
    MEM_W(0X3F0, ctx->r29) = ctx->r4;
    // 0x80100BCC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80100BD0: lbu         $v0, -0x4CBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4CBC);
    // 0x80100BD4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100BD8: sw          $zero, 0x3400($at)
    MEM_W(0X3400, ctx->r1) = 0;
    // 0x80100BDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100BE0: andi        $t7, $v0, 0xF0
    ctx->r15 = ctx->r2 & 0XF0;
    // 0x80100BE4: beq         $t7, $zero, L_80100C04
    if (ctx->r15 == 0) {
        // 0x80100BE8: sb          $zero, -0x52B0($at)
        MEM_B(-0X52B0, ctx->r1) = 0;
            goto L_80100C04;
    }
    // 0x80100BE8: sb          $zero, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = 0;
    // 0x80100BEC: sra         $t8, $v0, 4
    ctx->r24 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80100BF0: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80100BF4: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80100BF8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100BFC: b           L_80100C0C
    // 0x80100C00: sb          $t6, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = ctx->r14;
        goto L_80100C0C;
    // 0x80100C00: sb          $t6, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = ctx->r14;
L_80100C04:
    // 0x80100C04: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100C08: sb          $zero, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = 0;
L_80100C0C:
    // 0x80100C0C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80100C10: addiu       $t7, $t7, 0x53E8
    ctx->r15 = ADD32(ctx->r15, 0X53E8);
    // 0x80100C14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80100C18: sw          $t7, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r15;
    // 0x80100C1C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80100C20: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80100C24:
    // 0x80100C24: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80100C28: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x80100C2C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100C30: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80100C34: addiu       $t7, $t7, 0x3190
    ctx->r15 = ADD32(ctx->r15, 0X3190);
    // 0x80100C38: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100C3C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80100C40: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80100C44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80100C48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80100C4C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100C50: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x80100C54: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x80100C58: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100C5C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80100C60: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80100C64: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100C68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100C6C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100C70: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80100C74: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80100C78: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100C7C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100C80: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80100C84: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x80100C88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100C8C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100C90: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100C94: lui         $s2, 0xE700
    ctx->r18 = S32(0XE700 << 16);
    // 0x80100C98: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80100C9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100CA0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100CA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100CA8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80100CAC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100CB0: addiu       $t9, $t9, -0x6F70
    ctx->r25 = ADD32(ctx->r25, -0X6F70);
    // 0x80100CB4: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80100CB8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100CBC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100CC0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100CC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100CC8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100CCC: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80100CD0: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x80100CD4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100CD8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100CDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100CE0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100CE4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100CE8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80100CEC: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x80100CF0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100CF4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80100CF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100CFC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100D00: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100D04: lui         $s3, 0xE600
    ctx->r19 = S32(0XE600 << 16);
    // 0x80100D08: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x80100D0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100D10: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100D14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100D18: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80100D1C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100D20: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80100D24: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80100D28: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100D2C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80100D30: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100D34: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100D38: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100D3C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80100D40: addiu       $t8, $t8, -0x6D70
    ctx->r24 = ADD32(ctx->r24, -0X6D70);
    // 0x80100D44: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100D48: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100D4C: lui         $s1, 0xF548
    ctx->r17 = S32(0XF548 << 16);
    // 0x80100D50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100D54: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80100D58: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80100D5C: ori         $s1, $s1, 0x5000
    ctx->r17 = ctx->r17 | 0X5000;
    // 0x80100D60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80100D64: addiu       $ra, $zero, 0x5
    ctx->r31 = ADD32(0, 0X5);
    // 0x80100D68: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
L_80100D6C:
    // 0x80100D6C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100D70: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x80100D74: ori         $t6, $t6, 0x13F
    ctx->r14 = ctx->r14 | 0X13F;
    // 0x80100D78: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100D7C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80100D80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80100D84: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80100D88: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80100D8C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80100D90: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80100D94: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100D98: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80100D9C: sll         $a3, $ra, 2
    ctx->r7 = S32(ctx->r31 << 2);
    // 0x80100DA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100DA4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80100DA8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100DAC: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80100DB0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100DB4: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80100DB8: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80100DBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100DC0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100DC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100DC8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80100DCC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100DD0: lui         $at, 0x74F
    ctx->r1 = S32(0X74F << 16);
    // 0x80100DD4: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80100DD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100DDC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100DE0: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x80100DE4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80100DE8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80100DEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100DF0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100DF4: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x80100DF8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80100DFC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100E00: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80100E04: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100E08: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80100E0C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100E10: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80100E14: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80100E18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100E1C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80100E20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100E24: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80100E28: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100E2C: lui         $at, 0x4F
    ctx->r1 = S32(0X4F << 16);
    // 0x80100E30: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80100E34: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100E38: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100E3C: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x80100E40: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80100E44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100E48: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100E4C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80100E50: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80100E54: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100E58: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80100E5C: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x80100E60: sw          $v0, 0x398($sp)
    MEM_W(0X398, ctx->r29) = ctx->r2;
    // 0x80100E64: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80100E68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100E6C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80100E70: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100E74: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x80100E78: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80100E7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100E80: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100E84: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80100E88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100E8C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100E90: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100E94: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80100E98: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80100E9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100EA0: slti        $at, $t5, 0xE4
    ctx->r1 = SIGNED(ctx->r13) < 0XE4 ? 1 : 0;
    // 0x80100EA4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100EA8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80100EAC: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80100EB0: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80100EB4: addiu       $ra, $ra, 0x6
    ctx->r31 = ADD32(ctx->r31, 0X6);
    // 0x80100EB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100EBC: bne         $at, $zero, L_80100D6C
    if (ctx->r1 != 0) {
        // 0x80100EC0: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_80100D6C;
    }
    // 0x80100EC0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80100EC4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100EC8: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x80100ECC: ori         $t6, $t6, 0x13F
    ctx->r14 = ctx->r14 | 0X13F;
    // 0x80100ED0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100ED4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80100ED8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80100EDC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80100EE0: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80100EE4: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80100EE8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80100EEC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100EF0: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80100EF4: addiu       $a3, $s0, 0x1
    ctx->r7 = ADD32(ctx->r16, 0X1);
    // 0x80100EF8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100EFC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80100F00: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100F04: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80100F08: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100F0C: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x80100F10: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80100F14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100F18: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100F1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100F20: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80100F24: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100F28: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80100F2C: lui         $at, 0x74F
    ctx->r1 = S32(0X74F << 16);
    // 0x80100F30: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100F34: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100F38: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80100F3C: andi        $a3, $t6, 0xFFF
    ctx->r7 = ctx->r14 & 0XFFF;
    // 0x80100F40: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x80100F44: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x80100F48: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80100F4C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100F50: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100F54: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80100F58: or          $t8, $t4, $at
    ctx->r24 = ctx->r12 | ctx->r1;
    // 0x80100F5C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100F60: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80100F64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100F68: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80100F6C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100F70: lui         $at, 0x4F
    ctx->r1 = S32(0X4F << 16);
    // 0x80100F74: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80100F78: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100F7C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100F80: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100F84: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80100F88: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100F8C: or          $t9, $a3, $at
    ctx->r25 = ctx->r7 | ctx->r1;
    // 0x80100F90: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x80100F94: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100F98: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100F9C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100FA0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100FA4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100FA8: addiu       $t7, $s0, 0x2
    ctx->r15 = ADD32(ctx->r16, 0X2);
    // 0x80100FAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80100FB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100FB4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80100FB8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80100FBC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80100FC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80100FC4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80100FC8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100FCC: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x80100FD0: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80100FD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100FD8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100FDC: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80100FE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100FE4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100FE8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80100FEC: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80100FF0: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80100FF4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100FF8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80100FFC: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x80101000: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101004: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101008: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010100C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80101010: addiu       $t9, $t9, 0x5550
    ctx->r25 = ADD32(ctx->r25, 0X5550);
    // 0x80101014: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101018: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8010101C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101020: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101024: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101028: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8010102C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80101030: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101034: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101038: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010103C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101040: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101044: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80101048: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8010104C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101050: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101054: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101058: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010105C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101060: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80101064: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x80101068: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010106C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101070: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101074: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101078: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010107C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x80101080: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80101084: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101088: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8010108C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101090: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80101094: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101098: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x8010109C: addiu       $s1, $zero, 0x53
    ctx->r17 = ADD32(0, 0X53);
    // 0x801010A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801010A4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801010A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801010AC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801010B0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801010B4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x801010B8: addiu       $t9, $t9, 0x5750
    ctx->r25 = ADD32(ctx->r25, 0X5750);
    // 0x801010BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801010C0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801010C4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801010C8: sw          $v0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r2;
    // 0x801010CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801010D0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801010D4: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x801010D8: addiu       $ra, $zero, 0x5B
    ctx->r31 = ADD32(0, 0X5B);
L_801010DC:
    // 0x801010DC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801010E0: lui         $t7, 0xFD48
    ctx->r15 = S32(0XFD48 << 16);
    // 0x801010E4: ori         $t7, $t7, 0xDD
    ctx->r15 = ctx->r15 | 0XDD;
    // 0x801010E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801010EC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801010F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801010F4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801010F8: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x801010FC: ori         $t6, $t6, 0x3800
    ctx->r14 = ctx->r14 | 0X3800;
    // 0x80101100: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101104: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101108: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8010110C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80101110: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101114: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101118: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010111C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101120: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101124: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x80101128: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8010112C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101130: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101134: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101138: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8010113C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101140: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80101144: lui         $at, 0x737
    ctx->r1 = S32(0X737 << 16);
    // 0x80101148: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010114C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101150: sll         $a3, $t5, 2
    ctx->r7 = S32(ctx->r13 << 2);
    // 0x80101154: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x80101158: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x8010115C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80101160: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101164: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101168: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010116C: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80101170: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80101174: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101178: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8010117C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101180: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101184: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101188: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x8010118C: ori         $t8, $t8, 0x3800
    ctx->r24 = ctx->r24 | 0X3800;
    // 0x80101190: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101194: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101198: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010119C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801011A0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801011A4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801011A8: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x801011AC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801011B0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801011B4: lui         $at, 0x37
    ctx->r1 = S32(0X37 << 16);
    // 0x801011B8: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801011BC: or          $t7, $a3, $at
    ctx->r15 = ctx->r7 | ctx->r1;
    // 0x801011C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801011C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801011C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801011CC: lui         $at, 0xE443
    ctx->r1 = S32(0XE443 << 16);
    // 0x801011D0: sll         $t9, $ra, 2
    ctx->r25 = S32(ctx->r31 << 2);
    // 0x801011D4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x801011D8: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x801011DC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x801011E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801011E4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801011E8: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x801011EC: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x801011F0: sw          $v0, 0x32C($sp)
    MEM_W(0X32C, ctx->r29) = ctx->r2;
    // 0x801011F4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x801011F8: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801011FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101200: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80101204: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101208: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010120C: sll         $t7, $s0, 5
    ctx->r15 = S32(ctx->r16 << 5);
    // 0x80101210: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80101214: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101218: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8010121C: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x80101220: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101224: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101228: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010122C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80101230: addiu       $at, $zero, 0x93
    ctx->r1 = ADD32(0, 0X93);
    // 0x80101234: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101238: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8010123C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101240: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80101244: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80101248: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8010124C: addiu       $ra, $ra, 0x8
    ctx->r31 = ADD32(ctx->r31, 0X8);
    // 0x80101250: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x80101254: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101258: bne         $s1, $at, L_801010DC
    if (ctx->r17 != ctx->r1) {
        // 0x8010125C: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_801010DC;
    }
    // 0x8010125C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101260: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101264: lui         $t9, 0xFD48
    ctx->r25 = S32(0XFD48 << 16);
    // 0x80101268: ori         $t9, $t9, 0xDD
    ctx->r25 = ctx->r25 | 0XDD;
    // 0x8010126C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101270: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101274: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101278: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8010127C: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x80101280: ori         $t8, $t8, 0x3800
    ctx->r24 = ctx->r24 | 0X3800;
    // 0x80101284: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101288: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010128C: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80101290: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80101294: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101298: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8010129C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801012A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801012A4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801012A8: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x801012AC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x801012B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801012B4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801012B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801012BC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801012C0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801012C4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801012C8: addiu       $a3, $s0, 0x1
    ctx->r7 = ADD32(ctx->r16, 0X1);
    // 0x801012CC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x801012D0: lui         $at, 0x737
    ctx->r1 = S32(0X737 << 16);
    // 0x801012D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801012D8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801012DC: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801012E0: andi        $a3, $t6, 0xFFF
    ctx->r7 = ctx->r14 & 0XFFF;
    // 0x801012E4: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x801012E8: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x801012EC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801012F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801012F4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801012F8: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x801012FC: ori         $t7, $t7, 0x3800
    ctx->r15 = ctx->r15 | 0X3800;
    // 0x80101300: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101304: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101308: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010130C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101310: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101314: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80101318: or          $t9, $t4, $at
    ctx->r25 = ctx->r12 | ctx->r1;
    // 0x8010131C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101320: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101324: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101328: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010132C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101330: lui         $at, 0x37
    ctx->r1 = S32(0X37 << 16);
    // 0x80101334: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80101338: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010133C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101340: or          $t6, $a3, $at
    ctx->r14 = ctx->r7 | ctx->r1;
    // 0x80101344: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101348: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8010134C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101350: addiu       $t8, $s0, 0x55
    ctx->r24 = ADD32(ctx->r16, 0X55);
    // 0x80101354: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80101358: lui         $at, 0xE443
    ctx->r1 = S32(0XE443 << 16);
    // 0x8010135C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101360: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101364: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80101368: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8010136C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80101370: lui         $at, 0xC
    ctx->r1 = S32(0XC << 16);
    // 0x80101374: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80101378: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8010137C: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80101380: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80101384: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101388: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010138C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101390: sll         $t9, $s0, 5
    ctx->r25 = S32(ctx->r16 << 5);
    // 0x80101394: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80101398: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010139C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801013A0: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x801013A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801013A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801013AC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801013B0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801013B4: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x801013B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801013BC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801013C0: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x801013C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801013C8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801013CC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801013D0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x801013D4: addiu       $t9, $t9, 0x4A30
    ctx->r25 = ADD32(ctx->r25, 0X4A30);
    // 0x801013D8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801013DC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801013E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801013E4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801013E8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801013EC: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x801013F0: lui         $s1, 0xFD48
    ctx->r17 = S32(0XFD48 << 16);
    // 0x801013F4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801013F8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801013FC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101400: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101404: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101408: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8010140C: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x80101410: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101414: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101418: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010141C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101420: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101424: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80101428: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8010142C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101430: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101434: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101438: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8010143C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101440: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x80101444: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80101448: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010144C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101450: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101454: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80101458: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010145C: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80101460: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x80101464: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101468: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8010146C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101470: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101474: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101478: ori         $s1, $s1, 0x4F
    ctx->r17 = ctx->r17 | 0X4F;
    // 0x8010147C: addiu       $t5, $t5, 0x4528
    ctx->r13 = ADD32(ctx->r13, 0X4528);
    // 0x80101480: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101484: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101488: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010148C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101490: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101494: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80101498: ori         $t6, $t6, 0x1400
    ctx->r14 = ctx->r14 | 0X1400;
    // 0x8010149C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801014A0: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801014A4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801014A8: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x801014AC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801014B0: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x801014B4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x801014B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801014BC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801014C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801014C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801014C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801014CC: lui         $t7, 0x712
    ctx->r15 = S32(0X712 << 16);
    // 0x801014D0: ori         $t7, $t7, 0x4024
    ctx->r15 = ctx->r15 | 0X4024;
    // 0x801014D4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801014D8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801014DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801014E0: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801014E4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801014E8: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x801014EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801014F0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801014F4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801014F8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801014FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101500: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101504: lui         $t6, 0xF540
    ctx->r14 = S32(0XF540 << 16);
    // 0x80101508: ori         $t6, $t6, 0x1400
    ctx->r14 = ctx->r14 | 0X1400;
    // 0x8010150C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101510: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101514: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101518: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010151C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101520: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80101524: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101528: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8010152C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101530: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101534: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101538: lui         $t9, 0x24
    ctx->r25 = S32(0X24 << 16);
    // 0x8010153C: ori         $t9, $t9, 0x8024
    ctx->r25 = ctx->r25 | 0X8024;
    // 0x80101540: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101544: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101548: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010154C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101550: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101554: lui         $t8, 0x15
    ctx->r24 = S32(0X15 << 16);
    // 0x80101558: lui         $t7, 0xE43A
    ctx->r15 = S32(0XE43A << 16);
    // 0x8010155C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101560: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101564: ori         $t7, $t7, 0x2F0
    ctx->r15 = ctx->r15 | 0X2F0;
    // 0x80101568: ori         $t8, $t8, 0x42C8
    ctx->r24 = ctx->r24 | 0X42C8;
    // 0x8010156C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101570: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101574: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101578: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x8010157C: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x80101580: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101584: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101588: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010158C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101590: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101594: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80101598: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x8010159C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801015A0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801015A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801015A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801015AC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801015B0: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x801015B4: ori         $t8, $t8, 0x1400
    ctx->r24 = ctx->r24 | 0X1400;
    // 0x801015B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801015BC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801015C0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801015C4: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x801015C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801015CC: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x801015D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801015D4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801015D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801015DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801015E0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801015E4: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x801015E8: lui         $t9, 0x712
    ctx->r25 = S32(0X712 << 16);
    // 0x801015EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801015F0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801015F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801015F8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801015FC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101600: ori         $t9, $t9, 0x403C
    ctx->r25 = ctx->r25 | 0X403C;
    // 0x80101604: ori         $t8, $t8, 0x28
    ctx->r24 = ctx->r24 | 0X28;
    // 0x80101608: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010160C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101610: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101614: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101618: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010161C: lui         $t8, 0xF540
    ctx->r24 = S32(0XF540 << 16);
    // 0x80101620: ori         $t8, $t8, 0x1400
    ctx->r24 = ctx->r24 | 0X1400;
    // 0x80101624: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101628: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8010162C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101630: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101634: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80101638: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8010163C: ori         $t6, $t6, 0x28
    ctx->r14 = ctx->r14 | 0X28;
    // 0x80101640: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80101644: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101648: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8010164C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80101650: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101654: lui         $t7, 0x24
    ctx->r15 = S32(0X24 << 16);
    // 0x80101658: ori         $t7, $t7, 0x803C
    ctx->r15 = ctx->r15 | 0X803C;
    // 0x8010165C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101660: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101664: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101668: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8010166C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101670: lui         $t6, 0x15
    ctx->r14 = S32(0X15 << 16);
    // 0x80101674: lui         $t9, 0xE43A
    ctx->r25 = S32(0XE43A << 16);
    // 0x80101678: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010167C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101680: ori         $t9, $t9, 0x308
    ctx->r25 = ctx->r25 | 0X308;
    // 0x80101684: ori         $t6, $t6, 0x42F0
    ctx->r14 = ctx->r14 | 0X42F0;
    // 0x80101688: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010168C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101690: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101694: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x80101698: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x8010169C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801016A0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801016A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801016A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801016AC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801016B0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x801016B4: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x801016B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801016BC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801016C0: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x801016C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801016C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801016CC: lb          $v1, 0x2871($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X2871);
    // 0x801016D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801016D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801016D8: slti        $at, $v1, 0x15
    ctx->r1 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // 0x801016DC: bnel        $at, $zero, L_801016F0
    if (ctx->r1 != 0) {
        // 0x801016E0: slti        $at, $v1, -0x14
        ctx->r1 = SIGNED(ctx->r3) < -0X14 ? 1 : 0;
            goto L_801016F0;
    }
    goto skip_0;
    // 0x801016E0: slti        $at, $v1, -0x14
    ctx->r1 = SIGNED(ctx->r3) < -0X14 ? 1 : 0;
    skip_0:
    // 0x801016E4: b           L_801016FC
    // 0x801016E8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_801016FC;
    // 0x801016E8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801016EC: slti        $at, $v1, -0x14
    ctx->r1 = SIGNED(ctx->r3) < -0X14 ? 1 : 0;
L_801016F0:
    // 0x801016F0: beq         $at, $zero, L_801016FC
    if (ctx->r1 == 0) {
        // 0x801016F4: nop
    
            goto L_801016FC;
    }
    // 0x801016F4: nop

    // 0x801016F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801016FC:
    // 0x801016FC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80101700: lb          $v1, 0x2872($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X2872);
    // 0x80101704: slti        $at, $v1, 0x15
    ctx->r1 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // 0x80101708: bne         $at, $zero, L_80101718
    if (ctx->r1 != 0) {
        // 0x8010170C: ori         $t9, $v0, 0x1
        ctx->r25 = ctx->r2 | 0X1;
            goto L_80101718;
    }
    // 0x8010170C: ori         $t9, $v0, 0x1
    ctx->r25 = ctx->r2 | 0X1;
    // 0x80101710: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x80101714: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
L_80101718:
    // 0x80101718: slti        $at, $v1, -0x14
    ctx->r1 = SIGNED(ctx->r3) < -0X14 ? 1 : 0;
    // 0x8010171C: beq         $at, $zero, L_8010172C
    if (ctx->r1 == 0) {
        // 0x80101720: ori         $t8, $v0, 0x2
        ctx->r24 = ctx->r2 | 0X2;
            goto L_8010172C;
    }
    // 0x80101720: ori         $t8, $v0, 0x2
    ctx->r24 = ctx->r2 | 0X2;
    // 0x80101724: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80101728: sra         $v0, $t9, 24
    ctx->r2 = S32(SIGNED(ctx->r25) >> 24);
L_8010172C:
    // 0x8010172C: lb          $t7, -0x52A8($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52A8);
    // 0x80101730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101734: sb          $v0, -0x52A8($at)
    MEM_B(-0X52A8, ctx->r1) = ctx->r2;
    // 0x80101738: xor         $t8, $v0, $t7
    ctx->r24 = ctx->r2 ^ ctx->r15;
    // 0x8010173C: and         $v1, $t8, $v0
    ctx->r3 = ctx->r24 & ctx->r2;
    // 0x80101740: sll         $t9, $v1, 24
    ctx->r25 = S32(ctx->r3 << 24);
    // 0x80101744: sra         $v1, $t9, 24
    ctx->r3 = S32(SIGNED(ctx->r25) >> 24);
    // 0x80101748: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8010174C: beq         $t7, $zero, L_80101758
    if (ctx->r15 == 0) {
        // 0x80101750: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80101758;
    }
    // 0x80101750: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80101754: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80101758:
    // 0x80101758: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8010175C: beq         $t8, $zero, L_80101768
    if (ctx->r24 == 0) {
        // 0x80101760: andi        $t9, $v1, 0x4
        ctx->r25 = ctx->r3 & 0X4;
            goto L_80101768;
    }
    // 0x80101760: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    // 0x80101764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80101768:
    // 0x80101768: beq         $t9, $zero, L_80101774
    if (ctx->r25 == 0) {
        // 0x8010176C: andi        $t6, $v1, 0x8
        ctx->r14 = ctx->r3 & 0X8;
            goto L_80101774;
    }
    // 0x8010176C: andi        $t6, $v1, 0x8
    ctx->r14 = ctx->r3 & 0X8;
    // 0x80101770: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80101774:
    // 0x80101774: beq         $t6, $zero, L_80101780
    if (ctx->r14 == 0) {
        // 0x80101778: lw          $t7, 0x3F0($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3F0);
            goto L_80101780;
    }
    // 0x80101778: lw          $t7, 0x3F0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3F0);
    // 0x8010177C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80101780:
    // 0x80101780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101784: sb          $a0, -0x52A6($at)
    MEM_B(-0X52A6, ctx->r1) = ctx->r4;
    // 0x80101788: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010178C: sb          $a1, -0x52A7($at)
    MEM_B(-0X52A7, ctx->r1) = ctx->r5;
    // 0x80101790: sltiu       $at, $t7, 0x10
    ctx->r1 = ctx->r15 < 0X10 ? 1 : 0;
    // 0x80101794: beq         $at, $zero, L_80102E14
    if (ctx->r1 == 0) {
        // 0x80101798: sw          $t7, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r15;
            goto L_80102E14;
    }
    // 0x80101798: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8010179C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801017A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801017A4: addu        $at, $at, $t8
    gpr jr_addend_801017AC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801017A8: lw          $t8, -0x5310($at)
    ctx->r24 = ADD32(ctx->r1, -0X5310);
    // 0x801017AC: jr          $t8
    // 0x801017B0: nop

    switch (jr_addend_801017AC >> 2) {
        case 0: goto L_801017B4; break;
        case 1: goto L_801017B4; break;
        case 2: goto L_801017E8; break;
        case 3: goto L_80101980; break;
        case 4: goto L_80101980; break;
        case 5: goto L_80101980; break;
        case 6: goto L_80101908; break;
        case 7: goto L_80101908; break;
        case 8: goto L_80101908; break;
        case 9: goto L_80101980; break;
        case 10: goto L_80101980; break;
        case 11: goto L_80101980; break;
        case 12: goto L_80101980; break;
        case 13: goto L_80101980; break;
        case 14: goto L_80101980; break;
        case 15: goto L_80101980; break;
        default: switch_error(__func__, 0x801017AC, 0x8011ACF0);
    }
    // 0x801017B0: nop

L_801017B4:
    // 0x801017B4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801017B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801017BC: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x801017C0: beql        $at, $zero, L_80102E18
    if (ctx->r1 == 0) {
        // 0x801017C4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80102E18;
    }
    goto skip_1;
    // 0x801017C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x801017C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801017CC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801017D0: addiu       $t8, $t8, 0x32E0
    ctx->r24 = ADD32(ctx->r24, 0X32E0);
    // 0x801017D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801017D8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801017DC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801017E0: b           L_80102E14
    // 0x801017E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_80102E14;
    // 0x801017E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_801017E8:
    // 0x801017E8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801017EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801017F0: sb          $a0, -0x52A6($at)
    MEM_B(-0X52A6, ctx->r1) = ctx->r4;
    // 0x801017F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801017F8: bne         $t9, $at, L_80101908
    if (ctx->r25 != ctx->r1) {
        // 0x801017FC: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_80101908;
    }
    // 0x801017FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80101800: lb          $v0, 0x3404($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3404);
    // 0x80101804: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101808: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x8010180C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80101810: sll         $t6, $v0, 24
    ctx->r14 = S32(ctx->r2 << 24);
    // 0x80101814: sra         $v0, $t6, 24
    ctx->r2 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80101818: bgez        $v0, L_8010182C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8010181C: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8010182C;
    }
    // 0x8010181C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80101820: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101824: b           L_80101858
    // 0x80101828: sb          $zero, 0x3404($at)
    MEM_B(0X3404, ctx->r1) = 0;
        goto L_80101858;
    // 0x80101828: sb          $zero, 0x3404($at)
    MEM_B(0X3404, ctx->r1) = 0;
L_8010182C:
    // 0x8010182C: bne         $at, $zero, L_80101844
    if (ctx->r1 != 0) {
        // 0x80101830: nop
    
            goto L_80101844;
    }
    // 0x80101830: nop

    // 0x80101834: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80101838: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010183C: b           L_80101858
    // 0x80101840: sb          $v0, 0x3404($at)
    MEM_B(0X3404, ctx->r1) = ctx->r2;
        goto L_80101858;
    // 0x80101840: sb          $v0, 0x3404($at)
    MEM_B(0X3404, ctx->r1) = ctx->r2;
L_80101844:
    // 0x80101844: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101848: beq         $a1, $zero, L_80101858
    if (ctx->r5 == 0) {
        // 0x8010184C: sb          $v0, 0x3404($at)
        MEM_B(0X3404, ctx->r1) = ctx->r2;
            goto L_80101858;
    }
    // 0x8010184C: sb          $v0, 0x3404($at)
    MEM_B(0X3404, ctx->r1) = ctx->r2;
    // 0x80101850: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101854: sw          $zero, 0x3400($at)
    MEM_W(0X3400, ctx->r1) = 0;
L_80101858:
    // 0x80101858: lb          $t8, 0x3408($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X3408);
    // 0x8010185C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101860: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80101864: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x80101868: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8010186C: bgez        $t7, L_80101880
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80101870: sb          $t9, 0x3408($at)
        MEM_B(0X3408, ctx->r1) = ctx->r25;
            goto L_80101880;
    }
    // 0x80101870: sb          $t9, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = ctx->r25;
    // 0x80101874: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101878: b           L_801018AC
    // 0x8010187C: sb          $zero, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = 0;
        goto L_801018AC;
    // 0x8010187C: sb          $zero, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = 0;
L_80101880:
    // 0x80101880: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101884: lb          $t8, 0x3408($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X3408);
    // 0x80101888: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8010188C: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80101890: bne         $at, $zero, L_801018A0
    if (ctx->r1 != 0) {
        // 0x80101894: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_801018A0;
    }
    // 0x80101894: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101898: b           L_801018AC
    // 0x8010189C: sb          $t9, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = ctx->r25;
        goto L_801018AC;
    // 0x8010189C: sb          $t9, 0x3408($at)
    MEM_B(0X3408, ctx->r1) = ctx->r25;
L_801018A0:
    // 0x801018A0: beq         $a0, $zero, L_801018AC
    if (ctx->r4 == 0) {
        // 0x801018A4: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_801018AC;
    }
    // 0x801018A4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801018A8: sw          $zero, 0x3400($at)
    MEM_W(0X3400, ctx->r1) = 0;
L_801018AC:
    // 0x801018AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801018B0: beq         $a0, $zero, L_801018DC
    if (ctx->r4 == 0) {
        // 0x801018B4: sb          $a0, -0x52A6($at)
        MEM_B(-0X52A6, ctx->r1) = ctx->r4;
            goto L_801018DC;
    }
    // 0x801018B4: sb          $a0, -0x52A6($at)
    MEM_B(-0X52A6, ctx->r1) = ctx->r4;
    // 0x801018B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801018BC: sb          $a1, -0x52A7($at)
    MEM_B(-0X52A7, ctx->r1) = ctx->r5;
    // 0x801018C0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x801018C4: jal         0x80025B8C
    // 0x801018C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80025B8C(rdram, ctx);
        goto after_0;
    // 0x801018C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x801018CC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x801018D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801018D4: lb          $a1, -0x52A7($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X52A7);
    // 0x801018D8: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
L_801018DC:
    // 0x801018DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x801018E0: addiu       $v0, $v0, -0x4CBC
    ctx->r2 = ADD32(ctx->r2, -0X4CBC);
    // 0x801018E4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801018E8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x801018EC: andi        $t8, $t6, 0xF
    ctx->r24 = ctx->r14 & 0XF;
    // 0x801018F0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x801018F4: lb          $t9, 0x3408($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X3408);
    // 0x801018F8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x801018FC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80101900: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80101904: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80101908:
    // 0x80101908: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8010190C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101910: sb          $a1, -0x52A7($at)
    MEM_B(-0X52A7, ctx->r1) = ctx->r5;
    // 0x80101914: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80101918: beq         $t6, $at, L_80101980
    if (ctx->r14 == ctx->r1) {
        // 0x8010191C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80101980;
    }
    // 0x8010191C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80101920: lb          $t8, -0x52B0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X52B0);
    // 0x80101924: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010192C: addu        $t7, $t8, $a1
    ctx->r15 = ADD32(ctx->r24, ctx->r5);
    // 0x80101930: sb          $t7, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = ctx->r15;
    // 0x80101934: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101938: beq         $a1, $zero, L_80101954
    if (ctx->r5 == 0) {
        // 0x8010193C: sb          $a1, -0x52A7($at)
        MEM_B(-0X52A7, ctx->r1) = ctx->r5;
            goto L_80101954;
    }
    // 0x8010193C: sb          $a1, -0x52A7($at)
    MEM_B(-0X52A7, ctx->r1) = ctx->r5;
    // 0x80101940: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80101944: jal         0x80025B8C
    // 0x80101948: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_1;
    // 0x80101948: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x8010194C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80101950: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
L_80101954:
    // 0x80101954: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80101958: lb          $v0, -0x52B0($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52B0);
    // 0x8010195C: bgez        $v0, L_80101970
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80101960: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80101970;
    }
    // 0x80101960: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80101964: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101968: b           L_80101980
    // 0x8010196C: sb          $zero, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = 0;
        goto L_80101980;
    // 0x8010196C: sb          $zero, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = 0;
L_80101970:
    // 0x80101970: bne         $at, $zero, L_80101980
    if (ctx->r1 != 0) {
        // 0x80101974: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80101980;
    }
    // 0x80101974: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80101978: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010197C: sb          $t9, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = ctx->r25;
L_80101980:
    // 0x80101980: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101984: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101988: lui         $ra, 0x600
    ctx->r31 = S32(0X600 << 16);
    // 0x8010198C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101990: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101994: addiu       $t8, $t8, 0x31B0
    ctx->r24 = ADD32(ctx->r24, 0X31B0);
    // 0x80101998: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8010199C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801019A0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801019A4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801019A8: addiu       $t8, $t8, 0x4F80
    ctx->r24 = ADD32(ctx->r24, 0X4F80);
    // 0x801019AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801019B0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801019B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801019B8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801019BC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801019C0: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x801019C4: lui         $a3, 0x600
    ctx->r7 = S32(0X600 << 16);
    // 0x801019C8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801019CC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801019D0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801019D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801019D8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801019DC: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x801019E0: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x801019E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801019E8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801019EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801019F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801019F4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801019F8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x801019FC: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80101A00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101A04: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101A08: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101A0C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101A10: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101A14: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x80101A18: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80101A1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101A20: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101A24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101A28: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80101A2C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101A30: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80101A34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80101A38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101A3C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101A40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101A44: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101A48: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101A4C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101A50: addiu       $t8, $t8, 0x31D8
    ctx->r24 = ADD32(ctx->r24, 0X31D8);
    // 0x80101A54: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101A58: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101A5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101A60: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101A64: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101A68: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80101A6C: addiu       $t9, $t9, 0x3230
    ctx->r25 = ADD32(ctx->r25, 0X3230);
    // 0x80101A70: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101A74: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101A78: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101A7C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80101A80: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101A84: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101A88: addiu       $t8, $t8, 0x3288
    ctx->r24 = ADD32(ctx->r24, 0X3288);
    // 0x80101A8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101A90: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101A94: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101A98: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80101A9C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101AA0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80101AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80101AA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101AAC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101AB0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101AB4: beq         $a2, $at, L_80101AC8
    if (ctx->r6 == ctx->r1) {
        // 0x80101AB8: sw          $a3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r7;
            goto L_80101AC8;
    }
    // 0x80101AB8: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80101ABC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80101AC0: bne         $a2, $at, L_80101B1C
    if (ctx->r6 != ctx->r1) {
        // 0x80101AC4: nop
    
            goto L_80101B1C;
    }
    // 0x80101AC4: nop

L_80101AC8:
    // 0x80101AC8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101ACC: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80101AD0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80101AD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101AD8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101ADC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101AE0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101AE4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101AE8: ori         $t8, $t8, 0x4240
    ctx->r24 = ctx->r24 | 0X4240;
    // 0x80101AEC: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x80101AF0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101AF4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101AF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101AFC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101B00: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101B04: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80101B08: addiu       $t9, $t9, 0x3388
    ctx->r25 = ADD32(ctx->r25, 0X3388);
    // 0x80101B0C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101B10: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101B14: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101B18: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
L_80101B1C:
    // 0x80101B1C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80101B20: lw          $t6, 0x3400($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3400);
    // 0x80101B24: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101B28: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80101B2C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80101B30: sw          $t8, 0x3400($at)
    MEM_W(0X3400, ctx->r1) = ctx->r24;
    // 0x80101B34: slti        $at, $t8, 0x20
    ctx->r1 = SIGNED(ctx->r24) < 0X20 ? 1 : 0;
    // 0x80101B38: bne         $at, $zero, L_80101B48
    if (ctx->r1 != 0) {
        // 0x80101B3C: addiu       $t6, $zero, 0x8
        ctx->r14 = ADD32(0, 0X8);
            goto L_80101B48;
    }
    // 0x80101B3C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80101B40: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80101B44: sw          $zero, 0x3400($at)
    MEM_W(0X3400, ctx->r1) = 0;
L_80101B48:
    // 0x80101B48: lw          $t7, 0x3400($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3400);
    // 0x80101B4C: slti        $at, $t7, 0x11
    ctx->r1 = SIGNED(ctx->r15) < 0X11 ? 1 : 0;
    // 0x80101B50: bne         $at, $zero, L_80101B74
    if (ctx->r1 != 0) {
        // 0x80101B54: nop
    
            goto L_80101B74;
    }
    // 0x80101B54: nop

    // 0x80101B58: bgez        $t7, L_80101B68
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80101B5C: sra         $t9, $t7, 2
        ctx->r25 = S32(SIGNED(ctx->r15) >> 2);
            goto L_80101B68;
    }
    // 0x80101B5C: sra         $t9, $t7, 2
    ctx->r25 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80101B60: addiu       $at, $t7, 0x3
    ctx->r1 = ADD32(ctx->r15, 0X3);
    // 0x80101B64: sra         $t9, $at, 2
    ctx->r25 = S32(SIGNED(ctx->r1) >> 2);
L_80101B68:
    // 0x80101B68: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x80101B6C: b           L_80101B90
    // 0x80101B70: sw          $t8, 0x3E8($sp)
    MEM_W(0X3E8, ctx->r29) = ctx->r24;
        goto L_80101B90;
    // 0x80101B70: sw          $t8, 0x3E8($sp)
    MEM_W(0X3E8, ctx->r29) = ctx->r24;
L_80101B74:
    // 0x80101B74: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80101B78: lw          $t7, 0x3400($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3400);
    // 0x80101B7C: bgez        $t7, L_80101B8C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80101B80: sra         $t6, $t7, 2
        ctx->r14 = S32(SIGNED(ctx->r15) >> 2);
            goto L_80101B8C;
    }
    // 0x80101B80: sra         $t6, $t7, 2
    ctx->r14 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80101B84: addiu       $at, $t7, 0x3
    ctx->r1 = ADD32(ctx->r15, 0X3);
    // 0x80101B88: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_80101B8C:
    // 0x80101B8C: sw          $t6, 0x3E8($sp)
    MEM_W(0X3E8, ctx->r29) = ctx->r14;
L_80101B90:
    // 0x80101B90: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101B94: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80101B98: addiu       $t6, $t6, 0x51E8
    ctx->r14 = ADD32(ctx->r14, 0X51E8);
    // 0x80101B9C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101BA0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101BA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101BA8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101BAC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101BB0: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80101BB4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80101BB8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101BBC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101BC0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101BC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101BC8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101BCC: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80101BD0: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80101BD4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101BD8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101BDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101BE0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101BE4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101BE8: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80101BEC: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80101BF0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101BF4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101BF8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101BFC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101C00: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101C04: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x80101C08: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80101C0C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101C10: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101C14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101C18: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80101C1C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101C20: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80101C24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101C28: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101C2C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101C30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101C34: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101C38: lui         $t6, 0xFD48
    ctx->r14 = S32(0XFD48 << 16);
    // 0x80101C3C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80101C40: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101C44: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101C48: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101C4C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101C50: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101C54: addiu       $t9, $t9, 0x5188
    ctx->r25 = ADD32(ctx->r25, 0X5188);
    // 0x80101C58: ori         $t6, $t6, 0x7
    ctx->r14 = ctx->r14 | 0X7;
    // 0x80101C5C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101C60: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101C64: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80101C68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101C6C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101C70: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80101C74: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80101C78: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101C7C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101C80: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80101C84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101C88: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101C8C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101C90: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x80101C94: ori         $t6, $t6, 0x4028
    ctx->r14 = ctx->r14 | 0X4028;
    // 0x80101C98: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101C9C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101CA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101CA4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80101CA8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101CAC: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x80101CB0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101CB4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101CB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101CBC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101CC0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101CC4: lui         $t7, 0xF540
    ctx->r15 = S32(0XF540 << 16);
    // 0x80101CC8: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80101CCC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101CD0: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101CD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101CD8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101CDC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101CE0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80101CE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101CE8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101CEC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101CF0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101CF4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101CF8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80101CFC: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80101D00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101D04: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101D08: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101D0C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101D10: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101D14: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80101D18: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101D1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101D20: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101D24: lb          $t6, 0x3408($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3408);
    // 0x80101D28: addiu       $t8, $t8, 0x340C
    ctx->r24 = ADD32(ctx->r24, 0X340C);
    // 0x80101D2C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80101D30: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80101D34: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x80101D38: addiu       $t6, $t7, 0xB
    ctx->r14 = ADD32(ctx->r15, 0XB);
    // 0x80101D3C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80101D40: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80101D44: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80101D48: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80101D4C: addiu       $t9, $t6, 0xB
    ctx->r25 = ADD32(ctx->r14, 0XB);
    // 0x80101D50: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80101D54: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80101D58: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80101D5C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80101D60: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101D64: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x80101D68: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80101D6C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80101D70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80101D74: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80101D78: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80101D7C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80101D80: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80101D84: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80101D88: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101D8C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101D90: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80101D94: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80101D98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101D9C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101DA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101DA4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101DA8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101DAC: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80101DB0: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80101DB4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80101DB8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80101DBC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80101DC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80101DC4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80101DC8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80101DCC: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101DD0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80101E10;
    }
    // 0x80101DD0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80101DD4: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101DD8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80101E10;
    }
    // 0x80101DD8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80101DDC: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101DE0: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80101E10;
    }
    // 0x80101DE0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80101DE4: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101DE8: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80101E10;
    }
    // 0x80101DE8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80101DEC: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101DF0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80101E10;
    }
    // 0x80101DF0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80101DF4: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101DF8: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80101E10;
    }
    // 0x80101DF8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80101DFC: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101E00: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80101E10;
    }
    // 0x80101E00: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80101E04: beq         $t9, $at, L_80101E10
    if (ctx->r25 == ctx->r1) {
        // 0x80101E08: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80101E10;
    }
    // 0x80101E08: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80101E0C: bne         $t9, $at, L_80102E14
    if (ctx->r25 != ctx->r1) {
        // 0x80101E10: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80102E14;
    }
L_80101E10:
    // 0x80101E10: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80101E14: bne         $v0, $at, L_80101E2C
    if (ctx->r2 != ctx->r1) {
        // 0x80101E18: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_80101E2C;
    }
    // 0x80101E18: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101E1C: addiu       $t8, $t8, 0x53E8
    ctx->r24 = ADD32(ctx->r24, 0X53E8);
    // 0x80101E20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101E24: b           L_80101E98
    // 0x80101E28: sw          $t8, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r24;
        goto L_80101E98;
    // 0x80101E28: sw          $t8, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r24;
L_80101E2C:
    // 0x80101E2C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80101E30: bne         $v0, $at, L_80101E48
    if (ctx->r2 != ctx->r1) {
        // 0x80101E34: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_80101E48;
    }
    // 0x80101E34: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80101E38: addiu       $t6, $t6, 0x5464
    ctx->r14 = ADD32(ctx->r14, 0X5464);
    // 0x80101E3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101E40: b           L_80101E98
    // 0x80101E44: sw          $t6, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r14;
        goto L_80101E98;
    // 0x80101E44: sw          $t6, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r14;
L_80101E48:
    // 0x80101E48: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80101E4C: bne         $v0, $at, L_80101E64
    if (ctx->r2 != ctx->r1) {
        // 0x80101E50: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_80101E64;
    }
    // 0x80101E50: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80101E54: addiu       $t7, $t7, 0x5474
    ctx->r15 = ADD32(ctx->r15, 0X5474);
    // 0x80101E58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101E5C: b           L_80101E98
    // 0x80101E60: sw          $t7, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r15;
        goto L_80101E98;
    // 0x80101E60: sw          $t7, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r15;
L_80101E64:
    // 0x80101E64: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80101E68: bne         $v0, $at, L_80101E80
    if (ctx->r2 != ctx->r1) {
        // 0x80101E6C: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_80101E80;
    }
    // 0x80101E6C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80101E70: addiu       $t9, $t9, 0x54F0
    ctx->r25 = ADD32(ctx->r25, 0X54F0);
    // 0x80101E74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101E78: b           L_80101E98
    // 0x80101E7C: sw          $t9, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r25;
        goto L_80101E98;
    // 0x80101E7C: sw          $t9, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r25;
L_80101E80:
    // 0x80101E80: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80101E84: bne         $v0, $at, L_80101E98
    if (ctx->r2 != ctx->r1) {
        // 0x80101E88: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_80101E98;
    }
    // 0x80101E88: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80101E8C: addiu       $t8, $t8, 0x552C
    ctx->r24 = ADD32(ctx->r24, 0X552C);
    // 0x80101E90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80101E94: sw          $t8, -0x52A4($at)
    MEM_W(-0X52A4, ctx->r1) = ctx->r24;
L_80101E98:
    // 0x80101E98: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101E9C: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80101EA0: addiu       $t8, $t8, -0x480
    ctx->r24 = ADD32(ctx->r24, -0X480);
    // 0x80101EA4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101EA8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101EAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101EB0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101EB4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101EB8: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80101EBC: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80101EC0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101EC4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101EC8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80101ECC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80101ED0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101ED4: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80101ED8: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x80101EDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101EE0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101EE4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101EE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80101EEC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101EF0: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80101EF4: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80101EF8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101EFC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101F00: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101F04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101F08: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101F0C: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x80101F10: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80101F14: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101F18: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101F1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101F20: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80101F24: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101F28: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80101F2C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80101F30: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101F34: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101F38: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101F3C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101F40: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101F44: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80101F48: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80101F4C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80101F50: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80101F54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101F58: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101F5C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101F60: addiu       $t7, $zero, 0x67
    ctx->r15 = ADD32(0, 0X67);
    // 0x80101F64: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    // 0x80101F68: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80101F6C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80101F70: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80101F74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80101F78: jal         0x800307D8
    // 0x80101F7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800307D8(rdram, ctx);
        goto after_2;
    // 0x80101F7C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x80101F80: addiu       $t9, $zero, 0x67
    ctx->r25 = ADD32(0, 0X67);
    // 0x80101F84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80101F88: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80101F8C: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    // 0x80101F90: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    // 0x80101F94: jal         0x800307D8
    // 0x80101F98: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800307D8(rdram, ctx);
        goto after_3;
    // 0x80101F98: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x80101F9C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80101FA0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80101FA4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80101FA8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80101FAC: addiu       $a2, $zero, 0x8F
    ctx->r6 = ADD32(0, 0X8F);
    // 0x80101FB0: jal         0x800307D8
    // 0x80101FB4: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    func_800307D8(rdram, ctx);
        goto after_4;
    // 0x80101FB4: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    after_4:
    // 0x80101FB8: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80101FBC: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x80101FC0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80101FC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80101FC8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80101FCC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80101FD0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80101FD4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80101FD8: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80101FDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80101FE0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80101FE4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80101FE8: jal         0x800307D8
    // 0x80101FEC: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    func_800307D8(rdram, ctx);
        goto after_5;
    // 0x80101FEC: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    after_5:
    // 0x80101FF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80101FF4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80101FF8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80101FFC: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80102000: addiu       $a2, $zero, 0x8E
    ctx->r6 = ADD32(0, 0X8E);
    // 0x80102004: jal         0x800307D8
    // 0x80102008: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    func_800307D8(rdram, ctx);
        goto after_6;
    // 0x80102008: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    after_6:
    // 0x8010200C: addiu       $t8, $zero, 0x67
    ctx->r24 = ADD32(0, 0X67);
    // 0x80102010: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80102014: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80102018: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x8010201C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80102020: jal         0x800307D8
    // 0x80102024: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800307D8(rdram, ctx);
        goto after_7;
    // 0x80102024: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80102028: addiu       $t6, $zero, 0x67
    ctx->r14 = ADD32(0, 0X67);
    // 0x8010202C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80102030: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80102034: addiu       $a1, $zero, 0x101
    ctx->r5 = ADD32(0, 0X101);
    // 0x80102038: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8010203C: jal         0x800307D8
    // 0x80102040: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800307D8(rdram, ctx);
        goto after_8;
    // 0x80102040: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80102044: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80102048: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x8010204C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102050: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x80102054: ori         $t8, $t8, 0xE02
    ctx->r24 = ctx->r24 | 0XE02;
    // 0x80102058: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010205C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102060: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102064: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102068: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010206C: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80102070: lui         $s0, 0xFD48
    ctx->r16 = S32(0XFD48 << 16);
    // 0x80102074: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102078: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8010207C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102080: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102084: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102088: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8010208C: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80102090: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102094: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102098: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8010209C: ori         $t8, $t8, 0x4240
    ctx->r24 = ctx->r24 | 0X4240;
    // 0x801020A0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801020A4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801020A8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801020AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801020B0: addiu       $t9, $t9, -0x5568
    ctx->r25 = ADD32(ctx->r25, -0X5568);
    // 0x801020B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801020B8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801020BC: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x801020C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801020C4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801020C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801020CC: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x801020D0: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x801020D4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801020D8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801020DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801020E0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801020E4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801020E8: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x801020EC: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x801020F0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801020F4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801020F8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801020FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102100: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102104: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x80102108: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8010210C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102110: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102114: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102118: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8010211C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102120: lui         $t9, 0xF000
    ctx->r25 = S32(0XF000 << 16);
    // 0x80102124: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80102128: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010212C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102130: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102134: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102138: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010213C: ori         $s0, $s0, 0x3
    ctx->r16 = ctx->r16 | 0X3;
    // 0x80102140: addiu       $ra, $ra, -0x5360
    ctx->r31 = ADD32(ctx->r31, -0X5360);
    // 0x80102144: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102148: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8010214C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102150: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102154: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102158: lui         $s1, 0x708
    ctx->r17 = S32(0X708 << 16);
    // 0x8010215C: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80102160: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102164: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102168: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010216C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102170: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102174: ori         $s1, $s1, 0x200
    ctx->r17 = ctx->r17 | 0X200;
    // 0x80102178: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x8010217C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102180: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102184: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80102188: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8010218C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102190: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102194: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102198: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8010219C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801021A0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801021A4: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x801021A8: ori         $t6, $t6, 0xC00C
    ctx->r14 = ctx->r14 | 0XC00C;
    // 0x801021AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801021B0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801021B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801021B8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801021BC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801021C0: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x801021C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801021C8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801021CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801021D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801021D4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801021D8: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x801021DC: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x801021E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801021E4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801021E8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801021EC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801021F0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801021F4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x801021F8: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x801021FC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102200: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102204: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102208: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010220C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102210: ori         $t8, $zero, 0xC00C
    ctx->r24 = 0 | 0XC00C;
    // 0x80102214: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80102218: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010221C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102220: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102224: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102228: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010222C: lui         $t9, 0x10
    ctx->r25 = S32(0X10 << 16);
    // 0x80102230: lui         $t7, 0xE440
    ctx->r15 = S32(0XE440 << 16);
    // 0x80102234: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102238: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8010223C: ori         $t7, $t7, 0xAC
    ctx->r15 = ctx->r15 | 0XAC;
    // 0x80102240: ori         $t9, $t9, 0xA8
    ctx->r25 = ctx->r25 | 0XA8;
    // 0x80102244: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102248: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010224C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102250: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x80102254: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80102258: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010225C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102260: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102264: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102268: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010226C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80102270: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80102274: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102278: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8010227C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102280: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102284: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102288: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x8010228C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80102290: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102294: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102298: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010229C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801022A0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801022A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801022A8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801022AC: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x801022B0: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x801022B4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801022B8: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x801022BC: addiu       $ra, $ra, -0x5348
    ctx->r31 = ADD32(ctx->r31, -0X5348);
    // 0x801022C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801022C4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801022C8: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x801022CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801022D0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801022D4: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x801022D8: ori         $t8, $t8, 0xC00C
    ctx->r24 = ctx->r24 | 0XC00C;
    // 0x801022DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801022E0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801022E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801022E8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801022EC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801022F0: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x801022F4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801022F8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801022FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102300: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102304: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102308: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x8010230C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80102310: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102314: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102318: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010231C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102320: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102324: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80102328: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8010232C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102330: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102334: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102338: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8010233C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102340: ori         $t9, $zero, 0xC00C
    ctx->r25 = 0 | 0XC00C;
    // 0x80102344: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80102348: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010234C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102350: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102354: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102358: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010235C: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x80102360: lui         $t6, 0xE410
    ctx->r14 = S32(0XE410 << 16);
    // 0x80102364: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102368: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8010236C: ori         $t6, $t6, 0x4230
    ctx->r14 = ctx->r14 | 0X4230;
    // 0x80102370: ori         $t7, $t7, 0xA8
    ctx->r15 = ctx->r15 | 0XA8;
    // 0x80102374: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102378: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8010237C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102380: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80102384: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80102388: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010238C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102390: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102394: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102398: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010239C: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801023A0: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x801023A4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801023A8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801023AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801023B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801023B4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801023B8: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x801023BC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x801023C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801023C4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801023C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801023CC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801023D0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801023D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801023D8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801023DC: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x801023E0: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x801023E4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801023E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801023EC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801023F0: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x801023F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801023F8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801023FC: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80102400: ori         $t9, $t9, 0xC00C
    ctx->r25 = ctx->r25 | 0XC00C;
    // 0x80102404: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102408: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8010240C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102410: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80102414: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80102418: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x8010241C: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80102420: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102424: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80102428: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8010242C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102430: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80102434: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80102438: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010243C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102440: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102444: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102448: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010244C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80102450: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80102454: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102458: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8010245C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102460: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102464: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102468: ori         $t7, $zero, 0xC00C
    ctx->r15 = 0 | 0XC00C;
    // 0x8010246C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80102470: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102474: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102478: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010247C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102480: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102484: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x80102488: lui         $t8, 0xE440
    ctx->r24 = S32(0XE440 << 16);
    // 0x8010248C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102490: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102494: ori         $t8, $t8, 0x238
    ctx->r24 = ctx->r24 | 0X238;
    // 0x80102498: ori         $t6, $t6, 0x234
    ctx->r14 = ctx->r14 | 0X234;
    // 0x8010249C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801024A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801024A4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801024A8: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x801024AC: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x801024B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801024B4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801024B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801024BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801024C0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801024C4: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x801024C8: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x801024CC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801024D0: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801024D4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801024D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801024DC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801024E0: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x801024E4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x801024E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801024EC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801024F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801024F4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801024F8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801024FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80102500: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x80102504: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102508: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8010250C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80102510: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80102514: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102518: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8010251C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102520: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102524: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80102528: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010252C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102530: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80102534: ori         $t7, $t7, 0xC00C
    ctx->r15 = ctx->r15 | 0XC00C;
    // 0x80102538: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010253C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102540: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102544: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80102548: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010254C: lui         $t6, 0xF400
    ctx->r14 = S32(0XF400 << 16);
    // 0x80102550: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102554: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102558: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8010255C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102560: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102564: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80102568: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8010256C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102570: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102574: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102578: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010257C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102580: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80102584: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80102588: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010258C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102590: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102594: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102598: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010259C: ori         $t6, $zero, 0xC00C
    ctx->r14 = 0 | 0XC00C;
    // 0x801025A0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x801025A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801025A8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801025AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801025B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801025B4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801025B8: lui         $t8, 0x40
    ctx->r24 = S32(0X40 << 16);
    // 0x801025BC: lui         $t9, 0xE440
    ctx->r25 = S32(0XE440 << 16);
    // 0x801025C0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801025C4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801025C8: ori         $t9, $t9, 0x4238
    ctx->r25 = ctx->r25 | 0X4238;
    // 0x801025CC: ori         $t8, $t8, 0xA8
    ctx->r24 = ctx->r24 | 0XA8;
    // 0x801025D0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801025D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801025D8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801025DC: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x801025E0: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x801025E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801025E8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801025EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801025F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801025F4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801025F8: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x801025FC: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80102600: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102604: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102608: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010260C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102610: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102614: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80102618: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8010261C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102620: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102624: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102628: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010262C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102630: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102634: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102638: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010263C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102640: jal         0x80030EA0
    // 0x80102644: lw          $a2, -0x52A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X52A4);
    func_80030EA0(rdram, ctx);
        goto after_9;
    // 0x80102644: lw          $a2, -0x52A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X52A4);
    after_9:
    // 0x80102648: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8010264C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80102650: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    // 0x80102654: beq         $v0, $at, L_80102684
    if (ctx->r2 == ctx->r1) {
        // 0x80102658: addiu       $a1, $zero, 0x73
        ctx->r5 = ADD32(0, 0X73);
            goto L_80102684;
    }
    // 0x80102658: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x8010265C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80102660: beq         $v0, $at, L_80102684
    if (ctx->r2 == ctx->r1) {
        // 0x80102664: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80102684;
    }
    // 0x80102664: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80102668: beq         $v0, $at, L_80102684
    if (ctx->r2 == ctx->r1) {
        // 0x8010266C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80102684;
    }
    // 0x8010266C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80102670: beq         $v0, $at, L_80102684
    if (ctx->r2 == ctx->r1) {
        // 0x80102674: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80102684;
    }
    // 0x80102674: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80102678: beq         $v0, $at, L_80102684
    if (ctx->r2 == ctx->r1) {
        // 0x8010267C: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80102684;
    }
    // 0x8010267C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80102680: bne         $v0, $at, L_80102E14
    if (ctx->r2 != ctx->r1) {
        // 0x80102684: lui         $a2, 0x8010
        ctx->r6 = S32(0X8010 << 16);
            goto L_80102E14;
    }
L_80102684:
    // 0x80102684: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80102688: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8010268C: addiu       $s0, $s0, 0x3388
    ctx->r16 = ADD32(ctx->r16, 0X3388);
    // 0x80102690: jal         0x80030EA0
    // 0x80102694: addiu       $a2, $a2, 0x5538
    ctx->r6 = ADD32(ctx->r6, 0X5538);
    func_80030EA0(rdram, ctx);
        goto after_10;
    // 0x80102694: addiu       $a2, $a2, 0x5538
    ctx->r6 = ADD32(ctx->r6, 0X5538);
    after_10:
    // 0x80102698: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8010269C: addiu       $a2, $a2, 0x5540
    ctx->r6 = ADD32(ctx->r6, 0X5540);
    // 0x801026A0: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    // 0x801026A4: jal         0x80030EA0
    // 0x801026A8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_80030EA0(rdram, ctx);
        goto after_11;
    // 0x801026A8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_11:
    // 0x801026AC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801026B0: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x801026B4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801026B8: beq         $t7, $at, L_801026DC
    if (ctx->r15 == ctx->r1) {
        // 0x801026BC: addiu       $t3, $t3, -0x4D04
        ctx->r11 = ADD32(ctx->r11, -0X4D04);
            goto L_801026DC;
    }
    // 0x801026BC: addiu       $t3, $t3, -0x4D04
    ctx->r11 = ADD32(ctx->r11, -0X4D04);
    // 0x801026C0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x801026C4: beq         $t7, $at, L_801026DC
    if (ctx->r15 == ctx->r1) {
        // 0x801026C8: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_801026DC;
    }
    // 0x801026C8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801026CC: beq         $t7, $at, L_801026DC
    if (ctx->r15 == ctx->r1) {
        // 0x801026D0: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_801026DC;
    }
    // 0x801026D0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801026D4: bnel        $t7, $at, L_80102754
    if (ctx->r15 != ctx->r1) {
        // 0x801026D8: lw          $v0, 0x0($t3)
        ctx->r2 = MEM_W(ctx->r11, 0X0);
            goto L_80102754;
    }
    goto skip_2;
    // 0x801026D8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    skip_2:
L_801026DC:
    // 0x801026DC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801026E0: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x801026E4: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x801026E8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801026EC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801026F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801026F4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801026F8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801026FC: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x80102700: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x80102704: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102708: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8010270C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102710: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102714: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102718: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8010271C: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80102720: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102724: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102728: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8010272C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102730: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102734: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80102738: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010273C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102740: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102744: lw          $t9, -0x52AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X52AC);
    // 0x80102748: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8010274C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102750: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
L_80102754:
    // 0x80102754: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80102758: lui         $s1, 0xFD48
    ctx->r17 = S32(0XFD48 << 16);
    // 0x8010275C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102760: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102764: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102768: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8010276C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102770: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80102774: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x80102778: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8010277C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102780: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80102784: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102788: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010278C: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80102790: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x80102794: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102798: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8010279C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801027A0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801027A4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801027A8: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x801027AC: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x801027B0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801027B4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801027B8: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x801027BC: ori         $t6, $t6, 0x4240
    ctx->r14 = ctx->r14 | 0X4240;
    // 0x801027C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801027C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801027C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801027CC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801027D0: addiu       $t8, $t8, 0x3440
    ctx->r24 = ADD32(ctx->r24, 0X3440);
    // 0x801027D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801027D8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801027DC: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x801027E0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801027E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801027E8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801027EC: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x801027F0: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x801027F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801027F8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801027FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102800: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102804: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102808: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8010280C: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x80102810: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102814: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102818: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8010281C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102820: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102824: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x80102828: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8010282C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102830: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102834: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102838: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8010283C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102840: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80102844: ori         $s1, $s1, 0x7F
    ctx->r17 = ctx->r17 | 0X7F;
    // 0x80102848: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010284C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102850: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102854: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102858: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010285C: addiu       $s0, $s0, 0x3640
    ctx->r16 = ADD32(ctx->r16, 0X3640);
    // 0x80102860: lui         $ra, 0xF548
    ctx->r31 = S32(0XF548 << 16);
    // 0x80102864: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102868: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8010286C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102870: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102874: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102878: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x8010287C: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80102880: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102884: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102888: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8010288C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80102890: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102894: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80102898: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8010289C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801028A0: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801028A4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801028A8: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801028AC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801028B0: lui         $t6, 0x71C
    ctx->r14 = S32(0X71C << 16);
    // 0x801028B4: ori         $t6, $t6, 0x4024
    ctx->r14 = ctx->r14 | 0X4024;
    // 0x801028B8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801028BC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801028C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801028C4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801028C8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801028CC: lui         $t8, 0xF419
    ctx->r24 = S32(0XF419 << 16);
    // 0x801028D0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801028D4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x801028D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801028DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801028E0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801028E4: lui         $t6, 0xF219
    ctx->r14 = S32(0XF219 << 16);
    // 0x801028E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801028EC: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x801028F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801028F4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x801028F8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801028FC: lui         $t7, 0x1C
    ctx->r15 = S32(0X1C << 16);
    // 0x80102900: ori         $t7, $t7, 0x4024
    ctx->r15 = ctx->r15 | 0X4024;
    // 0x80102904: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102908: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8010290C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102910: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80102914: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102918: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010291C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102920: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102924: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102928: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8010292C: lw          $t8, 0x3E8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3E8);
    // 0x80102930: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102934: addiu       $t6, $t8, 0x89
    ctx->r14 = ADD32(ctx->r24, 0X89);
    // 0x80102938: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8010293C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102940: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80102944: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80102948: lb          $t7, -0x52B0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52B0);
    // 0x8010294C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80102950: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80102954: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102958: lui         $at, 0xE41E
    ctx->r1 = S32(0XE41E << 16);
    // 0x8010295C: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80102960: mflo        $t9
    ctx->r25 = lo;
    // 0x80102964: addiu       $t8, $t9, 0x7F
    ctx->r24 = ADD32(ctx->r25, 0X7F);
    // 0x80102968: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8010296C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80102970: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80102974: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102978: lw          $t7, 0x3E8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3E8);
    // 0x8010297C: addiu       $t6, $t7, 0x7B
    ctx->r14 = ADD32(ctx->r15, 0X7B);
    // 0x80102980: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80102984: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80102988: lb          $t6, -0x52B0($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52B0);
    // 0x8010298C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80102990: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80102994: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102998: mflo        $t9
    ctx->r25 = lo;
    // 0x8010299C: addiu       $t8, $t9, 0x75
    ctx->r24 = ADD32(ctx->r25, 0X75);
    // 0x801029A0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801029A4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x801029A8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x801029AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801029B0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801029B4: lui         $t9, 0xC80
    ctx->r25 = S32(0XC80 << 16);
    // 0x801029B8: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x801029BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801029C0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x801029C4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801029C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801029CC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801029D0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x801029D4: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x801029D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801029DC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x801029E0: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x801029E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801029E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801029EC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x801029F0: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x801029F4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x801029F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801029FC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102A00: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80102A04: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80102A08: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102A0C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80102A10: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102A14: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102A18: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102A1C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102A20: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102A24: lui         $t6, 0xF40C
    ctx->r14 = S32(0XF40C << 16);
    // 0x80102A28: lui         $t7, 0x70E
    ctx->r15 = S32(0X70E << 16);
    // 0x80102A2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102A30: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102A34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102A38: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80102A3C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102A40: ori         $t7, $t7, 0x4018
    ctx->r15 = ctx->r15 | 0X4018;
    // 0x80102A44: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80102A48: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102A4C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102A50: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102A54: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102A58: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102A5C: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80102A60: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80102A64: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102A68: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102A6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102A70: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102A74: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102A78: lui         $t9, 0xF20C
    ctx->r25 = S32(0XF20C << 16);
    // 0x80102A7C: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x80102A80: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102A84: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102A88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102A8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102A90: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102A94: lui         $t8, 0xE
    ctx->r24 = S32(0XE << 16);
    // 0x80102A98: ori         $t8, $t8, 0x4018
    ctx->r24 = ctx->r24 | 0X4018;
    // 0x80102A9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102AA0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102AA4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102AA8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102AAC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102AB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80102AB4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102AB8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102ABC: lb          $t7, -0x52B0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52B0);
    // 0x80102AC0: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102AC4: mflo        $t9
    ctx->r25 = lo;
    // 0x80102AC8: addiu       $t8, $t9, 0x7E
    ctx->r24 = ADD32(ctx->r25, 0X7E);
    // 0x80102ACC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80102AD0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80102AD4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80102AD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80102ADC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102AE0: lb          $t8, -0x52B0($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X52B0);
    // 0x80102AE4: lui         $at, 0x1C
    ctx->r1 = S32(0X1C << 16);
    // 0x80102AE8: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x80102AEC: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102AF0: mflo        $t6
    ctx->r14 = lo;
    // 0x80102AF4: addiu       $t7, $t6, 0x77
    ctx->r15 = ADD32(ctx->r14, 0X77);
    // 0x80102AF8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80102AFC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80102B00: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80102B04: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102B08: lw          $ra, 0x0($t3)
    ctx->r31 = MEM_W(ctx->r11, 0X0);
    // 0x80102B0C: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80102B10: lui         $t8, 0x660
    ctx->r24 = S32(0X660 << 16);
    // 0x80102B14: addiu       $t7, $ra, 0x8
    ctx->r15 = ADD32(ctx->r31, 0X8);
    // 0x80102B18: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102B1C: sw          $t9, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r25;
    // 0x80102B20: sw          $t8, 0x4($ra)
    MEM_W(0X4, ctx->r31) = ctx->r24;
    // 0x80102B24: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102B28: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80102B2C: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80102B30: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102B34: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102B38: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80102B3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102B40: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102B44: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102B48: lui         $ra, 0xF548
    ctx->r31 = S32(0XF548 << 16);
    // 0x80102B4C: ori         $ra, $ra, 0x400
    ctx->r31 = ctx->r31 | 0X400;
    // 0x80102B50: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102B54: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102B58: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80102B5C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80102B60: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102B64: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80102B68: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80102B6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102B70: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102B74: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102B78: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80102B7C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102B80: lui         $t7, 0x715
    ctx->r15 = S32(0X715 << 16);
    // 0x80102B84: ori         $t7, $t7, 0x4034
    ctx->r15 = ctx->r15 | 0X4034;
    // 0x80102B88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102B8C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102B90: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102B94: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80102B98: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102B9C: lui         $t6, 0xF412
    ctx->r14 = S32(0XF412 << 16);
    // 0x80102BA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102BA4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102BA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102BAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102BB0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102BB4: lui         $t7, 0xF212
    ctx->r15 = S32(0XF212 << 16);
    // 0x80102BB8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102BBC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102BC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102BC4: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102BC8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102BCC: lui         $t9, 0x15
    ctx->r25 = S32(0X15 << 16);
    // 0x80102BD0: ori         $t9, $t9, 0x4034
    ctx->r25 = ctx->r25 | 0X4034;
    // 0x80102BD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102BD8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102BDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102BE0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80102BE4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102BE8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102BEC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102BF0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102BF4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102BF8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102BFC: lw          $t6, 0x3E8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3E8);
    // 0x80102C00: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102C04: addiu       $t7, $t6, 0x88
    ctx->r15 = ADD32(ctx->r14, 0X88);
    // 0x80102C08: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80102C0C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102C10: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80102C14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80102C18: lb          $t9, -0x52B0($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X52B0);
    // 0x80102C1C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80102C20: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80102C24: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102C28: lui         $at, 0xE41E
    ctx->r1 = S32(0XE41E << 16);
    // 0x80102C2C: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80102C30: mflo        $t8
    ctx->r24 = lo;
    // 0x80102C34: addiu       $t6, $t8, 0x81
    ctx->r14 = ADD32(ctx->r24, 0X81);
    // 0x80102C38: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80102C3C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80102C40: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80102C44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102C48: lw          $t9, 0x3E8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3E8);
    // 0x80102C4C: addiu       $t7, $t9, 0x7A
    ctx->r15 = ADD32(ctx->r25, 0X7A);
    // 0x80102C50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80102C54: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80102C58: lb          $t7, -0x52B0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52B0);
    // 0x80102C5C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80102C60: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80102C64: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102C68: mflo        $t8
    ctx->r24 = lo;
    // 0x80102C6C: addiu       $t6, $t8, 0x73
    ctx->r14 = ADD32(ctx->r24, 0X73);
    // 0x80102C70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80102C74: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80102C78: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80102C7C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102C80: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102C84: lui         $t8, 0x900
    ctx->r24 = S32(0X900 << 16);
    // 0x80102C88: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80102C8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102C90: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102C94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102C98: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102C9C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102CA0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80102CA4: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x80102CA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102CAC: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102CB0: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x80102CB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102CB8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102CBC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102CC0: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80102CC4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80102CC8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102CCC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102CD0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80102CD4: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80102CD8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102CDC: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80102CE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102CE4: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102CE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102CEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102CF0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102CF4: lui         $t7, 0xF405
    ctx->r15 = S32(0XF405 << 16);
    // 0x80102CF8: lui         $t9, 0x707
    ctx->r25 = S32(0X707 << 16);
    // 0x80102CFC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102D00: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102D04: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102D08: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80102D0C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102D10: ori         $t9, $t9, 0x18
    ctx->r25 = ctx->r25 | 0X18;
    // 0x80102D14: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x80102D18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102D1C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102D20: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102D24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102D28: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102D2C: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x80102D30: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80102D34: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102D38: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80102D3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102D40: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80102D44: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102D48: lui         $t8, 0xF205
    ctx->r24 = S32(0XF205 << 16);
    // 0x80102D4C: ori         $t8, $t8, 0x8000
    ctx->r24 = ctx->r24 | 0X8000;
    // 0x80102D50: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102D54: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80102D58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102D5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102D60: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102D64: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x80102D68: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x80102D6C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102D70: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102D74: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102D78: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102D7C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102D80: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80102D84: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102D88: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102D8C: lb          $t9, -0x52B0($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X52B0);
    // 0x80102D90: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102D94: mflo        $t8
    ctx->r24 = lo;
    // 0x80102D98: addiu       $t6, $t8, 0x7C
    ctx->r14 = ADD32(ctx->r24, 0X7C);
    // 0x80102D9C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80102DA0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80102DA4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80102DA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80102DAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102DB0: lb          $t6, -0x52B0($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52B0);
    // 0x80102DB4: lui         $at, 0x1C
    ctx->r1 = S32(0X1C << 16);
    // 0x80102DB8: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x80102DBC: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80102DC0: mflo        $t7
    ctx->r15 = lo;
    // 0x80102DC4: addiu       $t9, $t7, 0x75
    ctx->r25 = ADD32(ctx->r15, 0X75);
    // 0x80102DC8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80102DCC: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80102DD0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80102DD4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102DD8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102DDC: lui         $t6, 0x2C0
    ctx->r14 = S32(0X2C0 << 16);
    // 0x80102DE0: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x80102DE4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102DE8: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80102DEC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102DF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102DF4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80102DF8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80102DFC: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80102E00: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102E04: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80102E08: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80102E0C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102E10: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80102E14:
    // 0x80102E14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80102E18:
    // 0x80102E18: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80102E1C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80102E20: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80102E24: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80102E28: jr          $ra
    // 0x80102E2C: addiu       $sp, $sp, 0x3F0
    ctx->r29 = ADD32(ctx->r29, 0X3F0);
    return;
    // 0x80102E2C: addiu       $sp, $sp, 0x3F0
    ctx->r29 = ADD32(ctx->r29, 0X3F0);
;}
RECOMP_FUNC void func_80006BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006BEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80006BF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80006BF4: andi        $s0, $a0, 0xFFFF
    ctx->r16 = ctx->r4 & 0XFFFF;
    // 0x80006BF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006BFC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80006C00: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80006C04: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80006C08: lhu         $t6, -0x4548($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4548);
    // 0x80006C0C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80006C10: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80006C14: beql        $t6, $at, L_80006F58
    if (ctx->r14 == ctx->r1) {
        // 0x80006C18: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80006F58;
    }
    goto skip_0;
    // 0x80006C18: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x80006C1C: lh          $t7, -0x44E4($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X44E4);
    // 0x80006C20: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80006C24: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80006C28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80006C2C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80006C30: lw          $t9, 0x3D00($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3D00);
    // 0x80006C34: beq         $s0, $zero, L_80006EBC
    if (ctx->r16 == 0) {
        // 0x80006C38: sw          $t9, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r25;
            goto L_80006EBC;
    }
    // 0x80006C38: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80006C3C: lw          $t0, 0x68($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X68);
    // 0x80006C40: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80006C44: lhu         $v0, 0x84($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X84);
    // 0x80006C48: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80006C4C: bgez        $v0, L_80006C64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80006C50: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80006C64;
    }
    // 0x80006C50: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006C54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006C58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80006C5C: nop

    // 0x80006C60: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80006C64:
    // 0x80006C64: lhu         $t1, -0x4440($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4440);
    // 0x80006C68: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80006C6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006C70: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80006C74: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80006C78: nop

    // 0x80006C7C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80006C80: bgez        $s0, L_80006C94
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80006C84: div.s       $f0, $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
            goto L_80006C94;
    }
    // 0x80006C84: div.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80006C88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006C8C: nop

    // 0x80006C90: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80006C94:
    // 0x80006C94: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80006C98: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80006C9C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006CA0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80006CA4: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x80006CA8: nop

    // 0x80006CAC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80006CB0: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80006CB4: nop

    // 0x80006CB8: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x80006CBC: beql        $s0, $zero, L_80006D0C
    if (ctx->r16 == 0) {
        // 0x80006CC0: mfc1        $s0, $f8
        ctx->r16 = (int32_t)ctx->f8.u32l;
            goto L_80006D0C;
    }
    goto skip_1;
    // 0x80006CC0: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x80006CC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006CC8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80006CCC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80006CD0: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x80006CD4: nop

    // 0x80006CD8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80006CDC: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80006CE0: nop

    // 0x80006CE4: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x80006CE8: bne         $s0, $zero, L_80006D00
    if (ctx->r16 != 0) {
        // 0x80006CEC: nop
    
            goto L_80006D00;
    }
    // 0x80006CEC: nop

    // 0x80006CF0: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x80006CF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006CF8: b           L_80006D18
    // 0x80006CFC: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_80006D18;
    // 0x80006CFC: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_80006D00:
    // 0x80006D00: b           L_80006D18
    // 0x80006D04: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_80006D18;
    // 0x80006D04: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80006D08: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
L_80006D0C:
    // 0x80006D0C: nop

    // 0x80006D10: bltz        $s0, L_80006D00
    if (SIGNED(ctx->r16) < 0) {
        // 0x80006D14: nop
    
            goto L_80006D00;
    }
    // 0x80006D14: nop

L_80006D18:
    // 0x80006D18: andi        $t4, $s0, 0xFFFF
    ctx->r12 = ctx->r16 & 0XFFFF;
    // 0x80006D1C: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80006D20: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80006D24: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80006D28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006D2C: bgez        $t4, L_80006D40
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80006D30: cvt.s.w     $f12, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80006D40;
    }
    // 0x80006D30: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80006D34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80006D38: nop

    // 0x80006D3C: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
L_80006D40:
    // 0x80006D40: jal         0x80034F60
    // 0x80006D44: nop

    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x80006D44: nop

    after_0:
    // 0x80006D48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006D4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006D50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006D54: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006D58: add.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80006D5C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80006D60: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80006D64: nop

    // 0x80006D68: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80006D6C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80006D70: nop

    // 0x80006D74: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80006D78: beql        $a0, $zero, L_80006DC8
    if (ctx->r4 == 0) {
        // 0x80006D7C: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_80006DC8;
    }
    goto skip_2;
    // 0x80006D7C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x80006D80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80006D84: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006D88: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80006D8C: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80006D90: nop

    // 0x80006D94: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80006D98: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80006D9C: nop

    // 0x80006DA0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80006DA4: bne         $a0, $zero, L_80006DBC
    if (ctx->r4 != 0) {
        // 0x80006DA8: nop
    
            goto L_80006DBC;
    }
    // 0x80006DA8: nop

    // 0x80006DAC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80006DB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006DB4: b           L_80006DD4
    // 0x80006DB8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80006DD4;
    // 0x80006DB8: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80006DBC:
    // 0x80006DBC: b           L_80006DD4
    // 0x80006DC0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80006DD4;
    // 0x80006DC0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80006DC4: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_80006DC8:
    // 0x80006DC8: nop

    // 0x80006DCC: bltz        $a0, L_80006DBC
    if (SIGNED(ctx->r4) < 0) {
        // 0x80006DD0: nop
    
            goto L_80006DBC;
    }
    // 0x80006DD0: nop

L_80006DD4:
    // 0x80006DD4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80006DD8: jal         0x80022FD0
    // 0x80006DDC: nop

    get_rand(rdram, ctx);
        goto after_1;
    // 0x80006DDC: nop

    after_1:
    // 0x80006DE0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80006DE4: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x80006DE8: bne         $t6, $zero, L_80006DFC
    if (ctx->r14 != 0) {
        // 0x80006DEC: or          $s0, $t6, $zero
        ctx->r16 = ctx->r14 | 0;
            goto L_80006DFC;
    }
    // 0x80006DEC: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80006DF0: addiu       $s0, $t6, 0x1
    ctx->r16 = ADD32(ctx->r14, 0X1);
    // 0x80006DF4: andi        $t7, $s0, 0xFFFF
    ctx->r15 = ctx->r16 & 0XFFFF;
    // 0x80006DF8: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
L_80006DFC:
    // 0x80006DFC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006E00: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80006E04: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80006E08: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80006E0C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80006E10: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80006E14: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80006E18: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80006E1C: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80006E20: beq         $at, $zero, L_80006E30
    if (ctx->r1 == 0) {
        // 0x80006E24: subu        $t0, $v1, $t9
        ctx->r8 = SUB32(ctx->r3, ctx->r25);
            goto L_80006E30;
    }
    // 0x80006E24: subu        $t0, $v1, $t9
    ctx->r8 = SUB32(ctx->r3, ctx->r25);
    // 0x80006E28: b           L_80006E34
    // 0x80006E2C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
        goto L_80006E34;
    // 0x80006E2C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
L_80006E30:
    // 0x80006E30: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
L_80006E34:
    // 0x80006E34: lhu         $t1, -0x44C8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X44C8);
    // 0x80006E38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80006E3C: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x80006E40: beq         $t2, $zero, L_80006E88
    if (ctx->r10 == 0) {
        // 0x80006E44: nop
    
            goto L_80006E88;
    }
    // 0x80006E44: nop

    // 0x80006E48: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80006E4C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80006E50: lhu         $t3, 0x8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8);
    // 0x80006E54: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80006E58: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80006E5C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80006E60: lhu         $v1, 0xA($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XA);
    // 0x80006E64: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x80006E68: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80006E6C: beq         $at, $zero, L_80006E78
    if (ctx->r1 == 0) {
        // 0x80006E70: nop
    
            goto L_80006E78;
    }
    // 0x80006E70: nop

    // 0x80006E74: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
L_80006E78:
    // 0x80006E78: jal         0x8001FCF8
    // 0x80006E7C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_8001FCF8(rdram, ctx);
        goto after_2;
    // 0x80006E7C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_2:
    // 0x80006E80: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006E84: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
L_80006E88:
    // 0x80006E88: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80006E8C: lw          $t7, -0x4538($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4538);
    // 0x80006E90: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80006E94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006E98: lhu         $t8, 0x28($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X28);
    // 0x80006E9C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80006EA0: sh          $t9, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r25;
    // 0x80006EA4: lw          $t0, -0x4538($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4538);
    // 0x80006EA8: lhu         $t1, 0x2E($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2E);
    // 0x80006EAC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80006EB0: sh          $t2, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r10;
    // 0x80006EB4: jal         0x80018DF4
    // 0x80006EB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80018DF4(rdram, ctx);
        goto after_3;
    // 0x80006EB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_3:
L_80006EBC:
    // 0x80006EBC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80006EC0: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80006EC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80006EC8: sh          $t3, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r11;
    // 0x80006ECC: lh          $t5, 0x62($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X62);
    // 0x80006ED0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80006ED4: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80006ED8: sh          $t5, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r13;
    // 0x80006EDC: lhu         $t6, 0x60($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X60);
    // 0x80006EE0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80006EE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006EE8: ori         $t8, $t6, 0x1
    ctx->r24 = ctx->r14 | 0X1;
    // 0x80006EEC: sh          $t8, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r24;
    // 0x80006EF0: lhu         $v0, 0x4E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X4E);
    // 0x80006EF4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80006EF8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80006EFC: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x80006F00: beq         $t9, $zero, L_80006F10
    if (ctx->r25 == 0) {
        // 0x80006F04: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80006F10;
    }
    // 0x80006F04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006F08: ori         $t1, $t8, 0x2
    ctx->r9 = ctx->r24 | 0X2;
    // 0x80006F0C: sh          $t1, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r9;
L_80006F10:
    // 0x80006F10: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x80006F14: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80006F18: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80006F1C: jal         0x8001D8B0
    // 0x80006F20: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8001D8B0(rdram, ctx);
        goto after_4;
    // 0x80006F20: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80006F24: beq         $s0, $zero, L_80006F3C
    if (ctx->r16 == 0) {
        // 0x80006F28: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_80006F3C;
    }
    // 0x80006F28: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80006F2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80006F30: jal         0x80013F20
    // 0x80006F34: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80013F20(rdram, ctx);
        goto after_5;
    // 0x80006F34: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80006F38: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80006F3C:
    // 0x80006F3C: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x80006F40: beq         $t3, $zero, L_80006F54
    if (ctx->r11 == 0) {
        // 0x80006F44: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80006F54;
    }
    // 0x80006F44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80006F48: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80006F4C: jal         0x800268D4
    // 0x80006F50: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_6;
    // 0x80006F50: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_6:
L_80006F54:
    // 0x80006F54: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80006F58:
    // 0x80006F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006F5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006F60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80006F64: jr          $ra
    // 0x80006F68: nop

    return;
    // 0x80006F68: nop

;}
RECOMP_FUNC void _nsqrtf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F60: jr          $ra
    // 0x80034F64: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x80034F64: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x80034F68: nop

    // 0x80034F6C: nop

;}
RECOMP_FUNC void func_8002260C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002260C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022614: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80022618: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8002261C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80022620: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80022624: jal         0x80014A98
    // 0x80022628: lh          $a1, 0x4($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X4);
    func_80014A98(rdram, ctx);
        goto after_0;
    // 0x80022628: lh          $a1, 0x4($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X4);
    after_0:
    // 0x8002262C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022634: jr          $ra
    // 0x80022638: nop

    return;
    // 0x80022638: nop

;}
RECOMP_FUNC void func_80021170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021178: lui         $a0, 0xD4
    ctx->r4 = S32(0XD4 << 16);
    // 0x8002117C: lui         $a1, 0x803B
    ctx->r5 = S32(0X803B << 16);
    // 0x80021180: addiu       $a1, $a1, -0x53E0
    ctx->r5 = ADD32(ctx->r5, -0X53E0);
    // 0x80021184: addiu       $a0, $a0, -0x41C0
    ctx->r4 = ADD32(ctx->r4, -0X41C0);
    // 0x80021188: jal         0x80024260
    // 0x8002118C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x8002118C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_0:
    // 0x80021190: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80021194: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80021198: addiu       $v0, $v0, -0x3890
    ctx->r2 = ADD32(ctx->r2, -0X3890);
    // 0x8002119C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800211A0:
    // 0x800211A0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800211A4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800211A8: bne         $v1, $zero, L_800211A0
    if (ctx->r3 != 0) {
        // 0x800211AC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800211A0;
    }
    // 0x800211AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800211B0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800211B4: addiu       $v0, $v0, -0x3087
    ctx->r2 = ADD32(ctx->r2, -0X3087);
    // 0x800211B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800211BC: sb          $a0, -0x3088($at)
    MEM_B(-0X3088, ctx->r1) = ctx->r4;
    // 0x800211C0: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x800211C4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800211C8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800211CC: addiu       $v1, $zero, 0x94
    ctx->r3 = ADD32(0, 0X94);
L_800211D0:
    // 0x800211D0: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800211D4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800211D8: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x800211DC: sb          $a0, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r4;
    // 0x800211E0: sb          $a0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r4;
    // 0x800211E4: bne         $v1, $zero, L_800211D0
    if (ctx->r3 != 0) {
        // 0x800211E8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800211D0;
    }
    // 0x800211E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800211EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800211F0: sw          $zero, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = 0;
    // 0x800211F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800211F8: sw          $zero, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = 0;
    // 0x800211FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80021200: sw          $zero, -0x3898($at)
    MEM_W(-0X3898, ctx->r1) = 0;
    // 0x80021204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002120C: jr          $ra
    // 0x80021210: nop

    return;
    // 0x80021210: nop

;}
RECOMP_FUNC void func_80030E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030E60: lui         $a0, 0xD4
    ctx->r4 = S32(0XD4 << 16);
    // 0x80030E64: lui         $a1, 0x8033
    ctx->r5 = S32(0X8033 << 16);
    // 0x80030E68: addiu       $a1, $a1, 0x1A30
    ctx->r5 = ADD32(ctx->r5, 0X1A30);
    // 0x80030E6C: addiu       $a0, $a0, -0x1DC0
    ctx->r4 = ADD32(ctx->r4, -0X1DC0);
    // 0x80030E70: jal         0x80024260
    // 0x80030E74: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80030E74: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_0:
    // 0x80030E78: lui         $a0, 0xD4
    ctx->r4 = S32(0XD4 << 16);
    // 0x80030E7C: lui         $a1, 0x8032
    ctx->r5 = S32(0X8032 << 16);
    // 0x80030E80: addiu       $a1, $a1, 0x32A0
    ctx->r5 = ADD32(ctx->r5, 0X32A0);
    // 0x80030E84: addiu       $a0, $a0, -0x1D40
    ctx->r4 = ADD32(ctx->r4, -0X1D40);
    // 0x80030E88: jal         0x80024260
    // 0x80030E8C: ori         $a2, $zero, 0xE790
    ctx->r6 = 0 | 0XE790;
    dma_write(rdram, ctx);
        goto after_1;
    // 0x80030E8C: ori         $a2, $zero, 0xE790
    ctx->r6 = 0 | 0XE790;
    after_1:
    // 0x80030E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030E98: jr          $ra
    // 0x80030E9C: nop

    return;
    // 0x80030E9C: nop

;}
RECOMP_FUNC void func_8000B2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B2C8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000B2CC: addiu       $v0, $v0, -0x2F40
    ctx->r2 = ADD32(ctx->r2, -0X2F40);
    // 0x8000B2D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000B2D4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8000B2D8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8000B2DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000B2E0: lw          $t7, 0x4640($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4640);
    // 0x8000B2E4: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000B2E8: addiu       $t8, $t8, -0x3644
    ctx->r24 = ADD32(ctx->r24, -0X3644);
    // 0x8000B2EC: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x8000B2F0: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x8000B2F4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000B2F8: jr          $ra
    // 0x8000B2FC: nop

    return;
    // 0x8000B2FC: nop

;}
RECOMP_FUNC void func_80016520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016520: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80016524: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80016528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001652C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016530: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80016534: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80016538: jal         0x800175D4
    // 0x8001653C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    func_800175D4(rdram, ctx);
        goto after_0;
    // 0x8001653C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_0:
    // 0x80016540: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80016544: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80016548: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x8001654C: lw          $t6, 0x68($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X68);
    // 0x80016550: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80016554: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80016558: beql        $t8, $zero, L_80016570
    if (ctx->r24 == 0) {
        // 0x8001655C: lhu         $t0, 0x5E($a0)
        ctx->r8 = MEM_HU(ctx->r4, 0X5E);
            goto L_80016570;
    }
    goto skip_0;
    // 0x8001655C: lhu         $t0, 0x5E($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X5E);
    skip_0:
    // 0x80016560: srl         $a3, $v0, 1
    ctx->r7 = S32(U32(ctx->r2) >> 1);
    // 0x80016564: andi        $t9, $a3, 0xFFFF
    ctx->r25 = ctx->r7 & 0XFFFF;
    // 0x80016568: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8001656C: lhu         $t0, 0x5E($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X5E);
L_80016570:
    // 0x80016570: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80016574: beql        $t1, $zero, L_800165C4
    if (ctx->r9 == 0) {
        // 0x80016578: lw          $t5, 0x2C($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X2C);
            goto L_800165C4;
    }
    goto skip_1;
    // 0x80016578: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    skip_1:
    // 0x8001657C: jal         0x8000B140
    // 0x80016580: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    func_8000B140(rdram, ctx);
        goto after_1;
    // 0x80016580: sh          $a3, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r7;
    after_1:
    // 0x80016584: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80016588: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8001658C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80016590: lbu         $a2, 0x6($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X6);
    // 0x80016594: lhu         $a3, 0x2($v1)
    ctx->r7 = MEM_HU(ctx->r3, 0X2);
    // 0x80016598: lhu         $a1, 0x2E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2E);
    // 0x8001659C: jal         0x8000ACC0
    // 0x800165A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_8000ACC0(rdram, ctx);
        goto after_2;
    // 0x800165A0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_2:
    // 0x800165A4: beq         $v0, $zero, L_800165D0
    if (ctx->r2 == 0) {
        // 0x800165A8: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_800165D0;
    }
    // 0x800165A8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800165AC: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
    // 0x800165B0: lhu         $t3, 0x2A($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X2A);
    // 0x800165B4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800165B8: b           L_800165D0
    // 0x800165BC: sh          $t4, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r12;
        goto L_800165D0;
    // 0x800165BC: sh          $t4, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r12;
    // 0x800165C0: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
L_800165C4:
    // 0x800165C4: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x800165C8: jal         0x80006BEC
    // 0x800165CC: lhu         $a1, 0x2($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X2);
    func_80006BEC(rdram, ctx);
        goto after_3;
    // 0x800165CC: lhu         $a1, 0x2($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X2);
    after_3:
L_800165D0:
    // 0x800165D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800165D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800165D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800165DC: jr          $ra
    // 0x800165E0: nop

    return;
    // 0x800165E0: nop

;}
RECOMP_FUNC void func_80041870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041870: beq         $a2, $zero, L_80041890
    if (ctx->r6 == 0) {
        // 0x80041874: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80041890;
    }
    // 0x80041874: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041878: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x8004187C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80041880: nop

    // 0x80041884: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80041888: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x8004188C: nop

L_80041890:
    // 0x80041890: jr          $ra
    // 0x80041894: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x80041894: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
;}
RECOMP_FUNC void func_80017428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001742C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80017438: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001743C: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x80017440: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80017444: lw          $v0, 0x68($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X68);
    // 0x80017448: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8001744C: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80017450: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x80017454: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80017458: jal         0x8001FCF8
    // 0x8001745C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x8001745C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80017460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017468: jr          $ra
    // 0x8001746C: nop

    return;
    // 0x8001746C: nop

;}
RECOMP_FUNC void func_80016D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016D6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80016D70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80016D74: jal         0x80016520
    // 0x80016D78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80016520(rdram, ctx);
        goto after_0;
    // 0x80016D78: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80016D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80016D80: jal         0x80016CB0
    // 0x80016D84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80016CB0(rdram, ctx);
        goto after_1;
    // 0x80016D84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80016D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80016D90: jr          $ra
    // 0x80016D94: nop

    return;
    // 0x80016D94: nop

;}
RECOMP_FUNC void _init_lpfilter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040350: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80040354: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x80040358: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004035C: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x80040360: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x80040364: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80040368: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004036C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x80040370: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x80040374: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80040378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004037C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_80040380:
    // 0x80040380: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80040384: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80040388: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8004038C: bne         $at, $zero, L_80040380
    if (ctx->r1 != 0) {
        // 0x80040390: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_80040380;
    }
    // 0x80040390: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80040394: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80040398: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x8004039C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800403A0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800403A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800403A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800403AC: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800403B0: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x800403B4: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x800403B8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800403BC: beq         $at, $zero, L_800403E8
    if (ctx->r1 == 0) {
        // 0x800403C0: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_800403E8;
    }
    // 0x800403C0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_800403C4:
    // 0x800403C4: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800403C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800403CC: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800403D0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800403D4: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x800403D8: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800403DC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800403E0: bne         $at, $zero, L_800403C4
    if (ctx->r1 != 0) {
        // 0x800403E4: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_800403C4;
    }
    // 0x800403E4: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_800403E8:
    // 0x800403E8: jr          $ra
    // 0x800403EC: nop

    return;
    // 0x800403EC: nop

;}
RECOMP_FUNC void func_80026554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002655C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80026560: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80026564: lw          $t6, 0x398C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X398C);
    // 0x80026568: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8002656C: bne         $t6, $zero, L_80026588
    if (ctx->r14 != 0) {
        // 0x80026570: nop
    
            goto L_80026588;
    }
    // 0x80026570: nop

    // 0x80026574: lw          $t7, 0x3990($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3990);
    // 0x80026578: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8002657C: addiu       $v0, $v0, 0x3974
    ctx->r2 = ADD32(ctx->r2, 0X3974);
    // 0x80026580: beq         $t7, $zero, L_80026590
    if (ctx->r15 == 0) {
        // 0x80026584: sll         $t8, $a2, 7
        ctx->r24 = S32(ctx->r6 << 7);
            goto L_80026590;
    }
    // 0x80026584: sll         $t8, $a2, 7
    ctx->r24 = S32(ctx->r6 << 7);
L_80026588:
    // 0x80026588: b           L_800265D8
    // 0x8002658C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800265D8;
    // 0x8002658C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80026590:
    // 0x80026590: addiu       $t9, $t8, 0x7F
    ctx->r25 = ADD32(ctx->r24, 0X7F);
    // 0x80026594: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80026598: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002659C: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    // 0x800265A0: jal         0x800368E0
    // 0x800265A4: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    func_800368E0(rdram, ctx);
        goto after_0;
    // 0x800265A4: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x800265A8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800265AC: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x800265B0: lh          $a1, 0x3976($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X3976);
    // 0x800265B4: jal         0x800368E0
    // 0x800265B8: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    func_800368E0(rdram, ctx);
        goto after_1;
    // 0x800265B8: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    after_1:
    // 0x800265BC: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x800265C0: lw          $v1, 0x3974($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3974);
    // 0x800265C4: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x800265C8: addiu       $a0, $a0, 0x3984
    ctx->r4 = ADD32(ctx->r4, 0X3984);
    // 0x800265CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800265D0: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800265D4: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_800265D8:
    // 0x800265D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800265DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800265E0: jr          $ra
    // 0x800265E4: nop

    return;
    // 0x800265E4: nop

    // 0x800265E8: nop

    // 0x800265EC: nop

;}
RECOMP_FUNC void func_8000A008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A008: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8000A00C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000A010: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000A014: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000A018: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x8000A01C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000A020: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000A024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000A028: lhu         $t6, 0x8($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X8);
    // 0x8000A02C: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8000A030: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8000A034: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000A038: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000A03C: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000A040: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000A044: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000A048: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000A04C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000A050: nop

    // 0x8000A054: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000A058: jal         0x80034F60
    // 0x8000A05C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000A05C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x8000A060: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000A064: lw          $t8, -0x44D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44D0);
    // 0x8000A068: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000A06C: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x8000A070: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8000A074: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8000A078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000A07C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000A080: lhu         $a2, 0x2C($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X2C);
    // 0x8000A084: addiu       $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
    // 0x8000A088: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000A08C: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8000A090: beq         $a2, $zero, L_8000A0C0
    if (ctx->r6 == 0) {
        // 0x8000A094: sub.s       $f16, $f0, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
            goto L_8000A0C0;
    }
    // 0x8000A094: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8000A098: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_8000A09C:
    // 0x8000A09C: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8000A0A0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000A0A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000A0A8: lhu         $a2, 0x2C($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X2C);
    // 0x8000A0AC: addiu       $t2, $t2, 0x18
    ctx->r10 = ADD32(ctx->r10, 0X18);
    // 0x8000A0B0: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x8000A0B4: bnel        $at, $zero, L_8000A09C
    if (ctx->r1 != 0) {
        // 0x8000A0B8: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_8000A09C;
    }
    goto skip_0;
    // 0x8000A0B8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    skip_0:
    // 0x8000A0BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000A0C0:
    // 0x8000A0C0: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
L_8000A0C4:
    // 0x8000A0C4: beq         $a3, $zero, L_8000A118
    if (ctx->r7 == 0) {
        // 0x8000A0C8: addiu       $v1, $sp, 0x3C
        ctx->r3 = ADD32(ctx->r29, 0X3C);
            goto L_8000A118;
    }
    // 0x8000A0C8: addiu       $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
L_8000A0CC:
    // 0x8000A0CC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8000A0D0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8000A0D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000A0D8: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000A0DC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000A0E0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8000A0E4: nop

    // 0x8000A0E8: bc1fl       L_8000A10C
    if (!c1cs) {
        // 0x8000A0EC: sltu        $at, $a0, $a3
        ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
            goto L_8000A10C;
    }
    goto skip_1;
    // 0x8000A0EC: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
    skip_1:
    // 0x8000A0F0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000A0F4: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8000A0F8: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8000A0FC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000A100: lhu         $a2, 0x2C($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X2C);
    // 0x8000A104: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x8000A108: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
L_8000A10C:
    // 0x8000A10C: bne         $at, $zero, L_8000A0CC
    if (ctx->r1 != 0) {
        // 0x8000A110: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000A0CC;
    }
    // 0x8000A110: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000A114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000A118:
    // 0x8000A118: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
    // 0x8000A11C: bne         $v0, $zero, L_8000A0C4
    if (ctx->r2 != 0) {
        // 0x8000A120: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8000A0C4;
    }
    // 0x8000A120: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000A124: beq         $a2, $zero, L_8000A22C
    if (ctx->r6 == 0) {
        // 0x8000A128: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8000A22C;
    }
    // 0x8000A128: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8000A12C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000A130: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8000A134: addiu       $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
    // 0x8000A138: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8000A13C: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000A140: nop

L_8000A144:
    // 0x8000A144: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x8000A148: beq         $at, $zero, L_8000A1D8
    if (ctx->r1 == 0) {
        // 0x8000A14C: lw          $t2, 0x0($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X0);
            goto L_8000A1D8;
    }
    // 0x8000A14C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000A150: lwc1        $f10, 0x10($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8000A154: mul.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8000A158: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8000A15C: add.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8000A160: bc1fl       L_8000A174
    if (!c1cs) {
        // 0x8000A164: c.lt.s      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
            goto L_8000A174;
    }
    goto skip_2;
    // 0x8000A164: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    skip_2:
    // 0x8000A168: b           L_8000A22C
    // 0x8000A16C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000A22C;
    // 0x8000A16C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A170: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
L_8000A174:
    // 0x8000A174: nop

    // 0x8000A178: bc1fl       L_8000A220
    if (!c1cs) {
        // 0x8000A17C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000A220;
    }
    goto skip_3;
    // 0x8000A17C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_3:
    // 0x8000A180: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x8000A184: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8000A188: mul.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8000A18C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8000A190: nop

    // 0x8000A194: bc1fl       L_8000A220
    if (!c1cs) {
        // 0x8000A198: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000A220;
    }
    goto skip_4;
    // 0x8000A198: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x8000A19C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000A1A0: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x8000A1A4: jal         0x80022FD0
    // 0x8000A1A8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    get_rand(rdram, ctx);
        goto after_1;
    // 0x8000A1A8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_1:
    // 0x8000A1AC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8000A1B0: bne         $v0, $zero, L_8000A1BC
    if (ctx->r2 != 0) {
        // 0x8000A1B4: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_8000A1BC;
    }
    // 0x8000A1B4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8000A1B8: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
L_8000A1BC:
    // 0x8000A1BC: beq         $t2, $a1, L_8000A1D0
    if (ctx->r10 == ctx->r5) {
        // 0x8000A1C0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8000A1D0;
    }
    // 0x8000A1C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A1C4: lhu         $t9, 0x8($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X8);
    // 0x8000A1C8: ori         $t3, $t9, 0x10
    ctx->r11 = ctx->r25 | 0X10;
    // 0x8000A1CC: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
L_8000A1D0:
    // 0x8000A1D0: b           L_8000A22C
    // 0x8000A1D4: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
        goto L_8000A22C;
    // 0x8000A1D4: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
L_8000A1D8:
    // 0x8000A1D8: lwc1        $f4, 0x10($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8000A1DC: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000A1E0: add.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8000A1E4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8000A1E8: nop

    // 0x8000A1EC: bc1fl       L_8000A220
    if (!c1cs) {
        // 0x8000A1F0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8000A220;
    }
    goto skip_5;
    // 0x8000A1F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_5:
    // 0x8000A1F4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8000A1F8: nop

    // 0x8000A1FC: bc1f        L_8000A214
    if (!c1cs) {
        // 0x8000A200: nop
    
            goto L_8000A214;
    }
    // 0x8000A200: nop

    // 0x8000A204: lhu         $t4, 0x8($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X8);
    // 0x8000A208: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8000A20C: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x8000A210: sh          $t5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r13;
L_8000A214:
    // 0x8000A214: b           L_8000A22C
    // 0x8000A218: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000A22C;
    // 0x8000A218: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000A21C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8000A220:
    // 0x8000A220: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8000A224: bne         $at, $zero, L_8000A144
    if (ctx->r1 != 0) {
        // 0x8000A228: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000A144;
    }
    // 0x8000A228: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000A22C:
    // 0x8000A22C: bnel        $t0, $zero, L_8000A23C
    if (ctx->r8 != 0) {
        // 0x8000A230: lhu         $t6, 0x24($t1)
        ctx->r14 = MEM_HU(ctx->r9, 0X24);
            goto L_8000A23C;
    }
    goto skip_6;
    // 0x8000A230: lhu         $t6, 0x24($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X24);
    skip_6:
    // 0x8000A234: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8000A238: lhu         $t6, 0x24($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X24);
L_8000A23C:
    // 0x8000A23C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8000A240: beql        $t7, $zero, L_8000A26C
    if (ctx->r15 == 0) {
        // 0x8000A244: sw          $t2, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r10;
            goto L_8000A26C;
    }
    goto skip_7;
    // 0x8000A244: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
    skip_7:
    // 0x8000A248: jal         0x80022FD0
    // 0x8000A24C: lhu         $a0, 0x2C($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2C);
    get_rand(rdram, ctx);
        goto after_2;
    // 0x8000A24C: lhu         $a0, 0x2C($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2C);
    after_2:
    // 0x8000A250: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x8000A254: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8000A258: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8000A25C: lw          $t3, 0x30($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X30);
    // 0x8000A260: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000A264: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x8000A268: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
L_8000A26C:
    // 0x8000A26C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8000A270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A274: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000A278: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000A27C: jr          $ra
    // 0x8000A280: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8000A280: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8002DF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DF6C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002DF70: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8002DF74: addiu       $a2, $a2, -0x2F4
    ctx->r6 = ADD32(ctx->r6, -0X2F4);
    // 0x8002DF78: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x8002DF7C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8002DF80: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x8002DF84: addiu       $t8, $t8, -0x560
    ctx->r24 = ADD32(ctx->r24, -0X560);
    // 0x8002DF88: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8002DF8C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8002DF90: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8002DF94: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8002DF98: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8002DF9C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8002DFA0: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8002DFA4: ori         $t0, $t0, 0xE02
    ctx->r8 = ctx->r8 | 0XE02;
    // 0x8002DFA8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8002DFAC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8002DFB0: ori         $t1, $zero, 0x8000
    ctx->r9 = 0 | 0X8000;
    // 0x8002DFB4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8002DFB8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8002DFBC: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x8002DFC0: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8002DFC4: sh          $t3, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r11;
    // 0x8002DFC8: jr          $ra
    // 0x8002DFCC: nop

    return;
    // 0x8002DFCC: nop

;}
RECOMP_FUNC void func_800250E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800250E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800250EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800250F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800250F4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800250F8: addiu       $t6, $t6, -0xDC0
    ctx->r14 = ADD32(ctx->r14, -0XDC0);
    // 0x800250FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025100: lui         $a2, 0x8002
    ctx->r6 = S32(0X8002 << 16);
    // 0x80025104: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80025108: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002510C: addiu       $a2, $a2, 0x4BEC
    ctx->r6 = ADD32(ctx->r6, 0X4BEC);
    // 0x80025110: addiu       $a0, $a0, -0x2F70
    ctx->r4 = ADD32(ctx->r4, -0X2F70);
    // 0x80025114: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80025118: jal         0x80033AE0
    // 0x8002511C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8002511C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80025120: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025124: jal         0x80033C30
    // 0x80025128: addiu       $a0, $a0, -0x2F70
    ctx->r4 = ADD32(ctx->r4, -0X2F70);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80025128: addiu       $a0, $a0, -0x2F70
    ctx->r4 = ADD32(ctx->r4, -0X2F70);
    after_1:
    // 0x8002512C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80025130: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80025134: jr          $ra
    // 0x80025138: nop

    return;
    // 0x80025138: nop

;}
RECOMP_FUNC void func_800408D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800408D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800408D4: bne         $a1, $at, L_800408F8
    if (ctx->r5 != ctx->r1) {
        // 0x800408D8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800408F8;
    }
    // 0x800408D8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800408DC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800408E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800408E4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800408E8: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800408EC: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800408F0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800408F4: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800408F8:
    // 0x800408F8: jr          $ra
    // 0x800408FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800408FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80101A5C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101A5C: sll         $t6, $a1, 0
    ctx->r14 = S32(ctx->r5 << 0);
    // 0x80101A60: bltz        $t6, L_80101A70
    if (SIGNED(ctx->r14) < 0) {
        // 0x80101A64: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80101A70;
    }
    // 0x80101A64: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80101A68: jr          $ra
    // 0x80101A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80101A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101A70:
    // 0x80101A70: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80101A74: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80101A78: addiu       $t8, $t8, 0x6250
    ctx->r24 = ADD32(ctx->r24, 0X6250);
    // 0x80101A7C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80101A80: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80101A84: lh          $t4, 0x2A($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2A);
    // 0x80101A88: lh          $t5, 0x26($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X26);
    // 0x80101A8C: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80101A90: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80101A94: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80101A98: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80101A9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80101AA0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80101AA4: lh          $t9, 0x24($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X24);
    // 0x80101AA8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80101AAC: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80101AB0: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    // 0x80101AB4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101AB8: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80101ABC: div.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80101AC0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80101AC4: nop

    // 0x80101AC8: bc1fl       L_80101AD8
    if (!c1cs) {
        // 0x80101ACC: lwc1        $f4, 0x1C($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_80101AD8;
    }
    goto skip_0;
    // 0x80101ACC: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    skip_0:
    // 0x80101AD0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80101AD4: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
L_80101AD8:
    // 0x80101AD8: lh          $t7, 0x2C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2C);
    // 0x80101ADC: lh          $t8, 0x28($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X28);
    // 0x80101AE0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80101AE4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80101AE8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80101AEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80101AF0: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x80101AF4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80101AF8: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80101AFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101B00: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80101B04: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80101B08: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80101B0C: div.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80101B10: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80101B14: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80101B18: nop

    // 0x80101B1C: bc1fl       L_80101B2C
    if (!c1cs) {
        // 0x80101B20: lwc1        $f8, 0x20($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
            goto L_80101B2C;
    }
    goto skip_1;
    // 0x80101B20: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
    skip_1:
    // 0x80101B24: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80101B28: lwc1        $f8, 0x20($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X20);
L_80101B2C:
    // 0x80101B2C: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80101B30: lh          $t2, 0x2A($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2A);
    // 0x80101B34: add.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80101B38: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80101B3C: swc1        $f16, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f16.u32l;
    // 0x80101B40: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80101B44: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80101B48: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80101B4C: beq         $at, $zero, L_80101B5C
    if (ctx->r1 == 0) {
        // 0x80101B50: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80101B5C;
    }
    // 0x80101B50: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80101B54: b           L_80101B60
    // 0x80101B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80101B60;
    // 0x80101B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80101B5C:
    // 0x80101B5C: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_80101B60:
    // 0x80101B60: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x80101B64: lh          $t3, 0x2C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2C);
    // 0x80101B68: ori         $t4, $v0, 0x4
    ctx->r12 = ctx->r2 | 0X4;
    // 0x80101B6C: ori         $t5, $v0, 0x8
    ctx->r13 = ctx->r2 | 0X8;
    // 0x80101B70: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80101B74: beql        $at, $zero, L_80101B88
    if (ctx->r1 == 0) {
        // 0x80101B78: negu        $a3, $a2
        ctx->r7 = SUB32(0, ctx->r6);
            goto L_80101B88;
    }
    goto skip_2;
    // 0x80101B78: negu        $a3, $a2
    ctx->r7 = SUB32(0, ctx->r6);
    skip_2:
    // 0x80101B7C: b           L_80101B8C
    // 0x80101B80: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
        goto L_80101B8C;
    // 0x80101B80: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x80101B84: negu        $a3, $a2
    ctx->r7 = SUB32(0, ctx->r6);
L_80101B88:
    // 0x80101B88: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80101B8C:
    // 0x80101B8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80101B90: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80101B94: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80101B98: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x80101B9C: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80101BA0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80101BA4: addu        $t7, $t1, $a3
    ctx->r15 = ADD32(ctx->r9, ctx->r7);
    // 0x80101BA8: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x80101BAC: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80101BB0: bc1f        L_80101BCC
    if (!c1cs) {
        // 0x80101BB4: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_80101BCC;
    }
    // 0x80101BB4: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x80101BB8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x80101BBC: nop

    // 0x80101BC0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80101BC4: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80101BC8: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
L_80101BCC:
    // 0x80101BCC: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80101BD0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80101BD4: nop

    // 0x80101BD8: bc1fl       L_80101BF8
    if (!c1cs) {
        // 0x80101BDC: lh          $t8, 0x24($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X24);
            goto L_80101BF8;
    }
    goto skip_3;
    // 0x80101BDC: lh          $t8, 0x24($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X24);
    skip_3:
    // 0x80101BE0: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80101BE4: nop

    // 0x80101BE8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80101BEC: sub.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80101BF0: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x80101BF4: lh          $t8, 0x24($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X24);
L_80101BF8:
    // 0x80101BF8: lw          $t9, 0x38($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X38);
    // 0x80101BFC: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80101C00: bne         $at, $zero, L_80101C18
    if (ctx->r1 != 0) {
        // 0x80101C04: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_80101C18;
    }
    // 0x80101C04: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x80101C08: lh          $t2, 0x2A($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2A);
    // 0x80101C0C: lh          $t3, 0x2C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2C);
    // 0x80101C10: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x80101C14: sh          $t3, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r11;
L_80101C18:
    // 0x80101C18: beq         $t4, $zero, L_80101C3C
    if (ctx->r12 == 0) {
        // 0x80101C1C: andi        $t2, $v0, 0x8
        ctx->r10 = ctx->r2 & 0X8;
            goto L_80101C3C;
    }
    // 0x80101C1C: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x80101C20: lh          $a0, 0x2A($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2A);
    // 0x80101C24: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    // 0x80101C28: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80101C2C: bne         $at, $zero, L_80101C5C
    if (ctx->r1 != 0) {
        // 0x80101C30: nop
    
            goto L_80101C5C;
    }
    // 0x80101C30: nop

    // 0x80101C34: b           L_80101C5C
    // 0x80101C38: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
        goto L_80101C5C;
    // 0x80101C38: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
L_80101C3C:
    // 0x80101C3C: beq         $t6, $zero, L_80101C5C
    if (ctx->r14 == 0) {
        // 0x80101C40: nop
    
            goto L_80101C5C;
    }
    // 0x80101C40: nop

    // 0x80101C44: lh          $a0, 0x2A($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2A);
    // 0x80101C48: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80101C4C: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80101C50: bne         $at, $zero, L_80101C5C
    if (ctx->r1 != 0) {
        // 0x80101C54: nop
    
            goto L_80101C5C;
    }
    // 0x80101C54: nop

    // 0x80101C58: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
L_80101C5C:
    // 0x80101C5C: beq         $t8, $zero, L_80101C80
    if (ctx->r24 == 0) {
        // 0x80101C60: nop
    
            goto L_80101C80;
    }
    // 0x80101C60: nop

    // 0x80101C64: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x80101C68: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80101C6C: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101C70: bnel        $at, $zero, L_80101CA4
    if (ctx->r1 != 0) {
        // 0x80101C74: lh          $t4, 0x24($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X24);
            goto L_80101CA4;
    }
    goto skip_4;
    // 0x80101C74: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
    skip_4:
    // 0x80101C78: b           L_80101CA0
    // 0x80101C7C: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
        goto L_80101CA0;
    // 0x80101C7C: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_80101C80:
    // 0x80101C80: beql        $t2, $zero, L_80101CA4
    if (ctx->r10 == 0) {
        // 0x80101C84: lh          $t4, 0x24($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X24);
            goto L_80101CA4;
    }
    goto skip_5;
    // 0x80101C84: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
    skip_5:
    // 0x80101C88: lh          $v0, 0x2C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2C);
    // 0x80101C8C: lh          $t3, 0x6($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X6);
    // 0x80101C90: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80101C94: bnel        $at, $zero, L_80101CA4
    if (ctx->r1 != 0) {
        // 0x80101C98: lh          $t4, 0x24($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X24);
            goto L_80101CA4;
    }
    goto skip_6;
    // 0x80101C98: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
    skip_6:
    // 0x80101C9C: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_80101CA0:
    // 0x80101CA0: lh          $t4, 0x24($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X24);
L_80101CA4:
    // 0x80101CA4: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    // 0x80101CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101CAC: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80101CB0: bne         $at, $zero, L_80101CD0
    if (ctx->r1 != 0) {
        // 0x80101CB4: nop
    
            goto L_80101CD0;
    }
    // 0x80101CB4: nop

    // 0x80101CB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101CBC: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x80101CC0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101CC4: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80101CC8: jr          $ra
    // 0x80101CCC: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80101CCC: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
L_80101CD0:
    // 0x80101CD0: jr          $ra
    // 0x80101CD4: nop

    return;
    // 0x80101CD4: nop

;}
RECOMP_FUNC void func_800086E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800086E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800086E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800086EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800086F0: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800086F4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800086F8: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800086FC: addiu       $t7, $t7, -0x42D0
    ctx->r15 = ADD32(ctx->r15, -0X42D0);
    // 0x80008700: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80008704: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80008708: lw          $t9, 0x80($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X80);
    // 0x8000870C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80008710: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80008714: lbu         $t0, 0x5($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X5);
    // 0x80008718: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x8000871C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008720: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x80008724: beql        $t1, $zero, L_80008738
    if (ctx->r9 == 0) {
        // 0x80008728: sh          $t2, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r10;
            goto L_80008738;
    }
    goto skip_0;
    // 0x80008728: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    skip_0:
    // 0x8000872C: b           L_800087E0
    // 0x80008730: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
        goto L_800087E0;
    // 0x80008730: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80008734: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
L_80008738:
    // 0x80008738: lwc1        $f4, -0x4534($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4534);
    // 0x8000873C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008740: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80008744: lwc1        $f8, -0x452C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X452C);
    // 0x80008748: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8000874C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008750: jal         0x80023210
    // 0x80008754: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x80008754: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x80008758: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8000875C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80008760: ldc1        $f18, 0x1130($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1130);
    // 0x80008764: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80008768: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000876C: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80008770: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80008774: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80008778: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000877C: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80008780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80008784: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80008788: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000878C: bc1f        L_800087A4
    if (!c1cs) {
        // 0x80008790: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_800087A4;
    }
    // 0x80008790: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80008794: ldc1        $f4, 0x1138($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1138);
    // 0x80008798: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x8000879C: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800087A0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_800087A4:
    // 0x800087A4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800087A8: ldc1        $f8, 0x1140($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1140);
    // 0x800087AC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800087B0: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x800087B4: nop

    // 0x800087B8: bc1fl       L_800087D0
    if (!c1cs) {
        // 0x800087BC: swc1        $f12, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f12.u32l;
            goto L_800087D0;
    }
    goto skip_1;
    // 0x800087BC: swc1        $f12, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f12.u32l;
    skip_1:
    // 0x800087C0: ldc1        $f10, 0x1148($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1148);
    // 0x800087C4: sub.d       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f2.d - ctx->f10.d;
    // 0x800087C8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x800087CC: swc1        $f12, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f12.u32l;
L_800087D0:
    // 0x800087D0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x800087D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800087D8: jal         0x8001D8B0
    // 0x800087DC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x800087DC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_1:
L_800087E0:
    // 0x800087E0: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    // 0x800087E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800087E8: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x800087EC: beq         $v1, $at, L_8000880C
    if (ctx->r3 == ctx->r1) {
        // 0x800087F0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8000880C;
    }
    // 0x800087F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800087F4: beq         $v1, $at, L_80008870
    if (ctx->r3 == ctx->r1) {
        // 0x800087F8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80008870;
    }
    // 0x800087F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800087FC: beq         $v1, $at, L_800088D4
    if (ctx->r3 == ctx->r1) {
        // 0x80008800: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800088D4;
    }
    // 0x80008800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80008804: b           L_8000892C
    // 0x80008808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8000892C;
    // 0x80008808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8000880C:
    // 0x8000880C: jal         0x80021240
    // 0x80008810: lbu         $a0, 0x7($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X7);
    func_80021240(rdram, ctx);
        goto after_2;
    // 0x80008810: lbu         $a0, 0x7($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X7);
    after_2:
    // 0x80008814: bne         $v0, $zero, L_8000882C
    if (ctx->r2 != 0) {
        // 0x80008818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000882C;
    }
    // 0x80008818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000881C: lw          $t6, 0x80($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80);
    // 0x80008820: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008824: b           L_80008838
    // 0x80008828: lhu         $a1, 0x8($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X8);
        goto L_80008838;
    // 0x80008828: lhu         $a1, 0x8($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X8);
L_8000882C:
    // 0x8000882C: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
    // 0x80008830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008834: lhu         $a1, 0xA($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0XA);
L_80008838:
    // 0x80008838: jal         0x80008A00
    // 0x8000883C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80008A00(rdram, ctx);
        goto after_3;
    // 0x8000883C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x80008840: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80008844: bnel        $v0, $zero, L_80008938
    if (ctx->r2 != 0) {
        // 0x80008848: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80008938;
    }
    goto skip_2;
    // 0x80008848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8000884C: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
    // 0x80008850: jal         0x800212A0
    // 0x80008854: lbu         $a0, 0x7($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X7);
    func_800212A0(rdram, ctx);
        goto after_4;
    // 0x80008854: lbu         $a0, 0x7($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X7);
    after_4:
    // 0x80008858: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000885C: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80008860: lhu         $t9, 0x8($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X8);
    // 0x80008864: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x80008868: b           L_80008934
    // 0x8000886C: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
        goto L_80008934;
    // 0x8000886C: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
L_80008870:
    // 0x80008870: jal         0x8000B9D8
    // 0x80008874: lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6);
    func_8000B9D8(rdram, ctx);
        goto after_5;
    // 0x80008874: lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6);
    after_5:
    // 0x80008878: bnel        $v0, $zero, L_80008890
    if (ctx->r2 != 0) {
        // 0x8000887C: lw          $v0, 0x80($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X80);
            goto L_80008890;
    }
    goto skip_3;
    // 0x8000887C: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    skip_3:
    // 0x80008880: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    // 0x80008884: b           L_800088C4
    // 0x80008888: lhu         $a1, 0x8($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X8);
        goto L_800088C4;
    // 0x80008888: lhu         $a1, 0x8($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X8);
    // 0x8000888C: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
L_80008890:
    // 0x80008890: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80008894: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80008898: lhu         $t2, 0x6($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X6);
    // 0x8000889C: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x800088A0: lhu         $a1, 0xA($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0XA);
    // 0x800088A4: bne         $t2, $at, L_800088C4
    if (ctx->r10 != ctx->r1) {
        // 0x800088A8: nop
    
            goto L_800088C4;
    }
    // 0x800088A8: nop

    // 0x800088AC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800088B0: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
    // 0x800088B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800088B8: ori         $t4, $t3, 0x8080
    ctx->r12 = ctx->r11 | 0X8080;
    // 0x800088BC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800088C0: sw          $t5, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r13;
L_800088C4:
    // 0x800088C4: jal         0x80008A00
    // 0x800088C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80008A00(rdram, ctx);
        goto after_6;
    // 0x800088C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800088CC: b           L_80008938
    // 0x800088D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80008938;
    // 0x800088D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800088D4:
    // 0x800088D4: jal         0x80008A00
    // 0x800088D8: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    func_80008A00(rdram, ctx);
        goto after_7;
    // 0x800088D8: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    after_7:
    // 0x800088DC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800088E0: addiu       $v0, $v0, 0x5C8
    ctx->r2 = ADD32(ctx->r2, 0X5C8);
    // 0x800088E4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x800088E8: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x800088EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800088F0: addiu       $t7, $t7, -0x3D80
    ctx->r15 = ADD32(ctx->r15, -0X3D80);
    // 0x800088F4: addiu       $t8, $t8, -0x3D78
    ctx->r24 = ADD32(ctx->r24, -0X3D78);
    // 0x800088F8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800088FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80008900: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x80008904: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x80008908: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000890C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80008910: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x80008914: sw          $t9, 0x5C4($at)
    MEM_W(0X5C4, ctx->r1) = ctx->r25;
    // 0x80008918: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000891C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80008920: b           L_80008934
    // 0x80008924: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_80008934;
    // 0x80008924: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80008928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8000892C:
    // 0x8000892C: jal         0x80008A00
    // 0x80008930: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    func_80008A00(rdram, ctx);
        goto after_8;
    // 0x80008930: lhu         $a1, 0x8($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X8);
    after_8:
L_80008934:
    // 0x80008934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80008938:
    // 0x80008938: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000893C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80008940: jr          $ra
    // 0x80008944: nop

    return;
    // 0x80008944: nop

;}
RECOMP_FUNC void func_80032704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032704: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x80032708: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003270C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80032710: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80032714: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80032718: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8003271C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80032720: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80032724: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80032728: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003272C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80032730: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80032734: lbu         $t6, 0x2A88($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2A88);
    // 0x80032738: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003273C: sw          $a0, 0x2D24($at)
    MEM_W(0X2D24, ctx->r1) = ctx->r4;
    // 0x80032740: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032744: bne         $t6, $zero, L_80032754
    if (ctx->r14 != 0) {
        // 0x80032748: sw          $a1, 0x2D28($at)
        MEM_W(0X2D28, ctx->r1) = ctx->r5;
            goto L_80032754;
    }
    // 0x80032748: sw          $a1, 0x2D28($at)
    MEM_W(0X2D28, ctx->r1) = ctx->r5;
    // 0x8003274C: b           L_80033820
    // 0x80032750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033820;
    // 0x80032750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032754:
    // 0x80032754: jal         0x8003AC10
    // 0x80032758: sw          $a0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r4;
    osContStartReadData_recomp(rdram, ctx);
        goto after_0;
    // 0x80032758: sw          $a0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003275C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80032760: addiu       $a1, $a1, 0x2D2C
    ctx->r5 = ADD32(ctx->r5, 0X2D2C);
    // 0x80032764: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x80032768: jal         0x80034020
    // 0x8003276C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8003276C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80032770: jal         0x8003AC9C
    // 0x80032774: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    osContGetReadData_recomp(rdram, ctx);
        goto after_2;
    // 0x80032774: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    after_2:
    // 0x80032778: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8003277C: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x80032780: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80032784: addiu       $fp, $sp, 0x7C
    ctx->r30 = ADD32(ctx->r29, 0X7C);
    // 0x80032788: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8003278C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80032790: lbu         $t8, 0x2A92($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2A92);
    // 0x80032794: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x80032798: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8003279C: bne         $t9, $zero, L_800327AC
    if (ctx->r25 != 0) {
        // 0x800327A0: nop
    
            goto L_800327AC;
    }
    // 0x800327A0: nop

    // 0x800327A4: b           L_80033820
    // 0x800327A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033820;
    // 0x800327A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800327AC:
    // 0x800327AC: jal         0x80039D90
    // 0x800327B0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_3;
    // 0x800327B0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_3:
    // 0x800327B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800327B8: bne         $v0, $at, L_800327DC
    if (ctx->r2 != ctx->r1) {
        // 0x800327BC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800327DC;
    }
    // 0x800327BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800327C0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x800327C4: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x800327C8: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x800327CC: jal         0x8003A4BC
    // 0x800327D0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x800327D0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_4:
    // 0x800327D4: b           L_800327E0
    // 0x800327D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800327E0;
    // 0x800327D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800327DC:
    // 0x800327DC: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_800327E0:
    // 0x800327E0: beq         $s0, $zero, L_800327F8
    if (ctx->r16 == 0) {
        // 0x800327E4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800327F8;
    }
    // 0x800327E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800327E8: beq         $s0, $at, L_800327F8
    if (ctx->r16 == ctx->r1) {
        // 0x800327EC: nop
    
            goto L_800327F8;
    }
    // 0x800327EC: nop

    // 0x800327F0: b           L_80033820
    // 0x800327F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033820;
    // 0x800327F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800327F8:
    // 0x800327F8: bne         $v1, $zero, L_80032808
    if (ctx->r3 != 0) {
        // 0x800327FC: lui         $t3, 0x8009
        ctx->r11 = S32(0X8009 << 16);
            goto L_80032808;
    }
    // 0x800327FC: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80032800: b           L_80033820
    // 0x80032804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033820;
    // 0x80032804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032808:
    // 0x80032808: bne         $s0, $zero, L_80032820
    if (ctx->r16 != 0) {
        // 0x8003280C: lui         $s6, 0x8009
        ctx->r22 = S32(0X8009 << 16);
            goto L_80032820;
    }
    // 0x8003280C: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80032810: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80032814: addiu       $s6, $s6, 0x2D08
    ctx->r22 = ADD32(ctx->r22, 0X2D08);
    // 0x80032818: b           L_8003282C
    // 0x8003281C: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
        goto L_8003282C;
    // 0x8003281C: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
L_80032820:
    // 0x80032820: addiu       $s6, $s6, 0x2D08
    ctx->r22 = ADD32(ctx->r22, 0X2D08);
    // 0x80032824: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80032828: sh          $t2, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r10;
L_8003282C:
    // 0x8003282C: lb          $t3, 0x2870($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X2870);
    // 0x80032830: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80032834: ori         $v1, $v1, 0xB000
    ctx->r3 = ctx->r3 | 0XB000;
    // 0x80032838: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003283C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80032840: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80032844: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x80032848: lhu         $t5, 0xF8($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0XF8);
    // 0x8003284C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80032850: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x80032854: bne         $t6, $zero, L_80032874
    if (ctx->r14 != 0) {
        // 0x80032858: nop
    
            goto L_80032874;
    }
    // 0x80032858: nop

    // 0x8003285C: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x80032860: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80032864: beq         $t7, $at, L_80032874
    if (ctx->r15 == ctx->r1) {
        // 0x80032868: nop
    
            goto L_80032874;
    }
    // 0x80032868: nop

    // 0x8003286C: b           L_80033820
    // 0x80032870: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80033820;
    // 0x80032870: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80032874:
    // 0x80032874: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80032878: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8003287C: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x80032880: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80032884: bne         $v0, $v1, L_80032874
    if (ctx->r2 != ctx->r3) {
        // 0x80032888: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_80032874;
    }
    // 0x80032888: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8003288C: jal         0x800346E0
    // 0x80032890: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_5;
    // 0x80032890: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80032894: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80032898: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003289C: jal         0x8003228C
    // 0x800328A0: sw          $s7, 0x2D1C($at)
    MEM_W(0X2D1C, ctx->r1) = ctx->r23;
    func_8003228C(rdram, ctx);
        goto after_6;
    // 0x800328A0: sw          $s7, 0x2D1C($at)
    MEM_W(0X2D1C, ctx->r1) = ctx->r23;
    after_6:
    // 0x800328A4: addiu       $t8, $zero, 0x5B
    ctx->r24 = ADD32(0, 0X5B);
    // 0x800328A8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800328AC: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x800328B0: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x800328B4: sw          $t8, 0x2CC0($at)
    MEM_W(0X2CC0, ctx->r1) = ctx->r24;
    // 0x800328B8: sh          $zero, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = 0;
    // 0x800328BC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800328C0: addiu       $a3, $zero, 0x400
    ctx->r7 = ADD32(0, 0X400);
    // 0x800328C4: sh          $zero, 0xEA($sp)
    MEM_H(0XEA, ctx->r29) = 0;
    // 0x800328C8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800328CC: addiu       $s4, $s4, 0x2D14
    ctx->r20 = ADD32(ctx->r20, 0X2D14);
    // 0x800328D0: addiu       $s5, $s5, 0x2D10
    ctx->r21 = ADD32(ctx->r21, 0X2D10);
    // 0x800328D4: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800328D8:
    // 0x800328D8: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x800328DC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800328E0: lbu         $v1, 0x2D0E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2D0E);
    // 0x800328E4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800328E8: lh          $v0, 0x2D0A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2D0A);
    // 0x800328EC: sltiu       $at, $a1, 0xB
    ctx->r1 = ctx->r5 < 0XB ? 1 : 0;
    // 0x800328F0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800328F4: beq         $at, $zero, L_80033650
    if (ctx->r1 == 0) {
        // 0x800328F8: addu        $s1, $v0, $v1
        ctx->r17 = ADD32(ctx->r2, ctx->r3);
            goto L_80033650;
    }
    // 0x800328F8: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x800328FC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80032900: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80032904: addu        $at, $at, $t9
    gpr jr_addend_8003290C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80032908: lw          $t9, 0x1A80($at)
    ctx->r25 = ADD32(ctx->r1, 0X1A80);
    // 0x8003290C: jr          $t9
    // 0x80032910: nop

    switch (jr_addend_8003290C >> 2) {
        case 0: goto L_80032914; break;
        case 1: goto L_80032A8C; break;
        case 2: goto L_80032B88; break;
        case 3: goto L_80032D20; break;
        case 4: goto L_80032EB4; break;
        case 5: goto L_80032FA4; break;
        case 6: goto L_800330E0; break;
        case 7: goto L_800331B8; break;
        case 8: goto L_80033210; break;
        case 9: goto L_800333D8; break;
        case 10: goto L_80033514; break;
        default: switch_error(__func__, 0x8003290C, 0x80071A80);
    }
    // 0x80032910: nop

L_80032914:
    // 0x80032914: bne         $s3, $zero, L_800329E8
    if (ctx->r19 != 0) {
        // 0x80032918: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_800329E8;
    }
    // 0x80032918: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8003291C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80032920: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80032924: jal         0x8003C790
    // 0x80032928: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_7;
    // 0x80032928: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_7:
    // 0x8003292C: bne         $v0, $zero, L_8003297C
    if (ctx->r2 != 0) {
        // 0x80032930: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8003297C;
    }
    // 0x80032930: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80032934: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80032938: addiu       $s0, $s0, 0x2CC8
    ctx->r16 = ADD32(ctx->r16, 0X2CC8);
L_8003293C:
    // 0x8003293C: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80032940: addiu       $t3, $t3, 0x2AC0
    ctx->r11 = ADD32(ctx->r11, 0X2AC0);
    // 0x80032944: sll         $t2, $s1, 5
    ctx->r10 = S32(ctx->r17 << 5);
    // 0x80032948: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8003294C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80032950: jal         0x8003AE30
    // 0x80032954: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    osPfsFileState_recomp(rdram, ctx);
        goto after_8;
    // 0x80032954: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80032958: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003295C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80032960: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80032964: bne         $s1, $at, L_8003293C
    if (ctx->r17 != ctx->r1) {
        // 0x80032968: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8003293C;
    }
    // 0x80032968: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x8003296C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80032970: addiu       $a1, $a1, 0x2D18
    ctx->r5 = ADD32(ctx->r5, 0X2D18);
    // 0x80032974: jal         0x8003B120
    // 0x80032978: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_9;
    // 0x80032978: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_9:
L_8003297C:
    // 0x8003297C: beq         $v0, $zero, L_800329A4
    if (ctx->r2 == 0) {
        // 0x80032980: nop
    
            goto L_800329A4;
    }
    // 0x80032980: nop

    // 0x80032984: beq         $v0, $s7, L_800329C4
    if (ctx->r2 == ctx->r23) {
        // 0x80032988: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800329C4;
    }
    // 0x80032988: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003298C: beq         $v0, $at, L_800329D0
    if (ctx->r2 == ctx->r1) {
        // 0x80032990: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800329D0;
    }
    // 0x80032990: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80032994: beq         $v0, $at, L_800329D8
    if (ctx->r2 == ctx->r1) {
        // 0x80032998: addiu       $t7, $zero, 0x5
        ctx->r15 = ADD32(0, 0X5);
            goto L_800329D8;
    }
    // 0x80032998: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8003299C: b           L_80033820
    // 0x800329A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033820;
    // 0x800329A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800329A4:
    // 0x800329A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800329A8: addiu       $v0, $v0, 0x2D18
    ctx->r2 = ADD32(ctx->r2, 0X2D18);
    // 0x800329AC: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800329B0: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x800329B4: sh          $s7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r23;
    // 0x800329B8: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800329BC: b           L_800329E8
    // 0x800329C0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_800329E8;
    // 0x800329C0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800329C4:
    // 0x800329C4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800329C8: b           L_800329E8
    // 0x800329CC: sh          $t6, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r14;
        goto L_800329E8;
    // 0x800329CC: sh          $t6, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r14;
L_800329D0:
    // 0x800329D0: b           L_800329E8
    // 0x800329D4: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
        goto L_800329E8;
    // 0x800329D4: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
L_800329D8:
    // 0x800329D8: b           L_800329E8
    // 0x800329DC: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
        goto L_800329E8;
    // 0x800329DC: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x800329E0: b           L_80033820
    // 0x800329E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033820;
    // 0x800329E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800329E8:
    // 0x800329E8: beq         $s3, $zero, L_80032A50
    if (ctx->r19 == 0) {
        // 0x800329EC: lw          $a0, 0x110($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X110);
            goto L_80032A50;
    }
    // 0x800329EC: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x800329F0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x800329F4: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x800329F8: jal         0x80039D90
    // 0x800329FC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_10;
    // 0x800329FC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_10:
    // 0x80032A00: bne         $v0, $zero, L_80032A10
    if (ctx->r2 != 0) {
        // 0x80032A04: nop
    
            goto L_80032A10;
    }
    // 0x80032A04: nop

    // 0x80032A08: b           L_80032A50
    // 0x80032A0C: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
        goto L_80032A50;
    // 0x80032A0C: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
L_80032A10:
    // 0x80032A10: bne         $v0, $s7, L_80032A24
    if (ctx->r2 != ctx->r23) {
        // 0x80032A14: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80032A24;
    }
    // 0x80032A14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80032A18: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80032A1C: b           L_80032A50
    // 0x80032A20: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
        goto L_80032A50;
    // 0x80032A20: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
L_80032A24:
    // 0x80032A24: bnel        $v0, $at, L_80032A38
    if (ctx->r2 != ctx->r1) {
        // 0x80032A28: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80032A38;
    }
    goto skip_0;
    // 0x80032A28: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_0:
    // 0x80032A2C: b           L_80032A50
    // 0x80032A30: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
        goto L_80032A50;
    // 0x80032A30: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
    // 0x80032A34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80032A38:
    // 0x80032A38: bne         $v0, $at, L_80032A48
    if (ctx->r2 != ctx->r1) {
        // 0x80032A3C: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80032A48;
    }
    // 0x80032A3C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80032A40: b           L_80032A50
    // 0x80032A44: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
        goto L_80032A50;
    // 0x80032A44: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
L_80032A48:
    // 0x80032A48: b           L_80033820
    // 0x80032A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033820;
    // 0x80032A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032A50:
    // 0x80032A50: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032A54: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80032A58: sb          $zero, 0x2D0E($at)
    MEM_B(0X2D0E, ctx->r1) = 0;
    // 0x80032A5C: addiu       $v0, $v0, 0x2D0F
    ctx->r2 = ADD32(ctx->r2, 0X2D0F);
    // 0x80032A60: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80032A64: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032A68: andi        $t2, $zero, 0xFF
    ctx->r10 = 0 & 0XFF;
    // 0x80032A6C: sh          $t2, 0x2D0A($at)
    MEM_H(0X2D0A, ctx->r1) = ctx->r10;
    // 0x80032A70: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80032A74: lh          $t3, 0x2D0A($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X2D0A);
    // 0x80032A78: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032A7C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80032A80: sh          $t3, 0x2D0C($at)
    MEM_H(0X2D0C, ctx->r1) = ctx->r11;
    // 0x80032A84: b           L_80033650
    // 0x80032A88: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032A88: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80032A8C:
    // 0x80032A8C: bnel        $s3, $zero, L_80032AEC
    if (ctx->r19 != 0) {
        // 0x80032A90: lh          $v0, 0x0($s4)
        ctx->r2 = MEM_H(ctx->r20, 0X0);
            goto L_80032AEC;
    }
    goto skip_1;
    // 0x80032A90: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    skip_1:
    // 0x80032A94: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80032A98: addiu       $t4, $zero, 0x36
    ctx->r12 = ADD32(0, 0X36);
    // 0x80032A9C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032AA0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80032AA4: bne         $v1, $zero, L_80032AB0
    if (ctx->r3 != 0) {
        // 0x80032AA8: sh          $t4, 0x2D12($at)
        MEM_H(0X2D12, ctx->r1) = ctx->r12;
            goto L_80032AB0;
    }
    // 0x80032AA8: sh          $t4, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r12;
    // 0x80032AAC: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
L_80032AB0:
    // 0x80032AB0: lh          $t5, 0x0($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X0);
    // 0x80032AB4: addiu       $t6, $zero, 0xB9
    ctx->r14 = ADD32(0, 0XB9);
    // 0x80032AB8: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80032ABC: beql        $t5, $zero, L_80032AD0
    if (ctx->r13 == 0) {
        // 0x80032AC0: sh          $t7, 0x0($s5)
        MEM_H(0X0, ctx->r21) = ctx->r15;
            goto L_80032AD0;
    }
    goto skip_2;
    // 0x80032AC0: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
    skip_2:
    // 0x80032AC4: b           L_80032AD0
    // 0x80032AC8: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
        goto L_80032AD0;
    // 0x80032AC8: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
    // 0x80032ACC: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
L_80032AD0:
    // 0x80032AD0: jal         0x8003265C
    // 0x80032AD4: nop

    func_8003265C(rdram, ctx);
        goto after_11;
    // 0x80032AD4: nop

    after_11:
    // 0x80032AD8: jal         0x800325A8
    // 0x80032ADC: nop

    func_800325A8(rdram, ctx);
        goto after_12;
    // 0x80032ADC: nop

    after_12:
    // 0x80032AE0: b           L_80033650
    // 0x80032AE4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032AE4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80032AE8: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
L_80032AEC:
    // 0x80032AEC: andi        $t8, $a3, 0x8000
    ctx->r24 = ctx->r7 & 0X8000;
    // 0x80032AF0: andi        $t2, $a3, 0xC000
    ctx->r10 = ctx->r7 & 0XC000;
    // 0x80032AF4: bne         $v0, $zero, L_80032B14
    if (ctx->r2 != 0) {
        // 0x80032AF8: nop
    
            goto L_80032B14;
    }
    // 0x80032AF8: nop

    // 0x80032AFC: beq         $t8, $zero, L_80032B14
    if (ctx->r24 == 0) {
        // 0x80032B00: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80032B14;
    }
    // 0x80032B00: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80032B04: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x80032B08: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80032B0C: b           L_80033650
    // 0x80032B10: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80033650;
    // 0x80032B10: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80032B14:
    // 0x80032B14: beq         $t2, $zero, L_80032B24
    if (ctx->r10 == 0) {
        // 0x80032B18: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032B24;
    }
    // 0x80032B18: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032B1C: b           L_80033820
    // 0x80032B20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80033820;
    // 0x80032B20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80032B24:
    // 0x80032B24: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80032B28: beq         $v1, $zero, L_80033650
    if (ctx->r3 == 0) {
        // 0x80032B2C: andi        $v1, $a0, 0x2
        ctx->r3 = ctx->r4 & 0X2;
            goto L_80033650;
    }
    // 0x80032B2C: andi        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 & 0X2;
    // 0x80032B30: beq         $v1, $zero, L_80032B40
    if (ctx->r3 == 0) {
        // 0x80032B34: andi        $t3, $a0, 0x1
        ctx->r11 = ctx->r4 & 0X1;
            goto L_80032B40;
    }
    // 0x80032B34: andi        $t3, $a0, 0x1
    ctx->r11 = ctx->r4 & 0X1;
    // 0x80032B38: bne         $v0, $zero, L_80032B50
    if (ctx->r2 != 0) {
        // 0x80032B3C: nop
    
            goto L_80032B50;
    }
    // 0x80032B3C: nop

L_80032B40:
    // 0x80032B40: beq         $t3, $zero, L_80033650
    if (ctx->r11 == 0) {
        // 0x80032B44: nop
    
            goto L_80033650;
    }
    // 0x80032B44: nop

    // 0x80032B48: bne         $v0, $zero, L_80033650
    if (ctx->r2 != 0) {
        // 0x80032B4C: nop
    
            goto L_80033650;
    }
    // 0x80032B4C: nop

L_80032B50:
    // 0x80032B50: beq         $v1, $zero, L_80032B68
    if (ctx->r3 == 0) {
        // 0x80032B54: addiu       $t5, $zero, 0xB9
        ctx->r13 = ADD32(0, 0XB9);
            goto L_80032B68;
    }
    // 0x80032B54: addiu       $t5, $zero, 0xB9
    ctx->r13 = ADD32(0, 0XB9);
    // 0x80032B58: addiu       $t4, $zero, 0x46
    ctx->r12 = ADD32(0, 0X46);
    // 0x80032B5C: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x80032B60: b           L_80032B70
    // 0x80032B64: sh          $t4, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r12;
        goto L_80032B70;
    // 0x80032B64: sh          $t4, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r12;
L_80032B68:
    // 0x80032B68: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x80032B6C: sh          $t5, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r13;
L_80032B70:
    // 0x80032B70: jal         0x8003265C
    // 0x80032B74: nop

    func_8003265C(rdram, ctx);
        goto after_13;
    // 0x80032B74: nop

    after_13:
    // 0x80032B78: jal         0x800325A8
    // 0x80032B7C: nop

    func_800325A8(rdram, ctx);
        goto after_14;
    // 0x80032B7C: nop

    after_14:
    // 0x80032B80: b           L_80033650
    // 0x80032B84: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032B84: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80032B88:
    // 0x80032B88: bne         $s3, $zero, L_80032BCC
    if (ctx->r19 != 0) {
        // 0x80032B8C: andi        $t9, $a3, 0x4000
        ctx->r25 = ctx->r7 & 0X4000;
            goto L_80032BCC;
    }
    // 0x80032B8C: andi        $t9, $a3, 0x4000
    ctx->r25 = ctx->r7 & 0X4000;
    // 0x80032B90: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80032B94: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80032B98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80032B9C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80032BA0: addiu       $t6, $zero, 0x26
    ctx->r14 = ADD32(0, 0X26);
    // 0x80032BA4: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
    // 0x80032BA8: addiu       $t8, $t7, 0x58
    ctx->r24 = ADD32(ctx->r15, 0X58);
    // 0x80032BAC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032BB0: jal         0x8003265C
    // 0x80032BB4: sh          $t8, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r24;
    func_8003265C(rdram, ctx);
        goto after_15;
    // 0x80032BB4: sh          $t8, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r24;
    after_15:
    // 0x80032BB8: jal         0x800325A8
    // 0x80032BBC: nop

    func_800325A8(rdram, ctx);
        goto after_16;
    // 0x80032BBC: nop

    after_16:
    // 0x80032BC0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80032BC4: b           L_80033650
    // 0x80032BC8: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032BC8: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80032BCC:
    // 0x80032BCC: beq         $t9, $zero, L_80032BE8
    if (ctx->r25 == 0) {
        // 0x80032BD0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032BE8;
    }
    // 0x80032BD0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032BD4: sh          $s7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r23;
    // 0x80032BD8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80032BDC: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80032BE0: b           L_80033650
    // 0x80032BE4: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
        goto L_80033650;
    // 0x80032BE4: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
L_80032BE8:
    // 0x80032BE8: andi        $t2, $a0, 0x8000
    ctx->r10 = ctx->r4 & 0X8000;
    // 0x80032BEC: beq         $t2, $zero, L_80032C24
    if (ctx->r10 == 0) {
        // 0x80032BF0: andi        $t6, $t1, 0x4
        ctx->r14 = ctx->r9 & 0X4;
            goto L_80032C24;
    }
    // 0x80032BF0: andi        $t6, $t1, 0x4
    ctx->r14 = ctx->r9 & 0X4;
    // 0x80032BF4: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80032BF8: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x80032BFC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80032C00: lw          $t4, 0x2CC8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2CC8);
    // 0x80032C04: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80032C08: bne         $t4, $zero, L_80033650
    if (ctx->r12 != 0) {
        // 0x80032C0C: nop
    
            goto L_80033650;
    }
    // 0x80032C0C: nop

    // 0x80032C10: sh          $t5, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r13;
    // 0x80032C14: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80032C18: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80032C1C: b           L_80033650
    // 0x80032C20: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
        goto L_80033650;
    // 0x80032C20: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
L_80032C24:
    // 0x80032C24: beq         $t6, $zero, L_80032C78
    if (ctx->r14 == 0) {
        // 0x80032C28: or          $a0, $t1, $zero
        ctx->r4 = ctx->r9 | 0;
            goto L_80032C78;
    }
    // 0x80032C28: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80032C2C: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80032C30: bne         $at, $zero, L_80032C68
    if (ctx->r1 != 0) {
        // 0x80032C34: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_80032C68;
    }
    // 0x80032C34: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80032C38: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80032C3C: beq         $at, $zero, L_80032C58
    if (ctx->r1 == 0) {
        // 0x80032C40: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_80032C58;
    }
    // 0x80032C40: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80032C44: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80032C48: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032C4C: sb          $t7, 0x2D0E($at)
    MEM_B(0X2D0E, ctx->r1) = ctx->r15;
    // 0x80032C50: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80032C54: lbu         $v1, 0x2D0E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2D0E);
L_80032C58:
    // 0x80032C58: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032C5C: sh          $t8, 0x2D0A($at)
    MEM_H(0X2D0A, ctx->r1) = ctx->r24;
    // 0x80032C60: b           L_80032C78
    // 0x80032C64: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80032C78;
    // 0x80032C64: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80032C68:
    // 0x80032C68: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032C6C: sh          $t9, 0x2D0A($at)
    MEM_H(0X2D0A, ctx->r1) = ctx->r25;
    // 0x80032C70: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80032C74: lh          $v0, 0x2D0A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2D0A);
L_80032C78:
    // 0x80032C78: andi        $t2, $a0, 0x8
    ctx->r10 = ctx->r4 & 0X8;
    // 0x80032C7C: beq         $t2, $zero, L_80032CB8
    if (ctx->r10 == 0) {
        // 0x80032C80: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_80032CB8;
    }
    // 0x80032C80: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80032C84: bne         $v0, $zero, L_80032CA8
    if (ctx->r2 != 0) {
        // 0x80032C88: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80032CA8;
    }
    // 0x80032C88: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80032C8C: beq         $v1, $zero, L_80032CB8
    if (ctx->r3 == 0) {
        // 0x80032C90: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80032CB8;
    }
    // 0x80032C90: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80032C94: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032C98: sb          $t3, 0x2D0E($at)
    MEM_B(0X2D0E, ctx->r1) = ctx->r11;
    // 0x80032C9C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80032CA0: b           L_80032CB8
    // 0x80032CA4: lbu         $v1, 0x2D0E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2D0E);
        goto L_80032CB8;
    // 0x80032CA4: lbu         $v1, 0x2D0E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2D0E);
L_80032CA8:
    // 0x80032CA8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032CAC: sh          $t4, 0x2D0A($at)
    MEM_H(0X2D0A, ctx->r1) = ctx->r12;
    // 0x80032CB0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80032CB4: lh          $v0, 0x2D0A($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2D0A);
L_80032CB8:
    // 0x80032CB8: lh          $t5, 0x2D0C($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X2D0C);
    // 0x80032CBC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80032CC0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032CC4: bne         $t5, $v0, L_80032CD8
    if (ctx->r13 != ctx->r2) {
        // 0x80032CC8: nop
    
            goto L_80032CD8;
    }
    // 0x80032CC8: nop

    // 0x80032CCC: lbu         $t6, 0x2D0F($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2D0F);
    // 0x80032CD0: beq         $t6, $v1, L_80033650
    if (ctx->r14 == ctx->r3) {
        // 0x80032CD4: nop
    
            goto L_80033650;
    }
    // 0x80032CD4: nop

L_80032CD8:
    // 0x80032CD8: sh          $v0, 0x2D0C($at)
    MEM_H(0X2D0C, ctx->r1) = ctx->r2;
    // 0x80032CDC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032CE0: jal         0x8003265C
    // 0x80032CE4: sb          $v1, 0x2D0F($at)
    MEM_B(0X2D0F, ctx->r1) = ctx->r3;
    func_8003265C(rdram, ctx);
        goto after_17;
    // 0x80032CE4: sb          $v1, 0x2D0F($at)
    MEM_B(0X2D0F, ctx->r1) = ctx->r3;
    after_17:
    // 0x80032CE8: addiu       $t7, $zero, 0x26
    ctx->r15 = ADD32(0, 0X26);
    // 0x80032CEC: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
    // 0x80032CF0: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80032CF4: lh          $t8, 0x2D0A($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X2D0A);
    // 0x80032CF8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032CFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80032D00: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80032D04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80032D08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80032D0C: addiu       $t2, $t9, 0x58
    ctx->r10 = ADD32(ctx->r25, 0X58);
    // 0x80032D10: jal         0x800325A8
    // 0x80032D14: sh          $t2, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r10;
    func_800325A8(rdram, ctx);
        goto after_18;
    // 0x80032D14: sh          $t2, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r10;
    after_18:
    // 0x80032D18: b           L_80033650
    // 0x80032D1C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032D1C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80032D20:
    // 0x80032D20: bne         $s3, $zero, L_80032D70
    if (ctx->r19 != 0) {
        // 0x80032D24: addiu       $t3, $zero, 0xA0
        ctx->r11 = ADD32(0, 0XA0);
            goto L_80032D70;
    }
    // 0x80032D24: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80032D28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032D2C: sh          $t3, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r11;
    // 0x80032D30: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x80032D34: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80032D38: addiu       $t5, $zero, 0xA2
    ctx->r13 = ADD32(0, 0XA2);
    // 0x80032D3C: beq         $t4, $zero, L_80032D4C
    if (ctx->r12 == 0) {
        // 0x80032D40: addiu       $t6, $zero, 0x64
        ctx->r14 = ADD32(0, 0X64);
            goto L_80032D4C;
    }
    // 0x80032D40: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80032D44: b           L_80032D50
    // 0x80032D48: sh          $t5, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r13;
        goto L_80032D50;
    // 0x80032D48: sh          $t5, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r13;
L_80032D4C:
    // 0x80032D4C: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
L_80032D50:
    // 0x80032D50: jal         0x8003265C
    // 0x80032D54: sh          $a3, 0xF2($sp)
    MEM_H(0XF2, ctx->r29) = ctx->r7;
    func_8003265C(rdram, ctx);
        goto after_19;
    // 0x80032D54: sh          $a3, 0xF2($sp)
    MEM_H(0XF2, ctx->r29) = ctx->r7;
    after_19:
    // 0x80032D58: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80032D5C: jal         0x800325FC
    // 0x80032D60: addiu       $a0, $a0, -0x1D58
    ctx->r4 = ADD32(ctx->r4, -0X1D58);
    func_800325FC(rdram, ctx);
        goto after_20;
    // 0x80032D60: addiu       $a0, $a0, -0x1D58
    ctx->r4 = ADD32(ctx->r4, -0X1D58);
    after_20:
    // 0x80032D64: jal         0x800325A8
    // 0x80032D68: nop

    func_800325A8(rdram, ctx);
        goto after_21;
    // 0x80032D68: nop

    after_21:
    // 0x80032D6C: lhu         $a3, 0xF2($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0XF2);
L_80032D70:
    // 0x80032D70: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x80032D74: andi        $t7, $a3, 0x8000
    ctx->r15 = ctx->r7 & 0X8000;
    // 0x80032D78: andi        $t5, $a3, 0xC000
    ctx->r13 = ctx->r7 & 0XC000;
    // 0x80032D7C: bne         $v0, $zero, L_80032E30
    if (ctx->r2 != 0) {
        // 0x80032D80: nop
    
            goto L_80032E30;
    }
    // 0x80032D80: nop

    // 0x80032D84: beq         $t7, $zero, L_80032E30
    if (ctx->r15 == 0) {
        // 0x80032D88: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_80032E30;
    }
    // 0x80032D88: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80032D8C: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80032D90: addiu       $t9, $t9, 0x2AC0
    ctx->r25 = ADD32(ctx->r25, 0X2AC0);
    // 0x80032D94: sll         $t8, $s1, 5
    ctx->r24 = S32(ctx->r17 << 5);
    // 0x80032D98: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80032D9C: addiu       $t2, $s0, 0xA
    ctx->r10 = ADD32(ctx->r16, 0XA);
    // 0x80032DA0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80032DA4: lhu         $a1, 0x8($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X8);
    // 0x80032DA8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80032DAC: addiu       $a3, $s0, 0xE
    ctx->r7 = ADD32(ctx->r16, 0XE);
    // 0x80032DB0: jal         0x8003BA20
    // 0x80032DB4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_22;
    // 0x80032DB4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_22:
    // 0x80032DB8: beq         $v0, $zero, L_80032DDC
    if (ctx->r2 == 0) {
        // 0x80032DBC: lw          $v1, 0x78($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X78);
            goto L_80032DDC;
    }
    // 0x80032DBC: lw          $v1, 0x78($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X78);
    // 0x80032DC0: bne         $v0, $s7, L_80032DD4
    if (ctx->r2 != ctx->r23) {
        // 0x80032DC4: addiu       $t4, $zero, 0x7
        ctx->r12 = ADD32(0, 0X7);
            goto L_80032DD4;
    }
    // 0x80032DC4: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80032DC8: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80032DCC: b           L_80032EAC
    // 0x80032DD0: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
        goto L_80032EAC;
    // 0x80032DD0: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
L_80032DD4:
    // 0x80032DD4: b           L_80032EAC
    // 0x80032DD8: sh          $t4, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r12;
        goto L_80032EAC;
    // 0x80032DD8: sh          $t4, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r12;
L_80032DDC:
    // 0x80032DDC: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80032DE0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032DE4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80032DE8: sw          $s2, 0x2CC8($at)
    MEM_W(0X2CC8, ctx->r1) = ctx->r18;
    // 0x80032DEC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80032DF0: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80032DF4: lw          $t6, 0x2D18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2D18);
    // 0x80032DF8: addiu       $t8, $t7, 0xFF
    ctx->r24 = ADD32(ctx->r15, 0XFF);
    // 0x80032DFC: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x80032E00: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80032E04: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032E08: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80032E0C: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x80032E10: sw          $t3, 0x2D18($at)
    MEM_W(0X2D18, ctx->r1) = ctx->r11;
    // 0x80032E14: beq         $v1, $zero, L_80032E28
    if (ctx->r3 == 0) {
        // 0x80032E18: sw          $v1, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r3;
            goto L_80032E28;
    }
    // 0x80032E18: sw          $v1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r3;
    // 0x80032E1C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80032E20: b           L_80032EAC
    // 0x80032E24: sh          $t4, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r12;
        goto L_80032EAC;
    // 0x80032E24: sh          $t4, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r12;
L_80032E28:
    // 0x80032E28: b           L_80032EAC
    // 0x80032E2C: sh          $s7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r23;
        goto L_80032EAC;
    // 0x80032E2C: sh          $s7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r23;
L_80032E30:
    // 0x80032E30: beq         $t5, $zero, L_80032E4C
    if (ctx->r13 == 0) {
        // 0x80032E34: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032E4C;
    }
    // 0x80032E34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032E38: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80032E3C: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x80032E40: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80032E44: b           L_80032EAC
    // 0x80032E48: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
        goto L_80032EAC;
    // 0x80032E48: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
L_80032E4C:
    // 0x80032E4C: andi        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 & 0X2;
    // 0x80032E50: beq         $v1, $zero, L_80032E60
    if (ctx->r3 == 0) {
        // 0x80032E54: andi        $t8, $a0, 0x1
        ctx->r24 = ctx->r4 & 0X1;
            goto L_80032E60;
    }
    // 0x80032E54: andi        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 & 0X1;
    // 0x80032E58: bne         $v0, $zero, L_80032E70
    if (ctx->r2 != 0) {
        // 0x80032E5C: nop
    
            goto L_80032E70;
    }
    // 0x80032E5C: nop

L_80032E60:
    // 0x80032E60: beq         $t8, $zero, L_80032EAC
    if (ctx->r24 == 0) {
        // 0x80032E64: nop
    
            goto L_80032EAC;
    }
    // 0x80032E64: nop

    // 0x80032E68: bne         $v0, $zero, L_80032EAC
    if (ctx->r2 != 0) {
        // 0x80032E6C: nop
    
            goto L_80032EAC;
    }
    // 0x80032E6C: nop

L_80032E70:
    // 0x80032E70: beq         $v1, $zero, L_80032E88
    if (ctx->r3 == 0) {
        // 0x80032E74: addiu       $t6, $zero, 0xA2
        ctx->r14 = ADD32(0, 0XA2);
            goto L_80032E88;
    }
    // 0x80032E74: addiu       $t6, $zero, 0xA2
    ctx->r14 = ADD32(0, 0XA2);
    // 0x80032E78: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80032E7C: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x80032E80: b           L_80032E90
    // 0x80032E84: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
        goto L_80032E90;
    // 0x80032E84: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
L_80032E88:
    // 0x80032E88: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x80032E8C: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
L_80032E90:
    // 0x80032E90: jal         0x8003265C
    // 0x80032E94: nop

    func_8003265C(rdram, ctx);
        goto after_23;
    // 0x80032E94: nop

    after_23:
    // 0x80032E98: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80032E9C: jal         0x800325FC
    // 0x80032EA0: addiu       $a0, $a0, -0x1D58
    ctx->r4 = ADD32(ctx->r4, -0X1D58);
    func_800325FC(rdram, ctx);
        goto after_24;
    // 0x80032EA0: addiu       $a0, $a0, -0x1D58
    ctx->r4 = ADD32(ctx->r4, -0X1D58);
    after_24:
    // 0x80032EA4: jal         0x800325A8
    // 0x80032EA8: nop

    func_800325A8(rdram, ctx);
        goto after_25;
    // 0x80032EA8: nop

    after_25:
L_80032EAC:
    // 0x80032EAC: b           L_80033650
    // 0x80032EB0: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032EB0: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80032EB4:
    // 0x80032EB4: bne         $s3, $zero, L_80032EFC
    if (ctx->r19 != 0) {
        // 0x80032EB8: addiu       $t2, $zero, 0xC1
        ctx->r10 = ADD32(0, 0XC1);
            goto L_80032EFC;
    }
    // 0x80032EB8: addiu       $t2, $zero, 0xC1
    ctx->r10 = ADD32(0, 0XC1);
    // 0x80032EBC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032EC0: sh          $t2, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r10;
    // 0x80032EC4: lh          $t3, 0x0($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X0);
    // 0x80032EC8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80032ECC: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80032ED0: beq         $t3, $zero, L_80032EE0
    if (ctx->r11 == 0) {
        // 0x80032ED4: addiu       $t5, $zero, 0x52
        ctx->r13 = ADD32(0, 0X52);
            goto L_80032EE0;
    }
    // 0x80032ED4: addiu       $t5, $zero, 0x52
    ctx->r13 = ADD32(0, 0X52);
    // 0x80032ED8: b           L_80032EE4
    // 0x80032EDC: sh          $t4, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r12;
        goto L_80032EE4;
    // 0x80032EDC: sh          $t4, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r12;
L_80032EE0:
    // 0x80032EE0: sh          $t5, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r13;
L_80032EE4:
    // 0x80032EE4: jal         0x8003265C
    // 0x80032EE8: nop

    func_8003265C(rdram, ctx);
        goto after_26;
    // 0x80032EE8: nop

    after_26:
    // 0x80032EEC: jal         0x800325A8
    // 0x80032EF0: nop

    func_800325A8(rdram, ctx);
        goto after_27;
    // 0x80032EF0: nop

    after_27:
    // 0x80032EF4: b           L_80033650
    // 0x80032EF8: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032EF8: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80032EFC:
    // 0x80032EFC: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x80032F00: andi        $t7, $a3, 0x8000
    ctx->r15 = ctx->r7 & 0X8000;
    // 0x80032F04: andi        $t9, $a3, 0xC000
    ctx->r25 = ctx->r7 & 0XC000;
    // 0x80032F08: bne         $v0, $zero, L_80032F2C
    if (ctx->r2 != 0) {
        // 0x80032F0C: nop
    
            goto L_80032F2C;
    }
    // 0x80032F0C: nop

    // 0x80032F10: beq         $t7, $zero, L_80032F2C
    if (ctx->r15 == 0) {
        // 0x80032F14: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80032F2C;
    }
    // 0x80032F14: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80032F18: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    // 0x80032F1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80032F20: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80032F24: b           L_80033650
    // 0x80032F28: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
        goto L_80033650;
    // 0x80032F28: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
L_80032F2C:
    // 0x80032F2C: beq         $t9, $zero, L_80032F48
    if (ctx->r25 == 0) {
        // 0x80032F30: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80032F48;
    }
    // 0x80032F30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80032F34: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80032F38: sh          $t6, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r14;
    // 0x80032F3C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80032F40: b           L_80033650
    // 0x80032F44: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80033650;
    // 0x80032F44: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80032F48:
    // 0x80032F48: andi        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 & 0X2;
    // 0x80032F4C: beq         $v1, $zero, L_80032F5C
    if (ctx->r3 == 0) {
        // 0x80032F50: andi        $t2, $a0, 0x1
        ctx->r10 = ctx->r4 & 0X1;
            goto L_80032F5C;
    }
    // 0x80032F50: andi        $t2, $a0, 0x1
    ctx->r10 = ctx->r4 & 0X1;
    // 0x80032F54: bne         $v0, $zero, L_80032F6C
    if (ctx->r2 != 0) {
        // 0x80032F58: nop
    
            goto L_80032F6C;
    }
    // 0x80032F58: nop

L_80032F5C:
    // 0x80032F5C: beq         $t2, $zero, L_80033650
    if (ctx->r10 == 0) {
        // 0x80032F60: nop
    
            goto L_80033650;
    }
    // 0x80032F60: nop

    // 0x80032F64: bne         $v0, $zero, L_80033650
    if (ctx->r2 != 0) {
        // 0x80032F68: nop
    
            goto L_80033650;
    }
    // 0x80032F68: nop

L_80032F6C:
    // 0x80032F6C: beq         $v1, $zero, L_80032F84
    if (ctx->r3 == 0) {
        // 0x80032F70: addiu       $t4, $zero, 0xA0
        ctx->r12 = ADD32(0, 0XA0);
            goto L_80032F84;
    }
    // 0x80032F70: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x80032F74: addiu       $t3, $zero, 0x52
    ctx->r11 = ADD32(0, 0X52);
    // 0x80032F78: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x80032F7C: b           L_80032F8C
    // 0x80032F80: sh          $t3, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r11;
        goto L_80032F8C;
    // 0x80032F80: sh          $t3, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r11;
L_80032F84:
    // 0x80032F84: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x80032F88: sh          $t4, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r12;
L_80032F8C:
    // 0x80032F8C: jal         0x8003265C
    // 0x80032F90: nop

    func_8003265C(rdram, ctx);
        goto after_28;
    // 0x80032F90: nop

    after_28:
    // 0x80032F94: jal         0x800325A8
    // 0x80032F98: nop

    func_800325A8(rdram, ctx);
        goto after_29;
    // 0x80032F98: nop

    after_29:
    // 0x80032F9C: b           L_80033650
    // 0x80032FA0: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80032FA0: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80032FA4:
    // 0x80032FA4: bne         $s3, $zero, L_80033030
    if (ctx->r19 != 0) {
        // 0x80032FA8: andi        $t6, $a3, 0x8000
        ctx->r14 = ctx->r7 & 0X8000;
            goto L_80033030;
    }
    // 0x80032FA8: andi        $t6, $a3, 0x8000
    ctx->r14 = ctx->r7 & 0X8000;
    // 0x80032FAC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80032FB0: addiu       $v0, $v0, 0x2D18
    ctx->r2 = ADD32(ctx->r2, 0X2D18);
    // 0x80032FB4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80032FB8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80032FBC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80032FC0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80032FC4: addiu       $s0, $s0, 0x2CC8
    ctx->r16 = ADD32(ctx->r16, 0X2CC8);
    // 0x80032FC8: addiu       $v0, $v0, 0x2D08
    ctx->r2 = ADD32(ctx->r2, 0X2D08);
    // 0x80032FCC: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_80032FD0:
    // 0x80032FD0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80032FD4: sw          $s2, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r18;
    // 0x80032FD8: sw          $s2, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r18;
    // 0x80032FDC: sw          $s2, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r18;
    // 0x80032FE0: bne         $s0, $v0, L_80032FD0
    if (ctx->r16 != ctx->r2) {
        // 0x80032FE4: sw          $s2, -0x10($s0)
        MEM_W(-0X10, ctx->r16) = ctx->r18;
            goto L_80032FD0;
    }
    // 0x80032FE4: sw          $s2, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->r18;
    // 0x80032FE8: lh          $t5, 0x0($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X0);
    // 0x80032FEC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80032FF0: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80032FF4: beq         $t5, $zero, L_80033008
    if (ctx->r13 == 0) {
        // 0x80032FF8: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80033008;
    }
    // 0x80032FF8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032FFC: addiu       $t7, $zero, 0xA2
    ctx->r15 = ADD32(0, 0XA2);
    // 0x80033000: b           L_8003300C
    // 0x80033004: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
        goto L_8003300C;
    // 0x80033004: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
L_80033008:
    // 0x80033008: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
L_8003300C:
    // 0x8003300C: jal         0x8003265C
    // 0x80033010: sh          $t9, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r25;
    func_8003265C(rdram, ctx);
        goto after_30;
    // 0x80033010: sh          $t9, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r25;
    after_30:
    // 0x80033014: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80033018: jal         0x800325FC
    // 0x8003301C: addiu       $a0, $a0, -0x1C94
    ctx->r4 = ADD32(ctx->r4, -0X1C94);
    func_800325FC(rdram, ctx);
        goto after_31;
    // 0x8003301C: addiu       $a0, $a0, -0x1C94
    ctx->r4 = ADD32(ctx->r4, -0X1C94);
    after_31:
    // 0x80033020: jal         0x800325A8
    // 0x80033024: nop

    func_800325A8(rdram, ctx);
        goto after_32;
    // 0x80033024: nop

    after_32:
    // 0x80033028: b           L_80033650
    // 0x8003302C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x8003302C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80033030:
    // 0x80033030: beq         $t6, $zero, L_80033070
    if (ctx->r14 == 0) {
        // 0x80033034: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80033070;
    }
    // 0x80033034: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80033038: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x8003303C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80033040: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x80033044: bnel        $t2, $zero, L_80033064
    if (ctx->r10 != 0) {
        // 0x80033048: sh          $t4, 0x0($s6)
        MEM_H(0X0, ctx->r22) = ctx->r12;
            goto L_80033064;
    }
    goto skip_3;
    // 0x80033048: sh          $t4, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r12;
    skip_3:
    // 0x8003304C: jal         0x8003C530
    // 0x80033050: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_8003C530(rdram, ctx);
        goto after_33;
    // 0x80033050: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_33:
    // 0x80033054: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80033058: b           L_80033068
    // 0x8003305C: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
        goto L_80033068;
    // 0x8003305C: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
    // 0x80033060: sh          $t4, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r12;
L_80033064:
    // 0x80033064: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
L_80033068:
    // 0x80033068: b           L_80033650
    // 0x8003306C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x8003306C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80033070:
    // 0x80033070: andi        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 & 0X2;
    // 0x80033074: beq         $v1, $zero, L_80033088
    if (ctx->r3 == 0) {
        // 0x80033078: andi        $t7, $a0, 0x1
        ctx->r15 = ctx->r4 & 0X1;
            goto L_80033088;
    }
    // 0x80033078: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x8003307C: lh          $t5, 0x0($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X0);
    // 0x80033080: bne         $t5, $zero, L_8003309C
    if (ctx->r13 != 0) {
        // 0x80033084: nop
    
            goto L_8003309C;
    }
    // 0x80033084: nop

L_80033088:
    // 0x80033088: beq         $t7, $zero, L_80033650
    if (ctx->r15 == 0) {
        // 0x8003308C: nop
    
            goto L_80033650;
    }
    // 0x8003308C: nop

    // 0x80033090: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x80033094: bne         $t8, $zero, L_80033650
    if (ctx->r24 != 0) {
        // 0x80033098: nop
    
            goto L_80033650;
    }
    // 0x80033098: nop

L_8003309C:
    // 0x8003309C: beq         $v1, $zero, L_800330B4
    if (ctx->r3 == 0) {
        // 0x800330A0: addiu       $t6, $zero, 0xA0
        ctx->r14 = ADD32(0, 0XA0);
            goto L_800330B4;
    }
    // 0x800330A0: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x800330A4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x800330A8: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x800330AC: b           L_800330BC
    // 0x800330B0: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
        goto L_800330BC;
    // 0x800330B0: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
L_800330B4:
    // 0x800330B4: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x800330B8: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
L_800330BC:
    // 0x800330BC: jal         0x8003265C
    // 0x800330C0: nop

    func_8003265C(rdram, ctx);
        goto after_34;
    // 0x800330C0: nop

    after_34:
    // 0x800330C4: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800330C8: jal         0x800325FC
    // 0x800330CC: addiu       $a0, $a0, -0x1C94
    ctx->r4 = ADD32(ctx->r4, -0X1C94);
    func_800325FC(rdram, ctx);
        goto after_35;
    // 0x800330CC: addiu       $a0, $a0, -0x1C94
    ctx->r4 = ADD32(ctx->r4, -0X1C94);
    after_35:
    // 0x800330D0: jal         0x800325A8
    // 0x800330D4: nop

    func_800325A8(rdram, ctx);
        goto after_36;
    // 0x800330D4: nop

    after_36:
    // 0x800330D8: b           L_80033650
    // 0x800330DC: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x800330DC: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_800330E0:
    // 0x800330E0: bne         $s3, $zero, L_800330F8
    if (ctx->r19 != 0) {
        // 0x800330E4: lw          $t2, 0xE4($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XE4);
            goto L_800330F8;
    }
    // 0x800330E4: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x800330E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800330EC: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
    // 0x800330F0: b           L_800331B0
    // 0x800330F4: sh          $zero, 0xEA($sp)
    MEM_H(0XEA, ctx->r29) = 0;
        goto L_800331B0;
    // 0x800330F4: sh          $zero, 0xEA($sp)
    MEM_H(0XEA, ctx->r29) = 0;
L_800330F8:
    // 0x800330F8: lhu         $t4, 0xEA($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XEA);
    // 0x800330FC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80033100: sw          $t3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r11;
    // 0x80033104: bne         $t4, $zero, L_8003315C
    if (ctx->r12 != 0) {
        // 0x80033108: addiu       $t9, $zero, 0xA0
        ctx->r25 = ADD32(0, 0XA0);
            goto L_8003315C;
    }
    // 0x80033108: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x8003310C: lh          $t5, 0x0($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X0);
    // 0x80033110: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80033114: addiu       $t7, $zero, 0xA2
    ctx->r15 = ADD32(0, 0XA2);
    // 0x80033118: beq         $t5, $zero, L_80033128
    if (ctx->r13 == 0) {
        // 0x8003311C: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80033128;
    }
    // 0x8003311C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80033120: b           L_8003312C
    // 0x80033124: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
        goto L_8003312C;
    // 0x80033124: sh          $t7, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r15;
L_80033128:
    // 0x80033128: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
L_8003312C:
    // 0x8003312C: jal         0x8003265C
    // 0x80033130: sh          $t9, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r25;
    func_8003265C(rdram, ctx);
        goto after_37;
    // 0x80033130: sh          $t9, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r25;
    after_37:
    // 0x80033134: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80033138: jal         0x800325FC
    // 0x8003313C: addiu       $a0, $a0, -0x1C94
    ctx->r4 = ADD32(ctx->r4, -0X1C94);
    func_800325FC(rdram, ctx);
        goto after_38;
    // 0x8003313C: addiu       $a0, $a0, -0x1C94
    ctx->r4 = ADD32(ctx->r4, -0X1C94);
    after_38:
    // 0x80033140: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80033144: lw          $t6, -0x1B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1B4C);
    // 0x80033148: andi        $t2, $t6, 0x1
    ctx->r10 = ctx->r14 & 0X1;
    // 0x8003314C: beq         $t2, $zero, L_8003315C
    if (ctx->r10 == 0) {
        // 0x80033150: nop
    
            goto L_8003315C;
    }
    // 0x80033150: nop

    // 0x80033154: jal         0x800325A8
    // 0x80033158: nop

    func_800325A8(rdram, ctx);
        goto after_39;
    // 0x80033158: nop

    after_39:
L_8003315C:
    // 0x8003315C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80033160: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x80033164: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x80033168: jal         0x80039D90
    // 0x8003316C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_40;
    // 0x8003316C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_40:
    // 0x80033170: bne         $v0, $zero, L_80033184
    if (ctx->r2 != 0) {
        // 0x80033174: nop
    
            goto L_80033184;
    }
    // 0x80033174: nop

    // 0x80033178: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
    // 0x8003317C: b           L_800331B0
    // 0x80033180: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800331B0;
    // 0x80033180: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80033184:
    // 0x80033184: bne         $v0, $s7, L_8003319C
    if (ctx->r2 != ctx->r23) {
        // 0x80033188: lw          $t4, 0xE4($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XE4);
            goto L_8003319C;
    }
    // 0x80033188: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8003318C: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80033190: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
    // 0x80033194: b           L_800331B0
    // 0x80033198: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800331B0;
    // 0x80033198: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8003319C:
    // 0x8003319C: sltiu       $at, $t4, 0xB5
    ctx->r1 = ctx->r12 < 0XB5 ? 1 : 0;
    // 0x800331A0: bne         $at, $zero, L_800331B0
    if (ctx->r1 != 0) {
        // 0x800331A4: addiu       $t5, $zero, 0xA
        ctx->r13 = ADD32(0, 0XA);
            goto L_800331B0;
    }
    // 0x800331A4: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x800331A8: sh          $t5, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r13;
    // 0x800331AC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800331B0:
    // 0x800331B0: b           L_80033650
    // 0x800331B4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x800331B4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_800331B8:
    // 0x800331B8: bne         $s3, $zero, L_800331F8
    if (ctx->r19 != 0) {
        // 0x800331BC: andi        $t9, $a3, 0xC000
        ctx->r25 = ctx->r7 & 0XC000;
            goto L_800331F8;
    }
    // 0x800331BC: andi        $t9, $a3, 0xC000
    ctx->r25 = ctx->r7 & 0XC000;
    // 0x800331C0: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x800331C4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800331C8: sh          $t7, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r15;
    // 0x800331CC: addiu       $t8, $zero, 0x88
    ctx->r24 = ADD32(0, 0X88);
    // 0x800331D0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800331D4: jal         0x8003265C
    // 0x800331D8: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
    func_8003265C(rdram, ctx);
        goto after_41;
    // 0x800331D8: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
    after_41:
    // 0x800331DC: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800331E0: jal         0x800325FC
    // 0x800331E4: addiu       $a0, $a0, -0x1CC4
    ctx->r4 = ADD32(ctx->r4, -0X1CC4);
    func_800325FC(rdram, ctx);
        goto after_42;
    // 0x800331E4: addiu       $a0, $a0, -0x1CC4
    ctx->r4 = ADD32(ctx->r4, -0X1CC4);
    after_42:
    // 0x800331E8: jal         0x800325A8
    // 0x800331EC: nop

    func_800325A8(rdram, ctx);
        goto after_43;
    // 0x800331EC: nop

    after_43:
    // 0x800331F0: b           L_80033650
    // 0x800331F4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x800331F4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_800331F8:
    // 0x800331F8: beq         $t9, $zero, L_80033650
    if (ctx->r25 == 0) {
        // 0x800331FC: nop
    
            goto L_80033650;
    }
    // 0x800331FC: nop

    // 0x80033200: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
    // 0x80033204: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80033208: b           L_80033650
    // 0x8003320C: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
        goto L_80033650;
    // 0x8003320C: or          $s3, $s7, $zero
    ctx->r19 = ctx->r23 | 0;
L_80033210:
    // 0x80033210: bne         $s3, $zero, L_80033298
    if (ctx->r19 != 0) {
        // 0x80033214: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_80033298;
    }
    // 0x80033214: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80033218: addiu       $v0, $v0, 0x2D18
    ctx->r2 = ADD32(ctx->r2, 0X2D18);
    // 0x8003321C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80033220: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80033224: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80033228: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003322C: addiu       $s0, $s0, 0x2CC8
    ctx->r16 = ADD32(ctx->r16, 0X2CC8);
    // 0x80033230: addiu       $v0, $v0, 0x2D08
    ctx->r2 = ADD32(ctx->r2, 0X2D08);
    // 0x80033234: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_80033238:
    // 0x80033238: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8003323C: sw          $s2, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r18;
    // 0x80033240: sw          $s2, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r18;
    // 0x80033244: sw          $s2, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r18;
    // 0x80033248: bne         $s0, $v0, L_80033238
    if (ctx->r16 != ctx->r2) {
        // 0x8003324C: sw          $s2, -0x10($s0)
        MEM_W(-0X10, ctx->r16) = ctx->r18;
            goto L_80033238;
    }
    // 0x8003324C: sw          $s2, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->r18;
    // 0x80033250: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x80033254: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80033258: addiu       $t4, $zero, 0xA0
    ctx->r12 = ADD32(0, 0XA0);
    // 0x8003325C: beq         $t6, $zero, L_80033270
    if (ctx->r14 == 0) {
        // 0x80033260: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80033270;
    }
    // 0x80033260: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80033264: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x80033268: b           L_80033274
    // 0x8003326C: sh          $t2, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r10;
        goto L_80033274;
    // 0x8003326C: sh          $t2, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r10;
L_80033270:
    // 0x80033270: sh          $t3, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r11;
L_80033274:
    // 0x80033274: jal         0x8003265C
    // 0x80033278: sh          $t4, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r12;
    func_8003265C(rdram, ctx);
        goto after_44;
    // 0x80033278: sh          $t4, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r12;
    after_44:
    // 0x8003327C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80033280: jal         0x800325FC
    // 0x80033284: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    func_800325FC(rdram, ctx);
        goto after_45;
    // 0x80033284: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    after_45:
    // 0x80033288: jal         0x800325A8
    // 0x8003328C: nop

    func_800325A8(rdram, ctx);
        goto after_46;
    // 0x8003328C: nop

    after_46:
    // 0x80033290: b           L_80033650
    // 0x80033294: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80033294: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80033298:
    // 0x80033298: bne         $s3, $s7, L_80033328
    if (ctx->r19 != ctx->r23) {
        // 0x8003329C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80033328;
    }
    // 0x8003329C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800332A0: andi        $t5, $a3, 0x8000
    ctx->r13 = ctx->r7 & 0X8000;
    // 0x800332A4: beq         $t5, $zero, L_800332B8
    if (ctx->r13 == 0) {
        // 0x800332A8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800332B8;
    }
    // 0x800332A8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800332AC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800332B0: b           L_80033650
    // 0x800332B4: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
        goto L_80033650;
    // 0x800332B4: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_800332B8:
    // 0x800332B8: andi        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 & 0X2;
    // 0x800332BC: beq         $v1, $zero, L_800332D0
    if (ctx->r3 == 0) {
        // 0x800332C0: andi        $t8, $a0, 0x1
        ctx->r24 = ctx->r4 & 0X1;
            goto L_800332D0;
    }
    // 0x800332C0: andi        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 & 0X1;
    // 0x800332C4: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
    // 0x800332C8: bne         $t7, $zero, L_800332E4
    if (ctx->r15 != 0) {
        // 0x800332CC: nop
    
            goto L_800332E4;
    }
    // 0x800332CC: nop

L_800332D0:
    // 0x800332D0: beq         $t8, $zero, L_80033650
    if (ctx->r24 == 0) {
        // 0x800332D4: nop
    
            goto L_80033650;
    }
    // 0x800332D4: nop

    // 0x800332D8: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x800332DC: bne         $t9, $zero, L_80033650
    if (ctx->r25 != 0) {
        // 0x800332E0: nop
    
            goto L_80033650;
    }
    // 0x800332E0: nop

L_800332E4:
    // 0x800332E4: beq         $v1, $zero, L_800332FC
    if (ctx->r3 == 0) {
        // 0x800332E8: addiu       $t2, $zero, 0xA0
        ctx->r10 = ADD32(0, 0XA0);
            goto L_800332FC;
    }
    // 0x800332E8: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x800332EC: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x800332F0: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x800332F4: b           L_80033304
    // 0x800332F8: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
        goto L_80033304;
    // 0x800332F8: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
L_800332FC:
    // 0x800332FC: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x80033300: sh          $t2, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r10;
L_80033304:
    // 0x80033304: jal         0x8003265C
    // 0x80033308: nop

    func_8003265C(rdram, ctx);
        goto after_47;
    // 0x80033308: nop

    after_47:
    // 0x8003330C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80033310: jal         0x800325FC
    // 0x80033314: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    func_800325FC(rdram, ctx);
        goto after_48;
    // 0x80033314: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    after_48:
    // 0x80033318: jal         0x800325A8
    // 0x8003331C: nop

    func_800325A8(rdram, ctx);
        goto after_49;
    // 0x8003331C: nop

    after_49:
    // 0x80033320: b           L_80033650
    // 0x80033324: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80033324: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80033328:
    // 0x80033328: bne         $s3, $at, L_80033650
    if (ctx->r19 != ctx->r1) {
        // 0x8003332C: nop
    
            goto L_80033650;
    }
    // 0x8003332C: nop

    // 0x80033330: lh          $t3, 0x0($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X0);
    // 0x80033334: lhu         $t4, 0xEA($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XEA);
    // 0x80033338: bne         $t3, $zero, L_800333D0
    if (ctx->r11 != 0) {
        // 0x8003333C: nop
    
            goto L_800333D0;
    }
    // 0x8003333C: nop

    // 0x80033340: bne         $t4, $zero, L_80033378
    if (ctx->r12 != 0) {
        // 0x80033344: nop
    
            goto L_80033378;
    }
    // 0x80033344: nop

    // 0x80033348: jal         0x8003265C
    // 0x8003334C: nop

    func_8003265C(rdram, ctx);
        goto after_50;
    // 0x8003334C: nop

    after_50:
    // 0x80033350: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80033354: jal         0x800325FC
    // 0x80033358: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    func_800325FC(rdram, ctx);
        goto after_51;
    // 0x80033358: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    after_51:
    // 0x8003335C: lui         $t5, 0x8007
    ctx->r13 = S32(0X8007 << 16);
    // 0x80033360: lw          $t5, -0x1B4C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X1B4C);
    // 0x80033364: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80033368: beq         $t7, $zero, L_80033378
    if (ctx->r15 == 0) {
        // 0x8003336C: nop
    
            goto L_80033378;
    }
    // 0x8003336C: nop

    // 0x80033370: jal         0x800325A8
    // 0x80033374: nop

    func_800325A8(rdram, ctx);
        goto after_52;
    // 0x80033374: nop

    after_52:
L_80033378:
    // 0x80033378: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8003337C: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x80033380: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x80033384: jal         0x80039D90
    // 0x80033388: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    osPfsInitPak_recomp(rdram, ctx);
        goto after_53;
    // 0x80033388: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_53:
    // 0x8003338C: bne         $v0, $zero, L_800333A0
    if (ctx->r2 != 0) {
        // 0x80033390: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800333A0;
    }
    // 0x80033390: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80033394: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
    // 0x80033398: b           L_800333B0
    // 0x8003339C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800333B0;
    // 0x8003339C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800333A0:
    // 0x800333A0: bne         $v0, $at, L_800333B0
    if (ctx->r2 != ctx->r1) {
        // 0x800333A4: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_800333B0;
    }
    // 0x800333A4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800333A8: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    // 0x800333AC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800333B0:
    // 0x800333B0: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x800333B4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800333B8: sltiu       $at, $t6, 0xB5
    ctx->r1 = ctx->r14 < 0XB5 ? 1 : 0;
    // 0x800333BC: bne         $at, $zero, L_800333C8
    if (ctx->r1 != 0) {
        // 0x800333C0: sw          $t6, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r14;
            goto L_800333C8;
    }
    // 0x800333C0: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800333C4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800333C8:
    // 0x800333C8: b           L_80033650
    // 0x800333CC: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x800333CC: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_800333D0:
    // 0x800333D0: b           L_80033820
    // 0x800333D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80033820;
    // 0x800333D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800333D8:
    // 0x800333D8: bne         $s3, $zero, L_80033428
    if (ctx->r19 != 0) {
        // 0x800333DC: addiu       $t5, $zero, 0xA0
        ctx->r13 = ADD32(0, 0XA0);
            goto L_80033428;
    }
    // 0x800333DC: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x800333E0: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x800333E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800333E8: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x800333EC: beq         $t2, $zero, L_80033400
    if (ctx->r10 == 0) {
        // 0x800333F0: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80033400;
    }
    // 0x800333F0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800333F4: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x800333F8: b           L_80033404
    // 0x800333FC: sh          $t3, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r11;
        goto L_80033404;
    // 0x800333FC: sh          $t3, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r11;
L_80033400:
    // 0x80033400: sh          $t4, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r12;
L_80033404:
    // 0x80033404: jal         0x8003265C
    // 0x80033408: sh          $t5, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r13;
    func_8003265C(rdram, ctx);
        goto after_54;
    // 0x80033408: sh          $t5, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r13;
    after_54:
    // 0x8003340C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80033410: jal         0x800325FC
    // 0x80033414: addiu       $a0, $a0, -0x1C10
    ctx->r4 = ADD32(ctx->r4, -0X1C10);
    func_800325FC(rdram, ctx);
        goto after_55;
    // 0x80033414: addiu       $a0, $a0, -0x1C10
    ctx->r4 = ADD32(ctx->r4, -0X1C10);
    after_55:
    // 0x80033418: jal         0x800325A8
    // 0x8003341C: nop

    func_800325A8(rdram, ctx);
        goto after_56;
    // 0x8003341C: nop

    after_56:
    // 0x80033420: b           L_80033650
    // 0x80033424: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80033424: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80033428:
    // 0x80033428: bne         $s3, $s7, L_800334B0
    if (ctx->r19 != ctx->r23) {
        // 0x8003342C: andi        $t7, $a3, 0x8000
        ctx->r15 = ctx->r7 & 0X8000;
            goto L_800334B0;
    }
    // 0x8003342C: andi        $t7, $a3, 0x8000
    ctx->r15 = ctx->r7 & 0X8000;
    // 0x80033430: beq         $t7, $zero, L_80033440
    if (ctx->r15 == 0) {
        // 0x80033434: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80033440;
    }
    // 0x80033434: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80033438: b           L_80033650
    // 0x8003343C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80033650;
    // 0x8003343C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80033440:
    // 0x80033440: andi        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 & 0X2;
    // 0x80033444: beq         $v1, $zero, L_80033458
    if (ctx->r3 == 0) {
        // 0x80033448: andi        $t9, $a0, 0x1
        ctx->r25 = ctx->r4 & 0X1;
            goto L_80033458;
    }
    // 0x80033448: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x8003344C: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x80033450: bne         $t8, $zero, L_8003346C
    if (ctx->r24 != 0) {
        // 0x80033454: nop
    
            goto L_8003346C;
    }
    // 0x80033454: nop

L_80033458:
    // 0x80033458: beq         $t9, $zero, L_80033650
    if (ctx->r25 == 0) {
        // 0x8003345C: nop
    
            goto L_80033650;
    }
    // 0x8003345C: nop

    // 0x80033460: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x80033464: bne         $t6, $zero, L_80033650
    if (ctx->r14 != 0) {
        // 0x80033468: nop
    
            goto L_80033650;
    }
    // 0x80033468: nop

L_8003346C:
    // 0x8003346C: beq         $v1, $zero, L_80033484
    if (ctx->r3 == 0) {
        // 0x80033470: addiu       $t3, $zero, 0xA0
        ctx->r11 = ADD32(0, 0XA0);
            goto L_80033484;
    }
    // 0x80033470: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80033474: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80033478: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x8003347C: b           L_8003348C
    // 0x80033480: sh          $t2, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r10;
        goto L_8003348C;
    // 0x80033480: sh          $t2, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r10;
L_80033484:
    // 0x80033484: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x80033488: sh          $t3, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r11;
L_8003348C:
    // 0x8003348C: jal         0x8003265C
    // 0x80033490: nop

    func_8003265C(rdram, ctx);
        goto after_57;
    // 0x80033490: nop

    after_57:
    // 0x80033494: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80033498: jal         0x800325FC
    // 0x8003349C: addiu       $a0, $a0, -0x1C10
    ctx->r4 = ADD32(ctx->r4, -0X1C10);
    func_800325FC(rdram, ctx);
        goto after_58;
    // 0x8003349C: addiu       $a0, $a0, -0x1C10
    ctx->r4 = ADD32(ctx->r4, -0X1C10);
    after_58:
    // 0x800334A0: jal         0x800325A8
    // 0x800334A4: nop

    func_800325A8(rdram, ctx);
        goto after_59;
    // 0x800334A4: nop

    after_59:
    // 0x800334A8: b           L_80033650
    // 0x800334AC: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x800334AC: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_800334B0:
    // 0x800334B0: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x800334B4: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x800334B8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800334BC: bne         $t4, $zero, L_8003350C
    if (ctx->r12 != 0) {
        // 0x800334C0: lui         $a2, 0x8009
        ctx->r6 = S32(0X8009 << 16);
            goto L_8003350C;
    }
    // 0x800334C0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x800334C4: jal         0x80039D90
    // 0x800334C8: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    osPfsInitPak_recomp(rdram, ctx);
        goto after_60;
    // 0x800334C8: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    after_60:
    // 0x800334CC: bne         $v0, $zero, L_800334E0
    if (ctx->r2 != 0) {
        // 0x800334D0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800334E0;
    }
    // 0x800334D0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800334D4: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
    // 0x800334D8: b           L_80033504
    // 0x800334DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80033504;
    // 0x800334DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800334E0:
    // 0x800334E0: bne         $v0, $at, L_800334F4
    if (ctx->r2 != ctx->r1) {
        // 0x800334E4: addiu       $t5, $zero, 0x5
        ctx->r13 = ADD32(0, 0X5);
            goto L_800334F4;
    }
    // 0x800334E4: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800334E8: sh          $t5, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r13;
    // 0x800334EC: b           L_80033504
    // 0x800334F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80033504;
    // 0x800334F0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800334F4:
    // 0x800334F4: bne         $v0, $s7, L_80033504
    if (ctx->r2 != ctx->r23) {
        // 0x800334F8: addiu       $t7, $zero, 0x8
        ctx->r15 = ADD32(0, 0X8);
            goto L_80033504;
    }
    // 0x800334F8: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800334FC: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x80033500: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80033504:
    // 0x80033504: b           L_80033650
    // 0x80033508: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80033508: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_8003350C:
    // 0x8003350C: b           L_80033820
    // 0x80033510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80033820;
    // 0x80033510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80033514:
    // 0x80033514: bne         $s3, $zero, L_80033564
    if (ctx->r19 != 0) {
        // 0x80033518: addiu       $t2, $zero, 0xA0
        ctx->r10 = ADD32(0, 0XA0);
            goto L_80033564;
    }
    // 0x80033518: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x8003351C: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x80033520: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80033524: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80033528: beq         $t8, $zero, L_8003353C
    if (ctx->r24 == 0) {
        // 0x8003352C: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_8003353C;
    }
    // 0x8003352C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80033530: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80033534: b           L_80033540
    // 0x80033538: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
        goto L_80033540;
    // 0x80033538: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
L_8003353C:
    // 0x8003353C: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
L_80033540:
    // 0x80033540: jal         0x8003265C
    // 0x80033544: sh          $t2, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r10;
    func_8003265C(rdram, ctx);
        goto after_61;
    // 0x80033544: sh          $t2, 0x2D12($at)
    MEM_H(0X2D12, ctx->r1) = ctx->r10;
    after_61:
    // 0x80033548: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8003354C: jal         0x800325FC
    // 0x80033550: addiu       $a0, $a0, -0x1BA0
    ctx->r4 = ADD32(ctx->r4, -0X1BA0);
    func_800325FC(rdram, ctx);
        goto after_62;
    // 0x80033550: addiu       $a0, $a0, -0x1BA0
    ctx->r4 = ADD32(ctx->r4, -0X1BA0);
    after_62:
    // 0x80033554: jal         0x800325A8
    // 0x80033558: nop

    func_800325A8(rdram, ctx);
        goto after_63;
    // 0x80033558: nop

    after_63:
    // 0x8003355C: b           L_80033650
    // 0x80033560: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80033560: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80033564:
    // 0x80033564: bne         $s3, $s7, L_800335EC
    if (ctx->r19 != ctx->r23) {
        // 0x80033568: andi        $t3, $a3, 0x8000
        ctx->r11 = ctx->r7 & 0X8000;
            goto L_800335EC;
    }
    // 0x80033568: andi        $t3, $a3, 0x8000
    ctx->r11 = ctx->r7 & 0X8000;
    // 0x8003356C: beq         $t3, $zero, L_8003357C
    if (ctx->r11 == 0) {
        // 0x80033570: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8003357C;
    }
    // 0x80033570: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80033574: b           L_80033650
    // 0x80033578: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80033650;
    // 0x80033578: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8003357C:
    // 0x8003357C: andi        $v1, $a0, 0x2
    ctx->r3 = ctx->r4 & 0X2;
    // 0x80033580: beq         $v1, $zero, L_80033594
    if (ctx->r3 == 0) {
        // 0x80033584: andi        $t5, $a0, 0x1
        ctx->r13 = ctx->r4 & 0X1;
            goto L_80033594;
    }
    // 0x80033584: andi        $t5, $a0, 0x1
    ctx->r13 = ctx->r4 & 0X1;
    // 0x80033588: lh          $t4, 0x0($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X0);
    // 0x8003358C: bne         $t4, $zero, L_800335A8
    if (ctx->r12 != 0) {
        // 0x80033590: nop
    
            goto L_800335A8;
    }
    // 0x80033590: nop

L_80033594:
    // 0x80033594: beq         $t5, $zero, L_80033650
    if (ctx->r13 == 0) {
        // 0x80033598: nop
    
            goto L_80033650;
    }
    // 0x80033598: nop

    // 0x8003359C: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
    // 0x800335A0: bne         $t7, $zero, L_80033650
    if (ctx->r15 != 0) {
        // 0x800335A4: nop
    
            goto L_80033650;
    }
    // 0x800335A4: nop

L_800335A8:
    // 0x800335A8: beq         $v1, $zero, L_800335C0
    if (ctx->r3 == 0) {
        // 0x800335AC: addiu       $t9, $zero, 0xA0
        ctx->r25 = ADD32(0, 0XA0);
            goto L_800335C0;
    }
    // 0x800335AC: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x800335B0: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800335B4: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x800335B8: b           L_800335C8
    // 0x800335BC: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
        goto L_800335C8;
    // 0x800335BC: sh          $t8, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r24;
L_800335C0:
    // 0x800335C0: sh          $s7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r23;
    // 0x800335C4: sh          $t9, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r25;
L_800335C8:
    // 0x800335C8: jal         0x8003265C
    // 0x800335CC: nop

    func_8003265C(rdram, ctx);
        goto after_64;
    // 0x800335CC: nop

    after_64:
    // 0x800335D0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800335D4: jal         0x800325FC
    // 0x800335D8: addiu       $a0, $a0, -0x1BA0
    ctx->r4 = ADD32(ctx->r4, -0X1BA0);
    func_800325FC(rdram, ctx);
        goto after_65;
    // 0x800335D8: addiu       $a0, $a0, -0x1BA0
    ctx->r4 = ADD32(ctx->r4, -0X1BA0);
    after_65:
    // 0x800335DC: jal         0x800325A8
    // 0x800335E0: nop

    func_800325A8(rdram, ctx);
        goto after_66;
    // 0x800335E0: nop

    after_66:
    // 0x800335E4: b           L_80033650
    // 0x800335E8: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x800335E8: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_800335EC:
    // 0x800335EC: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x800335F0: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x800335F4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800335F8: bne         $t6, $zero, L_80033648
    if (ctx->r14 != 0) {
        // 0x800335FC: lui         $a2, 0x8009
        ctx->r6 = S32(0X8009 << 16);
            goto L_80033648;
    }
    // 0x800335FC: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80033600: jal         0x80039D90
    // 0x80033604: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    osPfsInitPak_recomp(rdram, ctx);
        goto after_67;
    // 0x80033604: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    after_67:
    // 0x80033608: bne         $v0, $zero, L_8003361C
    if (ctx->r2 != 0) {
        // 0x8003360C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8003361C;
    }
    // 0x8003360C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80033610: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
    // 0x80033614: b           L_80033640
    // 0x80033618: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80033640;
    // 0x80033618: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8003361C:
    // 0x8003361C: bne         $v0, $at, L_80033630
    if (ctx->r2 != ctx->r1) {
        // 0x80033620: addiu       $t2, $zero, 0x5
        ctx->r10 = ADD32(0, 0X5);
            goto L_80033630;
    }
    // 0x80033620: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80033624: sh          $t2, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r10;
    // 0x80033628: b           L_80033640
    // 0x8003362C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_80033640;
    // 0x8003362C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80033630:
    // 0x80033630: bne         $v0, $s7, L_80033640
    if (ctx->r2 != ctx->r23) {
        // 0x80033634: addiu       $t3, $zero, 0x8
        ctx->r11 = ADD32(0, 0X8);
            goto L_80033640;
    }
    // 0x80033634: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80033638: sh          $t3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r11;
    // 0x8003363C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80033640:
    // 0x80033640: b           L_80033650
    // 0x80033644: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
        goto L_80033650;
    // 0x80033644: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
L_80033648:
    // 0x80033648: b           L_80033820
    // 0x8003364C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80033820;
    // 0x8003364C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80033650:
    // 0x80033650: beq         $a1, $zero, L_800336B8
    if (ctx->r5 == 0) {
        // 0x80033654: slti        $at, $a1, 0x5
        ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
            goto L_800336B8;
    }
    // 0x80033654: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80033658: beql        $at, $zero, L_800336BC
    if (ctx->r1 == 0) {
        // 0x8003365C: lhu         $t6, 0xEA($sp)
        ctx->r14 = MEM_HU(ctx->r29, 0XEA);
            goto L_800336BC;
    }
    goto skip_4;
    // 0x8003365C: lhu         $t6, 0xEA($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XEA);
    skip_4:
    // 0x80033660: jal         0x8003C8E0
    // 0x80033664: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    osContStartQuery_recomp(rdram, ctx);
        goto after_68;
    // 0x80033664: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    after_68:
    // 0x80033668: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8003366C: addiu       $a1, $a1, 0x2D2C
    ctx->r5 = ADD32(ctx->r5, 0X2D2C);
    // 0x80033670: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x80033674: jal         0x80034020
    // 0x80033678: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_69;
    // 0x80033678: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_69:
    // 0x8003367C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80033680: jal         0x8003C964
    // 0x80033684: addiu       $a0, $a0, 0x2A90
    ctx->r4 = ADD32(ctx->r4, 0X2A90);
    osContGetQuery_recomp(rdram, ctx);
        goto after_70;
    // 0x80033684: addiu       $a0, $a0, 0x2A90
    ctx->r4 = ADD32(ctx->r4, 0X2A90);
    after_70:
    // 0x80033688: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8003368C: lb          $t4, 0x2870($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X2870);
    // 0x80033690: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80033694: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80033698: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8003369C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800336A0: lbu         $t7, 0x2A92($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2A92);
    // 0x800336A4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800336A8: beql        $t8, $zero, L_800336BC
    if (ctx->r24 == 0) {
        // 0x800336AC: lhu         $t6, 0xEA($sp)
        ctx->r14 = MEM_HU(ctx->r29, 0XEA);
            goto L_800336BC;
    }
    goto skip_5;
    // 0x800336AC: lhu         $t6, 0xEA($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XEA);
    skip_5:
    // 0x800336B0: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x800336B4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800336B8:
    // 0x800336B8: lhu         $t6, 0xEA($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0XEA);
L_800336BC:
    // 0x800336BC: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x800336C0: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800336C4: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800336C8: bne         $at, $zero, L_800336D4
    if (ctx->r1 != 0) {
        // 0x800336CC: sh          $t2, 0xEA($sp)
        MEM_H(0XEA, ctx->r29) = ctx->r10;
            goto L_800336D4;
    }
    // 0x800336CC: sh          $t2, 0xEA($sp)
    MEM_H(0XEA, ctx->r29) = ctx->r10;
    // 0x800336D0: sh          $zero, 0xEA($sp)
    MEM_H(0XEA, ctx->r29) = 0;
L_800336D4:
    // 0x800336D4: jal         0x8003AC10
    // 0x800336D8: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    osContStartReadData_recomp(rdram, ctx);
        goto after_71;
    // 0x800336D8: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    after_71:
    // 0x800336DC: jal         0x8003228C
    // 0x800336E0: nop

    func_8003228C(rdram, ctx);
        goto after_72;
    // 0x800336E0: nop

    after_72:
    // 0x800336E4: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800336E8: addiu       $a1, $a1, 0x2D2C
    ctx->r5 = ADD32(ctx->r5, 0X2D2C);
    // 0x800336EC: lw          $a0, 0x110($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X110);
    // 0x800336F0: jal         0x80034020
    // 0x800336F4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_73;
    // 0x800336F4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_73:
    // 0x800336F8: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x800336FC: lb          $t4, 0x2870($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X2870);
    // 0x80033700: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x80033704: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80033708: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8003370C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80033710: addu        $s0, $a0, $t5
    ctx->r16 = ADD32(ctx->r4, ctx->r13);
    // 0x80033714: lb          $v1, 0x3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X3);
    // 0x80033718: lb          $s1, 0x2($s0)
    ctx->r17 = MEM_B(ctx->r16, 0X2);
    // 0x8003371C: slti        $t9, $v1, 0x21
    ctx->r25 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x80033720: xori        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 ^ 0X1;
    // 0x80033724: slti        $t7, $s1, 0x21
    ctx->r15 = SIGNED(ctx->r17) < 0X21 ? 1 : 0;
    // 0x80033728: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8003372C: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x80033730: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x80033734: slti        $t5, $v1, -0x20
    ctx->r13 = SIGNED(ctx->r3) < -0X20 ? 1 : 0;
    // 0x80033738: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8003373C: lhu         $t5, 0x0($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X0);
    // 0x80033740: slti        $t8, $s1, -0x20
    ctx->r24 = SIGNED(ctx->r17) < -0X20 ? 1 : 0;
    // 0x80033744: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x80033748: or          $t9, $t3, $t7
    ctx->r25 = ctx->r11 | ctx->r15;
    // 0x8003374C: or          $t4, $t9, $t2
    ctx->r12 = ctx->r25 | ctx->r10;
    // 0x80033750: or          $t3, $t5, $t4
    ctx->r11 = ctx->r13 | ctx->r12;
    // 0x80033754: jal         0x8003AC9C
    // 0x80033758: sh          $t3, 0xF2($sp)
    MEM_H(0XF2, ctx->r29) = ctx->r11;
    osContGetReadData_recomp(rdram, ctx);
        goto after_74;
    // 0x80033758: sh          $t3, 0xF2($sp)
    MEM_H(0XF2, ctx->r29) = ctx->r11;
    after_74:
    // 0x8003375C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80033760: lb          $t7, 0x2870($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X2870);
    // 0x80033764: addiu       $t8, $sp, 0xF8
    ctx->r24 = ADD32(ctx->r29, 0XF8);
    // 0x80033768: lhu         $a0, 0xF2($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XF2);
    // 0x8003376C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80033770: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80033774: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80033778: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
    // 0x8003377C: lb          $v1, 0x3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X3);
    // 0x80033780: lb          $s1, 0x2($s0)
    ctx->r17 = MEM_B(ctx->r16, 0X2);
    // 0x80033784: slti        $t4, $v1, 0x21
    ctx->r12 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x80033788: xori        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 ^ 0X1;
    // 0x8003378C: slti        $t9, $s1, 0x21
    ctx->r25 = SIGNED(ctx->r17) < 0X21 ? 1 : 0;
    // 0x80033790: xori        $t2, $t9, 0x1
    ctx->r10 = ctx->r25 ^ 0X1;
    // 0x80033794: sll         $t3, $t5, 3
    ctx->r11 = S32(ctx->r13 << 3);
    // 0x80033798: or          $t7, $t2, $t3
    ctx->r15 = ctx->r10 | ctx->r11;
    // 0x8003379C: slti        $t8, $v1, -0x20
    ctx->r24 = SIGNED(ctx->r3) < -0X20 ? 1 : 0;
    // 0x800337A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800337A4: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x800337A8: slti        $t2, $s1, -0x20
    ctx->r10 = SIGNED(ctx->r17) < -0X20 ? 1 : 0;
    // 0x800337AC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800337B0: or          $t4, $t7, $t9
    ctx->r12 = ctx->r15 | ctx->r25;
    // 0x800337B4: or          $t6, $t4, $t3
    ctx->r14 = ctx->r12 | ctx->r11;
    // 0x800337B8: or          $a2, $t8, $t6
    ctx->r6 = ctx->r24 | ctx->r14;
    // 0x800337BC: andi        $t0, $a2, 0xFFFF
    ctx->r8 = ctx->r6 & 0XFFFF;
    // 0x800337C0: and         $v0, $t0, $a0
    ctx->r2 = ctx->r8 & ctx->r4;
    // 0x800337C4: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x800337C8: beq         $t9, $zero, L_800337FC
    if (ctx->r25 == 0) {
        // 0x800337CC: andi        $t1, $v0, 0xFFFF
        ctx->r9 = ctx->r2 & 0XFFFF;
            goto L_800337FC;
    }
    // 0x800337CC: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x800337D0: lhu         $t5, 0xEC($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0XEC);
    // 0x800337D4: addiu       $t2, $t5, 0x1
    ctx->r10 = ADD32(ctx->r13, 0X1);
    // 0x800337D8: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
    // 0x800337DC: sra         $t4, $v0, 5
    ctx->r12 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800337E0: beq         $t4, $zero, L_800337F4
    if (ctx->r12 == 0) {
        // 0x800337E4: sh          $t2, 0xEC($sp)
        MEM_H(0XEC, ctx->r29) = ctx->r10;
            goto L_800337F4;
    }
    // 0x800337E4: sh          $t2, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = ctx->r10;
    // 0x800337E8: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x800337EC: beql        $t3, $zero, L_80033804
    if (ctx->r11 == 0) {
        // 0x800337F0: xor         $t6, $t0, $a0
        ctx->r14 = ctx->r8 ^ ctx->r4;
            goto L_80033804;
    }
    goto skip_6;
    // 0x800337F0: xor         $t6, $t0, $a0
    ctx->r14 = ctx->r8 ^ ctx->r4;
    skip_6:
L_800337F4:
    // 0x800337F4: b           L_80033800
    // 0x800337F8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80033800;
    // 0x800337F8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800337FC:
    // 0x800337FC: sh          $zero, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = 0;
L_80033800:
    // 0x80033800: xor         $t6, $t0, $a0
    ctx->r14 = ctx->r8 ^ ctx->r4;
L_80033804:
    // 0x80033804: and         $a3, $t0, $t6
    ctx->r7 = ctx->r8 & ctx->r14;
    // 0x80033808: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x8003380C: beq         $t8, $zero, L_800328D8
    if (ctx->r24 == 0) {
        // 0x80033810: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_800328D8;
    }
    // 0x80033810: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80033814: andi        $t1, $t8, 0xFFFF
    ctx->r9 = ctx->r24 & 0XFFFF;
    // 0x80033818: b           L_800328D8
    // 0x8003381C: sh          $zero, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = 0;
        goto L_800328D8;
    // 0x8003381C: sh          $zero, 0xEC($sp)
    MEM_H(0XEC, ctx->r29) = 0;
L_80033820:
    // 0x80033820: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80033824: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80033828: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003382C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80033830: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80033834: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80033838: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8003383C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80033840: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80033844: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80033848: jr          $ra
    // 0x8003384C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x8003384C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void func_8001D640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D640: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8001D644: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8001D648: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001D64C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8001D650: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8001D654: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8001D658: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x8001D65C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8001D660: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8001D664: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8001D668: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8001D66C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8001D670: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001D674: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001D678: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001D67C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001D680: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001D684: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001D688: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    // 0x8001D68C: jal         0x80022FD0
    // 0x8001D690: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    get_rand(rdram, ctx);
        goto after_0;
    // 0x8001D690: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8001D694: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8001D698: lw          $a0, -0x3A9C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3A9C);
    // 0x8001D69C: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8001D6A0: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8001D6A4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8001D6A8: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8001D6AC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8001D6B0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8001D6B4: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8001D6B8: lhu         $t3, 0x6($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X6);
    // 0x8001D6BC: lhu         $s7, 0x4($v1)
    ctx->r23 = MEM_HU(ctx->r3, 0X4);
    // 0x8001D6C0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001D6C4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001D6C8: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x8001D6CC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8001D6D0: addiu       $fp, $fp, -0x3AA8
    ctx->r30 = ADD32(ctx->r30, -0X3AA8);
    // 0x8001D6D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001D6D8: lw          $s5, 0x0($v1)
    ctx->r21 = MEM_W(ctx->r3, 0X0);
    // 0x8001D6DC: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001D6E0: addiu       $s2, $s2, -0x3668
    ctx->r18 = ADD32(ctx->r18, -0X3668);
    // 0x8001D6E4: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x8001D6E8: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    // 0x8001D6EC: beq         $s7, $zero, L_8001D7CC
    if (ctx->r23 == 0) {
        // 0x8001D6F0: addu        $s3, $t2, $t4
        ctx->r19 = ADD32(ctx->r10, ctx->r12);
            goto L_8001D7CC;
    }
    // 0x8001D6F0: addu        $s3, $t2, $t4
    ctx->r19 = ADD32(ctx->r10, ctx->r12);
    // 0x8001D6F4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8001D6F8: addiu       $s0, $s0, -0x3A80
    ctx->r16 = ADD32(ctx->r16, -0X3A80);
L_8001D6FC:
    // 0x8001D6FC: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x8001D700: lw          $s1, 0x4($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X4);
    // 0x8001D704: addiu       $s4, $s2, 0x24
    ctx->r20 = ADD32(ctx->r18, 0X24);
    // 0x8001D708: beql        $v0, $zero, L_8001D720
    if (ctx->r2 == 0) {
        // 0x8001D70C: lw          $t5, 0x0($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X0);
            goto L_8001D720;
    }
    goto skip_0;
    // 0x8001D70C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x8001D710: jal         0x80022FD0
    // 0x8001D714: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    get_rand(rdram, ctx);
        goto after_1;
    // 0x8001D714: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    after_1:
    // 0x8001D718: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8001D71C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
L_8001D720:
    // 0x8001D720: sw          $s1, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r17;
    // 0x8001D724: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001D728: sw          $t5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r13;
    // 0x8001D72C: lw          $t6, -0x3670($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3670);
    // 0x8001D730: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D734: addiu       $s6, $s6, 0x8
    ctx->r22 = ADD32(ctx->r22, 0X8);
    // 0x8001D738: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8001D73C: sw          $t7, -0x3670($at)
    MEM_W(-0X3670, ctx->r1) = ctx->r15;
    // 0x8001D740: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x8001D744: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001D748: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001D74C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001D750: sw          $s4, -0x3AC8($at)
    MEM_W(-0X3AC8, ctx->r1) = ctx->r20;
    // 0x8001D754: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8001D758: beq         $s1, $zero, L_8001D7C0
    if (ctx->r17 == 0) {
        // 0x8001D75C: sw          $t9, 0x0($fp)
        MEM_W(0X0, ctx->r30) = ctx->r25;
            goto L_8001D7C0;
    }
    // 0x8001D75C: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
L_8001D760:
    // 0x8001D760: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8001D764: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001D768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8001D76C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8001D770: lwc1        $f6, 0x4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8001D774: addiu       $s4, $s2, 0x24
    ctx->r20 = ADD32(ctx->r18, 0X24);
    // 0x8001D778: jal         0x800232F4
    // 0x8001D77C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x8001D77C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8001D780: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001D784: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001D788: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8001D78C: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x8001D790: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8001D794: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x8001D798: add.s       $f18, $f24, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f24.fl + ctx->f16.fl;
    // 0x8001D79C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001D7A0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8001D7A4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8001D7A8: jal         0x80008FE0
    // 0x8001D7AC: nop

    func_80008FE0(rdram, ctx);
        goto after_3;
    // 0x8001D7AC: nop

    after_3:
    // 0x8001D7B0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8001D7B4: addiu       $s2, $s2, 0x128
    ctx->r18 = ADD32(ctx->r18, 0X128);
    // 0x8001D7B8: bne         $s1, $zero, L_8001D760
    if (ctx->r17 != 0) {
        // 0x8001D7BC: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8001D760;
    }
    // 0x8001D7BC: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_8001D7C0:
    // 0x8001D7C0: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x8001D7C4: bne         $s7, $zero, L_8001D6FC
    if (ctx->r23 != 0) {
        // 0x8001D7C8: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_8001D6FC;
    }
    // 0x8001D7C8: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
L_8001D7CC:
    // 0x8001D7CC: jal         0x80009260
    // 0x8001D7D0: nop

    func_80009260(rdram, ctx);
        goto after_4;
    // 0x8001D7D0: nop

    after_4:
    // 0x8001D7D4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8001D7D8: lw          $t0, -0x3670($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3670);
    // 0x8001D7DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001D7E0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8001D7E4: sh          $t0, -0x3A66($at)
    MEM_H(-0X3A66, ctx->r1) = ctx->r8;
    // 0x8001D7E8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8001D7EC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8001D7F0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8001D7F4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7F8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001D7FC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001D800: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8001D804: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8001D808: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8001D80C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8001D810: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8001D814: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8001D818: jr          $ra
    // 0x8001D81C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8001D81C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void guPositionF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F70: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80034F74: lwc1        $f0, 0x1B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1B30);
    // 0x80034F78: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80034F7C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80034F80: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80034F84: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80034F88: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80034F8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80034F90: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80034F94: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80034F98: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80034F9C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80034FA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80034FA4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80034FA8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80034FAC: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x80034FB0: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    // 0x80034FB4: swc1        $f0, 0x5200($at)
    MEM_W(0X5200, ctx->r1) = ctx->f0.u32l;
    // 0x80034FB8: jal         0x80035680
    // 0x80034FBC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80034FBC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80034FC0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80034FC4: jal         0x800361F0
    // 0x80034FC8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80034FC8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x80034FCC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80034FD0: jal         0x80035680
    // 0x80034FD4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80034FD4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x80034FD8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80034FDC: jal         0x800361F0
    // 0x80034FE0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x80034FE0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x80034FE4: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80034FE8: jal         0x80035680
    // 0x80034FEC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x80034FEC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80034FF0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80034FF4: jal         0x800361F0
    // 0x80034FF8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x80034FF8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80034FFC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80035000: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80035004: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80035008: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003500C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80035010: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80035014: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80035018: nop

    // 0x8003501C: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80035020: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80035024: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80035028: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8003502C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80035030: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80035034: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80035038: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003503C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80035040: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80035044: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80035048: mul.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8003504C: nop

    // 0x80035050: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80035054: nop

    // 0x80035058: mul.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8003505C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035060: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80035064: nop

    // 0x80035068: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8003506C: nop

    // 0x80035070: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80035074: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80035078: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003507C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80035080: nop

    // 0x80035084: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80035088: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8003508C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80035090: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x80035094: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80035098: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8003509C: mul.s       $f12, $f22, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x800350A0: nop

    // 0x800350A4: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800350A8: nop

    // 0x800350AC: mul.s       $f4, $f20, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x800350B0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800350B4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800350B8: nop

    // 0x800350BC: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800350C0: nop

    // 0x800350C4: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800350C8: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800350CC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800350D0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800350D4: nop

    // 0x800350D8: mul.s       $f10, $f22, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x800350DC: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x800350E0: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800350E4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x800350E8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800350EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800350F0: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x800350F4: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800350F8: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x800350FC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80035100: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80035104: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x80035108: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003510C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80035110: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80035114: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80035118: jr          $ra
    // 0x8003511C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003511C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alCents2Ratio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800444F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800444F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800444F8: bltz        $a0, L_8004450C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800444FC: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8004450C;
    }
    // 0x800444FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80044500: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80044504: b           L_80044514
    // 0x80044508: lwc1        $f0, 0x2320($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2320);
        goto L_80044514;
    // 0x80044508: lwc1        $f0, 0x2320($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2320);
L_8004450C:
    // 0x8004450C: lwc1        $f0, 0x2324($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2324);
    // 0x80044510: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80044514:
    // 0x80044514: beq         $a0, $zero, L_80044538
    if (ctx->r4 == 0) {
        // 0x80044518: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_80044538;
    }
L_80044518:
    // 0x80044518: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x8004451C: beq         $t6, $zero, L_8004452C
    if (ctx->r14 == 0) {
        // 0x80044520: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8004452C;
    }
    // 0x80044520: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80044524: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80044528: nop

L_8004452C:
    // 0x8004452C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80044530: bne         $t7, $zero, L_80044518
    if (ctx->r15 != 0) {
        // 0x80044534: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80044518;
    }
    // 0x80044534: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_80044538:
    // 0x80044538: jr          $ra
    // 0x8004453C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8004453C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80009260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009260: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80009264: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80009268: lw          $v1, -0x3670($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3670);
    // 0x8000926C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80009270: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80009274: beq         $v1, $zero, L_800092B8
    if (ctx->r3 == 0) {
        // 0x80009278: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800092B8;
    }
    // 0x80009278: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000927C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009280: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80009284: addiu       $a3, $a3, -0x3668
    ctx->r7 = ADD32(ctx->r7, -0X3668);
    // 0x80009288: addiu       $a1, $a1, -0x2F50
    ctx->r5 = ADD32(ctx->r5, -0X2F50);
    // 0x8000928C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
L_80009290:
    // 0x80009290: lw          $t6, 0x20($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X20);
    // 0x80009294: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80009298: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000929C: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x800092A0: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800092A4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800092A8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800092AC: addiu       $a3, $a3, 0x128
    ctx->r7 = ADD32(ctx->r7, 0X128);
    // 0x800092B0: bne         $at, $zero, L_80009290
    if (ctx->r1 != 0) {
        // 0x800092B4: sh          $t7, -0x2($a2)
        MEM_H(-0X2, ctx->r6) = ctx->r15;
            goto L_80009290;
    }
    // 0x800092B4: sh          $t7, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r15;
L_800092B8:
    // 0x800092B8: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x800092BC: addiu       $t3, $t3, -0x2F50
    ctx->r11 = ADD32(ctx->r11, -0X2F50);
L_800092C0:
    // 0x800092C0: beq         $a0, $zero, L_8000931C
    if (ctx->r4 == 0) {
        // 0x800092C4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000931C;
    }
    // 0x800092C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800092C8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800092CC: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800092D0: addu        $t2, $t9, $a2
    ctx->r10 = ADD32(ctx->r25, ctx->r6);
    // 0x800092D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800092D8:
    // 0x800092D8: lhu         $a3, 0x0($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X0);
    // 0x800092DC: lhu         $t0, 0x2($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X2);
    // 0x800092E0: addu        $a1, $t3, $v0
    ctx->r5 = ADD32(ctx->r11, ctx->r2);
    // 0x800092E4: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800092E8: beql        $at, $zero, L_80009310
    if (ctx->r1 == 0) {
        // 0x800092EC: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80009310;
    }
    goto skip_0;
    // 0x800092EC: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_0:
    // 0x800092F0: lhu         $t1, 0x0($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X0);
    // 0x800092F4: lhu         $t4, 0x2($a1)
    ctx->r12 = MEM_HU(ctx->r5, 0X2);
    // 0x800092F8: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x800092FC: sh          $a3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r7;
    // 0x80009300: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80009304: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x80009308: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8000930C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_80009310:
    // 0x80009310: sltu        $at, $a2, $t2
    ctx->r1 = ctx->r6 < ctx->r10 ? 1 : 0;
    // 0x80009314: bne         $at, $zero, L_800092D8
    if (ctx->r1 != 0) {
        // 0x80009318: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_800092D8;
    }
    // 0x80009318: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8000931C:
    // 0x8000931C: bne         $v1, $zero, L_800092C0
    if (ctx->r3 != 0) {
        // 0x80009320: nop
    
            goto L_800092C0;
    }
    // 0x80009320: nop

    // 0x80009324: jr          $ra
    // 0x80009328: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80009328: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002543C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002543C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025444: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80025448: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8002544C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80025450: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80025454: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80025458: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002545C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80025460: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80025464: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80025468: addiu       $t8, $t8, -0x688
    ctx->r24 = ADD32(ctx->r24, -0X688);
    // 0x8002546C: addiu       $t7, $t6, 0x1C
    ctx->r15 = ADD32(ctx->r14, 0X1C);
    // 0x80025470: jal         0x800390F0
    // 0x80025474: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    alSeqpGetState(rdram, ctx);
        goto after_0;
    // 0x80025474: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x80025478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002547C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025480: jr          $ra
    // 0x80025484: nop

    return;
    // 0x80025484: nop

;}
RECOMP_FUNC void func_80008A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008A08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80008A0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80008A10: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80008A14: lui         $t7, 0xD3
    ctx->r15 = S32(0XD3 << 16);
    // 0x80008A18: addiu       $t7, $t7, 0x5E0
    ctx->r15 = ADD32(ctx->r15, 0X5E0);
    // 0x80008A1C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80008A20: addiu       $a1, $a1, -0x3A90
    ctx->r5 = ADD32(ctx->r5, -0X3A90);
    // 0x80008A24: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80008A28: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80008A2C: jal         0x80024260
    // 0x80008A30: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80008A30: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80008A34: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80008A38: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80008A3C: addiu       $v1, $v1, -0x3690
    ctx->r3 = ADD32(ctx->r3, -0X3690);
    // 0x80008A40: lw          $t8, 0x80($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X80);
    // 0x80008A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008A48: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80008A4C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80008A50: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80008A54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008A58: beq         $t9, $zero, L_80008AC4
    if (ctx->r25 == 0) {
        // 0x80008A5C: nop
    
            goto L_80008AC4;
    }
    // 0x80008A5C: nop

L_80008A60:
    // 0x80008A60: lw          $t0, 0x80($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X80);
    // 0x80008A64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80008A68: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x80008A6C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80008A70: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80008A74: sb          $t3, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r11;
    // 0x80008A78: lw          $t4, 0x80($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X80);
    // 0x80008A7C: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x80008A80: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80008A84: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x80008A88: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x80008A8C: lw          $t8, 0x80($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X80);
    // 0x80008A90: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80008A94: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80008A98: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80008A9C: sb          $t1, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r9;
    // 0x80008AA0: lw          $t2, 0x80($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X80);
    // 0x80008AA4: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80008AA8: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80008AAC: lbu         $t5, 0x3($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X3);
    // 0x80008AB0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008AB4: bne         $v0, $a0, L_80008A60
    if (ctx->r2 != ctx->r4) {
        // 0x80008AB8: sb          $t5, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r13;
            goto L_80008A60;
    }
    // 0x80008AB8: sb          $t5, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r13;
    // 0x80008ABC: b           L_80008ACC
    // 0x80008AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80008ACC;
    // 0x80008AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80008AC4:
    // 0x80008AC4: sb          $t6, -0x3690($at)
    MEM_B(-0X3690, ctx->r1) = ctx->r14;
    // 0x80008AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80008ACC:
    // 0x80008ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008AD0: jr          $ra
    // 0x80008AD4: nop

    return;
    // 0x80008AD4: nop

;}
RECOMP_FUNC void func_8000D518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D518: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000D51C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000D520: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000D524: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8000D528: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8000D52C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000D530: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000D534: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000D538: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000D53C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000D540: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000D544: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000D548: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000D54C: beq         $s6, $zero, L_8000D98C
    if (ctx->r22 == 0) {
        // 0x8000D550: lui         $fp, 0x8008
        ctx->r30 = S32(0X8008 << 16);
            goto L_8000D98C;
    }
    // 0x8000D550: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x8000D554: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x8000D558: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x8000D55C: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000D560: addiu       $s3, $s3, 0x2C10
    ctx->r19 = ADD32(ctx->r19, 0X2C10);
    // 0x8000D564: addiu       $s4, $s4, 0x28FC
    ctx->r20 = ADD32(ctx->r20, 0X28FC);
    // 0x8000D568: addiu       $s5, $s5, 0x28E4
    ctx->r21 = ADD32(ctx->r21, 0X28E4);
    // 0x8000D56C: addiu       $fp, $fp, -0x4548
    ctx->r30 = ADD32(ctx->r30, -0X4548);
    // 0x8000D570: lhu         $t6, 0x0($s7)
    ctx->r14 = MEM_HU(ctx->r23, 0X0);
L_8000D574:
    // 0x8000D574: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000D578: lw          $t8, 0x4F24($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F24);
    // 0x8000D57C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D580: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000D584: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000D588: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x8000D58C: lhu         $t9, 0x16($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X16);
    // 0x8000D590: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // 0x8000D594: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x8000D598: beql        $t0, $zero, L_8000D614
    if (ctx->r8 == 0) {
        // 0x8000D59C: lhu         $a0, 0x16($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X16);
            goto L_8000D614;
    }
    goto skip_0;
    // 0x8000D59C: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    skip_0:
    // 0x8000D5A0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000D5A4: lwc1        $f6, 0x14($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X14);
    // 0x8000D5A8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D5AC: lwc1        $f10, 0x18($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X18);
    // 0x8000D5B0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000D5B4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000D5B8: lwc1        $f18, 0x1C($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X1C);
    // 0x8000D5BC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000D5C0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000D5C4: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000D5C8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000D5CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000D5D0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000D5D4: jal         0x80034F60
    // 0x8000D5D8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000D5D8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8000D5DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D5E0: lwc1        $f16, 0x4ED4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4ED4);
    // 0x8000D5E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D5E8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8000D5EC: nop

    // 0x8000D5F0: bc1fl       L_8000D614
    if (!c1cs) {
        // 0x8000D5F4: lhu         $a0, 0x16($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X16);
            goto L_8000D614;
    }
    goto skip_1;
    // 0x8000D5F4: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    skip_1:
    // 0x8000D5F8: swc1        $f0, 0x4ED4($at)
    MEM_W(0X4ED4, ctx->r1) = ctx->f0.u32l;
    // 0x8000D5FC: lhu         $t1, 0x16($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X16);
    // 0x8000D600: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D604: andi        $t2, $t1, 0xF00
    ctx->r10 = ctx->r9 & 0XF00;
    // 0x8000D608: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x8000D60C: sw          $t3, 0x4ED8($at)
    MEM_W(0X4ED8, ctx->r1) = ctx->r11;
    // 0x8000D610: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
L_8000D614:
    // 0x8000D614: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D618: andi        $t4, $a0, 0x2000
    ctx->r12 = ctx->r4 & 0X2000;
    // 0x8000D61C: beq         $t4, $zero, L_8000D62C
    if (ctx->r12 == 0) {
        // 0x8000D620: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8000D62C;
    }
    // 0x8000D620: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000D624: b           L_8000D634
    // 0x8000D628: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8000D634;
    // 0x8000D628: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000D62C:
    // 0x8000D62C: andi        $t5, $v1, 0xFF
    ctx->r13 = ctx->r3 & 0XFF;
    // 0x8000D630: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_8000D634:
    // 0x8000D634: beq         $v1, $zero, L_8000D644
    if (ctx->r3 == 0) {
        // 0x8000D638: andi        $t6, $a0, 0x4000
        ctx->r14 = ctx->r4 & 0X4000;
            goto L_8000D644;
    }
    // 0x8000D638: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x8000D63C: bne         $v1, $at, L_8000D6B0
    if (ctx->r3 != ctx->r1) {
        // 0x8000D640: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000D6B0;
    }
    // 0x8000D640: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000D644:
    // 0x8000D644: beq         $t6, $zero, L_8000D67C
    if (ctx->r14 == 0) {
        // 0x8000D648: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_8000D67C;
    }
    // 0x8000D648: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D64C: addiu       $v0, $v0, 0x28F4
    ctx->r2 = ADD32(ctx->r2, 0X28F4);
    // 0x8000D650: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000D654: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000D658: addiu       $v1, $v1, 0x28DC
    ctx->r3 = ADD32(ctx->r3, 0X28DC);
    // 0x8000D65C: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x8000D660: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000D664: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000D668: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8000D66C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000D670: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000D674: b           L_8000D980
    // 0x8000D678: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_8000D980;
    // 0x8000D678: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8000D67C:
    // 0x8000D67C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D680: addiu       $v0, $v0, 0x28F0
    ctx->r2 = ADD32(ctx->r2, 0X28F0);
    // 0x8000D684: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000D688: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000D68C: addiu       $v1, $v1, 0x28D8
    ctx->r3 = ADD32(ctx->r3, 0X28D8);
    // 0x8000D690: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
    // 0x8000D694: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8000D698: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8000D69C: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x8000D6A0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000D6A4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000D6A8: b           L_8000D980
    // 0x8000D6AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_8000D980;
    // 0x8000D6AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8000D6B0:
    // 0x8000D6B0: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8000D6B4: beq         $at, $zero, L_8000D7E4
    if (ctx->r1 == 0) {
        // 0x8000D6B8: lui         $t7, 0x8008
        ctx->r15 = S32(0X8008 << 16);
            goto L_8000D7E4;
    }
    // 0x8000D6B8: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8000D6BC: lw          $t7, 0x2908($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2908);
    // 0x8000D6C0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000D6C4: addiu       $t1, $t1, 0x2C70
    ctx->r9 = ADD32(ctx->r9, 0X2C70);
    // 0x8000D6C8: beq         $t7, $zero, L_8000D704
    if (ctx->r15 == 0) {
        // 0x8000D6CC: sll         $s1, $v1, 2
        ctx->r17 = S32(ctx->r3 << 2);
            goto L_8000D704;
    }
    // 0x8000D6CC: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x8000D6D0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8000D6D4: lw          $at, 0x0($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X0);
    // 0x8000D6D8: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x8000D6DC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8000D6E0: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x8000D6E4: lw          $at, 0x8($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X8);
    // 0x8000D6E8: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x8000D6EC: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8000D6F0: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x8000D6F4: lw          $at, 0x10($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X10);
    // 0x8000D6F8: sw          $at, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r1;
    // 0x8000D6FC: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x8000D700: sw          $t0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r8;
L_8000D704:
    // 0x8000D704: addu        $s2, $s1, $t1
    ctx->r18 = ADD32(ctx->r17, ctx->r9);
    // 0x8000D708: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x8000D70C: ori         $at, $zero, 0xA000
    ctx->r1 = 0 | 0XA000;
    // 0x8000D710: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8000D714: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x8000D718: jal         0x80035190
    // 0x8000D71C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_80035190(rdram, ctx);
        goto after_1;
    // 0x8000D71C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x8000D720: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8000D724: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000D728: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8000D72C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D730: lwc1        $f6, -0x3CCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CCC);
    // 0x8000D734: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8000D738: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8000D73C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000D740: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000D744: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x8000D748: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x8000D74C: addiu       $a0, $a0, 0x2000
    ctx->r4 = ADD32(ctx->r4, 0X2000);
    // 0x8000D750: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x8000D754: jal         0x80035190
    // 0x8000D758: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_80035190(rdram, ctx);
        goto after_2;
    // 0x8000D758: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_2:
    // 0x8000D75C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8000D760: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000D764: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8000D768: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D76C: lwc1        $f6, -0x3CAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CAC);
    // 0x8000D770: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8000D774: lwc1        $f10, 0x8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8000D778: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000D77C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000D780: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8000D784: jal         0x80035190
    // 0x8000D788: lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X2);
    func_80035190(rdram, ctx);
        goto after_3;
    // 0x8000D788: lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X2);
    after_3:
    // 0x8000D78C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8000D790: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000D794: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x8000D798: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000D79C: lwc1        $f6, -0x3CBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3CBC);
    // 0x8000D7A0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8000D7A4: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8000D7A8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000D7AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000D7B0: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8000D7B4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8000D7B8: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    // 0x8000D7BC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8000D7C0: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x8000D7C4: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8000D7C8: addiu       $t8, $t9, 0x4
    ctx->r24 = ADD32(ctx->r25, 0X4);
    // 0x8000D7CC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8000D7D0: addiu       $t3, $t2, 0x18
    ctx->r11 = ADD32(ctx->r10, 0X18);
    // 0x8000D7D4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8000D7D8: sw          $t1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r9;
    // 0x8000D7DC: b           L_8000D980
    // 0x8000D7E0: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
        goto L_8000D980;
    // 0x8000D7E0: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
L_8000D7E4:
    // 0x8000D7E4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8000D7E8: beq         $v0, $at, L_8000D7F8
    if (ctx->r2 == ctx->r1) {
        // 0x8000D7EC: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8000D7F8;
    }
    // 0x8000D7EC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8000D7F0: bnel        $v0, $at, L_8000D830
    if (ctx->r2 != ctx->r1) {
        // 0x8000D7F4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8000D830;
    }
    goto skip_2;
    // 0x8000D7F4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_2:
L_8000D7F8:
    // 0x8000D7F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D7FC: addiu       $v0, $v0, 0x2900
    ctx->r2 = ADD32(ctx->r2, 0X2900);
    // 0x8000D800: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8000D804: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000D808: addiu       $v1, $v1, 0x28E8
    ctx->r3 = ADD32(ctx->r3, 0X28E8);
    // 0x8000D80C: sw          $s0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r16;
    // 0x8000D810: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8000D814: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000D818: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8000D81C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000D820: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000D824: b           L_8000D980
    // 0x8000D828: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8000D980;
    // 0x8000D828: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8000D82C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_8000D830:
    // 0x8000D830: bnel        $v0, $at, L_8000D884
    if (ctx->r2 != ctx->r1) {
        // 0x8000D834: addiu       $at, $zero, 0x7F
        ctx->r1 = ADD32(0, 0X7F);
            goto L_8000D884;
    }
    goto skip_3;
    // 0x8000D834: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    skip_3:
    // 0x8000D838: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D83C: addiu       $v0, $v0, 0x28F8
    ctx->r2 = ADD32(ctx->r2, 0X28F8);
    // 0x8000D840: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000D844: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000D848: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000D84C: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x8000D850: addiu       $a0, $a0, 0x4F38
    ctx->r4 = ADD32(ctx->r4, 0X4F38);
    // 0x8000D854: addiu       $v1, $v1, 0x28E0
    ctx->r3 = ADD32(ctx->r3, 0X28E0);
    // 0x8000D858: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8000D85C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000D860: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8000D864: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8000D868: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000D86C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000D870: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8000D874: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8000D878: b           L_8000D980
    // 0x8000D87C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_8000D980;
    // 0x8000D87C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8000D880: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
L_8000D884:
    // 0x8000D884: beq         $v0, $at, L_8000D894
    if (ctx->r2 == ctx->r1) {
        // 0x8000D888: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8000D894;
    }
    // 0x8000D888: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8000D88C: bnel        $v0, $at, L_8000D8BC
    if (ctx->r2 != ctx->r1) {
        // 0x8000D890: addiu       $at, $zero, 0x81
        ctx->r1 = ADD32(0, 0X81);
            goto L_8000D8BC;
    }
    goto skip_4;
    // 0x8000D890: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    skip_4:
L_8000D894:
    // 0x8000D894: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8000D898: sw          $s0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r16;
    // 0x8000D89C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8000D8A0: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x8000D8A4: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x8000D8A8: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8000D8AC: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x8000D8B0: b           L_8000D980
    // 0x8000D8B4: sw          $t0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r8;
        goto L_8000D980;
    // 0x8000D8B4: sw          $t0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r8;
    // 0x8000D8B8: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
L_8000D8BC:
    // 0x8000D8BC: bne         $v0, $at, L_8000D8DC
    if (ctx->r2 != ctx->r1) {
        // 0x8000D8C0: or          $a3, $s0, $zero
        ctx->r7 = ctx->r16 | 0;
            goto L_8000D8DC;
    }
    // 0x8000D8C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8000D8C4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000D8C8: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D8CC: jal         0x80018918
    // 0x8000D8D0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_80018918(rdram, ctx);
        goto after_4;
    // 0x8000D8D0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_4:
    // 0x8000D8D4: b           L_8000D984
    // 0x8000D8D8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
        goto L_8000D984;
    // 0x8000D8D8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
L_8000D8DC:
    // 0x8000D8DC: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x8000D8E0: bnel        $v0, $at, L_8000D8FC
    if (ctx->r2 != ctx->r1) {
        // 0x8000D8E4: addiu       $at, $zero, 0x84
        ctx->r1 = ADD32(0, 0X84);
            goto L_8000D8FC;
    }
    goto skip_5;
    // 0x8000D8E4: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
    skip_5:
    // 0x8000D8E8: jal         0x8000E10C
    // 0x8000D8EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000E10C(rdram, ctx);
        goto after_5;
    // 0x8000D8EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8000D8F0: b           L_8000D984
    // 0x8000D8F4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
        goto L_8000D984;
    // 0x8000D8F4: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000D8F8: addiu       $at, $zero, 0x84
    ctx->r1 = ADD32(0, 0X84);
L_8000D8FC:
    // 0x8000D8FC: bnel        $v0, $at, L_8000D918
    if (ctx->r2 != ctx->r1) {
        // 0x8000D900: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_8000D918;
    }
    goto skip_6;
    // 0x8000D900: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    skip_6:
    // 0x8000D904: jal         0x8000E2C0
    // 0x8000D908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000E2C0(rdram, ctx);
        goto after_6;
    // 0x8000D908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8000D90C: b           L_8000D984
    // 0x8000D910: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
        goto L_8000D984;
    // 0x8000D910: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000D914: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
L_8000D918:
    // 0x8000D918: bnel        $v0, $at, L_8000D944
    if (ctx->r2 != ctx->r1) {
        // 0x8000D91C: slti        $at, $v0, 0x40
        ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
            goto L_8000D944;
    }
    goto skip_7;
    // 0x8000D91C: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    skip_7:
    // 0x8000D920: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000D924: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000D928: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8000D92C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8000D930: jal         0x8000E418
    // 0x8000D934: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8000E418(rdram, ctx);
        goto after_7;
    // 0x8000D934: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x8000D938: b           L_8000D984
    // 0x8000D93C: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
        goto L_8000D984;
    // 0x8000D93C: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000D940: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
L_8000D944:
    // 0x8000D944: bne         $at, $zero, L_8000D980
    if (ctx->r1 != 0) {
        // 0x8000D948: slti        $at, $v0, 0x46
        ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
            goto L_8000D980;
    }
    // 0x8000D948: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x8000D94C: beq         $at, $zero, L_8000D980
    if (ctx->r1 == 0) {
        // 0x8000D950: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_8000D980;
    }
    // 0x8000D950: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000D954: addiu       $v0, $v0, 0x2904
    ctx->r2 = ADD32(ctx->r2, 0X2904);
    // 0x8000D958: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8000D95C: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8000D960: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D964: sw          $s0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r16;
    // 0x8000D968: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000D96C: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8000D970: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000D974: lw          $t4, 0x28EC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X28EC);
    // 0x8000D978: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000D97C: sw          $t5, 0x28EC($at)
    MEM_W(0X28EC, ctx->r1) = ctx->r13;
L_8000D980:
    // 0x8000D980: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
L_8000D984:
    // 0x8000D984: bnel        $s6, $zero, L_8000D574
    if (ctx->r22 != 0) {
        // 0x8000D988: lhu         $t6, 0x0($s7)
        ctx->r14 = MEM_HU(ctx->r23, 0X0);
            goto L_8000D574;
    }
    goto skip_8;
    // 0x8000D988: lhu         $t6, 0x0($s7)
    ctx->r14 = MEM_HU(ctx->r23, 0X0);
    skip_8:
L_8000D98C:
    // 0x8000D98C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000D990: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000D994: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000D998: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000D99C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000D9A0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000D9A4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000D9A8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000D9AC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D9B0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000D9B4: jr          $ra
    // 0x8000D9B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000D9B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void count_digits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024330: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80024334: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x80024338: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8002433C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80024340: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80024344: andi        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 & 0X2;
    // 0x80024348: beq         $t7, $zero, L_80024360
    if (ctx->r15 == 0) {
        // 0x8002434C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80024360;
    }
    // 0x8002434C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80024350: addiu       $v1, $zero, 0x2710
    ctx->r3 = ADD32(0, 0X2710);
    // 0x80024354: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80024358: b           L_800243DC
    // 0x8002435C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
        goto L_800243DC;
    // 0x8002435C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_80024360:
    // 0x80024360: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x80024364: beq         $t8, $zero, L_8002437C
    if (ctx->r24 == 0) {
        // 0x80024368: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8002437C;
    }
    // 0x80024368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002436C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80024370: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80024374: b           L_800243DC
    // 0x80024378: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
        goto L_800243DC;
    // 0x80024378: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_8002437C:
    // 0x8002437C: slti        $at, $a3, 0xA
    ctx->r1 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x80024380: bne         $at, $zero, L_800243A4
    if (ctx->r1 != 0) {
        // 0x80024384: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800243A4;
    }
    // 0x80024384: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80024388: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_8002438C:
    // 0x8002438C: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024390: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024394: mflo        $v1
    ctx->r3 = lo;
    // 0x80024398: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002439C: beq         $at, $zero, L_8002438C
    if (ctx->r1 == 0) {
        // 0x800243A0: nop
    
            goto L_8002438C;
    }
    // 0x800243A0: nop

L_800243A4:
    // 0x800243A4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800243A8: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x800243AC: bne         $t2, $zero, L_800243B8
    if (ctx->r10 != 0) {
        // 0x800243B0: nop
    
            goto L_800243B8;
    }
    // 0x800243B0: nop

    // 0x800243B4: break       7
    do_break(2147632052);
L_800243B8:
    // 0x800243B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800243BC: bne         $t2, $at, L_800243D0
    if (ctx->r10 != ctx->r1) {
        // 0x800243C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800243D0;
    }
    // 0x800243C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800243C4: bne         $v1, $at, L_800243D0
    if (ctx->r3 != ctx->r1) {
        // 0x800243C8: nop
    
            goto L_800243D0;
    }
    // 0x800243C8: nop

    // 0x800243CC: break       6
    do_break(2147632076);
L_800243D0:
    // 0x800243D0: mflo        $v1
    ctx->r3 = lo;
    // 0x800243D4: nop

    // 0x800243D8: nop

L_800243DC:
    // 0x800243DC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800243E0: beq         $a0, $zero, L_80024624
    if (ctx->r4 == 0) {
        // 0x800243E4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80024624;
    }
    // 0x800243E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800243E8: andi        $t1, $a0, 0x3
    ctx->r9 = ctx->r4 & 0X3;
    // 0x800243EC: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x800243F0: beq         $t1, $zero, L_80024474
    if (ctx->r9 == 0) {
        // 0x800243F4: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_80024474;
    }
    // 0x800243F4: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x800243F8: addu        $t0, $t1, $a0
    ctx->r8 = ADD32(ctx->r9, ctx->r4);
L_800243FC:
    // 0x800243FC: div         $zero, $a3, $v1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r3)));
    // 0x80024400: bne         $v1, $zero, L_8002440C
    if (ctx->r3 != 0) {
        // 0x80024404: nop
    
            goto L_8002440C;
    }
    // 0x80024404: nop

    // 0x80024408: break       7
    do_break(2147632136);
L_8002440C:
    // 0x8002440C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024410: bne         $v1, $at, L_80024424
    if (ctx->r3 != ctx->r1) {
        // 0x80024414: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024424;
    }
    // 0x80024414: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024418: bne         $a3, $at, L_80024424
    if (ctx->r7 != ctx->r1) {
        // 0x8002441C: nop
    
            goto L_80024424;
    }
    // 0x8002441C: nop

    // 0x80024420: break       6
    do_break(2147632160);
L_80024424:
    // 0x80024424: mfhi        $a3
    ctx->r7 = hi;
    // 0x80024428: mflo        $t9
    ctx->r25 = lo;
    // 0x8002442C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80024430: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
    // 0x80024434: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x80024438: bne         $t2, $zero, L_80024444
    if (ctx->r10 != 0) {
        // 0x8002443C: nop
    
            goto L_80024444;
    }
    // 0x8002443C: nop

    // 0x80024440: break       7
    do_break(2147632192);
L_80024444:
    // 0x80024444: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024448: bne         $t2, $at, L_8002445C
    if (ctx->r10 != ctx->r1) {
        // 0x8002444C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002445C;
    }
    // 0x8002444C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024450: bne         $v1, $at, L_8002445C
    if (ctx->r3 != ctx->r1) {
        // 0x80024454: nop
    
            goto L_8002445C;
    }
    // 0x80024454: nop

    // 0x80024458: break       6
    do_break(2147632216);
L_8002445C:
    // 0x8002445C: mflo        $v1
    ctx->r3 = lo;
    // 0x80024460: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80024464: bne         $t0, $a2, L_800243FC
    if (ctx->r8 != ctx->r6) {
        // 0x80024468: nop
    
            goto L_800243FC;
    }
    // 0x80024468: nop

    // 0x8002446C: beql        $a2, $zero, L_80024628
    if (ctx->r6 == 0) {
        // 0x80024470: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_80024628;
    }
    goto skip_0;
    // 0x80024470: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    skip_0:
L_80024474:
    // 0x80024474: div         $zero, $a3, $v1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r3)));
    // 0x80024478: bne         $v1, $zero, L_80024484
    if (ctx->r3 != 0) {
        // 0x8002447C: nop
    
            goto L_80024484;
    }
    // 0x8002447C: nop

    // 0x80024480: break       7
    do_break(2147632256);
L_80024484:
    // 0x80024484: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024488: bne         $v1, $at, L_8002449C
    if (ctx->r3 != ctx->r1) {
        // 0x8002448C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002449C;
    }
    // 0x8002448C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024490: bne         $a3, $at, L_8002449C
    if (ctx->r7 != ctx->r1) {
        // 0x80024494: nop
    
            goto L_8002449C;
    }
    // 0x80024494: nop

    // 0x80024498: break       6
    do_break(2147632280);
L_8002449C:
    // 0x8002449C: mflo        $t3
    ctx->r11 = lo;
    // 0x800244A0: mfhi        $a3
    ctx->r7 = hi;
    // 0x800244A4: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800244A8: sb          $t3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r11;
    // 0x800244AC: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x800244B0: bne         $t2, $zero, L_800244BC
    if (ctx->r10 != 0) {
        // 0x800244B4: nop
    
            goto L_800244BC;
    }
    // 0x800244B4: nop

    // 0x800244B8: break       7
    do_break(2147632312);
L_800244BC:
    // 0x800244BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800244C0: bne         $t2, $at, L_800244D4
    if (ctx->r10 != ctx->r1) {
        // 0x800244C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800244D4;
    }
    // 0x800244C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800244C8: bne         $v1, $at, L_800244D4
    if (ctx->r3 != ctx->r1) {
        // 0x800244CC: nop
    
            goto L_800244D4;
    }
    // 0x800244CC: nop

    // 0x800244D0: break       6
    do_break(2147632336);
L_800244D4:
    // 0x800244D4: mflo        $v1
    ctx->r3 = lo;
    // 0x800244D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800244DC: nop

    // 0x800244E0: div         $zero, $a3, $v1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r3)));
    // 0x800244E4: bne         $v1, $zero, L_800244F0
    if (ctx->r3 != 0) {
        // 0x800244E8: nop
    
            goto L_800244F0;
    }
    // 0x800244E8: nop

    // 0x800244EC: break       7
    do_break(2147632364);
L_800244F0:
    // 0x800244F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800244F4: bne         $v1, $at, L_80024508
    if (ctx->r3 != ctx->r1) {
        // 0x800244F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024508;
    }
    // 0x800244F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800244FC: bne         $a3, $at, L_80024508
    if (ctx->r7 != ctx->r1) {
        // 0x80024500: nop
    
            goto L_80024508;
    }
    // 0x80024500: nop

    // 0x80024504: break       6
    do_break(2147632388);
L_80024508:
    // 0x80024508: mfhi        $a3
    ctx->r7 = hi;
    // 0x8002450C: mflo        $t4
    ctx->r12 = lo;
    // 0x80024510: sb          $t4, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r12;
    // 0x80024514: nop

    // 0x80024518: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x8002451C: bne         $t2, $zero, L_80024528
    if (ctx->r10 != 0) {
        // 0x80024520: nop
    
            goto L_80024528;
    }
    // 0x80024520: nop

    // 0x80024524: break       7
    do_break(2147632420);
L_80024528:
    // 0x80024528: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002452C: bne         $t2, $at, L_80024540
    if (ctx->r10 != ctx->r1) {
        // 0x80024530: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024540;
    }
    // 0x80024530: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024534: bne         $v1, $at, L_80024540
    if (ctx->r3 != ctx->r1) {
        // 0x80024538: nop
    
            goto L_80024540;
    }
    // 0x80024538: nop

    // 0x8002453C: break       6
    do_break(2147632444);
L_80024540:
    // 0x80024540: mflo        $v1
    ctx->r3 = lo;
    // 0x80024544: nop

    // 0x80024548: nop

    // 0x8002454C: div         $zero, $a3, $v1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r3)));
    // 0x80024550: bne         $v1, $zero, L_8002455C
    if (ctx->r3 != 0) {
        // 0x80024554: nop
    
            goto L_8002455C;
    }
    // 0x80024554: nop

    // 0x80024558: break       7
    do_break(2147632472);
L_8002455C:
    // 0x8002455C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024560: bne         $v1, $at, L_80024574
    if (ctx->r3 != ctx->r1) {
        // 0x80024564: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024574;
    }
    // 0x80024564: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024568: bne         $a3, $at, L_80024574
    if (ctx->r7 != ctx->r1) {
        // 0x8002456C: nop
    
            goto L_80024574;
    }
    // 0x8002456C: nop

    // 0x80024570: break       6
    do_break(2147632496);
L_80024574:
    // 0x80024574: mfhi        $a3
    ctx->r7 = hi;
    // 0x80024578: mflo        $t5
    ctx->r13 = lo;
    // 0x8002457C: sb          $t5, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r13;
    // 0x80024580: nop

    // 0x80024584: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x80024588: bne         $t2, $zero, L_80024594
    if (ctx->r10 != 0) {
        // 0x8002458C: nop
    
            goto L_80024594;
    }
    // 0x8002458C: nop

    // 0x80024590: break       7
    do_break(2147632528);
L_80024594:
    // 0x80024594: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024598: bne         $t2, $at, L_800245AC
    if (ctx->r10 != ctx->r1) {
        // 0x8002459C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800245AC;
    }
    // 0x8002459C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800245A0: bne         $v1, $at, L_800245AC
    if (ctx->r3 != ctx->r1) {
        // 0x800245A4: nop
    
            goto L_800245AC;
    }
    // 0x800245A4: nop

    // 0x800245A8: break       6
    do_break(2147632552);
L_800245AC:
    // 0x800245AC: mflo        $v1
    ctx->r3 = lo;
    // 0x800245B0: nop

    // 0x800245B4: nop

    // 0x800245B8: div         $zero, $a3, $v1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r3)));
    // 0x800245BC: bne         $v1, $zero, L_800245C8
    if (ctx->r3 != 0) {
        // 0x800245C0: nop
    
            goto L_800245C8;
    }
    // 0x800245C0: nop

    // 0x800245C4: break       7
    do_break(2147632580);
L_800245C8:
    // 0x800245C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800245CC: bne         $v1, $at, L_800245E0
    if (ctx->r3 != ctx->r1) {
        // 0x800245D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800245E0;
    }
    // 0x800245D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800245D4: bne         $a3, $at, L_800245E0
    if (ctx->r7 != ctx->r1) {
        // 0x800245D8: nop
    
            goto L_800245E0;
    }
    // 0x800245D8: nop

    // 0x800245DC: break       6
    do_break(2147632604);
L_800245E0:
    // 0x800245E0: mfhi        $a3
    ctx->r7 = hi;
    // 0x800245E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800245E8: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
    // 0x800245EC: nop

    // 0x800245F0: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x800245F4: bne         $t2, $zero, L_80024600
    if (ctx->r10 != 0) {
        // 0x800245F8: nop
    
            goto L_80024600;
    }
    // 0x800245F8: nop

    // 0x800245FC: break       7
    do_break(2147632636);
L_80024600:
    // 0x80024600: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024604: bne         $t2, $at, L_80024618
    if (ctx->r10 != ctx->r1) {
        // 0x80024608: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024618;
    }
    // 0x80024608: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002460C: bne         $v1, $at, L_80024618
    if (ctx->r3 != ctx->r1) {
        // 0x80024610: nop
    
            goto L_80024618;
    }
    // 0x80024610: nop

    // 0x80024614: break       6
    do_break(2147632660);
L_80024618:
    // 0x80024618: mflo        $v1
    ctx->r3 = lo;
    // 0x8002461C: bne         $a2, $zero, L_80024474
    if (ctx->r6 != 0) {
        // 0x80024620: nop
    
            goto L_80024474;
    }
    // 0x80024620: nop

L_80024624:
    // 0x80024624: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
L_80024628:
    // 0x80024628: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8002462C: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
    // 0x80024630: beq         $t8, $zero, L_80024678
    if (ctx->r24 == 0) {
        // 0x80024634: sb          $t7, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r15;
            goto L_80024678;
    }
    // 0x80024634: sb          $t7, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r15;
    // 0x80024638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002463C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80024640: beq         $a0, $zero, L_80024678
    if (ctx->r4 == 0) {
        // 0x80024644: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80024678;
    }
    // 0x80024644: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80024648: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x8002464C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
L_80024650:
    // 0x80024650: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80024654: bnel        $t9, $zero, L_80024668
    if (ctx->r25 != 0) {
        // 0x80024658: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80024668;
    }
    goto skip_1;
    // 0x80024658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8002465C: b           L_80024668
    // 0x80024660: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
        goto L_80024668;
    // 0x80024660: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x80024664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80024668:
    // 0x80024668: beq         $a2, $zero, L_80024678
    if (ctx->r6 == 0) {
        // 0x8002466C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80024678;
    }
    // 0x8002466C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80024670: bnel        $v0, $zero, L_80024650
    if (ctx->r2 != 0) {
        // 0x80024674: lbu         $t9, 0x0($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X0);
            goto L_80024650;
    }
    goto skip_2;
    // 0x80024674: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    skip_2:
L_80024678:
    // 0x80024678: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8002467C: jr          $ra
    // 0x80024680: nop

    return;
    // 0x80024680: nop

;}
RECOMP_FUNC void func_80019354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019354: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80019358: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8001935C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80019360: lw          $t6, 0x74E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X74E8);
    // 0x80019364: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80019368: addiu       $v0, $v0, 0x74E8
    ctx->r2 = ADD32(ctx->r2, 0X74E8);
    // 0x8001936C: beq         $t6, $zero, L_8001938C
    if (ctx->r14 == 0) {
        // 0x80019370: addiu       $v1, $zero, 0x7
        ctx->r3 = ADD32(0, 0X7);
            goto L_8001938C;
    }
    // 0x80019370: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80019374: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80019378:
    // 0x80019378: beq         $v1, $zero, L_8001938C
    if (ctx->r3 == 0) {
        // 0x8001937C: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_8001938C;
    }
    // 0x8001937C: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80019380: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80019384: bnel        $t7, $zero, L_80019378
    if (ctx->r15 != 0) {
        // 0x80019388: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80019378;
    }
    goto skip_0;
    // 0x80019388: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
L_8001938C:
    // 0x8001938C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80019390: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80019394: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x80019398: swc1        $f14, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f14.u32l;
    // 0x8001939C: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800193A0: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x800193A4: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800193A8: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x800193AC: jr          $ra
    // 0x800193B0: nop

    return;
    // 0x800193B0: nop

;}
RECOMP_FUNC void func_80008948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008948: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000894C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80008950: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80008954: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80008958: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8000895C: addiu       $t7, $t7, -0x42D0
    ctx->r15 = ADD32(ctx->r15, -0X42D0);
    // 0x80008960: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80008964: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80008968: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x8000896C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80008970: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80008974: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80008978: bnel        $t8, $at, L_800089A0
    if (ctx->r24 != ctx->r1) {
        // 0x8000897C: lbu         $t0, 0x5($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X5);
            goto L_800089A0;
    }
    goto skip_0;
    // 0x8000897C: lbu         $t0, 0x5($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5);
    skip_0:
    // 0x80008980: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80008984: jal         0x80022FD0
    // 0x80008988: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    get_rand(rdram, ctx);
        goto after_0;
    // 0x80008988: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000898C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80008990: addiu       $t9, $v0, 0x1E
    ctx->r25 = ADD32(ctx->r2, 0X1E);
    // 0x80008994: b           L_800089F0
    // 0x80008998: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
        goto L_800089F0;
    // 0x80008998: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x8000899C: lbu         $t0, 0x5($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5);
L_800089A0:
    // 0x800089A0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800089A4: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800089A8: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800089AC: beq         $t1, $zero, L_800089C8
    if (ctx->r9 == 0) {
        // 0x800089B0: addiu       $a0, $v1, 0x14
        ctx->r4 = ADD32(ctx->r3, 0X14);
            goto L_800089C8;
    }
    // 0x800089B0: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    // 0x800089B4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800089B8: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x800089BC: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x800089C0: b           L_800089F0
    // 0x800089C4: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
        goto L_800089F0;
    // 0x800089C4: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
L_800089C8:
    // 0x800089C8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800089CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800089D0: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x800089D4: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x800089D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800089DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800089E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800089E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800089E8: jal         0x8001D8B0
    // 0x800089EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x800089EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
L_800089F0:
    // 0x800089F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800089F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800089F8: jr          $ra
    // 0x800089FC: nop

    return;
    // 0x800089FC: nop

;}
RECOMP_FUNC void func_80031CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031CF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80031CF4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80031CF8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80031CFC: slti        $at, $a0, 0x3E8
    ctx->r1 = SIGNED(ctx->r4) < 0X3E8 ? 1 : 0;
    // 0x80031D00: bne         $at, $zero, L_80031D0C
    if (ctx->r1 != 0) {
        // 0x80031D04: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80031D0C;
    }
    // 0x80031D04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80031D08: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
L_80031D0C:
    // 0x80031D0C: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x80031D10: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80031D14: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80031D18: mflo        $t7
    ctx->r15 = lo;
    // 0x80031D1C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80031D20: slti        $t8, $v0, 0x64
    ctx->r24 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80031D24: bne         $v1, $zero, L_80031D30
    if (ctx->r3 != 0) {
        // 0x80031D28: nop
    
            goto L_80031D30;
    }
    // 0x80031D28: nop

    // 0x80031D2C: break       7
    do_break(2147687724);
L_80031D30:
    // 0x80031D30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031D34: bne         $v1, $at, L_80031D48
    if (ctx->r3 != ctx->r1) {
        // 0x80031D38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80031D48;
    }
    // 0x80031D38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80031D3C: bne         $v0, $at, L_80031D48
    if (ctx->r2 != ctx->r1) {
        // 0x80031D40: nop
    
            goto L_80031D48;
    }
    // 0x80031D40: nop

    // 0x80031D44: break       6
    do_break(2147687748);
L_80031D48:
    // 0x80031D48: div         $zero, $t1, $a0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r4)));
    // 0x80031D4C: mflo        $t2
    ctx->r10 = lo;
    // 0x80031D50: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80031D54: slti        $t3, $v0, 0xA
    ctx->r11 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80031D58: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80031D5C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80031D60: xori        $t3, $t3, 0x1
    ctx->r11 = ctx->r11 ^ 0X1;
    // 0x80031D64: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80031D68: mfhi        $t6
    ctx->r14 = hi;
    // 0x80031D6C: addiu       $t0, $t9, 0xF
    ctx->r8 = ADD32(ctx->r25, 0XF);
    // 0x80031D70: addiu       $t5, $t4, 0xF
    ctx->r13 = ADD32(ctx->r12, 0XF);
    // 0x80031D74: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x80031D78: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x80031D7C: bne         $a0, $zero, L_80031D88
    if (ctx->r4 != 0) {
        // 0x80031D80: nop
    
            goto L_80031D88;
    }
    // 0x80031D80: nop

    // 0x80031D84: break       7
    do_break(2147687812);
L_80031D88:
    // 0x80031D88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031D8C: bne         $a0, $at, L_80031DA0
    if (ctx->r4 != ctx->r1) {
        // 0x80031D90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80031DA0;
    }
    // 0x80031D90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80031D94: bne         $t1, $at, L_80031DA0
    if (ctx->r9 != ctx->r1) {
        // 0x80031D98: nop
    
            goto L_80031DA0;
    }
    // 0x80031D98: nop

    // 0x80031D9C: break       6
    do_break(2147687836);
L_80031DA0:
    // 0x80031DA0: sb          $t5, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r13;
    // 0x80031DA4: bne         $a0, $zero, L_80031DB0
    if (ctx->r4 != 0) {
        // 0x80031DA8: nop
    
            goto L_80031DB0;
    }
    // 0x80031DA8: nop

    // 0x80031DAC: break       7
    do_break(2147687852);
L_80031DB0:
    // 0x80031DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031DB4: bne         $a0, $at, L_80031DC8
    if (ctx->r4 != ctx->r1) {
        // 0x80031DB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80031DC8;
    }
    // 0x80031DB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80031DBC: bne         $v0, $at, L_80031DC8
    if (ctx->r2 != ctx->r1) {
        // 0x80031DC0: nop
    
            goto L_80031DC8;
    }
    // 0x80031DC0: nop

    // 0x80031DC4: break       6
    do_break(2147687876);
L_80031DC8:
    // 0x80031DC8: sb          $t7, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r15;
    // 0x80031DCC: jr          $ra
    // 0x80031DD0: nop

    return;
    // 0x80031DD0: nop

;}
RECOMP_FUNC void func_80039810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039810: lw          $a2, 0x44($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X44);
    // 0x80039814: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80039818: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003981C: blez        $a2, L_800398A0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80039820: addiu       $a3, $zero, 0x30
        ctx->r7 = ADD32(0, 0X30);
            goto L_800398A0;
    }
    // 0x80039820: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
L_80039824:
    // 0x80039824: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039828: mflo        $t6
    ctx->r14 = lo;
    // 0x8003982C: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x80039830: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80039834: bne         $t7, $zero, L_80039888
    if (ctx->r15 != 0) {
        // 0x80039838: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80039888;
    }
    // 0x80039838: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003983C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039840: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80039844: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80039848: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x8003984C: sh          $t8, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r24;
    // 0x80039850: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80039854: sb          $t9, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r25;
    // 0x80039858: sb          $zero, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = 0;
    // 0x8003985C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x80039860: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x80039864: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80039868: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8003986C: sll         $t1, $t0, 15
    ctx->r9 = S32(ctx->r8 << 15);
    // 0x80039870: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80039874: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80039878: mflo        $t2
    ctx->r10 = lo;
    // 0x8003987C: sh          $t2, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r10;
    // 0x80039880: jr          $ra
    // 0x80039884: nop

    return;
    // 0x80039884: nop

L_80039888:
    // 0x80039888: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003988C: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80039890: sra         $v1, $t3, 16
    ctx->r3 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80039894: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80039898: bne         $at, $zero, L_80039824
    if (ctx->r1 != 0) {
        // 0x8003989C: nop
    
            goto L_80039824;
    }
    // 0x8003989C: nop

L_800398A0:
    // 0x800398A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800398A4: jr          $ra
    // 0x800398A8: nop

    return;
    // 0x800398A8: nop

    // 0x800398AC: nop

;}
RECOMP_FUNC void func_8003FF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FF90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003FF94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003FF98: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8003FF9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003FFA0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003FFA4: jal         0x80034160
    // 0x8003FFA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8003FFA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8003FFAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8003FFB0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8003FFB4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8003FFB8: lw          $s0, 0x8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X8);
    // 0x8003FFBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003FFC0: beql        $s0, $zero, L_8003FFF8
    if (ctx->r16 == 0) {
        // 0x8003FFC4: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8003FFF8;
    }
    goto skip_0;
    // 0x8003FFC4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_0:
    // 0x8003FFC8: jal         0x80036820
    // 0x8003FFCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_1;
    // 0x8003FFCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003FFD0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8003FFD4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003FFD8: jal         0x80048A40
    // 0x8003FFDC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    alCopy(rdram, ctx);
        goto after_2;
    // 0x8003FFDC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
    // 0x8003FFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FFE4: jal         0x80036850
    // 0x8003FFE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80036850(rdram, ctx);
        goto after_3;
    // 0x8003FFE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8003FFEC: b           L_8003FFFC
    // 0x8003FFF0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
        goto L_8003FFFC;
    // 0x8003FFF0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x8003FFF4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8003FFF8:
    // 0x8003FFF8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_8003FFFC:
    // 0x8003FFFC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80040000: jal         0x80034160
    // 0x80040004: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_4;
    // 0x80040004: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x80040008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004000C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80040010: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80040014: jr          $ra
    // 0x80040018: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80040018: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800056D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800056D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800056D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800056D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800056DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800056E0: jal         0x80006720
    // 0x800056E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80006720(rdram, ctx);
        goto after_0;
    // 0x800056E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800056E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800056EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800056F0: lh          $t6, 0x52($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X52);
    // 0x800056F4: lw          $a2, 0x24($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X24);
    // 0x800056F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800056FC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80005700: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005704: jal         0x8001D924
    // 0x80005708: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_8001D924(rdram, ctx);
        goto after_1;
    // 0x80005708: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x8000570C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80005710: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80005714: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80005718: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8000571C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80005720: lwc1        $f8, 0x4C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80005724: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x80005728: jal         0x800232F4
    // 0x8000572C: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x8000572C: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    after_2:
    // 0x80005730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005738: jr          $ra
    // 0x8000573C: nop

    return;
    // 0x8000573C: nop

    // 0x80005740: jr          $ra
    // 0x80005744: nop

    return;
    // 0x80005744: nop

;}
