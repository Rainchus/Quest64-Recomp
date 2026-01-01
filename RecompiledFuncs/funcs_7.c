#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8000F5A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F5A4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000F5A8: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8000F5AC: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8000F5B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000F5B4: c.le.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl <= ctx->f14.fl;
    // 0x8000F5B8: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000F5BC: bc1fl       L_8000F5D8
    if (!c1cs) {
        // 0x8000F5C0: lwc1        $f0, 0x24($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8000F5D8;
    }
    goto skip_0;
    // 0x8000F5C0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000F5C4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8000F5C8: nop

    // 0x8000F5CC: bc1tl       L_8000F5FC
    if (c1cs) {
        // 0x8000F5D0: lwc1        $f4, 0x18($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8000F5FC;
    }
    goto skip_1;
    // 0x8000F5D0: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8000F5D4: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
L_8000F5D8:
    // 0x8000F5D8: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8000F5DC: nop

    // 0x8000F5E0: bc1fl       L_8000F698
    if (!c1cs) {
        // 0x8000F5E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000F698;
    }
    goto skip_2;
    // 0x8000F5E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8000F5E8: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8000F5EC: nop

    // 0x8000F5F0: bc1fl       L_8000F698
    if (!c1cs) {
        // 0x8000F5F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000F698;
    }
    goto skip_3;
    // 0x8000F5F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8000F5F8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
L_8000F5FC:
    // 0x8000F5FC: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000F600: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000F604: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8000F608: nop

    // 0x8000F60C: bc1fl       L_8000F630
    if (!c1cs) {
        // 0x8000F610: c.le.s      $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
            goto L_8000F630;
    }
    goto skip_4;
    // 0x8000F610: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    skip_4:
    // 0x8000F614: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8000F618: nop

    // 0x8000F61C: bc1fl       L_8000F630
    if (!c1cs) {
        // 0x8000F620: c.le.s      $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
            goto L_8000F630;
    }
    goto skip_5;
    // 0x8000F620: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    skip_5:
    // 0x8000F624: b           L_8000F698
    // 0x8000F628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F698;
    // 0x8000F628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F62C: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
L_8000F630:
    // 0x8000F630: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000F634: bc1fl       L_8000F658
    if (!c1cs) {
        // 0x8000F638: c.eq.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
            goto L_8000F658;
    }
    goto skip_6;
    // 0x8000F638: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    skip_6:
    // 0x8000F63C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8000F640: nop

    // 0x8000F644: bc1fl       L_8000F658
    if (!c1cs) {
        // 0x8000F648: c.eq.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
            goto L_8000F658;
    }
    goto skip_7;
    // 0x8000F648: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    skip_7:
    // 0x8000F64C: b           L_8000F698
    // 0x8000F650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F698;
    // 0x8000F650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000F654: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
L_8000F658:
    // 0x8000F658: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000F65C: bc1tl       L_8000F698
    if (c1cs) {
        // 0x8000F660: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000F698;
    }
    goto skip_8;
    // 0x8000F660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x8000F664: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8000F668: sub.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8000F66C: sub.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f20.fl;
    // 0x8000F670: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000F674: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8000F678: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000F67C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x8000F680: nop

    // 0x8000F684: bc1fl       L_8000F698
    if (!c1cs) {
        // 0x8000F688: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000F698;
    }
    goto skip_9;
    // 0x8000F688: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x8000F68C: b           L_8000F698
    // 0x8000F690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000F698;
    // 0x8000F690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000F694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F698:
    // 0x8000F698: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8000F69C: jr          $ra
    // 0x8000F6A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000F6A0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8002D748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D74C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D750: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002D754: lb          $t6, -0x2D6($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2D6);
    // 0x8002D758: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002D75C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002D760: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002D764: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8002D768: addiu       $t8, $t8, 0x4E0
    ctx->r24 = ADD32(ctx->r24, 0X4E0);
    // 0x8002D76C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002D770: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    // 0x8002D774: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002D778: lb          $a1, -0x2D0($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2D0);
    // 0x8002D77C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8002D780: jal         0x800319E0
    // 0x8002D784: addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    func_800319E0(rdram, ctx);
        goto after_0;
    // 0x8002D784: addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    after_0:
    // 0x8002D788: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002D78C: addiu       $t0, $t0, 0x4E0
    ctx->r8 = ADD32(ctx->r8, 0X4E0);
    // 0x8002D790: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002D794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002D798: addiu       $t9, $t9, 0x398
    ctx->r25 = ADD32(ctx->r25, 0X398);
    // 0x8002D79C: addiu       $t3, $t0, 0xC0
    ctx->r11 = ADD32(ctx->r8, 0XC0);
L_8002D7A0:
    // 0x8002D7A0: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x8002D7A4: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x8002D7A8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8002D7AC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8002D7B0: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x8002D7B4: lwl         $at, -0x8($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, -0X8);
    // 0x8002D7B8: lwr         $at, -0x5($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, -0X5);
    // 0x8002D7BC: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x8002D7C0: lwl         $at, -0x4($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, -0X4);
    // 0x8002D7C4: lwr         $at, -0x1($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, -0X1);
    // 0x8002D7C8: bne         $t0, $t3, L_8002D7A0
    if (ctx->r8 != ctx->r11) {
        // 0x8002D7CC: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_8002D7A0;
    }
    // 0x8002D7CC: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x8002D7D0: lwl         $at, 0x0($t0)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r8, 0X0);
    // 0x8002D7D4: lwr         $at, 0x3($t0)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r8, 0X3);
    // 0x8002D7D8: lwl         $t3, 0x4($t0)
    ctx->r11 = do_lwl(rdram, ctx->r11, ctx->r8, 0X4);
    // 0x8002D7DC: lwr         $t3, 0x7($t0)
    ctx->r11 = do_lwr(rdram, ctx->r11, ctx->r8, 0X7);
    // 0x8002D7E0: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8002D7E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D7E8: beq         $v0, $zero, L_8002D884
    if (ctx->r2 == 0) {
        // 0x8002D7EC: sw          $t3, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r11;
            goto L_8002D884;
    }
    // 0x8002D7EC: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8002D7F0: jal         0x80031BB0
    // 0x8002D7F4: sw          $a0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r4;
    func_80031BB0(rdram, ctx);
        goto after_1;
    // 0x8002D7F4: sw          $a0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r4;
    after_1:
    // 0x8002D7F8: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8002D7FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D800: beq         $v1, $at, L_8002D830
    if (ctx->r3 == ctx->r1) {
        // 0x8002D804: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002D830;
    }
    // 0x8002D804: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D808: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002D80C: beq         $v1, $at, L_8002D84C
    if (ctx->r3 == ctx->r1) {
        // 0x8002D810: addiu       $t8, $zero, 0xB
        ctx->r24 = ADD32(0, 0XB);
            goto L_8002D84C;
    }
    // 0x8002D810: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8002D814: addiu       $t4, $zero, 0x11
    ctx->r12 = ADD32(0, 0X11);
    // 0x8002D818: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D81C: sb          $t4, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r12;
    // 0x8002D820: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D824: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8002D828: b           L_8002D860
    // 0x8002D82C: sb          $t5, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r13;
        goto L_8002D860;
    // 0x8002D82C: sb          $t5, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r13;
L_8002D830:
    // 0x8002D830: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8002D834: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D838: sb          $t6, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r14;
    // 0x8002D83C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D840: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8002D844: b           L_8002D860
    // 0x8002D848: sb          $t7, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r15;
        goto L_8002D860;
    // 0x8002D848: sb          $t7, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r15;
L_8002D84C:
    // 0x8002D84C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D850: sb          $t8, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r24;
    // 0x8002D854: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002D858: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002D85C: sb          $t2, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r10;
L_8002D860:
    // 0x8002D860: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D864: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D868: andi        $t0, $t1, 0xFFF8
    ctx->r8 = ctx->r9 & 0XFFF8;
    // 0x8002D86C: ori         $t4, $t0, 0x5
    ctx->r12 = ctx->r8 | 0X5;
    // 0x8002D870: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x8002D874: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x8002D878: andi        $t5, $t4, 0xDFFF
    ctx->r13 = ctx->r12 & 0XDFFF;
    // 0x8002D87C: b           L_8002D8AC
    // 0x8002D880: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
        goto L_8002D8AC;
    // 0x8002D880: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
L_8002D884:
    // 0x8002D884: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002D888: jal         0x8002E404
    // 0x8002D88C: lb          $a0, -0x2D6($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X2D6);
    func_8002E404(rdram, ctx);
        goto after_2;
    // 0x8002D88C: lb          $a0, -0x2D6($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X2D6);
    after_2:
    // 0x8002D890: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002D894: addiu       $v0, $v0, -0x2E0
    ctx->r2 = ADD32(ctx->r2, -0X2E0);
    // 0x8002D898: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8002D89C: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x8002D8A0: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x8002D8A4: ori         $t2, $t8, 0x8000
    ctx->r10 = ctx->r24 | 0X8000;
    // 0x8002D8A8: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
L_8002D8AC:
    // 0x8002D8AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D8B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002D8B4: jr          $ra
    // 0x8002D8B8: nop

    return;
    // 0x8002D8B8: nop

;}
RECOMP_FUNC void func_800256D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800256D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800256D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800256DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800256E0: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800256E4: lw          $t6, -0x974($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X974);
    // 0x800256E8: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800256EC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800256F0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800256F4: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    // 0x800256F8: jal         0x800398B0
    // 0x800256FC: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398B0(rdram, ctx);
        goto after_0;
    // 0x800256FC: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_0:
    // 0x80025700: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025704: jal         0x800398D0
    // 0x80025708: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398D0(rdram, ctx);
        goto after_1;
    // 0x80025708: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_1:
    // 0x8002570C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025714: jr          $ra
    // 0x80025718: nop

    return;
    // 0x80025718: nop

;}
RECOMP_FUNC void func_80049BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049BA8: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x80049BAC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80049BB0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80049BB4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80049BB8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80049BBC: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x80049BC0: bne         $at, $zero, L_80049BD0
    if (ctx->r1 != 0) {
        // 0x80049BC4: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_80049BD0;
    }
    // 0x80049BC4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80049BC8: b           L_80049BE8
    // 0x80049BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80049BE8;
    // 0x80049BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80049BD0:
    // 0x80049BD0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80049BD4: jal         0x80049778
    // 0x80049BD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80049778(rdram, ctx);
        goto after_0;
    // 0x80049BD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80049BDC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80049BE0: sw          $a3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r7;
    // 0x80049BE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80049BE8:
    // 0x80049BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049BF0: jr          $ra
    // 0x80049BF4: nop

    return;
    // 0x80049BF4: nop

;}
RECOMP_FUNC void alAuxBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004012C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80040130: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80040134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040138: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8004013C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80040140: addiu       $a1, $a1, 0x2500
    ctx->r5 = ADD32(ctx->r5, 0X2500);
    // 0x80040144: addiu       $a2, $a2, 0x24D0
    ctx->r6 = ADD32(ctx->r6, 0X24D0);
    // 0x80040148: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004014C: jal         0x80048AC0
    // 0x80040150: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x80040150: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80040154: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80040158: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8004015C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80040160: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80040164: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80040168: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8004016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040174: jr          $ra
    // 0x80040178: nop

    return;
    // 0x80040178: nop

;}
RECOMP_FUNC void func_80003A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003A1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80003A20: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80003A24: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80003A28: addiu       $t2, $t2, -0x4594
    ctx->r10 = ADD32(ctx->r10, -0X4594);
    // 0x80003A2C: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80003A30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80003A34: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80003A38: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003A3C: sw          $zero, -0x4598($at)
    MEM_W(-0X4598, ctx->r1) = 0;
    // 0x80003A40: lw          $t0, 0x78($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X78);
    // 0x80003A44: lh          $t7, 0x64($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X64);
    // 0x80003A48: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80003A4C: lhu         $t9, 0xC($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0XC);
    // 0x80003A50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80003A54: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80003A58: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80003A5C: lw          $t1, 0x3D00($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3D00);
    // 0x80003A60: bgez        $t9, L_80003A78
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80003A64: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80003A78;
    }
    // 0x80003A64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80003A68: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80003A6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80003A70: nop

    // 0x80003A74: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80003A78:
    // 0x80003A78: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80003A7C: ldc1        $f16, 0xF40($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0XF40);
    // 0x80003A80: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80003A84: lui         $at, 0x4031
    ctx->r1 = S32(0X4031 << 16);
    // 0x80003A88: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80003A8C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80003A90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80003A94: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80003A98: sh          $zero, 0x80($v0)
    MEM_H(0X80, ctx->r2) = 0;
    // 0x80003A9C: sh          $zero, 0x10C($v0)
    MEM_H(0X10C, ctx->r2) = 0;
    // 0x80003AA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003AA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80003AA8: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x80003AAC: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80003AB0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003AB4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80003AB8: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80003ABC: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80003AC0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80003AC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80003AC8: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x80003ACC: lbu         $t4, 0x24($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X24);
    // 0x80003AD0: lbu         $t3, 0x27($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X27);
    // 0x80003AD4: lbu         $t6, 0x25($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X25);
    // 0x80003AD8: lbu         $t8, 0x26($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X26);
    // 0x80003ADC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80003AE0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80003AE4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80003AE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80003AEC: sh          $t9, 0x104($v0)
    MEM_H(0X104, ctx->r2) = ctx->r25;
    // 0x80003AF0: sh          $t3, 0x10A($v0)
    MEM_H(0X10A, ctx->r2) = ctx->r11;
    // 0x80003AF4: lhu         $t4, 0xC($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0XC);
    // 0x80003AF8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80003AFC: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x80003B00: sh          $t4, 0x106($v0)
    MEM_H(0X106, ctx->r2) = ctx->r12;
    // 0x80003B04: lhu         $t5, 0xE($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0XE);
    // 0x80003B08: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80003B0C: swc1        $f10, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f10.u32l;
    // 0x80003B10: sh          $t5, 0x108($v0)
    MEM_H(0X108, ctx->r2) = ctx->r13;
    // 0x80003B14: lh          $t7, 0xDA($t1)
    ctx->r15 = MEM_H(ctx->r9, 0XDA);
    // 0x80003B18: lhu         $t3, 0x74($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X74);
    // 0x80003B1C: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80003B20: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x80003B24: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80003B28: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x80003B2C: sh          $t4, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r12;
    // 0x80003B30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80003B34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003B38: swc1        $f16, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f16.u32l;
    // 0x80003B3C: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x80003B40: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x80003B44: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80003B48: jal         0x8001D8B0
    // 0x80003B4C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8001D8B0(rdram, ctx);
        goto after_0;
    // 0x80003B4C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_0:
    // 0x80003B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80003B54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80003B58: jr          $ra
    // 0x80003B5C: nop

    return;
    // 0x80003B5C: nop

;}
RECOMP_FUNC void func_80010510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010510: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80010514: addiu       $a1, $a1, 0x59D0
    ctx->r5 = ADD32(ctx->r5, 0X59D0);
    // 0x80010518: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x8001051C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80010520: lw          $v1, 0x59D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X59D4);
    // 0x80010524: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80010528: addiu       $a2, $a2, 0x59E0
    ctx->r6 = ADD32(ctx->r6, 0X59E0);
    // 0x8001052C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010530: bne         $at, $zero, L_80010550
    if (ctx->r1 != 0) {
        // 0x80010534: subu        $t6, $a0, $v1
        ctx->r14 = SUB32(ctx->r4, ctx->r3);
            goto L_80010550;
    }
    // 0x80010534: subu        $t6, $a0, $v1
    ctx->r14 = SUB32(ctx->r4, ctx->r3);
    // 0x80010538: lhu         $a0, 0x0($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X0);
    // 0x8001053C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80010540: slti        $at, $a0, 0x270F
    ctx->r1 = SIGNED(ctx->r4) < 0X270F ? 1 : 0;
    // 0x80010544: beq         $at, $zero, L_80010550
    if (ctx->r1 == 0) {
        // 0x80010548: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_80010550;
    }
    // 0x80010548: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8001054C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_80010550:
    // 0x80010550: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80010554: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010558: sw          $t8, 0x59D8($at)
    MEM_W(0X59D8, ctx->r1) = ctx->r24;
    // 0x8001055C: jr          $ra
    // 0x80010560: nop

    return;
    // 0x80010560: nop

;}
RECOMP_FUNC void func_80002F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002F60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80002F64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002F68: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80002F6C: lh          $t6, -0x44E4($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X44E4);
    // 0x80002F70: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80002F74: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80002F78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80002F7C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80002F80: lw          $t8, 0x3D00($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3D00);
    // 0x80002F84: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
    // 0x80002F88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80002F8C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80002F90: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x80002F94: lhu         $t3, 0x6($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X6);
    // 0x80002F98: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80002F9C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80002FA0: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80002FA4: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80002FA8: beq         $at, $zero, L_80002FC0
    if (ctx->r1 == 0) {
        // 0x80002FAC: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_80002FC0;
    }
    // 0x80002FAC: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80002FB0: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    // 0x80002FB4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002FB8: b           L_80002FE8
    // 0x80002FBC: sw          $t4, -0x43D4($at)
    MEM_W(-0X43D4, ctx->r1) = ctx->r12;
        goto L_80002FE8;
    // 0x80002FBC: sw          $t4, -0x43D4($at)
    MEM_W(-0X43D4, ctx->r1) = ctx->r12;
L_80002FC0:
    // 0x80002FC0: lhu         $t5, -0x3A6E($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X3A6E);
    // 0x80002FC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002FC8: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x80002FCC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80002FD0: beq         $t6, $zero, L_80002FE4
    if (ctx->r14 == 0) {
        // 0x80002FD4: nop
    
            goto L_80002FE4;
    }
    // 0x80002FD4: nop

    // 0x80002FD8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002FDC: b           L_80002FE8
    // 0x80002FE0: sw          $t7, -0x43D4($at)
    MEM_W(-0X43D4, ctx->r1) = ctx->r15;
        goto L_80002FE8;
    // 0x80002FE0: sw          $t7, -0x43D4($at)
    MEM_W(-0X43D4, ctx->r1) = ctx->r15;
L_80002FE4:
    // 0x80002FE4: sw          $zero, -0x43D4($at)
    MEM_W(-0X43D4, ctx->r1) = 0;
L_80002FE8:
    // 0x80002FE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002FEC: swc1        $f4, -0x45A8($at)
    MEM_W(-0X45A8, ctx->r1) = ctx->f4.u32l;
    // 0x80002FF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002FF4: addiu       $t1, $t1, -0x4D1C
    ctx->r9 = ADD32(ctx->r9, -0X4D1C);
    // 0x80002FF8: swc1        $f4, -0x45AC($at)
    MEM_W(-0X45AC, ctx->r1) = ctx->f4.u32l;
    // 0x80002FFC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80003000: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80003004: andi        $t9, $t8, 0x87
    ctx->r25 = ctx->r24 & 0X87;
    // 0x80003008: bne         $t9, $zero, L_8000312C
    if (ctx->r25 != 0) {
        // 0x8000300C: nop
    
            goto L_8000312C;
    }
    // 0x8000300C: nop

    // 0x80003010: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x80003014: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80003018: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x8000301C: beq         $t2, $zero, L_80003058
    if (ctx->r10 == 0) {
        // 0x80003020: andi        $t3, $v0, 0x2
        ctx->r11 = ctx->r2 & 0X2;
            goto L_80003058;
    }
    // 0x80003020: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x80003024: bne         $t3, $zero, L_80003050
    if (ctx->r11 != 0) {
        // 0x80003028: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_80003050;
    }
    // 0x80003028: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000302C: lhu         $t0, -0x44D4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44D4);
    // 0x80003030: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003034: andi        $t4, $t0, 0x1
    ctx->r12 = ctx->r8 & 0X1;
    // 0x80003038: bne         $t4, $zero, L_80003050
    if (ctx->r12 != 0) {
        // 0x8000303C: nop
    
            goto L_80003050;
    }
    // 0x8000303C: nop

    // 0x80003040: jal         0x80006774
    // 0x80003044: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_80006774(rdram, ctx);
        goto after_0;
    // 0x80003044: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_0:
    // 0x80003048: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000304C: sh          $v0, -0x4546($at)
    MEM_H(-0X4546, ctx->r1) = ctx->r2;
L_80003050:
    // 0x80003050: b           L_8000312C
    // 0x80003054: nop

        goto L_8000312C;
    // 0x80003054: nop

L_80003058:
    // 0x80003058: lhu         $t0, -0x44D4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44D4);
    // 0x8000305C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003060: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    // 0x80003064: andi        $t5, $t0, 0x1
    ctx->r13 = ctx->r8 & 0X1;
    // 0x80003068: bne         $t5, $zero, L_8000312C
    if (ctx->r13 != 0) {
        // 0x8000306C: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_8000312C;
    }
    // 0x8000306C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003070: jal         0x80005A10
    // 0x80003074: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    func_80005A10(rdram, ctx);
        goto after_1;
    // 0x80003074: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    after_1:
    // 0x80003078: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000307C: sw          $v0, -0x458C($at)
    MEM_W(-0X458C, ctx->r1) = ctx->r2;
    // 0x80003080: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80003084: lw          $t6, -0x458C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X458C);
    // 0x80003088: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000308C: bne         $t6, $zero, L_8000312C
    if (ctx->r14 != 0) {
        // 0x80003090: nop
    
            goto L_8000312C;
    }
    // 0x80003090: nop

    // 0x80003094: jal         0x80012358
    // 0x80003098: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_80012358(rdram, ctx);
        goto after_2;
    // 0x80003098: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_2:
    // 0x8000309C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800030A0: sw          $v0, -0x4588($at)
    MEM_W(-0X4588, ctx->r1) = ctx->r2;
    // 0x800030A4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800030A8: lw          $t7, -0x4588($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4588);
    // 0x800030AC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800030B0: bne         $t7, $zero, L_8000312C
    if (ctx->r15 != 0) {
        // 0x800030B4: nop
    
            goto L_8000312C;
    }
    // 0x800030B4: nop

    // 0x800030B8: jal         0x80011E78
    // 0x800030BC: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_80011E78(rdram, ctx);
        goto after_3;
    // 0x800030BC: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_3:
    // 0x800030C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800030C4: sw          $v0, -0x4584($at)
    MEM_W(-0X4584, ctx->r1) = ctx->r2;
    // 0x800030C8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800030CC: lw          $t8, -0x4584($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4584);
    // 0x800030D0: bne         $t8, $zero, L_8000312C
    if (ctx->r24 != 0) {
        // 0x800030D4: nop
    
            goto L_8000312C;
    }
    // 0x800030D4: nop

    // 0x800030D8: jal         0x8000B740
    // 0x800030DC: nop

    func_8000B740(rdram, ctx);
        goto after_4;
    // 0x800030DC: nop

    after_4:
    // 0x800030E0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800030E4: addiu       $a0, $a0, -0x43E0
    ctx->r4 = ADD32(ctx->r4, -0X43E0);
    // 0x800030E8: beq         $v0, $zero, L_8000312C
    if (ctx->r2 == 0) {
        // 0x800030EC: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_8000312C;
    }
    // 0x800030EC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800030F0: jal         0x8000BA4C
    // 0x800030F4: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    func_8000BA4C(rdram, ctx);
        goto after_5;
    // 0x800030F4: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    after_5:
    // 0x800030F8: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800030FC: lw          $t2, -0x4D1C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4D1C);
    // 0x80003100: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80003104: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003108: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8000310C: lhu         $t4, -0x4540($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X4540);
    // 0x80003110: sw          $t9, -0x43DC($at)
    MEM_W(-0X43DC, ctx->r1) = ctx->r25;
    // 0x80003114: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003118: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8000311C: sw          $t3, -0x4D1C($at)
    MEM_W(-0X4D1C, ctx->r1) = ctx->r11;
    // 0x80003120: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003124: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80003128: sh          $t5, -0x4540($at)
    MEM_H(-0X4540, ctx->r1) = ctx->r13;
