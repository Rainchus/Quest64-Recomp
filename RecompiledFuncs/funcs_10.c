#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80018F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018F60: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80018F64: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80018F68: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80018F6C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80018F70: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80018F74: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80018F78: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80018F7C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80018F80: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80018F84: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80018F88: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80018F8C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80018F90: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80018F94: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018F98: lui         $s6, 0x400
    ctx->r22 = S32(0X400 << 16);
    // 0x80018F9C: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80018FA0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80018FA4: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x80018FA8: addiu       $s1, $s1, 0x73D0
    ctx->r17 = ADD32(ctx->r17, 0X73D0);
    // 0x80018FAC: addiu       $s0, $s0, -0x4D04
    ctx->r16 = ADD32(ctx->r16, -0X4D04);
    // 0x80018FB0: ori         $s6, $s6, 0x400
    ctx->r22 = ctx->r22 | 0X400;
    // 0x80018FB4: ldc1        $f20, 0x1580($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X1580);
    // 0x80018FB8: lui         $s5, 0xB300
    ctx->r21 = S32(0XB300 << 16);
    // 0x80018FBC: lui         $s4, 0xB400
    ctx->r20 = S32(0XB400 << 16);
    // 0x80018FC0: lui         $s3, 0xE400
    ctx->r19 = S32(0XE400 << 16);
    // 0x80018FC4: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
L_80018FC8:
    // 0x80018FC8: lhu         $t6, 0xC($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XC);
    // 0x80018FCC: addiu       $a3, $sp, 0xA4
    ctx->r7 = ADD32(ctx->r29, 0XA4);
    // 0x80018FD0: addiu       $t8, $sp, 0xA0
    ctx->r24 = ADD32(ctx->r29, 0XA0);
    // 0x80018FD4: beql        $t6, $zero, L_800192E8
    if (ctx->r14 == 0) {
        // 0x80018FD8: addiu       $fp, $fp, -0x1
        ctx->r30 = ADD32(ctx->r30, -0X1);
            goto L_800192E8;
    }
    goto skip_0;
    // 0x80018FD8: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    skip_0:
    // 0x80018FDC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80018FE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018FE4: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80018FE8: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80018FEC: bne         $a0, $zero, L_8001900C
    if (ctx->r4 != 0) {
        // 0x80018FF0: nop
    
            goto L_8001900C;
    }
    // 0x80018FF0: nop

    // 0x80018FF4: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80018FF8: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80018FFC: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80019000: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80019004: b           L_8001903C
    // 0x80019008: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
        goto L_8001903C;
    // 0x80019008: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
L_8001900C:
    // 0x8001900C: bnel        $a0, $at, L_80019024
    if (ctx->r4 != ctx->r1) {
        // 0x80019010: lwc1        $f4, 0x24($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
            goto L_80019024;
    }
    goto skip_1;
    // 0x80019010: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    skip_1:
    // 0x80019014: lw          $t7, 0x68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X68);
    // 0x80019018: b           L_8001903C
    // 0x8001901C: lwc1        $f14, 0x94($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X94);
        goto L_8001903C;
    // 0x8001901C: lwc1        $f14, 0x94($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X94);
    // 0x80019020: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
L_80019024:
    // 0x80019024: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80019028: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001902C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80019030: mul.d       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f20.d, ctx->f6.d);
    // 0x80019034: add.d       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f18.d + ctx->f10.d;
    // 0x80019038: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
L_8001903C:
    // 0x8001903C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019040: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80019044: jal         0x8002413C
    // 0x80019048: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8002413C(rdram, ctx);
        goto after_0;
    // 0x80019048: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8001904C: beql        $v0, $zero, L_800192DC
    if (ctx->r2 == 0) {
        // 0x80019050: lhu         $t4, 0xC($s1)
        ctx->r12 = MEM_HU(ctx->r17, 0XC);
            goto L_800192DC;
    }
    goto skip_2;
    // 0x80019050: lhu         $t4, 0xC($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XC);
    skip_2:
    // 0x80019054: bne         $s7, $zero, L_80019144
    if (ctx->r23 != 0) {
        // 0x80019058: lui         $t3, 0x600
        ctx->r11 = S32(0X600 << 16);
            goto L_80019144;
    }
    // 0x80019058: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8001905C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80019060: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80019064: addiu       $t4, $t4, 0x47A0
    ctx->r12 = ADD32(ctx->r12, 0X47A0);
    // 0x80019068: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001906C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80019070: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80019074: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80019078: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001907C: lui         $t7, 0x803A
    ctx->r15 = S32(0X803A << 16);
    // 0x80019080: addiu       $t7, $t7, -0x3070
    ctx->r15 = ADD32(ctx->r15, -0X3070);
    // 0x80019084: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80019088: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8001908C: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x80019090: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80019094: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80019098: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001909C: lui         $t9, 0xF510
    ctx->r25 = S32(0XF510 << 16);
    // 0x800190A0: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x800190A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800190A8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800190AC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800190B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800190B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800190B8: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x800190BC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800190C0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800190C4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800190C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800190CC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800190D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800190D4: lui         $t8, 0x74F
    ctx->r24 = S32(0X74F << 16);
    // 0x800190D8: ori         $t8, $t8, 0xF040
    ctx->r24 = ctx->r24 | 0XF040;
    // 0x800190DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800190E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800190E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800190E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800190EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800190F0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800190F4: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800190F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800190FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80019100: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80019104: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80019108: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001910C: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x80019110: ori         $t5, $t5, 0x4000
    ctx->r13 = ctx->r13 | 0X4000;
    // 0x80019114: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80019118: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8001911C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80019120: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80019124: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80019128: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x8001912C: ori         $t8, $t8, 0xC024
    ctx->r24 = ctx->r24 | 0XC024;
    // 0x80019130: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80019134: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80019138: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001913C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80019140: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80019144:
    // 0x80019144: lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC);
    // 0x80019148: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x8001914C: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80019150: bne         $at, $zero, L_80019180
    if (ctx->r1 != 0) {
        // 0x80019154: subu        $a0, $t9, $v0
        ctx->r4 = SUB32(ctx->r25, ctx->r2);
            goto L_80019180;
    }
    // 0x80019154: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x80019158: sll         $t3, $a0, 12
    ctx->r11 = S32(ctx->r4 << 12);
    // 0x8001915C: jal         0x80035190
    // 0x80019160: andi        $a0, $t3, 0xFFFF
    ctx->r4 = ctx->r11 & 0XFFFF;
    func_80035190(rdram, ctx);
        goto after_1;
    // 0x80019160: andi        $a0, $t3, 0xFFFF
    ctx->r4 = ctx->r11 & 0XFFFF;
    after_1:
    // 0x80019164: sra         $v1, $v0, 11
    ctx->r3 = S32(SIGNED(ctx->r2) >> 11);
    // 0x80019168: bgez        $v1, L_80019174
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001916C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80019174;
    }
    // 0x8001916C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80019170: negu        $a0, $v1
    ctx->r4 = SUB32(0, ctx->r3);
L_80019174:
    // 0x80019174: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x80019178: subu        $t6, $t5, $a0
    ctx->r14 = SUB32(ctx->r13, ctx->r4);
    // 0x8001917C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
L_80019180:
    // 0x80019180: lw          $t8, 0x18($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X18);
    // 0x80019184: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x80019188: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x8001918C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80019190: subu        $t3, $t7, $t9
    ctx->r11 = SUB32(ctx->r15, ctx->r25);
    // 0x80019194: sw          $t3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r11;
    // 0x80019198: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
    // 0x8001919C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800191A0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800191A4: subu        $t8, $t4, $t6
    ctx->r24 = SUB32(ctx->r12, ctx->r14);
    // 0x800191A8: addiu       $t7, $t8, -0x8
    ctx->r15 = ADD32(ctx->r24, -0X8);
    // 0x800191AC: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x800191B0: lw          $t9, 0x10($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X10);
    // 0x800191B4: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x800191B8: addiu       $t5, $t5, -0x305C
    ctx->r13 = ADD32(ctx->r13, -0X305C);
    // 0x800191BC: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x800191C0: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x800191C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800191C8: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800191CC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800191D0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800191D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800191D8: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x800191DC: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x800191E0: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800191E4: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x800191E8: sll         $t4, $t5, 24
    ctx->r12 = S32(ctx->r13 << 24);
    // 0x800191EC: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x800191F0: sll         $t3, $t7, 16
    ctx->r11 = S32(ctx->r15 << 16);
    // 0x800191F4: or          $t5, $t6, $t3
    ctx->r13 = ctx->r14 | ctx->r11;
    // 0x800191F8: ori         $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 | 0XFF;
    // 0x800191FC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80019200: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80019204: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80019208: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    // 0x8001920C: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80019210: subu        $t7, $t4, $t8
    ctx->r15 = SUB32(ctx->r12, ctx->r24);
    // 0x80019214: beq         $a3, $zero, L_800192D8
    if (ctx->r7 == 0) {
        // 0x80019218: sw          $t7, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->r15;
            goto L_800192D8;
    }
    // 0x80019218: sw          $t7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r15;
L_8001921C:
    // 0x8001921C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80019220: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80019224: beq         $s2, $t6, L_800192D0
    if (ctx->r18 == ctx->r14) {
        // 0x80019228: nop
    
            goto L_800192D0;
    }
    // 0x80019228: nop

    // 0x8001922C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80019230: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80019234: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80019238: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8001923C: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x80019240: addiu       $t9, $t5, 0x4
    ctx->r25 = ADD32(ctx->r13, 0X4);
    // 0x80019244: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80019248: andi        $t8, $t4, 0xFFF
    ctx->r24 = ctx->r12 & 0XFFF;
    // 0x8001924C: addiu       $t5, $t3, 0x5
    ctx->r13 = ADD32(ctx->r11, 0X5);
    // 0x80019250: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80019254: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80019258: or          $t6, $t7, $s3
    ctx->r14 = ctx->r15 | ctx->r19;
    // 0x8001925C: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x80019260: or          $t8, $t6, $t4
    ctx->r24 = ctx->r14 | ctx->r12;
    // 0x80019264: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80019268: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x8001926C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x80019270: addiu       $t3, $t7, -0x4
    ctx->r11 = ADD32(ctx->r15, -0X4);
    // 0x80019274: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80019278: addiu       $t8, $t4, -0x5
    ctx->r24 = ADD32(ctx->r12, -0X5);
    // 0x8001927C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80019280: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x80019284: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80019288: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x8001928C: or          $t5, $t6, $t3
    ctx->r13 = ctx->r14 | ctx->r11;
    // 0x80019290: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80019294: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80019298: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001929C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800192A0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x800192A4: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x800192A8: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x800192AC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800192B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800192B4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800192B8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800192BC: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800192C0: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x800192C4: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800192C8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800192CC: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
L_800192D0:
    // 0x800192D0: bne         $a3, $zero, L_8001921C
    if (ctx->r7 != 0) {
        // 0x800192D4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8001921C;
    }
    // 0x800192D4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800192D8:
    // 0x800192D8: lhu         $t4, 0xC($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0XC);
L_800192DC:
    // 0x800192DC: addiu       $t8, $t4, -0x1
    ctx->r24 = ADD32(ctx->r12, -0X1);
    // 0x800192E0: sh          $t8, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r24;
    // 0x800192E4: addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
L_800192E8:
    // 0x800192E8: bne         $fp, $zero, L_80018FC8
    if (ctx->r30 != 0) {
        // 0x800192EC: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_80018FC8;
    }
    // 0x800192EC: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x800192F0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800192F4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800192F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800192FC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80019300: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80019304: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80019308: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8001930C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80019310: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80019314: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80019318: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8001931C: jr          $ra
    // 0x80019320: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80019320: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80018DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018DB4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80018DB8: addiu       $v1, $v1, 0x73EC
    ctx->r3 = ADD32(ctx->r3, 0X73EC);
    // 0x80018DBC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018DC0: sh          $zero, 0x73DC($at)
    MEM_H(0X73DC, ctx->r1) = 0;
    // 0x80018DC4: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x80018DC8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80018DCC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80018DD0:
    // 0x80018DD0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80018DD4: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x80018DD8: sh          $zero, 0x28($v1)
    MEM_H(0X28, ctx->r3) = 0;
    // 0x80018DDC: sh          $zero, 0x44($v1)
    MEM_H(0X44, ctx->r3) = 0;
    // 0x80018DE0: sh          $zero, 0x60($v1)
    MEM_H(0X60, ctx->r3) = 0;
    // 0x80018DE4: bne         $v0, $zero, L_80018DD0
    if (ctx->r2 != 0) {
        // 0x80018DE8: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_80018DD0;
    }
    // 0x80018DE8: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x80018DEC: jr          $ra
    // 0x80018DF0: nop

    return;
    // 0x80018DF0: nop

;}
RECOMP_FUNC void func_80020888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020888: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002088C: addiu       $v0, $v0, -0x3998
    ctx->r2 = ADD32(ctx->r2, -0X3998);
    // 0x80020890: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_80020894:
    // 0x80020894: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80020898: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8002089C: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x800208A0: sh          $zero, 0x38($v0)
    MEM_H(0X38, ctx->r2) = 0;
    // 0x800208A4: sh          $zero, 0x54($v0)
    MEM_H(0X54, ctx->r2) = 0;
    // 0x800208A8: bne         $v1, $zero, L_80020894
    if (ctx->r3 != 0) {
        // 0x800208AC: addiu       $v0, $v0, 0x70
        ctx->r2 = ADD32(ctx->r2, 0X70);
            goto L_80020894;
    }
    // 0x800208AC: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x800208B0: jr          $ra
    // 0x800208B4: nop

    return;
    // 0x800208B4: nop

;}
RECOMP_FUNC void func_800154EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800154EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800154F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800154F4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800154F8: lhu         $t6, 0x5E($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X5E);
    // 0x800154FC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80015500: beql        $t7, $zero, L_80015554
    if (ctx->r15 == 0) {
        // 0x80015504: lw          $t8, 0x64($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X64);
            goto L_80015554;
    }
    goto skip_0;
    // 0x80015504: lw          $t8, 0x64($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X64);
    skip_0:
    // 0x80015508: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x8001550C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80015510: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80015514: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80015518: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001551C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80015520: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80015524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80015528: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001552C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80015530: nop

    // 0x80015534: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80015538: jal         0x80034F60
    // 0x8001553C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8001553C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x80015540: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80015544: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80015548: b           L_8001557C
    // 0x8001554C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8001557C;
    // 0x8001554C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80015550: lw          $t8, 0x64($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X64);
L_80015554:
    // 0x80015554: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80015558: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001555C: lwc1        $f4, 0x18($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X18);
    // 0x80015560: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80015564: lwc1        $f16, 0x24($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80015568: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8001556C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80015570: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80015574: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80015578: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_8001557C:
    // 0x8001557C: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80015580: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80015584: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80015588: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8001558C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80015590: mul.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80015594: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80015598: swc1        $f2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f2.u32l;
    // 0x8001559C: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800155A0: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800155A4: lwc1        $f12, 0x10($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800155A8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800155AC: jal         0x800232F4
    // 0x800155B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x800155B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800155B4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800155B8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800155BC: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x800155C0: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800155C4: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800155C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800155CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800155D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800155D4: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800155D8: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800155DC: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800155E0: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800155E4: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800155E8: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x800155EC: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800155F0: bnel        $t9, $at, L_8001561C
    if (ctx->r25 != ctx->r1) {
        // 0x800155F4: lwc1        $f10, 0x4($a2)
        ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
            goto L_8001561C;
    }
    goto skip_1;
    // 0x800155F4: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    skip_1:
    // 0x800155F8: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800155FC: lwc1        $f4, 0x24($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80015600: lw          $t0, 0x68($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X68);
    // 0x80015604: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80015608: lwc1        $f8, 0x94($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X94);
    // 0x8001560C: sub.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80015610: b           L_80015620
    // 0x80015614: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
        goto L_80015620;
    // 0x80015614: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80015618: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
L_8001561C:
    // 0x8001561C: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
L_80015620:
    // 0x80015620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015628: jr          $ra
    // 0x8001562C: nop

    return;
    // 0x8001562C: nop

;}
RECOMP_FUNC void func_80039050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80039054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039058: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8003905C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80039060: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80039064: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80039068: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x8003906C: jal         0x8003FE6C
    // 0x80039070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80039070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80039074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003907C: jr          $ra
    // 0x80039080: nop

    return;
    // 0x80039080: nop

    // 0x80039084: nop

    // 0x80039088: nop

    // 0x8003908C: nop

;}
RECOMP_FUNC void func_8002699C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002699C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800269A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800269A4: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800269A8: sra         $a0, $t6, 24
    ctx->r4 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800269AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800269B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800269B4: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x800269B8: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x800269BC: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x800269C0: lbu         $t8, 0x3CAC($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3CAC);
    // 0x800269C4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800269C8: lbu         $t0, -0x33A($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X33A);
    // 0x800269CC: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800269D0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800269D4: mflo        $t9
    ctx->r25 = lo;
    // 0x800269D8: nop

    // 0x800269DC: nop

    // 0x800269E0: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800269E4: mflo        $a1
    ctx->r5 = lo;
    // 0x800269E8: srl         $t1, $a1, 16
    ctx->r9 = S32(U32(ctx->r5) >> 16);
    // 0x800269EC: jal         0x80025B8C
    // 0x800269F0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80025B8C(rdram, ctx);
        goto after_0;
    // 0x800269F0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_0:
    // 0x800269F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800269F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800269FC: jr          $ra
    // 0x80026A00: nop

    return;
    // 0x80026A00: nop

;}
RECOMP_FUNC void func_800471B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044B4C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80044B50: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x80044B54: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80044B58: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x80044B5C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80044B60: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80044B64:
    // 0x80044B64: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80044B68: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80044B6C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80044B70: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x80044B74: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x80044B78: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x80044B7C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80044B80: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x80044B84: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x80044B88: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x80044B8C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80044B90: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x80044B94: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80044B98: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x80044B9C: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x80044BA0: bne         $at, $zero, L_80044B64
    if (ctx->r1 != 0) {
        // 0x80044BA4: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_80044B64;
    }
    // 0x80044BA4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80044BA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80044BAC: jr          $ra
    // 0x80044BB0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80044BB0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800121F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800121F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800121F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800121F8: addiu       $v0, $v0, 0x6AF8
    ctx->r2 = ADD32(ctx->r2, 0X6AF8);
    // 0x800121FC: addiu       $v1, $v1, 0x6AE8
    ctx->r3 = ADD32(ctx->r3, 0X6AE8);
L_80012200:
    // 0x80012200: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80012204: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x80012208: sb          $zero, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = 0;
    // 0x8001220C: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80012210: bne         $v1, $v0, L_80012200
    if (ctx->r3 != ctx->r2) {
        // 0x80012214: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80012200;
    }
    // 0x80012214: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80012218: jr          $ra
    // 0x8001221C: nop

    return;
    // 0x8001221C: nop

;}
RECOMP_FUNC void func_80007B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B64: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80007B68: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80007B6C: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x80007B70: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x80007B74: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80007B78: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80007B7C: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80007B80: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80007B84: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80007B88: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80007B8C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80007B90: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80007B94: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80007B98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80007B9C: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80007BA0: lw          $s4, -0x431C($s4)
    ctx->r20 = MEM_W(ctx->r20, -0X431C);
    // 0x80007BA4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80007BA8: addiu       $s1, $s1, -0x42D0
    ctx->r17 = ADD32(ctx->r17, -0X42D0);
    // 0x80007BAC: beq         $s4, $zero, L_80007EDC
    if (ctx->r20 == 0) {
        // 0x80007BB0: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_80007EDC;
    }
    // 0x80007BB0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80007BB4: ldc1        $f30, 0x1110($at)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r1, 0X1110);
    // 0x80007BB8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80007BBC: ldc1        $f28, 0x1118($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X1118);
    // 0x80007BC0: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80007BC4: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x80007BC8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80007BCC: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80007BD0: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80007BD4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80007BD8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80007BDC: addiu       $s2, $s2, -0x4348
    ctx->r18 = ADD32(ctx->r18, -0X4348);
    // 0x80007BE0: addiu       $s3, $s3, -0x434C
    ctx->r19 = ADD32(ctx->r19, -0X434C);
    // 0x80007BE4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80007BE8:
    // 0x80007BE8: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80007BEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007BF0: beql        $v0, $zero, L_80007C1C
    if (ctx->r2 == 0) {
        // 0x80007BF4: lw          $t6, 0x80($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X80);
            goto L_80007C1C;
    }
    goto skip_0;
    // 0x80007BF4: lw          $t6, 0x80($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X80);
    skip_0:
    // 0x80007BF8: beql        $v0, $at, L_80007D6C
    if (ctx->r2 == ctx->r1) {
        // 0x80007BFC: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80007D6C;
    }
    goto skip_1;
    // 0x80007BFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x80007C00: beq         $v0, $s5, L_80007DF8
    if (ctx->r2 == ctx->r21) {
        // 0x80007C04: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80007DF8;
    }
    // 0x80007C04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80007C08: beql        $v0, $at, L_80007E64
    if (ctx->r2 == ctx->r1) {
        // 0x80007C0C: lwc1        $f8, 0x10($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
            goto L_80007E64;
    }
    goto skip_2;
    // 0x80007C0C: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    skip_2:
    // 0x80007C10: b           L_80007ED4
    // 0x80007C14: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
        goto L_80007ED4;
    // 0x80007C14: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80007C18: lw          $t6, 0x80($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X80);
L_80007C1C:
    // 0x80007C1C: lbu         $t7, 0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4);
    // 0x80007C20: bnel        $s5, $t7, L_80007ED4
    if (ctx->r21 != ctx->r15) {
        // 0x80007C24: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_80007ED4;
    }
    goto skip_3;
    // 0x80007C24: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_3:
    // 0x80007C28: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    // 0x80007C2C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80007C30: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x80007C34: bne         $t0, $zero, L_80007ED0
    if (ctx->r8 != 0) {
        // 0x80007C38: sh          $t9, 0x2($s1)
        MEM_H(0X2, ctx->r17) = ctx->r25;
            goto L_80007ED0;
    }
    // 0x80007C38: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
    // 0x80007C3C: lhu         $t1, 0x0($s3)
    ctx->r9 = MEM_HU(ctx->r19, 0X0);
    // 0x80007C40: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80007C44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80007C48: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80007C4C: beq         $at, $zero, L_80007D3C
    if (ctx->r1 == 0) {
        // 0x80007C50: nop
    
            goto L_80007D3C;
    }
    // 0x80007C50: nop

    // 0x80007C54: jal         0x80022FD0
    // 0x80007C58: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
    get_rand(rdram, ctx);
        goto after_0;
    // 0x80007C58: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
    after_0:
    // 0x80007C5C: lw          $t4, 0x80($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X80);
    // 0x80007C60: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80007C64: addiu       $s0, $s1, 0x14
    ctx->r16 = ADD32(ctx->r17, 0X14);
    // 0x80007C68: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80007C6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80007C70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80007C74: lh          $t6, 0xE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XE);
    // 0x80007C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80007C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80007C80: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007C84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80007C88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80007C8C: mflo        $t7
    ctx->r15 = lo;
    // 0x80007C90: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x80007C94: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80007C98: jal         0x8001D8B0
    // 0x80007C9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x80007C9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x80007CA0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80007CA4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80007CA8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80007CAC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80007CB0: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80007CB4: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80007CB8: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80007CBC: nop

    // 0x80007CC0: mul.s       $f18, $f22, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80007CC4: jal         0x80034F60
    // 0x80007CC8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x80007CC8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_2:
    // 0x80007CCC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80007CD0: c.lt.d      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.d < ctx->f4.d;
    // 0x80007CD4: nop

    // 0x80007CD8: bc1f        L_80007CF4
    if (!c1cs) {
        // 0x80007CDC: nop
    
            goto L_80007CF4;
    }
    // 0x80007CDC: nop

    // 0x80007CE0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80007CE4: jal         0x80023210
    // 0x80007CE8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80023210(rdram, ctx);
        goto after_3;
    // 0x80007CE8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_3:
    // 0x80007CEC: b           L_80007D2C
    // 0x80007CF0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
        goto L_80007D2C;
    // 0x80007CF0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
L_80007CF4:
    // 0x80007CF4: jal         0x80022FD0
    // 0x80007CF8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    get_rand(rdram, ctx);
        goto after_4;
    // 0x80007CF8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x80007CFC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80007D00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80007D04: bgez        $v0, L_80007D18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80007D08: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80007D18;
    }
    // 0x80007D08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80007D0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80007D10: nop

    // 0x80007D14: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80007D18:
    // 0x80007D18: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80007D1C: mul.d       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f28.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f28.d);
    // 0x80007D20: sub.d       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = ctx->f18.d - ctx->f30.d;
    // 0x80007D24: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80007D28: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_80007D2C:
    // 0x80007D2C: lhu         $t0, 0x0($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X0);
    // 0x80007D30: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80007D34: b           L_80007ED0
    // 0x80007D38: sh          $t1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r9;
        goto L_80007ED0;
    // 0x80007D38: sh          $t1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r9;