L_8000312C:
    // 0x8000312C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80003130: addiu       $t1, $t1, -0x4D1C
    ctx->r9 = ADD32(ctx->r9, -0X4D1C);
    // 0x80003134: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80003138: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000313C: lhu         $t0, -0x44D4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44D4);
    // 0x80003140: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x80003144: bne         $t6, $zero, L_800035B0
    if (ctx->r14 != 0) {
        // 0x80003148: andi        $t3, $v1, 0x4
        ctx->r11 = ctx->r3 & 0X4;
            goto L_800035B0;
    }
    // 0x80003148: andi        $t3, $v1, 0x4
    ctx->r11 = ctx->r3 & 0X4;
    // 0x8000314C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80003150: lhu         $t7, 0x2876($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X2876);
    // 0x80003154: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003158: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    // 0x8000315C: andi        $t8, $t7, 0xA000
    ctx->r24 = ctx->r15 & 0XA000;
    // 0x80003160: beq         $t8, $zero, L_800034E4
    if (ctx->r24 == 0) {
        // 0x80003164: lui         $a1, 0x8008
        ctx->r5 = S32(0X8008 << 16);
            goto L_800034E4;
    }
    // 0x80003164: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003168: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8000316C: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x80003170: andi        $a0, $t0, 0x1
    ctx->r4 = ctx->r8 & 0X1;
    // 0x80003174: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80003178: beq         $t9, $zero, L_800031F0
    if (ctx->r25 == 0) {
        // 0x8000317C: nop
    
            goto L_800031F0;
    }
    // 0x8000317C: nop

    // 0x80003180: bne         $a0, $zero, L_800031F0
    if (ctx->r4 != 0) {
        // 0x80003184: andi        $t2, $v0, 0x2
        ctx->r10 = ctx->r2 & 0X2;
            goto L_800031F0;
    }
    // 0x80003184: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x80003188: bne         $t2, $zero, L_8000363C
    if (ctx->r10 != 0) {
        // 0x8000318C: nop
    
            goto L_8000363C;
    }
    // 0x8000318C: nop

    // 0x80003190: jal         0x80015B50
    // 0x80003194: nop

    func_80015B50(rdram, ctx);
        goto after_6;
    // 0x80003194: nop

    after_6:
    // 0x80003198: bne         $v0, $zero, L_8000363C
    if (ctx->r2 != 0) {
        // 0x8000319C: lui         $t3, 0x8008
        ctx->r11 = S32(0X8008 << 16);
            goto L_8000363C;
    }
    // 0x8000319C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800031A0: lhu         $t3, -0x4546($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4546);
    // 0x800031A4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800031A8: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x800031AC: beq         $t3, $zero, L_800031CC
    if (ctx->r11 == 0) {
        // 0x800031B0: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_800031CC;
    }
    // 0x800031B0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800031B4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800031B8: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    // 0x800031BC: jal         0x800069FC
    // 0x800031C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800069FC(rdram, ctx);
        goto after_7;
    // 0x800031C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x800031C4: b           L_8000363C
    // 0x800031C8: nop

        goto L_8000363C;
    // 0x800031C8: nop

L_800031CC:
    // 0x800031CC: jal         0x800073CC
    // 0x800031D0: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    func_800073CC(rdram, ctx);
        goto after_8;
    // 0x800031D0: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    after_8:
    // 0x800031D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800031D8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800031DC: sh          $zero, -0x4546($at)
    MEM_H(-0X4546, ctx->r1) = 0;
    // 0x800031E0: jal         0x8001D358
    // 0x800031E4: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_8001D358(rdram, ctx);
        goto after_9;
    // 0x800031E4: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_9:
    // 0x800031E8: b           L_8000363C
    // 0x800031EC: nop

        goto L_8000363C;
    // 0x800031EC: nop

L_800031F0:
    // 0x800031F0: bne         $a0, $zero, L_8000363C
    if (ctx->r4 != 0) {
        // 0x800031F4: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_8000363C;
    }
    // 0x800031F4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800031F8: addiu       $t0, $t0, -0x458C
    ctx->r8 = ADD32(ctx->r8, -0X458C);
    // 0x800031FC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80003200: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80003204: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003208: beq         $v0, $zero, L_800032BC
    if (ctx->r2 == 0) {
        // 0x8000320C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800032BC;
    }
    // 0x8000320C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80003210: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80003214: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80003218: sh          $t5, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r13;
    // 0x8000321C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003220: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80003224: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80003228: swc1        $f6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->f6.u32l;
    // 0x8000322C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003230: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003234: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80003238: lw          $a1, -0x43D4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X43D4);
    // 0x8000323C: swc1        $f8, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->f8.u32l;
    // 0x80003240: swc1        $f10, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->f10.u32l;
    // 0x80003244: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003248: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000324C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003250: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80003254: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80003258: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000325C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80003260: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80003264: swc1        $f16, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = ctx->f16.u32l;
    // 0x80003268: jal         0x8001D8B0
    // 0x8000326C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_10;
    // 0x8000326C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_10:
    // 0x80003270: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003274: jal         0x800086E4
    // 0x80003278: lw          $a0, -0x458C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X458C);
    func_800086E4(rdram, ctx);
        goto after_11;
    // 0x80003278: lw          $a0, -0x458C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X458C);
    after_11:
    // 0x8000327C: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80003280: lw          $t8, -0x39BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X39BC);
    // 0x80003284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80003288: slti        $at, $t8, 0x46
    ctx->r1 = SIGNED(ctx->r24) < 0X46 ? 1 : 0;
    // 0x8000328C: beq         $at, $zero, L_8000329C
    if (ctx->r1 == 0) {
        // 0x80003290: nop
    
            goto L_8000329C;
    }
    // 0x80003290: nop

    // 0x80003294: b           L_8000329C
    // 0x80003298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8000329C;
    // 0x80003298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000329C:
    // 0x8000329C: jal         0x8002E768
    // 0x800032A0: nop

    func_8002E768(rdram, ctx);
        goto after_12;
    // 0x800032A0: nop

    after_12:
    // 0x800032A4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800032A8: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x800032AC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800032B0: ori         $t2, $t9, 0x2
    ctx->r10 = ctx->r25 | 0X2;
    // 0x800032B4: b           L_8000363C
    // 0x800032B8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_8000363C;
    // 0x800032B8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_800032BC:
    // 0x800032BC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800032C0: addiu       $a1, $a1, -0x4588
    ctx->r5 = ADD32(ctx->r5, -0X4588);
    // 0x800032C4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800032C8: beq         $t3, $zero, L_80003354
    if (ctx->r11 == 0) {
        // 0x800032CC: lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
            goto L_80003354;
    }
    // 0x800032CC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800032D0: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
    // 0x800032D4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800032D8: ori         $t8, $v1, 0x8
    ctx->r24 = ctx->r3 | 0X8;
    // 0x800032DC: lbu         $t4, 0x24($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X24);
    // 0x800032E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800032E4: addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    // 0x800032E8: bnel        $a0, $t4, L_80003318
    if (ctx->r4 != ctx->r12) {
        // 0x800032EC: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80003318;
    }
    goto skip_0;
    // 0x800032EC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    skip_0:
    // 0x800032F0: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x800032F4: bnel        $a0, $t5, L_80003318
    if (ctx->r4 != ctx->r13) {
        // 0x800032F8: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80003318;
    }
    goto skip_1;
    // 0x800032F8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    skip_1:
    // 0x800032FC: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x80003300: bnel        $a0, $t6, L_80003318
    if (ctx->r4 != ctx->r14) {
        // 0x80003304: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_80003318;
    }
    goto skip_2;
    // 0x80003304: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    skip_2:
    // 0x80003308: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x8000330C: beq         $a0, $t7, L_8000363C
    if (ctx->r4 == ctx->r15) {
        // 0x80003310: nop
    
            goto L_8000363C;
    }
    // 0x80003310: nop

    // 0x80003314: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_80003318:
    // 0x80003318: sh          $zero, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = 0;
    // 0x8000331C: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80003320: jal         0x80012740
    // 0x80003324: lbu         $a0, 0x14($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X14);
    func_80012740(rdram, ctx);
        goto after_13;
    // 0x80003324: lbu         $a0, 0x14($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X14);
    after_13:
    // 0x80003328: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000332C: lw          $v0, -0x4588($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4588);
    // 0x80003330: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003334: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80003338: lhu         $t2, 0x10($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X10);
    // 0x8000333C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80003340: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80003344: jal         0x800268D4
    // 0x80003348: sh          $t3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r11;
    func_800268D4(rdram, ctx);
        goto after_14;
    // 0x80003348: sh          $t3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r11;
    after_14:
    // 0x8000334C: b           L_8000363C
    // 0x80003350: nop

        goto L_8000363C;
    // 0x80003350: nop

L_80003354:
    // 0x80003354: jal         0x80021214
    // 0x80003358: nop

    func_80021214(rdram, ctx);
        goto after_15;
    // 0x80003358: nop

    after_15:
    // 0x8000335C: beq         $v0, $zero, L_8000345C
    if (ctx->r2 == 0) {
        // 0x80003360: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8000345C;
    }
    // 0x80003360: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003364: lw          $a0, -0x4584($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4584);
    // 0x80003368: beq         $a0, $zero, L_8000345C
    if (ctx->r4 == 0) {
        // 0x8000336C: nop
    
            goto L_8000345C;
    }
    // 0x8000336C: nop

    // 0x80003370: jal         0x8001205C
    // 0x80003374: nop

    func_8001205C(rdram, ctx);
        goto after_16;
    // 0x80003374: nop

    after_16:
    // 0x80003378: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000337C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80003380: addiu       $a1, $a3, -0x43D0
    ctx->r5 = ADD32(ctx->r7, -0X43D0);
    // 0x80003384: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003388: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8000338C: lwc1        $f4, -0x4510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80003390: lui         $at, 0x432B
    ctx->r1 = S32(0X432B << 16);
    // 0x80003394: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80003398: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8000339C: lw          $t4, -0x4584($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4584);
    // 0x800033A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800033A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800033A8: swc1        $f8, -0x43CC($at)
    MEM_W(-0X43CC, ctx->r1) = ctx->f8.u32l;
    // 0x800033AC: jal         0x800232F4
    // 0x800033B0: lwc1        $f12, 0x10($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_17;
    // 0x800033B0: lwc1        $f12, 0x10($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X10);
    after_17:
    // 0x800033B4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800033B8: addiu       $v0, $v0, -0x4584
    ctx->r2 = ADD32(ctx->r2, -0X4584);
    // 0x800033BC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800033C0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800033C4: addiu       $a3, $a3, -0x43D0
    ctx->r7 = ADD32(ctx->r7, -0X43D0);
    // 0x800033C8: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800033CC: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800033D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800033D4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800033D8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800033DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800033E0: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x800033E4: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    // 0x800033E8: swc1        $f18, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f18.u32l;
    // 0x800033EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800033F0: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800033F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800033F8: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800033FC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80003400: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80003404: swc1        $f8, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->f8.u32l;
    // 0x80003408: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000340C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003410: lwc1        $f10, 0x10($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80003414: swc1        $f10, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->f10.u32l;
    // 0x80003418: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000341C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80003420: ldc1        $f4, 0xF30($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0XF30);
    // 0x80003424: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80003428: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000342C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80003430: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80003434: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80003438: swc1        $f8, -0x4414($at)
    MEM_W(-0X4414, ctx->r1) = ctx->f8.u32l;
    // 0x8000343C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80003440: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003444: lh          $t2, 0x50($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X50);
    // 0x80003448: jal         0x80006604
    // 0x8000344C: sb          $t2, -0x4430($at)
    MEM_B(-0X4430, ctx->r1) = ctx->r10;
    func_80006604(rdram, ctx);
        goto after_18;
    // 0x8000344C: sb          $t2, -0x4430($at)
    MEM_B(-0X4430, ctx->r1) = ctx->r10;
    after_18:
    // 0x80003450: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003454: b           L_8000363C
    // 0x80003458: sw          $zero, -0x4584($at)
    MEM_W(-0X4584, ctx->r1) = 0;
        goto L_8000363C;
    // 0x80003458: sw          $zero, -0x4584($at)
    MEM_W(-0X4584, ctx->r1) = 0;
L_8000345C:
    // 0x8000345C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80003460: lhu         $t0, -0x44D4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44D4);
    // 0x80003464: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003468: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8000346C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80003470: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80003474: sh          $t3, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r11;
    // 0x80003478: sh          $t4, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r12;
    // 0x8000347C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003480: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80003484: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80003488: swc1        $f10, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->f10.u32l;
    // 0x8000348C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003490: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80003494: swc1        $f16, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->f16.u32l;
    // 0x80003498: swc1        $f18, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->f18.u32l;
    // 0x8000349C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800034A0: swc1        $f4, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = ctx->f4.u32l;
    // 0x800034A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800034A8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800034AC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800034B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800034B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800034B8: ori         $t6, $t0, 0x1
    ctx->r14 = ctx->r8 | 0X1;
    // 0x800034BC: sh          $t6, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r14;
    // 0x800034C0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800034C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800034C8: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x800034CC: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x800034D0: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x800034D4: jal         0x8001D8B0
    // 0x800034D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_19;
    // 0x800034D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x800034DC: b           L_8000363C
    // 0x800034E0: nop

        goto L_8000363C;
    // 0x800034E0: nop

L_800034E4:
    // 0x800034E4: jal         0x80007030
    // 0x800034E8: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    func_80007030(rdram, ctx);
        goto after_20;
    // 0x800034E8: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    after_20:
    // 0x800034EC: beq         $v0, $zero, L_8000363C
    if (ctx->r2 == 0) {
        // 0x800034F0: lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
            goto L_8000363C;
    }
    // 0x800034F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800034F4: lw          $v1, -0x4D1C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4D1C);
    // 0x800034F8: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x800034FC: andi        $t9, $v1, 0x4
    ctx->r25 = ctx->r3 & 0X4;
    // 0x80003500: bnel        $t9, $zero, L_80003564
    if (ctx->r25 != 0) {
        // 0x80003504: andi        $t7, $v1, 0x1
        ctx->r15 = ctx->r3 & 0X1;
            goto L_80003564;
    }
    goto skip_3;
    // 0x80003504: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    skip_3:
    // 0x80003508: lhu         $t2, 0x2876($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X2876);
    // 0x8000350C: xori        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 ^ 0X1;
    // 0x80003510: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003514: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80003518: beq         $t3, $zero, L_80003560
    if (ctx->r11 == 0) {
        // 0x8000351C: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80003560;
    }
    // 0x8000351C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80003520: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80003524: sw          $t4, -0x4D1C($at)
    MEM_W(-0X4D1C, ctx->r1) = ctx->r12;
    // 0x80003528: addiu       $a2, $a2, -0x2AD0
    ctx->r6 = ADD32(ctx->r6, -0X2AD0);
    // 0x8000352C: jal         0x80022B08
    // 0x80003530: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80022B08(rdram, ctx);
        goto after_21;
    // 0x80003530: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x80003534: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80003538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000353C: jal         0x800268D4
    // 0x80003540: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_22;
    // 0x80003540: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_22:
    // 0x80003544: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80003548: lhu         $t0, -0x44D4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44D4);
    // 0x8000354C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80003550: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003554: ori         $t6, $t0, 0x1
    ctx->r14 = ctx->r8 | 0X1;
    // 0x80003558: sh          $t6, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r14;
    // 0x8000355C: lw          $v1, -0x4D1C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4D1C);
L_80003560:
    // 0x80003560: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
L_80003564:
    // 0x80003564: bne         $t7, $zero, L_8000363C
    if (ctx->r15 != 0) {
        // 0x80003568: lui         $t8, 0x8008
        ctx->r24 = S32(0X8008 << 16);
            goto L_8000363C;
    }
    // 0x80003568: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000356C: lw          $t8, -0x44CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44CC);
    // 0x80003570: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003574: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80003578: andi        $t2, $t9, 0x40
    ctx->r10 = ctx->r25 & 0X40;
    // 0x8000357C: bne         $t2, $zero, L_8000363C
    if (ctx->r10 != 0) {
        // 0x80003580: nop
    
            goto L_8000363C;
    }
    // 0x80003580: nop

    // 0x80003584: jal         0x800070C0
    // 0x80003588: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    func_800070C0(rdram, ctx);
        goto after_23;
    // 0x80003588: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    after_23:
    // 0x8000358C: beq         $v0, $zero, L_8000363C
    if (ctx->r2 == 0) {
        // 0x80003590: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8000363C;
    }
    // 0x80003590: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003594: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003598: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x8000359C: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    // 0x800035A0: jal         0x800072A8
    // 0x800035A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800072A8(rdram, ctx);
        goto after_24;
    // 0x800035A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_24:
    // 0x800035A8: b           L_8000363C
    // 0x800035AC: nop

        goto L_8000363C;
    // 0x800035AC: nop

L_800035B0:
    // 0x800035B0: beq         $t3, $zero, L_800035E8
    if (ctx->r11 == 0) {
        // 0x800035B4: andi        $t4, $v1, 0x1
        ctx->r12 = ctx->r3 & 0X1;
            goto L_800035E8;
    }
    // 0x800035B4: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x800035B8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800035BC: jal         0x800070C0
    // 0x800035C0: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    func_800070C0(rdram, ctx);
        goto after_25;
    // 0x800035C0: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    after_25:
    // 0x800035C4: beq         $v0, $zero, L_8000363C
    if (ctx->r2 == 0) {
        // 0x800035C8: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8000363C;
    }
    // 0x800035C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800035CC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800035D0: addiu       $a1, $a1, -0x4534
    ctx->r5 = ADD32(ctx->r5, -0X4534);
    // 0x800035D4: addiu       $a0, $a0, -0x4548
    ctx->r4 = ADD32(ctx->r4, -0X4548);
    // 0x800035D8: jal         0x800072A8
    // 0x800035DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800072A8(rdram, ctx);
        goto after_26;
    // 0x800035DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_26:
    // 0x800035E0: b           L_8000363C
    // 0x800035E4: nop

        goto L_8000363C;
    // 0x800035E4: nop

L_800035E8:
    // 0x800035E8: beq         $t4, $zero, L_8000363C
    if (ctx->r12 == 0) {
        // 0x800035EC: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_8000363C;
    }
    // 0x800035EC: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800035F0: lhu         $t5, 0x2876($t5)
    ctx->r13 = MEM_HU(ctx->r13, 0X2876);
    // 0x800035F4: xori        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 ^ 0X1;
    // 0x800035F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800035FC: andi        $t6, $t5, 0x4010
    ctx->r14 = ctx->r13 & 0X4010;
    // 0x80003600: beq         $t6, $zero, L_8000363C
    if (ctx->r14 == 0) {
        // 0x80003604: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8000363C;
    }
    // 0x80003604: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80003608: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8000360C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80003610: jal         0x80022B08
    // 0x80003614: addiu       $a2, $a2, -0x2ABC
    ctx->r6 = ADD32(ctx->r6, -0X2ABC);
    func_80022B08(rdram, ctx);
        goto after_27;
    // 0x80003614: addiu       $a2, $a2, -0x2ABC
    ctx->r6 = ADD32(ctx->r6, -0X2ABC);
    after_27:
    // 0x80003618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000361C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80003620: jal         0x800268D4
    // 0x80003624: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_28;
    // 0x80003624: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_28:
    // 0x80003628: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000362C: lhu         $t0, -0x44D4($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X44D4);
    // 0x80003630: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003634: andi        $t9, $t0, 0xFFFE
    ctx->r25 = ctx->r8 & 0XFFFE;
    // 0x80003638: sh          $t9, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r25;
L_8000363C:
    // 0x8000363C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80003640: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x80003644: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80003648: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8000364C: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x80003650: beq         $t2, $zero, L_80003760
    if (ctx->r10 == 0) {
        // 0x80003654: andi        $t5, $v0, 0x10
        ctx->r13 = ctx->r2 & 0X10;
            goto L_80003760;
    }
    // 0x80003654: andi        $t5, $v0, 0x10
    ctx->r13 = ctx->r2 & 0X10;
    // 0x80003658: lw          $t4, -0x44D0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X44D0);
    // 0x8000365C: andi        $t3, $v0, 0xFFF7
    ctx->r11 = ctx->r2 & 0XFFF7;
    // 0x80003660: sh          $t3, -0x3A6E($at)
    MEM_H(-0X3A6E, ctx->r1) = ctx->r11;
    // 0x80003664: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80003668: lw          $t6, -0x4598($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4598);
    // 0x8000366C: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80003670: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80003674: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80003678: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8000367C: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
    // 0x80003680: lw          $t8, -0x44D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44D0);
    // 0x80003684: lw          $t2, -0x4594($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4594);
    // 0x80003688: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000368C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80003690: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80003694: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80003698: sw          $t3, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r11;
    // 0x8000369C: lw          $v1, -0x4590($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4590);
    // 0x800036A0: beq         $v1, $at, L_800036C0
    if (ctx->r3 == ctx->r1) {
        // 0x800036A4: nop
    
            goto L_800036C0;
    }
    // 0x800036A4: nop

    // 0x800036A8: jal         0x80021240
    // 0x800036AC: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    func_80021240(rdram, ctx);
        goto after_29;
    // 0x800036AC: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    after_29:
    // 0x800036B0: beq         $v0, $zero, L_800036C0
    if (ctx->r2 == 0) {
        // 0x800036B4: addiu       $t5, $zero, 0xFF
        ctx->r13 = ADD32(0, 0XFF);
            goto L_800036C0;
    }
    // 0x800036B4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x800036B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800036BC: sw          $t5, -0x4590($at)
    MEM_W(-0X4590, ctx->r1) = ctx->r13;
L_800036C0:
    // 0x800036C0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800036C4: jal         0x800202E4
    // 0x800036C8: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_800202E4(rdram, ctx);
        goto after_30;
    // 0x800036C8: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_30:
    // 0x800036CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800036D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800036D4: sh          $zero, -0x44C8($at)
    MEM_H(-0X44C8, ctx->r1) = 0;
    // 0x800036D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800036DC: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x800036E0: sh          $t6, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r14;
    // 0x800036E4: lh          $t4, 0xC2($t7)
    ctx->r12 = MEM_H(ctx->r15, 0XC2);
    // 0x800036E8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800036EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800036F0: sh          $t4, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r12;
    // 0x800036F4: lhu         $t9, -0x44D4($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X44D4);
    // 0x800036F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800036FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80003700: ori         $t2, $t9, 0x1
    ctx->r10 = ctx->r25 | 0X1;
    // 0x80003704: sh          $t2, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r10;
    // 0x80003708: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000370C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80003710: swc1        $f6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->f6.u32l;
    // 0x80003714: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003718: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000371C: swc1        $f8, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->f8.u32l;
    // 0x80003720: swc1        $f10, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->f10.u32l;
    // 0x80003724: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003728: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000372C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80003730: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80003734: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80003738: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8000373C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80003740: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x80003744: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80003748: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8000374C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80003750: jal         0x8001D8B0
    // 0x80003754: swc1        $f16, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = ctx->f16.u32l;
    func_8001D8B0(rdram, ctx);
        goto after_31;
    // 0x80003754: swc1        $f16, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = ctx->f16.u32l;
    after_31:
    // 0x80003758: b           L_80003778
    // 0x8000375C: nop

        goto L_80003778;
    // 0x8000375C: nop

L_80003760:
    // 0x80003760: beq         $t5, $zero, L_80003778
    if (ctx->r13 == 0) {
        // 0x80003764: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80003778;
    }
    // 0x80003764: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003768: jal         0x800202E4
    // 0x8000376C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    func_800202E4(rdram, ctx);
        goto after_32;
    // 0x8000376C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    after_32:
    // 0x80003770: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80003774: sh          $zero, -0x44C8($at)
    MEM_H(-0X44C8, ctx->r1) = 0;
L_80003778:
    // 0x80003778: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000377C: lhu         $t6, -0x4548($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4548);
    // 0x80003780: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80003784: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80003788: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000378C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80003790: lw          $t9, -0x3DD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3DD0);
    // 0x80003794: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80003798: addiu       $a1, $a1, -0x4548
    ctx->r5 = ADD32(ctx->r5, -0X4548);
    // 0x8000379C: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x800037A0: jalr        $t9
    // 0x800037A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_33;
    // 0x800037A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_33:
    // 0x800037A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800037AC: lwc1        $f2, -0x45AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X45AC);
    // 0x800037B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800037B4: lwc1        $f0, -0x45A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X45A8);
    // 0x800037B8: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800037BC: nop

    // 0x800037C0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800037C4: jal         0x80034F60
    // 0x800037C8: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_34;
    // 0x800037C8: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_34:
    // 0x800037CC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800037D0: addiu       $v1, $v1, -0x45A4
    ctx->r3 = ADD32(ctx->r3, -0X45A4);
    // 0x800037D4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800037D8: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x800037DC: lhu         $t4, -0x3A6E($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X3A6E);
    // 0x800037E0: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800037E4: andi        $t2, $t4, 0x1
    ctx->r10 = ctx->r12 & 0X1;
    // 0x800037E8: bnel        $t2, $zero, L_80003864
    if (ctx->r10 != 0) {
        // 0x800037EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80003864;
    }
    goto skip_4;
    // 0x800037EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800037F0: lw          $t3, -0x44D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X44D0);
    // 0x800037F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800037F8: addiu       $v0, $v0, -0x43F4
    ctx->r2 = ADD32(ctx->r2, -0X43F4);
    // 0x800037FC: lhu         $t8, 0x8($t3)
    ctx->r24 = MEM_HU(ctx->r11, 0X8);
    // 0x80003800: lhu         $t5, 0xA($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0XA);
    // 0x80003804: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80003808: beql        $at, $zero, L_80003864
    if (ctx->r1 == 0) {
        // 0x8000380C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80003864;
    }
    goto skip_5;
    // 0x8000380C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80003810: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80003814: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80003818: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000381C: ldc1        $f2, 0xF38($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0XF38);
    // 0x80003820: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80003824: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80003828: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000382C: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80003830: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80003834: nop

    // 0x80003838: bc1fl       L_80003864
    if (!c1cs) {
        // 0x8000383C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80003864;
    }
    goto skip_6;
    // 0x8000383C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80003840: sub.d       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f0.d - ctx->f2.d;
    // 0x80003844: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80003848: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8000384C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80003850: lw          $t6, -0x44D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X44D0);
    // 0x80003854: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x80003858: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8000385C: sh          $t9, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r25;
    // 0x80003860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80003864:
    // 0x80003864: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80003868: jr          $ra
    // 0x8000386C: nop

    return;
    // 0x8000386C: nop