L_80007D3C:
    // 0x80007D3C: jal         0x80022FD0
    // 0x80007D40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    get_rand(rdram, ctx);
        goto after_5;
    // 0x80007D40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80007D44: lw          $t4, 0x80($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X80);
    // 0x80007D48: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80007D4C: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80007D50: lh          $t3, 0x2($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X2);
    // 0x80007D54: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80007D58: mflo        $t6
    ctx->r14 = lo;
    // 0x80007D5C: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
    // 0x80007D60: b           L_80007ED4
    // 0x80007D64: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
        goto L_80007ED4;
    // 0x80007D64: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80007D68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80007D6C:
    // 0x80007D6C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80007D70: addiu       $s0, $s1, 0x14
    ctx->r16 = ADD32(ctx->r17, 0X14);
    // 0x80007D74: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80007D78: lwc1        $f8, 0x1120($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1120);
    // 0x80007D7C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80007D80: swc1        $f8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f8.u32l;
    // 0x80007D84: jal         0x800232F4
    // 0x80007D88: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_6;
    // 0x80007D88: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    after_6:
    // 0x80007D8C: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80007D90: lwc1        $f14, 0x4($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80007D94: jal         0x80008290
    // 0x80007D98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80008290(rdram, ctx);
        goto after_7;
    // 0x80007D98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80007D9C: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
    // 0x80007DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80007DA4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80007DA8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80007DAC: bne         $t9, $zero, L_80007ED0
    if (ctx->r25 != 0) {
        // 0x80007DB0: sh          $t8, 0x2($s1)
        MEM_H(0X2, ctx->r17) = ctx->r24;
            goto L_80007ED0;
    }
    // 0x80007DB0: sh          $t8, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r24;
    // 0x80007DB4: lw          $t0, 0x80($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X80);
    // 0x80007DB8: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80007DBC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80007DC0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80007DC4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80007DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007DCC: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80007DD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80007DD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80007DD8: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
    // 0x80007DDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80007DE0: jal         0x8001D8B0
    // 0x80007DE4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8001D8B0(rdram, ctx);
        goto after_8;
    // 0x80007DE4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_8:
    // 0x80007DE8: lhu         $t3, 0x0($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X0);
    // 0x80007DEC: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80007DF0: b           L_80007ED0
    // 0x80007DF4: sh          $t6, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r14;
        goto L_80007ED0;
    // 0x80007DF4: sh          $t6, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r14;
L_80007DF8:
    // 0x80007DF8: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x80007DFC: beql        $v0, $zero, L_80007ED4
    if (ctx->r2 == 0) {
        // 0x80007E00: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_80007ED4;
    }
    goto skip_4;
    // 0x80007E00: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_4:
    // 0x80007E04: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80007E08: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80007E0C: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x80007E10: div.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80007E14: addiu       $s0, $s1, 0x14
    ctx->r16 = ADD32(ctx->r17, 0X14);
    // 0x80007E18: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80007E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80007E20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80007E24: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80007E28: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80007E2C: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    // 0x80007E30: bnel        $t8, $zero, L_80007ED4
    if (ctx->r24 != 0) {
        // 0x80007E34: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_80007ED4;
    }
    goto skip_5;
    // 0x80007E34: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_5:
    // 0x80007E38: lw          $t9, 0x80($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X80);
    // 0x80007E3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80007E40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80007E44: lhu         $a1, 0x18($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X18);
    // 0x80007E48: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80007E4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80007E50: jal         0x8001D8B0
    // 0x80007E54: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_9;
    // 0x80007E54: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_9:
    // 0x80007E58: b           L_80007ED4
    // 0x80007E5C: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
        goto L_80007ED4;
    // 0x80007E5C: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80007E60: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
L_80007E64:
    // 0x80007E64: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
    // 0x80007E68: addiu       $s0, $s1, 0x14
    ctx->r16 = ADD32(ctx->r17, 0X14);
    // 0x80007E6C: div.s       $f18, $f8, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f24.fl);
    // 0x80007E70: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80007E74: sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // 0x80007E78: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80007E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80007E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007E84: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80007E88: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x80007E8C: lhu         $t2, 0x2($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X2);
    // 0x80007E90: bnel        $t2, $zero, L_80007ED4
    if (ctx->r10 != 0) {
        // 0x80007E94: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_80007ED4;
    }
    goto skip_6;
    // 0x80007E94: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_6:
    // 0x80007E98: lw          $t3, 0x80($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X80);
    // 0x80007E9C: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x80007EA0: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80007EA4: lw          $t6, 0x10($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X10);
    // 0x80007EA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80007EAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80007EB0: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80007EB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80007EB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80007EBC: sh          $t7, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r15;
    // 0x80007EC0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80007EC4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80007EC8: jal         0x8001D8B0
    // 0x80007ECC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8001D8B0(rdram, ctx);
        goto after_10;
    // 0x80007ECC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_10:
L_80007ED0:
    // 0x80007ED0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
L_80007ED4:
    // 0x80007ED4: bne         $s4, $zero, L_80007BE8
    if (ctx->r20 != 0) {
        // 0x80007ED8: addiu       $s1, $s1, 0x84
        ctx->r17 = ADD32(ctx->r17, 0X84);
            goto L_80007BE8;
    }
    // 0x80007ED8: addiu       $s1, $s1, 0x84
    ctx->r17 = ADD32(ctx->r17, 0X84);
L_80007EDC:
    // 0x80007EDC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80007EE0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80007EE4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80007EE8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80007EEC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80007EF0: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80007EF4: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80007EF8: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80007EFC: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80007F00: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80007F04: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80007F08: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80007F0C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80007F10: jr          $ra
    // 0x80007F14: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80007F14: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80031F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031F74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031F78: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80031F7C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80031F80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031F84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80031F88: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x80031F8C: beq         $s0, $zero, L_80031FA8
    if (ctx->r16 == 0) {
        // 0x80031F90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80031FA8;
    }
    // 0x80031F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80031F94:
    // 0x80031F94: jal         0x80031DD4
    // 0x80031F98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_80031DD4(rdram, ctx);
        goto after_0;
    // 0x80031F98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80031F9C: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x80031FA0: bnel        $s0, $zero, L_80031F94
    if (ctx->r16 != 0) {
        // 0x80031FA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80031F94;
    }
    goto skip_0;
    // 0x80031FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80031FA8:
    // 0x80031FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031FAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80031FB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80031FB4: jr          $ra
    // 0x80031FB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80031FB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026658: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002665C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80026660: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80026664: addiu       $s0, $s0, -0x33E
    ctx->r16 = ADD32(ctx->r16, -0X33E);
    // 0x80026668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002666C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80026670: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80026674: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026678: addiu       $a0, $a0, -0x33C
    ctx->r4 = ADD32(ctx->r4, -0X33C);
    // 0x8002667C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80026680: beq         $t6, $zero, L_800266D8
    if (ctx->r14 == 0) {
        // 0x80026684: nop
    
            goto L_800266D8;
    }
    // 0x80026684: nop

    // 0x80026688: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8002668C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80026690: addiu       $s1, $s1, -0x340
    ctx->r17 = ADD32(ctx->r17, -0X340);
    // 0x80026694: bnel        $v1, $zero, L_800266D4
    if (ctx->r3 != 0) {
        // 0x80026698: addiu       $t2, $v1, -0x1
        ctx->r10 = ADD32(ctx->r3, -0X1);
            goto L_800266D4;
    }
    goto skip_0;
    // 0x80026698: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8002669C: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x800266A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800266A4: ori         $t8, $v0, 0x2
    ctx->r24 = ctx->r2 | 0X2;
    // 0x800266A8: beq         $t7, $at, L_800266B8
    if (ctx->r15 == ctx->r1) {
        // 0x800266AC: ori         $t9, $v0, 0x4
        ctx->r25 = ctx->r2 | 0X4;
            goto L_800266B8;
    }
    // 0x800266AC: ori         $t9, $v0, 0x4
    ctx->r25 = ctx->r2 | 0X4;
    // 0x800266B0: b           L_800266BC
    // 0x800266B4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800266BC;
    // 0x800266B4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800266B8:
    // 0x800266B8: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_800266BC:
    // 0x800266BC: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x800266C0: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x800266C4: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x800266C8: b           L_800266D8
    // 0x800266CC: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
        goto L_800266D8;
    // 0x800266CC: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x800266D0: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
L_800266D4:
    // 0x800266D4: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
L_800266D8:
    // 0x800266D8: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x800266DC: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x800266E0: beq         $t3, $zero, L_80026708
    if (ctx->r11 == 0) {
        // 0x800266E4: addiu       $s1, $s1, -0x340
        ctx->r17 = ADD32(ctx->r17, -0X340);
            goto L_80026708;
    }
    // 0x800266E4: addiu       $s1, $s1, -0x340
    ctx->r17 = ADD32(ctx->r17, -0X340);
    // 0x800266E8: andi        $t5, $v0, 0xFFFD
    ctx->r13 = ctx->r2 & 0XFFFD;
    // 0x800266EC: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x800266F0: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x800266F4: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x800266F8: jal         0x800253F0
    // 0x800266FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800253F0(rdram, ctx);
        goto after_0;
    // 0x800266FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80026700: b           L_80026764
    // 0x80026704: nop

        goto L_80026764;
    // 0x80026704: nop

L_80026708:
    // 0x80026708: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8002670C: beq         $t7, $zero, L_80026764
    if (ctx->r15 == 0) {
        // 0x80026710: nop
    
            goto L_80026764;
    }
    // 0x80026710: nop

    // 0x80026714: jal         0x8002543C
    // 0x80026718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8002543C(rdram, ctx);
        goto after_1;
    // 0x80026718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8002671C: bne         $v0, $zero, L_80026764
    if (ctx->r2 != 0) {
        // 0x80026720: nop
    
            goto L_80026764;
    }
    // 0x80026720: nop

    // 0x80026724: lhu         $t8, 0x0($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X0);
    // 0x80026728: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002672C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80026730: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x80026734: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x80026738: lb          $t0, -0x33F($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X33F);
    // 0x8002673C: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x80026740: lb          $a1, 0x0($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X0);
    // 0x80026744: beq         $a1, $at, L_80026764
    if (ctx->r5 == ctx->r1) {
        // 0x80026748: nop
    
            goto L_80026764;
    }
    // 0x80026748: nop

    // 0x8002674C: jal         0x800252D8
    // 0x80026750: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800252D8(rdram, ctx);
        goto after_2;
    // 0x80026750: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80026754: jal         0x80026A04
    // 0x80026758: nop

    func_80026A04(rdram, ctx);
        goto after_3;
    // 0x80026758: nop

    after_3:
    // 0x8002675C: jal         0x80025364
    // 0x80026760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80025364(rdram, ctx);
        goto after_4;
    // 0x80026760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
L_80026764:
    // 0x80026764: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80026768: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // 0x8002676C: addiu       $s0, $s0, -0x338
    ctx->r16 = ADD32(ctx->r16, -0X338);
L_80026770:
    // 0x80026770: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80026774: beq         $v0, $zero, L_80026798
    if (ctx->r2 == 0) {
        // 0x80026778: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80026798;
    }
    // 0x80026778: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8002677C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80026780: bne         $t2, $zero, L_80026798
    if (ctx->r10 != 0) {
        // 0x80026784: sb          $t1, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r9;
            goto L_80026798;
    }
    // 0x80026784: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x80026788: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x8002678C: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x80026790: jal         0x80025B8C
    // 0x80026794: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80025B8C(rdram, ctx);
        goto after_5;
    // 0x80026794: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_5:
L_80026798:
    // 0x80026798: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8002679C: bne         $s1, $zero, L_80026770
    if (ctx->r17 != 0) {
        // 0x800267A0: addiu       $s0, $s0, 0x3
        ctx->r16 = ADD32(ctx->r16, 0X3);
            goto L_80026770;
    }
    // 0x800267A0: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x800267A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800267A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800267AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800267B0: jr          $ra
    // 0x800267B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800267B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80011E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011E78: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80011E7C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80011E80: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80011E84: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80011E88: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80011E8C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80011E90: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80011E94: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80011E98: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80011E9C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80011EA0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80011EA4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80011EA8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80011EAC: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80011EB0: lw          $s3, 0x69A0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X69A0);
    // 0x80011EB4: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80011EB8: addiu       $s0, $s0, 0x62E0
    ctx->r16 = ADD32(ctx->r16, 0X62E0);
    // 0x80011EBC: beq         $s3, $zero, L_8001201C
    if (ctx->r19 == 0) {
        // 0x80011EC0: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8001201C;
    }
    // 0x80011EC0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011EC4: ldc1        $f28, 0x12C8($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X12C8);
    // 0x80011EC8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011ECC: ldc1        $f26, 0x12D0($at)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r1, 0X12D0);
    // 0x80011ED0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011ED4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80011ED8: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80011EDC: addiu       $s1, $s1, 0x69A8
    ctx->r17 = ADD32(ctx->r17, 0X69A8);
    // 0x80011EE0: ldc1        $f24, 0x12D8($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X12D8);
L_80011EE4:
    // 0x80011EE4: jal         0x80012170
    // 0x80011EE8: lhu         $a0, 0x62($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X62);
    func_80012170(rdram, ctx);
        goto after_0;
    // 0x80011EE8: lhu         $a0, 0x62($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X62);
    after_0:
    // 0x80011EEC: bnel        $v0, $zero, L_80012014
    if (ctx->r2 != 0) {
        // 0x80011EF0: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80012014;
    }
    goto skip_0;
    // 0x80011EF0: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_0:
    // 0x80011EF4: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80011EF8: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80011EFC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011F00: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80011F04: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80011F08: c.lt.d      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.d < ctx->f0.d;
    // 0x80011F0C: nop

    // 0x80011F10: bc1f        L_80011F28
    if (!c1cs) {
        // 0x80011F14: nop
    
            goto L_80011F28;
    }
    // 0x80011F14: nop

    // 0x80011F18: sub.d       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f24.d); 
    ctx->f8.d = ctx->f0.d - ctx->f24.d;
    // 0x80011F1C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80011F20: b           L_80011F48
    // 0x80011F24: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
        goto L_80011F48;
    // 0x80011F24: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80011F28:
    // 0x80011F28: ldc1        $f10, 0x12E0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X12E0);
    // 0x80011F2C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80011F30: nop

    // 0x80011F34: bc1fl       L_80011F4C
    if (!c1cs) {
        // 0x80011F38: c.lt.d      $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.d < ctx->f26.d;
            goto L_80011F4C;
    }
    goto skip_1;
    // 0x80011F38: c.lt.d      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.d < ctx->f26.d;
    skip_1:
    // 0x80011F3C: add.d       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f24.d); 
    ctx->f16.d = ctx->f0.d + ctx->f24.d;
    // 0x80011F40: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80011F44: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80011F48:
    // 0x80011F48: c.lt.d      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.d < ctx->f26.d;
L_80011F4C:
    // 0x80011F4C: nop

    // 0x80011F50: bc1fl       L_80012014
    if (!c1cs) {
        // 0x80011F54: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80012014;
    }
    goto skip_2;
    // 0x80011F54: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_2:
    // 0x80011F58: c.lt.d      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.d < ctx->f0.d;
    // 0x80011F5C: nop

    // 0x80011F60: bc1fl       L_80012014
    if (!c1cs) {
        // 0x80011F64: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80012014;
    }
    goto skip_3;
    // 0x80011F64: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_3:
    // 0x80011F68: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80011F6C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80011F70: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80011F74: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80011F78: sub.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80011F7C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80011F80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80011F84: sub.s       $f22, $f6, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80011F88: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80011F8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80011F90: mul.s       $f16, $f22, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80011F94: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80011F98: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80011F9C: nop

    // 0x80011FA0: bc1fl       L_80012014
    if (!c1cs) {
        // 0x80011FA4: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80012014;
    }
    goto skip_4;
    // 0x80011FA4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_4:
    // 0x80011FA8: swc1        $f20, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
    // 0x80011FAC: swc1        $f22, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f22.u32l;
    // 0x80011FB0: jal         0x800232F4
    // 0x80011FB4: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x80011FB4: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    after_1:
    // 0x80011FB8: lwc1        $f20, 0x0($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80011FBC: lwc1        $f22, 0x4($s1)
    ctx->f22.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80011FC0: c.lt.s      $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f20.fl < ctx->f30.fl;
    // 0x80011FC4: nop

    // 0x80011FC8: bc1fl       L_80011FD8
    if (!c1cs) {
        // 0x80011FCC: c.lt.s      $f22, $f30
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f22.fl < ctx->f30.fl;
            goto L_80011FD8;
    }
    goto skip_5;
    // 0x80011FCC: c.lt.s      $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f22.fl < ctx->f30.fl;
    skip_5:
    // 0x80011FD0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x80011FD4: c.lt.s      $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f22.fl < ctx->f30.fl;
L_80011FD8:
    // 0x80011FD8: nop

    // 0x80011FDC: bc1fl       L_80011FEC
    if (!c1cs) {
        // 0x80011FE0: lwc1        $f6, 0x18($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
            goto L_80011FEC;
    }
    goto skip_6;
    // 0x80011FE0: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    skip_6:
    // 0x80011FE4: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x80011FE8: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
L_80011FEC:
    // 0x80011FEC: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x80011FF0: nop

    // 0x80011FF4: bc1fl       L_80012014
    if (!c1cs) {
        // 0x80011FF8: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80012014;
    }
    goto skip_7;
    // 0x80011FF8: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_7:
    // 0x80011FFC: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80012000: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x80012004: nop

    // 0x80012008: bc1t        L_8001201C
    if (c1cs) {
        // 0x8001200C: nop
    
            goto L_8001201C;
    }
    // 0x8001200C: nop

    // 0x80012010: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80012014:
    // 0x80012014: bne         $s3, $zero, L_80011EE4
    if (ctx->r19 != 0) {
        // 0x80012018: addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
            goto L_80011EE4;
    }
    // 0x80012018: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
L_8001201C:
    // 0x8001201C: bne         $s3, $zero, L_80012028
    if (ctx->r19 != 0) {
        // 0x80012020: ldc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
            goto L_80012028;
    }
    // 0x80012020: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80012024: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80012028:
    // 0x80012028: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8001202C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80012030: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80012034: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80012038: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8001203C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80012040: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80012044: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80012048: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8001204C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80012050: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80012054: jr          $ra
    // 0x80012058: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80012058: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80039090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039090: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80039094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039098: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8003909C: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800390A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800390A4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800390A8: jal         0x8003FE6C
    // 0x800390AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800390AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800390B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800390B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800390B8: jr          $ra
    // 0x800390BC: nop

    return;
    // 0x800390BC: nop

;}
RECOMP_FUNC void func_80022260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022260: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x80022264: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80022268: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8002226C: beql        $t6, $zero, L_8002228C
    if (ctx->r14 == 0) {
        // 0x80022270: lh          $t9, 0x6($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X6);
            goto L_8002228C;
    }
    goto skip_0;
    // 0x80022270: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    skip_0:
    // 0x80022274: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x80022278: lhu         $t8, 0x6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X6);
    // 0x8002227C: beql        $t7, $t8, L_8002228C
    if (ctx->r15 == ctx->r24) {
        // 0x80022280: lh          $t9, 0x6($a1)
        ctx->r25 = MEM_H(ctx->r5, 0X6);
            goto L_8002228C;
    }
    goto skip_1;
    // 0x80022280: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    skip_1:
    // 0x80022284: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80022288: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
L_8002228C:
    // 0x8002228C: beql        $t9, $zero, L_800222AC
    if (ctx->r25 == 0) {
        // 0x80022290: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800222AC;
    }
    goto skip_2;
    // 0x80022290: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x80022294: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x80022298: lhu         $t1, 0xA($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XA);
    // 0x8002229C: beql        $t0, $t1, L_800222AC
    if (ctx->r8 == ctx->r9) {
        // 0x800222A0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800222AC;
    }
    goto skip_3;
    // 0x800222A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_3:
    // 0x800222A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800222A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800222AC:
    // 0x800222AC: jr          $ra
    // 0x800222B0: nop

    return;
    // 0x800222B0: nop

;}
RECOMP_FUNC void func_800325FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800325FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80032608: jal         0x8003265C
    // 0x8003260C: nop

    func_8003265C(rdram, ctx);
        goto after_0;
    // 0x8003260C: nop

    after_0:
    // 0x80032610: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80032614: addiu       $a0, $a0, -0x2478
    ctx->r4 = ADD32(ctx->r4, -0X2478);
    // 0x80032618: jal         0x80032218
    // 0x8003261C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_80032218(rdram, ctx);
        goto after_1;
    // 0x8003261C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_1:
    // 0x80032620: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80032624: addiu       $a0, $a0, -0x1ED8
    ctx->r4 = ADD32(ctx->r4, -0X1ED8);
    // 0x80032628: jal         0x80032218
    // 0x8003262C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80032218(rdram, ctx);
        goto after_2;
    // 0x8003262C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_2:
    // 0x80032630: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80032634: jal         0x80031F1C
    // 0x80032638: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    func_80031F1C(rdram, ctx);
        goto after_3;
    // 0x80032638: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_3:
    // 0x8003263C: jal         0x80032020
    // 0x80032640: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80032020(rdram, ctx);
        goto after_4;
    // 0x80032640: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80032644: jal         0x80031F74
    // 0x80032648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80031F74(rdram, ctx);
        goto after_5;
    // 0x80032648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8003264C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032654: jr          $ra
    // 0x80032658: nop

    return;
    // 0x80032658: nop

;}
RECOMP_FUNC void func_80102058_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102058: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8010205C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80102060: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80102064: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80102068: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8010206C: jr          $ra
    // 0x80102070: sh          $zero, 0x6284($at)
    MEM_H(0X6284, ctx->r1) = 0;
    return;
    // 0x80102070: sh          $zero, 0x6284($at)
    MEM_H(0X6284, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8000B2B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B2B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000B2BC: sw          $zero, -0x2F3C($at)
    MEM_W(-0X2F3C, ctx->r1) = 0;
    // 0x8000B2C0: jr          $ra
    // 0x8000B2C4: nop

    return;
    // 0x8000B2C4: nop

;}
RECOMP_FUNC void func_80101148_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101148: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010114C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80101150: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80101154: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101158: addiu       $v0, $v0, 0x6250
    ctx->r2 = ADD32(ctx->r2, 0X6250);
    // 0x8010115C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80101160: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80101164: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_80101168:
    // 0x80101168: sh          $zero, 0x80($v0)
    MEM_H(0X80, ctx->r2) = 0;
    // 0x8010116C: sh          $zero, 0x30($v0)
    MEM_H(0X30, ctx->r2) = 0;
    // 0x80101170: lh          $t7, 0x80($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X80);
    // 0x80101174: lh          $t6, 0x30($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X30);
    // 0x80101178: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8010117C: sw          $zero, 0x50($v0)
    MEM_W(0X50, ctx->r2) = 0;
    // 0x80101180: sh          $zero, 0x54($v0)
    MEM_H(0X54, ctx->r2) = 0;
    // 0x80101184: sh          $zero, 0x56($v0)
    MEM_H(0X56, ctx->r2) = 0;
    // 0x80101188: sh          $zero, 0x5C($v0)
    MEM_H(0X5C, ctx->r2) = 0;
    // 0x8010118C: sh          $zero, 0x5E($v0)
    MEM_H(0X5E, ctx->r2) = 0;
    // 0x80101190: sh          $zero, 0x58($v0)
    MEM_H(0X58, ctx->r2) = 0;
    // 0x80101194: sh          $zero, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = 0;
    // 0x80101198: sh          $zero, 0x60($v0)
    MEM_H(0X60, ctx->r2) = 0;
    // 0x8010119C: sh          $zero, 0x62($v0)
    MEM_H(0X62, ctx->r2) = 0;
    // 0x801011A0: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x801011A4: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
    // 0x801011A8: swc1        $f0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f0.u32l;
    // 0x801011AC: sh          $a0, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = ctx->r4;
    // 0x801011B0: sh          $zero, 0x82($v0)
    MEM_H(0X82, ctx->r2) = 0;
    // 0x801011B4: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x801011B8: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x801011BC: sh          $zero, 0x74($v0)
    MEM_H(0X74, ctx->r2) = 0;
    // 0x801011C0: sh          $zero, 0x7A($v0)
    MEM_H(0X7A, ctx->r2) = 0;
    // 0x801011C4: sh          $zero, 0x7C($v0)
    MEM_H(0X7C, ctx->r2) = 0;
    // 0x801011C8: sh          $zero, 0x76($v0)
    MEM_H(0X76, ctx->r2) = 0;
    // 0x801011CC: sh          $zero, 0x78($v0)
    MEM_H(0X78, ctx->r2) = 0;
    // 0x801011D0: sh          $zero, 0x84($v0)
    MEM_H(0X84, ctx->r2) = 0;
    // 0x801011D4: swc1        $f0, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f0.u32l;
    // 0x801011D8: swc1        $f2, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f2.u32l;
    // 0x801011DC: sh          $zero, 0x9C($v0)
    MEM_H(0X9C, ctx->r2) = 0;
    // 0x801011E0: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x801011E4: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
    // 0x801011E8: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
    // 0x801011EC: sw          $zero, -0xA0($v0)
    MEM_W(-0XA0, ctx->r2) = 0;
    // 0x801011F0: sh          $zero, -0x9C($v0)
    MEM_H(-0X9C, ctx->r2) = 0;
    // 0x801011F4: sh          $zero, -0x9A($v0)
    MEM_H(-0X9A, ctx->r2) = 0;
    // 0x801011F8: sh          $zero, -0x94($v0)
    MEM_H(-0X94, ctx->r2) = 0;
    // 0x801011FC: sh          $zero, -0x92($v0)
    MEM_H(-0X92, ctx->r2) = 0;
    // 0x80101200: sh          $zero, -0x98($v0)
    MEM_H(-0X98, ctx->r2) = 0;
    // 0x80101204: sh          $zero, -0x96($v0)
    MEM_H(-0X96, ctx->r2) = 0;
    // 0x80101208: sh          $zero, -0x90($v0)
    MEM_H(-0X90, ctx->r2) = 0;
    // 0x8010120C: sh          $zero, -0x8E($v0)
    MEM_H(-0X8E, ctx->r2) = 0;
    // 0x80101210: sw          $zero, -0x8C($v0)
    MEM_W(-0X8C, ctx->r2) = 0;
    // 0x80101214: sw          $zero, -0x88($v0)
    MEM_W(-0X88, ctx->r2) = 0;
    // 0x80101218: swc1        $f0, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8010121C: sh          $a0, -0x52($v0)
    MEM_H(-0X52, ctx->r2) = ctx->r4;
    // 0x80101220: sh          $zero, -0x6E($v0)
    MEM_H(-0X6E, ctx->r2) = 0;
    // 0x80101224: swc1        $f0, -0x84($v0)
    MEM_W(-0X84, ctx->r2) = ctx->f0.u32l;
    // 0x80101228: swc1        $f0, -0x80($v0)
    MEM_W(-0X80, ctx->r2) = ctx->f0.u32l;
    // 0x8010122C: sh          $zero, -0x7C($v0)
    MEM_H(-0X7C, ctx->r2) = 0;
    // 0x80101230: sh          $zero, -0x76($v0)
    MEM_H(-0X76, ctx->r2) = 0;
    // 0x80101234: sh          $zero, -0x74($v0)
    MEM_H(-0X74, ctx->r2) = 0;
    // 0x80101238: sh          $zero, -0x7A($v0)
    MEM_H(-0X7A, ctx->r2) = 0;
    // 0x8010123C: sh          $zero, -0x78($v0)
    MEM_H(-0X78, ctx->r2) = 0;
    // 0x80101240: sh          $zero, -0x6C($v0)
    MEM_H(-0X6C, ctx->r2) = 0;
    // 0x80101244: swc1        $f0, -0x60($v0)
    MEM_W(-0X60, ctx->r2) = ctx->f0.u32l;
    // 0x80101248: swc1        $f2, -0x5C($v0)
    MEM_W(-0X5C, ctx->r2) = ctx->f2.u32l;
    // 0x8010124C: sh          $zero, -0x54($v0)
    MEM_H(-0X54, ctx->r2) = 0;
    // 0x80101250: sw          $zero, -0x68($v0)
    MEM_W(-0X68, ctx->r2) = 0;
    // 0x80101254: sw          $zero, -0x64($v0)
    MEM_W(-0X64, ctx->r2) = 0;
    // 0x80101258: sh          $t7, -0x22($v0)
    MEM_H(-0X22, ctx->r2) = ctx->r15;
    // 0x8010125C: bne         $v1, $a1, L_80101168
    if (ctx->r3 != ctx->r5) {
        // 0x80101260: sh          $t6, -0x72($v0)
        MEM_H(-0X72, ctx->r2) = ctx->r14;
            goto L_80101168;
    }
    // 0x80101260: sh          $t6, -0x72($v0)
    MEM_H(-0X72, ctx->r2) = ctx->r14;
    // 0x80101264: jr          $ra
    // 0x80101268: nop

    return;
    // 0x80101268: nop

;}
RECOMP_FUNC void alSeqpSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038550: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80038554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038558: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8003855C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038560: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80038564: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80038568: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x8003856C: jal         0x8003FE6C
    // 0x80038570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80038570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80038574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038578: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003857C: jr          $ra
    // 0x80038580: nop

    return;
    // 0x80038580: nop

    // 0x80038584: nop

    // 0x80038588: nop

    // 0x8003858C: nop

;}
RECOMP_FUNC void func_80044760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004476C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80044770: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80044774: beql        $t6, $zero, L_800447E0
    if (ctx->r14 == 0) {
        // 0x80044778: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800447E0;
    }
    goto skip_0;
    // 0x80044778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004477C: jal         0x80036A30
    // 0x80044780: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x80044780: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80044784: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044788: beq         $v0, $zero, L_800447DC
    if (ctx->r2 == 0) {
        // 0x8004478C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800447DC;
    }
    // 0x8004478C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80044790: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80044794: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80044798: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x8004479C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800447A0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800447A4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800447A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800447AC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800447B0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800447B4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800447B8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800447BC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800447C0: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x800447C4: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x800447C8: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800447CC: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800447D0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800447D4: jalr        $t9
    // 0x800447D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800447D8: nop

    after_1:
L_800447DC:
    // 0x800447DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800447E0:
    // 0x800447E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800447E4: jr          $ra
    // 0x800447E8: nop

    return;
    // 0x800447E8: nop

    // 0x800447EC: nop

;}
RECOMP_FUNC void func_800027D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800027D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800027D4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800027D8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800027DC: lui         $a0, 0x87
    ctx->r4 = S32(0X87 << 16);
    // 0x800027E0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800027E4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800027E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800027EC: addiu       $t0, $t0, -0x43E4
    ctx->r8 = ADD32(ctx->r8, -0X43E4);
    // 0x800027F0: addiu       $a3, $a3, -0x43EC
    ctx->r7 = ADD32(ctx->r7, -0X43EC);
    // 0x800027F4: addiu       $a0, $a0, -0x47D0
    ctx->r4 = ADD32(ctx->r4, -0X47D0);
    // 0x800027F8: addiu       $v1, $v1, -0x4580
    ctx->r3 = ADD32(ctx->r3, -0X4580);
    // 0x800027FC: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80002800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002804: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80002808: addiu       $t6, $t6, 0x3D04
    ctx->r14 = ADD32(ctx->r14, 0X3D04);
    // 0x8000280C: addiu       $t9, $t6, 0x30
    ctx->r25 = ADD32(ctx->r14, 0X30);
    // 0x80002810: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80002814:
    // 0x80002814: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80002818: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8000281C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80002820: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x80002824: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80002828: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x8000282C: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x80002830: bne         $t6, $t9, L_80002814
    if (ctx->r14 != ctx->r25) {
        // 0x80002834: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_80002814;
    }
    // 0x80002834: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x80002838: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8000283C: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80002840: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80002844: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80002848: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8000284C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80002850: addiu       $t5, $t5, -0x44C8
    ctx->r13 = ADD32(ctx->r13, -0X44C8);
    // 0x80002854: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80002858: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8000285C: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80002860: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x80002864: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80002868: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x8000286C: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80002870: sh          $zero, 0x11C($v0)
    MEM_H(0X11C, ctx->r2) = 0;
    // 0x80002874: sh          $t3, 0x66($v0)
    MEM_H(0X66, ctx->r2) = ctx->r11;
    // 0x80002878: sh          $zero, 0x68($v0)
    MEM_H(0X68, ctx->r2) = 0;
    // 0x8000287C: sh          $t4, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = ctx->r12;
    // 0x80002880: sw          $v1, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r3;
    // 0x80002884: sw          $t5, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r13;
    // 0x80002888: sh          $zero, 0x72($v0)
    MEM_H(0X72, ctx->r2) = 0;
    // 0x8000288C: sh          $zero, 0x74($v0)
    MEM_H(0X74, ctx->r2) = 0;
    // 0x80002890: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002894: addiu       $t8, $zero, 0x108
    ctx->r24 = ADD32(0, 0X108);
    // 0x80002898: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x8000289C: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800028A0: sh          $t2, 0x64($v0)
    MEM_H(0X64, ctx->r2) = ctx->r10;
    // 0x800028A4: sw          $t8, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r24;
    // 0x800028A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800028AC: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x800028B0: sh          $t7, -0x45A0($at)
    MEM_H(-0X45A0, ctx->r1) = ctx->r15;
    // 0x800028B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800028B8: addiu       $t9, $zero, 0x11
    ctx->r25 = ADD32(0, 0X11);
    // 0x800028BC: sh          $t9, -0x459E($at)
    MEM_H(-0X459E, ctx->r1) = ctx->r25;
    // 0x800028C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800028C4: sh          $zero, -0x459C($at)
    MEM_H(-0X459C, ctx->r1) = 0;
    // 0x800028C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800028CC: swc1        $f0, -0x4360($at)
    MEM_W(-0X4360, ctx->r1) = ctx->f0.u32l;
    // 0x800028D0: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x800028D4: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800028D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800028DC: lui         $t6, 0x87
    ctx->r14 = S32(0X87 << 16);
    // 0x800028E0: swc1        $f8, -0x43F0($at)
    MEM_W(-0X43F0, ctx->r1) = ctx->f8.u32l;
    // 0x800028E4: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x800028E8: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800028EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800028F0: addiu       $t6, $t6, 0x1900
    ctx->r14 = ADD32(ctx->r14, 0X1900);
    // 0x800028F4: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x800028F8: addiu       $a1, $a1, 0x6000
    ctx->r5 = ADD32(ctx->r5, 0X6000);
    // 0x800028FC: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    // 0x80002900: jal         0x80024260
    // 0x80002904: swc1        $f10, -0x43E8($at)
    MEM_W(-0X43E8, ctx->r1) = ctx->f10.u32l;
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80002904: swc1        $f10, -0x43E8($at)
    MEM_W(-0X43E8, ctx->r1) = ctx->f10.u32l;
    after_0:
    // 0x80002908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000290C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002910: jr          $ra
    // 0x80002914: nop

    return;
    // 0x80002914: nop

;}
RECOMP_FUNC void func_80026A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026A80: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80026A84: addiu       $a1, $a1, -0x4D04
    ctx->r5 = ADD32(ctx->r5, -0X4D04);
    // 0x80026A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026A8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80026A90: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80026A94: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80026A98: addiu       $t8, $t8, -0x560
    ctx->r24 = ADD32(ctx->r24, -0X560);
    // 0x80026A9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80026AA0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80026AA4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80026AA8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80026AAC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80026AB0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80026AB4: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x80026AB8: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x80026ABC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80026AC0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80026AC4: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x80026AC8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80026ACC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80026AD0: jal         0x8002A668
    // 0x80026AD4: nop

    func_8002A668(rdram, ctx);
        goto after_0;
    // 0x80026AD4: nop

    after_0:
    // 0x80026AD8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80026ADC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026AE0: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026AE4: addiu       $v0, $v0, -0x2F0
    ctx->r2 = ADD32(ctx->r2, -0X2F0);
    // 0x80026AE8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80026AEC: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    // 0x80026AF0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80026AF4: andi        $t6, $v1, 0x4000
    ctx->r14 = ctx->r3 & 0X4000;
    // 0x80026AF8: beq         $t6, $zero, L_80026B1C
    if (ctx->r14 == 0) {
        // 0x80026AFC: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_80026B1C;
    }
    // 0x80026AFC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80026B00: jal         0x8002B57C
    // 0x80026B04: nop

    func_8002B57C(rdram, ctx);
        goto after_1;
    // 0x80026B04: nop

    after_1:
    // 0x80026B08: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026B0C: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026B10: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026B14: b           L_80026BD8
    // 0x80026B18: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
        goto L_80026BD8;
    // 0x80026B18: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
L_80026B1C:
    // 0x80026B1C: andi        $t7, $v1, 0x2000
    ctx->r15 = ctx->r3 & 0X2000;
    // 0x80026B20: beq         $t7, $zero, L_80026B44
    if (ctx->r15 == 0) {
        // 0x80026B24: andi        $t8, $v1, 0x3
        ctx->r24 = ctx->r3 & 0X3;
            goto L_80026B44;
    }
    // 0x80026B24: andi        $t8, $v1, 0x3
    ctx->r24 = ctx->r3 & 0X3;
    // 0x80026B28: jal         0x80026D1C
    // 0x80026B2C: nop

    func_80026D1C(rdram, ctx);
        goto after_2;
    // 0x80026B2C: nop

    after_2:
    // 0x80026B30: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026B34: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026B38: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026B3C: b           L_80026BD8
    // 0x80026B40: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
        goto L_80026BD8;
    // 0x80026B40: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
L_80026B44:
    // 0x80026B44: beq         $t8, $zero, L_80026B6C
    if (ctx->r24 == 0) {
        // 0x80026B48: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80026B6C;
    }
    // 0x80026B48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80026B4C: beq         $t8, $at, L_80026B88
    if (ctx->r24 == ctx->r1) {
        // 0x80026B50: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80026B88;
    }
    // 0x80026B50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80026B54: beq         $t8, $at, L_80026BA4
    if (ctx->r24 == ctx->r1) {
        // 0x80026B58: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80026BA4;
    }
    // 0x80026B58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80026B5C: beq         $t8, $at, L_80026BC0
    if (ctx->r24 == ctx->r1) {
        // 0x80026B60: nop
    
            goto L_80026BC0;
    }
    // 0x80026B60: nop

    // 0x80026B64: b           L_80026BD8
    // 0x80026B68: nop

        goto L_80026BD8;
    // 0x80026B68: nop

L_80026B6C:
    // 0x80026B6C: jal         0x80026F34
    // 0x80026B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80026F34(rdram, ctx);
        goto after_3;
    // 0x80026B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80026B74: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026B78: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026B7C: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026B80: b           L_80026BD8
    // 0x80026B84: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
        goto L_80026BD8;
    // 0x80026B84: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
L_80026B88:
    // 0x80026B88: jal         0x800278B0
    // 0x80026B8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800278B0(rdram, ctx);
        goto after_4;
    // 0x80026B8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80026B90: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026B94: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026B98: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026B9C: b           L_80026BD8
    // 0x80026BA0: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
        goto L_80026BD8;
    // 0x80026BA0: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
L_80026BA4:
    // 0x80026BA4: jal         0x80028624
    // 0x80026BA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80028624(rdram, ctx);
        goto after_5;
    // 0x80026BA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80026BAC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026BB0: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026BB4: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026BB8: b           L_80026BD8
    // 0x80026BBC: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
        goto L_80026BD8;
    // 0x80026BBC: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
L_80026BC0:
    // 0x80026BC0: jal         0x80029448
    // 0x80026BC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80029448(rdram, ctx);
        goto after_6;
    // 0x80026BC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80026BC8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80026BCC: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026BD0: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026BD4: lhu         $v1, -0x2F4($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2F4);
L_80026BD8:
    // 0x80026BD8: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80026BDC: andi        $t9, $v1, 0xFFEF
    ctx->r25 = ctx->r3 & 0XFFEF;
    // 0x80026BE0: addiu       $t0, $t0, -0x4D04
    ctx->r8 = ADD32(ctx->r8, -0X4D04);
    // 0x80026BE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80026BE8: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x80026BEC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80026BF0: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x80026BF4: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x80026BF8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80026BFC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80026C00: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80026C04: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80026C08: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80026C0C: lui         $t5, 0xF900
    ctx->r13 = S32(0XF900 << 16);
    // 0x80026C10: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80026C14: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80026C18: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80026C1C: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80026C20: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80026C24: lhu         $a2, 0x2876($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X2876);
    // 0x80026C28: andi        $t6, $a2, 0x4000
    ctx->r14 = ctx->r6 & 0X4000;
    // 0x80026C2C: bne         $t6, $zero, L_80026C3C
    if (ctx->r14 != 0) {
        // 0x80026C30: andi        $t7, $a2, 0x1000
        ctx->r15 = ctx->r6 & 0X1000;
            goto L_80026C3C;
    }
    // 0x80026C30: andi        $t7, $a2, 0x1000
    ctx->r15 = ctx->r6 & 0X1000;
    // 0x80026C34: beql        $t7, $zero, L_80026C70
    if (ctx->r15 == 0) {
        // 0x80026C38: lhu         $v1, 0x0($t1)
        ctx->r3 = MEM_HU(ctx->r9, 0X0);
            goto L_80026C70;
    }
    goto skip_0;
    // 0x80026C38: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    skip_0:
L_80026C3C:
    // 0x80026C3C: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    // 0x80026C40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026C44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80026C48: andi        $t8, $v1, 0x4000
    ctx->r24 = ctx->r3 & 0X4000;
    // 0x80026C4C: bne         $t8, $zero, L_80026C6C
    if (ctx->r24 != 0) {
        // 0x80026C50: andi        $t9, $v1, 0x7FFF
        ctx->r25 = ctx->r3 & 0X7FFF;
            goto L_80026C6C;
    }
    // 0x80026C50: andi        $t9, $v1, 0x7FFF
    ctx->r25 = ctx->r3 & 0X7FFF;
    // 0x80026C54: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x80026C58: jal         0x800268D4
    // 0x80026C5C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_7;
    // 0x80026C5C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_7:
    // 0x80026C60: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80026C64: addiu       $t1, $t1, -0x2F4
    ctx->r9 = ADD32(ctx->r9, -0X2F4);
    // 0x80026C68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80026C6C:
    // 0x80026C6C: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
L_80026C70:
    // 0x80026C70: andi        $t2, $v1, 0x8000
    ctx->r10 = ctx->r3 & 0X8000;
    // 0x80026C74: bne         $t2, $zero, L_80026D0C
    if (ctx->r10 != 0) {
        // 0x80026C78: andi        $t3, $v1, 0x4000
        ctx->r11 = ctx->r3 & 0X4000;
            goto L_80026D0C;
    }
    // 0x80026C78: andi        $t3, $v1, 0x4000
    ctx->r11 = ctx->r3 & 0X4000;
    // 0x80026C7C: beq         $t3, $zero, L_80026D00
    if (ctx->r11 == 0) {
        // 0x80026C80: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80026D00;
    }
    // 0x80026C80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80026C84: andi        $t4, $v1, 0xC
    ctx->r12 = ctx->r3 & 0XC;
    // 0x80026C88: beq         $t4, $zero, L_80026CAC
    if (ctx->r12 == 0) {
        // 0x80026C8C: lui         $t5, 0x8009
        ctx->r13 = S32(0X8009 << 16);
            goto L_80026CAC;
    }
    // 0x80026C8C: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80026C90: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80026C94: beq         $t4, $at, L_80026CF4
    if (ctx->r12 == ctx->r1) {
        // 0x80026C98: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80026CF4;
    }
    // 0x80026C98: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80026C9C: beq         $t4, $at, L_80026CE8
    if (ctx->r12 == ctx->r1) {
        // 0x80026CA0: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_80026CE8;
    }
    // 0x80026CA0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80026CA4: b           L_80026D04
    // 0x80026CA8: nop

        goto L_80026D04;
    // 0x80026CA8: nop

L_80026CAC:
    // 0x80026CAC: lhu         $t5, -0x2E0($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2E0);
    // 0x80026CB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80026CB4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80026CB8: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80026CBC: beq         $t6, $zero, L_80026CD8
    if (ctx->r14 == 0) {
        // 0x80026CC0: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80026CD8;
    }
    // 0x80026CC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80026CC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80026CC8: sh          $a3, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r7;
    // 0x80026CCC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026CD0: b           L_80026D04
    // 0x80026CD4: sb          $t7, -0x2F2($at)
    MEM_B(-0X2F2, ctx->r1) = ctx->r15;
        goto L_80026D04;
    // 0x80026CD4: sb          $t7, -0x2F2($at)
    MEM_B(-0X2F2, ctx->r1) = ctx->r15;
L_80026CD8:
    // 0x80026CD8: sh          $t8, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r24;
    // 0x80026CDC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80026CE0: b           L_80026D04
    // 0x80026CE4: sb          $zero, -0x2F2($at)
    MEM_B(-0X2F2, ctx->r1) = 0;
        goto L_80026D04;
    // 0x80026CE4: sb          $zero, -0x2F2($at)
    MEM_B(-0X2F2, ctx->r1) = 0;
L_80026CE8:
    // 0x80026CE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80026CEC: b           L_80026D04
    // 0x80026CF0: sh          $t9, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r25;
        goto L_80026D04;
    // 0x80026CF0: sh          $t9, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r25;
L_80026CF4:
    // 0x80026CF4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80026CF8: b           L_80026D04
    // 0x80026CFC: sh          $a3, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r7;
        goto L_80026D04;
    // 0x80026CFC: sh          $a3, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r7;
L_80026D00:
    // 0x80026D00: sh          $a3, -0x4D20($at)
    MEM_H(-0X4D20, ctx->r1) = ctx->r7;
L_80026D04:
    // 0x80026D04: jal         0x80026A40
    // 0x80026D08: nop

    func_80026A40(rdram, ctx);
        goto after_8;
    // 0x80026D08: nop

    after_8:
L_80026D0C:
    // 0x80026D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026D14: jr          $ra
    // 0x80026D18: nop

    return;
    // 0x80026D18: nop

;}
RECOMP_FUNC void func_800353B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800353B8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800353BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800353C0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800353C4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800353C8: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800353CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800353D0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800353D4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800353D8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800353DC: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800353E0:
    // 0x800353E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800353E4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800353E8:
    // 0x800353E8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800353EC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800353F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800353F4: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800353F8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800353FC: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x80035400: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x80035404: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80035408: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8003540C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80035410: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80035414: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80035418: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x8003541C: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x80035420: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x80035424: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x80035428: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003542C: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80035430: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x80035434: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80035438: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8003543C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80035440: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80035444: div.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80035448: div.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003544C: swc1        $f18, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f18.u32l;
    // 0x80035450: bne         $a0, $t3, L_800353E8
    if (ctx->r4 != ctx->r11) {
        // 0x80035454: swc1        $f16, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
            goto L_800353E8;
    }
    // 0x80035454: swc1        $f16, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f16.u32l;
    // 0x80035458: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8003545C: bne         $a2, $t4, L_800353E0
    if (ctx->r6 != ctx->r12) {
        // 0x80035460: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800353E0;
    }
    // 0x80035460: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80035464: jr          $ra
    // 0x80035468: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80035468: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8003546C: nop

;}
RECOMP_FUNC void func_80024A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024A48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80024A4C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80024A50: addiu       $v1, $v1, -0x968
    ctx->r3 = ADD32(ctx->r3, -0X968);
    // 0x80024A54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80024A58: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80024A5C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80024A60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80024A64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80024A68: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80024A6C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80024A70: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80024A74: addiu       $t7, $t7, -0x958
    ctx->r15 = ADD32(ctx->r15, -0X958);
    // 0x80024A78: bne         $t6, $zero, L_80024AF0
    if (ctx->r14 != 0) {
        // 0x80024A7C: lui         $s0, 0x8009
        ctx->r16 = S32(0X8009 << 16);
            goto L_80024AF0;
    }
    // 0x80024A7C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80024A80: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80024A84: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80024A88: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80024A8C: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80024A90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80024A94: addiu       $s2, $s2, -0xDC0
    ctx->r18 = ADD32(ctx->r18, -0XDC0);
    // 0x80024A98: addiu       $s3, $s3, -0x6D8
    ctx->r19 = ADD32(ctx->r19, -0X6D8);
    // 0x80024A9C: addiu       $s1, $s1, -0x944
    ctx->r17 = ADD32(ctx->r17, -0X944);
    // 0x80024AA0: addiu       $s0, $s0, -0x958
    ctx->r16 = ADD32(ctx->r16, -0X958);