;}
RECOMP_FUNC void func_80101854_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101854: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101858: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8010185C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80101860: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x80101864: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101868: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8010186C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80101870: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x80101874: bltzl       $t9, L_80101888
    if (SIGNED(ctx->r25) < 0) {
        // 0x80101878: lw          $v1, 0x38($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X38);
            goto L_80101888;
    }
    goto skip_0;
    // 0x80101878: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
    skip_0:
    // 0x8010187C: jr          $ra
    // 0x80101880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80101880: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101884: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
L_80101888:
    // 0x80101888: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8010188C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80101890: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80101894: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80101898: lhu         $t0, 0x32($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X32);
    // 0x8010189C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801018A0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801018A4: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801018A8: sh          $t1, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r9;
    // 0x801018AC: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801018B0: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x801018B4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801018B8: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x801018BC: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801018C0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x801018C4: nop

    // 0x801018C8: bc1tl       L_801018DC
    if (c1cs) {
        // 0x801018CC: swc1        $f12, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
            goto L_801018DC;
    }
    goto skip_1;
    // 0x801018CC: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
    skip_1:
    // 0x801018D0: bne         $at, $zero, L_801018E0
    if (ctx->r1 != 0) {
        // 0x801018D4: nop
    
            goto L_801018E0;
    }
    // 0x801018D4: nop

    // 0x801018D8: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
L_801018DC:
    // 0x801018DC: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
L_801018E0:
    // 0x801018E0: bnel        $a1, $zero, L_801018FC
    if (ctx->r5 != 0) {
        // 0x801018E4: sub.s       $f18, $f12, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_801018FC;
    }
    goto skip_2;
    // 0x801018E4: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
    // 0x801018E8: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801018EC: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x801018F0: b           L_8010190C
    // 0x801018F4: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
        goto L_8010190C;
    // 0x801018F4: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
    // 0x801018F8: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
L_801018FC:
    // 0x801018FC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80101900: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80101904: nop

    // 0x80101908: sh          $t6, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r14;
L_8010190C:
    // 0x8010190C: lhu         $t7, 0x32($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X32);
    // 0x80101910: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
    // 0x80101914: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80101918: bnel        $at, $zero, L_80101950
    if (ctx->r1 != 0) {
        // 0x8010191C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80101950;
    }
    goto skip_3;
    // 0x8010191C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80101920: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80101924: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x80101928: bne         $a1, $zero, L_80101940
    if (ctx->r5 != 0) {
        // 0x8010192C: swc1        $f6, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
            goto L_80101940;
    }
    // 0x8010192C: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80101930: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80101934: sh          $t9, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r25;
    // 0x80101938: jr          $ra
    // 0x8010193C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x8010193C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101940:
    // 0x80101940: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
    // 0x80101944: jr          $ra
    // 0x80101948: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101948: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8010194C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101950:
    // 0x80101950: jr          $ra
    // 0x80101954: nop

    return;
    // 0x80101954: nop

;}
RECOMP_FUNC void func_8002568C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002568C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025694: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80025698: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002569C: lw          $t6, -0x974($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X974);
    // 0x800256A0: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800256A4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800256A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800256AC: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    // 0x800256B0: jal         0x800398B0
    // 0x800256B4: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398B0(rdram, ctx);
        goto after_0;
    // 0x800256B4: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_0:
    // 0x800256B8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800256BC: jal         0x80039960
    // 0x800256C0: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    alSndpStop(rdram, ctx);
        goto after_1;
    // 0x800256C0: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_1:
    // 0x800256C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800256C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800256CC: jr          $ra
    // 0x800256D0: nop

    return;
    // 0x800256D0: nop

;}
RECOMP_FUNC void UpdateBGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800267B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800267BC: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800267C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800267C4: addiu       $v0, $v0, -0x33F
    ctx->r2 = ADD32(ctx->r2, -0X33F);
    // 0x800267C8: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800267CC: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x800267D0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800267D4: addiu       $v1, $v1, -0x33E
    ctx->r3 = ADD32(ctx->r3, -0X33E);
    // 0x800267D8: beq         $a0, $t8, L_800267F0
    if (ctx->r4 == ctx->r24) {
        // 0x800267DC: nop
    
            goto L_800267F0;
    }
    // 0x800267DC: nop

    // 0x800267E0: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x800267E4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800267E8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800267EC: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
L_800267F0:
    // 0x800267F0: jr          $ra
    // 0x800267F4: nop

    return;
    // 0x800267F4: nop

;}
RECOMP_FUNC void func_80018524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018524: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80018528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001852C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80018530: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80018534: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80018538: addiu       $t6, $t6, -0x3204
    ctx->r14 = ADD32(ctx->r14, -0X3204);
    // 0x8001853C: addiu       $t9, $t6, 0x30
    ctx->r25 = ADD32(ctx->r14, 0X30);
    // 0x80018540: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_80018544:
    // 0x80018544: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80018548: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8001854C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80018550: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x80018554: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80018558: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8001855C: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x80018560: bne         $t6, $t9, L_80018544
    if (ctx->r14 != ctx->r25) {
        // 0x80018564: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_80018544;
    }
    // 0x80018564: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x80018568: lw          $t1, 0x24($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X24);
    // 0x8001856C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80018570: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80018574: beq         $a1, $t1, L_800185AC
    if (ctx->r5 == ctx->r9) {
        // 0x80018578: sll         $t0, $t6, 2
        ctx->r8 = S32(ctx->r14 << 2);
            goto L_800185AC;
    }
    // 0x80018578: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8001857C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80018580: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80018584: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80018588: jal         0x80022FD0
    // 0x8001858C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    get_rand(rdram, ctx);
        goto after_0;
    // 0x8001858C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80018590: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80018594: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80018598: addiu       $t5, $v0, 0x2
    ctx->r13 = ADD32(ctx->r2, 0X2);
    // 0x8001859C: lw          $t8, 0x68($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X68);
    // 0x800185A0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800185A4: b           L_800185D4
    // 0x800185A8: sb          $t5, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r13;
        goto L_800185D4;
    // 0x800185A8: sb          $t5, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r13;
L_800185AC:
    // 0x800185AC: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x800185B0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x800185B4: jal         0x80022FD0
    // 0x800185B8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    get_rand(rdram, ctx);
        goto after_1;
    // 0x800185B8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800185BC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800185C0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800185C4: addiu       $t2, $v0, 0x3
    ctx->r10 = ADD32(ctx->r2, 0X3);
    // 0x800185C8: lw          $t3, 0x68($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X68);
    // 0x800185CC: addu        $t8, $t3, $t4
    ctx->r24 = ADD32(ctx->r11, ctx->r12);
    // 0x800185D0: sb          $t2, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r10;
L_800185D4:
    // 0x800185D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800185D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800185DC: jr          $ra
    // 0x800185E0: nop

    return;
    // 0x800185E0: nop

    // 0x800185E4: nop

    // 0x800185E8: nop

    // 0x800185EC: nop

;}
RECOMP_FUNC void func_8000111C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000111C: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80001120: addiu       $v0, $v0, -0x6110
    ctx->r2 = ADD32(ctx->r2, -0X6110);
    // 0x80001124: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80001128: addiu       $t7, $t7, -0x6040
    ctx->r15 = ADD32(ctx->r15, -0X6040);
    // 0x8000112C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80001130: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80001134: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80001138: addiu       $t9, $t9, -0x6040
    ctx->r25 = ADD32(ctx->r25, -0X6040);
    // 0x8000113C: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80001140: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x80001144: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80001148: addiu       $t0, $t0, 0x23D0
    ctx->r8 = ADD32(ctx->r8, 0X23D0);
    // 0x8000114C: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x80001150: sw          $t0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r8;
    // 0x80001154: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x80001158: lui         $t2, 0x8030
    ctx->r10 = S32(0X8030 << 16);
    // 0x8000115C: lui         $t4, 0x8032
    ctx->r12 = S32(0X8032 << 16);
    // 0x80001160: lui         $t5, 0x8032
    ctx->r13 = S32(0X8032 << 16);
    // 0x80001164: lui         $t6, 0x8030
    ctx->r14 = S32(0X8030 << 16);
    // 0x80001168: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000116C: ori         $at, $zero, 0xD148
    ctx->r1 = 0 | 0XD148;
    // 0x80001170: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x80001174: addiu       $t2, $t2, 0x0
    ctx->r10 = ADD32(ctx->r10, 0X0);
    // 0x80001178: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x8000117C: addiu       $t4, $t4, -0x4D60
    ctx->r12 = ADD32(ctx->r12, -0X4D60);
    // 0x80001180: addiu       $t5, $t5, 0x32A0
    ctx->r13 = ADD32(ctx->r13, 0X32A0);
    // 0x80001184: addiu       $t6, $t6, 0x400
    ctx->r14 = ADD32(ctx->r14, 0X400);
    // 0x80001188: addiu       $t7, $zero, 0xC00
    ctx->r15 = ADD32(0, 0XC00);
    // 0x8000118C: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80001190: addiu       $t9, $t9, -0x4618
    ctx->r25 = ADD32(ctx->r25, -0X4618);
    // 0x80001194: addu        $t0, $a0, $at
    ctx->r8 = ADD32(ctx->r4, ctx->r1);
    // 0x80001198: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8000119C: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800011A0: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
    // 0x800011A4: sw          $t3, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r11;
    // 0x800011A8: sw          $t4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r12;
    // 0x800011AC: sw          $t5, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r13;
    // 0x800011B0: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    // 0x800011B4: sw          $t7, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r15;
    // 0x800011B8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800011BC: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800011C0: sw          $t9, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r25;
    // 0x800011C4: sw          $t0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r8;
    // 0x800011C8: addiu       $t1, $a0, 0x7FFF
    ctx->r9 = ADD32(ctx->r4, 0X7FFF);
    // 0x800011CC: lw          $t1, 0x514D($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X514D);
    // 0x800011D0: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x800011D4: jr          $ra
    // 0x800011D8: nop

    return;
    // 0x800011D8: nop

;}
RECOMP_FUNC void func_80016FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016FFC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80017000: sw          $t6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r14;
    // 0x80017004: jr          $ra
    // 0x80017008: nop

    return;
    // 0x80017008: nop

;}
RECOMP_FUNC void func_80101040_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101040: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101044: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101048: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8010104C: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x80101050: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101054: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101058: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8010105C: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80101060: lh          $t1, 0x6($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X6);
    // 0x80101064: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x80101068: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8010106C: sh          $t0, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r8;
    // 0x80101070: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80101074: jr          $ra
    // 0x80101078: sh          $t3, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r11;
    return;
    // 0x80101078: sh          $t3, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_80040900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040900: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80040904: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80040908: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8004090C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80040910: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80040914: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80040918: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004091C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80040920: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80040924: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80040928: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004092C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80040930: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80040934: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x80040938: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x8004093C: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80040940: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x80040944: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x80040948: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8004094C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80040950: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x80040954: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x80040958: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8004095C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80040960: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80040964: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x80040968: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8004096C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80040970: blez        $t8, L_800409EC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80040974: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_800409EC;
    }
    // 0x80040974: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x80040978: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x8004097C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x80040980: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80040984: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_80040988:
    // 0x80040988: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004098C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80040990: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80040994: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80040998: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8004099C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800409A0: jalr        $t9
    // 0x800409A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800409A4: nop

    after_0:
    // 0x800409A8: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800409AC: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800409B0: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x800409B4: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x800409B8: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x800409BC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800409C0: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800409C4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800409C8: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x800409CC: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800409D0: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800409D4: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x800409D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800409DC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800409E0: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800409E4: bne         $at, $zero, L_80040988
    if (ctx->r1 != 0) {
        // 0x800409E8: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_80040988;
    }
    // 0x800409E8: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_800409EC:
    // 0x800409EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800409F0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800409F4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800409F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800409FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80040A00: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80040A04: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80040A08: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80040A0C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80040A10: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80040A14: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80040A18: jr          $ra
    // 0x80040A1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80040A1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8000CE8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CE8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000CE90: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000CE94: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000CE98: addiu       $s2, $s2, 0x28FC
    ctx->r18 = ADD32(ctx->r18, 0X28FC);
    // 0x8000CE9C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8000CEA0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8000CEA4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8000CEA8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8000CEAC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000CEB0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8000CEB4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000CEB8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000CEBC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000CEC0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000CEC4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000CEC8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000CECC: addiu       $t6, $t6, 0x3488
    ctx->r14 = ADD32(ctx->r14, 0X3488);
    // 0x8000CED0: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8000CED4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000CED8: lw          $s3, 0x28E4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X28E4);
    // 0x8000CEDC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000CEE0: addiu       $s0, $s0, -0x4D04
    ctx->r16 = ADD32(ctx->r16, -0X4D04);
    // 0x8000CEE4: beq         $s3, $zero, L_8000CF74
    if (ctx->r19 == 0) {
        // 0x8000CEE8: nop
    
            goto L_8000CF74;
    }
    // 0x8000CEE8: nop

    // 0x8000CEEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000CEF0: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8000CEF4: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8000CEF8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000CEFC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000CF00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000CF04: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000CF08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000CF0C: lui         $t3, 0xC18
    ctx->r11 = S32(0XC18 << 16);
    // 0x8000CF10: ori         $t3, $t3, 0x49D8
    ctx->r11 = ctx->r11 | 0X49D8;
    // 0x8000CF14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000CF18: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000CF1C: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8000CF20: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8000CF24: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8000CF28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000CF2C: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8000CF30: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000CF34: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8000CF38: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8000CF3C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000CF40: lw          $t6, 0x4EE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4EE4);
    // 0x8000CF44: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8000CF48: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8000CF4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000CF50: lbu         $t8, -0x1018($t7)
    ctx->r24 = MEM_BU(ctx->r15, -0X1018);
    // 0x8000CF54: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000CF58: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000CF5C: ori         $t2, $t2, 0xC02
    ctx->r10 = ctx->r10 | 0XC02;
    // 0x8000CF60: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x8000CF64: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8000CF68: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8000CF6C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8000CF70: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_8000CF74:
    // 0x8000CF74: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000CF78: beq         $s3, $zero, L_8000D06C
    if (ctx->r19 == 0) {
        // 0x8000CF7C: addiu       $s0, $s0, -0x4D04
        ctx->r16 = ADD32(ctx->r16, -0X4D04);
            goto L_8000D06C;
    }
    // 0x8000CF7C: addiu       $s0, $s0, -0x4D04
    ctx->r16 = ADD32(ctx->r16, -0X4D04);
    // 0x8000CF80: lui         $s7, 0x200
    ctx->r23 = S32(0X200 << 16);
    // 0x8000CF84: lui         $s6, 0x102
    ctx->r22 = S32(0X102 << 16);
    // 0x8000CF88: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x8000CF8C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000CF90: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000CF94: addiu       $s1, $s1, -0x4D08
    ctx->r17 = ADD32(ctx->r17, -0X4D08);
    // 0x8000CF98: addiu       $s5, $s5, 0x4F34
    ctx->r21 = ADD32(ctx->r21, 0X4F34);
    // 0x8000CF9C: ori         $s6, $s6, 0x40
    ctx->r22 = ctx->r22 | 0X40;
    // 0x8000CFA0: addiu       $s7, $s7, 0x0
    ctx->r23 = ADD32(ctx->r23, 0X0);
    // 0x8000CFA4: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
L_8000CFA8:
    // 0x8000CFA8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8000CFAC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000CFB0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8000CFB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000CFB8: addiu       $t4, $v1, 0x4
    ctx->r12 = ADD32(ctx->r3, 0X4);
    // 0x8000CFBC: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8000CFC0: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000CFC4: lh          $s4, 0x14($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X14);
    // 0x8000CFC8: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8000CFCC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8000CFD0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000CFD4: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8000CFD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000CFDC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8000CFE0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000CFE4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8000CFE8: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    // 0x8000CFEC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8000CFF0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000CFF4: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8000CFF8: jal         0x80035120
    // 0x8000CFFC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guPosition(rdram, ctx);
        goto after_0;
    // 0x8000CFFC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8000D000: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D004: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D008: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000D00C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8000D010: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8000D014: sll         $t2, $t9, 6
    ctx->r10 = S32(ctx->r25 << 6);
    // 0x8000D018: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x8000D01C: addiu       $t4, $t3, 0xC0
    ctx->r12 = ADD32(ctx->r11, 0XC0);
    // 0x8000D020: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000D024: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000D028: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x8000D02C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8000D030: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D034: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000D038: sll         $t9, $s4, 5
    ctx->r25 = S32(ctx->r20 << 5);
    // 0x8000D03C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000D040: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000D044: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8000D048: lw          $t8, 0x4F28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F28);
    // 0x8000D04C: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x8000D050: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8000D054: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8000D058: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8000D05C: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8000D060: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8000D064: bne         $s3, $zero, L_8000CFA8
    if (ctx->r19 != 0) {
        // 0x8000D068: sw          $t6, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r14;
            goto L_8000CFA8;
    }
    // 0x8000D068: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
L_8000D06C:
    // 0x8000D06C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000D070: lw          $a2, 0x28EC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X28EC);
    // 0x8000D074: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000D078: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x8000D07C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000D080: addiu       $s5, $s5, 0x4F34
    ctx->r21 = ADD32(ctx->r21, 0X4F34);
    // 0x8000D084: addiu       $s1, $s1, -0x4D08
    ctx->r17 = ADD32(ctx->r17, -0X4D08);
    // 0x8000D088: beq         $a2, $zero, L_8000D10C
    if (ctx->r6 == 0) {
        // 0x8000D08C: lui         $fp, 0x600
        ctx->r30 = S32(0X600 << 16);
            goto L_8000D10C;
    }
    // 0x8000D08C: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
    // 0x8000D090: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D094: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8000D098: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000D09C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8000D0A0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8000D0A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D0A8: lw          $t8, 0x4EE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4EE4);
    // 0x8000D0AC: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x8000D0B0: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x8000D0B4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8000D0B8: lbu         $t2, -0x1018($t9)
    ctx->r10 = MEM_BU(ctx->r25, -0X1018);
    // 0x8000D0BC: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x8000D0C0: lui         $t7, 0xFC12
    ctx->r15 = S32(0XFC12 << 16);
    // 0x8000D0C4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8000D0C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D0CC: lui         $t6, 0xC810
    ctx->r14 = S32(0XC810 << 16);
    // 0x8000D0D0: ori         $t6, $t6, 0x49D8
    ctx->r14 = ctx->r14 | 0X49D8;
    // 0x8000D0D4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8000D0D8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8000D0DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000D0E0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000D0E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D0E8: ori         $t7, $t7, 0x1A04
    ctx->r15 = ctx->r15 | 0X1A04;
    // 0x8000D0EC: addiu       $t8, $zero, -0x8
    ctx->r24 = ADD32(0, -0X8);
    // 0x8000D0F0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8000D0F4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8000D0F8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000D0FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D100: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8000D104: lw          $a2, 0x28EC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X28EC);
    // 0x8000D108: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
L_8000D10C:
    // 0x8000D10C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000D110: addiu       $t9, $t9, 0x3C90
    ctx->r25 = ADD32(ctx->r25, 0X3C90);
    // 0x8000D114: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000D118: sw          $t9, 0x2904($at)
    MEM_W(0X2904, ctx->r1) = ctx->r25;
    // 0x8000D11C: beq         $a2, $zero, L_8000D3C4
    if (ctx->r6 == 0) {
        // 0x8000D120: or          $s3, $a2, $zero
        ctx->r19 = ctx->r6 | 0;
            goto L_8000D3C4;
    }
    // 0x8000D120: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000D124: lui         $s6, 0xF510
    ctx->r22 = S32(0XF510 << 16);
    // 0x8000D128: ori         $s6, $s6, 0x1000
    ctx->r22 = ctx->r22 | 0X1000;
    // 0x8000D12C: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x8000D130: addiu       $s7, $zero, 0x20
    ctx->r23 = ADD32(0, 0X20);
L_8000D134:
    // 0x8000D134: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8000D138: addiu       $t0, $t0, 0x2904
    ctx->r8 = ADD32(ctx->r8, 0X2904);
    // 0x8000D13C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8000D140: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000D144: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8000D148: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000D14C: addiu       $t2, $v1, 0x4
    ctx->r10 = ADD32(ctx->r3, 0X4);
    // 0x8000D150: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8000D154: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000D158: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000D15C: lhu         $s2, 0x16($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X16);
    // 0x8000D160: lh          $s4, 0x14($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X14);
    // 0x8000D164: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8000D168: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000D16C: sll         $t5, $t6, 6
    ctx->r13 = S32(ctx->r14 << 6);
    // 0x8000D170: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000D174: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8000D178: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000D17C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8000D180: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8000D184: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8000D188: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000D18C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8000D190: andi        $t3, $s2, 0xFF
    ctx->r11 = ctx->r18 & 0XFF;
    // 0x8000D194: addiu       $s2, $t3, -0x40
    ctx->r18 = ADD32(ctx->r11, -0X40);
    // 0x8000D198: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x8000D19C: jal         0x80035120
    // 0x8000D1A0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    guPosition(rdram, ctx);
        goto after_1;
    // 0x8000D1A0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8000D1A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1A8: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x8000D1AC: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x8000D1B0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000D1B4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000D1B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000D1BC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8000D1C0: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8000D1C4: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8000D1C8: sll         $t2, $t9, 6
    ctx->r10 = S32(ctx->r25 << 6);
    // 0x8000D1CC: addiu       $t3, $t2, 0xC0
    ctx->r11 = ADD32(ctx->r10, 0XC0);
    // 0x8000D1D0: addu        $t4, $t3, $t6
    ctx->r12 = ADD32(ctx->r11, ctx->r14);
    // 0x8000D1D4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000D1D8: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8000D1DC: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8000D1E0: ori         $t9, $t9, 0x1F
    ctx->r25 = ctx->r25 | 0X1F;
    // 0x8000D1E4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8000D1E8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8000D1EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1F0: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x8000D1F4: lui         $t3, 0x8005
    ctx->r11 = S32(0X8005 << 16);
    // 0x8000D1F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D1FC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000D200: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8000D204: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000D208: lw          $t3, -0x3CEC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3CEC);
    // 0x8000D20C: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x8000D210: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x8000D214: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8000D218: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8000D21C: addiu       $t5, $t5, -0x3CD8
    ctx->r13 = ADD32(ctx->r13, -0X3CD8);
    // 0x8000D220: addu        $a3, $t4, $t5
    ctx->r7 = ADD32(ctx->r12, ctx->r13);
    // 0x8000D224: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x8000D228: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000D22C: sw          $s6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r22;
    // 0x8000D230: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x8000D234: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8000D238: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8000D23C: bne         $s7, $t7, L_8000D24C
    if (ctx->r23 != ctx->r15) {
        // 0x8000D240: nop
    
            goto L_8000D24C;
    }
    // 0x8000D240: nop

    // 0x8000D244: b           L_8000D24C
    // 0x8000D248: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
        goto L_8000D24C;
    // 0x8000D248: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_8000D24C:
    // 0x8000D24C: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x8000D250: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8000D254: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x8000D258: ori         $t3, $t2, 0x50
    ctx->r11 = ctx->r10 | 0X50;
    // 0x8000D25C: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x8000D260: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D264: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x8000D268: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8000D26C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000D270: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000D274: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D278: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000D27C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D280: lui         $t7, 0xF400
    ctx->r15 = S32(0XF400 << 16);
    // 0x8000D284: lui         $at, 0x707
    ctx->r1 = S32(0X707 << 16);
    // 0x8000D288: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8000D28C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8000D290: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000D294: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
    // 0x8000D298: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8000D29C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8000D2A0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8000D2A4: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8000D2A8: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x8000D2AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000D2B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2B4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8000D2B8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8000D2BC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8000D2C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D2C4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000D2C8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2CC: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x8000D2D0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000D2D4: sw          $s6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r22;
    // 0x8000D2D8: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
    // 0x8000D2DC: bne         $s7, $t8, L_8000D2EC
    if (ctx->r23 != ctx->r24) {
        // 0x8000D2E0: nop
    
            goto L_8000D2EC;
    }
    // 0x8000D2E0: nop

    // 0x8000D2E4: b           L_8000D2EC
    // 0x8000D2E8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
        goto L_8000D2EC;
    // 0x8000D2E8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_8000D2EC:
    // 0x8000D2EC: andi        $t9, $t0, 0xF
    ctx->r25 = ctx->r8 & 0XF;
    // 0x8000D2F0: sll         $t2, $t9, 14
    ctx->r10 = S32(ctx->r25 << 14);
    // 0x8000D2F4: ori         $t3, $t2, 0x50
    ctx->r11 = ctx->r10 | 0X50;
    // 0x8000D2F8: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8000D2FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D300: lui         $at, 0x7
    ctx->r1 = S32(0X7 << 16);
    // 0x8000D304: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8000D308: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000D30C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000D310: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8000D314: lhu         $t4, 0x0($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X0);
    // 0x8000D318: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8000D31C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8000D320: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8000D324: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8000D328: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000D32C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D330: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x8000D334: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8000D338: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8000D33C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8000D340: lhu         $a1, -0x3CF0($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X3CF0);
    // 0x8000D344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000D348: bgez        $a1, L_8000D35C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8000D34C: andi        $t3, $a1, 0xFF
        ctx->r11 = ctx->r5 & 0XFF;
            goto L_8000D35C;
    }
    // 0x8000D34C: andi        $t3, $a1, 0xFF
    ctx->r11 = ctx->r5 & 0XFF;
    // 0x8000D350: beq         $t3, $zero, L_8000D35C
    if (ctx->r11 == 0) {
        // 0x8000D354: nop
    
            goto L_8000D35C;
    }
    // 0x8000D354: nop

    // 0x8000D358: addiu       $t3, $t3, -0x100
    ctx->r11 = ADD32(ctx->r11, -0X100);