L_80024AA4:
    // 0x80024AA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80024AA8: jal         0x80036850
    // 0x80024AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80036850(rdram, ctx);
        goto after_0;
    // 0x80024AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80024AB0: addiu       $t8, $zero, 0x500
    ctx->r24 = ADD32(0, 0X500);
    // 0x80024AB4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80024AB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80024ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80024AC0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80024AC4: jal         0x80036660
    // 0x80024AC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x80024AC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80024ACC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80024AD0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80024AD4: bne         $s1, $s3, L_80024AA4
    if (ctx->r17 != ctx->r19) {
        // 0x80024AD8: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_80024AA4;
    }
    // 0x80024AD8: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80024ADC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80024AE0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80024AE4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80024AE8: addiu       $v1, $v1, -0x968
    ctx->r3 = ADD32(ctx->r3, -0X968);
    // 0x80024AEC: sb          $t9, -0x968($at)
    MEM_B(-0X968, ctx->r1) = ctx->r25;
L_80024AF0:
    // 0x80024AF0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80024AF4: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x80024AF8: addiu       $v0, $v0, 0x48C8
    ctx->r2 = ADD32(ctx->r2, 0X48C8);
    // 0x80024AFC: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x80024B00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80024B04: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80024B08: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80024B0C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80024B10: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80024B14: jr          $ra
    // 0x80024B18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80024B18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80049B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049B4C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80049B50: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x80049B54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80049B58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80049B5C: bgez        $a2, L_80049B70
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80049B60: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80049B70;
    }
    // 0x80049B60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049B64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80049B68: nop

    // 0x80049B6C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80049B70:
    // 0x80049B70: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80049B74: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80049B78: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80049B7C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80049B80: ldc1        $f10, 0x23C8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X23C8);
    // 0x80049B84: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80049B88: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80049B8C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80049B90: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80049B94: div.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f18.d);
    // 0x80049B98: jr          $ra
    // 0x80049B9C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    return;
    // 0x80049B9C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
;}
RECOMP_FUNC void func_80025634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002563C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80025640: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80025644: lw          $t6, -0x974($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X974);
    // 0x80025648: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x8002564C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025650: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80025654: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    // 0x80025658: jal         0x800398B0
    // 0x8002565C: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398B0(rdram, ctx);
        goto after_0;
    // 0x8002565C: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_0:
    // 0x80025660: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025664: jal         0x800398D0
    // 0x80025668: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398D0(rdram, ctx);
        goto after_1;
    // 0x80025668: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_1:
    // 0x8002566C: bne         $v0, $zero, L_8002567C
    if (ctx->r2 != 0) {
        // 0x80025670: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_8002567C;
    }
    // 0x80025670: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80025674: jal         0x800398F0
    // 0x80025678: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    func_800398F0(rdram, ctx);
        goto after_2;
    // 0x80025678: addiu       $a0, $a0, -0x9E0
    ctx->r4 = ADD32(ctx->r4, -0X9E0);
    after_2:
L_8002567C:
    // 0x8002567C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025684: jr          $ra
    // 0x80025688: nop

    return;
    // 0x80025688: nop

;}
RECOMP_FUNC void func_8002BCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BCA0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002BCA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002BCA8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002BCAC: lbu         $v1, -0x2DE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2DE);
    // 0x8002BCB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002BCB4: beq         $v1, $at, L_8002BCD4
    if (ctx->r3 == ctx->r1) {
        // 0x8002BCB8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8002BCD4;
    }
    // 0x8002BCB8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002BCBC: beq         $v1, $at, L_8002BCD4
    if (ctx->r3 == ctx->r1) {
        // 0x8002BCC0: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8002BCD4;
    }
    // 0x8002BCC0: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8002BCC4: beq         $v1, $at, L_8002BCD4
    if (ctx->r3 == ctx->r1) {
        // 0x8002BCC8: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8002BCD4;
    }
    // 0x8002BCC8: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8002BCCC: bne         $v1, $at, L_8002BCE4
    if (ctx->r3 != ctx->r1) {
        // 0x8002BCD0: nop
    
            goto L_8002BCE4;
    }
    // 0x8002BCD0: nop

L_8002BCD4:
    // 0x8002BCD4: jal         0x8002C818
    // 0x8002BCD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002C818(rdram, ctx);
        goto after_0;
    // 0x8002BCD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8002BCDC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002BCE0: lbu         $v1, -0x2DE($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X2DE);
L_8002BCE4:
    // 0x8002BCE4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8002BCE8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002BCEC: lhu         $t8, -0x2F4($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2F4);
    // 0x8002BCF0: addiu       $t7, $t7, -0x5624
    ctx->r15 = ADD32(ctx->r15, -0X5624);
    // 0x8002BCF4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8002BCF8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8002BCFC: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x8002BD00: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8002BD04: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8002BD08: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x8002BD0C: beq         $t9, $zero, L_8002BD2C
    if (ctx->r25 == 0) {
        // 0x8002BD10: lh          $t0, 0x6($v0)
        ctx->r8 = MEM_H(ctx->r2, 0X6);
            goto L_8002BD2C;
    }
    // 0x8002BD10: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x8002BD14: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8002BD18: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x8002BD1C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8002BD20: lw          $t2, -0x56EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X56EC);
    // 0x8002BD24: b           L_8002BD40
    // 0x8002BD28: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
        goto L_8002BD40;
    // 0x8002BD28: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_8002BD2C:
    // 0x8002BD2C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8002BD30: lui         $t4, 0x8007
    ctx->r12 = S32(0X8007 << 16);
    // 0x8002BD34: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8002BD38: lw          $t4, -0x5688($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5688);
    // 0x8002BD3C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_8002BD40:
    // 0x8002BD40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002BD44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8002BD48: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8002BD4C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8002BD50: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002BD54: jal         0x80029B58
    // 0x8002BD58: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80029B58(rdram, ctx);
        goto after_1;
    // 0x8002BD58: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x8002BD5C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8002BD60: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002BD64: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002BD68: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002BD6C: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8002BD70: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002BD74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002BD78: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002BD7C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BD80: jal         0x80029B58
    // 0x8002BD84: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x8002BD84: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    after_2:
    // 0x8002BD88: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8002BD8C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BD90: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002BD94: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8002BD98: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8002BD9C: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x8002BDA0: addiu       $t2, $t1, -0x5
    ctx->r10 = ADD32(ctx->r9, -0X5);
    // 0x8002BDA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002BDA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002BDAC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002BDB0: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002BDB4: jal         0x80029B58
    // 0x8002BDB8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x8002BDB8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x8002BDBC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002BDC0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BDC4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002BDC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002BDCC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002BDD0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8002BDD4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8002BDD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002BDDC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002BDE0: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002BDE4: jal         0x80029B58
    // 0x8002BDE8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_80029B58(rdram, ctx);
        goto after_4;
    // 0x8002BDE8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_4:
    // 0x8002BDEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002BDF0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8002BDF4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002BDF8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002BDFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002BE00: jal         0x80029B58
    // 0x8002BE04: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x8002BE04: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8002BE08: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE0C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002BE10: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002BE14: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002BE18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002BE1C: jal         0x80029B58
    // 0x8002BE20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x8002BE20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_6:
    // 0x8002BE24: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE28: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002BE2C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002BE30: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002BE34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002BE38: jal         0x80029B58
    // 0x8002BE3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x8002BE3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_7:
    // 0x8002BE40: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002BE44: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002BE48: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BE4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002BE50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002BE54: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002BE58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002BE5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002BE60: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002BE64: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002BE68: jal         0x80029B58
    // 0x8002BE6C: addiu       $a3, $a3, -0x3
    ctx->r7 = ADD32(ctx->r7, -0X3);
    func_80029B58(rdram, ctx);
        goto after_8;
    // 0x8002BE6C: addiu       $a3, $a3, -0x3
    ctx->r7 = ADD32(ctx->r7, -0X3);
    after_8:
    // 0x8002BE70: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002BE74: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002BE78: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002BE7C: addiu       $t9, $t8, -0x4
    ctx->r25 = ADD32(ctx->r24, -0X4);
    // 0x8002BE80: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002BE84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002BE88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002BE8C: jal         0x80029B58
    // 0x8002BE90: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    func_80029B58(rdram, ctx);
        goto after_9;
    // 0x8002BE90: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_9:
    // 0x8002BE94: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002BE98: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002BE9C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002BEA0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002BEA4: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002BEA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002BEAC: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8002BEB0: jal         0x80029B58
    // 0x8002BEB4: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    func_80029B58(rdram, ctx);
        goto after_10;
    // 0x8002BEB4: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    after_10:
    // 0x8002BEB8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002BEBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002BEC0: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002BEC4: addiu       $t3, $t2, -0x3
    ctx->r11 = ADD32(ctx->r10, -0X3);
    // 0x8002BEC8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002BECC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8002BED0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002BED4: jal         0x80029B58
    // 0x8002BED8: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    func_80029B58(rdram, ctx);
        goto after_11;
    // 0x8002BED8: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    after_11:
    // 0x8002BEDC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002BEE0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8002BEE4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8002BEE8: jal         0x80030EA0
    // 0x8002BEEC: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    func_80030EA0(rdram, ctx);
        goto after_12;
    // 0x8002BEEC: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    after_12:
    // 0x8002BEF0: jal         0x8002DF6C
    // 0x8002BEF4: nop

    func_8002DF6C(rdram, ctx);
        goto after_13;
    // 0x8002BEF4: nop

    after_13:
    // 0x8002BEF8: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002BEFC: addiu       $t0, $t0, -0x2D7
    ctx->r8 = ADD32(ctx->r8, -0X2D7);
    // 0x8002BF00: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x8002BF04: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002BF08: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002BF0C: bltz        $v0, L_8002BF1C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002BF10: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_8002BF1C;
    }
    // 0x8002BF10: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8002BF14: sb          $t4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r12;
    // 0x8002BF18: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
L_8002BF1C:
    // 0x8002BF1C: bgez        $v0, L_8002C174
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002BF20: nop
    
            goto L_8002C174;
    }
    // 0x8002BF20: nop

    // 0x8002BF24: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BF28: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002BF2C: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
    // 0x8002BF30: bne         $t5, $zero, L_8002C174
    if (ctx->r13 != 0) {
        // 0x8002BF34: nop
    
            goto L_8002C174;
    }
    // 0x8002BF34: nop

    // 0x8002BF38: lhu         $a0, 0x2876($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2876);
    // 0x8002BF3C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8002BF40: andi        $t6, $a0, 0x8000
    ctx->r14 = ctx->r4 & 0X8000;
    // 0x8002BF44: beq         $t6, $zero, L_8002BFB0
    if (ctx->r14 == 0) {
        // 0x8002BF48: nop
    
            goto L_8002BFB0;
    }
    // 0x8002BF48: nop

    // 0x8002BF4C: lbu         $t7, -0x2DE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2DE);
    // 0x8002BF50: addiu       $t8, $t7, -0x8
    ctx->r24 = ADD32(ctx->r15, -0X8);
    // 0x8002BF54: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x8002BF58: beq         $at, $zero, L_8002BFB0
    if (ctx->r1 == 0) {
        // 0x8002BF5C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8002BFB0;
    }
    // 0x8002BF5C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002BF60: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002BF64: addu        $at, $at, $t8
    gpr jr_addend_8002BF6C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002BF68: lw          $t8, 0x1780($at)
    ctx->r24 = ADD32(ctx->r1, 0X1780);
    // 0x8002BF6C: jr          $t8
    // 0x8002BF70: nop

    switch (jr_addend_8002BF6C >> 2) {
        case 0: goto L_8002BF74; break;
        case 1: goto L_8002BF74; break;
        case 2: goto L_8002BF74; break;
        case 3: goto L_8002BF74; break;
        case 4: goto L_8002BF74; break;
        case 5: goto L_8002BFB0; break;
        case 6: goto L_8002BFB0; break;
        case 7: goto L_8002BFB0; break;
        case 8: goto L_8002BF74; break;
        case 9: goto L_8002BFB0; break;
        case 10: goto L_8002BFB0; break;
        case 11: goto L_8002BFB0; break;
        case 12: goto L_8002BF74; break;
        case 13: goto L_8002BFB0; break;
        case 14: goto L_8002BFB0; break;
        case 15: goto L_8002BFB0; break;
        case 16: goto L_8002BFA8; break;
        default: switch_error(__func__, 0x8002BF6C, 0x80071780);
    }
    // 0x8002BF70: nop

L_8002BF74:
    // 0x8002BF74: ori         $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 | 0X8000;
    // 0x8002BF78: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x8002BF7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002BF80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002BF84: jal         0x800268D4
    // 0x8002BF88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_14;
    // 0x8002BF88: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_14:
    // 0x8002BF8C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002BF90: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002BF94: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8002BF98: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002BF9C: addiu       $t0, $t0, -0x2D7
    ctx->r8 = ADD32(ctx->r8, -0X2D7);
    // 0x8002BFA0: b           L_8002BFB0
    // 0x8002BFA4: lhu         $a0, 0x2876($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2876);
        goto L_8002BFB0;
    // 0x8002BFA4: lhu         $a0, 0x2876($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2876);
L_8002BFA8:
    // 0x8002BFA8: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x8002BFAC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
L_8002BFB0:
    // 0x8002BFB0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002BFB4: andi        $t2, $a0, 0xC000
    ctx->r10 = ctx->r4 & 0XC000;
    // 0x8002BFB8: beq         $t2, $zero, L_8002C0D4
    if (ctx->r10 == 0) {
        // 0x8002BFBC: lbu         $v0, -0x2DE($v0)
        ctx->r2 = MEM_BU(ctx->r2, -0X2DE);
            goto L_8002C0D4;
    }
    // 0x8002BFBC: lbu         $v0, -0x2DE($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X2DE);
    // 0x8002BFC0: addiu       $t3, $v0, -0x4
    ctx->r11 = ADD32(ctx->r2, -0X4);
    // 0x8002BFC4: sltiu       $at, $t3, 0x14
    ctx->r1 = ctx->r11 < 0X14 ? 1 : 0;
    // 0x8002BFC8: beq         $at, $zero, L_8002C174
    if (ctx->r1 == 0) {
        // 0x8002BFCC: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8002C174;
    }
    // 0x8002BFCC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8002BFD0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002BFD4: addu        $at, $at, $t3
    gpr jr_addend_8002BFDC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8002BFD8: lw          $t3, 0x17C4($at)
    ctx->r11 = ADD32(ctx->r1, 0X17C4);
    // 0x8002BFDC: jr          $t3
    // 0x8002BFE0: nop

    switch (jr_addend_8002BFDC >> 2) {
        case 0: goto L_8002C070; break;
        case 1: goto L_8002C070; break;
        case 2: goto L_8002C070; break;
        case 3: goto L_8002C070; break;
        case 4: goto L_8002C174; break;
        case 5: goto L_8002C174; break;
        case 6: goto L_8002C174; break;
        case 7: goto L_8002C174; break;
        case 8: goto L_8002C174; break;
        case 9: goto L_8002C070; break;
        case 10: goto L_8002C070; break;
        case 11: goto L_8002C070; break;
        case 12: goto L_8002C174; break;
        case 13: goto L_8002C034; break;
        case 14: goto L_8002C174; break;
        case 15: goto L_8002BFE4; break;
        case 16: goto L_8002C174; break;
        case 17: goto L_8002C070; break;
        case 18: goto L_8002C070; break;
        case 19: goto L_8002C070; break;
        default: switch_error(__func__, 0x8002BFDC, 0x800717C4);
    }
    // 0x8002BFE0: nop

L_8002BFE4:
    // 0x8002BFE4: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x8002BFE8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002BFEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002BFF0: andi        $t6, $t4, 0xDFFF
    ctx->r14 = ctx->r12 & 0XDFFF;
    // 0x8002BFF4: andi        $t8, $t6, 0xFFF8
    ctx->r24 = ctx->r14 & 0XFFF8;
    // 0x8002BFF8: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8002BFFC: andi        $t1, $t8, 0xBFFF
    ctx->r9 = ctx->r24 & 0XBFFF;
    // 0x8002C000: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8002C004: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8002C008: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x8002C00C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8002C010: sb          $zero, -0x2D6($at)
    MEM_B(-0X2D6, ctx->r1) = 0;
    // 0x8002C014: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C01C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8002C020: ori         $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 | 0X1000;
    // 0x8002C024: jal         0x800268D4
    // 0x8002C028: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    func_800268D4(rdram, ctx);
        goto after_15;
    // 0x8002C028: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    after_15:
    // 0x8002C02C: b           L_8002C174
    // 0x8002C030: nop

        goto L_8002C174;
    // 0x8002C030: nop

L_8002C034:
    // 0x8002C034: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C038: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C03C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8002C040: ori         $t7, $t5, 0x10
    ctx->r15 = ctx->r13 | 0X10;
    // 0x8002C044: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8002C048: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x8002C04C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8002C050: sb          $zero, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = 0;
    // 0x8002C054: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8002C058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C05C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C060: jal         0x800268D4
    // 0x8002C064: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_16;
    // 0x8002C064: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_16:
    // 0x8002C068: b           L_8002C174
    // 0x8002C06C: nop

        goto L_8002C174;
    // 0x8002C06C: nop

L_8002C070:
    // 0x8002C070: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C074: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002C078: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002C07C: andi        $t3, $t1, 0xFFEF
    ctx->r11 = ctx->r9 & 0XFFEF;
    // 0x8002C080: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x8002C084: ori         $t4, $t3, 0x800
    ctx->r12 = ctx->r11 | 0X800;
    // 0x8002C088: beq         $v0, $at, L_8002C0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8002C08C: sh          $t4, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r12;
            goto L_8002C0A4;
    }
    // 0x8002C08C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x8002C090: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002C094: beq         $v0, $at, L_8002C0A4
    if (ctx->r2 == ctx->r1) {
        // 0x8002C098: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8002C0A4;
    }
    // 0x8002C098: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002C09C: bne         $v0, $at, L_8002C0B0
    if (ctx->r2 != ctx->r1) {
        // 0x8002C0A0: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8002C0B0;
    }
    // 0x8002C0A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8002C0A4:
    // 0x8002C0A4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C0A8: b           L_8002C0B8
    // 0x8002C0AC: sb          $zero, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = 0;
        goto L_8002C0B8;
    // 0x8002C0AC: sb          $zero, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = 0;
L_8002C0B0:
    // 0x8002C0B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C0B4: sb          $t5, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = ctx->r13;
L_8002C0B8:
    // 0x8002C0B8: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
    // 0x8002C0BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C0C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002C0C4: jal         0x800268D4
    // 0x8002C0C8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_17;
    // 0x8002C0C8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_17:
    // 0x8002C0CC: b           L_8002C174
    // 0x8002C0D0: nop

        goto L_8002C174;
    // 0x8002C0D0: nop

L_8002C0D4:
    // 0x8002C0D4: addiu       $t7, $v0, -0x4
    ctx->r15 = ADD32(ctx->r2, -0X4);
    // 0x8002C0D8: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x8002C0DC: beq         $at, $zero, L_8002C174
    if (ctx->r1 == 0) {
        // 0x8002C0E0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8002C174;
    }
    // 0x8002C0E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002C0E4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002C0E8: addu        $at, $at, $t7
    gpr jr_addend_8002C0F0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8002C0EC: lw          $t7, 0x1814($at)
    ctx->r15 = ADD32(ctx->r1, 0X1814);
    // 0x8002C0F0: jr          $t7
    // 0x8002C0F4: nop

    switch (jr_addend_8002C0F0 >> 2) {
        case 0: goto L_8002C120; break;
        case 1: goto L_8002C120; break;
        case 2: goto L_8002C120; break;
        case 3: goto L_8002C120; break;
        case 4: goto L_8002C174; break;
        case 5: goto L_8002C174; break;
        case 6: goto L_8002C174; break;
        case 7: goto L_8002C174; break;
        case 8: goto L_8002C174; break;
        case 9: goto L_8002C120; break;
        case 10: goto L_8002C120; break;
        case 11: goto L_8002C120; break;
        case 12: goto L_8002C174; break;
        case 13: goto L_8002C0F8; break;
        case 14: goto L_8002C120; break;
        case 15: goto L_8002C174; break;
        case 16: goto L_8002C174; break;
        case 17: goto L_8002C120; break;
        case 18: goto L_8002C120; break;
        case 19: goto L_8002C120; break;
        default: switch_error(__func__, 0x8002C0F0, 0x80071814);
    }
    // 0x8002C0F4: nop

L_8002C0F8:
    // 0x8002C0F8: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C0FC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C100: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8002C104: ori         $t1, $t8, 0x10
    ctx->r9 = ctx->r24 | 0X10;
    // 0x8002C108: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8002C10C: ori         $t2, $t1, 0x800
    ctx->r10 = ctx->r9 | 0X800;
    // 0x8002C110: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8002C114: sb          $zero, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = 0;
    // 0x8002C118: b           L_8002C174
    // 0x8002C11C: sb          $t3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r11;
        goto L_8002C174;
    // 0x8002C11C: sb          $t3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r11;
L_8002C120:
    // 0x8002C120: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C124: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002C128: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8002C12C: andi        $t6, $t4, 0xFFEF
    ctx->r14 = ctx->r12 & 0XFFEF;
    // 0x8002C130: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8002C134: ori         $t7, $t6, 0x800
    ctx->r15 = ctx->r14 | 0X800;
    // 0x8002C138: beq         $v0, $at, L_8002C15C
    if (ctx->r2 == ctx->r1) {
        // 0x8002C13C: sh          $t7, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r15;
            goto L_8002C15C;
    }
    // 0x8002C13C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8002C140: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002C144: beq         $v0, $at, L_8002C15C
    if (ctx->r2 == ctx->r1) {
        // 0x8002C148: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8002C15C;
    }
    // 0x8002C148: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002C14C: beq         $v0, $at, L_8002C15C
    if (ctx->r2 == ctx->r1) {
        // 0x8002C150: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8002C15C;
    }
    // 0x8002C150: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002C154: bne         $v0, $at, L_8002C168
    if (ctx->r2 != ctx->r1) {
        // 0x8002C158: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8002C168;
    }
    // 0x8002C158: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8002C15C:
    // 0x8002C15C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C160: b           L_8002C170
    // 0x8002C164: sb          $zero, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = 0;
        goto L_8002C170;
    // 0x8002C164: sb          $zero, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = 0;
L_8002C168:
    // 0x8002C168: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C16C: sb          $t8, -0x2D8($at)
    MEM_B(-0X2D8, ctx->r1) = ctx->r24;
L_8002C170:
    // 0x8002C170: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
L_8002C174:
    // 0x8002C174: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C178: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002C17C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C180: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C184: andi        $t1, $v0, 0x800
    ctx->r9 = ctx->r2 & 0X800;
    // 0x8002C188: beq         $t1, $zero, L_8002C808
    if (ctx->r9 == 0) {
        // 0x8002C18C: andi        $t2, $v0, 0x10
        ctx->r10 = ctx->r2 & 0X10;
            goto L_8002C808;
    }
    // 0x8002C18C: andi        $t2, $v0, 0x10
    ctx->r10 = ctx->r2 & 0X10;
    // 0x8002C190: beq         $t2, $zero, L_8002C1C4
    if (ctx->r10 == 0) {
        // 0x8002C194: lui         $v0, 0x8007
        ctx->r2 = S32(0X8007 << 16);
            goto L_8002C1C4;
    }
    // 0x8002C194: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8002C198: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8002C19C: addiu       $v0, $v0, -0x5624
    ctx->r2 = ADD32(ctx->r2, -0X5624);
    // 0x8002C1A0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8002C1A4: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8002C1A8: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8002C1AC: lh          $t6, 0x6($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6);
    // 0x8002C1B0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8002C1B4: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8002C1B8: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8002C1BC: b           L_8002C1E8
    // 0x8002C1C0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
        goto L_8002C1E8;
    // 0x8002C1C0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_8002C1C4:
    // 0x8002C1C4: addiu       $v0, $v0, -0x5624
    ctx->r2 = ADD32(ctx->r2, -0X5624);
    // 0x8002C1C8: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8002C1CC: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x8002C1D0: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x8002C1D4: lh          $t1, 0x16($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X16);
    // 0x8002C1D8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8002C1DC: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8002C1E0: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8002C1E4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
L_8002C1E8:
    // 0x8002C1E8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002C1EC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002C1F0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C1F4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C1F8: jal         0x80029B58
    // 0x8002C1FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_80029B58(rdram, ctx);
        goto after_18;
    // 0x8002C1FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_18:
    // 0x8002C200: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8002C204: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002C208: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002C20C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8002C210: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x8002C214: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002C218: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002C21C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002C220: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C224: jal         0x80029B58
    // 0x8002C228: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    func_80029B58(rdram, ctx);
        goto after_19;
    // 0x8002C228: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    after_19:
    // 0x8002C22C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8002C230: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C234: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C238: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8002C23C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8002C240: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x8002C244: addiu       $t9, $t8, -0x5
    ctx->r25 = ADD32(ctx->r24, -0X5);
    // 0x8002C248: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002C24C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002C250: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002C254: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002C258: jal         0x80029B58
    // 0x8002C25C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80029B58(rdram, ctx);
        goto after_20;
    // 0x8002C25C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_20:
    // 0x8002C260: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002C264: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C268: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C26C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8002C270: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002C274: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8002C278: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8002C27C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002C280: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C284: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002C288: jal         0x80029B58
    // 0x8002C28C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_80029B58(rdram, ctx);
        goto after_21;
    // 0x8002C28C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_21:
    // 0x8002C290: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002C294: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8002C298: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002C29C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002C2A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002C2A4: jal         0x80029B58
    // 0x8002C2A8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_80029B58(rdram, ctx);
        goto after_22;
    // 0x8002C2A8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_22:
    // 0x8002C2AC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8002C2B0: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002C2B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002C2B8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C2BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002C2C0: jal         0x80029B58
    // 0x8002C2C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_80029B58(rdram, ctx);
        goto after_23;
    // 0x8002C2C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_23:
    // 0x8002C2C8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8002C2CC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x8002C2D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C2D4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C2D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002C2DC: jal         0x80029B58
    // 0x8002C2E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_80029B58(rdram, ctx);
        goto after_24;
    // 0x8002C2E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_24:
    // 0x8002C2E4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002C2E8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C2EC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C2F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8002C2F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002C2F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002C2FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002C300: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002C304: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002C308: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002C30C: jal         0x80029B58
    // 0x8002C310: addiu       $a3, $a3, -0x3
    ctx->r7 = ADD32(ctx->r7, -0X3);
    func_80029B58(rdram, ctx);
        goto after_25;
    // 0x8002C310: addiu       $a3, $a3, -0x3
    ctx->r7 = ADD32(ctx->r7, -0X3);
    after_25:
    // 0x8002C314: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002C318: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8002C31C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002C320: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x8002C324: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002C328: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002C32C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002C330: jal         0x80029B58
    // 0x8002C334: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    func_80029B58(rdram, ctx);
        goto after_26;
    // 0x8002C334: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_26:
    // 0x8002C338: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8002C33C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C340: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002C344: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002C348: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002C34C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002C350: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8002C354: jal         0x80029B58
    // 0x8002C358: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    func_80029B58(rdram, ctx);
        goto after_27;
    // 0x8002C358: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    after_27:
    // 0x8002C35C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8002C360: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C364: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002C368: addiu       $t1, $t9, -0x3
    ctx->r9 = ADD32(ctx->r25, -0X3);
    // 0x8002C36C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C370: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8002C374: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002C378: jal         0x80029B58
    // 0x8002C37C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    func_80029B58(rdram, ctx);
        goto after_28;
    // 0x8002C37C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    after_28:
    // 0x8002C380: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C384: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002C388: lhu         $t2, 0x0($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C38C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002C390: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8002C394: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x8002C398: beq         $t3, $zero, L_8002C3DC
    if (ctx->r11 == 0) {
        // 0x8002C39C: addiu       $a0, $a0, 0x6
        ctx->r4 = ADD32(ctx->r4, 0X6);
            goto L_8002C3DC;
    }
    // 0x8002C39C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x8002C3A0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8002C3A4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8002C3A8: lw          $a2, -0x56E8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X56E8);
    // 0x8002C3AC: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x8002C3B0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002C3B4: jal         0x80030EA0
    // 0x8002C3B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80030EA0(rdram, ctx);
        goto after_29;
    // 0x8002C3B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_29:
    // 0x8002C3BC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002C3C0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8002C3C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002C3C8: lw          $a2, -0x56EC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X56EC);
    // 0x8002C3CC: jal         0x80030EA0
    // 0x8002C3D0: addiu       $a1, $a1, 0x13
    ctx->r5 = ADD32(ctx->r5, 0X13);
    func_80030EA0(rdram, ctx);
        goto after_30;
    // 0x8002C3D0: addiu       $a1, $a1, 0x13
    ctx->r5 = ADD32(ctx->r5, 0X13);
    after_30:
    // 0x8002C3D4: b           L_8002C404
    // 0x8002C3D8: nop

        goto L_8002C404;
    // 0x8002C3D8: nop

L_8002C3DC:
    // 0x8002C3DC: lw          $a2, -0x56E4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X56E4);
    // 0x8002C3E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8002C3E4: jal         0x80030EA0
    // 0x8002C3E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80030EA0(rdram, ctx);
        goto after_31;
    // 0x8002C3E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_31:
    // 0x8002C3EC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8002C3F0: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8002C3F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002C3F8: lw          $a2, -0x56E0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X56E0);
    // 0x8002C3FC: jal         0x80030EA0
    // 0x8002C400: addiu       $a1, $a1, 0x13
    ctx->r5 = ADD32(ctx->r5, 0X13);
    func_80030EA0(rdram, ctx);
        goto after_32;
    // 0x8002C400: addiu       $a1, $a1, 0x13
    ctx->r5 = ADD32(ctx->r5, 0X13);
    after_32:
L_8002C404:
    // 0x8002C404: jal         0x8002DF6C
    // 0x8002C408: nop

    func_8002DF6C(rdram, ctx);
        goto after_33;
    // 0x8002C408: nop

    after_33:
    // 0x8002C40C: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8002C410: lb          $t4, -0x2D7($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X2D7);
    // 0x8002C414: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C418: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002C41C: bgez        $t4, L_8002C808
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002C420: lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
            goto L_8002C808;
    }
    // 0x8002C420: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002C424: lb          $v0, 0x2872($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2872);
    // 0x8002C428: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x8002C42C: bne         $at, $zero, L_8002C43C
    if (ctx->r1 != 0) {
        // 0x8002C430: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_8002C43C;
    }
    // 0x8002C430: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8002C434: bnel        $at, $zero, L_8002C480
    if (ctx->r1 != 0) {
        // 0x8002C438: lhu         $t9, 0x0($v1)
        ctx->r25 = MEM_HU(ctx->r3, 0X0);
            goto L_8002C480;
    }
    goto skip_0;
    // 0x8002C438: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    skip_0:
L_8002C43C:
    // 0x8002C43C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C440: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x8002C444: addiu       $a3, $a3, -0x2D8
    ctx->r7 = ADD32(ctx->r7, -0X2D8);
    // 0x8002C448: andi        $t5, $v0, 0x8
    ctx->r13 = ctx->r2 & 0X8;
    // 0x8002C44C: bne         $t5, $zero, L_8002C488
    if (ctx->r13 != 0) {
        // 0x8002C450: ori         $t8, $v0, 0x8
        ctx->r24 = ctx->r2 | 0X8;
            goto L_8002C488;
    }
    // 0x8002C450: ori         $t8, $v0, 0x8
    ctx->r24 = ctx->r2 | 0X8;
    // 0x8002C454: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x8002C458: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8002C45C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C460: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8002C464: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
    // 0x8002C468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C46C: jal         0x800268D4
    // 0x8002C470: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_34;
    // 0x8002C470: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_34:
    // 0x8002C474: b           L_8002C488
    // 0x8002C478: nop

        goto L_8002C488;
    // 0x8002C478: nop

    // 0x8002C47C: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
L_8002C480:
    // 0x8002C480: andi        $t1, $t9, 0xFFF7
    ctx->r9 = ctx->r25 & 0XFFF7;
    // 0x8002C484: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
L_8002C488:
    // 0x8002C488: jal         0x8002DF6C
    // 0x8002C48C: nop

    func_8002DF6C(rdram, ctx);
        goto after_35;
    // 0x8002C48C: nop

    after_35:
    // 0x8002C490: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C494: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002C498: lhu         $t2, 0x0($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C49C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002C4A0: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002C4A4: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x8002C4A8: beq         $t3, $zero, L_8002C4F0
    if (ctx->r11 == 0) {
        // 0x8002C4AC: lui         $t1, 0x8007
        ctx->r9 = S32(0X8007 << 16);
            goto L_8002C4F0;
    }
    // 0x8002C4AC: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8002C4B0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8002C4B4: lbu         $t4, -0x2D8($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2D8);
    // 0x8002C4B8: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x8002C4BC: addiu       $t6, $t6, -0x555C
    ctx->r14 = ADD32(ctx->r14, -0X555C);
    // 0x8002C4C0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8002C4C4: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8002C4C8: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8002C4CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002C4D0: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x8002C4D4: lh          $a2, 0xA($v0)
    ctx->r6 = MEM_H(ctx->r2, 0XA);
    // 0x8002C4D8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002C4DC: jal         0x80029B58
    // 0x8002C4E0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80029B58(rdram, ctx);
        goto after_36;
    // 0x8002C4E0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_36:
    // 0x8002C4E4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C4E8: b           L_8002C520
    // 0x8002C4EC: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
        goto L_8002C520;
    // 0x8002C4EC: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
L_8002C4F0:
    // 0x8002C4F0: lbu         $t8, -0x2D8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2D8);
    // 0x8002C4F4: addiu       $t1, $t1, -0x555C
    ctx->r9 = ADD32(ctx->r9, -0X555C);
    // 0x8002C4F8: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8002C4FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002C500: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8002C504: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8002C508: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8002C50C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002C510: jal         0x80029B58
    // 0x8002C514: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80029B58(rdram, ctx);
        goto after_37;
    // 0x8002C514: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_37:
    // 0x8002C518: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C51C: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
L_8002C520:
    // 0x8002C520: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8002C524: lhu         $a0, 0x2876($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2876);
    // 0x8002C528: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8002C52C: andi        $t3, $a0, 0x8000
    ctx->r11 = ctx->r4 & 0X8000;
    // 0x8002C530: beql        $t3, $zero, L_8002C7B0
    if (ctx->r11 == 0) {
        // 0x8002C534: andi        $t3, $a0, 0x4000
        ctx->r11 = ctx->r4 & 0X4000;
            goto L_8002C7B0;
    }
    goto skip_1;
    // 0x8002C534: andi        $t3, $a0, 0x4000
    ctx->r11 = ctx->r4 & 0X4000;
    skip_1:
    // 0x8002C538: lbu         $t4, -0x2D8($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2D8);
    // 0x8002C53C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8002C540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C544: bne         $t4, $zero, L_8002C6A0
    if (ctx->r12 != 0) {
        // 0x8002C548: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8002C6A0;
    }
    // 0x8002C548: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8002C54C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002C550: jal         0x800268D4
    // 0x8002C554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800268D4(rdram, ctx);
        goto after_38;
    // 0x8002C554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
    // 0x8002C558: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8002C55C: lbu         $t5, -0x2DE($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X2DE);
    // 0x8002C560: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C564: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002C568: addiu       $t6, $t5, -0x4
    ctx->r14 = ADD32(ctx->r13, -0X4);
    // 0x8002C56C: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x8002C570: beq         $at, $zero, L_8002C79C
    if (ctx->r1 == 0) {
        // 0x8002C574: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8002C79C;
    }
    // 0x8002C574: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002C578: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002C57C: addu        $at, $at, $t6
    gpr jr_addend_8002C584 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8002C580: lw          $t6, 0x1864($at)
    ctx->r14 = ADD32(ctx->r1, 0X1864);
    // 0x8002C584: jr          $t6
    // 0x8002C588: nop

    switch (jr_addend_8002C584 >> 2) {
        case 0: goto L_8002C5D4; break;
        case 1: goto L_8002C5A8; break;
        case 2: goto L_8002C604; break;
        case 3: goto L_8002C690; break;
        case 4: goto L_8002C79C; break;
        case 5: goto L_8002C79C; break;
        case 6: goto L_8002C79C; break;
        case 7: goto L_8002C79C; break;
        case 8: goto L_8002C79C; break;
        case 9: goto L_8002C680; break;
        case 10: goto L_8002C658; break;
        case 11: goto L_8002C658; break;
        case 12: goto L_8002C79C; break;
        case 13: goto L_8002C58C; break;
        case 14: goto L_8002C658; break;
        case 15: goto L_8002C79C; break;
        case 16: goto L_8002C79C; break;
        case 17: goto L_8002C634; break;
        case 18: goto L_8002C658; break;
        case 19: goto L_8002C658; break;
        default: switch_error(__func__, 0x8002C584, 0x80071864);
    }
    // 0x8002C588: nop

L_8002C58C:
    // 0x8002C58C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x8002C590: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C594: sb          $t7, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r15;
    // 0x8002C598: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C59C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8002C5A0: b           L_8002C79C
    // 0x8002C5A4: sb          $t8, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r24;
        goto L_8002C79C;
    // 0x8002C5A4: sb          $t8, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r24;
L_8002C5A8:
    // 0x8002C5A8: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C5AC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8002C5B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C5B4: andi        $t2, $t9, 0xFFF8
    ctx->r10 = ctx->r25 & 0XFFF8;
    // 0x8002C5B8: ori         $t4, $t2, 0x4
    ctx->r12 = ctx->r10 | 0X4;
    // 0x8002C5BC: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8002C5C0: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x8002C5C4: ori         $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 | 0X2000;
    // 0x8002C5C8: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8002C5CC: b           L_8002C79C
    // 0x8002C5D0: sb          $t6, -0x2DD($at)
    MEM_B(-0X2DD, ctx->r1) = ctx->r14;
        goto L_8002C79C;
    // 0x8002C5D0: sb          $t6, -0x2DD($at)
    MEM_B(-0X2DD, ctx->r1) = ctx->r14;
L_8002C5D4:
    // 0x8002C5D4: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C5D8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8002C5DC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C5E0: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x8002C5E4: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8002C5E8: sb          $t9, -0x2DD($at)
    MEM_B(-0X2DD, ctx->r1) = ctx->r25;
    // 0x8002C5EC: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C5F0: andi        $t3, $t1, 0xFFF8
    ctx->r11 = ctx->r9 & 0XFFF8;
    // 0x8002C5F4: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x8002C5F8: ori         $t4, $t3, 0x3
    ctx->r12 = ctx->r11 | 0X3;
    // 0x8002C5FC: b           L_8002C79C
    // 0x8002C600: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
        goto L_8002C79C;
    // 0x8002C600: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8002C604:
    // 0x8002C604: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C608: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8002C60C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C610: ori         $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 | 0X2000;
    // 0x8002C614: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8002C618: sb          $t7, -0x2DD($at)
    MEM_B(-0X2DD, ctx->r1) = ctx->r15;
    // 0x8002C61C: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C620: andi        $t1, $t8, 0xFFF8
    ctx->r9 = ctx->r24 & 0XFFF8;
    // 0x8002C624: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8002C628: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8002C62C: b           L_8002C79C
    // 0x8002C630: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
        goto L_8002C79C;
    // 0x8002C630: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
L_8002C634:
    // 0x8002C634: jal         0x8002DD18
    // 0x8002C638: nop

    func_8002DD18(rdram, ctx);
        goto after_39;
    // 0x8002C638: nop

    after_39:
    // 0x8002C63C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C640: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002C644: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C648: andi        $t5, $t3, 0xFFF8
    ctx->r13 = ctx->r11 & 0XFFF8;
    // 0x8002C64C: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8002C650: b           L_8002C79C
    // 0x8002C654: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
        goto L_8002C79C;
    // 0x8002C654: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
L_8002C658:
    // 0x8002C658: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C65C: andi        $t8, $t6, 0xDFFF
    ctx->r24 = ctx->r14 & 0XDFFF;
    // 0x8002C660: andi        $t1, $t8, 0xFFF8
    ctx->r9 = ctx->r24 & 0XFFF8;
    // 0x8002C664: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8002C668: andi        $t3, $t1, 0xBFFF
    ctx->r11 = ctx->r9 & 0XBFFF;
    // 0x8002C66C: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8002C670: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x8002C674: ori         $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 | 0X1000;
    // 0x8002C678: b           L_8002C79C
    // 0x8002C67C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
        goto L_8002C79C;
    // 0x8002C67C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8002C680:
    // 0x8002C680: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C684: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x8002C688: b           L_8002C79C
    // 0x8002C68C: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
        goto L_8002C79C;
    // 0x8002C68C: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_8002C690:
    // 0x8002C690: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C694: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x8002C698: b           L_8002C79C
    // 0x8002C69C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
        goto L_8002C79C;
    // 0x8002C69C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_8002C6A0:
    // 0x8002C6A0: jal         0x800268D4
    // 0x8002C6A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_40;
    // 0x8002C6A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_40:
    // 0x8002C6A8: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x8002C6AC: lbu         $t9, -0x2DE($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2DE);
    // 0x8002C6B0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8002C6B4: addiu       $v1, $v1, -0x2E0
    ctx->r3 = ADD32(ctx->r3, -0X2E0);
    // 0x8002C6B8: addiu       $t1, $t9, -0x4
    ctx->r9 = ADD32(ctx->r25, -0X4);
    // 0x8002C6BC: sltiu       $at, $t1, 0x14
    ctx->r1 = ctx->r9 < 0X14 ? 1 : 0;
    // 0x8002C6C0: beq         $at, $zero, L_8002C79C
    if (ctx->r1 == 0) {
        // 0x8002C6C4: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8002C79C;
    }
    // 0x8002C6C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8002C6C8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002C6CC: addu        $at, $at, $t1
    gpr jr_addend_8002C6D4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8002C6D0: lw          $t1, 0x18B4($at)
    ctx->r9 = ADD32(ctx->r1, 0X18B4);
    // 0x8002C6D4: jr          $t1
    // 0x8002C6D8: nop

    switch (jr_addend_8002C6D4 >> 2) {
        case 0: goto L_8002C740; break;
        case 1: goto L_8002C740; break;
        case 2: goto L_8002C774; break;
        case 3: goto L_8002C740; break;
        case 4: goto L_8002C79C; break;
        case 5: goto L_8002C79C; break;
        case 6: goto L_8002C79C; break;
        case 7: goto L_8002C79C; break;
        case 8: goto L_8002C79C; break;
        case 9: goto L_8002C6FC; break;
        case 10: goto L_8002C724; break;
        case 11: goto L_8002C6EC; break;
        case 12: goto L_8002C79C; break;
        case 13: goto L_8002C6DC; break;
        case 14: goto L_8002C6EC; break;
        case 15: goto L_8002C79C; break;
        case 16: goto L_8002C79C; break;
        case 17: goto L_8002C724; break;
        case 18: goto L_8002C6EC; break;
        case 19: goto L_8002C6EC; break;
        default: switch_error(__func__, 0x8002C6D4, 0x800718B4);
    }
    // 0x8002C6D8: nop

L_8002C6DC:
    // 0x8002C6DC: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8002C6E0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C6E4: b           L_8002C79C
    // 0x8002C6E8: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
        goto L_8002C79C;
    // 0x8002C6E8: sb          $t2, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r10;
L_8002C6EC:
    // 0x8002C6EC: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C6F0: ori         $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 | 0X8000;
    // 0x8002C6F4: b           L_8002C79C
    // 0x8002C6F8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
        goto L_8002C79C;
    // 0x8002C6F8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8002C6FC:
    // 0x8002C6FC: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C700: andi        $t7, $t5, 0xDFFF
    ctx->r15 = ctx->r13 & 0XDFFF;
    // 0x8002C704: andi        $t9, $t7, 0xFFF8
    ctx->r25 = ctx->r15 & 0XFFF8;
    // 0x8002C708: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8002C70C: andi        $t2, $t9, 0xBFFF
    ctx->r10 = ctx->r25 & 0XBFFF;
    // 0x8002C710: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x8002C714: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8002C718: ori         $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 | 0X1000;
    // 0x8002C71C: b           L_8002C79C
    // 0x8002C720: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
        goto L_8002C79C;
    // 0x8002C720: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_8002C724:
    // 0x8002C724: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8002C728: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C72C: sb          $t4, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r12;
    // 0x8002C730: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C734: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8002C738: b           L_8002C79C
    // 0x8002C73C: sb          $t5, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r13;
        goto L_8002C79C;
    // 0x8002C73C: sb          $t5, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r13;
L_8002C740:
    // 0x8002C740: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C744: andi        $t7, $t6, 0xFFF8
    ctx->r15 = ctx->r14 & 0XFFF8;
    // 0x8002C748: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x8002C74C: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x8002C750: beq         $t8, $zero, L_8002C76C
    if (ctx->r24 == 0) {
        // 0x8002C754: sh          $t7, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r15;
            goto L_8002C76C;
    }
    // 0x8002C754: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8002C758: andi        $t1, $v0, 0xBFFF
    ctx->r9 = ctx->r2 & 0XBFFF;
    // 0x8002C75C: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8002C760: ori         $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 | 0X2000;
    // 0x8002C764: b           L_8002C79C
    // 0x8002C768: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
        goto L_8002C79C;
    // 0x8002C768: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
L_8002C76C:
    // 0x8002C76C: b           L_8002C79C
    // 0x8002C770: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_8002C79C;
    // 0x8002C770: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8002C774:
    // 0x8002C774: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C778: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8002C77C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C780: andi        $t5, $t3, 0xDFFF
    ctx->r13 = ctx->r11 & 0XDFFF;
    // 0x8002C784: andi        $t7, $t5, 0xFFF8
    ctx->r15 = ctx->r13 & 0XFFF8;
    // 0x8002C788: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x8002C78C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8002C790: ori         $t8, $t7, 0x1005
    ctx->r24 = ctx->r15 | 0X1005;
    // 0x8002C794: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x8002C798: sb          $t9, -0x2DE($at)
    MEM_B(-0X2DE, ctx->r1) = ctx->r25;
L_8002C79C:
    // 0x8002C79C: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C7A0: andi        $t2, $t1, 0xF7FF
    ctx->r10 = ctx->r9 & 0XF7FF;
    // 0x8002C7A4: b           L_8002C808
    // 0x8002C7A8: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
        goto L_8002C808;
    // 0x8002C7A8: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8002C7AC: andi        $t3, $a0, 0x4000
    ctx->r11 = ctx->r4 & 0X4000;
L_8002C7B0:
    // 0x8002C7B0: beq         $t3, $zero, L_8002C808
    if (ctx->r11 == 0) {
        // 0x8002C7B4: lui         $t4, 0x8009
        ctx->r12 = S32(0X8009 << 16);
            goto L_8002C808;
    }
    // 0x8002C7B4: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x8002C7B8: lbu         $t4, -0x2DE($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2DE);
    // 0x8002C7BC: addiu       $t5, $t4, -0x6
    ctx->r13 = ADD32(ctx->r12, -0X6);
    // 0x8002C7C0: sltiu       $at, $t5, 0x12
    ctx->r1 = ctx->r13 < 0X12 ? 1 : 0;
    // 0x8002C7C4: beq         $at, $zero, L_8002C7E0
    if (ctx->r1 == 0) {
        // 0x8002C7C8: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8002C7E0;
    }
    // 0x8002C7C8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8002C7CC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8002C7D0: addu        $at, $at, $t5
    gpr jr_addend_8002C7D8 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8002C7D4: lw          $t5, 0x1904($at)
    ctx->r13 = ADD32(ctx->r1, 0X1904);
    // 0x8002C7D8: jr          $t5
    // 0x8002C7DC: nop

    switch (jr_addend_8002C7D8 >> 2) {
        case 0: goto L_8002C808; break;
        case 1: goto L_8002C808; break;
        case 2: goto L_8002C7E0; break;
        case 3: goto L_8002C7E0; break;
        case 4: goto L_8002C7E0; break;
        case 5: goto L_8002C7E0; break;
        case 6: goto L_8002C7E0; break;
        case 7: goto L_8002C808; break;
        case 8: goto L_8002C808; break;
        case 9: goto L_8002C808; break;
        case 10: goto L_8002C7E0; break;
        case 11: goto L_8002C808; break;
        case 12: goto L_8002C808; break;
        case 13: goto L_8002C7E0; break;
        case 14: goto L_8002C7E0; break;
        case 15: goto L_8002C808; break;
        case 16: goto L_8002C808; break;
        case 17: goto L_8002C808; break;
        default: switch_error(__func__, 0x8002C7D8, 0x80071904);
    }
    // 0x8002C7DC: nop

L_8002C7E0:
    // 0x8002C7E0: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C7E4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8002C7E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8002C7EC: andi        $t7, $t6, 0xF7FF
    ctx->r15 = ctx->r14 & 0XF7FF;
    // 0x8002C7F0: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8002C7F4: sb          $t8, -0x2D7($at)
    MEM_B(-0X2D7, ctx->r1) = ctx->r24;
    // 0x8002C7F8: lhu         $t9, 0x0($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C7FC: andi        $t2, $t9, 0xFFF8
    ctx->r10 = ctx->r25 & 0XFFF8;
    // 0x8002C800: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x8002C804: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
L_8002C808:
    // 0x8002C808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C80C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8002C810: jr          $ra
    // 0x8002C814: nop

    return;
    // 0x8002C814: nop