L_8000D35C:
    // 0x8000D35C: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8000D360: andi        $t4, $t6, 0xFFF
    ctx->r12 = ctx->r14 & 0XFFF;
    // 0x8000D364: or          $t5, $t4, $fp
    ctx->r13 = ctx->r12 | ctx->r30;
    // 0x8000D368: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8000D36C: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x8000D370: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x8000D374: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000D378: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x8000D37C: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8000D380: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8000D384: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D388: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8000D38C: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x8000D390: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8000D394: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000D398: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8000D39C: lw          $t5, 0x4F28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4F28);
    // 0x8000D3A0: sll         $t7, $s4, 5
    ctx->r15 = S32(ctx->r20 << 5);
    // 0x8000D3A4: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8000D3A8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8000D3AC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000D3B0: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8000D3B4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8000D3B8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000D3BC: bne         $s3, $zero, L_8000D134
    if (ctx->r19 != 0) {
        // 0x8000D3C0: sw          $t3, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r11;
            goto L_8000D134;
    }
    // 0x8000D3C0: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
L_8000D3C4:
    // 0x8000D3C4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000D3C8: addiu       $s1, $s1, 0x28E8
    ctx->r17 = ADD32(ctx->r17, 0X28E8);
    // 0x8000D3CC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8000D3D0: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8000D3D4: addiu       $s2, $s2, 0x2900
    ctx->r18 = ADD32(ctx->r18, 0X2900);
    // 0x8000D3D8: beq         $t6, $zero, L_8000D468
    if (ctx->r14 == 0) {
        // 0x8000D3DC: lui         $t8, 0xB900
        ctx->r24 = S32(0XB900 << 16);
            goto L_8000D468;
    }
    // 0x8000D3DC: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8000D3E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D3E4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8000D3E8: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8000D3EC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8000D3F0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8000D3F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D3F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000D3FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D400: lui         $t9, 0xC18
    ctx->r25 = S32(0XC18 << 16);
    // 0x8000D404: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x8000D408: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8000D40C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8000D410: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8000D414: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000D418: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D41C: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8000D420: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x8000D424: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8000D428: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8000D42C: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8000D430: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000D434: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000D438: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8000D43C: addiu       $a3, $t4, 0x3888
    ctx->r7 = ADD32(ctx->r12, 0X3888);
    // 0x8000D440: sw          $a3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r7;
    // 0x8000D444: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8000D448: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8000D44C: jal         0x8000E774
    // 0x8000D450: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    func_8000E774(rdram, ctx);
        goto after_2;
    // 0x8000D450: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_2:
    // 0x8000D454: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8000D458: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8000D45C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8000D460: jal         0x8000E774
    // 0x8000D464: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    func_8000E774(rdram, ctx);
        goto after_3;
    // 0x8000D464: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    after_3:
L_8000D468:
    // 0x8000D468: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8000D46C: addiu       $a2, $a2, -0x3D30
    ctx->r6 = ADD32(ctx->r6, -0X3D30);
    // 0x8000D470: lhu         $t5, 0x0($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X0);
    // 0x8000D474: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8000D478: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8000D47C: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x8000D480: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D484: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8000D488: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8000D48C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8000D490: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000D494: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D498: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8000D49C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D4A0: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x8000D4A4: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8000D4A8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8000D4AC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8000D4B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000D4B4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000D4B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000D4BC: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x8000D4C0: ori         $t5, $t5, 0xE02
    ctx->r13 = ctx->r13 | 0XE02;
    // 0x8000D4C4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8000D4C8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8000D4CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000D4D0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000D4D4: lhu         $t7, -0x3CF0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X3CF0);
    // 0x8000D4D8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000D4DC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000D4E0: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x8000D4E4: sh          $t8, -0x3CF0($at)
    MEM_H(-0X3CF0, ctx->r1) = ctx->r24;
    // 0x8000D4E8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8000D4EC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000D4F0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000D4F4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000D4F8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8000D4FC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8000D500: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8000D504: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8000D508: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8000D50C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8000D510: jr          $ra
    // 0x8000D514: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8000D514: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800319E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800319E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800319E4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800319E8: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800319EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800319F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800319F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800319F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800319FC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80031A00: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80031A04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031A08: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031A0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031A10: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80031A14: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80031A18: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80031A1C: addiu       $t8, $t8, 0x2898
    ctx->r24 = ADD32(ctx->r24, 0X2898);
    // 0x80031A20: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80031A24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031A28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80031A2C: jal         0x8003C12C
    // 0x80031A30: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x80031A30: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x80031A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031A38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031A3C: jr          $ra
    // 0x80031A40: nop

    return;
    // 0x80031A40: nop

;}
RECOMP_FUNC void func_8002B8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B8C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002B8C8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002B8CC: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002B8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B8D4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002B8D8: lhu         $t6, -0x2F4($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2F4);
    // 0x8002B8DC: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8002B8E0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002B8E4: andi        $t7, $t6, 0xC
    ctx->r15 = ctx->r14 & 0XC;
    // 0x8002B8E8: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x8002B8EC: beq         $t9, $zero, L_8002B9A8
    if (ctx->r25 == 0) {
        // 0x8002B8F0: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_8002B9A8;
    }
    // 0x8002B8F0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8002B8F4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8002B8F8: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x8002B8FC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8002B900: addiu       $t1, $t1, 0x2898
    ctx->r9 = ADD32(ctx->r9, 0X2898);
    // 0x8002B904: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8002B908: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8002B90C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8002B910: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8002B914: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002B918: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8002B91C: jal         0x80039D90
    // 0x8002B920: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    osPfsInitPak_recomp(rdram, ctx);
        goto after_0;
    // 0x8002B920: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    after_0:
    // 0x8002B924: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002B928: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002B92C: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002B930: bne         $v0, $at, L_8002B940
    if (ctx->r2 != ctx->r1) {
        // 0x8002B934: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8002B940;
    }
    // 0x8002B934: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002B938: b           L_8002B998
    // 0x8002B93C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8002B998;
    // 0x8002B93C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002B940:
    // 0x8002B940: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8002B944: bne         $v0, $a3, L_8002B998
    if (ctx->r2 != ctx->r7) {
        // 0x8002B948: lui         $a2, 0x8009
        ctx->r6 = S32(0X8009 << 16);
            goto L_8002B998;
    }
    // 0x8002B948: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8002B94C: lb          $a2, 0x2870($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X2870);
    // 0x8002B950: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x8002B954: addiu       $t3, $t3, 0x2898
    ctx->r11 = ADD32(ctx->r11, 0X2898);
    // 0x8002B958: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8002B95C: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x8002B960: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8002B964: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x8002B968: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002B96C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002B970: addiu       $a0, $a0, 0x2880
    ctx->r4 = ADD32(ctx->r4, 0X2880);
    // 0x8002B974: jal         0x8003A4BC
    // 0x8002B978: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x8002B978: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x8002B97C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002B980: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002B984: bne         $v0, $zero, L_8002B994
    if (ctx->r2 != 0) {
        // 0x8002B988: addiu       $a3, $zero, 0xA
        ctx->r7 = ADD32(0, 0XA);
            goto L_8002B994;
    }
    // 0x8002B988: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8002B98C: b           L_8002B998
    // 0x8002B990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8002B998;
    // 0x8002B990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002B994:
    // 0x8002B994: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8002B998:
    // 0x8002B998: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x8002B99C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002B9A0: andi        $t5, $t4, 0xEFFF
    ctx->r13 = ctx->r12 & 0XEFFF;
    // 0x8002B9A4: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
L_8002B9A8:
    // 0x8002B9A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002B9AC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8002B9B0: bne         $a0, $zero, L_8002B9D4
    if (ctx->r4 != 0) {
        // 0x8002B9B4: nop
    
            goto L_8002B9D4;
    }
    // 0x8002B9B4: nop

    // 0x8002B9B8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002B9BC: jal         0x80031574
    // 0x8002B9C0: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    func_80031574(rdram, ctx);
        goto after_2;
    // 0x8002B9C0: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    after_2:
    // 0x8002B9C4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002B9C8: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002B9CC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8002B9D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8002B9D4:
    // 0x8002B9D4: beq         $a0, $zero, L_8002BA68
    if (ctx->r4 == 0) {
        // 0x8002B9D8: lw          $t5, 0x1C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X1C);
            goto L_8002BA68;
    }
    // 0x8002B9D8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B9DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002B9E0: jal         0x80031BB0
    // 0x8002B9E4: sw          $a0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r4;
    func_80031BB0(rdram, ctx);
        goto after_3;
    // 0x8002B9E4: sw          $a0, -0x2DC($at)
    MEM_W(-0X2DC, ctx->r1) = ctx->r4;
    after_3:
    // 0x8002B9E8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002B9EC: negu        $t6, $v0
    ctx->r14 = SUB32(0, ctx->r2);
    // 0x8002B9F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002B9F4: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002B9F8: bne         $t6, $at, L_8002BA3C
    if (ctx->r14 != ctx->r1) {
        // 0x8002B9FC: addiu       $a3, $zero, 0xA
        ctx->r7 = ADD32(0, 0XA);
            goto L_8002BA3C;
    }
    // 0x8002B9FC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8002BA00: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BA04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002BA08: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8002BA0C: bne         $t7, $at, L_8002BA28
    if (ctx->r15 != ctx->r1) {
        // 0x8002BA10: addiu       $t9, $zero, 0x8
        ctx->r25 = ADD32(0, 0X8);
            goto L_8002BA28;
    }
    // 0x8002BA10: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8002BA14: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BA18: sb          $t8, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r24;
    // 0x8002BA1C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BA20: b           L_8002BA50
    // 0x8002BA24: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
        goto L_8002BA50;
    // 0x8002BA24: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
L_8002BA28:
    // 0x8002BA28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BA2C: sb          $t9, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r25;
    // 0x8002BA30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BA34: b           L_8002BA50
    // 0x8002BA38: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
        goto L_8002BA50;
    // 0x8002BA38: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
L_8002BA3C:
    // 0x8002BA3C: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x8002BA40: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BA44: sb          $t0, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r8;
    // 0x8002BA48: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BA4C: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
L_8002BA50:
    // 0x8002BA50: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BA54: andi        $t3, $t1, 0xFFF8
    ctx->r11 = ctx->r9 & 0XFFF8;
    // 0x8002BA58: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x8002BA5C: ori         $t4, $t3, 0x5
    ctx->r12 = ctx->r11 | 0X5;
    // 0x8002BA60: b           L_8002BC90
    // 0x8002BA64: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
        goto L_8002BC90;
    // 0x8002BA64: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8002BA68:
    // 0x8002BA68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002BA6C: bne         $t5, $at, L_8002BB4C
    if (ctx->r13 != ctx->r1) {
        // 0x8002BA70: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_8002BB4C;
    }
    // 0x8002BA70: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002BA74: lb          $t6, 0x2870($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2870);
    // 0x8002BA78: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002BA7C: addiu       $t8, $t8, 0x2A38
    ctx->r24 = ADD32(ctx->r24, 0X2A38);
    // 0x8002BA80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002BA84: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002BA88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002BA8C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002BA90: lbu         $t9, 0x13($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X13);
    // 0x8002BA94: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8002BA98: beql        $at, $zero, L_8002BAEC
    if (ctx->r1 == 0) {
        // 0x8002BA9C: lh          $a1, 0x0($v0)
        ctx->r5 = MEM_H(ctx->r2, 0X0);
            goto L_8002BAEC;
    }
    goto skip_0;
    // 0x8002BA9C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    skip_0:
    // 0x8002BAA0: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8002BAA4: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BAA8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8002BAAC: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x8002BAB0: beq         $t1, $zero, L_8002BAC8
    if (ctx->r9 == 0) {
        // 0x8002BAB4: andi        $t5, $a0, 0xFFF8
        ctx->r13 = ctx->r4 & 0XFFF8;
            goto L_8002BAC8;
    }
    // 0x8002BAB4: andi        $t5, $a0, 0xFFF8
    ctx->r13 = ctx->r4 & 0XFFF8;
    // 0x8002BAB8: addiu       $t2, $zero, 0x15
    ctx->r10 = ADD32(0, 0X15);
    // 0x8002BABC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BAC0: b           L_8002BAD0
    // 0x8002BAC4: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
        goto L_8002BAD0;
    // 0x8002BAC4: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
L_8002BAC8:
    // 0x8002BAC8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BACC: sb          $t3, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r11;
L_8002BAD0:
    // 0x8002BAD0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BAD4: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
    // 0x8002BAD8: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8002BADC: ori         $t6, $t5, 0x5
    ctx->r14 = ctx->r13 | 0X5;
    // 0x8002BAE0: b           L_8002BC90
    // 0x8002BAE4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
        goto L_8002BC90;
    // 0x8002BAE4: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8002BAE8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
L_8002BAEC:
    // 0x8002BAEC: andi        $t7, $a1, 0x2000
    ctx->r15 = ctx->r5 & 0X2000;
    // 0x8002BAF0: beq         $t7, $zero, L_8002BC5C
    if (ctx->r15 == 0) {
        // 0x8002BAF4: andi        $t8, $a1, 0x4000
        ctx->r24 = ctx->r5 & 0X4000;
            goto L_8002BC5C;
    }
    // 0x8002BAF4: andi        $t8, $a1, 0x4000
    ctx->r24 = ctx->r5 & 0X4000;
    // 0x8002BAF8: beq         $t8, $zero, L_8002BB24
    if (ctx->r24 == 0) {
        // 0x8002BAFC: lhu         $a0, 0x0($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X0);
            goto L_8002BB24;
    }
    // 0x8002BAFC: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BB00: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x8002BB04: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BB08: sb          $t9, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r25;
    // 0x8002BB0C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BB10: sb          $zero, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = 0;
    // 0x8002BB14: andi        $t0, $a0, 0xFFDF
    ctx->r8 = ctx->r4 & 0XFFDF;
    // 0x8002BB18: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8002BB1C: b           L_8002BB30
    // 0x8002BB20: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
        goto L_8002BB30;
    // 0x8002BB20: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
L_8002BB24:
    // 0x8002BB24: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8002BB28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BB2C: sb          $t1, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r9;
L_8002BB30:
    // 0x8002BB30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BB34: andi        $t3, $a0, 0xFFF8
    ctx->r11 = ctx->r4 & 0XFFF8;
    // 0x8002BB38: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
    // 0x8002BB3C: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x8002BB40: ori         $t4, $t3, 0x5
    ctx->r12 = ctx->r11 | 0X5;
    // 0x8002BB44: b           L_8002BC90
    // 0x8002BB48: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
        goto L_8002BC90;
    // 0x8002BB48: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8002BB4C:
    // 0x8002BB4C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002BB50: lbu         $t5, -0x2D4($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X2D4);
    // 0x8002BB54: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8002BB58: beq         $t5, $zero, L_8002BBE4
    if (ctx->r13 == 0) {
        // 0x8002BB5C: nop
    
            goto L_8002BBE4;
    }
    // 0x8002BB5C: nop

    // 0x8002BB60: lb          $t6, 0x2870($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X2870);
    // 0x8002BB64: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002BB68: addiu       $t8, $t8, 0x2A38
    ctx->r24 = ADD32(ctx->r24, 0X2A38);
    // 0x8002BB6C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002BB70: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8002BB74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002BB78: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002BB7C: lbu         $t9, 0x13($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X13);
    // 0x8002BB80: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x8002BB84: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8002BB88: bne         $at, $zero, L_8002BB9C
    if (ctx->r1 != 0) {
        // 0x8002BB8C: nop
    
            goto L_8002BB9C;
    }
    // 0x8002BB8C: nop

    // 0x8002BB90: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8002BB94: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x8002BB98: beq         $t1, $zero, L_8002BBE4
    if (ctx->r9 == 0) {
        // 0x8002BB9C: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_8002BBE4;
    }
L_8002BB9C:
    // 0x8002BB9C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BBA0: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
    // 0x8002BBA4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BBA8: jal         0x8002DD18
    // 0x8002BBAC: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
    func_8002DD18(rdram, ctx);
        goto after_4;
    // 0x8002BBAC: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
    after_4:
    // 0x8002BBB0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002BBB4: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002BBB8: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BBBC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BBC0: andi        $t5, $t3, 0xFFF8
    ctx->r13 = ctx->r11 & 0XFFF8;
    // 0x8002BBC4: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8002BBC8: ori         $t6, $t5, 0x5
    ctx->r14 = ctx->r13 | 0X5;
    // 0x8002BBCC: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8002BBD0: sb          $zero, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = 0;
    // 0x8002BBD4: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BBD8: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x8002BBDC: b           L_8002BC90
    // 0x8002BBE0: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
        goto L_8002BC90;
    // 0x8002BBE0: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_8002BBE4:
    // 0x8002BBE4: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002BBE8: lb          $t9, 0x2870($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X2870);
    // 0x8002BBEC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x8002BBF0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BBF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002BBF8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8002BBFC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8002BC00: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8002BC04: lh          $t1, 0x2A38($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X2A38);
    // 0x8002BC08: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8002BC0C: bne         $t2, $zero, L_8002BC5C
    if (ctx->r10 != 0) {
        // 0x8002BC10: nop
    
            goto L_8002BC5C;
    }
    // 0x8002BC10: nop

    // 0x8002BC14: bne         $t3, $zero, L_8002BC34
    if (ctx->r11 != 0) {
        // 0x8002BC18: lhu         $a0, 0x0($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X0);
            goto L_8002BC34;
    }
    // 0x8002BC18: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BC1C: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x8002BC20: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BC24: sb          $t4, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r12;
    // 0x8002BC28: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BC2C: b           L_8002BC48
    // 0x8002BC30: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
        goto L_8002BC48;
    // 0x8002BC30: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
L_8002BC34:
    // 0x8002BC34: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8002BC38: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BC3C: sb          $t5, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r13;
    // 0x8002BC40: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BC44: sb          $a3, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r7;
L_8002BC48:
    // 0x8002BC48: andi        $t7, $a0, 0xFFF8
    ctx->r15 = ctx->r4 & 0XFFF8;
    // 0x8002BC4C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8002BC50: ori         $t8, $t7, 0x5
    ctx->r24 = ctx->r15 | 0X5;
    // 0x8002BC54: b           L_8002BC90
    // 0x8002BC58: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
        goto L_8002BC90;
    // 0x8002BC58: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_8002BC5C:
    // 0x8002BC5C: jal         0x8002DD18
    // 0x8002BC60: nop

    func_8002DD18(rdram, ctx);
        goto after_5;
    // 0x8002BC60: nop

    after_5:
    // 0x8002BC64: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002BC68: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002BC6C: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BC70: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BC74: andi        $t1, $t9, 0xFFF8
    ctx->r9 = ctx->r25 & 0XFFF8;
    // 0x8002BC78: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8002BC7C: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8002BC80: sb          $zero, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = 0;
    // 0x8002BC84: lhu         $t2, 0x0($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BC88: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x8002BC8C: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_8002BC90:
    // 0x8002BC90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BC94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002BC98: jr          $ra
    // 0x8002BC9C: nop

    return;
    // 0x8002BC9C: nop

;}
RECOMP_FUNC void func_80024704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024704: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024708: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002470C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80024710: addiu       $s0, $s0, -0xDC0
    ctx->r16 = ADD32(ctx->r16, -0XDC0);
    // 0x80024714: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024718: lui         $a1, 0x8033
    ctx->r5 = S32(0X8033 << 16);
    // 0x8002471C: lui         $a2, 0x6
    ctx->r6 = S32(0X6 << 16);
    // 0x80024720: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80024724: addiu       $a1, $a1, 0x1AB0
    ctx->r5 = ADD32(ctx->r5, 0X1AB0);
    // 0x80024728: jal         0x80036620
    // 0x8002472C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036620(rdram, ctx);
        goto after_0;
    // 0x8002472C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80024730: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80024734: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80024738: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002473C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024740: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80024744: jal         0x80036660
    // 0x80024748: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80024748: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8002474C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80024750: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80024754: sw          $v0, -0xDB0($at)
    MEM_W(-0XDB0, ctx->r1) = ctx->r2;
    // 0x80024758: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002475C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80024760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024764: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80024768: jal         0x80036660
    // 0x8002476C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8002476C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80024770: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80024774: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x80024778: sw          $v0, -0xDAC($at)
    MEM_W(-0XDAC, ctx->r1) = ctx->r2;
    // 0x8002477C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80024780: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80024784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024788: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002478C: jal         0x80036660
    // 0x80024790: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x80024790: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80024794: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80024798: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x8002479C: sw          $v0, -0xDA8($at)
    MEM_W(-0XDA8, ctx->r1) = ctx->r2;
    // 0x800247A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800247A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800247A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800247AC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800247B0: jal         0x80036660
    // 0x800247B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x800247B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800247B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800247BC: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x800247C0: sw          $v0, -0xDA4($at)
    MEM_W(-0XDA4, ctx->r1) = ctx->r2;
    // 0x800247C4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800247C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800247CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800247D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800247D4: jal         0x80036660
    // 0x800247D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x800247D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800247DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800247E0: ori         $t1, $zero, 0x8000
    ctx->r9 = 0 | 0X8000;
    // 0x800247E4: sw          $v0, -0xDA0($at)
    MEM_W(-0XDA0, ctx->r1) = ctx->r2;
    // 0x800247E8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800247EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800247F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800247F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800247F8: jal         0x80036660
    // 0x800247FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_6;
    // 0x800247FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80024800: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80024804: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x80024808: sw          $v0, -0xD9C($at)
    MEM_W(-0XD9C, ctx->r1) = ctx->r2;
    // 0x8002480C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80024810: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80024814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024818: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002481C: jal         0x80036660
    // 0x80024820: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_7;
    // 0x80024820: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80024824: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80024828: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002482C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80024830: sw          $v0, -0xD98($at)
    MEM_W(-0XD98, ctx->r1) = ctx->r2;
    // 0x80024834: addiu       $a1, $a1, -0xD60
    ctx->r5 = ADD32(ctx->r5, -0XD60);
    // 0x80024838: addiu       $a0, $a0, -0xD90
    ctx->r4 = ADD32(ctx->r4, -0XD90);
    // 0x8002483C: jal         0x80033F10
    // 0x80024840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_8;
    // 0x80024840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80024844: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80024848: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8002484C: addiu       $a1, $a1, -0xD5C
    ctx->r5 = ADD32(ctx->r5, -0XD5C);
    // 0x80024850: addiu       $a0, $a0, -0xD78
    ctx->r4 = ADD32(ctx->r4, -0XD78);
    // 0x80024854: jal         0x80033F10
    // 0x80024858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_9;
    // 0x80024858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8002485C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80024860: sb          $zero, -0x968($at)
    MEM_B(-0X968, ctx->r1) = 0;
    // 0x80024864: jal         0x800366C0
    // 0x80024868: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_10;
    // 0x80024868: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    after_10:
    // 0x8002486C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80024870: addiu       $a1, $a1, -0xA08
    ctx->r5 = ADD32(ctx->r5, -0XA08);
    // 0x80024874: lui         $t4, 0x8002
    ctx->r12 = S32(0X8002 << 16);
    // 0x80024878: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8002487C: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x80024880: addiu       $t4, $t4, 0x4A48
    ctx->r12 = ADD32(ctx->r12, 0X4A48);
    // 0x80024884: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80024888: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002488C: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x80024890: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80024894: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80024898: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x8002489C: sw          $t4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r12;
    // 0x800248A0: sb          $t5, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r13;
    // 0x800248A4: sw          $s0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r16;
    // 0x800248A8: sw          $zero, 0x20($a1)
    MEM_W(0X20, ctx->r5) = 0;
    // 0x800248AC: jal         0x800368AC
    // 0x800248B0: addiu       $a0, $a0, -0xA58
    ctx->r4 = ADD32(ctx->r4, -0XA58);
    func_800368AC(rdram, ctx);
        goto after_11;
    // 0x800248B0: addiu       $a0, $a0, -0xA58
    ctx->r4 = ADD32(ctx->r4, -0XA58);
    after_11:
    // 0x800248B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800248B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800248BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800248C0: jr          $ra
    // 0x800248C4: nop

    return;
    // 0x800248C4: nop