;}
RECOMP_FUNC void func_80049C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049C80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80049C84: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80049C88: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x80049C8C: sh          $zero, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = 0;
    // 0x80049C90: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80049C94: jal         0x80049BF8
    // 0x80049C98: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    func_80049BF8(rdram, ctx);
        goto after_0;
    // 0x80049C98: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    after_0:
    // 0x80049C9C: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x80049CA0: ori         $at, $at, 0x6864
    ctx->r1 = ctx->r1 | 0X6864;
    // 0x80049CA4: bnel        $v0, $at, L_80049D44
    if (ctx->r2 != ctx->r1) {
        // 0x80049CA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049D44;
    }
    goto skip_0;
    // 0x80049CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80049CAC: jal         0x80049BF8
    // 0x80049CB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80049BF8(rdram, ctx);
        goto after_1;
    // 0x80049CB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80049CB4: jal         0x80049C48
    // 0x80049CB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80049C48(rdram, ctx);
        goto after_2;
    // 0x80049CB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80049CBC: bnel        $v0, $zero, L_80049D44
    if (ctx->r2 != 0) {
        // 0x80049CC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049D44;
    }
    goto skip_1;
    // 0x80049CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80049CC4: jal         0x80049C48
    // 0x80049CC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80049C48(rdram, ctx);
        goto after_3;
    // 0x80049CC8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x80049CCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80049CD0: bnel        $v0, $at, L_80049D44
    if (ctx->r2 != ctx->r1) {
        // 0x80049CD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049D44;
    }
    goto skip_2;
    // 0x80049CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80049CD8: jal         0x80049C48
    // 0x80049CDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80049C48(rdram, ctx);
        goto after_4;
    // 0x80049CDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x80049CE0: sh          $v0, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r2;
    // 0x80049CE4: lh          $v1, 0x18($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X18);
    // 0x80049CE8: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x80049CEC: bnel        $t6, $zero, L_80049D44
    if (ctx->r14 != 0) {
        // 0x80049CF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049D44;
    }
    goto skip_3;
    // 0x80049CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80049CF4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80049CF8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80049CFC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80049D00: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80049D04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80049D08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80049D0C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80049D10: div.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80049D14: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80049D18: jal         0x80049BF8
    // 0x80049D1C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    func_80049BF8(rdram, ctx);
        goto after_5;
    // 0x80049D1C: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    after_5:
    // 0x80049D20: lui         $at, 0x4D54
    ctx->r1 = S32(0X4D54 << 16);
    // 0x80049D24: ori         $at, $at, 0x726B
    ctx->r1 = ctx->r1 | 0X726B;
    // 0x80049D28: bnel        $v0, $at, L_80049D44
    if (ctx->r2 != ctx->r1) {
        // 0x80049D2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049D44;
    }
    goto skip_4;
    // 0x80049D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80049D30: jal         0x80049BF8
    // 0x80049D34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80049BF8(rdram, ctx);
        goto after_6;
    // 0x80049D34: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80049D38: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x80049D3C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80049D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049D44:
    // 0x80049D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049D48: jr          $ra
    // 0x80049D4C: nop

    return;
    // 0x80049D4C: nop

;}
RECOMP_FUNC void func_800100D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800100D0: addiu       $t6, $zero, 0x1EC3
    ctx->r14 = ADD32(0, 0X1EC3);
    // 0x800100D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800100D8: sw          $t6, 0x59D0($at)
    MEM_W(0X59D0, ctx->r1) = ctx->r14;
    // 0x800100DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800100E0: addiu       $t7, $zero, 0x6978
    ctx->r15 = ADD32(0, 0X6978);
    // 0x800100E4: sw          $t7, 0x59D4($at)
    MEM_W(0X59D4, ctx->r1) = ctx->r15;
    // 0x800100E8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800100EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800100F0: sh          $t8, 0x59E0($at)
    MEM_H(0X59E0, ctx->r1) = ctx->r24;
    // 0x800100F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800100F8: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800100FC: sw          $t9, -0x39CC($at)
    MEM_W(-0X39CC, ctx->r1) = ctx->r25;
    // 0x80010100: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010104: sw          $zero, 0x5B68($at)
    MEM_W(0X5B68, ctx->r1) = 0;
    // 0x80010108: sw          $zero, 0x5B6C($at)
    MEM_W(0X5B6C, ctx->r1) = 0;
    // 0x8001010C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010110: sw          $zero, 0x5B74($at)
    MEM_W(0X5B74, ctx->r1) = 0;
    // 0x80010114: sw          $zero, 0x5B70($at)
    MEM_W(0X5B70, ctx->r1) = 0;
    // 0x80010118: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001011C: sw          $zero, 0x5B78($at)
    MEM_W(0X5B78, ctx->r1) = 0;
    // 0x80010120: sw          $zero, 0x5B7C($at)
    MEM_W(0X5B7C, ctx->r1) = 0;
    // 0x80010124: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010128: sw          $zero, 0x5B80($at)
    MEM_W(0X5B80, ctx->r1) = 0;
    // 0x8001012C: sw          $zero, 0x5B84($at)
    MEM_W(0X5B84, ctx->r1) = 0;
    // 0x80010130: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010134: sw          $zero, 0x5B88($at)
    MEM_W(0X5B88, ctx->r1) = 0;
    // 0x80010138: sw          $zero, 0x5B8C($at)
    MEM_W(0X5B8C, ctx->r1) = 0;
    // 0x8001013C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80010140: sw          $zero, 0x5B90($at)
    MEM_W(0X5B90, ctx->r1) = 0;
    // 0x80010144: sw          $zero, 0x5B94($at)
    MEM_W(0X5B94, ctx->r1) = 0;
    // 0x80010148: jr          $ra
    // 0x8001014C: nop

    return;
    // 0x8001014C: nop

;}
RECOMP_FUNC void func_80013D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013D30: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80013D34: jr          $ra
    // 0x80013D38: nop

    return;
    // 0x80013D38: nop

;}
RECOMP_FUNC void func_80036360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036368: jal         0x8003FB20
    // 0x8003636C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8003636C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80036370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036374: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80036378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003637C: jr          $ra
    // 0x80036380: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x80036380: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
;}
RECOMP_FUNC void func_800170DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800170DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800170E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800170E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800170E8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800170EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800170F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800170F4: lw          $v0, 0x68($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X68);
    // 0x800170F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800170FC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80017100: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80017104: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x80017108: beq         $a0, $at, L_80017124
    if (ctx->r4 == ctx->r1) {
        // 0x8001710C: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_80017124;
    }
    // 0x8001710C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80017110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80017114: beq         $a0, $at, L_80017138
    if (ctx->r4 == ctx->r1) {
        // 0x80017118: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_80017138;
    }
    // 0x80017118: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001711C: b           L_80017144
    // 0x80017120: nop

        goto L_80017144;
    // 0x80017120: nop

L_80017124:
    // 0x80017124: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80017128: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x8001712C: lw          $t1, 0x68($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X68);
    // 0x80017130: b           L_80017144
    // 0x80017134: sh          $t9, 0x8A($t1)
    MEM_H(0X8A, ctx->r9) = ctx->r25;
        goto L_80017144;
    // 0x80017134: sh          $t9, 0x8A($t1)
    MEM_H(0X8A, ctx->r9) = ctx->r25;
L_80017138:
    // 0x80017138: lw          $t4, 0x68($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X68);
    // 0x8001713C: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80017140: sh          $t2, 0x8A($t4)
    MEM_H(0X8A, ctx->r12) = ctx->r10;
L_80017144:
    // 0x80017144: jal         0x8001FCF8
    // 0x80017148: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x80017148: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x8001714C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017154: jr          $ra
    // 0x80017158: nop

    return;
    // 0x80017158: nop

;}
RECOMP_FUNC void func_800253F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800253F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800253F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800253F8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800253FC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80025400: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80025404: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80025408: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8002540C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80025410: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80025414: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80025418: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8002541C: addiu       $t8, $t8, -0x688
    ctx->r24 = ADD32(ctx->r24, -0X688);
    // 0x80025420: addiu       $t7, $t6, 0x1C
    ctx->r15 = ADD32(ctx->r14, 0X1C);
    // 0x80025424: jal         0x800390C0
    // 0x80025428: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    func_800390C0(rdram, ctx);
        goto after_0;
    // 0x80025428: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_0:
    // 0x8002542C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025434: jr          $ra
    // 0x80025438: nop

    return;
    // 0x80025438: nop

;}
RECOMP_FUNC void func_8000ACC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ACC0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000ACC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000ACC8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8000ACCC: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x8000ACD0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8000ACD4: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x8000ACD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000ACDC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8000ACE0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8000ACE4: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8000ACE8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8000ACEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000ACF0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8000ACF4: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000ACF8: addiu       $t8, $t8, -0x3668
    ctx->r24 = ADD32(ctx->r24, -0X3668);
    // 0x8000ACFC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000AD00: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8000AD04: lh          $t0, 0x74($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X74);
    // 0x8000AD08: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x8000AD0C: lw          $t9, -0x2F58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2F58);
    // 0x8000AD10: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000AD14: lhu         $t4, 0xA($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0XA);
    // 0x8000AD18: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000AD1C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8000AD20: beq         $t4, $zero, L_8000B0DC
    if (ctx->r12 == 0) {
        // 0x8000AD24: sw          $t3, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r11;
            goto L_8000B0DC;
    }
    // 0x8000AD24: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8000AD28: beq         $s0, $zero, L_8000AFFC
    if (ctx->r16 == 0) {
        // 0x8000AD2C: lhu         $t5, 0x5E($sp)
        ctx->r13 = MEM_HU(ctx->r29, 0X5E);
            goto L_8000AFFC;
    }
    // 0x8000AD2C: lhu         $t5, 0x5E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X5E);
    // 0x8000AD30: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8000AD34: bne         $t6, $zero, L_8000ADA4
    if (ctx->r14 != 0) {
        // 0x8000AD38: lui         $v0, 0x8005
        ctx->r2 = S32(0X8005 << 16);
            goto L_8000ADA4;
    }
    // 0x8000AD38: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8000AD3C: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x8000AD40: addiu       $v0, $v0, -0x3D58
    ctx->r2 = ADD32(ctx->r2, -0X3D58);
    // 0x8000AD44: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8000AD48: lhu         $t1, 0x26($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X26);
    // 0x8000AD4C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8000AD50: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8000AD54: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000AD58: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8000AD5C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8000AD60: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x8000AD64: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8000AD68: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8000AD6C: beq         $at, $zero, L_8000ADA4
    if (ctx->r1 == 0) {
        // 0x8000AD70: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8000ADA4;
    }
    // 0x8000AD70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000AD74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000AD78: addu        $at, $at, $t6
    gpr jr_addend_8000AD80 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000AD7C: lw          $t6, 0x1198($at)
    ctx->r14 = ADD32(ctx->r1, 0X1198);
    // 0x8000AD80: jr          $t6
    // 0x8000AD84: nop

    switch (jr_addend_8000AD80 >> 2) {
        case 0: goto L_8000AD88; break;
        case 1: goto L_8000AD88; break;
        case 2: goto L_8000ADA4; break;
        case 3: goto L_8000AD88; break;
        case 4: goto L_8000AD94; break;
        case 5: goto L_8000ADA4; break;
        case 6: goto L_8000ADA4; break;
        case 7: goto L_8000AD88; break;
        case 8: goto L_8000ADA4; break;
        case 9: goto L_8000AD94; break;
        default: switch_error(__func__, 0x8000AD80, 0x80071198);
    }
    // 0x8000AD84: nop

L_8000AD88:
    // 0x8000AD88: srl         $t7, $s0, 1
    ctx->r15 = S32(U32(ctx->r16) >> 1);
    // 0x8000AD8C: b           L_8000ADA4
    // 0x8000AD90: andi        $s0, $t7, 0xFFFF
    ctx->r16 = ctx->r15 & 0XFFFF;
        goto L_8000ADA4;
    // 0x8000AD90: andi        $s0, $t7, 0xFFFF
    ctx->r16 = ctx->r15 & 0XFFFF;
L_8000AD94:
    // 0x8000AD94: sra         $t9, $s0, 2
    ctx->r25 = S32(SIGNED(ctx->r16) >> 2);
    // 0x8000AD98: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x8000AD9C: andi        $t1, $s0, 0xFFFF
    ctx->r9 = ctx->r16 & 0XFFFF;
    // 0x8000ADA0: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
L_8000ADA4:
    // 0x8000ADA4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8000ADA8: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x8000ADAC: lw          $t3, 0x68($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X68);
    // 0x8000ADB0: lhu         $v0, 0x84($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X84);
    // 0x8000ADB4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000ADB8: bgez        $v0, L_8000ADD0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000ADBC: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8000ADD0;
    }
    // 0x8000ADBC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000ADC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000ADC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000ADC8: nop

    // 0x8000ADCC: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_8000ADD0:
    // 0x8000ADD0: lhu         $t0, 0x118($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X118);
    // 0x8000ADD4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000ADD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000ADDC: addu        $t4, $v0, $t0
    ctx->r12 = ADD32(ctx->r2, ctx->r8);
    // 0x8000ADE0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8000ADE4: nop

    // 0x8000ADE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000ADEC: bgez        $s0, L_8000AE00
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8000ADF0: div.s       $f0, $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
            goto L_8000AE00;
    }
    // 0x8000ADF0: div.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000ADF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000ADF8: nop

    // 0x8000ADFC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8000AE00:
    // 0x8000AE00: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8000AE04: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000AE08: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000AE0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8000AE10: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x8000AE14: nop

    // 0x8000AE18: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000AE1C: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x8000AE20: nop

    // 0x8000AE24: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x8000AE28: beql        $s0, $zero, L_8000AE78
    if (ctx->r16 == 0) {
        // 0x8000AE2C: mfc1        $s0, $f8
        ctx->r16 = (int32_t)ctx->f8.u32l;
            goto L_8000AE78;
    }
    goto skip_0;
    // 0x8000AE2C: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8000AE30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000AE34: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000AE38: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000AE3C: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x8000AE40: nop

    // 0x8000AE44: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000AE48: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x8000AE4C: nop

    // 0x8000AE50: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x8000AE54: bne         $s0, $zero, L_8000AE6C
    if (ctx->r16 != 0) {
        // 0x8000AE58: nop
    
            goto L_8000AE6C;
    }
    // 0x8000AE58: nop

    // 0x8000AE5C: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x8000AE60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000AE64: b           L_8000AE84
    // 0x8000AE68: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_8000AE84;
    // 0x8000AE68: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_8000AE6C:
    // 0x8000AE6C: b           L_8000AE84
    // 0x8000AE70: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_8000AE84;
    // 0x8000AE70: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8000AE74: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
L_8000AE78:
    // 0x8000AE78: nop

    // 0x8000AE7C: bltz        $s0, L_8000AE6C
    if (SIGNED(ctx->r16) < 0) {
        // 0x8000AE80: nop
    
            goto L_8000AE6C;
    }
    // 0x8000AE80: nop

L_8000AE84:
    // 0x8000AE84: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8000AE88: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8000AE8C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8000AE90: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x8000AE94: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000AE98: bgez        $t6, L_8000AEAC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000AE9C: cvt.s.w     $f12, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000AEAC;
    }
    // 0x8000AE9C: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000AEA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000AEA4: nop

    // 0x8000AEA8: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
L_8000AEAC:
    // 0x8000AEAC: jal         0x80034F60
    // 0x8000AEB0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000AEB0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8000AEB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000AEB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000AEBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000AEC0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000AEC4: add.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8000AEC8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000AECC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8000AED0: nop

    // 0x8000AED4: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000AED8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8000AEDC: nop

    // 0x8000AEE0: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8000AEE4: beql        $a0, $zero, L_8000AF34
    if (ctx->r4 == 0) {
        // 0x8000AEE8: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_8000AF34;
    }
    goto skip_1;
    // 0x8000AEE8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x8000AEEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000AEF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000AEF4: sub.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8000AEF8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8000AEFC: nop

    // 0x8000AF00: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000AF04: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8000AF08: nop

    // 0x8000AF0C: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8000AF10: bne         $a0, $zero, L_8000AF28
    if (ctx->r4 != 0) {
        // 0x8000AF14: nop
    
            goto L_8000AF28;
    }
    // 0x8000AF14: nop

    // 0x8000AF18: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8000AF1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000AF20: b           L_8000AF40
    // 0x8000AF24: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8000AF40;
    // 0x8000AF24: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_8000AF28:
    // 0x8000AF28: b           L_8000AF40
    // 0x8000AF2C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8000AF40;
    // 0x8000AF2C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8000AF30: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_8000AF34:
    // 0x8000AF34: nop

    // 0x8000AF38: bltz        $a0, L_8000AF28
    if (SIGNED(ctx->r4) < 0) {
        // 0x8000AF3C: nop
    
            goto L_8000AF28;
    }
    // 0x8000AF3C: nop

L_8000AF40:
    // 0x8000AF40: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000AF44: jal         0x80022FD0
    // 0x8000AF48: nop

    get_rand(rdram, ctx);
        goto after_1;
    // 0x8000AF48: nop

    after_1:
    // 0x8000AF4C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8000AF50: andi        $t8, $s0, 0xFFFF
    ctx->r24 = ctx->r16 & 0XFFFF;
    // 0x8000AF54: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8000AF58: bne         $t8, $zero, L_8000AF6C
    if (ctx->r24 != 0) {
        // 0x8000AF5C: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8000AF6C;
    }
    // 0x8000AF5C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8000AF60: addiu       $s0, $t8, 0x1
    ctx->r16 = ADD32(ctx->r24, 0X1);
    // 0x8000AF64: andi        $t9, $s0, 0xFFFF
    ctx->r25 = ctx->r16 & 0XFFFF;
    // 0x8000AF68: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_8000AF6C:
    // 0x8000AF6C: lhu         $v0, 0xA($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XA);
    // 0x8000AF70: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8000AF74: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AF78: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8000AF7C: beq         $at, $zero, L_8000AF8C
    if (ctx->r1 == 0) {
        // 0x8000AF80: subu        $t3, $v0, $t2
        ctx->r11 = SUB32(ctx->r2, ctx->r10);
            goto L_8000AF8C;
    }
    // 0x8000AF80: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x8000AF84: b           L_8000AF90
    // 0x8000AF88: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
        goto L_8000AF90;
    // 0x8000AF88: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
L_8000AF8C:
    // 0x8000AF8C: sh          $t3, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r11;
L_8000AF90:
    // 0x8000AF90: lhu         $t0, 0x90($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X90);
    // 0x8000AF94: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AF98: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x8000AF9C: andi        $t4, $t0, 0x200
    ctx->r12 = ctx->r8 & 0X200;
    // 0x8000AFA0: beq         $t4, $zero, L_8000AFE4
    if (ctx->r12 == 0) {
        // 0x8000AFA4: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8000AFE4;
    }
    // 0x8000AFA4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8000AFA8: lhu         $t5, 0xC($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XC);
    // 0x8000AFAC: addiu       $a0, $v1, 0x24
    ctx->r4 = ADD32(ctx->r3, 0X24);
    // 0x8000AFB0: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8000AFB4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8000AFB8: sh          $t7, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r15;
    // 0x8000AFBC: lw          $t8, 0x64($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X64);
    // 0x8000AFC0: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8000AFC4: lhu         $v0, 0xA($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0XA);
    // 0x8000AFC8: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000AFCC: beq         $at, $zero, L_8000AFD8
    if (ctx->r1 == 0) {
        // 0x8000AFD0: nop
    
            goto L_8000AFD8;
    }
    // 0x8000AFD0: nop

    // 0x8000AFD4: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
L_8000AFD8:
    // 0x8000AFD8: jal         0x8001FCF8
    // 0x8000AFDC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8001FCF8(rdram, ctx);
        goto after_2;
    // 0x8000AFDC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_2:
    // 0x8000AFE0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8000AFE4:
    // 0x8000AFE4: addiu       $a0, $v1, 0x24
    ctx->r4 = ADD32(ctx->r3, 0X24);
    // 0x8000AFE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000AFEC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AFF0: jal         0x80018DF4
    // 0x8000AFF4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80018DF4(rdram, ctx);
        goto after_3;
    // 0x8000AFF4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_3:
    // 0x8000AFF8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8000AFFC:
    // 0x8000AFFC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000B000: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x8000B004: addiu       $a0, $v1, 0x24
    ctx->r4 = ADD32(ctx->r3, 0X24);
    // 0x8000B008: lhu         $t2, 0x60($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X60);
    // 0x8000B00C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8000B010: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8000B014: sh          $t3, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r11;
    // 0x8000B018: lhu         $t0, 0x5E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X5E);
    // 0x8000B01C: ori         $t6, $t3, 0x2
    ctx->r14 = ctx->r11 | 0X2;
    // 0x8000B020: andi        $t4, $t0, 0x4
    ctx->r12 = ctx->r8 & 0X4;
    // 0x8000B024: beq         $t4, $zero, L_8000B030
    if (ctx->r12 == 0) {
        // 0x8000B028: nop
    
            goto L_8000B030;
    }
    // 0x8000B028: nop

    // 0x8000B02C: sh          $t6, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r14;
L_8000B030:
    // 0x8000B030: lhu         $t7, -0x3A6E($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X3A6E);
    // 0x8000B034: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x8000B038: beql        $t8, $zero, L_8000B090
    if (ctx->r24 == 0) {
        // 0x8000B03C: lw          $v0, 0x20($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X20);
            goto L_8000B090;
    }
    goto skip_2;
    // 0x8000B03C: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    skip_2:
    // 0x8000B040: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x8000B044: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8000B048: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000B04C: lh          $t1, 0x28($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X28);
    // 0x8000B050: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000B054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000B058: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000B05C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8000B060: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8000B064: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8000B068: lh          $t0, 0x2($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X2);
    // 0x8000B06C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000B070: sh          $t0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r8;
    // 0x8000B074: lh          $a1, 0x28($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X28);
    // 0x8000B078: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8000B07C: jal         0x8001D8B0
    // 0x8000B080: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8001D8B0(rdram, ctx);
        goto after_4;
    // 0x8000B080: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x8000B084: b           L_8000B0E0
    // 0x8000B088: lhu         $t4, 0x5E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X5E);
        goto L_8000B0E0;
    // 0x8000B088: lhu         $t4, 0x5E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X5E);
    // 0x8000B08C: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
L_8000B090:
    // 0x8000B090: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8000B094: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8000B098: lh          $t7, 0x28($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X28);
    // 0x8000B09C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000B0A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000B0A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000B0A8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8000B0AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000B0B0: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8000B0B4: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x8000B0B8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8000B0BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000B0C0: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8000B0C4: mflo        $t2
    ctx->r10 = lo;
    // 0x8000B0C8: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x8000B0CC: lh          $a1, 0x28($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X28);
    // 0x8000B0D0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000B0D4: jal         0x8001D8B0
    // 0x8000B0D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8001D8B0(rdram, ctx);
        goto after_5;
    // 0x8000B0D8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_5:
L_8000B0DC:
    // 0x8000B0DC: lhu         $t4, 0x5E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X5E);
L_8000B0E0:
    // 0x8000B0E0: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8000B0E4: beq         $t5, $zero, L_8000B0F8
    if (ctx->r13 == 0) {
        // 0x8000B0E8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000B0F8;
    }
    // 0x8000B0E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000B0EC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8000B0F0: jal         0x800268D4
    // 0x8000B0F4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_6;
    // 0x8000B0F4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_6:
L_8000B0F8:
    // 0x8000B0F8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000B0FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B100: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000B104: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8000B108: jr          $ra
    // 0x8000B10C: nop

    return;
    // 0x8000B10C: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049D60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80049D64: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80049D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049D6C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80049D70: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80049D74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80049D78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80049D7C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80049D80: jal         0x80039BDC
    // 0x80049D84: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x80049D84: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80049D88: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80049D8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80049D90: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80049D94: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80049D98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80049D9C: jal         0x80039C38
    // 0x80049DA0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80049DA0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x80049DA4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80049DA8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80049DAC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80049DB0: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x80049DB4: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x80049DB8: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x80049DBC: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x80049DC0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80049DC4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80049DC8: bgtz        $t0, L_80049E28
    if (SIGNED(ctx->r8) > 0) {
        // 0x80049DCC: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80049E28;
    }
    // 0x80049DCC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80049DD0: bltz        $t0, L_80049DE0
    if (SIGNED(ctx->r8) < 0) {
        // 0x80049DD4: nop
    
            goto L_80049DE0;
    }
    // 0x80049DD4: nop

    // 0x80049DD8: b           L_80049E2C
    // 0x80049DDC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_80049E2C;
    // 0x80049DDC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_80049DE0:
    // 0x80049DE0: bltzl       $t8, L_80049E2C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80049DE4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_80049E2C;
    }
    goto skip_0;
    // 0x80049DE4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x80049DE8: bgtz        $t8, L_80049DF8
    if (SIGNED(ctx->r24) > 0) {
        // 0x80049DEC: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_80049DF8;
    }
    // 0x80049DEC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80049DF0: beql        $t9, $zero, L_80049E2C
    if (ctx->r25 == 0) {
        // 0x80049DF4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_80049E2C;
    }
    goto skip_1;
    // 0x80049DF4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_80049DF8:
    // 0x80049DF8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80049DFC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80049E00: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80049E04: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x80049E08: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x80049E0C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x80049E10: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x80049E14: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80049E18: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80049E1C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80049E20: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80049E24: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80049E28:
    // 0x80049E28: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_80049E2C:
    // 0x80049E2C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80049E30: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80049E34: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80049E38: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80049E3C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80049E40: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80049E44: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x80049E48: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x80049E4C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80049E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049E54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80049E58: jr          $ra
    // 0x80049E5C: nop

    return;
    // 0x80049E5C: nop

;}
RECOMP_FUNC void func_8003FDFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FDFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003FE00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003FE04: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003FE08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003FE0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003FE10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003FE14: jal         0x80034160
    // 0x8003FE18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8003FE18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8003FE1C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8003FE20: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x8003FE24: beq         $s0, $zero, L_8003FE4C
    if (ctx->r16 == 0) {
        // 0x8003FE28: nop
    
            goto L_8003FE4C;
    }
    // 0x8003FE28: nop

L_8003FE2C:
    // 0x8003FE2C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8003FE30: jal         0x80036820
    // 0x8003FE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_1;
    // 0x8003FE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003FE38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003FE3C: jal         0x80036850
    // 0x8003FE40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80036850(rdram, ctx);
        goto after_2;
    // 0x8003FE40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x8003FE44: bne         $s1, $zero, L_8003FE2C
    if (ctx->r17 != 0) {
        // 0x8003FE48: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8003FE2C;
    }
    // 0x8003FE48: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8003FE4C:
    // 0x8003FE4C: jal         0x80034160
    // 0x8003FE50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x8003FE50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8003FE54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003FE58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003FE5C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003FE60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003FE64: jr          $ra
    // 0x8003FE68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003FE68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8003232C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003232C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80032330: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032334: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80032338: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003233C: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80032340: lh          $t7, 0x2D0A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X2D0A);
    // 0x80032344: addiu       $t6, $zero, 0x41
    ctx->r14 = ADD32(0, 0X41);
    // 0x80032348: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8003234C: bne         $s0, $t7, L_80032380
    if (ctx->r16 != ctx->r15) {
        // 0x80032350: sw          $t6, 0x2CC0($at)
        MEM_W(0X2CC0, ctx->r1) = ctx->r14;
            goto L_80032380;
    }
    // 0x80032350: sw          $t6, 0x2CC0($at)
    MEM_W(0X2CC0, ctx->r1) = ctx->r14;
    // 0x80032354: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80032358: lh          $v0, 0x2D08($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2D08);
    // 0x8003235C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80032360: bne         $at, $zero, L_80032380
    if (ctx->r1 != 0) {
        // 0x80032364: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_80032380;
    }
    // 0x80032364: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80032368: beq         $at, $zero, L_80032380
    if (ctx->r1 == 0) {
        // 0x8003236C: nop
    
            goto L_80032380;
    }
    // 0x8003236C: nop

    // 0x80032370: jal         0x80032020
    // 0x80032374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80032020(rdram, ctx);
        goto after_0;
    // 0x80032374: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80032378: b           L_80032388
    // 0x8003237C: nop

        goto L_80032388;
    // 0x8003237C: nop

L_80032380:
    // 0x80032380: jal         0x80032020
    // 0x80032384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80032020(rdram, ctx);
        goto after_1;
    // 0x80032384: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_80032388:
    // 0x80032388: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8003238C: lbu         $v0, 0x2D0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D0E);
    // 0x80032390: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80032394: lui         $t1, 0x8009
    ctx->r9 = S32(0X8009 << 16);
    // 0x80032398: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8003239C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800323A0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800323A4: lw          $t1, 0x2CC8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2CC8);
    // 0x800323A8: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x800323AC: subu        $a1, $a1, $s0
    ctx->r5 = SUB32(ctx->r5, ctx->r16);
    // 0x800323B0: bne         $t1, $zero, L_800324A4
    if (ctx->r9 != 0) {
        // 0x800323B4: addiu       $a0, $zero, 0x52
        ctx->r4 = ADD32(0, 0X52);
            goto L_800324A4;
    }
    // 0x800323B4: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x800323B8: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800323BC: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800323C0: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x800323C4: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x800323C8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800323CC: jal         0x80031F1C
    // 0x800323D0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80031F1C(rdram, ctx);
        goto after_2;
    // 0x800323D0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x800323D4: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800323D8: lbu         $t6, 0x2D0E($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2D0E);
    // 0x800323DC: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x800323E0: addiu       $t5, $t5, 0x2AC0
    ctx->r13 = ADD32(ctx->r13, 0X2AC0);
    // 0x800323E4: sll         $t4, $s0, 5
    ctx->r12 = S32(ctx->r16 << 5);
    // 0x800323E8: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x800323EC: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800323F0: addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // 0x800323F4: addiu       $a0, $a0, 0xE
    ctx->r4 = ADD32(ctx->r4, 0XE);
    // 0x800323F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800323FC: jal         0x80031FBC
    // 0x80032400: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80031FBC(rdram, ctx);
        goto after_3;
    // 0x80032400: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x80032404: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80032408: lbu         $t9, 0x2D0E($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2D0E);
    // 0x8003240C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80032410: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80032414: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80032418: lbu         $t2, 0xA($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XA);
    // 0x8003241C: beql        $t2, $zero, L_8003245C
    if (ctx->r10 == 0) {
        // 0x80032420: addiu       $a0, $zero, 0x100
        ctx->r4 = ADD32(0, 0X100);
            goto L_8003245C;
    }
    goto skip_0;
    // 0x80032420: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    skip_0:
    // 0x80032424: jal         0x80031DD4
    // 0x80032428: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80031DD4(rdram, ctx);
        goto after_4;
    // 0x80032428: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_4:
    // 0x8003242C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80032430: addiu       $v0, $v0, 0x2D30
    ctx->r2 = ADD32(ctx->r2, 0X2D30);
    // 0x80032434: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80032438: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8003243C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80032440: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80032444: lbu         $t5, 0x2D0E($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X2D0E);
    // 0x80032448: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8003244C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80032450: jal         0x80031DD4
    // 0x80032454: lbu         $a0, 0xA($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0XA);
    func_80031DD4(rdram, ctx);
        goto after_5;
    // 0x80032454: lbu         $a0, 0xA($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0XA);
    after_5:
    // 0x80032458: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
L_8003245C:
    // 0x8003245C: jal         0x80031F1C
    // 0x80032460: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    func_80031F1C(rdram, ctx);
        goto after_6;
    // 0x80032460: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    after_6:
    // 0x80032464: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x80032468: lbu         $t8, 0x2D0E($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2D0E);
    // 0x8003246C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80032470: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80032474: sll         $t0, $t8, 5
    ctx->r8 = S32(ctx->r24 << 5);
    // 0x80032478: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8003247C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80032480: addiu       $a0, $a0, 0xFF
    ctx->r4 = ADD32(ctx->r4, 0XFF);
    // 0x80032484: srl         $t2, $a0, 8
    ctx->r10 = S32(U32(ctx->r4) >> 8);
    // 0x80032488: jal         0x80031CF0
    // 0x8003248C: andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    func_80031CF0(rdram, ctx);
        goto after_7;
    // 0x8003248C: andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    after_7:
    // 0x80032490: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80032494: jal         0x80031FBC
    // 0x80032498: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80031FBC(rdram, ctx);
        goto after_8;
    // 0x80032498: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8003249C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800324A0: lbu         $v0, 0x2D0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D0E);
L_800324A4:
    // 0x800324A4: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x800324A8: subu        $a1, $a1, $s0
    ctx->r5 = SUB32(ctx->r5, ctx->r16);
    // 0x800324AC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800324B0: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800324B4: addiu       $a1, $a1, 0x58
    ctx->r5 = ADD32(ctx->r5, 0X58);
    // 0x800324B8: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x800324BC: addu        $t6, $v0, $s0
    ctx->r14 = ADD32(ctx->r2, ctx->r16);
    // 0x800324C0: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x800324C4: sra         $t4, $t5, 16
    ctx->r12 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800324C8: beq         $at, $zero, L_800324F8
    if (ctx->r1 == 0) {
        // 0x800324CC: or          $a1, $t4, $zero
        ctx->r5 = ctx->r12 | 0;
            goto L_800324F8;
    }
    // 0x800324CC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800324D0: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800324D4: jal         0x80031F1C
    // 0x800324D8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_80031F1C(rdram, ctx);
        goto after_9;
    // 0x800324D8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_9:
    // 0x800324DC: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800324E0: lbu         $t7, 0x2D0E($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X2D0E);
    // 0x800324E4: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x800324E8: jal         0x80031DD4
    // 0x800324EC: addiu       $a0, $a0, 0x11
    ctx->r4 = ADD32(ctx->r4, 0X11);
    func_80031DD4(rdram, ctx);
        goto after_10;
    // 0x800324EC: addiu       $a0, $a0, 0x11
    ctx->r4 = ADD32(ctx->r4, 0X11);
    after_10:
    // 0x800324F0: b           L_80032530
    // 0x800324F4: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
        goto L_80032530;
    // 0x800324F4: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
L_800324F8:
    // 0x800324F8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x800324FC: jal         0x80031F1C
    // 0x80032500: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80031F1C(rdram, ctx);
        goto after_11;
    // 0x80032500: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_11:
    // 0x80032504: jal         0x80031DD4
    // 0x80032508: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_80031DD4(rdram, ctx);
        goto after_12;
    // 0x80032508: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_12:
    // 0x8003250C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x80032510: jal         0x80031F1C
    // 0x80032514: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    func_80031F1C(rdram, ctx);
        goto after_13;
    // 0x80032514: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    after_13:
    // 0x80032518: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x8003251C: lbu         $t8, 0x2D0E($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2D0E);
    // 0x80032520: addu        $a0, $t8, $s0
    ctx->r4 = ADD32(ctx->r24, ctx->r16);
    // 0x80032524: jal         0x80031DD4
    // 0x80032528: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    func_80031DD4(rdram, ctx);
        goto after_14;
    // 0x80032528: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    after_14:
    // 0x8003252C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
L_80032530:
    // 0x80032530: jal         0x80031F1C
    // 0x80032534: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    func_80031F1C(rdram, ctx);
        goto after_15;
    // 0x80032534: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    after_15:
    // 0x80032538: jal         0x80031DD4
    // 0x8003253C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    func_80031DD4(rdram, ctx);
        goto after_16;
    // 0x8003253C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    after_16:
    // 0x80032540: addiu       $t9, $zero, 0x5B
    ctx->r25 = ADD32(0, 0X5B);
    // 0x80032544: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80032548: sw          $t9, 0x2CC0($at)
    MEM_W(0X2CC0, ctx->r1) = ctx->r25;
    // 0x8003254C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032550: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032554: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80032558: jr          $ra
    // 0x8003255C: nop

    return;
    // 0x8003255C: nop

;}
RECOMP_FUNC void func_80011B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011B70: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80011B74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80011B78: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80011B7C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80011B80: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80011B84: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80011B88: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80011B8C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80011B90: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80011B94: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80011B98: addiu       $v0, $v0, -0x3B90
    ctx->r2 = ADD32(ctx->r2, -0X3B90);
    // 0x80011B9C: lw          $v1, 0x4EE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4EE4);
    // 0x80011BA0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80011BA4:
    // 0x80011BA4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80011BA8: beql        $v1, $t6, L_80011BC4
    if (ctx->r3 == ctx->r14) {
        // 0x80011BAC: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80011BC4;
    }
    goto skip_0;
    // 0x80011BAC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    skip_0:
    // 0x80011BB0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80011BB4: sltiu       $at, $s3, 0x13
    ctx->r1 = ctx->r19 < 0X13 ? 1 : 0;
    // 0x80011BB8: bne         $at, $zero, L_80011BA4
    if (ctx->r1 != 0) {
        // 0x80011BBC: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80011BA4;
    }
    // 0x80011BBC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80011BC0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
L_80011BC4:
    // 0x80011BC4: beq         $s3, $at, L_80011CFC
    if (ctx->r19 == ctx->r1) {
        // 0x80011BC8: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80011CFC;
    }
    // 0x80011BC8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80011BCC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80011BD0: lw          $t8, 0x4EE8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4EE8);
    // 0x80011BD4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80011BD8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80011BDC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80011BE0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x80011BE4: lhu         $s3, 0x0($v1)
    ctx->r19 = MEM_HU(ctx->r3, 0X0);
    // 0x80011BE8: addiu       $a0, $a0, 0x69A0
    ctx->r4 = ADD32(ctx->r4, 0X69A0);
    // 0x80011BEC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80011BF0: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80011BF4: lw          $s1, 0x4($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X4);
    // 0x80011BF8: beq         $s3, $zero, L_80011D04
    if (ctx->r19 == 0) {
        // 0x80011BFC: addiu       $s0, $s0, 0x62E0
        ctx->r16 = ADD32(ctx->r16, 0X62E0);
            goto L_80011D04;
    }
    // 0x80011BFC: addiu       $s0, $s0, 0x62E0
    ctx->r16 = ADD32(ctx->r16, 0X62E0);
    // 0x80011C00: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80011C04: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80011C08: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80011C0C: addiu       $s2, $s2, 0x69B8
    ctx->r18 = ADD32(ctx->r18, 0X69B8);
    // 0x80011C10: lwc1        $f22, 0x12C0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X12C0);
L_80011C14:
    // 0x80011C14: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80011C18: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80011C1C: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x80011C20: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80011C24: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80011C28: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x80011C2C: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x80011C30: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80011C34: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80011C38: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80011C3C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80011C40: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80011C44: jal         0x8000EE60
    // 0x80011C48: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8000EE60(rdram, ctx);
        goto after_0;
    // 0x80011C48: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x80011C4C: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80011C50: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80011C54: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80011C58: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80011C5C: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80011C60: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x80011C64: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80011C68: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80011C6C: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80011C70: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80011C74: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80011C78: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80011C7C: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80011C80: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80011C84: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80011C88: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x80011C8C: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80011C90: swc1        $f22, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f22.u32l;
    // 0x80011C94: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80011C98: lbu         $t1, 0x20($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X20);
    // 0x80011C9C: sh          $t1, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r9;
    // 0x80011CA0: lbu         $t2, 0x21($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X21);
    // 0x80011CA4: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x80011CA8: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x80011CAC: jal         0x80012170
    // 0x80011CB0: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    func_80012170(rdram, ctx);
        goto after_1;
    // 0x80011CB0: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    after_1:
    // 0x80011CB4: beq         $v0, $zero, L_80011CC4
    if (ctx->r2 == 0) {
        // 0x80011CB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80011CC4;
    }
    // 0x80011CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80011CBC: b           L_80011CC8
    // 0x80011CC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80011CC8;
    // 0x80011CC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80011CC4:
    // 0x80011CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80011CC8:
    // 0x80011CC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80011CCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80011CD0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80011CD4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80011CD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80011CDC: jal         0x8001D8B0
    // 0x80011CE0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    func_8001D8B0(rdram, ctx);
        goto after_2;
    // 0x80011CE0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    after_2:
    // 0x80011CE4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80011CE8: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
    // 0x80011CEC: bne         $s3, $zero, L_80011C14
    if (ctx->r19 != 0) {
        // 0x80011CF0: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_80011C14;
    }
    // 0x80011CF0: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x80011CF4: b           L_80011D08
    // 0x80011CF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80011D08;
    // 0x80011CF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80011CFC:
    // 0x80011CFC: addiu       $a0, $a0, 0x69A0
    ctx->r4 = ADD32(ctx->r4, 0X69A0);
    // 0x80011D00: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80011D04:
    // 0x80011D04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80011D08:
    // 0x80011D08: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80011D0C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80011D10: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80011D14: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80011D18: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80011D1C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80011D20: jr          $ra
    // 0x80011D24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80011D24: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8010200C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010200C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80102010: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80102014: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80102018: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x8010201C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80102020: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80102024: lh          $t8, 0x34($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X34);
    // 0x80102028: lw          $t1, 0x38($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X38);
    // 0x8010202C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80102030: sh          $t9, 0x34($v0)
    MEM_H(0X34, ctx->r2) = ctx->r25;
    // 0x80102034: lh          $t0, 0x34($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X34);
    // 0x80102038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010203C: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80102040: bne         $at, $zero, L_80102050
    if (ctx->r1 != 0) {
        // 0x80102044: nop
    
            goto L_80102050;
    }
    // 0x80102044: nop

    // 0x80102048: jr          $ra
    // 0x8010204C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x8010204C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80102050:
    // 0x80102050: jr          $ra
    // 0x80102054: nop

    return;
    // 0x80102054: nop

;}
RECOMP_FUNC void alSeqFileNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038508: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x8003850C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038510: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80038514: blez        $t6, L_80038540
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80038518: nop
    
            goto L_80038540;
    }
    // 0x80038518: nop

    // 0x8003851C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
L_80038520:
    // 0x80038520: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80038524: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80038528: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8003852C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80038530: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x80038534: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80038538: bnel        $at, $zero, L_80038520
    if (ctx->r1 != 0) {
        // 0x8003853C: lw          $t7, 0x4($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X4);
            goto L_80038520;
    }
    goto skip_0;
    // 0x8003853C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    skip_0:
L_80038540:
    // 0x80038540: jr          $ra
    // 0x80038544: nop

    return;
    // 0x80038544: nop

;}
RECOMP_FUNC void func_80043D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043D10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80043D14: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80043D18: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80043D1C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80043D20: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80043D24: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80043D28: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80043D2C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80043D30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80043D34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80043D38: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x80043D3C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80043D40: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80043D44: beq         $s0, $zero, L_80043DE8
    if (ctx->r16 == 0) {
        // 0x80043D48: addiu       $s7, $zero, 0x17
        ctx->r23 = ADD32(0, 0X17);
            goto L_80043DE8;
    }
    // 0x80043D48: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x80043D4C: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_80043D50:
    // 0x80043D50: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x80043D54: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80043D58: beql        $s3, $s6, L_80043D6C
    if (ctx->r19 == ctx->r22) {
        // 0x80043D5C: lw          $t6, 0x10($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X10);
            goto L_80043D6C;
    }
    goto skip_0;
    // 0x80043D5C: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x80043D60: bne         $s3, $s7, L_80043DE0
    if (ctx->r19 != ctx->r23) {
        // 0x80043D64: nop
    
            goto L_80043DE0;
    }
    // 0x80043D64: nop

    // 0x80043D68: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
L_80043D6C:
    // 0x80043D6C: bne         $s2, $t6, L_80043DE0
    if (ctx->r18 != ctx->r14) {
        // 0x80043D70: nop
    
            goto L_80043DE0;
    }
    // 0x80043D70: nop

    // 0x80043D74: lw          $t9, 0x78($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X78);
    // 0x80043D78: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80043D7C: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    // 0x80043D80: jalr        $t9
    // 0x80043D84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80043D84: nop

    after_0:
    // 0x80043D88: jal         0x80036820
    // 0x80043D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_1;
    // 0x80043D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80043D90: beq         $s1, $zero, L_80043DA8
    if (ctx->r17 == 0) {
        // 0x80043D94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80043DA8;
    }
    // 0x80043D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043D98: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x80043D9C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80043DA0: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80043DA4: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_80043DA8:
    // 0x80043DA8: jal         0x80036850
    // 0x80043DAC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80036850(rdram, ctx);
        goto after_2;
    // 0x80043DAC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x80043DB0: bnel        $s3, $s6, L_80043DCC
    if (ctx->r19 != ctx->r22) {
        // 0x80043DB4: lbu         $t3, 0x37($s2)
        ctx->r11 = MEM_BU(ctx->r18, 0X37);
            goto L_80043DCC;
    }
    goto skip_1;
    // 0x80043DB4: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    skip_1:
    // 0x80043DB8: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x80043DBC: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x80043DC0: b           L_80043DD4
    // 0x80043DC4: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_80043DD4;
    // 0x80043DC4: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
    // 0x80043DC8: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
L_80043DCC:
    // 0x80043DCC: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x80043DD0: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_80043DD4:
    // 0x80043DD4: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x80043DD8: beql        $t5, $zero, L_80043DEC
    if (ctx->r13 == 0) {
        // 0x80043DDC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80043DEC;
    }
    goto skip_2;
    // 0x80043DDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_80043DE0:
    // 0x80043DE0: bne         $s1, $zero, L_80043D50
    if (ctx->r17 != 0) {
        // 0x80043DE4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80043D50;
    }
    // 0x80043DE4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80043DE8:
    // 0x80043DE8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80043DEC:
    // 0x80043DEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80043DF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80043DF4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80043DF8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80043DFC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80043E00: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80043E04: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80043E08: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80043E0C: jr          $ra
    // 0x80043E10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80043E10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80026A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026A0C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80026A10: lb          $t6, -0xFF0($t6)
    ctx->r14 = MEM_B(ctx->r14, -0XFF0);
    // 0x80026A14: lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // 0x80026A18: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80026A1C: jal         0x80026554
    // 0x80026A20: lbu         $a0, 0x3CA4($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X3CA4);
    func_80026554(rdram, ctx);
        goto after_0;
    // 0x80026A20: lbu         $a0, 0x3CA4($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X3CA4);
    after_0:
    // 0x80026A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026A2C: jr          $ra
    // 0x80026A30: nop

    return;
    // 0x80026A30: nop

;}
RECOMP_FUNC void func_80031BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BB0: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80031BB4: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x80031BB8: beq         $at, $zero, L_80031BFC
    if (ctx->r1 == 0) {
        // 0x80031BBC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80031BFC;
    }
    // 0x80031BBC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80031BC0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80031BC4: addu        $at, $at, $t6
    gpr jr_addend_80031BCC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80031BC8: lw          $t6, 0x1A50($at)
    ctx->r14 = ADD32(ctx->r1, 0X1A50);
    // 0x80031BCC: jr          $t6
    // 0x80031BD0: nop

    switch (jr_addend_80031BCC >> 2) {
        case 0: goto L_80031BD4; break;
        case 1: goto L_80031BEC; break;
        case 2: goto L_80031BE4; break;
        case 3: goto L_80031BDC; break;
        case 4: goto L_80031BFC; break;
        case 5: goto L_80031BFC; break;
        case 6: goto L_80031BFC; break;
        case 7: goto L_80031BFC; break;
        case 8: goto L_80031BF4; break;
        case 9: goto L_80031BE4; break;
        case 10: goto L_80031BDC; break;
        default: switch_error(__func__, 0x80031BCC, 0x80071A50);
    }
    // 0x80031BD0: nop

L_80031BD4:
    // 0x80031BD4: b           L_80031C00
    // 0x80031BD8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80031C00;
    // 0x80031BD8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80031BDC:
    // 0x80031BDC: b           L_80031C00
    // 0x80031BE0: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
        goto L_80031C00;
    // 0x80031BE0: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
L_80031BE4:
    // 0x80031BE4: b           L_80031C00
    // 0x80031BE8: addiu       $v1, $zero, -0x3
    ctx->r3 = ADD32(0, -0X3);
        goto L_80031C00;
    // 0x80031BE8: addiu       $v1, $zero, -0x3
    ctx->r3 = ADD32(0, -0X3);
L_80031BEC:
    // 0x80031BEC: b           L_80031C00
    // 0x80031BF0: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
        goto L_80031C00;
    // 0x80031BF0: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
L_80031BF4:
    // 0x80031BF4: b           L_80031C00
    // 0x80031BF8: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
        goto L_80031C00;
    // 0x80031BF8: addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
L_80031BFC:
    // 0x80031BFC: addiu       $v1, $zero, -0x6
    ctx->r3 = ADD32(0, -0X6);
L_80031C00:
    // 0x80031C00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80031C04: jr          $ra
    // 0x80031C08: nop

    return;
    // 0x80031C08: nop