;}
RECOMP_FUNC void func_80031C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031C7C: lui         $a0, 0xDC
    ctx->r4 = S32(0XDC << 16);
    // 0x80031C80: addiu       $a0, $a0, 0x1620
    ctx->r4 = ADD32(ctx->r4, 0X1620);
    // 0x80031C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031C88: lui         $t6, 0xE2
    ctx->r14 = S32(0XE2 << 16);
    // 0x80031C8C: addiu       $t6, $t6, 0x7840
    ctx->r14 = ADD32(ctx->r14, 0X7840);
    // 0x80031C90: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80031C94: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80031C98: jal         0x80024260
    // 0x80031C9C: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80031C9C: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x80031CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031CA8: jr          $ra
    // 0x80031CAC: nop

    return;
    // 0x80031CAC: nop

;}
RECOMP_FUNC void func_80025B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B3C: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80025B40: addiu       $a1, $a1, 0x3970
    ctx->r5 = ADD32(ctx->r5, 0X3970);
    // 0x80025B44: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80025B48: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025B4C: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80025B50: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80025B54: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80025B58: sw          $a0, 0x390C($at)
    MEM_W(0X390C, ctx->r1) = ctx->r4;
    // 0x80025B5C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025B60: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80025B64: sw          $zero, 0x392C($at)
    MEM_W(0X392C, ctx->r1) = 0;
    // 0x80025B68: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80025B6C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80025B70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80025B74: sw          $t6, 0x394C($at)
    MEM_W(0X394C, ctx->r1) = ctx->r14;
    // 0x80025B78: andi        $t7, $v0, 0x7
    ctx->r15 = ctx->r2 & 0X7;
    // 0x80025B7C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80025B80: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80025B84: jr          $ra
    // 0x80025B88: sw          $v0, -0x350($at)
    MEM_W(-0X350, ctx->r1) = ctx->r2;
    return;
    // 0x80025B88: sw          $v0, -0x350($at)
    MEM_W(-0X350, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80007A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007A58: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80007A5C: lhu         $t6, 0x4F10($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4F10);
    // 0x80007A60: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80007A64: sw          $zero, -0x431C($at)
    MEM_W(-0X431C, ctx->r1) = 0;
    // 0x80007A68: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80007A6C: bne         $t7, $zero, L_80007B54
    if (ctx->r15 != 0) {
        // 0x80007A70: lui         $a0, 0x87
        ctx->r4 = S32(0X87 << 16);
            goto L_80007B54;
    }
    // 0x80007A70: lui         $a0, 0x87
    ctx->r4 = S32(0X87 << 16);
    // 0x80007A74: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80007A78: lw          $t8, 0x4F1C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F1C);
    // 0x80007A7C: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80007A80: addiu       $t1, $t1, 0x47F0
    ctx->r9 = ADD32(ctx->r9, 0X47F0);
    // 0x80007A84: lhu         $t9, 0x12($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X12);
    // 0x80007A88: lui         $t3, 0x87
    ctx->r11 = S32(0X87 << 16);
    // 0x80007A8C: addiu       $a0, $a0, 0x1900
    ctx->r4 = ADD32(ctx->r4, 0X1900);
    // 0x80007A90: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80007A94: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80007A98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80007A9C: addiu       $t3, $t3, 0x3F20
    ctx->r11 = ADD32(ctx->r11, 0X3F20);
    // 0x80007AA0: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x80007AA4: sw          $t2, -0x4350($at)
    MEM_W(-0X4350, ctx->r1) = ctx->r10;
    // 0x80007AA8: addiu       $a1, $a1, -0x3F30
    ctx->r5 = ADD32(ctx->r5, -0X3F30);
    // 0x80007AAC: jal         0x80024260
    // 0x80007AB0: subu        $a2, $t3, $a0
    ctx->r6 = SUB32(ctx->r11, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80007AB0: subu        $a2, $t3, $a0
    ctx->r6 = SUB32(ctx->r11, ctx->r4);
    after_0:
    // 0x80007AB4: lui         $a0, 0xA7
    ctx->r4 = S32(0XA7 << 16);
    // 0x80007AB8: lui         $t4, 0xA8
    ctx->r12 = S32(0XA8 << 16);
    // 0x80007ABC: addiu       $a0, $a0, 0x25D0
    ctx->r4 = ADD32(ctx->r4, 0X25D0);
    // 0x80007AC0: addiu       $t4, $t4, -0x5E70
    ctx->r12 = ADD32(ctx->r12, -0X5E70);
    // 0x80007AC4: lui         $a1, 0x802A
    ctx->r5 = S32(0X802A << 16);
    // 0x80007AC8: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80007ACC: jal         0x80024260
    // 0x80007AD0: subu        $a2, $t4, $a0
    ctx->r6 = SUB32(ctx->r12, ctx->r4);
    dma_write(rdram, ctx);
        goto after_1;
    // 0x80007AD0: subu        $a2, $t4, $a0
    ctx->r6 = SUB32(ctx->r12, ctx->r4);
    after_1:
    // 0x80007AD4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80007AD8: lw          $v0, -0x4350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4350);
    // 0x80007ADC: lui         $a1, 0x8021
    ctx->r5 = S32(0X8021 << 16);
    // 0x80007AE0: addiu       $a1, $a1, -0x1910
    ctx->r5 = ADD32(ctx->r5, -0X1910);
    // 0x80007AE4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80007AE8: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80007AEC: jal         0x80024260
    // 0x80007AF0: subu        $a2, $v1, $a0
    ctx->r6 = SUB32(ctx->r3, ctx->r4);
    dma_write(rdram, ctx);
        goto after_2;
    // 0x80007AF0: subu        $a2, $v1, $a0
    ctx->r6 = SUB32(ctx->r3, ctx->r4);
    after_2:
    // 0x80007AF4: jal         0x800080E8
    // 0x80007AF8: nop

    func_800080E8(rdram, ctx);
        goto after_3;
    // 0x80007AF8: nop

    after_3:
    // 0x80007AFC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80007B00: lhu         $v0, -0x4D18($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4D18);
    // 0x80007B04: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80007B08: sh          $zero, -0x434C($at)
    MEM_H(-0X434C, ctx->r1) = 0;
    // 0x80007B0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007B10: bne         $v0, $at, L_80007B34
    if (ctx->r2 != ctx->r1) {
        // 0x80007B14: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80007B34;
    }
    // 0x80007B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80007B18: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80007B1C: jal         0x80008AD8
    // 0x80007B20: addiu       $a1, $a1, 0x4828
    ctx->r5 = ADD32(ctx->r5, 0X4828);
    func_80008AD8(rdram, ctx);
        goto after_4;
    // 0x80007B20: addiu       $a1, $a1, 0x4828
    ctx->r5 = ADD32(ctx->r5, 0X4828);
    after_4:
    // 0x80007B24: jal         0x8002E768
    // 0x80007B28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002E768(rdram, ctx);
        goto after_5;
    // 0x80007B28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80007B2C: b           L_80007B58
    // 0x80007B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80007B58;
    // 0x80007B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80007B34:
    // 0x80007B34: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80007B38: bne         $v0, $at, L_80007B54
    if (ctx->r2 != ctx->r1) {
        // 0x80007B3C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80007B54;
    }
    // 0x80007B3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80007B40: lui         $a1, 0x8005
    ctx->r5 = S32(0X8005 << 16);
    // 0x80007B44: jal         0x80008AD8
    // 0x80007B48: addiu       $a1, $a1, 0x4C04
    ctx->r5 = ADD32(ctx->r5, 0X4C04);
    func_80008AD8(rdram, ctx);
        goto after_6;
    // 0x80007B48: addiu       $a1, $a1, 0x4C04
    ctx->r5 = ADD32(ctx->r5, 0X4C04);
    after_6:
    // 0x80007B4C: jal         0x8002E768
    // 0x80007B50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002E768(rdram, ctx);
        goto after_7;
    // 0x80007B50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
L_80007B54:
    // 0x80007B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80007B58:
    // 0x80007B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007B5C: jr          $ra
    // 0x80007B60: nop

    return;
    // 0x80007B60: nop

;}
RECOMP_FUNC void nnScAddClient(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800007D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800007D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800007DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800007E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800007E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800007E8: jal         0x80034160
    // 0x800007EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800007EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800007F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800007F4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800007F8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800007FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000800: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80000804: lw          $t7, 0x668($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X668);
    // 0x80000808: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8000080C: jal         0x80034160
    // 0x80000810: sw          $a1, 0x668($v1)
    MEM_W(0X668, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80000810: sw          $a1, 0x668($v1)
    MEM_W(0X668, ctx->r3) = ctx->r5;
    after_1:
    // 0x80000814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000081C: jr          $ra
    // 0x80000820: nop

    return;
    // 0x80000820: nop

;}
RECOMP_FUNC void func_80021434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021434: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80021438: andi        $a3, $a0, 0xFFFF
    ctx->r7 = ctx->r4 & 0XFFFF;
    // 0x8002143C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80021440: lbu         $t6, -0x3088($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3088);
    // 0x80021444: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80021448: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8002144C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80021450: addiu       $v0, $v0, -0x3088
    ctx->r2 = ADD32(ctx->r2, -0X3088);
    // 0x80021454: beq         $t0, $t6, L_800214AC
    if (ctx->r8 == ctx->r14) {
        // 0x80021458: addiu       $a1, $zero, 0x96
        ctx->r5 = ADD32(0, 0X96);
            goto L_800214AC;
    }
    // 0x80021458: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x8002145C: lui         $t1, 0x803B
    ctx->r9 = S32(0X803B << 16);
    // 0x80021460: addiu       $t1, $t1, -0x6E10
    ctx->r9 = ADD32(ctx->r9, -0X6E10);
    // 0x80021464: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80021468: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x8002146C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
L_80021470:
    // 0x80021470: multu       $a0, $t2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021474: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021478: mflo        $t7
    ctx->r15 = lo;
    // 0x8002147C: addu        $a2, $t1, $t7
    ctx->r6 = ADD32(ctx->r9, ctx->r15);
    // 0x80021480: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x80021484: bne         $t3, $t8, L_80021498
    if (ctx->r11 != ctx->r24) {
        // 0x80021488: nop
    
            goto L_80021498;
    }
    // 0x80021488: nop

    // 0x8002148C: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x80021490: xor         $v1, $t9, $a3
    ctx->r3 = ctx->r25 ^ ctx->r7;
    // 0x80021494: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
L_80021498:
    // 0x80021498: bne         $v1, $zero, L_800214AC
    if (ctx->r3 != 0) {
        // 0x8002149C: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800214AC;
    }
    // 0x8002149C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800214A0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800214A4: bne         $t0, $a0, L_80021470
    if (ctx->r8 != ctx->r4) {
        // 0x800214A8: nop
    
            goto L_80021470;
    }
    // 0x800214A8: nop

L_800214AC:
    // 0x800214AC: beq         $v1, $zero, L_80021518
    if (ctx->r3 == 0) {
        // 0x800214B0: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_80021518;
    }
    // 0x800214B0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800214B4: beq         $a1, $zero, L_80021514
    if (ctx->r5 == 0) {
        // 0x800214B8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80021514;
    }
    // 0x800214B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800214BC: andi        $a2, $a1, 0x3
    ctx->r6 = ctx->r5 & 0X3;
    // 0x800214C0: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800214C4: beq         $a2, $zero, L_800214E8
    if (ctx->r6 == 0) {
        // 0x800214C8: addu        $a0, $a2, $a1
        ctx->r4 = ADD32(ctx->r6, ctx->r5);
            goto L_800214E8;
    }
    // 0x800214C8: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_800214CC:
    // 0x800214CC: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x800214D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800214D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800214D8: bne         $a0, $a1, L_800214CC
    if (ctx->r4 != ctx->r5) {
        // 0x800214DC: sb          $t4, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r12;
            goto L_800214CC;
    }
    // 0x800214DC: sb          $t4, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r12;
    // 0x800214E0: beql        $a1, $zero, L_80021518
    if (ctx->r5 == 0) {
        // 0x800214E4: sb          $t9, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r25;
            goto L_80021518;
    }
    goto skip_0;
    // 0x800214E4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    skip_0:
L_800214E8:
    // 0x800214E8: lbu         $t5, 0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1);
    // 0x800214EC: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x800214F0: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x800214F4: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x800214F8: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800214FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021500: sb          $t5, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r13;
    // 0x80021504: sb          $t6, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r14;
    // 0x80021508: sb          $t7, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r15;
    // 0x8002150C: bne         $a1, $zero, L_800214E8
    if (ctx->r5 != 0) {
        // 0x80021510: sb          $t8, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r24;
            goto L_800214E8;
    }
    // 0x80021510: sb          $t8, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r24;
L_80021514:
    // 0x80021514: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80021518:
    // 0x80021518: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8002151C: jr          $ra
    // 0x80021520: nop

    return;
    // 0x80021520: nop

;}
RECOMP_FUNC void func_80019CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019CCC: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x80019CD0: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80019CD4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80019CD8: addiu       $s1, $s1, -0x4D04
    ctx->r17 = ADD32(ctx->r17, -0X4D04);
    // 0x80019CDC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80019CE0: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80019CE4: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x80019CE8: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80019CEC: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80019CF0: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80019CF4: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80019CF8: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80019CFC: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80019D00: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80019D04: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80019D08: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80019D0C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80019D10: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80019D14: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80019D18: sw          $a0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r4;
    // 0x80019D1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019D20: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80019D24: addiu       $t8, $t8, 0x4EA0
    ctx->r24 = ADD32(ctx->r24, 0X4EA0);
    // 0x80019D28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80019D2C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80019D30: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80019D34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80019D38: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80019D3C: lui         $s7, 0x8009
    ctx->r23 = S32(0X8009 << 16);
    // 0x80019D40: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80019D44: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80019D48: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80019D4C: addiu       $s7, $s7, -0x7F58
    ctx->r23 = ADD32(ctx->r23, -0X7F58);
    // 0x80019D50: sw          $t9, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r25;
    // 0x80019D54: addiu       $s4, $s4, -0x4D08
    ctx->r20 = ADD32(ctx->r20, -0X4D08);
    // 0x80019D58: addiu       $s6, $s6, 0x6DC0
    ctx->r22 = ADD32(ctx->r22, 0X6DC0);
    // 0x80019D5C: addiu       $s5, $sp, 0xE0
    ctx->r21 = ADD32(ctx->r29, 0XE0);
L_80019D60:
    // 0x80019D60: lhu         $t3, 0x0($s7)
    ctx->r11 = MEM_HU(ctx->r23, 0X0);
    // 0x80019D64: lw          $v0, 0x154($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X154);
    // 0x80019D68: lui         $t5, 0xFD90
    ctx->r13 = S32(0XFD90 << 16);
    // 0x80019D6C: beq         $t3, $zero, L_8001A1E0
    if (ctx->r11 == 0) {
        // 0x80019D70: addiu       $s0, $s7, 0x10
        ctx->r16 = ADD32(ctx->r23, 0X10);
            goto L_8001A1E0;
    }
    // 0x80019D70: addiu       $s0, $s7, 0x10
    ctx->r16 = ADD32(ctx->r23, 0X10);
    // 0x80019D74: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019D78: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80019D7C: addiu       $t6, $t6, 0x4998
    ctx->r14 = ADD32(ctx->r14, 0X4998);
    // 0x80019D80: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80019D84: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80019D88: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80019D8C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80019D90: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019D94: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x80019D98: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80019D9C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80019DA0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80019DA4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80019DA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80019DAC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019DB0: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80019DB4: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80019DB8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80019DBC: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80019DC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80019DC4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80019DC8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019DCC: lui         $t7, 0x71F
    ctx->r15 = S32(0X71F << 16);
    // 0x80019DD0: ori         $t7, $t7, 0xF200
    ctx->r15 = ctx->r15 | 0XF200;
    // 0x80019DD4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80019DD8: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80019DDC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80019DE0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80019DE4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019DE8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80019DEC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80019DF0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80019DF4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80019DF8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80019DFC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80019E00: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019E04: lui         $t4, 0xF588
    ctx->r12 = S32(0XF588 << 16);
    // 0x80019E08: ori         $t4, $t4, 0x800
    ctx->r12 = ctx->r12 | 0X800;
    // 0x80019E0C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80019E10: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80019E14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80019E18: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80019E1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019E20: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x80019E24: ori         $t7, $t7, 0xC07C
    ctx->r15 = ctx->r15 | 0XC07C;
    // 0x80019E28: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80019E2C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80019E30: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80019E34: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80019E38: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80019E3C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80019E40: addiu       $t9, $t9, 0x4F78
    ctx->r25 = ADD32(ctx->r25, 0X4F78);
    // 0x80019E44: addiu       $t8, $t8, 0x4EF8
    ctx->r24 = ADD32(ctx->r24, 0X4EF8);
    // 0x80019E48: lui         $fp, 0x800C
    ctx->r30 = S32(0X800C << 16);
    // 0x80019E4C: addiu       $s2, $s7, 0x70
    ctx->r18 = ADD32(ctx->r23, 0X70);
    // 0x80019E50: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x80019E54: addiu       $fp, $fp, 0x4EE0
    ctx->r30 = ADD32(ctx->r30, 0X4EE0);
    // 0x80019E58: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
    // 0x80019E5C: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x80019E60: sw          $s0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r16;
L_80019E64:
    // 0x80019E64: lwc1        $f30, 0x4($s2)
    ctx->f30.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80019E68: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80019E6C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80019E70: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80019E74: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x80019E78: swc1        $f30, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f30.u32l;
    // 0x80019E7C: lwc1        $f30, 0x8($s2)
    ctx->f30.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80019E80: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80019E84: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80019E88: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x80019E8C: jal         0x80011860
    // 0x80019E90: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    func_80011860(rdram, ctx);
        goto after_0;
    // 0x80019E90: swc1        $f28, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f28.u32l;
    after_0:
    // 0x80019E94: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80019E98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019E9C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80019EA0: lwc1        $f4, 0xC($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80019EA4: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80019EA8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80019EAC: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80019EB0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80019EB4: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80019EB8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80019EBC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80019EC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80019EC4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80019EC8: jal         0x8002371C
    // 0x80019ECC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_8002371C(rdram, ctx);
        goto after_1;
    // 0x80019ECC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80019ED0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80019ED4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019ED8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80019EDC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80019EE0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80019EE4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80019EE8: jal         0x80023DF4
    // 0x80019EEC: nop

    func_80023DF4(rdram, ctx);
        goto after_2;
    // 0x80019EEC: nop

    after_2:
    // 0x80019EF0: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80019EF4: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x80019EF8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80019EFC: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80019F00: addu        $a1, $t3, $t5
    ctx->r5 = ADD32(ctx->r11, ctx->r13);
    // 0x80019F04: jal         0x80035200
    // 0x80019F08: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x80019F08: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    after_3:
    // 0x80019F0C: lhu         $t6, 0x4($s7)
    ctx->r14 = MEM_HU(ctx->r23, 0X4);
    // 0x80019F10: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80019F14: addiu       $t8, $t8, -0x2FD0
    ctx->r24 = ADD32(ctx->r24, -0X2FD0);
    // 0x80019F18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80019F1C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80019F20: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019F24: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x80019F28: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x80019F2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80019F30: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80019F34: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80019F38: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80019F3C: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x80019F40: addiu       $t7, $t7, 0x0
    ctx->r15 = ADD32(ctx->r15, 0X0);
    // 0x80019F44: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x80019F48: addiu       $t6, $t5, 0xC0
    ctx->r14 = ADD32(ctx->r13, 0XC0);
    // 0x80019F4C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80019F50: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80019F54: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80019F58: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80019F5C: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80019F60: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
    // 0x80019F64: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x80019F68: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019F6C: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80019F70: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80019F74: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80019F78: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80019F7C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80019F80: lhu         $t6, 0x2($s7)
    ctx->r14 = MEM_HU(ctx->r23, 0X2);
    // 0x80019F84: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80019F88: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80019F8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80019F90: lbu         $t9, -0x2FC4($t8)
    ctx->r25 = MEM_BU(ctx->r24, -0X2FC4);
    // 0x80019F94: sll         $t5, $t3, 24
    ctx->r13 = S32(ctx->r11 << 24);
    // 0x80019F98: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x80019F9C: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x80019FA0: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    // 0x80019FA4: sll         $t4, $t8, 16
    ctx->r12 = S32(ctx->r24 << 16);
    // 0x80019FA8: or          $t3, $t6, $t4
    ctx->r11 = ctx->r14 | ctx->r12;
    // 0x80019FAC: sll         $t7, $t5, 8
    ctx->r15 = S32(ctx->r13 << 8);
    // 0x80019FB0: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80019FB4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80019FB8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019FBC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80019FC0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80019FC4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80019FC8: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80019FCC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80019FD0: bne         $s3, $zero, L_80019E64
    if (ctx->r19 != 0) {
        // 0x80019FD4: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80019E64;
    }
    // 0x80019FD4: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80019FD8: lhu         $t9, 0x2($s7)
    ctx->r25 = MEM_HU(ctx->r23, 0X2);
    // 0x80019FDC: lui         $t4, 0xF590
    ctx->r12 = S32(0XF590 << 16);
    // 0x80019FE0: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x80019FE4: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x80019FE8: sh          $t5, 0x2($s7)
    MEM_H(0X2, ctx->r23) = ctx->r13;
    // 0x80019FEC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80019FF0: lui         $t7, 0xFD90
    ctx->r15 = S32(0XFD90 << 16);
    // 0x80019FF4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80019FF8: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80019FFC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001A000: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8001A004: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001A008: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A00C: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x8001A010: ori         $t9, $t9, 0x30
    ctx->r25 = ctx->r25 | 0X30;
    // 0x8001A014: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001A018: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8001A01C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001A020: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8001A024: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A028: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x8001A02C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8001A030: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001A034: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8001A038: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001A03C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8001A040: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A044: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x8001A048: ori         $t6, $t6, 0xF800
    ctx->r14 = ctx->r14 | 0XF800;
    // 0x8001A04C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001A050: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001A054: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001A058: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001A05C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A060: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001A064: lui         $t3, 0xF588
    ctx->r11 = S32(0XF588 << 16);
    // 0x8001A068: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8001A06C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8001A070: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001A074: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001A078: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A07C: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x8001A080: addiu       $t7, $zero, 0x30
    ctx->r15 = ADD32(0, 0X30);
    // 0x8001A084: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8001A088: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8001A08C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001A090: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8001A094: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A098: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8001A09C: ori         $t4, $t4, 0xC01C
    ctx->r12 = ctx->r12 | 0XC01C;
    // 0x8001A0A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001A0A4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8001A0A8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8001A0AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001A0B0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8001A0B4: lw          $s0, 0x8C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8C);
    // 0x8001A0B8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8001A0BC:
    // 0x8001A0BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001A0C0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001A0C4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8001A0C8: lwc1        $f26, 0x0($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001A0CC: lwc1        $f30, 0x8($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001A0D0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8001A0D4: bne         $s3, $zero, L_8001A0E0
    if (ctx->r19 != 0) {
        // 0x8001A0D8: add.s       $f28, $f10, $f0
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f10.fl + ctx->f0.fl;
            goto L_8001A0E0;
    }
    // 0x8001A0D8: add.s       $f28, $f10, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8001A0DC: lw          $s0, 0x8C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8C);
L_8001A0E0:
    // 0x8001A0E0: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001A0E4: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8001A0E8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001A0EC: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8001A0F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001A0F4: sub.s       $f20, $f16, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x8001A0F8: sub.s       $f22, $f4, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x8001A0FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001A100: sub.s       $f24, $f6, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f6.fl - ctx->f30.fl;
    // 0x8001A104: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8001A108: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8001A10C: jal         0x80023A08
    // 0x8001A110: nop

    func_80023A08(rdram, ctx);
        goto after_4;
    // 0x8001A110: nop

    after_4:
    // 0x8001A114: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8001A118: nop

    // 0x8001A11C: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001A120: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001A124: mul.s       $f18, $f24, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001A128: jal         0x80034F60
    // 0x8001A12C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_5;
    // 0x8001A12C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_5:
    // 0x8001A130: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001A134: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001A138: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001A13C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001A140: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8001A144: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8001A148: jal         0x80023DF4
    // 0x8001A14C: nop

    func_80023DF4(rdram, ctx);
        goto after_6;
    // 0x8001A14C: nop

    after_6:
    // 0x8001A150: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8001A154: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x8001A158: swc1        $f26, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f26.u32l;
    // 0x8001A15C: sll         $t3, $t5, 6
    ctx->r11 = S32(ctx->r13 << 6);
    // 0x8001A160: addu        $a1, $t9, $t3
    ctx->r5 = ADD32(ctx->r25, ctx->r11);
    // 0x8001A164: swc1        $f28, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f28.u32l;
    // 0x8001A168: swc1        $f30, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f30.u32l;
    // 0x8001A16C: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x8001A170: jal         0x80035200
    // 0x8001A174: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    guMtxF2L(rdram, ctx);
        goto after_7;
    // 0x8001A174: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x8001A178: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A17C: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x8001A180: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x8001A184: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001A188: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001A18C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001A190: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8001A194: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x8001A198: addiu       $t9, $t9, 0x0
    ctx->r25 = ADD32(ctx->r25, 0X0);
    // 0x8001A19C: sll         $t4, $t6, 6
    ctx->r12 = S32(ctx->r14 << 6);
    // 0x8001A1A0: addiu       $t5, $t4, 0xC0
    ctx->r13 = ADD32(ctx->r12, 0XC0);
    // 0x8001A1A4: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x8001A1A8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8001A1AC: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8001A1B0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001A1B4: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8001A1B8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8001A1BC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8001A1C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001A1C4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8001A1C8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8001A1CC: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x8001A1D0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8001A1D4: bnel        $s3, $zero, L_8001A0BC
    if (ctx->r19 != 0) {
        // 0x8001A1D8: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8001A0BC;
    }
    goto skip_0;
    // 0x8001A1D8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_0:
    // 0x8001A1DC: lw          $v0, 0x154($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X154);
L_8001A1E0:
    // 0x8001A1E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A1E4: addiu       $s7, $s7, 0xD0
    ctx->r23 = ADD32(ctx->r23, 0XD0);
    // 0x8001A1E8: bne         $v0, $zero, L_80019D60
    if (ctx->r2 != 0) {
        // 0x8001A1EC: sw          $v0, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r2;
            goto L_80019D60;
    }
    // 0x8001A1EC: sw          $v0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r2;
    // 0x8001A1F0: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8001A1F4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8001A1F8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8001A1FC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8001A200: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8001A204: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8001A208: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8001A20C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8001A210: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8001A214: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8001A218: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8001A21C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8001A220: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8001A224: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8001A228: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8001A22C: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8001A230: jr          $ra
    // 0x8001A234: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x8001A234: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void func_800004B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800004B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800004B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800004B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800004BC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800004C0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800004C4: addiu       $a2, $a2, -0x7DF8
    ctx->r6 = ADD32(ctx->r6, -0X7DF8);
    // 0x800004C8: addiu       $a1, $a1, -0x7E10
    ctx->r5 = ADD32(ctx->r5, -0X7E10);
    // 0x800004CC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800004D0: jal         0x80033D80
    // 0x800004D4: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_0;
    // 0x800004D4: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_0:
    // 0x800004D8: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800004DC: addiu       $t6, $t6, -0x7E10
    ctx->r14 = ADD32(ctx->r14, -0X7E10);
    // 0x800004E0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800004E4: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800004E8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800004EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800004F0: addiu       $a2, $a2, 0xC50
    ctx->r6 = ADD32(ctx->r6, 0XC50);
    // 0x800004F4: addiu       $a0, $a0, 0x5040
    ctx->r4 = ADD32(ctx->r4, 0X5040);
    // 0x800004F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800004FC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80000500: jal         0x80033AE0
    // 0x80000504: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80000504: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80000508: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8000050C: jal         0x80033C30
    // 0x80000510: addiu       $a0, $a0, 0x5040
    ctx->r4 = ADD32(ctx->r4, 0X5040);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80000510: addiu       $a0, $a0, 0x5040
    ctx->r4 = ADD32(ctx->r4, 0X5040);
    after_2:
L_80000514:
    // 0x80000514: b           L_80000514
    pause_self(rdram);
    // 0x80000518: nop

    // 0x8000051C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80000520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80000524: jr          $ra
    // 0x80000528: nop

    return;
    // 0x80000528: nop

    // 0x8000052C: nop

;}
RECOMP_FUNC void func_80005A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005A10: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80005A14: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80005A18: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80005A1C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80005A20: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x80005A24: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80005A28: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80005A2C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80005A30: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80005A34: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80005A38: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80005A3C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80005A40: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80005A44: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80005A48: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80005A4C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80005A50: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80005A54: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80005A58: lw          $t6, -0x4D1C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4D1C);
    // 0x80005A5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80005A60: andi        $t7, $t6, 0x448D
    ctx->r15 = ctx->r14 & 0X448D;
    // 0x80005A64: bnel        $t7, $zero, L_80005C28
    if (ctx->r15 != 0) {
        // 0x80005A68: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80005C28;
    }
    goto skip_0;
    // 0x80005A68: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x80005A6C: lhu         $t8, 0x8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X8);
    // 0x80005A70: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x80005A74: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80005A78: bnel        $t9, $zero, L_80005C28
    if (ctx->r25 != 0) {
        // 0x80005A7C: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80005C28;
    }
    goto skip_1;
    // 0x80005A7C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_1:
    // 0x80005A80: lw          $s5, -0x4318($s5)
    ctx->r21 = MEM_W(ctx->r21, -0X4318);
    // 0x80005A84: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80005A88: addiu       $s6, $s6, -0x4310
    ctx->r22 = ADD32(ctx->r22, -0X4310);
    // 0x80005A8C: beq         $s5, $zero, L_80005C24
    if (ctx->r21 == 0) {
        // 0x80005A90: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_80005C24;
    }
    // 0x80005A90: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80005A94: lwc1        $f28, 0x10C0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X10C0);
    // 0x80005A98: lui         $at, 0x4018
    ctx->r1 = S32(0X4018 << 16);
    // 0x80005A9C: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x80005AA0: lui         $at, 0xC018
    ctx->r1 = S32(0XC018 << 16);
    // 0x80005AA4: mtc1        $at, $f25
    ctx->f_odd[(25 - 1) * 2] = ctx->r1;
    // 0x80005AA8: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80005AAC: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x80005AB0: lui         $at, 0xC02E
    ctx->r1 = S32(0XC02E << 16);
    // 0x80005AB4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80005AB8: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80005ABC: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x80005AC0: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80005AC4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80005AC8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80005ACC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80005AD0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80005AD4: addiu       $s2, $s2, -0x43D0
    ctx->r18 = ADD32(ctx->r18, -0X43D0);
    // 0x80005AD8: addiu       $s3, $s3, -0x42D0
    ctx->r19 = ADD32(ctx->r19, -0X42D0);
    // 0x80005ADC: addiu       $s7, $zero, 0x210
    ctx->r23 = ADD32(0, 0X210);
    // 0x80005AE0: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
L_80005AE4:
    // 0x80005AE4: lwc1        $f10, 0x4($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80005AE8: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80005AEC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80005AF0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80005AF4: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80005AF8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80005AFC: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80005B00: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005B04: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80005B08: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80005B0C: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80005B10: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x80005B14: nop

    // 0x80005B18: bc1fl       L_80005C14
    if (!c1cs) {
        // 0x80005B1C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_80005C14;
    }
    goto skip_2;
    // 0x80005B1C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_2:
    // 0x80005B20: c.lt.d      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.d < ctx->f22.d;
    // 0x80005B24: nop

    // 0x80005B28: bc1fl       L_80005C14
    if (!c1cs) {
        // 0x80005B2C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_80005C14;
    }
    goto skip_3;
    // 0x80005B2C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_3:
    // 0x80005B30: lhu         $t0, 0x60($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X60);
    // 0x80005B34: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80005B38: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80005B3C: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x80005B40: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80005B44: beq         $t1, $zero, L_80005B54
    if (ctx->r9 == 0) {
        // 0x80005B48: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80005B54;
    }
    // 0x80005B48: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80005B4C: b           L_80005B5C
    // 0x80005B50: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
        goto L_80005B5C;
    // 0x80005B50: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_80005B54:
    // 0x80005B54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80005B58: nop

L_80005B5C:
    // 0x80005B5C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80005B60: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80005B64: nop

    // 0x80005B68: bc1fl       L_80005C14
    if (!c1cs) {
        // 0x80005B6C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_80005C14;
    }
    goto skip_4;
    // 0x80005B6C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_4:
    // 0x80005B70: swc1        $f14, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f14.u32l;
    // 0x80005B74: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x80005B78: jal         0x800232F4
    // 0x80005B7C: lwc1        $f12, 0x10($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80005B7C: lwc1        $f12, 0x10($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X10);
    after_0:
    // 0x80005B80: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80005B84: c.le.s      $f30, $f18
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f30.fl <= ctx->f18.fl;
    // 0x80005B88: nop

    // 0x80005B8C: bc1fl       L_80005C14
    if (!c1cs) {
        // 0x80005B90: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_80005C14;
    }
    goto skip_5;
    // 0x80005B90: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_5:
    // 0x80005B94: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80005B98: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80005B9C: c.lt.d      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.d < ctx->f0.d;
    // 0x80005BA0: nop

    // 0x80005BA4: bc1fl       L_80005C14
    if (!c1cs) {
        // 0x80005BA8: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_80005C14;
    }
    goto skip_6;
    // 0x80005BA8: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_6:
    // 0x80005BAC: c.lt.d      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.d < ctx->f26.d;
    // 0x80005BB0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80005BB4: addiu       $a0, $s1, -0x14
    ctx->r4 = ADD32(ctx->r17, -0X14);
    // 0x80005BB8: bc1fl       L_80005C14
    if (!c1cs) {
        // 0x80005BBC: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_80005C14;
    }
    goto skip_7;
    // 0x80005BBC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    skip_7:
    // 0x80005BC0: beq         $a0, $s3, L_80005C10
    if (ctx->r4 == ctx->r19) {
        // 0x80005BC4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80005C10;
    }
    // 0x80005BC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80005BC8: subu        $t2, $s1, $s3
    ctx->r10 = SUB32(ctx->r17, ctx->r19);
    // 0x80005BCC: addiu       $t3, $t2, -0x14
    ctx->r11 = ADD32(ctx->r10, -0X14);
    // 0x80005BD0: divu        $zero, $t3, $s7
    lo = S32(U32(ctx->r11) / U32(ctx->r23)); hi = S32(U32(ctx->r11) % U32(ctx->r23));
    // 0x80005BD4: mfhi        $a1
    ctx->r5 = hi;
    // 0x80005BD8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80005BDC: bne         $s7, $zero, L_80005BE8
    if (ctx->r23 != 0) {
        // 0x80005BE0: nop
    
            goto L_80005BE8;
    }
    // 0x80005BE0: nop

    // 0x80005BE4: break       7
    do_break(2147507172);
L_80005BE8:
    // 0x80005BE8: addu        $v1, $a1, $s3
    ctx->r3 = ADD32(ctx->r5, ctx->r19);
    // 0x80005BEC: beql        $a1, $zero, L_80005C08
    if (ctx->r5 == 0) {
        // 0x80005BF0: addiu       $v0, $v0, 0x210
        ctx->r2 = ADD32(ctx->r2, 0X210);
            goto L_80005C08;
    }
    goto skip_8;
    // 0x80005BF0: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, 0X210);
    skip_8:
L_80005BF4:
    // 0x80005BF4: addiu       $v0, $v0, 0x84
    ctx->r2 = ADD32(ctx->r2, 0X84);
    // 0x80005BF8: bne         $v1, $v0, L_80005BF4
    if (ctx->r3 != ctx->r2) {
        // 0x80005BFC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80005BF4;
    }
    // 0x80005BFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80005C00: beq         $v0, $a0, L_80005C10
    if (ctx->r2 == ctx->r4) {
        // 0x80005C04: addiu       $v0, $v0, 0x210
        ctx->r2 = ADD32(ctx->r2, 0X210);
            goto L_80005C10;
    }
L_80005C04:
    // 0x80005C04: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, 0X210);
L_80005C08:
    // 0x80005C08: bne         $v0, $a0, L_80005C04
    if (ctx->r2 != ctx->r4) {
        // 0x80005C0C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80005C04;
    }
    // 0x80005C0C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80005C10:
    // 0x80005C10: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80005C14:
    // 0x80005C14: beql        $s5, $zero, L_80005C28
    if (ctx->r21 == 0) {
        // 0x80005C18: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80005C28;
    }
    goto skip_9;
    // 0x80005C18: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_9:
    // 0x80005C1C: beql        $s0, $zero, L_80005AE4
    if (ctx->r16 == 0) {
        // 0x80005C20: lw          $s1, 0x0($s6)
        ctx->r17 = MEM_W(ctx->r22, 0X0);
            goto L_80005AE4;
    }
    goto skip_10;
    // 0x80005C20: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    skip_10:
L_80005C24:
    // 0x80005C24: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80005C28:
    // 0x80005C28: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80005C2C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80005C30: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80005C34: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80005C38: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80005C3C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80005C40: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80005C44: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80005C48: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80005C4C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80005C50: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80005C54: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80005C58: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80005C5C: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x80005C60: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x80005C64: jr          $ra
    // 0x80005C68: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80005C68: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80101958_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101958: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8010195C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101960: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80101964: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x80101968: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8010196C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101970: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80101974: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x80101978: bltzl       $t9, L_8010198C
    if (SIGNED(ctx->r25) < 0) {
        // 0x8010197C: lw          $v1, 0x38($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X38);
            goto L_8010198C;
    }
    goto skip_0;
    // 0x8010197C: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
    skip_0:
    // 0x80101980: jr          $ra
    // 0x80101984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80101984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101988: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
L_8010198C:
    // 0x8010198C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80101990: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80101994: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80101998: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8010199C: lhu         $t0, 0x32($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X32);
    // 0x801019A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801019A4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801019A8: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801019AC: sh          $t1, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r9;
    // 0x801019B0: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801019B4: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x801019B8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801019BC: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x801019C0: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801019C4: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x801019C8: nop

    // 0x801019CC: bc1tl       L_801019E0
    if (c1cs) {
        // 0x801019D0: swc1        $f12, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
            goto L_801019E0;
    }
    goto skip_1;
    // 0x801019D0: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
    skip_1:
    // 0x801019D4: bne         $at, $zero, L_801019E4
    if (ctx->r1 != 0) {
        // 0x801019D8: nop
    
            goto L_801019E4;
    }
    // 0x801019D8: nop

    // 0x801019DC: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
L_801019E0:
    // 0x801019E0: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
L_801019E4:
    // 0x801019E4: bnel        $a1, $zero, L_80101A00
    if (ctx->r5 != 0) {
        // 0x801019E8: sub.s       $f18, $f12, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80101A00;
    }
    goto skip_2;
    // 0x801019E8: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
    // 0x801019EC: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801019F0: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x801019F4: b           L_80101A10
    // 0x801019F8: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
        goto L_80101A10;
    // 0x801019F8: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
    // 0x801019FC: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
L_80101A00:
    // 0x80101A00: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80101A04: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80101A08: nop

    // 0x80101A0C: sh          $t6, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r14;
L_80101A10:
    // 0x80101A10: lhu         $t7, 0x32($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X32);
    // 0x80101A14: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
    // 0x80101A18: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80101A1C: bnel        $at, $zero, L_80101A54
    if (ctx->r1 != 0) {
        // 0x80101A20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80101A54;
    }
    goto skip_3;
    // 0x80101A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80101A24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80101A28: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x80101A2C: bne         $a1, $zero, L_80101A44
    if (ctx->r5 != 0) {
        // 0x80101A30: swc1        $f6, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
            goto L_80101A44;
    }
    // 0x80101A30: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80101A34: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80101A38: sh          $t9, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r25;
    // 0x80101A3C: jr          $ra
    // 0x80101A40: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101A40: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101A44:
    // 0x80101A44: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
    // 0x80101A48: jr          $ra
    // 0x80101A4C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101A4C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101A54:
    // 0x80101A54: jr          $ra
    // 0x80101A58: nop

    return;
    // 0x80101A58: nop

;}
RECOMP_FUNC void func_80006A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006A7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80006A80: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x80006A84: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80006A88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80006A8C: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80006A90: lw          $t6, 0x68($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X68);
    // 0x80006A94: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80006A98: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80006A9C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80006AA0: lw          $t9, -0x35DC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X35DC);
    // 0x80006AA4: lhu         $v0, 0x86($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X86);
    // 0x80006AA8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80006AAC: lhu         $t0, 0x86($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X86);
    // 0x80006AB0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80006AB4: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80006AB8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80006ABC: addiu       $t1, $t0, 0x7
    ctx->r9 = ADD32(ctx->r8, 0X7);
    // 0x80006AC0: sra         $t2, $t1, 3
    ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80006AC4: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80006AC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80006ACC: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80006AD0: div         $zero, $t7, $t3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r11)));
    // 0x80006AD4: mflo        $t4
    ctx->r12 = lo;
    // 0x80006AD8: sh          $t4, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r12;
    // 0x80006ADC: bne         $t3, $zero, L_80006AE8
    if (ctx->r11 != 0) {
        // 0x80006AE0: nop
    
            goto L_80006AE8;
    }
    // 0x80006AE0: nop

    // 0x80006AE4: break       7
    do_break(2147511012);
L_80006AE8:
    // 0x80006AE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80006AEC: bne         $t3, $at, L_80006B00
    if (ctx->r11 != ctx->r1) {
        // 0x80006AF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80006B00;
    }
    // 0x80006AF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006AF4: bne         $t7, $at, L_80006B00
    if (ctx->r15 != ctx->r1) {
        // 0x80006AF8: nop
    
            goto L_80006B00;
    }
    // 0x80006AF8: nop

    // 0x80006AFC: break       6
    do_break(2147511036);
L_80006B00:
    // 0x80006B00: jal         0x80022FD0
    // 0x80006B04: nop

    get_rand(rdram, ctx);
        goto after_0;
    // 0x80006B04: nop

    after_0:
    // 0x80006B08: lh          $t5, 0x1E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X1E);
    // 0x80006B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006B10: sltu        $v0, $v0, $t5
    ctx->r2 = ctx->r2 < ctx->r13 ? 1 : 0;
    // 0x80006B14: jr          $ra
    // 0x80006B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80006B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80020E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E24: jr          $ra
    // 0x80020E28: nop

    return;
    // 0x80020E28: nop

;}
RECOMP_FUNC void func_80037140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037140: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80037144: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80037148: beql        $v0, $zero, L_8003716C
    if (ctx->r2 == 0) {
        // 0x8003714C: sw          $t8, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->r24;
            goto L_8003716C;
    }
    goto skip_0;
    // 0x8003714C: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    skip_0:
    // 0x80037150: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80037154: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80037158: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8003715C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80037160: jr          $ra
    // 0x80037164: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    return;
    // 0x80037164: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x80037168: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
L_8003716C:
    // 0x8003716C: jr          $ra
    // 0x80037170: nop

    return;
    // 0x80037170: nop

    // 0x80037174: jr          $ra
    // 0x80037178: nop

    return;
    // 0x80037178: nop

;}
RECOMP_FUNC void func_800426D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800426D0: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x800426D4: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x800426D8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800426DC: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x800426E0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x800426E4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x800426E8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800426EC: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x800426F0: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x800426F4: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x800426F8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800426FC: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x80042700: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x80042704: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80042708: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8004270C: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x80042710: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x80042714: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x80042718: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8004271C: jr          $ra
    // 0x80042720: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x80042720: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void nnScWaitTaskReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000BB4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80000BB8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000BBC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80000BC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000BC4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000BC8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000BCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000BD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000BD4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80000BD8: jal         0x800347A0
    // 0x80000BDC: lw          $s4, 0xC($a1)
    ctx->r20 = MEM_W(ctx->r5, 0XC);
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80000BDC: lw          $s4, 0xC($a1)
    ctx->r20 = MEM_W(ctx->r5, 0XC);
    after_0:
    // 0x80000BE0: bne         $v0, $s4, L_80000C2C
    if (ctx->r2 != ctx->r20) {
        // 0x80000BE4: addiu       $s2, $s1, 0x11C
        ctx->r18 = ADD32(ctx->r17, 0X11C);
            goto L_80000C2C;
    }
    // 0x80000BE4: addiu       $s2, $s1, 0x11C
    ctx->r18 = ADD32(ctx->r17, 0X11C);
    // 0x80000BE8: addiu       $s3, $sp, 0x44
    ctx->r19 = ADD32(ctx->r29, 0X44);
    // 0x80000BEC: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80000BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80000BF4:
    // 0x80000BF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80000BF8: jal         0x800007D4
    // 0x80000BFC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    nnScAddClient(rdram, ctx);
        goto after_1;
    // 0x80000BFC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80000C00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80000C04: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80000C08: jal         0x80034020
    // 0x80000C0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80000C0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80000C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80000C14: jal         0x80000824
    // 0x80000C18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    nnScRemoveClient(rdram, ctx);
        goto after_3;
    // 0x80000C18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80000C1C: jal         0x800347A0
    // 0x80000C20: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_4;
    // 0x80000C20: nop

    after_4:
    // 0x80000C24: beql        $v0, $s4, L_80000BF4
    if (ctx->r2 == ctx->r20) {
        // 0x80000C28: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80000BF4;
    }
    goto skip_0;
    // 0x80000C28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80000C2C:
    // 0x80000C2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000C30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000C34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000C38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000C3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000C40: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000C44: jr          $ra
    // 0x80000C48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80000C48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8010004C_DA693C_ovl_title(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010004C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100054: jal         0x801000A8
    // 0x80100058: nop

    func_801000A8_ovl_title(rdram, ctx);
        goto after_0;
    // 0x80100058: nop

    after_0:
    // 0x8010005C: bne         $v0, $zero, L_80100094
    if (ctx->r2 != 0) {
        // 0x80100060: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80100094;
    }
    // 0x80100060: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80100064: addiu       $v1, $v1, -0x52BC
    ctx->r3 = ADD32(ctx->r3, -0X52BC);
    // 0x80100068: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010006C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80100070: bne         $v0, $zero, L_80100080
    if (ctx->r2 != 0) {
        // 0x80100074: nop
    
            goto L_80100080;
    }
    // 0x80100074: nop

    // 0x80100078: b           L_80100098
    // 0x8010007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80100098;
    // 0x8010007C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80100080:
    // 0x80100080: bnel        $v0, $at, L_80100098
    if (ctx->r2 != ctx->r1) {
        // 0x80100084: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80100098;
    }
    goto skip_0;
    // 0x80100084: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80100088: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8010008C: b           L_80100098
    // 0x80100090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100098;
    // 0x80100090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100094:
    // 0x80100094: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80100098:
    // 0x80100098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801000A0: jr          $ra
    // 0x801000A4: nop

    return;
    // 0x801000A4: nop