;}
RECOMP_FUNC void func_80006774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006774: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80006778: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8000677C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80006780: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80006784: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80006788: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8000678C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80006790: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80006794: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80006798: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8000679C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800067A0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800067A4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800067A8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800067AC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800067B0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800067B4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800067B8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800067BC: lw          $t6, 0x64($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X64);
    // 0x800067C0: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800067C4: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800067C8: lwc1        $f4, 0x18($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X18);
    // 0x800067CC: lhu         $t7, -0x3A66($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X3A66);
    // 0x800067D0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800067D4: mul.s       $f30, $f4, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800067D8: beq         $t7, $zero, L_800069B0
    if (ctx->r15 == 0) {
        // 0x800067DC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800069B0;
    }
    // 0x800067DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800067E0: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800067E4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x800067E8: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x800067EC: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x800067F0: mtc1        $at, $f29
    ctx->f_odd[(29 - 1) * 2] = ctx->r1;
    // 0x800067F4: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800067F8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800067FC: addiu       $s2, $s2, -0x43D0
    ctx->r18 = ADD32(ctx->r18, -0X43D0);
    // 0x80006800: addiu       $s6, $s6, -0x3668
    ctx->r22 = ADD32(ctx->r22, -0X3668);
    // 0x80006804: addiu       $s3, $s3, -0x2F50
    ctx->r19 = ADD32(ctx->r19, -0X2F50);
    // 0x80006808: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8000680C: addiu       $s7, $zero, 0x128
    ctx->r23 = ADD32(0, 0X128);
    // 0x80006810: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80006814: lhu         $t8, 0x0($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X0);
L_80006818:
    // 0x80006818: multu       $t8, $s7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000681C: mflo        $t9
    ctx->r25 = lo;
    // 0x80006820: addu        $v0, $s6, $t9
    ctx->r2 = ADD32(ctx->r22, ctx->r25);
    // 0x80006824: lh          $t0, 0x74($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X74);
    // 0x80006828: addiu       $s0, $v0, 0x24
    ctx->r16 = ADD32(ctx->r2, 0X24);
    // 0x8000682C: beq         $s5, $t0, L_80006994
    if (ctx->r21 == ctx->r8) {
        // 0x80006830: nop
    
            goto L_80006994;
    }
    // 0x80006830: nop

    // 0x80006834: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80006838: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000683C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80006840: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80006844: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80006848: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000684C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80006850: nop

    // 0x80006854: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80006858: jal         0x80034F60
    // 0x8000685C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000685C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x80006860: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80006864: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80006868: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8000686C: lwc1        $f8, 0x18($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80006870: mul.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80006874: add.s       $f18, $f30, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f30.fl + ctx->f24.fl;
    // 0x80006878: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8000687C: add.d       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f28.d); 
    ctx->f6.d = ctx->f4.d + ctx->f28.d;
    // 0x80006880: c.lt.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d < ctx->f6.d;
    // 0x80006884: nop

    // 0x80006888: bc1f        L_80006994
    if (!c1cs) {
        // 0x8000688C: nop
    
            goto L_80006994;
    }
    // 0x8000688C: nop

    // 0x80006890: swc1        $f20, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f20.u32l;
    // 0x80006894: swc1        $f22, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f22.u32l;
    // 0x80006898: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8000689C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800068A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800068A4: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800068A8: bne         $fp, $v1, L_800068D4
    if (ctx->r30 != ctx->r3) {
        // 0x800068AC: nop
    
            goto L_800068D4;
    }
    // 0x800068AC: nop

    // 0x800068B0: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800068B4: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x800068B8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800068BC: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x800068C0: lwc1        $f8, 0x94($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X94);
    // 0x800068C4: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x800068C8: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800068CC: b           L_800068F8
    // 0x800068D0: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
        goto L_800068F8;
    // 0x800068D0: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
L_800068D4:
    // 0x800068D4: bnel        $v1, $at, L_800068EC
    if (ctx->r3 != ctx->r1) {
        // 0x800068D8: lwc1        $f16, 0x4($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800068EC;
    }
    goto skip_0;
    // 0x800068D8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x800068DC: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    // 0x800068E0: b           L_800068F8
    // 0x800068E4: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
        goto L_800068F8;
    // 0x800068E4: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x800068E8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
L_800068EC:
    // 0x800068EC: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800068F0: lwc1        $f22, 0x1C($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800068F4: sub.s       $f20, $f16, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f6.fl;
L_800068F8:
    // 0x800068F8: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800068FC: nop

    // 0x80006900: bc1fl       L_80006910
    if (!c1cs) {
        // 0x80006904: lw          $t3, 0x64($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X64);
            goto L_80006910;
    }
    goto skip_1;
    // 0x80006904: lw          $t3, 0x64($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X64);
    skip_1:
    // 0x80006908: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8000690C: lw          $t3, 0x64($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X64);
L_80006910:
    // 0x80006910: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80006914: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80006918: lwc1        $f8, 0x1C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x8000691C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80006920: nop

    // 0x80006924: mul.s       $f16, $f22, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80006928: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000692C: sub.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x80006930: c.le.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
    // 0x80006934: nop

    // 0x80006938: bc1f        L_80006994
    if (!c1cs) {
        // 0x8000693C: nop
    
            goto L_80006994;
    }
    // 0x8000693C: nop

    // 0x80006940: jal         0x800232F4
    // 0x80006944: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x80006944: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    after_1:
    // 0x80006948: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8000694C: c.le.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl <= ctx->f8.fl;
    // 0x80006950: nop

    // 0x80006954: bc1f        L_80006994
    if (!c1cs) {
        // 0x80006958: nop
    
            goto L_80006994;
    }
    // 0x80006958: nop

    // 0x8000695C: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80006960: neg.s       $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = -ctx->f24.fl;
    // 0x80006964: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80006968: nop

    // 0x8000696C: bc1f        L_80006994
    if (!c1cs) {
        // 0x80006970: nop
    
            goto L_80006994;
    }
    // 0x80006970: nop

    // 0x80006974: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80006978: nop

    // 0x8000697C: bc1f        L_80006994
    if (!c1cs) {
        // 0x80006980: nop
    
            goto L_80006994;
    }
    // 0x80006980: nop

    // 0x80006984: lhu         $t4, 0x0($s3)
    ctx->r12 = MEM_HU(ctx->r19, 0X0);
    // 0x80006988: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000698C: b           L_800069B0
    // 0x80006990: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
        goto L_800069B0;
    // 0x80006990: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
L_80006994:
    // 0x80006994: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80006998: lhu         $t6, -0x3A66($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A66);
    // 0x8000699C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800069A0: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800069A4: sltu        $at, $s4, $t6
    ctx->r1 = ctx->r20 < ctx->r14 ? 1 : 0;
    // 0x800069A8: bnel        $at, $zero, L_80006818
    if (ctx->r1 != 0) {
        // 0x800069AC: lhu         $t8, 0x0($s3)
        ctx->r24 = MEM_HU(ctx->r19, 0X0);
            goto L_80006818;
    }
    goto skip_2;
    // 0x800069AC: lhu         $t8, 0x0($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0X0);
    skip_2:
L_800069B0:
    // 0x800069B0: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x800069B4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800069B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800069BC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800069C0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800069C4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800069C8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800069CC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800069D0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800069D4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800069D8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800069DC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800069E0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800069E4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800069E8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800069EC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800069F0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800069F4: jr          $ra
    // 0x800069F8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800069F8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80004BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004BD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004BD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80004BDC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80004BE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004BE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80004BE8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80004BEC: swc1        $f0, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f0.u32l;
    // 0x80004BF0: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x80004BF4: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x80004BF8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80004BFC: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x80004C00: beql        $at, $zero, L_80004CE8
    if (ctx->r1 == 0) {
        // 0x80004C04: lhu         $t7, 0x4($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X4);
            goto L_80004CE8;
    }
    goto skip_0;
    // 0x80004C04: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    skip_0:
    // 0x80004C08: lwc1        $f12, 0x10($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80004C0C: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x80004C10: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004C14: ldc1        $f14, 0xF98($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0XF98);
    // 0x80004C18: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80004C1C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004C20: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80004C24: c.lt.d      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.d < ctx->f14.d;
    // 0x80004C28: nop

    // 0x80004C2C: bc1f        L_80004C4C
    if (!c1cs) {
        // 0x80004C30: nop
    
            goto L_80004C4C;
    }
    // 0x80004C30: nop

    // 0x80004C34: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004C38: ldc1        $f16, 0xFA0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0XFA0);
    // 0x80004C3C: add.d       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f0.d + ctx->f16.d;
    // 0x80004C40: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80004C44: b           L_80004C74
    // 0x80004C48: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
        goto L_80004C74;
    // 0x80004C48: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80004C4C:
    // 0x80004C4C: ldc1        $f8, 0xFA8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0XFA8);
    // 0x80004C50: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004C54: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80004C58: nop

    // 0x80004C5C: bc1f        L_80004C74
    if (!c1cs) {
        // 0x80004C60: nop
    
            goto L_80004C74;
    }
    // 0x80004C60: nop

    // 0x80004C64: ldc1        $f16, 0xFB0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0XFB0);
    // 0x80004C68: sub.d       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f0.d - ctx->f16.d;
    // 0x80004C6C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80004C70: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80004C74:
    // 0x80004C74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004C78: ldc1        $f16, 0xFB8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0XFB8);
    // 0x80004C7C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004C80: ldc1        $f4, 0xFC0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0XFC0);
    // 0x80004C84: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80004C88: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80004C8C: mul.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80004C90: add.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f18.d + ctx->f6.d;
    // 0x80004C94: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80004C98: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x80004C9C: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80004CA0: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x80004CA4: c.lt.d      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.d < ctx->f14.d;
    // 0x80004CA8: nop

    // 0x80004CAC: bc1f        L_80004CC4
    if (!c1cs) {
        // 0x80004CB0: nop
    
            goto L_80004CC4;
    }
    // 0x80004CB0: nop

    // 0x80004CB4: add.d       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f2.d + ctx->f16.d;
    // 0x80004CB8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80004CBC: b           L_80004CE4
    // 0x80004CC0: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
        goto L_80004CE4;
    // 0x80004CC0: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
L_80004CC4:
    // 0x80004CC4: ldc1        $f8, 0xFC8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0XFC8);
    // 0x80004CC8: c.lt.d      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.d < ctx->f2.d;
    // 0x80004CCC: nop

    // 0x80004CD0: bc1fl       L_80004CE8
    if (!c1cs) {
        // 0x80004CD4: lhu         $t7, 0x4($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X4);
            goto L_80004CE8;
    }
    goto skip_1;
    // 0x80004CD4: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
    skip_1:
    // 0x80004CD8: sub.d       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = ctx->f2.d - ctx->f16.d;
    // 0x80004CDC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80004CE0: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
L_80004CE4:
    // 0x80004CE4: lhu         $t7, 0x4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X4);
L_80004CE8:
    // 0x80004CE8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80004CEC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80004CF0: bne         $t9, $zero, L_80004D1C
    if (ctx->r25 != 0) {
        // 0x80004CF4: sh          $t8, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r24;
            goto L_80004D1C;
    }
    // 0x80004CF4: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x80004CF8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80004CFC: lhu         $t0, 0x60($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X60);
    // 0x80004D00: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80004D04: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80004D08: andi        $t1, $t0, 0xFFFC
    ctx->r9 = ctx->r8 & 0XFFFC;
    // 0x80004D0C: sh          $t1, 0x60($a3)
    MEM_H(0X60, ctx->r7) = ctx->r9;
    // 0x80004D10: lw          $a1, 0x4EE8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4EE8);
    // 0x80004D14: jal         0x8002684C
    // 0x80004D18: lw          $a0, 0x4EE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EE4);
    func_8002684C(rdram, ctx);
        goto after_0;
    // 0x80004D18: lw          $a0, 0x4EE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EE4);
    after_0:
L_80004D1C:
    // 0x80004D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004D20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004D28: jr          $ra
    // 0x80004D2C: nop

    return;
    // 0x80004D2C: nop

;}
RECOMP_FUNC void func_80044230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004423C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80044240: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80044244: beql        $t6, $zero, L_800442A8
    if (ctx->r14 == 0) {
        // 0x80044248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800442A8;
    }
    goto skip_0;
    // 0x80044248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004424C: jal         0x80036A30
    // 0x80044250: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x80044250: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80044254: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80044258: beq         $v0, $zero, L_800442A4
    if (ctx->r2 == 0) {
        // 0x8004425C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800442A4;
    }
    // 0x8004425C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80044260: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80044264: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x80044268: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8004426C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80044270: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80044274: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80044278: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8004427C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80044280: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80044284: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80044288: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8004428C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80044290: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x80044294: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x80044298: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8004429C: jalr        $t9
    // 0x800442A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800442A0: nop

    after_1:
L_800442A4:
    // 0x800442A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800442A8:
    // 0x800442A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800442AC: jr          $ra
    // 0x800442B0: nop

    return;
    // 0x800442B0: nop

    // 0x800442B4: nop

    // 0x800442B8: nop

    // 0x800442BC: nop

;}
RECOMP_FUNC void func_8001F3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F3DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001F3E0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001F3E4: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8001F3E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001F3EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001F3F0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001F3F4: sw          $zero, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = 0;
    // 0x8001F3F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001F3FC: sw          $zero, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = 0;
    // 0x8001F400: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F404: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8001F408: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8001F40C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001F410: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001F414: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F418: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001F41C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F420: lui         $t6, 0x803A
    ctx->r14 = S32(0X803A << 16);
    // 0x8001F424: addiu       $t6, $t6, -0x2670
    ctx->r14 = ADD32(ctx->r14, -0X2670);
    // 0x8001F428: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001F42C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001F430: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001F434: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001F438: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F43C: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8001F440: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8001F444: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001F448: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001F44C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F450: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001F454: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F458: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8001F45C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8001F460: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001F464: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001F468: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001F46C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001F470: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F474: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8001F478: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x8001F47C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001F480: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001F484: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F488: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001F48C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F490: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x8001F494: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8001F498: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001F49C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001F4A0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001F4A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001F4A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F4AC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8001F4B0: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001F4B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001F4B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001F4BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F4C0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001F4C4: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8001F4C8: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001F4CC: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001F4D0: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001F4D4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001F4D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001F4DC: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x8001F4E0: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8001F4E4: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x8001F4E8: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8001F4EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001F4F0: jal         0x800210FC
    // 0x8001F4F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_0;
    // 0x8001F4F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x8001F4F8: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001F4FC: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8001F500: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8001F504: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001F508: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001F50C: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001F510: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001F514: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001F518: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001F51C: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x8001F520: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8001F524: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x8001F528: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8001F52C: jal         0x800210FC
    // 0x8001F530: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_1;
    // 0x8001F530: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8001F534: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001F538: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8001F53C: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x8001F540: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001F544: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001F548: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001F54C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001F550: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001F554: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001F558: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x8001F55C: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8001F560: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x8001F564: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8001F568: jal         0x800210FC
    // 0x8001F56C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_2;
    // 0x8001F56C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8001F570: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001F574: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8001F578: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8001F57C: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x8001F580: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x8001F584: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8001F588: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8001F58C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8001F590: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001F594: addiu       $a0, $a0, 0x6F60
    ctx->r4 = ADD32(ctx->r4, 0X6F60);
    // 0x8001F598: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // 0x8001F59C: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x8001F5A0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8001F5A4: jal         0x800210FC
    // 0x8001F5A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800210FC(rdram, ctx);
        goto after_3;
    // 0x8001F5A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x8001F5AC: lui         $a0, 0x803A
    ctx->r4 = S32(0X803A << 16);
    // 0x8001F5B0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8001F5B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001F5B8: addiu       $a0, $a0, 0x6F40
    ctx->r4 = ADD32(ctx->r4, 0X6F40);
    // 0x8001F5BC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8001F5C0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x8001F5C4: jal         0x80020E2C
    // 0x8001F5C8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    func_80020E2C(rdram, ctx);
        goto after_4;
    // 0x8001F5C8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_4:
    // 0x8001F5CC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001F5D0: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8001F5D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F5D8: lui         $t9, 0x803A
    ctx->r25 = S32(0X803A << 16);
    // 0x8001F5DC: addiu       $t9, $t9, -0x6550
    ctx->r25 = ADD32(ctx->r25, -0X6550);
    // 0x8001F5E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001F5E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001F5E8: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x8001F5EC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001F5F0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8001F5F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F5F8: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x8001F5FC: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8001F600: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8001F604: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8001F608: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F60C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001F610: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F614: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8001F618: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8001F61C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001F620: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001F624: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001F628: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001F62C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F630: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8001F634: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8001F638: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8001F63C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001F640: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F644: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001F648: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F64C: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8001F650: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8001F654: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8001F658: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001F65C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8001F660: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001F664: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001F668: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001F66C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8001F670: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8001F674: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8001F678: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001F67C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8001F680: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001F684: lbu         $a3, -0x455C($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X455C);
    // 0x8001F688: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    // 0x8001F68C: jal         0x80020D4C
    // 0x8001F690: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    func_80020D4C(rdram, ctx);
        goto after_5;
    // 0x8001F690: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    after_5:
    // 0x8001F694: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001F698: lbu         $a3, -0x455B($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X455B);
    // 0x8001F69C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8001F6A0: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x8001F6A4: jal         0x80020D4C
    // 0x8001F6A8: addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    func_80020D4C(rdram, ctx);
        goto after_6;
    // 0x8001F6A8: addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    after_6:
    // 0x8001F6AC: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001F6B0: lbu         $a3, -0x455A($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X455A);
    // 0x8001F6B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8001F6B8: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    // 0x8001F6BC: jal         0x80020D4C
    // 0x8001F6C0: addiu       $a2, $zero, 0x8B
    ctx->r6 = ADD32(0, 0X8B);
    func_80020D4C(rdram, ctx);
        goto after_7;
    // 0x8001F6C0: addiu       $a2, $zero, 0x8B
    ctx->r6 = ADD32(0, 0X8B);
    after_7:
    // 0x8001F6C4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001F6C8: lbu         $a3, -0x4559($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X4559);
    // 0x8001F6CC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8001F6D0: addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // 0x8001F6D4: jal         0x80020D4C
    // 0x8001F6D8: addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    func_80020D4C(rdram, ctx);
        goto after_8;
    // 0x8001F6D8: addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    after_8:
    // 0x8001F6DC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8001F6E0: lhu         $v1, 0x2876($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2876);
    // 0x8001F6E4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001F6E8: andi        $t6, $v1, 0x8
    ctx->r14 = ctx->r3 & 0X8;
    // 0x8001F6EC: beql        $t6, $zero, L_8001F72C
    if (ctx->r14 == 0) {
        // 0x8001F6F0: andi        $t6, $v1, 0x4
        ctx->r14 = ctx->r3 & 0X4;
            goto L_8001F72C;
    }
    goto skip_0;
    // 0x8001F6F0: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    skip_0:
    // 0x8001F6F4: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8001F6F8: lbu         $a0, 0x24($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X24);
    // 0x8001F6FC: slti        $at, $a0, 0x32
    ctx->r1 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // 0x8001F700: beq         $at, $zero, L_8001F728
    if (ctx->r1 == 0) {
        // 0x8001F704: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_8001F728;
    }
    // 0x8001F704: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8001F708: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001F70C: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x8001F710: sb          $t7, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r15;
    // 0x8001F714: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001F718: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001F71C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8001F720: b           L_8001F7E4
    // 0x8001F724: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8001F7E4;
    // 0x8001F724: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8001F728:
    // 0x8001F728: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
L_8001F72C:
    // 0x8001F72C: beq         $t6, $zero, L_8001F768
    if (ctx->r14 == 0) {
        // 0x8001F730: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_8001F768;
    }
    // 0x8001F730: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8001F734: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8001F738: lbu         $a0, 0x26($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X26);
    // 0x8001F73C: slti        $at, $a0, 0x32
    ctx->r1 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // 0x8001F740: beq         $at, $zero, L_8001F768
    if (ctx->r1 == 0) {
        // 0x8001F744: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_8001F768;
    }
    // 0x8001F744: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8001F748: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001F74C: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x8001F750: sb          $t7, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r15;
    // 0x8001F754: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001F758: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001F75C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8001F760: b           L_8001F7E4
    // 0x8001F764: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8001F7E4;
    // 0x8001F764: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8001F768:
    // 0x8001F768: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8001F76C: beql        $t6, $zero, L_8001F7AC
    if (ctx->r14 == 0) {
        // 0x8001F770: andi        $t6, $v1, 0x2
        ctx->r14 = ctx->r3 & 0X2;
            goto L_8001F7AC;
    }
    goto skip_1;
    // 0x8001F770: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    skip_1:
    // 0x8001F774: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8001F778: lbu         $a0, 0x27($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X27);
    // 0x8001F77C: slti        $at, $a0, 0x32
    ctx->r1 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // 0x8001F780: beq         $at, $zero, L_8001F7A8
    if (ctx->r1 == 0) {
        // 0x8001F784: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_8001F7A8;
    }
    // 0x8001F784: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8001F788: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001F78C: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x8001F790: sb          $t7, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r15;
    // 0x8001F794: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001F798: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001F79C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8001F7A0: b           L_8001F7E4
    // 0x8001F7A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8001F7E4;
    // 0x8001F7A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8001F7A8:
    // 0x8001F7A8: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
L_8001F7AC:
    // 0x8001F7AC: beq         $t6, $zero, L_8001F7E4
    if (ctx->r14 == 0) {
        // 0x8001F7B0: nop
    
            goto L_8001F7E4;
    }
    // 0x8001F7B0: nop

    // 0x8001F7B4: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8001F7B8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001F7BC: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x8001F7C0: lbu         $a0, 0x25($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X25);
    // 0x8001F7C4: slti        $at, $a0, 0x32
    ctx->r1 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // 0x8001F7C8: beq         $at, $zero, L_8001F7E4
    if (ctx->r1 == 0) {
        // 0x8001F7CC: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_8001F7E4;
    }
    // 0x8001F7CC: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x8001F7D0: sb          $t7, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r15;
    // 0x8001F7D4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8001F7D8: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8001F7DC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8001F7E0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8001F7E4:
    // 0x8001F7E4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001F7E8: addiu       $v1, $v1, -0x4D1C
    ctx->r3 = ADD32(ctx->r3, -0X4D1C);
    // 0x8001F7EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001F7F0: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x8001F7F4: bne         $t7, $zero, L_8001F808
    if (ctx->r15 != 0) {
        // 0x8001F7F8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001F808;
    }
    // 0x8001F7F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F7FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001F800: jal         0x800268D4
    // 0x8001F804: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_9;
    // 0x8001F804: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_9:
L_8001F808:
    // 0x8001F808: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F80C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001F810: jr          $ra
    // 0x8001F814: nop

    return;
    // 0x8001F814: nop

;}
RECOMP_FUNC void func_80013D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013D3C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80013D40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013D44: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x80013D48: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80013D4C: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x80013D50: lw          $t6, 0x64($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X64);
    // 0x80013D54: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80013D58: bnel        $t7, $at, L_80013D70
    if (ctx->r15 != ctx->r1) {
        // 0x80013D5C: lwc1        $f0, 0x4($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
            goto L_80013D70;
    }
    goto skip_0;
    // 0x80013D5C: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x80013D60: lw          $t8, 0x68($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X68);
    // 0x80013D64: b           L_80013D70
    // 0x80013D68: lwc1        $f0, 0x94($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X94);
        goto L_80013D70;
    // 0x80013D68: lwc1        $f0, 0x94($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X94);
    // 0x80013D6C: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
L_80013D70:
    // 0x80013D70: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80013D74: lwc1        $f8, 0x5C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x80013D78: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80013D7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80013D80: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80013D84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013D88: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80013D8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013D90: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80013D94: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80013D98: nop

    // 0x80013D9C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80013DA0: lwc1        $f18, 0x74($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80013DA4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80013DA8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80013DAC: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x80013DB0: lwc1        $f12, 0x34($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80013DB4: add.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80013DB8: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80013DBC: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x80013DC0: ldc1        $f8, 0x13F8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X13F8);
    // 0x80013DC4: mul.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80013DC8: nop

    // 0x80013DCC: mul.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80013DD0: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80013DD4: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x80013DD8: jr          $ra
    // 0x80013DDC: nop

    return;
    // 0x80013DDC: nop

;}
RECOMP_FUNC void func_800212A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800212A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800212A4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800212A8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800212AC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800212B0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800212B4: addiu       $a1, $a1, -0x2FF2
    ctx->r5 = ADD32(ctx->r5, -0X2FF2);
    // 0x800212B8: addiu       $v1, $v1, -0x3088
    ctx->r3 = ADD32(ctx->r3, -0X3088);
    // 0x800212BC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800212C0: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
L_800212C4:
    // 0x800212C4: beql        $v0, $t7, L_800212DC
    if (ctx->r2 == ctx->r15) {
        // 0x800212C8: sb          $a0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r4;
            goto L_800212DC;
    }
    goto skip_0;
    // 0x800212C8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    skip_0:
    // 0x800212CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800212D0: bnel        $v1, $a1, L_800212C4
    if (ctx->r3 != ctx->r5) {
        // 0x800212D4: lbu         $t7, 0x0($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X0);
            goto L_800212C4;
    }
    goto skip_1;
    // 0x800212D4: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    skip_1:
    // 0x800212D8: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
L_800212DC:
    // 0x800212DC: jr          $ra
    // 0x800212E0: nop

    return;
    // 0x800212E0: nop

;}