;}
RECOMP_FUNC void func_80020E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E2C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80020E30: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80020E34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80020E38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020E3C: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80020E40: addu        $t2, $a1, $a3
    ctx->r10 = ADD32(ctx->r5, ctx->r7);
    // 0x80020E44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80020E48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80020E4C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80020E50: subu        $t5, $t2, $a1
    ctx->r13 = SUB32(ctx->r10, ctx->r5);
    // 0x80020E54: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x80020E58: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80020E5C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80020E60: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80020E64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80020E68: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80020E6C: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80020E70: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x80020E74: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80020E78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020E7C: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80020E80: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80020E84: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80020E88: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80020E8C: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x80020E90: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80020E94: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80020E98: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80020E9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020EA0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80020EA4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80020EA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80020EAC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80020EB0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020EB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80020EB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020EBC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80020EC0: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80020EC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80020EC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80020ECC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80020ED0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80020ED4: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80020ED8: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80020EDC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80020EE0: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80020EE4: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x80020EE8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80020EEC: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80020EF0: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80020EF4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80020EF8: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80020EFC: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x80020F00: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80020F04: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80020F08: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80020F0C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80020F10: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80020F14: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80020F18: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x80020F1C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80020F20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020F24: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80020F28: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80020F2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80020F30: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80020F34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80020F38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020F3C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80020F40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020F44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80020F48: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80020F4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80020F50: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80020F54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80020F58: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x80020F5C: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80020F60: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80020F64: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80020F68: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80020F6C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80020F70: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80020F74: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x80020F78: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80020F7C: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80020F80: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80020F84: jr          $ra
    // 0x80020F88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80020F88: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000E10C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E10C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000E110: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000E114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000E118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000E11C: lh          $t6, 0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X14);
    // 0x8000E120: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000E124: sh          $t7, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r15;
    // 0x8000E128: lh          $t8, 0x14($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X14);
    // 0x8000E12C: bltzl       $t8, L_8000E214
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000E130: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E214;
    }
    goto skip_0;
    // 0x8000E130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8000E134: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000E138: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E13C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E140: swc1        $f4, -0x3C84($at)
    MEM_W(-0X3C84, ctx->r1) = ctx->f4.u32l;
    // 0x8000E144: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000E148: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E14C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000E150: swc1        $f6, -0x3C80($at)
    MEM_W(-0X3C80, ctx->r1) = ctx->f6.u32l;
    // 0x8000E154: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000E158: addiu       $a1, $a1, 0x2C18
    ctx->r5 = ADD32(ctx->r5, 0X2C18);
    // 0x8000E15C: swc1        $f8, -0x3C7C($at)
    MEM_W(-0X3C7C, ctx->r1) = ctx->f8.u32l;
    // 0x8000E160: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000E164: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8000E168: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8000E16C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8000E170: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E174: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8000E178: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000E17C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8000E180: swc1        $f6, -0x3C70($at)
    MEM_W(-0X3C70, ctx->r1) = ctx->f6.u32l;
    // 0x8000E184: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E188: swc1        $f6, -0x3C74($at)
    MEM_W(-0X3C74, ctx->r1) = ctx->f6.u32l;
    // 0x8000E18C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000E190: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x8000E194: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8000E198: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8000E19C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8000E1A0: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8000E1A4: jal         0x800232F4
    // 0x8000E1A8: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x8000E1A8: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    after_0:
    // 0x8000E1AC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000E1B0: addiu       $a1, $a1, 0x2C18
    ctx->r5 = ADD32(ctx->r5, 0X2C18);
    // 0x8000E1B4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000E1B8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E1BC: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x8000E1C0: swc1        $f4, -0x3C6C($at)
    MEM_W(-0X3C6C, ctx->r1) = ctx->f4.u32l;
    // 0x8000E1C4: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000E1C8: addiu       $t1, $t1, -0x32A8
    ctx->r9 = ADD32(ctx->r9, -0X32A8);
    // 0x8000E1CC: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x8000E1D0: swc1        $f6, -0x3C64($at)
    MEM_W(-0X3C64, ctx->r1) = ctx->f6.u32l;
    // 0x8000E1D4: lh          $t9, 0x14($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X14);
    // 0x8000E1D8: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x8000E1DC: addiu       $a0, $a0, -0x3C9C
    ctx->r4 = ADD32(ctx->r4, -0X3C9C);
    // 0x8000E1E0: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8000E1E4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000E1E8: jal         0x8001B108
    // 0x8000E1EC: sw          $t2, -0x3C8C($at)
    MEM_W(-0X3C8C, ctx->r1) = ctx->r10;
    func_8001B108(rdram, ctx);
        goto after_1;
    // 0x8000E1EC: sw          $t2, -0x3C8C($at)
    MEM_W(-0X3C8C, ctx->r1) = ctx->r10;
    after_1:
    // 0x8000E1F0: lh          $t3, 0x14($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X14);
    // 0x8000E1F4: slti        $at, $t3, 0x7
    ctx->r1 = SIGNED(ctx->r11) < 0X7 ? 1 : 0;
    // 0x8000E1F8: bnel        $at, $zero, L_8000E214
    if (ctx->r1 != 0) {
        // 0x8000E1FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E214;
    }
    goto skip_1;
    // 0x8000E1FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8000E200: jal         0x80022FD0
    // 0x8000E204: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    get_rand(rdram, ctx);
        goto after_2;
    // 0x8000E204: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_2:
    // 0x8000E208: addiu       $t4, $v0, -0x78
    ctx->r12 = ADD32(ctx->r2, -0X78);
    // 0x8000E20C: sh          $t4, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r12;
    // 0x8000E210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000E214:
    // 0x8000E214: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000E21C: jr          $ra
    // 0x8000E220: nop

    return;
    // 0x8000E220: nop

;}
RECOMP_FUNC void func_80018CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018CFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018D00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80018D04: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018D08: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80018D0C: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80018D10: swc1        $f12, -0x30CC($at)
    MEM_W(-0X30CC, ctx->r1) = ctx->f12.u32l;
    // 0x80018D14: swc1        $f14, -0x30C8($at)
    MEM_W(-0X30C8, ctx->r1) = ctx->f14.u32l;
    // 0x80018D18: addiu       $a0, $a0, -0x30E4
    ctx->r4 = ADD32(ctx->r4, -0X30E4);
    // 0x80018D1C: jal         0x8001B108
    // 0x80018D20: swc1        $f4, -0x30C4($at)
    MEM_W(-0X30C4, ctx->r1) = ctx->f4.u32l;
    func_8001B108(rdram, ctx);
        goto after_0;
    // 0x80018D20: swc1        $f4, -0x30C4($at)
    MEM_W(-0X30C4, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80018D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018D2C: jr          $ra
    // 0x80018D30: nop

    return;
    // 0x80018D30: nop

;}
RECOMP_FUNC void alResampleNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004017C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040180: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80040184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040188: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8004018C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80040190: addiu       $a2, $a2, 0x1570
    ctx->r6 = ADD32(ctx->r6, 0X1570);
    // 0x80040194: addiu       $a1, $a1, 0x165C
    ctx->r5 = ADD32(ctx->r5, 0X165C);
    // 0x80040198: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8004019C: jal         0x80048AC0
    // 0x800401A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800401A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800401A4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800401A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800401AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800401B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800401B4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800401B8: jal         0x80036660
    // 0x800401BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800401BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800401C0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800401C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800401C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800401CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800401D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800401D4: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800401D8: sw          $t7, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r15;
    // 0x800401DC: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800401E0: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x800401E4: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x800401E8: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800401EC: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x800401F0: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x800401F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800401F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800401FC: jr          $ra
    // 0x80040200: nop

    return;
    // 0x80040200: nop

;}
RECOMP_FUNC void func_80036874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036874: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80036878: lw          $t6, 0x990($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X990);
    // 0x8003687C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036884: beql        $t6, $zero, L_800368A0
    if (ctx->r14 == 0) {
        // 0x80036888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800368A0;
    }
    goto skip_0;
    // 0x80036888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003688C: jal         0x8003FD40
    // 0x80036890: nop

    func_8003FD40(rdram, ctx);
        goto after_0;
    // 0x80036890: nop

    after_0:
    // 0x80036894: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80036898: sw          $zero, 0x990($at)
    MEM_W(0X990, ctx->r1) = 0;
    // 0x8003689C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800368A0:
    // 0x800368A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800368A4: jr          $ra
    // 0x800368A8: nop

    return;
    // 0x800368A8: nop

;}
RECOMP_FUNC void func_80009934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009934: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009938: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000993C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80009940: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009944: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80009948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000994C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80009950: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009954: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80009958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000995C: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x80009960: jal         0x8000A3F4
    // 0x80009964: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    func_8000A3F4(rdram, ctx);
        goto after_0;
    // 0x80009964: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    after_0:
    // 0x80009968: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000996C: addiu       $a1, $a1, -0x2F30
    ctx->r5 = ADD32(ctx->r5, -0X2F30);
    // 0x80009970: jal         0x8000A7D8
    // 0x80009974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000A7D8(rdram, ctx);
        goto after_1;
    // 0x80009974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80009978: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000997C: addiu       $v0, $v0, -0x2F30
    ctx->r2 = ADD32(ctx->r2, -0X2F30);
    // 0x80009980: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80009984: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80009988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000998C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80009990: jal         0x8000A508
    // 0x80009994: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_8000A508(rdram, ctx);
        goto after_2;
    // 0x80009994: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x80009998: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x8000999C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800099A0: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x800099A4: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x800099A8: bnel        $t8, $zero, L_800099CC
    if (ctx->r24 != 0) {
        // 0x800099AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800099CC;
    }
    goto skip_0;
    // 0x800099AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800099B0: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x800099B4: lhu         $t9, 0x60($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X60);
    // 0x800099B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800099BC: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x800099C0: jal         0x8001D358
    // 0x800099C4: sh          $t0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r8;
    func_8001D358(rdram, ctx);
        goto after_3;
    // 0x800099C4: sh          $t0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r8;
    after_3:
    // 0x800099C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800099CC:
    // 0x800099CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800099D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800099D4: jr          $ra
    // 0x800099D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800099D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80005748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005748: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000574C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80005750: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80005754: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80005758: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8000575C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80005760: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80005764: lhu         $v0, -0x3A6E($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3A6E);
    // 0x80005768: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8000576C: beq         $t6, $zero, L_8000592C
    if (ctx->r14 == 0) {
        // 0x80005770: andi        $t7, $v0, 0x6
        ctx->r15 = ctx->r2 & 0X6;
            goto L_8000592C;
    }
    // 0x80005770: andi        $t7, $v0, 0x6
    ctx->r15 = ctx->r2 & 0X6;
    // 0x80005774: bnel        $t7, $zero, L_80005930
    if (ctx->r15 != 0) {
        // 0x80005778: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80005930;
    }
    goto skip_0;
    // 0x80005778: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    skip_0:
    // 0x8000577C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005780: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80005784: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005788: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8000578C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005790: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80005794: lwc1        $f10, -0x3A5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A5C);
    // 0x80005798: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000579C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800057A0: lwc1        $f6, -0x3BD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3BD0);
    // 0x800057A4: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800057A8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800057AC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800057B0: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800057B4: nop

    // 0x800057B8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800057BC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800057C0: jal         0x80034F60
    // 0x800057C4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x800057C4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800057C8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800057CC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800057D0: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800057D4: lwc1        $f18, 0x110($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X110);
    // 0x800057D8: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800057DC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800057E0: nop

    // 0x800057E4: bc1fl       L_80005830
    if (!c1cs) {
        // 0x800057E8: lwc1        $f4, 0x0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80005830;
    }
    goto skip_1;
    // 0x800057E8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800057EC: mul.s       $f4, $f12, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800057F0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800057F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800057F8: lwc1        $f16, -0x3A5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3A5C);
    // 0x800057FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80005800: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80005804: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80005808: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000580C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005810: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80005814: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005818: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8000581C: lwc1        $f16, -0x3BD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3BD0);
    // 0x80005820: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80005824: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005828: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8000582C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
L_80005830:
    // 0x80005830: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80005834: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005838: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8000583C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005840: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80005844: lwc1        $f10, -0x3A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A64);
    // 0x80005848: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000584C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80005850: lwc1        $f6, -0x3A60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A60);
    // 0x80005854: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80005858: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000585C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005860: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80005864: nop

    // 0x80005868: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000586C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80005870: jal         0x80034F60
    // 0x80005874: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x80005874: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80005878: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8000587C: lhu         $t8, -0x3A6E($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X3A6E);
    // 0x80005880: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80005884: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005888: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x8000588C: beq         $t9, $zero, L_800058F8
    if (ctx->r25 == 0) {
        // 0x80005890: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_800058F8;
    }
    // 0x80005890: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80005894: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80005898: addiu       $v0, $v0, -0x3BCC
    ctx->r2 = ADD32(ctx->r2, -0X3BCC);
    // 0x8000589C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800058A0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800058A4: nop

    // 0x800058A8: bc1fl       L_80005930
    if (!c1cs) {
        // 0x800058AC: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_80005930;
    }
    goto skip_2;
    // 0x800058AC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    skip_2:
    // 0x800058B0: mul.s       $f16, $f12, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800058B4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800058B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800058BC: lwc1        $f8, -0x3A64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A64);
    // 0x800058C0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800058C4: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800058C8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800058CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800058D0: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800058D4: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x800058D8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800058DC: lwc1        $f10, -0x3A60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A60);
    // 0x800058E0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800058E4: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800058E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800058EC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800058F0: b           L_8000592C
    // 0x800058F4: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
        goto L_8000592C;
    // 0x800058F4: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
L_800058F8:
    // 0x800058F8: addiu       $v0, $v0, -0x3BCC
    ctx->r2 = ADD32(ctx->r2, -0X3BCC);
    // 0x800058FC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80005900: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80005904: nop

    // 0x80005908: bc1fl       L_80005924
    if (!c1cs) {
        // 0x8000590C: lhu         $t2, 0x8($a2)
        ctx->r10 = MEM_HU(ctx->r6, 0X8);
            goto L_80005924;
    }
    goto skip_3;
    // 0x8000590C: lhu         $t2, 0x8($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X8);
    skip_3:
    // 0x80005910: lhu         $t0, 0x8($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X8);
    // 0x80005914: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80005918: b           L_8000592C
    // 0x8000591C: sh          $t1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r9;
        goto L_8000592C;
    // 0x8000591C: sh          $t1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r9;
    // 0x80005920: lhu         $t2, 0x8($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X8);
L_80005924:
    // 0x80005924: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x80005928: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
L_8000592C:
    // 0x8000592C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_80005930:
    // 0x80005930: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    // 0x80005934: jal         0x80005C6C
    // 0x80005938: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80005C6C(rdram, ctx);
        goto after_2;
    // 0x80005938: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x8000593C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80005940: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80005944: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005948: swc1        $f4, -0x45AC($at)
    MEM_W(-0X45AC, ctx->r1) = ctx->f4.u32l;
    // 0x8000594C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80005950: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80005954: addiu       $v0, $v0, -0x43C0
    ctx->r2 = ADD32(ctx->r2, -0X43C0);
    // 0x80005958: swc1        $f6, -0x45A8($at)
    MEM_W(-0X45A8, ctx->r1) = ctx->f6.u32l;
    // 0x8000595C: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80005960: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80005964: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80005968: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8000596C: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80005970: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005974: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80005978: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000597C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80005980: lhu         $a3, 0x3A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X3A);
    // 0x80005984: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80005988: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8000598C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80005990: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80005994: jal         0x8000EE60
    // 0x80005998: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8000EE60(rdram, ctx);
        goto after_3;
    // 0x80005998: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x8000599C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800059A0: addiu       $v0, $v0, -0x43C0
    ctx->r2 = ADD32(ctx->r2, -0X43C0);
    // 0x800059A4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800059A8: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800059AC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800059B0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800059B4: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800059B8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800059BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800059C0: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800059C4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800059C8: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800059CC: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800059D0: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x800059D4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800059D8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800059DC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800059E0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x800059E4: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800059E8: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x800059EC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800059F0: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x800059F4: lhu         $t4, 0x18($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X18);
    // 0x800059F8: sh          $t4, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r12;
    // 0x800059FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80005A00: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80005A04: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80005A08: jr          $ra
    // 0x80005A0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80005A0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8001B108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B108: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8001B10C: lhu         $t6, -0x7BD8($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X7BD8);
    // 0x8001B110: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001B114: addiu       $v1, $v1, -0x7BD8
    ctx->r3 = ADD32(ctx->r3, -0X7BD8);
    // 0x8001B118: beq         $t6, $zero, L_8001B138
    if (ctx->r14 == 0) {
        // 0x8001B11C: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_8001B138;
    }
    // 0x8001B11C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x8001B120: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001B124:
    // 0x8001B124: beq         $v0, $zero, L_8001B138
    if (ctx->r2 == 0) {
        // 0x8001B128: addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
            goto L_8001B138;
    }
    // 0x8001B128: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x8001B12C: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x8001B130: bnel        $t7, $zero, L_8001B124
    if (ctx->r15 != 0) {
        // 0x8001B134: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001B124;
    }
    goto skip_0;
    // 0x8001B134: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
L_8001B138:
    // 0x8001B138: beq         $v0, $zero, L_8001B18C
    if (ctx->r2 == 0) {
        // 0x8001B13C: or          $t0, $a0, $zero
        ctx->r8 = ctx->r4 | 0;
            goto L_8001B18C;
    }
    // 0x8001B13C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8001B140: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8001B144: addiu       $v0, $v0, -0x7BE0
    ctx->r2 = ADD32(ctx->r2, -0X7BE0);
    // 0x8001B148: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8001B14C: addiu       $t9, $a0, 0x3C
    ctx->r25 = ADD32(ctx->r4, 0X3C);
L_8001B150:
    // 0x8001B150: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8001B154: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8001B158: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8001B15C: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x8001B160: lw          $at, -0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X8);
    // 0x8001B164: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x8001B168: lw          $at, -0x4($t0)
    ctx->r1 = MEM_W(ctx->r8, -0X4);
    // 0x8001B16C: bne         $t0, $t9, L_8001B150
    if (ctx->r8 != ctx->r25) {
        // 0x8001B170: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_8001B150;
    }
    // 0x8001B170: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x8001B174: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8001B178: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8001B17C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8001B180: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8001B184: b           L_8001B190
    // 0x8001B188: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8001B190;
    // 0x8001B188: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8001B18C:
    // 0x8001B18C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001B190:
    // 0x8001B190: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001B194: jr          $ra
    // 0x8001B198: nop

    return;
    // 0x8001B198: nop

;}
RECOMP_FUNC void func_80049C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049C48: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x80049C4C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80049C50: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x80049C54: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80049C58: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80049C5C: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x80049C60: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x80049C64: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x80049C68: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80049C6C: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80049C70: jr          $ra
    // 0x80049C74: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x80049C74: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void nnScGetAudioMQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800006F8: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x800006FC: jr          $ra
    // 0x80000700: nop

    return;
    // 0x80000700: nop

;}
RECOMP_FUNC void func_80023E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E80: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80023E84: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x80023E88: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x80023E8C: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80023E90: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80023E94: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80023E98: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80023E9C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80023EA0: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80023EA4: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80023EA8: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80023EAC: lwc1        $f20, 0x20($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80023EB0: lwc1        $f22, 0x24($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80023EB4: lwc1        $f24, 0x28($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80023EB8: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x80023EBC: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80023EC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023EC4: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80023EC8: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80023ECC: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80023ED0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80023ED4: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80023ED8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80023EDC: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x80023EE0: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80023EE4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80023EE8: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80023EEC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80023EF0: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80023EF4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80023EF8: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80023EFC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80023F00: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80023F04: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80023F08: lwc1        $f8, 0x24($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80023F0C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80023F10: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80023F14: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80023F18: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80023F1C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023F20: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80023F24: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80023F28: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80023F2C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80023F30: lwc1        $f8, 0x38($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80023F34: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023F38: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80023F3C: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80023F40: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80023F44: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80023F48: mul.s       $f4, $f20, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80023F4C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80023F50: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80023F54: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80023F58: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80023F5C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80023F60: nop

    // 0x80023F64: mul.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80023F68: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80023F6C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80023F70: mul.s       $f10, $f20, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x80023F74: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80023F78: swc1        $f8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f8.u32l;
    // 0x80023F7C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80023F80: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80023F84: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80023F88: nop

    // 0x80023F8C: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80023F90: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023F94: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80023F98: mul.s       $f6, $f20, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80023F9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80023FA0: swc1        $f8, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f8.u32l;
    // 0x80023FA4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80023FA8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023FAC: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80023FB0: nop

    // 0x80023FB4: mul.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80023FB8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80023FBC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80023FC0: mul.s       $f4, $f20, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80023FC4: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80023FC8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80023FCC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80023FD0: swc1        $f10, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f10.u32l;
    // 0x80023FD4: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80023FD8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80023FDC: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80023FE0: nop

    // 0x80023FE4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80023FE8: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80023FEC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80023FF0: mul.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80023FF4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80023FF8: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x80023FFC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80024000: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80024004: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80024008: nop

    // 0x8002400C: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80024010: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80024014: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80024018: mul.s       $f4, $f22, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8002401C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80024020: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x80024024: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80024028: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002402C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80024030: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80024034: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80024038: lwc1        $f20, 0x20($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002403C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80024040: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80024044: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80024048: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8002404C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80024050: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80024054: nop

    // 0x80024058: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8002405C: swc1        $f10, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f10.u32l;
    // 0x80024060: mul.s       $f10, $f22, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80024064: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80024068: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002406C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80024070: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80024074: swc1        $f6, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f6.u32l;
    // 0x80024078: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002407C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80024080: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80024084: nop

    // 0x80024088: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8002408C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80024090: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80024094: mul.s       $f4, $f24, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80024098: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002409C: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x800240A0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800240A4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800240A8: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800240AC: nop

    // 0x800240B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800240B4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800240B8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800240BC: mul.s       $f10, $f24, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x800240C0: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800240C4: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
    // 0x800240C8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800240CC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800240D0: mul.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800240D4: nop

    // 0x800240D8: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800240DC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800240E0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800240E4: mul.s       $f8, $f24, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f10.fl);
    // 0x800240E8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800240EC: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800240F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800240F4: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800240F8: swc1        $f6, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f6.u32l;
    // 0x800240FC: mul.s       $f6, $f24, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x80024100: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80024104: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80024108: swc1        $f0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f0.u32l;
    // 0x8002410C: swc1        $f0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f0.u32l;
    // 0x80024110: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80024114: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80024118: swc1        $f0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f0.u32l;
    // 0x8002411C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80024120: swc1        $f6, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f6.u32l;
    // 0x80024124: swc1        $f8, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f8.u32l;
    // 0x80024128: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8002412C: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x80024130: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x80024134: jr          $ra
    // 0x80024138: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80024138: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80018DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018DF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80018DF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80018DFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80018E00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018E04: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80018E08: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80018E0C: lhu         $t6, 0x73DC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X73DC);
    // 0x80018E10: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80018E14: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x80018E18: beq         $t6, $zero, L_80018E38
    if (ctx->r14 == 0) {
        // 0x80018E1C: addiu       $t0, $t0, 0x73D0
        ctx->r8 = ADD32(ctx->r8, 0X73D0);
            goto L_80018E38;
    }
    // 0x80018E1C: addiu       $t0, $t0, 0x73D0
    ctx->r8 = ADD32(ctx->r8, 0X73D0);
    // 0x80018E20: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_80018E24:
    // 0x80018E24: beq         $a3, $zero, L_80018E38
    if (ctx->r7 == 0) {
        // 0x80018E28: addiu       $t0, $t0, 0x1C
        ctx->r8 = ADD32(ctx->r8, 0X1C);
            goto L_80018E38;
    }
    // 0x80018E28: addiu       $t0, $t0, 0x1C
    ctx->r8 = ADD32(ctx->r8, 0X1C);
    // 0x80018E2C: lhu         $t7, 0xC($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0XC);
    // 0x80018E30: bnel        $t7, $zero, L_80018E24
    if (ctx->r15 != 0) {
        // 0x80018E34: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80018E24;
    }
    goto skip_0;
    // 0x80018E34: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    skip_0:
L_80018E38:
    // 0x80018E38: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80018E3C: sh          $t8, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r24;
    // 0x80018E40: sw          $s0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r16;
    // 0x80018E44: sw          $a1, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r5;
    // 0x80018E48: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80018E4C: addiu       $a1, $t0, 0x4
    ctx->r5 = ADD32(ctx->r8, 0X4);
    // 0x80018E50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80018E54: bgez        $t9, L_80018E60
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80018E58: negu        $t1, $t9
        ctx->r9 = SUB32(0, ctx->r25);
            goto L_80018E60;
    }
    // 0x80018E58: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x80018E5C: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
L_80018E60:
    // 0x80018E60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80018E64: jal         0x80024330
    // 0x80018E68: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    count_digits(rdram, ctx);
        goto after_0;
    // 0x80018E68: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x80018E6C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80018E70: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80018E74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80018E78: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x80018E7C: lhu         $t2, 0x73DC($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X73DC);
    // 0x80018E80: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018E84: addiu       $v0, $v0, 0x7408
    ctx->r2 = ADD32(ctx->r2, 0X7408);
    // 0x80018E88: beq         $t2, $zero, L_80018EA4
    if (ctx->r10 == 0) {
        // 0x80018E8C: lui         $t4, 0x8008
        ctx->r12 = S32(0X8008 << 16);
            goto L_80018EA4;
    }
    // 0x80018E8C: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80018E90: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80018E94: lw          $t3, 0x73D0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X73D0);
    // 0x80018E98: bne         $s0, $t3, L_80018EA4
    if (ctx->r16 != ctx->r11) {
        // 0x80018E9C: nop
    
            goto L_80018EA4;
    }
    // 0x80018E9C: nop

    // 0x80018EA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80018EA4:
    // 0x80018EA4: lhu         $t4, 0x73F8($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X73F8);
    // 0x80018EA8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80018EAC: addiu       $a0, $a0, 0x74E8
    ctx->r4 = ADD32(ctx->r4, 0X74E8);
    // 0x80018EB0: beq         $t4, $zero, L_80018EC8
    if (ctx->r12 == 0) {
        // 0x80018EB4: lui         $t5, 0x8008
        ctx->r13 = S32(0X8008 << 16);
            goto L_80018EC8;
    }
    // 0x80018EB4: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80018EB8: lw          $t5, 0x73EC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X73EC);
    // 0x80018EBC: bne         $s0, $t5, L_80018EC8
    if (ctx->r16 != ctx->r13) {
        // 0x80018EC0: nop
    
            goto L_80018EC8;
    }
    // 0x80018EC0: nop

    // 0x80018EC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80018EC8:
    // 0x80018EC8: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
L_80018ECC:
    // 0x80018ECC: beql        $t6, $zero, L_80018EE8
    if (ctx->r14 == 0) {
        // 0x80018ED0: lhu         $t8, 0x28($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X28);
            goto L_80018EE8;
    }
    goto skip_1;
    // 0x80018ED0: lhu         $t8, 0x28($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X28);
    skip_1:
    // 0x80018ED4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80018ED8: bnel        $s0, $t7, L_80018EE8
    if (ctx->r16 != ctx->r15) {
        // 0x80018EDC: lhu         $t8, 0x28($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X28);
            goto L_80018EE8;
    }
    goto skip_2;
    // 0x80018EDC: lhu         $t8, 0x28($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X28);
    skip_2:
    // 0x80018EE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80018EE4: lhu         $t8, 0x28($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X28);
L_80018EE8:
    // 0x80018EE8: beql        $t8, $zero, L_80018F04
    if (ctx->r24 == 0) {
        // 0x80018EEC: lhu         $t1, 0x44($v0)
        ctx->r9 = MEM_HU(ctx->r2, 0X44);
            goto L_80018F04;
    }
    goto skip_3;
    // 0x80018EEC: lhu         $t1, 0x44($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X44);
    skip_3:
    // 0x80018EF0: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80018EF4: bnel        $s0, $t9, L_80018F04
    if (ctx->r16 != ctx->r25) {
        // 0x80018EF8: lhu         $t1, 0x44($v0)
        ctx->r9 = MEM_HU(ctx->r2, 0X44);
            goto L_80018F04;
    }
    goto skip_4;
    // 0x80018EF8: lhu         $t1, 0x44($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X44);
    skip_4:
    // 0x80018EFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80018F00: lhu         $t1, 0x44($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X44);
L_80018F04:
    // 0x80018F04: beql        $t1, $zero, L_80018F20
    if (ctx->r9 == 0) {
        // 0x80018F08: lhu         $t3, 0x60($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X60);
            goto L_80018F20;
    }
    goto skip_5;
    // 0x80018F08: lhu         $t3, 0x60($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X60);
    skip_5:
    // 0x80018F0C: lw          $t2, 0x38($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X38);
    // 0x80018F10: bnel        $s0, $t2, L_80018F20
    if (ctx->r16 != ctx->r10) {
        // 0x80018F14: lhu         $t3, 0x60($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X60);
            goto L_80018F20;
    }
    goto skip_6;
    // 0x80018F14: lhu         $t3, 0x60($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X60);
    skip_6:
    // 0x80018F18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80018F1C: lhu         $t3, 0x60($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X60);
L_80018F20:
    // 0x80018F20: beql        $t3, $zero, L_80018F3C
    if (ctx->r11 == 0) {
        // 0x80018F24: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80018F3C;
    }
    goto skip_7;
    // 0x80018F24: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_7:
    // 0x80018F28: lw          $t4, 0x54($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X54);
    // 0x80018F2C: bnel        $s0, $t4, L_80018F3C
    if (ctx->r16 != ctx->r12) {
        // 0x80018F30: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80018F3C;
    }
    goto skip_8;
    // 0x80018F30: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    skip_8:
    // 0x80018F34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80018F38: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
L_80018F3C:
    // 0x80018F3C: bnel        $v0, $a0, L_80018ECC
    if (ctx->r2 != ctx->r4) {
        // 0x80018F40: lhu         $t6, 0xC($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0XC);
            goto L_80018ECC;
    }
    goto skip_9;
    // 0x80018F40: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    skip_9:
    // 0x80018F44: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80018F48: sw          $t5, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r13;
    // 0x80018F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018F50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80018F54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80018F58: jr          $ra
    // 0x80018F5C: nop

    return;
    // 0x80018F5C: nop

;}
RECOMP_FUNC void func_80048F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048F54: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80048F58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80048F5C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80048F60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80048F64: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80048F68: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x80048F6C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80048F70: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80048F74: beq         $t6, $zero, L_80049130
    if (ctx->r14 == 0) {
        // 0x80048F78: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_80049130;
    }
    // 0x80048F78: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x80048F7C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80048F80: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80048F84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80048F88: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80048F8C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80048F90: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80048F94: jal         0x80048AE0
    // 0x80048F98: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    func_80048AE0(rdram, ctx);
        goto after_0;
    // 0x80048F98: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_0:
    // 0x80048F9C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80048FA0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80048FA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048FA8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80048FAC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80048FB0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80048FB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80048FB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80048FBC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80048FC0: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x80048FC4: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80048FC8: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80048FCC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80048FD0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80048FD4: nop

    // 0x80048FD8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80048FDC: nop

    // 0x80048FE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80048FE4: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80048FE8: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80048FEC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80048FF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80048FF4: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x80048FF8: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80048FFC: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80049000: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x80049004: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80049008: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8004900C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80049010: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80049014: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80049018: nop

    // 0x8004901C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80049020: nop

    // 0x80049024: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80049028: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8004902C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x80049030: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x80049034: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80049038: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8004903C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80049040: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x80049044: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80049048: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8004904C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x80049050: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x80049054: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80049058: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8004905C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80049060: subu        $a1, $t0, $t3
    ctx->r5 = SUB32(ctx->r8, ctx->r11);
    // 0x80049064: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80049068: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8004906C: addu        $a3, $t1, $t8
    ctx->r7 = ADD32(ctx->r9, ctx->r24);
    // 0x80049070: jal         0x80048DC8
    // 0x80049074: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80048DC8(rdram, ctx);
        goto after_1;
    // 0x80049074: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x80049078: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8004907C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80049080: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80049084: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x80049088: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x8004908C: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x80049090: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80049094: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80049098: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x8004909C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800490A0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800490A4: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800490A8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800490AC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800490B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800490B4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800490B8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800490BC: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x800490C0: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800490C4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800490C8: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x800490CC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800490D0: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800490D4: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800490D8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800490DC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800490E0: nop

    // 0x800490E4: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800490E8: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x800490EC: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800490F0: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800490F4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800490F8: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x800490FC: jal         0x80034DD0
    // 0x80049100: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80049100: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80049104: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80049108: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8004910C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80049110: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x80049114: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80049118: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x8004911C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x80049120: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x80049124: subu        $t5, $t9, $s1
    ctx->r13 = SUB32(ctx->r25, ctx->r17);
    // 0x80049128: b           L_80049160
    // 0x8004912C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_80049160;
    // 0x8004912C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_80049130:
    // 0x80049130: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80049134: lw          $t7, 0x18($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X18);
    // 0x80049138: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8004913C: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x80049140: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x80049144: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80049148: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8004914C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80049150: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x80049154: jal         0x80048DC8
    // 0x80049158: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80048DC8(rdram, ctx);
        goto after_3;
    // 0x80049158: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x8004915C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80049160:
    // 0x80049160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80049164: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80049168: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8004916C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80049170: jr          $ra
    // 0x80049174: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80049174: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8001E138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E138: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8001E13C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001E140: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E144: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001E148: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001E14C: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8001E150: lwc1        $f18, 0x10($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001E154: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8001E158: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001E15C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E160: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8001E164: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8001E168: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001E16C: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8001E170: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8001E174: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001E178: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x8001E17C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001E180: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001E184: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001E188: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8001E18C: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001E190: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001E194: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8001E198: mul.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8001E19C: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8001E1A0: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8001E1A4: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8001E1A8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8001E1AC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8001E1B0: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001E1B4: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001E1B8: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8001E1BC: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8001E1C0: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8001E1C4: nop

    // 0x8001E1C8: mul.s       $f16, $f2, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8001E1CC: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8001E1D0: mul.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8001E1D4: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001E1D8: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8001E1DC: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8001E1E0: swc1        $f16, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f16.u32l;
    // 0x8001E1E4: jr          $ra
    // 0x8001E1E8: nop

    return;
    // 0x8001E1E8: nop

;}
RECOMP_FUNC void func_80024BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024BEC: addiu       $sp, $sp, -0x1B8
    ctx->r29 = ADD32(ctx->r29, -0X1B8);
    // 0x80024BF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80024BF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80024BF8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80024BFC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80024C00: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80024C04: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80024C08: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80024C0C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80024C10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80024C14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80024C18: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80024C1C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80024C20: lw          $t6, -0x9F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X9F0);
    // 0x80024C24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80024C28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024C2C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80024C30: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80024C34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80024C38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80024C3C: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
    // 0x80024C40: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80024C44: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80024C48: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80024C4C: addiu       $a0, $sp, 0x1A0
    ctx->r4 = ADD32(ctx->r29, 0X1A0);
    // 0x80024C50: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80024C54: addiu       $a1, $sp, 0x180
    ctx->r5 = ADD32(ctx->r29, 0X180);
    // 0x80024C58: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80024C5C: div.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80024C60: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80024C64: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80024C68: nop

    // 0x80024C6C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80024C70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80024C74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80024C78: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80024C7C: nop

    // 0x80024C80: bc1fl       L_80024C90
    if (!c1cs) {
        // 0x80024C84: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_80024C90;
    }
    goto skip_0;
    // 0x80024C84: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    skip_0:
    // 0x80024C88: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80024C8C: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
L_80024C90:
    // 0x80024C90: beq         $t8, $zero, L_80024C9C
    if (ctx->r24 == 0) {
        // 0x80024C94: and         $t9, $v0, $at
        ctx->r25 = ctx->r2 & ctx->r1;
            goto L_80024C9C;
    }
    // 0x80024C94: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x80024C98: addiu       $v0, $t9, 0x10
    ctx->r2 = ADD32(ctx->r25, 0X10);
L_80024C9C:
    // 0x80024C9C: jal         0x80033F10
    // 0x80024CA0: sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80024CA0: sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    after_0:
    // 0x80024CA4: addiu       $a0, $sp, 0x168
    ctx->r4 = ADD32(ctx->r29, 0X168);
    // 0x80024CA8: addiu       $a1, $sp, 0x148
    ctx->r5 = ADD32(ctx->r29, 0X148);
    // 0x80024CAC: jal         0x80033F10
    // 0x80024CB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80024CB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x80024CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024CB8: addiu       $a1, $sp, 0x140
    ctx->r5 = ADD32(ctx->r29, 0X140);
    // 0x80024CBC: jal         0x800007D4
    // 0x80024CC0: addiu       $a2, $sp, 0x1A0
    ctx->r6 = ADD32(ctx->r29, 0X1A0);
    nnScAddClient(rdram, ctx);
        goto after_2;
    // 0x80024CC0: addiu       $a2, $sp, 0x1A0
    ctx->r6 = ADD32(ctx->r29, 0X1A0);
    after_2:
    // 0x80024CC4: jal         0x800006F8
    // 0x80024CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    nnScGetAudioMQ(rdram, ctx);
        goto after_3;
    // 0x80024CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80024CCC: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x80024CD0: sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    // 0x80024CD4: addiu       $fp, $fp, -0x688
    ctx->r30 = ADD32(ctx->r30, -0X688);
    // 0x80024CD8: addiu       $s7, $zero, 0x1C
    ctx->r23 = ADD32(0, 0X1C);
    // 0x80024CDC: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_80024CE0:
    // 0x80024CE0: addiu       $a0, $sp, 0x1A0
    ctx->r4 = ADD32(ctx->r29, 0X1A0);
L_80024CE4:
    // 0x80024CE4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80024CE8: jal         0x80034020
    // 0x80024CEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80024CEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80024CF0: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80024CF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024CF8: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x80024CFC: beq         $v1, $at, L_80024D14
    if (ctx->r3 == ctx->r1) {
        // 0x80024D00: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80024D14;
    }
    // 0x80024D00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024D04: beq         $v1, $at, L_80024FC8
    if (ctx->r3 == ctx->r1) {
        // 0x80024D08: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_80024FC8;
    }
    // 0x80024D08: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80024D0C: b           L_80024CE4
    // 0x80024D10: addiu       $a0, $sp, 0x1A0
    ctx->r4 = ADD32(ctx->r29, 0X1A0);
        goto L_80024CE4;
    // 0x80024D10: addiu       $a0, $sp, 0x1A0
    ctx->r4 = ADD32(ctx->r29, 0X1A0);
L_80024D14:
    // 0x80024D14: jal         0x8002571C
    // 0x80024D18: nop

    func_8002571C(rdram, ctx);
        goto after_5;
    // 0x80024D18: nop

    after_5:
    // 0x80024D1C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80024D20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024D24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80024D28: beq         $t1, $at, L_80024D44
    if (ctx->r9 == ctx->r1) {
        // 0x80024D2C: addiu       $s0, $sp, 0x5C
        ctx->r16 = ADD32(ctx->r29, 0X5C);
            goto L_80024D44;
    }
    // 0x80024D2C: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x80024D30: beql        $t1, $s4, L_80024CE4
    if (ctx->r9 == ctx->r20) {
        // 0x80024D34: addiu       $a0, $sp, 0x1A0
        ctx->r4 = ADD32(ctx->r29, 0X1A0);
            goto L_80024CE4;
    }
    goto skip_1;
    // 0x80024D34: addiu       $a0, $sp, 0x1A0
    ctx->r4 = ADD32(ctx->r29, 0X1A0);
    skip_1:
    // 0x80024D38: lw          $s3, 0x130($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X130);
    // 0x80024D3C: b           L_80024DF8
    // 0x80024D40: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
        goto L_80024DF8;
    // 0x80024D40: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
L_80024D44:
    // 0x80024D44: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
L_80024D48:
    // 0x80024D48: lh          $t3, 0x0($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X0);
    // 0x80024D4C: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80024D50: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80024D54: div         $zero, $t3, $s7
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r23)));
    // 0x80024D58: mflo        $t4
    ctx->r12 = lo;
    // 0x80024D5C: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x80024D60: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x80024D64: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80024D68: bne         $s7, $zero, L_80024D74
    if (ctx->r23 != 0) {
        // 0x80024D6C: nop
    
            goto L_80024D74;
    }
    // 0x80024D6C: nop

    // 0x80024D70: break       7
    do_break(2147634544);
L_80024D74:
    // 0x80024D74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024D78: bne         $s7, $at, L_80024D8C
    if (ctx->r23 != ctx->r1) {
        // 0x80024D7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024D8C;
    }
    // 0x80024D7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024D80: bne         $t3, $at, L_80024D8C
    if (ctx->r11 != ctx->r1) {
        // 0x80024D84: nop
    
            goto L_80024D8C;
    }
    // 0x80024D84: nop

    // 0x80024D88: break       6
    do_break(2147634568);
L_80024D8C:
    // 0x80024D8C: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80024D90: bgezl       $a1, L_80024DA4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80024D94: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80024DA4;
    }
    goto skip_2;
    // 0x80024D94: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    skip_2:
    // 0x80024D98: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80024D9C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80024DA0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
L_80024DA4:
    // 0x80024DA4: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80024DA8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80024DAC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80024DB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80024DB4: addu        $a0, $fp, $t6
    ctx->r4 = ADD32(ctx->r30, ctx->r14);
    // 0x80024DB8: jal         0x800368E0
    // 0x80024DBC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800368E0(rdram, ctx);
        goto after_6;
    // 0x80024DBC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_6:
    // 0x80024DC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80024DC4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80024DC8: bne         $s1, $s4, L_80024D48
    if (ctx->r17 != ctx->r20) {
        // 0x80024DCC: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80024D48;
    }
    // 0x80024DCC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80024DD0: lh          $t7, 0x5C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5C);
    // 0x80024DD4: lh          $t8, 0x5E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5E);
    // 0x80024DD8: bnel        $t7, $zero, L_80024DF4
    if (ctx->r15 != 0) {
        // 0x80024DDC: lw          $s3, 0x130($sp)
        ctx->r19 = MEM_W(ctx->r29, 0X130);
            goto L_80024DF4;
    }
    goto skip_3;
    // 0x80024DDC: lw          $s3, 0x130($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X130);
    skip_3:
    // 0x80024DE0: bne         $t8, $zero, L_80024DF0
    if (ctx->r24 != 0) {
        // 0x80024DE4: lw          $t9, 0x64($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X64);
            goto L_80024DF0;
    }
    // 0x80024DE4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80024DE8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80024DEC: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
L_80024DF0:
    // 0x80024DF0: lw          $s3, 0x130($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X130);
L_80024DF4:
    // 0x80024DF4: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
L_80024DF8:
    // 0x80024DF8: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x80024DFC: lw          $s2, 0x3900($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3900);
    // 0x80024E00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024E04: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80024E08: div         $zero, $s2, $at
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r1)));
    // 0x80024E0C: lw          $a3, 0x38FC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X38FC);
    // 0x80024E10: lui         $s5, 0x8009
    ctx->r21 = S32(0X8009 << 16);
    // 0x80024E14: addiu       $t3, $sp, 0x70
    ctx->r11 = ADD32(ctx->r29, 0X70);
    // 0x80024E18: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x80024E1C: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x80024E20: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80024E24: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x80024E28: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x80024E2C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80024E30: addu        $s5, $s5, $t2
    ctx->r21 = ADD32(ctx->r21, ctx->r10);
    // 0x80024E34: mfhi        $s2
    ctx->r18 = hi;
    // 0x80024E38: addu        $s0, $t1, $t3
    ctx->r16 = ADD32(ctx->r9, ctx->r11);
    // 0x80024E3C: jal         0x80024B1C
    // 0x80024E40: lw          $s5, -0xDB0($s5)
    ctx->r21 = MEM_W(ctx->r21, -0XDB0);
    func_80024B1C(rdram, ctx);
        goto after_7;
    // 0x80024E40: lw          $s5, -0xDB0($s5)
    ctx->r21 = MEM_W(ctx->r21, -0XDB0);
    after_7:
    // 0x80024E44: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80024E48: addiu       $t6, $t6, -0xDA0
    ctx->r14 = ADD32(ctx->r14, -0XDA0);
    // 0x80024E4C: sll         $t5, $s2, 2
    ctx->r13 = S32(ctx->r18 << 2);
    // 0x80024E50: addu        $s6, $t5, $t6
    ctx->r22 = ADD32(ctx->r13, ctx->r14);
    // 0x80024E54: jal         0x80034DD0
    // 0x80024E58: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_8;
    // 0x80024E58: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_8:
    // 0x80024E5C: lw          $t9, 0x130($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X130);
    // 0x80024E60: lw          $t0, 0x128($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X128);
    // 0x80024E64: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x80024E68: addiu       $t8, $t8, 0x3904
    ctx->r24 = ADD32(ctx->r24, 0X3904);
    // 0x80024E6C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x80024E70: addiu       $t3, $t1, 0x60
    ctx->r11 = ADD32(ctx->r9, 0X60);
    // 0x80024E74: sll         $t7, $s2, 1
    ctx->r15 = S32(ctx->r18 << 1);
    // 0x80024E78: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x80024E7C: andi        $t2, $t3, 0xFFF0
    ctx->r10 = ctx->r11 & 0XFFF0;
    // 0x80024E80: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
    // 0x80024E84: lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X0);
    // 0x80024E88: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80024E8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80024E90: slt         $at, $a3, $s3
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80024E94: beq         $at, $zero, L_80024EA4
    if (ctx->r1 == 0) {
        // 0x80024E98: lui         $a1, 0x8009
        ctx->r5 = S32(0X8009 << 16);
            goto L_80024EA4;
    }
    // 0x80024E98: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80024E9C: sh          $s3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r19;
    // 0x80024EA0: lh          $a3, 0x0($s1)
    ctx->r7 = MEM_H(ctx->r17, 0X0);
L_80024EA4:
    // 0x80024EA4: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x80024EA8: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80024EAC: addiu       $t5, $t5, -0x6110
    ctx->r13 = ADD32(ctx->r13, -0X6110);
    // 0x80024EB0: addiu       $t4, $t4, -0x6040
    ctx->r12 = ADD32(ctx->r12, -0X6040);
    // 0x80024EB4: subu        $s2, $t4, $t5
    ctx->r18 = SUB32(ctx->r12, ctx->r13);
    // 0x80024EB8: jal         0x80036A68
    // 0x80024EBC: addiu       $a1, $a1, -0x6D8
    ctx->r5 = ADD32(ctx->r5, -0X6D8);
    func_80036A68(rdram, ctx);
        goto after_9;
    // 0x80024EBC: addiu       $a1, $a1, -0x6D8
    ctx->r5 = ADD32(ctx->r5, -0X6D8);
    after_9:
    // 0x80024EC0: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80024EC4: lw          $a3, 0x38FC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X38FC);
    // 0x80024EC8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80024ECC: addiu       $t6, $sp, 0x168
    ctx->r14 = ADD32(ctx->r29, 0X168);
    // 0x80024ED0: addiu       $t8, $t8, -0xDB0
    ctx->r24 = ADD32(ctx->r24, -0XDB0);
    // 0x80024ED4: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80024ED8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80024EDC: sw          $t6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r14;
    // 0x80024EE0: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80024EE4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80024EE8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80024EEC: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x80024EF0: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x80024EF4: sw          $t9, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r25;
    // 0x80024EF8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80024EFC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80024F00: addiu       $t4, $t4, -0x6110
    ctx->r12 = ADD32(ctx->r12, -0X6110);
    // 0x80024F04: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x80024F08: sra         $t3, $t1, 3
    ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80024F0C: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x80024F10: addiu       $t5, $t5, -0x4C10
    ctx->r13 = ADD32(ctx->r13, -0X4C10);
    // 0x80024F14: addiu       $t6, $t6, 0x2BD0
    ctx->r14 = ADD32(ctx->r14, 0X2BD0);
    // 0x80024F18: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x80024F1C: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    // 0x80024F20: sw          $s4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r20;
    // 0x80024F24: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80024F28: sw          $t4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r12;
    // 0x80024F2C: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x80024F30: sw          $t5, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r13;
    // 0x80024F34: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80024F38: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x80024F3C: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80024F40: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80024F44: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x80024F48: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80024F4C: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x80024F50: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x80024F54: lw          $a0, 0x120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X120);
    // 0x80024F58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80024F5C: jal         0x80034200
    // 0x80024F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80024F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80024F64: jal         0x80037000
    // 0x80024F68: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_11;
    // 0x80024F68: nop

    after_11:
    // 0x80024F6C: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80024F70: lw          $t0, 0x3900($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X3900);
    // 0x80024F74: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80024F78: lw          $a3, 0x38FC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X38FC);
    // 0x80024F7C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80024F80: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80024F84: sw          $t1, 0x3900($at)
    MEM_W(0X3900, ctx->r1) = ctx->r9;
    // 0x80024F88: srl         $t8, $v0, 2
    ctx->r24 = S32(U32(ctx->r2) >> 2);
    // 0x80024F8C: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80024F90: xori        $t9, $a3, 0x1
    ctx->r25 = ctx->r7 ^ 0X1;
    // 0x80024F94: sw          $t8, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r24;
    // 0x80024F98: sw          $t9, 0x38FC($at)
    MEM_W(0X38FC, ctx->r1) = ctx->r25;
    // 0x80024F9C: addiu       $a0, $sp, 0x168
    ctx->r4 = ADD32(ctx->r29, 0X168);
    // 0x80024FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024FA4: jal         0x80034020
    // 0x80024FA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80024FA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80024FAC: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x80024FB0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80024FB4: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80024FB8: jal         0x80037010
    // 0x80024FBC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_13;
    // 0x80024FBC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_13:
    // 0x80024FC0: b           L_80024CE4
    // 0x80024FC4: addiu       $a0, $sp, 0x1A0
    ctx->r4 = ADD32(ctx->r29, 0X1A0);
        goto L_80024CE4;
    // 0x80024FC4: addiu       $a0, $sp, 0x1A0
    ctx->r4 = ADD32(ctx->r29, 0X1A0);
L_80024FC8:
    // 0x80024FC8: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80024FCC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80024FD0: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80024FD4: jal         0x800370C0
    // 0x80024FD8: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    func_800370C0(rdram, ctx);
        goto after_14;
    // 0x80024FD8: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    after_14:
    // 0x80024FDC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80024FE0: sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    // 0x80024FE4: jal         0x800370C0
    // 0x80024FE8: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    func_800370C0(rdram, ctx);
        goto after_15;
    // 0x80024FE8: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    after_15:
    // 0x80024FEC: lh          $t6, 0x60($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X60);
    // 0x80024FF0: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
    // 0x80024FF4: sh          $v0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r2;
    // 0x80024FF8: b           L_80024CE0
    // 0x80024FFC: sh          $t6, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r14;
        goto L_80024CE0;
    // 0x80024FFC: sh          $t6, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r14;
    // 0x80025000: nop

    // 0x80025004: nop

    // 0x80025008: nop

    // 0x8002500C: nop

    // 0x80025010: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80025014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80025018: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002501C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80025020: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80025024: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80025028: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002502C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80025030: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80025034: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80025038: jr          $ra
    // 0x8002503C: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
    return;
    // 0x8002503C: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
;}
