#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80017FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017FA0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80017FA4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80017FA8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80017FAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80017FB0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80017FB4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80017FB8: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80017FBC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80017FC0: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x80017FC4: lh          $t1, 0x20($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X20);
    // 0x80017FC8: addiu       $v0, $v0, 0x71D0
    ctx->r2 = ADD32(ctx->r2, 0X71D0);
    // 0x80017FCC: bltzl       $t1, L_8001805C
    if (SIGNED(ctx->r9) < 0) {
        // 0x80017FD0: lhu         $t9, 0x0($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X0);
            goto L_8001805C;
    }
    goto skip_0;
    // 0x80017FD0: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
    skip_0:
    // 0x80017FD4: lwc1        $f4, 0x28($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80017FD8: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80017FDC: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80017FE0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80017FE4: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80017FE8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80017FEC: addiu       $t7, $t7, 0x1B90
    ctx->r15 = ADD32(ctx->r15, 0X1B90);
    // 0x80017FF0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80017FF4: lwc1        $f8, 0x1C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80017FF8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80017FFC: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x80018000: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80018004: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018008: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x8001800C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80018010: lhu         $a1, 0x24($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X24);
    // 0x80018014: lhu         $a0, 0x22($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X22);
    // 0x80018018: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8001801C: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80018020: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80018024: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80018028: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8001802C: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80018030: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80018034: jal         0x800177F8
    // 0x80018038: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_800177F8(rdram, ctx);
        goto after_0;
    // 0x80018038: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x8001803C: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80018040: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80018044: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x80018048: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8001804C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x80018050: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80018054: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x80018058: lhu         $t9, 0x0($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X0);
L_8001805C:
    // 0x8001805C: lhu         $t5, 0x2($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X2);
    // 0x80018060: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80018064: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80018068: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001806C: lw          $t4, 0x38F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X38F4);
    // 0x80018070: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80018074: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80018078: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001807C: addu        $t0, $t4, $t6
    ctx->r8 = ADD32(ctx->r12, ctx->r14);
    // 0x80018080: lhu         $a0, 0x4($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X4);
    // 0x80018084: beql        $a0, $zero, L_80018154
    if (ctx->r4 == 0) {
        // 0x80018088: lb          $a1, 0x44($v1)
        ctx->r5 = MEM_B(ctx->r3, 0X44);
            goto L_80018154;
    }
    goto skip_1;
    // 0x80018088: lb          $a1, 0x44($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X44);
    skip_1:
    // 0x8001808C: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x80018090: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80018094: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80018098: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8001809C: cvt.d.s     $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.d = CVT_D_S(ctx->f2.fl);
    // 0x800180A0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800180A4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800180A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800180AC: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800180B0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800180B4: nop

    // 0x800180B8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800180BC: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
    // 0x800180C0: beq         $a0, $at, L_800180DC
    if (ctx->r4 == ctx->r1) {
        // 0x800180C4: add.s       $f14, $f4, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
            goto L_800180DC;
    }
    // 0x800180C4: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800180C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800180CC: beq         $a0, $at, L_8001811C
    if (ctx->r4 == ctx->r1) {
        // 0x800180D0: nop
    
            goto L_8001811C;
    }
    // 0x800180D0: nop

    // 0x800180D4: b           L_80018154
    // 0x800180D8: lb          $a1, 0x44($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X44);
        goto L_80018154;
    // 0x800180D8: lb          $a1, 0x44($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X44);
L_800180DC:
    // 0x800180DC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800180E0: ldc1        $f18, 0x1518($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1518);
    // 0x800180E4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800180E8: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800180EC: mul.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800180F0: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    // 0x800180F4: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x800180F8: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800180FC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80018100: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80018104: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80018108: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8001810C: jal         0x80019354
    // 0x80018110: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80019354(rdram, ctx);
        goto after_1;
    // 0x80018110: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80018114: b           L_80018150
    // 0x80018118: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
        goto L_80018150;
    // 0x80018118: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_8001811C:
    // 0x8001811C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80018120: ldc1        $f10, 0x1520($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1520);
    // 0x80018124: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80018128: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    // 0x8001812C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80018130: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80018134: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80018138: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x8001813C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80018140: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80018144: jal         0x80019738
    // 0x80018148: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80019738(rdram, ctx);
        goto after_2;
    // 0x80018148: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8001814C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_80018150:
    // 0x80018150: lb          $a1, 0x44($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X44);
L_80018154:
    // 0x80018154: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80018158: bltzl       $a1, L_8001816C
    if (SIGNED(ctx->r5) < 0) {
        // 0x8001815C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001816C;
    }
    goto skip_2;
    // 0x8001815C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80018160: jal         0x800268D4
    // 0x80018164: lbu         $a0, 0x45($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X45);
    func_800268D4(rdram, ctx);
        goto after_3;
    // 0x80018164: lbu         $a0, 0x45($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X45);
    after_3:
    // 0x80018168: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001816C:
    // 0x8001816C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80018170: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80018174: jr          $ra
    // 0x80018178: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80018178: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80042CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042CA4: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x80042CA8: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x80042CAC: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x80042CB0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80042CB4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80042CB8: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x80042CBC: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x80042CC0: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x80042CC4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80042CC8: bgtzl       $v1, L_80042CD8
    if (SIGNED(ctx->r3) > 0) {
        // 0x80042CCC: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_80042CD8;
    }
    goto skip_0;
    // 0x80042CCC: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    skip_0:
    // 0x80042CD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80042CD4: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_80042CD8:
    // 0x80042CD8: bne         $at, $zero, L_80042CE4
    if (ctx->r1 != 0) {
        // 0x80042CDC: nop
    
            goto L_80042CE4;
    }
    // 0x80042CDC: nop

    // 0x80042CE0: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80042CE4:
    // 0x80042CE4: jr          $ra
    // 0x80042CE8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x80042CE8: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void func_8002E5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E5E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E5E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E5E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002E5EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002E5F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002E5F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002E5F8: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8002E5FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002E600:
    // 0x8002E600: jal         0x8002E628
    // 0x8002E604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002E628(rdram, ctx);
        goto after_0;
    // 0x8002E604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8002E608: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002E60C: bnel        $s0, $s1, L_8002E600
    if (ctx->r16 != ctx->r17) {
        // 0x8002E610: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002E600;
    }
    goto skip_0;
    // 0x8002E610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8002E614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E618: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002E61C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002E620: jr          $ra
    // 0x8002E624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002E624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80032218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032218: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003221C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80032220: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80032224: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80032228: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003222C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80032230: blez        $s2, L_80032274
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80032234: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80032274;
    }
    // 0x80032234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80032238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_8003223C:
    // 0x8003223C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80032240: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80032244: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x80032248: lbu         $a2, 0x4($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4);
    // 0x8003224C: lbu         $a3, 0x5($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X5);
    // 0x80032250: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80032254: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80032258: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8003225C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80032260: jal         0x80032040
    // 0x80032264: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80032040(rdram, ctx);
        goto after_0;
    // 0x80032264: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80032268: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003226C: bne         $s1, $s2, L_8003223C
    if (ctx->r17 != ctx->r18) {
        // 0x80032270: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8003223C;
    }
    // 0x80032270: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_80032274:
    // 0x80032274: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80032278: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003227C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80032280: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80032284: jr          $ra
    // 0x80032288: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80032288: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void nnScEventHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000710: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80000714: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80000718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000071C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000720: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80000724: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80000728: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000072C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80000730: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80000734: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80000738: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8000073C: addiu       $s1, $s1, -0x4D30
    ctx->r17 = ADD32(ctx->r17, -0X4D30);
    // 0x80000740: addiu       $s5, $s0, 0x74
    ctx->r21 = ADD32(ctx->r16, 0X74);
    // 0x80000744: addiu       $s4, $zero, 0x29D
    ctx->r20 = ADD32(0, 0X29D);
    // 0x80000748: addiu       $s3, $zero, 0x29A
    ctx->r19 = ADD32(0, 0X29A);
    // 0x8000074C: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x80000750: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80000754:
    // 0x80000754: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80000758: jal         0x80034020
    // 0x8000075C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000075C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80000760: lhu         $t6, 0x0($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X0);
    // 0x80000764: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80000768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000076C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80000770: beq         $t8, $s3, L_80000788
    if (ctx->r24 == ctx->r19) {
        // 0x80000774: sh          $t7, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r15;
            goto L_80000788;
    }
    // 0x80000774: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x80000778: beq         $t8, $s4, L_80000798
    if (ctx->r24 == ctx->r20) {
        // 0x8000077C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80000798;
    }
    // 0x8000077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80000780: b           L_80000754
    // 0x80000784: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80000754;
    // 0x80000784: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80000788:
    // 0x80000788: jal         0x800008B0
    // 0x8000078C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    nnScEventBroadcast(rdram, ctx);
        goto after_1;
    // 0x8000078C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80000790: b           L_80000754
    // 0x80000794: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80000754;
    // 0x80000794: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80000798:
    // 0x80000798: jal         0x800008B0
    // 0x8000079C: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    nnScEventBroadcast(rdram, ctx);
        goto after_2;
    // 0x8000079C: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    after_2:
    // 0x800007A0: b           L_80000754
    // 0x800007A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_80000754;
    // 0x800007A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800007A8: nop

    // 0x800007AC: nop

    // 0x800007B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800007B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800007B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800007BC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800007C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800007C4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800007C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800007CC: jr          $ra
    // 0x800007D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800007D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80101D0C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101D0C: sll         $t6, $a1, 0
    ctx->r14 = S32(ctx->r5 << 0);
    // 0x80101D10: bltz        $t6, L_80101D20
    if (SIGNED(ctx->r14) < 0) {
        // 0x80101D14: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_80101D20;
    }
    // 0x80101D14: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80101D18: jr          $ra
    // 0x80101D1C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101D1C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101D20:
    // 0x80101D20: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80101D24: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80101D28: addiu       $t8, $t8, 0x6250
    ctx->r24 = ADD32(ctx->r24, 0X6250);
    // 0x80101D2C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80101D30: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80101D34: lh          $v0, 0x2A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2A);
    // 0x80101D38: lh          $t1, 0x26($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X26);
    // 0x80101D3C: lw          $t2, 0x38($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X38);
    // 0x80101D40: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80101D44: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80101D48: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80101D4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101D50: lh          $t9, 0x24($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X24);
    // 0x80101D54: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80101D58: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80101D5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80101D60: sh          $t0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r8;
    // 0x80101D64: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80101D68: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80101D6C: div.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80101D70: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80101D74: nop

    // 0x80101D78: bc1fl       L_80101D88
    if (!c1cs) {
        // 0x80101D7C: lwc1        $f6, 0x1C($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_80101D88;
    }
    goto skip_0;
    // 0x80101D7C: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    skip_0:
    // 0x80101D80: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80101D84: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
L_80101D88:
    // 0x80101D88: lh          $a2, 0x4($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X4);
    // 0x80101D8C: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80101D90: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101D94: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80101D98: swc1        $f10, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f10.u32l;
    // 0x80101D9C: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80101DA0: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80101DA4: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80101DA8: beq         $at, $zero, L_80101DB8
    if (ctx->r1 == 0) {
        // 0x80101DAC: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80101DB8;
    }
    // 0x80101DAC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80101DB0: b           L_80101DBC
    // 0x80101DB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80101DBC;
    // 0x80101DB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80101DB8:
    // 0x80101DB8: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_80101DBC:
    // 0x80101DBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80101DC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80101DC4: addu        $t4, $a2, $a1
    ctx->r12 = ADD32(ctx->r6, ctx->r5);
    // 0x80101DC8: sh          $t4, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r12;
    // 0x80101DCC: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x80101DD0: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80101DD4: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x80101DD8: bc1fl       L_80101DF8
    if (!c1cs) {
        // 0x80101DDC: lh          $t5, 0x24($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X24);
            goto L_80101DF8;
    }
    goto skip_1;
    // 0x80101DDC: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
    skip_1:
    // 0x80101DE0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80101DE4: nop

    // 0x80101DE8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80101DEC: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80101DF0: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x80101DF4: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
L_80101DF8:
    // 0x80101DF8: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x80101DFC: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80101E00: bne         $at, $zero, L_80101E10
    if (ctx->r1 != 0) {
        // 0x80101E04: nop
    
            goto L_80101E10;
    }
    // 0x80101E04: nop

    // 0x80101E08: lh          $t7, 0x2A($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2A);
    // 0x80101E0C: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
L_80101E10:
    // 0x80101E10: beq         $t8, $zero, L_80101E34
    if (ctx->r24 == 0) {
        // 0x80101E14: nop
    
            goto L_80101E34;
    }
    // 0x80101E14: nop

    // 0x80101E18: lh          $v0, 0x2A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2A);
    // 0x80101E1C: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80101E20: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80101E24: bnel        $at, $zero, L_80101E58
    if (ctx->r1 != 0) {
        // 0x80101E28: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101E58;
    }
    goto skip_2;
    // 0x80101E28: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_2:
    // 0x80101E2C: b           L_80101E54
    // 0x80101E30: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
        goto L_80101E54;
    // 0x80101E30: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_80101E34:
    // 0x80101E34: beql        $t0, $zero, L_80101E58
    if (ctx->r8 == 0) {
        // 0x80101E38: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101E58;
    }
    goto skip_3;
    // 0x80101E38: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_3:
    // 0x80101E3C: lh          $v0, 0x2A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2A);
    // 0x80101E40: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x80101E44: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80101E48: bnel        $at, $zero, L_80101E58
    if (ctx->r1 != 0) {
        // 0x80101E4C: lh          $t2, 0x24($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X24);
            goto L_80101E58;
    }
    goto skip_4;
    // 0x80101E4C: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    skip_4:
    // 0x80101E50: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_80101E54:
    // 0x80101E54: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
L_80101E58:
    // 0x80101E58: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80101E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101E60: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80101E64: bne         $at, $zero, L_80101E84
    if (ctx->r1 != 0) {
        // 0x80101E68: nop
    
            goto L_80101E84;
    }
    // 0x80101E68: nop

    // 0x80101E6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101E70: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x80101E74: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101E78: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80101E7C: jr          $ra
    // 0x80101E80: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80101E80: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
L_80101E84:
    // 0x80101E84: jr          $ra
    // 0x80101E88: nop

    return;
    // 0x80101E88: nop

;}
RECOMP_FUNC void func_8002224C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002224C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80022250: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80022254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022258: jr          $ra
    // 0x8002225C: nop

    return;
    // 0x8002225C: nop

;}
RECOMP_FUNC void osSyncPrintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A7A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8003A7A4: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8003A7A8: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8003A7AC: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8003A7B0: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8003A7B4: jr          $ra
    // 0x8003A7B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8003A7B8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8001249C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001249C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800124A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800124A4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800124A8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800124AC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800124B0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800124B4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800124B8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800124BC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800124C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800124C4: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800124C8: lw          $s1, 0x6A00($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X6A00);
    // 0x800124CC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800124D0: addiu       $s0, $s0, 0x6A08
    ctx->r16 = ADD32(ctx->r16, 0X6A08);
    // 0x800124D4: beq         $s1, $zero, L_800125C8
    if (ctx->r17 == 0) {
        // 0x800124D8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800125C8;
    }
    // 0x800124D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800124DC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800124E0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800124E4: lui         $s4, 0x8005
    ctx->r20 = S32(0X8005 << 16);
    // 0x800124E8: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x800124EC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800124F0: addiu       $s3, $s3, -0x3858
    ctx->r19 = ADD32(ctx->r19, -0X3858);
    // 0x800124F4: addiu       $s4, $s4, -0x3458
    ctx->r20 = ADD32(ctx->r20, -0X3458);
    // 0x800124F8: ldc1        $f20, 0x12F0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X12F0);
    // 0x800124FC: addiu       $s2, $sp, 0x4C
    ctx->r18 = ADD32(ctx->r29, 0X4C);
L_80012500:
    // 0x80012500: lhu         $t6, 0x10($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X10);
    // 0x80012504: bnel        $t6, $zero, L_800125C0
    if (ctx->r14 != 0) {
        // 0x80012508: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800125C0;
    }
    goto skip_0;
    // 0x80012508: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x8001250C: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x80012510: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80012514: sh          $t8, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r24;
    // 0x80012518: lh          $v0, 0x12($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X12);
    // 0x8001251C: bltz        $v0, L_800125BC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80012520: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_800125BC;
    }
    // 0x80012520: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80012524: beq         $t9, $zero, L_800125BC
    if (ctx->r25 == 0) {
        // 0x80012528: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_800125BC;
    }
    // 0x80012528: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001252C: swc1        $f22, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f22.u32l;
    // 0x80012530: swc1        $f24, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f24.u32l;
    // 0x80012534: jal         0x800232F4
    // 0x80012538: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80012538: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    after_0:
    // 0x8001253C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80012540: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80012544: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80012548: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001254C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80012550: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80012554: swc1        $f8, -0x3440($at)
    MEM_W(-0X3440, ctx->r1) = ctx->f8.u32l;
    // 0x80012558: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8001255C: swc1        $f10, -0x343C($at)
    MEM_W(-0X343C, ctx->r1) = ctx->f10.u32l;
    // 0x80012560: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80012564: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80012568: swc1        $f4, -0x3438($at)
    MEM_W(-0X3438, ctx->r1) = ctx->f4.u32l;
    // 0x8001256C: lh          $t0, 0x12($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X12);
    // 0x80012570: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80012574: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80012578: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8001257C: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80012580: jal         0x8001B108
    // 0x80012584: sw          $t3, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = ctx->r11;
    func_8001B108(rdram, ctx);
        goto after_1;
    // 0x80012584: sw          $t3, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = ctx->r11;
    after_1:
    // 0x80012588: lh          $t4, 0x12($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X12);
    // 0x8001258C: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x80012590: bnel        $at, $zero, L_800125C0
    if (ctx->r1 != 0) {
        // 0x80012594: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_800125C0;
    }
    goto skip_1;
    // 0x80012594: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x80012598: jal         0x80022FD0
    // 0x8001259C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    get_rand(rdram, ctx);
        goto after_2;
    // 0x8001259C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x800125A0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800125A4: addiu       $t5, $v0, -0x3C
    ctx->r13 = ADD32(ctx->r2, -0X3C);
    // 0x800125A8: sh          $t5, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r13;
    // 0x800125AC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800125B0: add.d       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f10.d = ctx->f8.d + ctx->f20.d;
    // 0x800125B4: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800125B8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
L_800125BC:
    // 0x800125BC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_800125C0:
    // 0x800125C0: bne         $s1, $zero, L_80012500
    if (ctx->r17 != 0) {
        // 0x800125C4: addiu       $s0, $s0, 0x18
        ctx->r16 = ADD32(ctx->r16, 0X18);
            goto L_80012500;
    }
    // 0x800125C4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
L_800125C8:
    // 0x800125C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800125CC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800125D0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800125D4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800125D8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800125DC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800125E0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800125E4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800125E8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800125EC: jr          $ra
    // 0x800125F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800125F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800368AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800368AC: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800368B0: addiu       $v0, $v0, 0x990
    ctx->r2 = ADD32(ctx->r2, 0X990);
    // 0x800368B4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800368B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800368BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800368C0: bnel        $t6, $zero, L_800368D4
    if (ctx->r14 != 0) {
        // 0x800368C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800368D4;
    }
    goto skip_0;
    // 0x800368C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800368C8: jal         0x80036D00
    // 0x800368CC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    func_80036D00(rdram, ctx);
        goto after_0;
    // 0x800368CC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800368D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800368D4:
    // 0x800368D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800368D8: jr          $ra
    // 0x800368DC: nop

    return;
    // 0x800368DC: nop

;}
RECOMP_FUNC void func_80006720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006724: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80006728: lw          $a3, -0x3D90($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3D90);
    // 0x8000672C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006730: lh          $v1, 0x52($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X52);
    // 0x80006734: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80006738: addiu       $t7, $t7, 0x3F58
    ctx->r15 = ADD32(ctx->r15, 0X3F58);
    // 0x8000673C: beq         $a3, $v1, L_80006764
    if (ctx->r7 == ctx->r3) {
        // 0x80006740: sll         $t6, $v1, 3
        ctx->r14 = S32(ctx->r3 << 3);
            goto L_80006764;
    }
    // 0x80006740: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80006744: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80006748: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8000674C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80006750: lui         $at, 0x8005
    ctx->r1 = S32(0X8005 << 16);
    // 0x80006754: sw          $v1, -0x3D90($at)
    MEM_W(-0X3D90, ctx->r1) = ctx->r3;
    // 0x80006758: lui         $a1, 0x8020
    ctx->r5 = S32(0X8020 << 16);
    // 0x8000675C: jal         0x80024260
    // 0x80006760: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    dma_write(rdram, ctx);
        goto after_0;
    // 0x80006760: subu        $a2, $t8, $a0
    ctx->r6 = SUB32(ctx->r24, ctx->r4);
    after_0:
L_80006764:
    // 0x80006764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000676C: jr          $ra
    // 0x80006770: nop

    return;
    // 0x80006770: nop

;}
RECOMP_FUNC void func_800446C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800446C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800446C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800446C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800446CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800446D0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800446D4: beql        $t6, $zero, L_80044748
    if (ctx->r14 == 0) {
        // 0x800446D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044748;
    }
    goto skip_0;
    // 0x800446D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800446DC: jal         0x80036A30
    // 0x800446E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80036A30(rdram, ctx);
        goto after_0;
    // 0x800446E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800446E4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800446E8: beq         $v0, $zero, L_80044744
    if (ctx->r2 == 0) {
        // 0x800446EC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80044744;
    }
    // 0x800446EC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800446F0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800446F4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800446F8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800446FC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80044700: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x80044704: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x80044708: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8004470C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80044710: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x80044714: bgez        $v1, L_80044724
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044718: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_80044724;
    }
    // 0x80044718: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x8004471C: b           L_80044728
    // 0x80044720: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_80044728;
    // 0x80044720: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_80044724:
    // 0x80044724: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_80044728:
    // 0x80044728: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8004472C: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x80044730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80044734: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x80044738: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x8004473C: jalr        $t9
    // 0x80044740: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80044740: nop

    after_1:
L_80044744:
    // 0x80044744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044748:
    // 0x80044748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004474C: jr          $ra
    // 0x80044750: nop

    return;
    // 0x80044750: nop

    // 0x80044754: nop

    // 0x80044758: nop

    // 0x8004475C: nop

;}
RECOMP_FUNC void func_8004974C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004974C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80049750: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x80049754: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x80049758: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x8004975C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80049760: jr          $ra
    // 0x80049764: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x80049764: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80014A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014A98: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80014A9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80014AA0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80014AA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80014AA8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80014AAC: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80014AB0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80014AB4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80014AB8: addiu       $t7, $t7, -0x326C
    ctx->r15 = ADD32(ctx->r15, -0X326C);
    // 0x80014ABC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80014AC0: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x80014AC4: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80014AC8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80014ACC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80014AD0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80014AD4: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x80014AD8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80014ADC: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80014AE0: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80014AE4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014AE8: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80014AEC: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80014AF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80014AF4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80014AF8: bne         $t2, $zero, L_80014B2C
    if (ctx->r10 != 0) {
        // 0x80014AFC: lui         $a3, 0x800F
        ctx->r7 = S32(0X800F << 16);
            goto L_80014B2C;
    }
    // 0x80014AFC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80014B00: lw          $a0, -0x4CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4CC0);
    // 0x80014B04: jal         0x800111A4
    // 0x80014B08: addiu       $a3, $a3, -0x41C8
    ctx->r7 = ADD32(ctx->r7, -0X41C8);
    func_800111A4(rdram, ctx);
        goto after_0;
    // 0x80014B08: addiu       $a3, $a3, -0x41C8
    ctx->r7 = ADD32(ctx->r7, -0X41C8);
    after_0:
    // 0x80014B0C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014B10: addiu       $v0, $v0, 0x6F10
    ctx->r2 = ADD32(ctx->r2, 0X6F10);
    // 0x80014B14: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80014B18: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80014B1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014B20: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80014B24: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80014B28: sw          $t5, 0x6F14($at)
    MEM_W(0X6F14, ctx->r1) = ctx->r13;
L_80014B2C:
    // 0x80014B2C: srl         $a3, $s0, 8
    ctx->r7 = S32(U32(ctx->r16) >> 8);
    // 0x80014B30: andi        $t9, $a3, 0xF
    ctx->r25 = ctx->r7 & 0XF;
    // 0x80014B34: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80014B38: sll         $v0, $t9, 2
    ctx->r2 = S32(ctx->r25 << 2);
    // 0x80014B3C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80014B40: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80014B44: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80014B48: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80014B4C: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80014B50: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80014B54: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x80014B58: lw          $t8, 0x1B14($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1B14);
    // 0x80014B5C: lw          $t7, 0x3520($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3520);
    // 0x80014B60: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80014B64: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80014B68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80014B6C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80014B70: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80014B74: addu        $a2, $t8, $t6
    ctx->r6 = ADD32(ctx->r24, ctx->r14);
    // 0x80014B78: bne         $t2, $zero, L_80014BEC
    if (ctx->r10 != 0) {
        // 0x80014B7C: addu        $t0, $t7, $t1
        ctx->r8 = ADD32(ctx->r15, ctx->r9);
            goto L_80014BEC;
    }
    // 0x80014B7C: addu        $t0, $t7, $t1
    ctx->r8 = ADD32(ctx->r15, ctx->r9);
    // 0x80014B80: lhu         $a0, 0x20($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X20);
    // 0x80014B84: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80014B88: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80014B8C: bne         $at, $zero, L_80014BEC
    if (ctx->r1 != 0) {
        // 0x80014B90: addiu       $t5, $a0, -0x1
        ctx->r13 = ADD32(ctx->r4, -0X1);
            goto L_80014BEC;
    }
    // 0x80014B90: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x80014B94: lhu         $t3, 0x7170($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X7170);
    // 0x80014B98: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80014B9C: addiu       $v1, $v1, 0x7170
    ctx->r3 = ADD32(ctx->r3, 0X7170);
    // 0x80014BA0: beq         $t3, $zero, L_80014BC0
    if (ctx->r11 == 0) {
        // 0x80014BA4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80014BC0;
    }
    // 0x80014BA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80014BA8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80014BAC:
    // 0x80014BAC: beq         $v0, $zero, L_80014BC0
    if (ctx->r2 == 0) {
        // 0x80014BB0: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_80014BC0;
    }
    // 0x80014BB0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80014BB4: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x80014BB8: bnel        $t4, $zero, L_80014BAC
    if (ctx->r12 != 0) {
        // 0x80014BBC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80014BAC;
    }
    goto skip_0;
    // 0x80014BBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
L_80014BC0:
    // 0x80014BC0: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x80014BC4: lhu         $t9, 0x22($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X22);
    // 0x80014BC8: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80014BCC: sw          $s0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r16;
    // 0x80014BD0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80014BD4: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x80014BD8: lhu         $t6, 0x76($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X76);
    // 0x80014BDC: sw          $a2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r6;
    // 0x80014BE0: sh          $t6, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r14;
    // 0x80014BE4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80014BE8: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
L_80014BEC:
    // 0x80014BEC: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80014BF0: lhu         $t1, 0x6F1C($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X6F1C);
    // 0x80014BF4: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80014BF8: addiu       $s0, $s0, 0x6F18
    ctx->r16 = ADD32(ctx->r16, 0X6F18);
    // 0x80014BFC: beq         $t1, $zero, L_80014C1C
    if (ctx->r9 == 0) {
        // 0x80014C00: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80014C1C;
    }
    // 0x80014C00: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80014C04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80014C08:
    // 0x80014C08: beq         $v0, $zero, L_80014C1C
    if (ctx->r2 == 0) {
        // 0x80014C0C: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_80014C1C;
    }
    // 0x80014C0C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80014C10: lhu         $t2, 0x4($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X4);
    // 0x80014C14: bnel        $t2, $zero, L_80014C08
    if (ctx->r10 != 0) {
        // 0x80014C18: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80014C08;
    }
    goto skip_1;
    // 0x80014C18: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_1:
L_80014C1C:
    // 0x80014C1C: sh          $a3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r7;
    // 0x80014C20: sh          $a1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r5;
    // 0x80014C24: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80014C28: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80014C2C: sw          $a2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r6;
    // 0x80014C30: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x80014C34: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
    // 0x80014C38: lhu         $t4, 0xA($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0XA);
    // 0x80014C3C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80014C40: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80014C44: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x80014C48: lhu         $t5, 0x24($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X24);
    // 0x80014C4C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x80014C50: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
    // 0x80014C54: sh          $t5, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r13;
    // 0x80014C58: lhu         $t8, 0x76($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X76);
    // 0x80014C5C: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
    // 0x80014C60: jal         0x80018318
    // 0x80014C64: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    func_80018318(rdram, ctx);
        goto after_1;
    // 0x80014C64: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_1:
    // 0x80014C68: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80014C6C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80014C70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014C74: lhu         $v0, 0x12($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X12);
    // 0x80014C78: beql        $v0, $zero, L_80014C9C
    if (ctx->r2 == 0) {
        // 0x80014C7C: lhu         $t3, 0x2C($a2)
        ctx->r11 = MEM_HU(ctx->r6, 0X2C);
            goto L_80014C9C;
    }
    goto skip_2;
    // 0x80014C7C: lhu         $t3, 0x2C($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X2C);
    skip_2:
    // 0x80014C80: beq         $v0, $at, L_80014DA4
    if (ctx->r2 == ctx->r1) {
        // 0x80014C84: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80014DA4;
    }
    // 0x80014C84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80014C88: beql        $v0, $at, L_80014DA8
    if (ctx->r2 == ctx->r1) {
        // 0x80014C8C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80014DA8;
    }
    goto skip_3;
    // 0x80014C8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x80014C90: b           L_80014DBC
    // 0x80014C94: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
        goto L_80014DBC;
    // 0x80014C94: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80014C98: lhu         $t3, 0x2C($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X2C);
L_80014C9C:
    // 0x80014C9C: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80014CA0: lh          $t7, 0x30($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X30);
    // 0x80014CA4: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x80014CA8: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x80014CAC: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014CB0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80014CB4: addiu       $v0, $v0, 0x1B30
    ctx->r2 = ADD32(ctx->r2, 0X1B30);
    // 0x80014CB8: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x80014CBC: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80014CC0: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x80014CC4: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80014CC8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014CCC: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80014CD0: mflo        $t9
    ctx->r25 = lo;
    // 0x80014CD4: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x80014CD8: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80014CDC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80014CE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80014CE4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80014CE8: lhu         $t2, 0x2C($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X2C);
    // 0x80014CEC: lh          $t6, 0x30($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X30);
    // 0x80014CF0: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80014CF4: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x80014CF8: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014CFC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80014D00: addu        $t1, $a3, $t7
    ctx->r9 = ADD32(ctx->r7, ctx->r15);
    // 0x80014D04: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80014D08: mflo        $t5
    ctx->r13 = lo;
    // 0x80014D0C: addu        $t9, $v0, $t5
    ctx->r25 = ADD32(ctx->r2, ctx->r13);
    // 0x80014D10: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80014D14: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80014D18: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x80014D1C: lwc1        $f12, 0x10($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80014D20: jal         0x800232F4
    // 0x80014D24: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x80014D24: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_2:
    // 0x80014D28: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014D2C: addiu       $a1, $a1, 0x71D0
    ctx->r5 = ADD32(ctx->r5, 0X71D0);
    // 0x80014D30: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80014D34: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80014D38: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80014D3C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80014D40: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80014D44: lhu         $t6, 0x2A($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2A);
    // 0x80014D48: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80014D4C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80014D50: beql        $t7, $zero, L_80014D68
    if (ctx->r15 == 0) {
        // 0x80014D54: lhu         $t1, 0x2C($a2)
        ctx->r9 = MEM_HU(ctx->r6, 0X2C);
            goto L_80014D68;
    }
    goto skip_4;
    // 0x80014D54: lhu         $t1, 0x2C($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X2C);
    skip_4:
    // 0x80014D58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80014D5C: b           L_80014DB8
    // 0x80014D60: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
        goto L_80014DB8;
    // 0x80014D60: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80014D64: lhu         $t1, 0x2C($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X2C);
L_80014D68:
    // 0x80014D68: lh          $t9, 0x30($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X30);
    // 0x80014D6C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80014D70: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80014D74: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x80014D78: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80014D7C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80014D80: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80014D84: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80014D88: addu        $t6, $sp, $t8
    ctx->r14 = ADD32(ctx->r29, ctx->r24);
    // 0x80014D8C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80014D90: lwc1        $f8, 0x1B34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1B34);
    // 0x80014D94: lwc1        $f10, 0x3C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x80014D98: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80014D9C: b           L_80014DB8
    // 0x80014DA0: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
        goto L_80014DB8;
    // 0x80014DA0: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
L_80014DA4:
    // 0x80014DA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80014DA8:
    // 0x80014DA8: nop

    // 0x80014DAC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80014DB0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80014DB4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80014DB8:
    // 0x80014DB8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
L_80014DBC:
    // 0x80014DBC: lhu         $t7, 0x18($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X18);
    // 0x80014DC0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80014DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014DC8: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80014DCC: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80014DD0: lw          $t9, -0x3308($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3308);
    // 0x80014DD4: jalr        $t9
    // 0x80014DD8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80014DD8: nop

    after_3:
    // 0x80014DDC: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x80014DE0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80014DE4: beql        $t2, $zero, L_80014E6C
    if (ctx->r10 == 0) {
        // 0x80014DE8: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_80014E6C;
    }
    goto skip_5;
    // 0x80014DE8: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    skip_5:
    // 0x80014DEC: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80014DF0: lhu         $t3, 0x26($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X26);
    // 0x80014DF4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80014DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014DFC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80014E00: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80014E04: lw          $t9, -0x3330($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3330);
    // 0x80014E08: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80014E0C: jalr        $t9
    // 0x80014E10: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80014E10: nop

    after_4:
    // 0x80014E14: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80014E18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80014E1C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80014E20: lhu         $t5, 0x14($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X14);
    // 0x80014E24: addiu       $t8, $t8, 0x71E0
    ctx->r24 = ADD32(ctx->r24, 0X71E0);
    // 0x80014E28: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x80014E2C: bnel        $t5, $at, L_80014E58
    if (ctx->r13 != ctx->r1) {
        // 0x80014E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80014E58;
    }
    goto skip_6;
    // 0x80014E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x80014E34: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80014E38: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80014E3C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80014E40: jal         0x8000EE60
    // 0x80014E44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8000EE60(rdram, ctx);
        goto after_5;
    // 0x80014E44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
    // 0x80014E48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014E4C: lwc1        $f18, 0x71E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71E4);
    // 0x80014E50: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x80014E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80014E58:
    // 0x80014E58: jal         0x80017998
    // 0x80014E5C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    func_80017998(rdram, ctx);
        goto after_6;
    // 0x80014E5C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_6:
    // 0x80014E60: b           L_80014E70
    // 0x80014E64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80014E70;
    // 0x80014E64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80014E68: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_80014E6C:
    // 0x80014E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80014E70:
    // 0x80014E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80014E74: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80014E78: jr          $ra
    // 0x80014E7C: nop

    return;
    // 0x80014E7C: nop

;}
RECOMP_FUNC void func_8000FF54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FF54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FF58: ldc1        $f4, 0x1280($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1280);
    // 0x8000FF5C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x8000FF60: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FF64: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x8000FF68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000FF6C: bc1f        L_8000FF88
    if (!c1cs) {
        // 0x8000FF70: nop
    
            goto L_8000FF88;
    }
    // 0x8000FF70: nop

    // 0x8000FF74: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FF78: ldc1        $f6, 0x1288($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1288);
    // 0x8000FF7C: sub.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d - ctx->f6.d;
    // 0x8000FF80: b           L_8000FFAC
    // 0x8000FF84: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
        goto L_8000FFAC;
    // 0x8000FF84: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
L_8000FF88:
    // 0x8000FF88: ldc1        $f10, 0x1290($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1290);
    // 0x8000FF8C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FF90: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x8000FF94: nop

    // 0x8000FF98: bc1fl       L_8000FFB0
    if (!c1cs) {
        // 0x8000FF9C: c.lt.s      $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
            goto L_8000FFB0;
    }
    goto skip_0;
    // 0x8000FF9C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    skip_0:
    // 0x8000FFA0: ldc1        $f16, 0x1298($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1298);
    // 0x8000FFA4: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x8000FFA8: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
L_8000FFAC:
    // 0x8000FFAC: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
L_8000FFB0:
    // 0x8000FFB0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FFB4: bc1f        L_8000FFC0
    if (!c1cs) {
        // 0x8000FFB8: nop
    
            goto L_8000FFC0;
    }
    // 0x8000FFB8: nop

    // 0x8000FFBC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8000FFC0:
    // 0x8000FFC0: ldc1        $f8, 0x12A0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X12A0);
    // 0x8000FFC4: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8000FFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000FFCC: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8000FFD0: nop

    // 0x8000FFD4: bc1f        L_8000FFE0
    if (!c1cs) {
        // 0x8000FFD8: nop
    
            goto L_8000FFE0;
    }
    // 0x8000FFD8: nop

    // 0x8000FFDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000FFE0:
    // 0x8000FFE0: jr          $ra
    // 0x8000FFE4: nop

    return;
    // 0x8000FFE4: nop

;}
RECOMP_FUNC void func_8002B364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B364: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8002B368: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002B36C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002B370: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002B374: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002B378: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8002B37C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8002B380: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8002B384: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x8002B388: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8002B38C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002B390: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002B394: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002B398: lui         $t7, 0x3B9A
    ctx->r15 = S32(0X3B9A << 16);
    // 0x8002B39C: ori         $t7, $t7, 0xCA00
    ctx->r15 = ctx->r15 | 0XCA00;
    // 0x8002B3A0: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8002B3A4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8002B3A8: lui         $t0, 0x8006
    ctx->r8 = S32(0X8006 << 16);
    // 0x8002B3AC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x8002B3B0: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8002B3B4: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x8002B3B8: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8002B3BC: addiu       $t0, $t0, -0x674
    ctx->r8 = ADD32(ctx->r8, -0X674);
    // 0x8002B3C0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8002B3C4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8002B3C8: addiu       $t4, $sp, 0x5C
    ctx->r12 = ADD32(ctx->r29, 0X5C);
    // 0x8002B3CC: sw          $at, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r1;
    // 0x8002B3D0: lbu         $at, 0x4($t0)
    ctx->r1 = MEM_BU(ctx->r8, 0X4);
    // 0x8002B3D4: addu        $s0, $v0, $t4
    ctx->r16 = ADD32(ctx->r2, ctx->r12);
    // 0x8002B3D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002B3DC: sb          $at, 0x4($s6)
    MEM_B(0X4, ctx->r22) = ctx->r1;
    // 0x8002B3E0: slti        $at, $s3, 0xA
    ctx->r1 = SIGNED(ctx->r19) < 0XA ? 1 : 0;
    // 0x8002B3E4: bne         $at, $zero, L_8002B3F0
    if (ctx->r1 != 0) {
        // 0x8002B3E8: nop
    
            goto L_8002B3F0;
    }
    // 0x8002B3E8: nop

    // 0x8002B3EC: addiu       $s3, $zero, 0x9
    ctx->r19 = ADD32(0, 0X9);
L_8002B3F0:
    // 0x8002B3F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B3F4:
    // 0x8002B3F4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8002B3F8: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8002B3FC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8002B400: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x8002B404: subu        $t2, $t6, $t8
    ctx->r10 = SUB32(ctx->r14, ctx->r24);
    // 0x8002B408: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x8002B40C: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8002B410: subu        $t3, $t7, $t9
    ctx->r11 = SUB32(ctx->r15, ctx->r25);
    // 0x8002B414: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x8002B418: bgtz        $t2, L_8002B44C
    if (SIGNED(ctx->r10) > 0) {
        // 0x8002B41C: sw          $t2, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r10;
            goto L_8002B44C;
    }
    // 0x8002B41C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x8002B420: bltzl       $t2, L_8002B434
    if (SIGNED(ctx->r10) < 0) {
        // 0x8002B424: addu        $t1, $t3, $t9
        ctx->r9 = ADD32(ctx->r11, ctx->r25);
            goto L_8002B434;
    }
    goto skip_0;
    // 0x8002B424: addu        $t1, $t3, $t9
    ctx->r9 = ADD32(ctx->r11, ctx->r25);
    skip_0:
    // 0x8002B428: b           L_8002B3F4
    // 0x8002B42C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8002B3F4;
    // 0x8002B42C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B430: addu        $t1, $t3, $t9
    ctx->r9 = ADD32(ctx->r11, ctx->r25);
L_8002B434:
    // 0x8002B434: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x8002B438: addu        $t0, $at, $t2
    ctx->r8 = ADD32(ctx->r1, ctx->r10);
    // 0x8002B43C: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8002B440: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8002B444: b           L_8002B454
    // 0x8002B448: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
        goto L_8002B454;
    // 0x8002B448: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
L_8002B44C:
    // 0x8002B44C: b           L_8002B3F4
    // 0x8002B450: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8002B3F4;
    // 0x8002B450: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002B454:
    // 0x8002B454: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8002B458: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8002B45C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8002B460: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8002B464: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8002B468: jal         0x80039B38
    // 0x8002B46C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    __ull_div_recomp(rdram, ctx);
        goto after_0;
    // 0x8002B46C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x8002B470: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002B474: slti        $at, $s1, 0x9
    ctx->r1 = SIGNED(ctx->r17) < 0X9 ? 1 : 0;
    // 0x8002B478: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8002B47C: bne         $at, $zero, L_8002B3F0
    if (ctx->r1 != 0) {
        // 0x8002B480: sw          $v1, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r3;
            goto L_8002B3F0;
    }
    // 0x8002B480: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x8002B484: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x8002B488: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x8002B48C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002B490: bltz        $v1, L_8002B4E0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8002B494: sb          $t5, 0x5C($sp)
        MEM_B(0X5C, ctx->r29) = ctx->r13;
            goto L_8002B4E0;
    }
    // 0x8002B494: sb          $t5, 0x5C($sp)
    MEM_B(0X5C, ctx->r29) = ctx->r13;
    // 0x8002B498: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x8002B49C: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x8002B4A0: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x8002B4A4: addu        $s0, $v1, $t7
    ctx->r16 = ADD32(ctx->r3, ctx->r15);
L_8002B4A8:
    // 0x8002B4A8: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8002B4AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002B4B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8002B4B4: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8002B4B8: bne         $s1, $zero, L_8002B4C8
    if (ctx->r17 != 0) {
        // 0x8002B4BC: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_8002B4C8;
    }
    // 0x8002B4BC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8002B4C0: bnel        $s0, $s3, L_8002B4D4
    if (ctx->r16 != ctx->r19) {
        // 0x8002B4C4: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8002B4D4;
    }
    goto skip_1;
    // 0x8002B4C4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
L_8002B4C8:
    // 0x8002B4C8: jal         0x80030EA0
    // 0x8002B4CC: sb          $v0, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r2;
    func_80030EA0(rdram, ctx);
        goto after_1;
    // 0x8002B4CC: sb          $v0, 0x53($sp)
    MEM_B(0X53, ctx->r29) = ctx->r2;
    after_1:
    // 0x8002B4D0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8002B4D4:
    // 0x8002B4D4: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x8002B4D8: beq         $at, $zero, L_8002B4A8
    if (ctx->r1 == 0) {
        // 0x8002B4DC: addiu       $s2, $s2, 0xA
        ctx->r18 = ADD32(ctx->r18, 0XA);
            goto L_8002B4A8;
    }
    // 0x8002B4DC: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
L_8002B4E0:
    // 0x8002B4E0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8002B4E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002B4E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B4EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002B4F0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002B4F4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002B4F8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B4FC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002B500: jr          $ra
    // 0x8002B504: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8002B504: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8002B508: nop

    // 0x8002B50C: nop

;}
RECOMP_FUNC void func_8000ABF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ABF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000ABF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000ABFC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000AC00: lw          $t6, 0x68($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X68);
    // 0x8000AC04: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000AC08: lw          $t8, -0x44CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44CC);
    // 0x8000AC0C: lhu         $v0, 0x86($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X86);
    // 0x8000AC10: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8000AC14: lhu         $t9, 0x86($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X86);
    // 0x8000AC18: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000AC1C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8000AC20: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000AC24: addiu       $t0, $t9, 0x7
    ctx->r8 = ADD32(ctx->r25, 0X7);
    // 0x8000AC28: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8000AC2C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8000AC30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000AC34: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x8000AC38: div         $zero, $t7, $t2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r10)));
    // 0x8000AC3C: mflo        $t3
    ctx->r11 = lo;
    // 0x8000AC40: sh          $t3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r11;
    // 0x8000AC44: bne         $t2, $zero, L_8000AC50
    if (ctx->r10 != 0) {
        // 0x8000AC48: nop
    
            goto L_8000AC50;
    }
    // 0x8000AC48: nop

    // 0x8000AC4C: break       7
    do_break(2147527756);
L_8000AC50:
    // 0x8000AC50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000AC54: bne         $t2, $at, L_8000AC68
    if (ctx->r10 != ctx->r1) {
        // 0x8000AC58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000AC68;
    }
    // 0x8000AC58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000AC5C: bne         $t7, $at, L_8000AC68
    if (ctx->r15 != ctx->r1) {
        // 0x8000AC60: nop
    
            goto L_8000AC68;
    }
    // 0x8000AC60: nop

    // 0x8000AC64: break       6
    do_break(2147527780);
L_8000AC68:
    // 0x8000AC68: jal         0x80022FD0
    // 0x8000AC6C: nop

    get_rand(rdram, ctx);
        goto after_0;
    // 0x8000AC6C: nop

    after_0:
    // 0x8000AC70: lh          $t4, 0x1E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1E);
    // 0x8000AC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AC78: sltu        $v0, $v0, $t4
    ctx->r2 = ctx->r2 < ctx->r12 ? 1 : 0;
    // 0x8000AC7C: jr          $ra
    // 0x8000AC80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000AC80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80101080_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101080: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80101084: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80101088: sll         $t2, $t7, 2
    ctx->r10 = S32(ctx->r15 << 2);
    // 0x8010108C: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x80101090: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80101094: addiu       $t3, $t3, 0x6250
    ctx->r11 = ADD32(ctx->r11, 0X6250);
    // 0x80101098: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8010109C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x801010A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801010A4: lh          $t4, 0x12($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X12);
    // 0x801010A8: lh          $t5, 0x16($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X16);
    // 0x801010AC: sh          $zero, 0x30($v0)
    MEM_H(0X30, ctx->r2) = 0;
    // 0x801010B0: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
    // 0x801010B4: sh          $t5, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r13;
    // 0x801010B8: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x801010BC: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x801010C0: lh          $t8, 0x22($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X22);
    // 0x801010C4: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x801010C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801010CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801010D0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x801010D4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801010D8: lh          $t5, 0x30($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X30);
    // 0x801010DC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801010E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801010E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801010E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801010EC: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x801010F0: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    // 0x801010F4: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    // 0x801010F8: sh          $zero, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = 0;
    // 0x801010FC: sh          $t2, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r10;
    // 0x80101100: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x80101104: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x80101108: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x8010110C: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x80101110: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x80101114: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x80101118: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8010111C: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80101120: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80101124: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x80101128: sh          $t8, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r24;
    // 0x8010112C: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    // 0x80101130: sw          $t0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r8;
    // 0x80101134: sw          $t1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r9;
    // 0x80101138: sw          $t3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r11;
    // 0x8010113C: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
    // 0x80101140: jr          $ra
    // 0x80101144: sh          $t5, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r13;
    return;
    // 0x80101144: sh          $t5, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_8010107C_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010107C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101080: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101084: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80101088: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x8010108C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101090: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101094: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80101098: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x8010109C: bltzl       $t9, L_801010B0
    if (SIGNED(ctx->r25) < 0) {
        // 0x801010A0: lw          $v1, 0x38($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X38);
            goto L_801010B0;
    }
    goto skip_0;
    // 0x801010A0: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
    skip_0:
    // 0x801010A4: jr          $ra
    // 0x801010A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801010A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801010AC: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
L_801010B0:
    // 0x801010B0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801010B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801010B8: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x801010BC: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801010C0: lhu         $t0, 0x32($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X32);
    // 0x801010C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801010C8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801010CC: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x801010D0: sh          $t1, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r9;
    // 0x801010D4: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801010D8: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x801010DC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801010E0: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x801010E4: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801010E8: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x801010EC: nop

    // 0x801010F0: bc1tl       L_80101104
    if (c1cs) {
        // 0x801010F4: swc1        $f12, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
            goto L_80101104;
    }
    goto skip_1;
    // 0x801010F4: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
    skip_1:
    // 0x801010F8: bne         $at, $zero, L_80101108
    if (ctx->r1 != 0) {
        // 0x801010FC: nop
    
            goto L_80101108;
    }
    // 0x801010FC: nop

    // 0x80101100: swc1        $f12, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f12.u32l;
L_80101104:
    // 0x80101104: lwc1        $f2, 0x48($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X48);
L_80101108:
    // 0x80101108: bnel        $a1, $zero, L_80101124
    if (ctx->r5 != 0) {
        // 0x8010110C: sub.s       $f18, $f12, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80101124;
    }
    goto skip_2;
    // 0x8010110C: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
    // 0x80101110: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80101114: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80101118: b           L_80101134
    // 0x8010111C: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
        goto L_80101134;
    // 0x8010111C: sh          $t4, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r12;
    // 0x80101120: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
L_80101124:
    // 0x80101124: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80101128: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8010112C: nop

    // 0x80101130: sh          $t6, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r14;
L_80101134:
    // 0x80101134: lhu         $t7, 0x32($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X32);
    // 0x80101138: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
    // 0x8010113C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80101140: bnel        $at, $zero, L_80101178
    if (ctx->r1 != 0) {
        // 0x80101144: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80101178;
    }
    goto skip_3;
    // 0x80101144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80101148: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010114C: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x80101150: bne         $a1, $zero, L_80101168
    if (ctx->r5 != 0) {
        // 0x80101154: swc1        $f6, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
            goto L_80101168;
    }
    // 0x80101154: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80101158: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8010115C: sh          $t9, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r25;
    // 0x80101160: jr          $ra
    // 0x80101164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101168:
    // 0x80101168: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
    // 0x8010116C: jr          $ra
    // 0x80101170: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101170: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80101174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101178:
    // 0x80101178: jr          $ra
    // 0x8010117C: nop

    return;
    // 0x8010117C: nop

;}
RECOMP_FUNC void func_8000F6A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F6A4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000F6A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000F6AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000F6B0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8000F6B4: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8000F6B8: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F6BC: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F6C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000F6C4: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F6C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8000F6CC: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F6D0: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F6D4: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8000F6D8: bc1f        L_8000F6E8
    if (!c1cs) {
        // 0x8000F6DC: lwc1        $f4, 0x78($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
            goto L_8000F6E8;
    }
    // 0x8000F6DC: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000F6E0: b           L_8000F6E8
    // 0x8000F6E4: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
        goto L_8000F6E8;
    // 0x8000F6E4: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
L_8000F6E8:
    // 0x8000F6E8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8000F6EC: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F6F0: lwc1        $f20, 0x78($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000F6F4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000F6F8: bc1f        L_8000F708
    if (!c1cs) {
        // 0x8000F6FC: lwc1        $f8, 0x68($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
            goto L_8000F708;
    }
    // 0x8000F6FC: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000F700: b           L_8000F708
    // 0x8000F704: mov.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = ctx->f10.fl;
        goto L_8000F708;
    // 0x8000F704: mov.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = ctx->f10.fl;
L_8000F708:
    // 0x8000F708: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8000F70C: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000F710: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8000F714: bc1f        L_8000F724
    if (!c1cs) {
        // 0x8000F718: nop
    
            goto L_8000F724;
    }
    // 0x8000F718: nop

    // 0x8000F71C: b           L_8000F724
    // 0x8000F720: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8000F724;
    // 0x8000F720: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8000F724:
    // 0x8000F724: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8000F728: nop

    // 0x8000F72C: bc1f        L_8000F73C
    if (!c1cs) {
        // 0x8000F730: nop
    
            goto L_8000F73C;
    }
    // 0x8000F730: nop

    // 0x8000F734: b           L_8000F73C
    // 0x8000F738: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8000F73C;
    // 0x8000F738: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8000F73C:
    // 0x8000F73C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F740: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8000F744: nop

    // 0x8000F748: bc1t        L_8000F798
    if (c1cs) {
        // 0x8000F74C: nop
    
            goto L_8000F798;
    }
    // 0x8000F74C: nop

    // 0x8000F750: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8000F754: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8000F758: nop

    // 0x8000F75C: bc1t        L_8000F798
    if (c1cs) {
        // 0x8000F760: nop
    
            goto L_8000F798;
    }
    // 0x8000F760: nop

    // 0x8000F764: sub.s       $f6, $f20, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8000F768: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000F76C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8000F770: nop

    // 0x8000F774: bc1t        L_8000F798
    if (c1cs) {
        // 0x8000F778: nop
    
            goto L_8000F798;
    }
    // 0x8000F778: nop

    // 0x8000F77C: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8000F780: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F784: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F788: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8000F78C: nop

    // 0x8000F790: bc1fl       L_8000F7A4
    if (!c1cs) {
        // 0x8000F794: c.eq.s      $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
            goto L_8000F7A4;
    }
    goto skip_0;
    // 0x8000F794: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    skip_0:
L_8000F798:
    // 0x8000F798: b           L_8000FCA8
    // 0x8000F79C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FCA8;
    // 0x8000F79C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000F7A0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
L_8000F7A4:
    // 0x8000F7A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F7A8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000F7AC: bc1fl       L_8000F7C8
    if (!c1cs) {
        // 0x8000F7B0: c.eq.s      $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
            goto L_8000F7C8;
    }
    goto skip_1;
    // 0x8000F7B0: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    skip_1:
    // 0x8000F7B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000F7B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000F7BC: b           L_8000F818
    // 0x8000F7C0: neg.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = -ctx->f4.fl;
        goto L_8000F818;
    // 0x8000F7C0: neg.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = -ctx->f4.fl;
    // 0x8000F7C4: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
L_8000F7C8:
    // 0x8000F7C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F7CC: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000F7D0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8000F7D4: bc1fl       L_8000F7F0
    if (!c1cs) {
        // 0x8000F7D8: sub.s       $f4, $f10, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
            goto L_8000F7F0;
    }
    goto skip_2;
    // 0x8000F7D8: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    skip_2:
    // 0x8000F7DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000F7E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000F7E4: b           L_8000F818
    // 0x8000F7E8: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
        goto L_8000F818;
    // 0x8000F7E8: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
    // 0x8000F7EC: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
L_8000F7F0:
    // 0x8000F7F0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F7F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F7F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000F7FC: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8000F800: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F804: sub.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000F808: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000F80C: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8000F810: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8000F814: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
L_8000F818:
    // 0x8000F818: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8000F81C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000F820: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8000F824: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8000F828: add.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8000F82C: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x8000F830: nop

    // 0x8000F834: bc1f        L_8000F840
    if (!c1cs) {
        // 0x8000F838: nop
    
            goto L_8000F840;
    }
    // 0x8000F838: nop

    // 0x8000F83C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_8000F840:
    // 0x8000F840: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000F844: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x8000F848: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8000F84C: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8000F850: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000F854: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x8000F858: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x8000F85C: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x8000F860: jal         0x80034F60
    // 0x8000F864: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_0;
    // 0x8000F864: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_0:
    // 0x8000F868: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000F86C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000F870: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8000F874: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000F878: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000F87C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8000F880: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8000F884: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8000F888: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8000F88C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8000F890: bc1fl       L_8000FCA8
    if (!c1cs) {
        // 0x8000F894: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000FCA8;
    }
    goto skip_3;
    // 0x8000F894: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_3:
    // 0x8000F898: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000F89C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F8A0: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x8000F8A4: nop

    // 0x8000F8A8: bc1fl       L_8000F8D4
    if (!c1cs) {
        // 0x8000F8AC: c.eq.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
            goto L_8000F8D4;
    }
    goto skip_4;
    // 0x8000F8AC: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    skip_4:
    // 0x8000F8B0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F8B4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000F8B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000F8BC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000F8C0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8000F8C4: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    // 0x8000F8C8: b           L_8000F938
    // 0x8000F8CC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
        goto L_8000F938;
    // 0x8000F8CC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8000F8D0: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
L_8000F8D4:
    // 0x8000F8D4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8000F8D8: bc1fl       L_8000F908
    if (!c1cs) {
        // 0x8000F8DC: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8000F908;
    }
    goto skip_5;
    // 0x8000F8DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_5:
    // 0x8000F8E0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000F8E4: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F8E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F8EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000F8F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000F8F4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8000F8F8: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    // 0x8000F8FC: b           L_8000F938
    // 0x8000F900: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
        goto L_8000F938;
    // 0x8000F900: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8000F904: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8000F908:
    // 0x8000F908: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F90C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000F910: div.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8000F914: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8000F918: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000F91C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000F920: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000F924: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8000F928: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000F92C: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8000F930: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8000F934: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
L_8000F938:
    // 0x8000F938: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8000F93C: nop

    // 0x8000F940: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8000F944: nop

    // 0x8000F948: mul.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8000F94C: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F950: mul.s       $f6, $f20, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x8000F954: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F958: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8000F95C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8000F960: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8000F964: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000F968: mul.s       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8000F96C: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F970: div.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000F974: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8000F978: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F97C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F980: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x8000F984: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8000F988: div.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000F98C: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8000F990: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000F994: bc1f        L_8000F9A8
    if (!c1cs) {
        // 0x8000F998: swc1        $f4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
            goto L_8000F9A8;
    }
    // 0x8000F998: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8000F99C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x8000F9A0: b           L_8000F9A8
    // 0x8000F9A4: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
        goto L_8000F9A8;
    // 0x8000F9A4: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
L_8000F9A8:
    // 0x8000F9A8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8000F9AC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000F9B0: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000F9B4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000F9B8: bc1f        L_8000F9C8
    if (!c1cs) {
        // 0x8000F9BC: nop
    
            goto L_8000F9C8;
    }
    // 0x8000F9BC: nop

    // 0x8000F9C0: b           L_8000F9C8
    // 0x8000F9C4: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
        goto L_8000F9C8;
    // 0x8000F9C4: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_8000F9C8:
    // 0x8000F9C8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8000F9CC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000F9D0: bc1fl       L_8000F9E4
    if (!c1cs) {
        // 0x8000F9D4: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_8000F9E4;
    }
    goto skip_6;
    // 0x8000F9D4: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    skip_6:
    // 0x8000F9D8: b           L_8000F9E4
    // 0x8000F9DC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8000F9E4;
    // 0x8000F9DC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8000F9E0: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_8000F9E4:
    // 0x8000F9E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8000F9E8: nop

    // 0x8000F9EC: bc1fl       L_8000FA00
    if (!c1cs) {
        // 0x8000F9F0: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8000FA00;
    }
    goto skip_7;
    // 0x8000F9F0: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    skip_7:
    // 0x8000F9F4: b           L_8000FA00
    // 0x8000F9F8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8000FA00;
    // 0x8000F9F8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8000F9FC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
L_8000FA00:
    // 0x8000FA00: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8000FA04: nop

    // 0x8000FA08: bc1tl       L_8000FA44
    if (c1cs) {
        // 0x8000FA0C: sub.s       $f18, $f4, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
            goto L_8000FA44;
    }
    goto skip_8;
    // 0x8000FA0C: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    skip_8:
    // 0x8000FA10: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8000FA14: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000FA18: bc1tl       L_8000FA44
    if (c1cs) {
        // 0x8000FA1C: sub.s       $f18, $f4, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
            goto L_8000FA44;
    }
    goto skip_9;
    // 0x8000FA1C: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    skip_9:
    // 0x8000FA20: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8000FA24: nop

    // 0x8000FA28: bc1tl       L_8000FA44
    if (c1cs) {
        // 0x8000FA2C: sub.s       $f18, $f4, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
            goto L_8000FA44;
    }
    goto skip_10;
    // 0x8000FA2C: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    skip_10:
    // 0x8000FA30: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x8000FA34: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000FA38: bc1fl       L_8000FC0C
    if (!c1cs) {
        // 0x8000FA3C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8000FC0C;
    }
    goto skip_11;
    // 0x8000FA3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_11:
    // 0x8000FA40: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
L_8000FA44:
    // 0x8000FA44: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8000FA48: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000FA4C: sub.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8000FA50: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000FA54: nop

    // 0x8000FA58: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8000FA5C: jal         0x80034F60
    // 0x8000FA60: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    _nsqrtf(rdram, ctx);
        goto after_1;
    // 0x8000FA60: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_1:
    // 0x8000FA64: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000FA68: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000FA6C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8000FA70: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8000FA74: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8000FA78: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000FA7C: bc1fl       L_8000FB20
    if (!c1cs) {
        // 0x8000FA80: lwc1        $f8, 0x0($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8000FB20;
    }
    goto skip_12;
    // 0x8000FA80: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    skip_12:
    // 0x8000FA84: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000FA88: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000FA8C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8000FA90: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000FA94: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000FA98: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000FA9C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8000FAA0: sub.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000FAA4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000FAA8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8000FAAC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000FAB0: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x8000FAB4: jal         0x80034F60
    // 0x8000FAB8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    _nsqrtf(rdram, ctx);
        goto after_2;
    // 0x8000FAB8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_2:
    // 0x8000FABC: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000FAC0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FAC4: ldc1        $f6, 0x1268($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1268);
    // 0x8000FAC8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8000FACC: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x8000FAD0: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x8000FAD4: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000FAD8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000FADC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8000FAE0: sub.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d - ctx->f4.d;
    // 0x8000FAE4: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000FAE8: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000FAEC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8000FAF0: div.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x8000FAF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000FAF8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8000FAFC: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000FB00: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000FB04: mul.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000FB08: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8000FB0C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000FB10: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8000FB14: b           L_8000FCA8
    // 0x8000FB18: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
        goto L_8000FCA8;
    // 0x8000FB18: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8000FB1C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
L_8000FB20:
    // 0x8000FB20: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000FB24: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000FB28: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000FB2C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000FB30: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8000FB34: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000FB38: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000FB3C: nop

    // 0x8000FB40: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8000FB44: jal         0x80034F60
    // 0x8000FB48: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    _nsqrtf(rdram, ctx);
        goto after_3;
    // 0x8000FB48: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_3:
    // 0x8000FB4C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000FB50: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000FB54: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8000FB58: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8000FB5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8000FB60: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000FB64: bc1f        L_8000FC00
    if (!c1cs) {
        // 0x8000FB68: nop
    
            goto L_8000FC00;
    }
    // 0x8000FB68: nop

    // 0x8000FB6C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000FB70: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8000FB74: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000FB78: sub.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8000FB7C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000FB80: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8000FB84: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8000FB88: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000FB8C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8000FB90: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000FB94: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x8000FB98: jal         0x80034F60
    // 0x8000FB9C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_4;
    // 0x8000FB9C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_4:
    // 0x8000FBA0: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000FBA4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FBA8: ldc1        $f10, 0x1270($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1270);
    // 0x8000FBAC: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8000FBB0: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x8000FBB4: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x8000FBB8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000FBBC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000FBC0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8000FBC4: sub.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f6.d - ctx->f8.d;
    // 0x8000FBC8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000FBCC: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000FBD0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8000FBD4: div.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x8000FBD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000FBDC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8000FBE0: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000FBE4: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8000FBE8: mul.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000FBEC: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8000FBF0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000FBF4: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000FBF8: b           L_8000FCA8
    // 0x8000FBFC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8000FCA8;
    // 0x8000FBFC: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8000FC00:
    // 0x8000FC00: b           L_8000FCA8
    // 0x8000FC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FCA8;
    // 0x8000FC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000FC08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8000FC0C:
    // 0x8000FC0C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000FC10: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000FC14: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x8000FC18: sub.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8000FC1C: bc1t        L_8000FCA0
    if (c1cs) {
        // 0x8000FC20: sub.s       $f14, $f16, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f6.fl;
            goto L_8000FCA0;
    }
    // 0x8000FC20: sub.s       $f14, $f16, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8000FC24: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000FC28: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8000FC2C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000FC30: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000FC34: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8000FC38: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x8000FC3C: jal         0x80034F60
    // 0x8000FC40: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    _nsqrtf(rdram, ctx);
        goto after_5;
    // 0x8000FC40: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_5:
    // 0x8000FC44: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000FC48: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000FC4C: ldc1        $f10, 0x1278($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1278);
    // 0x8000FC50: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8000FC54: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000FC58: add.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d + ctx->f10.d;
    // 0x8000FC5C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000FC60: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8000FC64: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8000FC68: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8000FC6C: sub.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d - ctx->f4.d;
    // 0x8000FC70: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000FC74: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000FC78: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8000FC7C: div.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f8.d);
    // 0x8000FC80: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x8000FC84: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000FC88: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000FC8C: mul.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8000FC90: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8000FC94: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000FC98: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8000FC9C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_8000FCA0:
    // 0x8000FCA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000FCA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000FCA8:
    // 0x8000FCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FCAC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000FCB0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8000FCB4: jr          $ra
    // 0x8000FCB8: nop

    return;
    // 0x8000FCB8: nop

;}
RECOMP_FUNC void func_8000A3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A3F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A3F8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8000A3FC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8000A400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A404: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000A408: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000A40C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000A410: sub.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8000A414: jal         0x80023210
    // 0x8000A418: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x8000A418: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    after_0:
    // 0x8000A41C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A420: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A424: ldc1        $f16, 0x1160($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1160);
    // 0x8000A428: lwc1        $f14, 0x10($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000A42C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A430: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8000A434: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x8000A438: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x8000A43C: nop

    // 0x8000A440: bc1f        L_8000A460
    if (!c1cs) {
        // 0x8000A444: nop
    
            goto L_8000A460;
    }
    // 0x8000A444: nop

    // 0x8000A448: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A44C: ldc1        $f18, 0x1168($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1168);
    // 0x8000A450: sub.d       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f2.d - ctx->f18.d;
    // 0x8000A454: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x8000A458: b           L_8000A488
    // 0x8000A45C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
        goto L_8000A488;
    // 0x8000A45C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_8000A460:
    // 0x8000A460: ldc1        $f10, 0x1170($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X1170);
    // 0x8000A464: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A468: c.lt.d      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.d < ctx->f10.d;
    // 0x8000A46C: nop

    // 0x8000A470: bc1f        L_8000A488
    if (!c1cs) {
        // 0x8000A474: nop
    
            goto L_8000A488;
    }
    // 0x8000A474: nop

    // 0x8000A478: ldc1        $f18, 0x1178($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1178);
    // 0x8000A47C: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x8000A480: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x8000A484: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
L_8000A488:
    // 0x8000A488: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A48C: ldc1        $f18, 0x1180($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1180);
    // 0x8000A490: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A494: ldc1        $f8, 0x1188($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1188);
    // 0x8000A498: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x8000A49C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000A4A0: mul.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x8000A4A4: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x8000A4A8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8000A4AC: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x8000A4B0: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000A4B4: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8000A4B8: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x8000A4BC: nop

    // 0x8000A4C0: bc1f        L_8000A4D8
    if (!c1cs) {
        // 0x8000A4C4: nop
    
            goto L_8000A4D8;
    }
    // 0x8000A4C4: nop

    // 0x8000A4C8: sub.d       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f0.d - ctx->f18.d;
    // 0x8000A4CC: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8000A4D0: b           L_8000A4F8
    // 0x8000A4D4: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
        goto L_8000A4F8;
    // 0x8000A4D4: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
L_8000A4D8:
    // 0x8000A4D8: ldc1        $f8, 0x1190($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1190);
    // 0x8000A4DC: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8000A4E0: nop

    // 0x8000A4E4: bc1fl       L_8000A4FC
    if (!c1cs) {
        // 0x8000A4E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000A4FC;
    }
    goto skip_0;
    // 0x8000A4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000A4EC: add.d       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f0.d + ctx->f18.d;
    // 0x8000A4F0: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x8000A4F4: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
L_8000A4F8:
    // 0x8000A4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000A4FC:
    // 0x8000A4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A500: jr          $ra
    // 0x8000A504: nop

    return;
    // 0x8000A504: nop

;}
RECOMP_FUNC void func_80022F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022F60: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80022F64: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80022F68: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80022F6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022F70: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80022F74: mul.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80022F78: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80022F7C: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80022F80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80022F84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80022F88: cvt.d.s     $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.d = CVT_D_S(ctx->f2.fl);
    // 0x80022F8C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80022F90: sub.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d - ctx->f14.d;
    // 0x80022F94: sub.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = ctx->f10.d - ctx->f14.d;
    // 0x80022F98: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
    // 0x80022F9C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80022FA0: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x80022FA4: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80022FA8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80022FAC: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80022FB0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80022FB4: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x80022FB8: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80022FBC: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80022FC0: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x80022FC4: jr          $ra
    // 0x80022FC8: nop

    return;
    // 0x80022FC8: nop

    // 0x80022FCC: nop

;}
RECOMP_FUNC void func_80029448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029448: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002944C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80029450: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80029454: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80029458: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8002945C: addiu       $t6, $zero, 0x9F
    ctx->r14 = ADD32(0, 0X9F);
    // 0x80029460: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80029464: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029468: addiu       $a1, $s1, 0x28
    ctx->r5 = ADD32(ctx->r17, 0X28);
    // 0x8002946C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80029470: jal         0x80029B58
    // 0x80029474: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    func_80029B58(rdram, ctx);
        goto after_0;
    // 0x80029474: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_0:
    // 0x80029478: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002947C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029480: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80029484: addiu       $a1, $s1, 0x2B
    ctx->r5 = ADD32(ctx->r17, 0X2B);
    // 0x80029488: addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // 0x8002948C: jal         0x80029B58
    // 0x80029490: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    func_80029B58(rdram, ctx);
        goto after_1;
    // 0x80029490: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_1:
    // 0x80029494: addiu       $t8, $zero, 0x9A
    ctx->r24 = ADD32(0, 0X9A);
    // 0x80029498: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002949C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x800294A0: addiu       $a1, $s1, 0x119
    ctx->r5 = ADD32(ctx->r17, 0X119);
    // 0x800294A4: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x800294A8: jal         0x80029B58
    // 0x800294AC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x800294AC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x800294B0: addiu       $s0, $s1, 0x27
    ctx->r16 = ADD32(ctx->r17, 0X27);
    // 0x800294B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800294B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800294BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800294C0: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x800294C4: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x800294C8: jal         0x80029B58
    // 0x800294CC: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x800294CC: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_3:
    // 0x800294D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800294D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800294D8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x800294DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800294E0: addiu       $a2, $zero, 0xBD
    ctx->r6 = ADD32(0, 0XBD);
    // 0x800294E4: jal         0x80029B58
    // 0x800294E8: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_4;
    // 0x800294E8: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_4:
    // 0x800294EC: addiu       $t2, $zero, 0x9F
    ctx->r10 = ADD32(0, 0X9F);
    // 0x800294F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800294F4: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x800294F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800294FC: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80029500: jal         0x80029B58
    // 0x80029504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x80029504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80029508: addiu       $t3, $zero, 0x9F
    ctx->r11 = ADD32(0, 0X9F);
    // 0x8002950C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80029510: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80029514: addiu       $a1, $s1, 0x118
    ctx->r5 = ADD32(ctx->r17, 0X118);
    // 0x80029518: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8002951C: jal         0x80029B58
    // 0x80029520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x80029520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80029524: addiu       $s0, $s1, 0x29
    ctx->r16 = ADD32(ctx->r17, 0X29);
    // 0x80029528: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002952C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80029530: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029534: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80029538: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8002953C: jal         0x80029B58
    // 0x80029540: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x80029540: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    after_7:
    // 0x80029544: addiu       $t5, $zero, 0x9B
    ctx->r13 = ADD32(0, 0X9B);
    // 0x80029548: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002954C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80029550: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029554: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80029558: jal         0x80029B58
    // 0x8002955C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_8;
    // 0x8002955C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80029560: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80029564: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80029568: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8002956C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029570: addiu       $a2, $zero, 0xBB
    ctx->r6 = ADD32(0, 0XBB);
    // 0x80029574: jal         0x80029B58
    // 0x80029578: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    func_80029B58(rdram, ctx);
        goto after_9;
    // 0x80029578: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    after_9:
    // 0x8002957C: addiu       $t7, $zero, 0x9C
    ctx->r15 = ADD32(0, 0X9C);
    // 0x80029580: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029584: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80029588: addiu       $a1, $s1, 0x116
    ctx->r5 = ADD32(ctx->r17, 0X116);
    // 0x8002958C: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80029590: jal         0x80029B58
    // 0x80029594: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_10;
    // 0x80029594: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80029598: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8002959C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800295A0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800295A4: addiu       $a1, $s1, 0x45
    ctx->r5 = ADD32(ctx->r17, 0X45);
    // 0x800295A8: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x800295AC: jal         0x80029B58
    // 0x800295B0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_80029B58(rdram, ctx);
        goto after_11;
    // 0x800295B0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_11:
    // 0x800295B4: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800295B8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800295BC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800295C0: addiu       $a1, $s1, 0xF3
    ctx->r5 = ADD32(ctx->r17, 0XF3);
    // 0x800295C4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x800295C8: jal         0x80029B58
    // 0x800295CC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_80029B58(rdram, ctx);
        goto after_12;
    // 0x800295CC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_12:
    // 0x800295D0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x800295D4: lw          $s0, -0x2F0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2F0);
    // 0x800295D8: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x800295DC: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800295E0: sra         $t1, $s0, 2
    ctx->r9 = S32(SIGNED(ctx->r16) >> 2);
    // 0x800295E4: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x800295E8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800295EC: lb          $s0, -0xF40($at)
    ctx->r16 = MEM_B(ctx->r1, -0XF40);
    // 0x800295F0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800295F4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800295F8: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x800295FC: addiu       $a1, $a1, 0x36
    ctx->r5 = ADD32(ctx->r5, 0X36);
    // 0x80029600: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80029604: jal         0x80029B58
    // 0x80029608: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80029B58(rdram, ctx);
        goto after_13;
    // 0x80029608: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_13:
    // 0x8002960C: subu        $a1, $s1, $s0
    ctx->r5 = SUB32(ctx->r17, ctx->r16);
    // 0x80029610: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80029614: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80029618: addiu       $a1, $a1, 0xFB
    ctx->r5 = ADD32(ctx->r5, 0XFB);
    // 0x8002961C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80029620: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80029624: jal         0x80029B58
    // 0x80029628: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80029B58(rdram, ctx);
        goto after_14;
    // 0x80029628: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_14:
    // 0x8002962C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x80029630: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80029634: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80029638: addiu       $a1, $s1, 0x81
    ctx->r5 = ADD32(ctx->r17, 0X81);
    // 0x8002963C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80029640: jal         0x80029B58
    // 0x80029644: addiu       $a3, $zero, 0x3A
    ctx->r7 = ADD32(0, 0X3A);
    func_80029B58(rdram, ctx);
        goto after_15;
    // 0x80029644: addiu       $a3, $zero, 0x3A
    ctx->r7 = ADD32(0, 0X3A);
    after_15:
    // 0x80029648: addiu       $s0, $s1, 0xA5
    ctx->r16 = ADD32(ctx->r17, 0XA5);
    // 0x8002964C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80029650: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80029654: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029658: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8002965C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x80029660: jal         0x80029B58
    // 0x80029664: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    func_80029B58(rdram, ctx);
        goto after_16;
    // 0x80029664: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    after_16:
    // 0x80029668: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8002966C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029670: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80029674: addiu       $a1, $s1, 0x31
    ctx->r5 = ADD32(ctx->r17, 0X31);
    // 0x80029678: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8002967C: jal         0x80029B58
    // 0x80029680: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    func_80029B58(rdram, ctx);
        goto after_17;
    // 0x80029680: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    after_17:
    // 0x80029684: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80029688: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8002968C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80029690: addiu       $a1, $s1, 0xD9
    ctx->r5 = ADD32(ctx->r17, 0XD9);
    // 0x80029694: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x80029698: jal         0x80029B58
    // 0x8002969C: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    func_80029B58(rdram, ctx);
        goto after_18;
    // 0x8002969C: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    after_18:
    // 0x800296A0: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800296A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800296A8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800296AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800296B0: addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    // 0x800296B4: jal         0x80029B58
    // 0x800296B8: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    func_80029B58(rdram, ctx);
        goto after_19;
    // 0x800296B8: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    after_19:
    // 0x800296BC: addiu       $s0, $s1, 0x86
    ctx->r16 = ADD32(ctx->r17, 0X86);
    // 0x800296C0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800296C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800296C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800296CC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800296D0: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x800296D4: jal         0x80029B58
    // 0x800296D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_20;
    // 0x800296D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_20:
    // 0x800296DC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800296E0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800296E4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800296E8: addiu       $a1, $s1, 0x47
    ctx->r5 = ADD32(ctx->r17, 0X47);
    // 0x800296EC: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // 0x800296F0: jal         0x80029B58
    // 0x800296F4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_21;
    // 0x800296F4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_21:
    // 0x800296F8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800296FC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80029700: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80029704: addiu       $a1, $s1, 0xF0
    ctx->r5 = ADD32(ctx->r17, 0XF0);
    // 0x80029708: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // 0x8002970C: jal         0x80029B58
    // 0x80029710: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_22;
    // 0x80029710: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_22:
    // 0x80029714: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80029718: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8002971C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80029720: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029724: addiu       $a2, $zero, 0xAD
    ctx->r6 = ADD32(0, 0XAD);
    // 0x80029728: jal         0x80029B58
    // 0x8002972C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_23;
    // 0x8002972C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_23:
    // 0x80029730: addiu       $s0, $s1, 0x9A
    ctx->r16 = ADD32(ctx->r17, 0X9A);
    // 0x80029734: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80029738: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002973C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029740: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80029744: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // 0x80029748: jal         0x80029B58
    // 0x8002974C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80029B58(rdram, ctx);
        goto after_24;
    // 0x8002974C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_24:
    // 0x80029750: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80029754: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80029758: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x8002975C: addiu       $a1, $s1, 0x67
    ctx->r5 = ADD32(ctx->r17, 0X67);
    // 0x80029760: addiu       $a2, $zero, 0x6F
    ctx->r6 = ADD32(0, 0X6F);
    // 0x80029764: jal         0x80029B58
    // 0x80029768: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80029B58(rdram, ctx);
        goto after_25;
    // 0x80029768: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_25:
    // 0x8002976C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80029770: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029774: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80029778: addiu       $a1, $s1, 0xCC
    ctx->r5 = ADD32(ctx->r17, 0XCC);
    // 0x8002977C: addiu       $a2, $zero, 0x6F
    ctx->r6 = ADD32(0, 0X6F);
    // 0x80029780: jal         0x80029B58
    // 0x80029784: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80029B58(rdram, ctx);
        goto after_26;
    // 0x80029784: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_26:
    // 0x80029788: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8002978C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80029790: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x80029794: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029798: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8002979C: jal         0x80029B58
    // 0x800297A0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80029B58(rdram, ctx);
        goto after_27;
    // 0x800297A0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_27:
    // 0x800297A4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800297A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800297AC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800297B0: addiu       $a1, $s1, 0xA7
    ctx->r5 = ADD32(ctx->r17, 0XA7);
    // 0x800297B4: addiu       $a2, $zero, 0x92
    ctx->r6 = ADD32(0, 0X92);
    // 0x800297B8: jal         0x80029B58
    // 0x800297BC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_28;
    // 0x800297BC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_28:
    // 0x800297C0: addiu       $s0, $s1, 0x8D
    ctx->r16 = ADD32(ctx->r17, 0X8D);
    // 0x800297C4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800297C8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800297CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800297D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800297D4: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x800297D8: jal         0x8002AB64
    // 0x800297DC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_8002AB64(rdram, ctx);
        goto after_29;
    // 0x800297DC: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_29:
    // 0x800297E0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800297E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800297E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800297EC: addiu       $a1, $s1, 0x4E
    ctx->r5 = ADD32(ctx->r17, 0X4E);
    // 0x800297F0: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // 0x800297F4: jal         0x8002AB64
    // 0x800297F8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_8002AB64(rdram, ctx);
        goto after_30;
    // 0x800297F8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_30:
    // 0x800297FC: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80029800: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80029804: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80029808: addiu       $a1, $s1, 0xF7
    ctx->r5 = ADD32(ctx->r17, 0XF7);
    // 0x8002980C: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // 0x80029810: jal         0x8002AB64
    // 0x80029814: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_8002AB64(rdram, ctx);
        goto after_31;
    // 0x80029814: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_31:
    // 0x80029818: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8002981C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80029820: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80029824: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029828: addiu       $a2, $zero, 0xAD
    ctx->r6 = ADD32(0, 0XAD);
    // 0x8002982C: jal         0x8002AB64
    // 0x80029830: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_8002AB64(rdram, ctx);
        goto after_32;
    // 0x80029830: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_32:
    // 0x80029834: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80029838: addiu       $a1, $s1, 0x78
    ctx->r5 = ADD32(ctx->r17, 0X78);
    // 0x8002983C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80029840: lbu         $a3, -0x455C($s0)
    ctx->r7 = MEM_BU(ctx->r16, -0X455C);
    // 0x80029844: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80029848: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8002984C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80029850: jal         0x8002AB64
    // 0x80029854: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    func_8002AB64(rdram, ctx);
        goto after_33;
    // 0x80029854: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    after_33:
    // 0x80029858: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8002985C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80029860: lbu         $a3, -0x455B($s0)
    ctx->r7 = MEM_BU(ctx->r16, -0X455B);
    // 0x80029864: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80029868: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002986C: addiu       $a1, $s1, 0x39
    ctx->r5 = ADD32(ctx->r17, 0X39);
    // 0x80029870: jal         0x8002AB64
    // 0x80029874: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    func_8002AB64(rdram, ctx);
        goto after_34;
    // 0x80029874: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    after_34:
    // 0x80029878: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8002987C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80029880: lbu         $a3, -0x4559($s0)
    ctx->r7 = MEM_BU(ctx->r16, -0X4559);
    // 0x80029884: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029888: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002988C: addiu       $a1, $s1, 0xE2
    ctx->r5 = ADD32(ctx->r17, 0XE2);
    // 0x80029890: jal         0x8002AB64
    // 0x80029894: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    func_8002AB64(rdram, ctx);
        goto after_35;
    // 0x80029894: addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    after_35:
    // 0x80029898: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8002989C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800298A0: lbu         $a3, -0x455A($s0)
    ctx->r7 = MEM_BU(ctx->r16, -0X455A);
    // 0x800298A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800298A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800298AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800298B0: jal         0x8002AB64
    // 0x800298B4: addiu       $a2, $zero, 0xAD
    ctx->r6 = ADD32(0, 0XAD);
    func_8002AB64(rdram, ctx);
        goto after_36;
    // 0x800298B4: addiu       $a2, $zero, 0xAD
    ctx->r6 = ADD32(0, 0XAD);
    after_36:
    // 0x800298B8: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800298BC: lbu         $t9, -0x455C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X455C);
    // 0x800298C0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800298C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800298C8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800298CC: bgez        $t9, L_800298E4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800298D0: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800298E4;
    }
    // 0x800298D0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800298D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800298D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800298DC: nop

    // 0x800298E0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800298E4:
    // 0x800298E4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800298E8: addiu       $s0, $s1, 0xA6
    ctx->r16 = ADD32(ctx->r17, 0XA6);
    // 0x800298EC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800298F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800298F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800298F8: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800298FC: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    // 0x80029900: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80029904: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80029908: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8002990C: jal         0x80029B58
    // 0x80029910: nop

    func_80029B58(rdram, ctx);
        goto after_37;
    // 0x80029910: nop

    after_37:
    // 0x80029914: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80029918: lbu         $t3, -0x455B($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X455B);
    // 0x8002991C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80029920: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80029924: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80029928: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002992C: bgez        $t3, L_80029940
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80029930: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80029940;
    }
    // 0x80029930: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80029934: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80029938: nop

    // 0x8002993C: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_80029940:
    // 0x80029940: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80029944: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80029948: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002994C: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80029950: addiu       $a1, $s1, 0x32
    ctx->r5 = ADD32(ctx->r17, 0X32);
    // 0x80029954: addiu       $a2, $zero, 0x79
    ctx->r6 = ADD32(0, 0X79);
    // 0x80029958: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002995C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80029960: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80029964: jal         0x80029B58
    // 0x80029968: nop

    func_80029B58(rdram, ctx);
        goto after_38;
    // 0x80029968: nop

    after_38:
    // 0x8002996C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80029970: lbu         $t6, -0x4559($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X4559);
    // 0x80029974: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80029978: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002997C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80029980: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80029984: bgez        $t6, L_80029998
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80029988: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80029998;
    }
    // 0x80029988: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002998C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029990: nop

    // 0x80029994: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80029998:
    // 0x80029998: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002999C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800299A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800299A4: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800299A8: addiu       $a1, $s1, 0xDA
    ctx->r5 = ADD32(ctx->r17, 0XDA);
    // 0x800299AC: addiu       $a2, $zero, 0x79
    ctx->r6 = ADD32(0, 0X79);
    // 0x800299B0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800299B4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800299B8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800299BC: jal         0x80029B58
    // 0x800299C0: nop

    func_80029B58(rdram, ctx);
        goto after_39;
    // 0x800299C0: nop

    after_39:
    // 0x800299C4: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800299C8: lbu         $t9, -0x455A($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X455A);
    // 0x800299CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800299D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800299D4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800299D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800299DC: bgez        $t9, L_800299F0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800299E0: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800299F0;
    }
    // 0x800299E0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800299E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800299E8: nop

    // 0x800299EC: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_800299F0:
    // 0x800299F0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800299F4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800299F8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800299FC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80029A00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80029A04: addiu       $a2, $zero, 0xAF
    ctx->r6 = ADD32(0, 0XAF);
    // 0x80029A08: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80029A0C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80029A10: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80029A14: jal         0x80029B58
    // 0x80029A18: nop

    func_80029B58(rdram, ctx);
        goto after_40;
    // 0x80029A18: nop

    after_40:
    // 0x80029A1C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80029A20: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80029A24: lbu         $t5, -0x454C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X454C);
    // 0x80029A28: lw          $t3, -0x4570($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4570);
    // 0x80029A2C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80029A30: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80029A34: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80029A38: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80029A3C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80029A40: lw          $t7, 0x3D3C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3D3C);
    // 0x80029A44: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80029A48: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80029A4C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80029A50: divu        $zero, $t4, $t7
    lo = S32(U32(ctx->r12) / U32(ctx->r15)); hi = S32(U32(ctx->r12) % U32(ctx->r15));
    // 0x80029A54: mflo        $s0
    ctx->r16 = lo;
    // 0x80029A58: slti        $at, $s0, 0x65
    ctx->r1 = SIGNED(ctx->r16) < 0X65 ? 1 : 0;
    // 0x80029A5C: bne         $t7, $zero, L_80029A68
    if (ctx->r15 != 0) {
        // 0x80029A60: nop
    
            goto L_80029A68;
    }
    // 0x80029A60: nop

    // 0x80029A64: break       7
    do_break(2147654244);
L_80029A68:
    // 0x80029A68: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80029A6C: bne         $at, $zero, L_80029A78
    if (ctx->r1 != 0) {
        // 0x80029A70: addiu       $a1, $s1, 0x91
        ctx->r5 = ADD32(ctx->r17, 0X91);
            goto L_80029A78;
    }
    // 0x80029A70: addiu       $a1, $s1, 0x91
    ctx->r5 = ADD32(ctx->r17, 0X91);
    // 0x80029A74: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
L_80029A78:
    // 0x80029A78: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80029A7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80029A80: addiu       $a2, $zero, 0x92
    ctx->r6 = ADD32(0, 0X92);
    // 0x80029A84: jal         0x8002AB64
    // 0x80029A88: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_8002AB64(rdram, ctx);
        goto after_41;
    // 0x80029A88: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_41:
    // 0x80029A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80029A90: jal         0x8002A0B8
    // 0x80029A94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8002A0B8(rdram, ctx);
        goto after_42;
    // 0x80029A94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_42:
    // 0x80029A98: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x80029A9C: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x80029AA0: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x80029AA4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80029AA8: andi        $t9, $a3, 0x2000
    ctx->r25 = ctx->r7 & 0X2000;
    // 0x80029AAC: bnel        $t9, $zero, L_80029B48
    if (ctx->r25 != 0) {
        // 0x80029AB0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80029B48;
    }
    goto skip_0;
    // 0x80029AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80029AB4: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x80029AB8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80029ABC: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x80029AC0: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80029AC4: beq         $at, $zero, L_80029AE0
    if (ctx->r1 == 0) {
        // 0x80029AC8: ori         $t3, $a3, 0x2000
        ctx->r11 = ctx->r7 | 0X2000;
            goto L_80029AE0;
    }
    // 0x80029AC8: ori         $t3, $a3, 0x2000
    ctx->r11 = ctx->r7 | 0X2000;
    // 0x80029ACC: lhu         $v1, 0x2876($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2876);
    // 0x80029AD0: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80029AD4: andi        $t1, $v1, 0x10
    ctx->r9 = ctx->r3 & 0X10;
    // 0x80029AD8: beq         $t1, $zero, L_80029B0C
    if (ctx->r9 == 0) {
        // 0x80029ADC: nop
    
            goto L_80029B0C;
    }
    // 0x80029ADC: nop

L_80029AE0:
    // 0x80029AE0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80029AE4: sw          $t2, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = ctx->r10;
    // 0x80029AE8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80029AEC: sw          $zero, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = 0;
    // 0x80029AF0: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80029AF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029AF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029AFC: jal         0x800268D4
    // 0x80029B00: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_43;
    // 0x80029B00: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_43:
    // 0x80029B04: b           L_80029B48
    // 0x80029B08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80029B48;
    // 0x80029B08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80029B0C:
    // 0x80029B0C: bne         $at, $zero, L_80029B18
    if (ctx->r1 != 0) {
        // 0x80029B10: andi        $t5, $v1, 0x2000
        ctx->r13 = ctx->r3 & 0X2000;
            goto L_80029B18;
    }
    // 0x80029B10: andi        $t5, $v1, 0x2000
    ctx->r13 = ctx->r3 & 0X2000;
    // 0x80029B14: beq         $t5, $zero, L_80029B44
    if (ctx->r13 == 0) {
        // 0x80029B18: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80029B44;
    }
L_80029B18:
    // 0x80029B18: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80029B1C: sw          $zero, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = 0;
    // 0x80029B20: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80029B24: addiu       $t6, $zero, -0x140
    ctx->r14 = ADD32(0, -0X140);
    // 0x80029B28: sw          $t6, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = ctx->r14;
    // 0x80029B2C: ori         $t4, $a3, 0x3000
    ctx->r12 = ctx->r7 | 0X3000;
    // 0x80029B30: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x80029B34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029B3C: jal         0x800268D4
    // 0x80029B40: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_44;
    // 0x80029B40: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_44:
L_80029B44:
    // 0x80029B44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80029B48:
    // 0x80029B48: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80029B4C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80029B50: jr          $ra
    // 0x80029B54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80029B54: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80014F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014F48: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80014F4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014F50: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80014F54: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80014F58: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80014F5C: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x80014F60: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80014F64: bnel        $t6, $at, L_80014F9C
    if (ctx->r14 != ctx->r1) {
        // 0x80014F68: lwc1        $f10, 0x1C($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_80014F9C;
    }
    goto skip_0;
    // 0x80014F68: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x80014F6C: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80014F70: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80014F74: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x80014F78: lw          $t8, 0x2C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2C);
    // 0x80014F7C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80014F80: lwc1        $f18, 0x94($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X94);
    // 0x80014F84: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80014F88: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80014F8C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80014F90: jr          $ra
    // 0x80014F94: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80014F94: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80014F98: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
L_80014F9C:
    // 0x80014F9C: lwc1        $f16, 0x24($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80014FA0: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80014FA4: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80014FA8: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80014FAC: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x80014FB0: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x80014FB4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80014FB8: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80014FBC: lwc1        $f18, 0x1C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80014FC0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x80014FC4: add.d       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f10.d + ctx->f6.d;
    // 0x80014FC8: add.d       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f16.d + ctx->f4.d;
    // 0x80014FCC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80014FD0: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x80014FD4: jr          $ra
    // 0x80014FD8: nop

    return;
    // 0x80014FD8: nop

;}
RECOMP_FUNC void func_80035510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035510: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80035514: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80035518: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x8003551C: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x80035520: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80035524: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80035528: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_8003552C:
    // 0x8003552C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80035530: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80035534: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x80035538: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8003553C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80035540: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80035544: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80035548: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8003554C: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80035550: beql        $a0, $t2, L_800355D4
    if (ctx->r4 == ctx->r10) {
        // 0x80035554: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800355D4;
    }
    goto skip_0;
    // 0x80035554: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x80035558: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8003555C:
    // 0x8003555C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80035560: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80035564: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80035568: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8003556C: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80035570: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80035574: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80035578: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8003557C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80035580: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x80035584: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80035588: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8003558C: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80035590: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80035594: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80035598: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8003559C: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800355A0: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800355A4: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800355A8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800355AC: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800355B0: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800355B4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800355B8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800355BC: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800355C0: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800355C4: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800355C8: bnel        $a0, $t2, L_8003555C
    if (ctx->r4 != ctx->r10) {
        // 0x800355CC: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8003555C;
    }
    goto skip_1;
    // 0x800355CC: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x800355D0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800355D4:
    // 0x800355D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800355D8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800355DC: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800355E0: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800355E4: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800355E8: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800355EC: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800355F0: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800355F4: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800355F8: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800355FC: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80035600: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x80035604: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80035608: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8003560C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x80035610: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x80035614: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80035618: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8003561C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80035620: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80035624: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80035628: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8003562C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x80035630: bne         $at, $zero, L_8003552C
    if (ctx->r1 != 0) {
        // 0x80035634: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8003552C;
    }
    // 0x80035634: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80035638: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8003563C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80035640: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_80035644:
    // 0x80035644: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80035648: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8003564C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80035650: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x80035654: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0XC);
    // 0x80035658: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8003565C: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x80035660: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80035664: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x80035668: bne         $a0, $v0, L_80035644
    if (ctx->r4 != ctx->r2) {
        // 0x8003566C: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80035644;
    }
    // 0x8003566C: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80035670: jr          $ra
    // 0x80035674: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80035674: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80035678: nop

    // 0x8003567C: nop

;}
RECOMP_FUNC void func_800173E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800173E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800173E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800173E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800173EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800173F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800173F4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800173F8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800173FC: lw          $v0, 0x68($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X68);
    // 0x80017400: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80017404: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80017408: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8001740C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80017410: jal         0x8001FCF8
    // 0x80017414: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x80017414: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80017418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001741C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017420: jr          $ra
    // 0x80017424: nop

    return;
    // 0x80017424: nop

;}
RECOMP_FUNC void func_80047854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047854: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80047858: lw          $t6, 0x55D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X55D4);
    // 0x8004785C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80047860: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047864: addiu       $t7, $t6, 0x14
    ctx->r15 = ADD32(ctx->r14, 0X14);
    // 0x80047868: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8004786C: lui         $t8, 0xA460
    ctx->r24 = S32(0XA460 << 16);
    // 0x80047870: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80047874: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80047878: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8004787C: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80047880: beq         $t1, $zero, L_800478A4
    if (ctx->r9 == 0) {
        // 0x80047884: nop
    
            goto L_800478A4;
    }
    // 0x80047884: nop

L_80047888:
    // 0x80047888: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x8004788C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80047890: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80047894: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80047898: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x8004789C: bne         $t5, $zero, L_80047888
    if (ctx->r13 != 0) {
        // 0x800478A0: nop
    
            goto L_80047888;
    }
    // 0x800478A0: nop

L_800478A4:
    // 0x800478A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800478A8: lui         $at, 0x1000
    ctx->r1 = S32(0X1000 << 16);
    // 0x800478AC: lui         $t9, 0xA500
    ctx->r25 = S32(0XA500 << 16);
    // 0x800478B0: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800478B4: lui         $t0, 0xA460
    ctx->r8 = S32(0XA460 << 16);
    // 0x800478B8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800478BC: sw          $t8, 0x510($t9)
    MEM_W(0X510, ctx->r25) = ctx->r24;
    // 0x800478C0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x800478C4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800478C8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800478CC: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x800478D0: beq         $t3, $zero, L_800478F4
    if (ctx->r11 == 0) {
        // 0x800478D4: nop
    
            goto L_800478F4;
    }
    // 0x800478D4: nop

L_800478D8:
    // 0x800478D8: lui         $t4, 0xA460
    ctx->r12 = S32(0XA460 << 16);
    // 0x800478DC: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x800478E0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800478E4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800478E8: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x800478EC: bne         $t7, $zero, L_800478D8
    if (ctx->r15 != 0) {
        // 0x800478F0: nop
    
            goto L_800478D8;
    }
    // 0x800478F0: nop

L_800478F4:
    // 0x800478F4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800478F8: lui         $t0, 0xA500
    ctx->r8 = S32(0XA500 << 16);
    // 0x800478FC: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80047900: jal         0x8004793C
    // 0x80047904: sw          $t9, 0x510($t0)
    MEM_W(0X510, ctx->r8) = ctx->r25;
    func_8004793C(rdram, ctx);
        goto after_0;
    // 0x80047904: sw          $t9, 0x510($t0)
    MEM_W(0X510, ctx->r8) = ctx->r25;
    after_0:
    // 0x80047908: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8004790C: lui         $t2, 0xA460
    ctx->r10 = S32(0XA460 << 16);
    // 0x80047910: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x80047914: lui         $t3, 0x8007
    ctx->r11 = S32(0X8007 << 16);
    // 0x80047918: lw          $t3, -0xBF0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XBF0);
    // 0x8004791C: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80047920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047924: ori         $at, $at, 0x401
    ctx->r1 = ctx->r1 | 0X401;
    // 0x80047928: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8004792C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80047930: sw          $t4, -0xBF0($at)
    MEM_W(-0XBF0, ctx->r1) = ctx->r12;
    // 0x80047934: jr          $ra
    // 0x80047938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80047938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035388: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8003538C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035390: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80035394: jal         0x80035300
    // 0x80035398: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80035398: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8003539C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800353A0: jal         0x80035200
    // 0x800353A4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800353A4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800353A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800353AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800353B0: jr          $ra
    // 0x800353B4: nop

    return;
    // 0x800353B4: nop

;}
RECOMP_FUNC void func_80038D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038D6C: jr          $ra
    // 0x80038D70: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x80038D70: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void nnScGetGfxMQ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000704: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
    // 0x80000708: jr          $ra
    // 0x8000070C: nop

    return;
    // 0x8000070C: nop

;}
RECOMP_FUNC void func_80038794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003879C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800387A0: jal         0x800386D0
    // 0x800387A4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_0;
    // 0x800387A4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800387A8: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800387AC: beq         $t6, $zero, L_800387D8
    if (ctx->r14 == 0) {
        // 0x800387B0: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800387D8;
    }
    // 0x800387B0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800387B4: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_800387B8:
    // 0x800387B8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800387BC: jal         0x800386D0
    // 0x800387C0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_1;
    // 0x800387C0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800387C4: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x800387C8: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800387CC: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800387D0: bne         $t9, $zero, L_800387B8
    if (ctx->r25 != 0) {
        // 0x800387D4: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_800387B8;
    }
    // 0x800387D4: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_800387D8:
    // 0x800387D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800387DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800387E0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800387E4: jr          $ra
    // 0x800387E8: nop

    return;
    // 0x800387E8: nop

    // 0x800387EC: jr          $ra
    // 0x800387F0: nop

    return;
    // 0x800387F0: nop

;}
RECOMP_FUNC void func_80031890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031890: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80031894: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80031898: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8003189C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800318A0: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x800318A4: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x800318A8: addiu       $t6, $t6, -0x490
    ctx->r14 = ADD32(ctx->r14, -0X490);
    // 0x800318AC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800318B0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x800318B4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800318B8: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x800318BC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800318C0: lbu         $t1, 0x3F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X3F);
    // 0x800318C4: addiu       $t4, $t4, 0x2898
    ctx->r12 = ADD32(ctx->r12, 0X2898);
    // 0x800318C8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800318CC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800318D0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800318D4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800318D8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800318DC: lui         $a2, 0x4E45
    ctx->r6 = S32(0X4E45 << 16);
    // 0x800318E0: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x800318E4: addiu       $t5, $zero, 0x200
    ctx->r13 = ADD32(0, 0X200);
    // 0x800318E8: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x800318EC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800318F0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800318F4: addiu       $a3, $a3, -0x4C0
    ctx->r7 = ADD32(ctx->r7, -0X4C0);
    // 0x800318F8: ori         $a2, $a2, 0x5445
    ctx->r6 = ctx->r6 | 0X5445;
    // 0x800318FC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80031900: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80031904: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80031908: addiu       $a1, $zero, 0x3738
    ctx->r5 = ADD32(0, 0X3738);
    // 0x8003190C: jal         0x8003B270
    // 0x80031910: sb          $t1, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r9;
    osPfsAllocateFile_recomp(rdram, ctx);
        goto after_0;
    // 0x80031910: sb          $t1, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r9;
    after_0:
    // 0x80031914: bne         $v0, $zero, L_80031948
    if (ctx->r2 != 0) {
        // 0x80031918: negu        $v1, $v0
        ctx->r3 = SUB32(0, ctx->r2);
            goto L_80031948;
    }
    // 0x80031918: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8003191C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80031920: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80031924: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x80031928: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8003192C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80031930: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80031934: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80031938: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x8003193C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80031940: b           L_80031948
    // 0x80031944: sb          $t7, 0x2A3A($at)
    MEM_B(0X2A3A, ctx->r1) = ctx->r15;
        goto L_80031948;
    // 0x80031944: sb          $t7, 0x2A3A($at)
    MEM_B(0X2A3A, ctx->r1) = ctx->r15;
L_80031948:
    // 0x80031948: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8003194C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80031950: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80031954: jr          $ra
    // 0x80031958: nop

    return;
    // 0x80031958: nop

;}
RECOMP_FUNC void func_800387F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800387F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800387F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800387FC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80038800: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80038804: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80038808: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8003880C: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x80038810: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80038814: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80038818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003881C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
L_80038820:
    // 0x80038820: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x80038824: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80038828: beql        $t8, $zero, L_8003886C
    if (ctx->r24 == 0) {
        // 0x8003882C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8003886C;
    }
    goto skip_0;
    // 0x8003882C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80038830: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x80038834: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80038838: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x8003883C: beql        $t6, $zero, L_80038854
    if (ctx->r14 == 0) {
        // 0x80038840: lw          $a0, 0xB8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XB8);
            goto L_80038854;
    }
    goto skip_1;
    // 0x80038840: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
    skip_1:
    // 0x80038844: lw          $t7, 0xB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB8);
    // 0x80038848: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x8003884C: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x80038850: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
L_80038854:
    // 0x80038854: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x80038858: beql        $at, $zero, L_8003886C
    if (ctx->r1 == 0) {
        // 0x8003885C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8003886C;
    }
    goto skip_2;
    // 0x8003885C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x80038860: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x80038864: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80038868: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8003886C:
    // 0x8003886C: bnel        $v0, $a1, L_80038820
    if (ctx->r2 != ctx->r5) {
        // 0x80038870: lw          $t6, 0x4($t4)
        ctx->r14 = MEM_W(ctx->r12, 0X4);
            goto L_80038820;
    }
    goto skip_3;
    // 0x80038870: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    skip_3:
    // 0x80038874: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80038878: jal         0x800386D0
    // 0x8003887C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_0;
    // 0x8003887C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x80038880: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80038884: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80038888: bne         $v0, $at, L_800389F4
    if (ctx->r2 != ctx->r1) {
        // 0x8003888C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800389F4;
    }
    // 0x8003888C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80038890: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80038894: jal         0x800386D0
    // 0x80038898: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_1;
    // 0x80038898: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x8003889C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800388A0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800388A4: bne         $v0, $at, L_800388F8
    if (ctx->r2 != ctx->r1) {
        // 0x800388A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800388F8;
    }
    // 0x800388A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800388AC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800388B0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800388B4: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800388B8: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x800388BC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800388C0: jal         0x800386D0
    // 0x800388C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_2;
    // 0x800388C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x800388C8: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800388CC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800388D0: jal         0x800386D0
    // 0x800388D4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_3;
    // 0x800388D4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x800388D8: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x800388DC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800388E0: jal         0x800386D0
    // 0x800388E4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_4;
    // 0x800388E4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x800388E8: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x800388EC: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800388F0: b           L_80038A90
    // 0x800388F4: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_80038A90;
    // 0x800388F4: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_800388F8:
    // 0x800388F8: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800388FC: bnel        $v1, $at, L_80038938
    if (ctx->r3 != ctx->r1) {
        // 0x80038900: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80038938;
    }
    goto skip_4;
    // 0x80038900: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x80038904: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80038908: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003890C: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x80038910: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x80038914: beq         $t6, $zero, L_80038928
    if (ctx->r14 == 0) {
        // 0x80038918: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_80038928;
    }
    // 0x80038918: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8003891C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x80038920: b           L_80038A90
    // 0x80038924: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_80038A90;
    // 0x80038924: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_80038928:
    // 0x80038928: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8003892C: b           L_80038A90
    // 0x80038930: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_80038A90;
    // 0x80038930: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x80038934: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_80038938:
    // 0x80038938: bne         $v1, $at, L_80038968
    if (ctx->r3 != ctx->r1) {
        // 0x8003893C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_80038968;
    }
    // 0x8003893C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80038940: jal         0x800386D0
    // 0x80038944: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_5;
    // 0x80038944: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x80038948: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8003894C: jal         0x800386D0
    // 0x80038950: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_6;
    // 0x80038950: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x80038954: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80038958: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x8003895C: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x80038960: b           L_80038A90
    // 0x80038964: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_80038A90;
    // 0x80038964: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_80038968:
    // 0x80038968: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8003896C: bne         $v1, $at, L_80038A90
    if (ctx->r3 != ctx->r1) {
        // 0x80038970: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_80038A90;
    }
    // 0x80038970: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80038974: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x80038978: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x8003897C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80038980: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80038984: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80038988: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x8003898C: bne         $a0, $zero, L_800389A0
    if (ctx->r4 != 0) {
        // 0x80038990: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_800389A0;
    }
    // 0x80038990: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x80038994: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80038998: b           L_800389E0
    // 0x8003899C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_800389E0;
    // 0x8003899C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800389A0:
    // 0x800389A0: beq         $a0, $at, L_800389AC
    if (ctx->r4 == ctx->r1) {
        // 0x800389A4: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800389AC;
    }
    // 0x800389A4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800389A8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_800389AC:
    // 0x800389AC: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800389B0: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800389B4: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800389B8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800389BC: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x800389C0: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800389C4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800389C8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800389CC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800389D0: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800389D4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800389D8: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800389DC: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800389E0:
    // 0x800389E0: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800389E4: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800389E8: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x800389EC: b           L_80038A90
    // 0x800389F0: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_80038A90;
    // 0x800389F0: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800389F4:
    // 0x800389F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800389F8: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x800389FC: beq         $t9, $zero, L_80038A24
    if (ctx->r25 == 0) {
        // 0x80038A00: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_80038A24;
    }
    // 0x80038A00: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80038A04: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x80038A08: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80038A0C: jal         0x800386D0
    // 0x80038A10: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_7;
    // 0x80038A10: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x80038A14: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x80038A18: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80038A1C: b           L_80038A34
    // 0x80038A20: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
        goto L_80038A34;
    // 0x80038A20: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
L_80038A24:
    // 0x80038A24: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x80038A28: lbu         $t7, 0xA8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA8);
    // 0x80038A2C: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x80038A30: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_80038A34:
    // 0x80038A34: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80038A38: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x80038A3C: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x80038A40: beq         $t9, $at, L_80038A8C
    if (ctx->r25 == ctx->r1) {
        // 0x80038A44: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_80038A8C;
    }
    // 0x80038A44: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x80038A48: beq         $t9, $at, L_80038A8C
    if (ctx->r25 == ctx->r1) {
        // 0x80038A4C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_80038A8C;
    }
    // 0x80038A4C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80038A50: jal         0x800386D0
    // 0x80038A54: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_800386D0(rdram, ctx);
        goto after_8;
    // 0x80038A54: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x80038A58: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x80038A5C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80038A60: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x80038A64: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x80038A68: bne         $t8, $at, L_80038A90
    if (ctx->r24 != ctx->r1) {
        // 0x80038A6C: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_80038A90;
    }
    // 0x80038A6C: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80038A70: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80038A74: jal         0x80038794
    // 0x80038A78: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    func_80038794(rdram, ctx);
        goto after_9;
    // 0x80038A78: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x80038A7C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80038A80: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80038A84: b           L_80038A90
    // 0x80038A88: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_80038A90;
    // 0x80038A88: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_80038A8C:
    // 0x80038A8C: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_80038A90:
    // 0x80038A90: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80038A94: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x80038A98: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x80038A9C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80038AA0: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80038AA4: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x80038AA8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80038AAC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80038AB0: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80038AB4: beql        $t6, $at, L_80038AD4
    if (ctx->r14 == ctx->r1) {
        // 0x80038AB8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80038AD4;
    }
    goto skip_5;
    // 0x80038AB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_5:
    // 0x80038ABC: jal         0x80038794
    // 0x80038AC0: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    func_80038794(rdram, ctx);
        goto after_10;
    // 0x80038AC0: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x80038AC4: lw          $t7, 0xB8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XB8);
    // 0x80038AC8: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x80038ACC: sw          $t9, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r25;
    // 0x80038AD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80038AD4:
    // 0x80038AD4: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x80038AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80038ADC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80038AE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80038AE4: jr          $ra
    // 0x80038AE8: nop

    return;
    // 0x80038AE8: nop

;}
RECOMP_FUNC void func_8000227C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000227C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80002280: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80002284: lui         $fp, 0x8008
    ctx->r30 = S32(0X8008 << 16);
    // 0x80002288: addiu       $fp, $fp, -0x4CB8
    ctx->r30 = ADD32(ctx->r30, -0X4CB8);
    // 0x8000228C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80002290: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002294: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002298: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000229C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800022A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800022A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800022A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800022AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800022B0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800022B4: jal         0x80031C40
    // 0x800022B8: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    func_80031C40(rdram, ctx);
        goto after_0;
    // 0x800022B8: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
    after_0:
    // 0x800022BC: jal         0x80100000
    // 0x800022C0: nop

    LOOKUP_FUNC(0x80100000)(rdram, ctx);
        goto after_1;
    // 0x800022C0: nop

    after_1:
    // 0x800022C4: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800022C8: lhu         $t6, -0x4D20($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4D20);
    // 0x800022CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800022D0: ori         $s7, $zero, 0xD150
    ctx->r23 = 0 | 0XD150;
    // 0x800022D4: bne         $t6, $at, L_800023C8
    if (ctx->r14 != ctx->r1) {
        // 0x800022D8: lui         $s6, 0x8030
        ctx->r22 = S32(0X8030 << 16);
            goto L_800023C8;
    }
    // 0x800022D8: lui         $s6, 0x8030
    ctx->r22 = S32(0X8030 << 16);
    // 0x800022DC: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x800022E0: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800022E4: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x800022E8: addiu       $s4, $s4, -0x4D0C
    ctx->r20 = ADD32(ctx->r20, -0X4D0C);
    // 0x800022EC: addiu       $s6, $s6, 0x1000
    ctx->r22 = ADD32(ctx->r22, 0X1000);
    // 0x800022F0: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800022F4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800022F8: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
L_800022FC:
    // 0x800022FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80002300: jal         0x800314C0
    // 0x80002304: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    func_800314C0(rdram, ctx);
        goto after_2;
    // 0x80002304: lb          $a0, 0x2870($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X2870);
    after_2:
    // 0x80002308: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000230C: sw          $zero, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = 0;
    // 0x80002310: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80002314: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002318: mflo        $t8
    ctx->r24 = lo;
    // 0x8000231C: addu        $a0, $s6, $t8
    ctx->r4 = ADD32(ctx->r22, ctx->r24);
    // 0x80002320: jal         0x800011DC
    // 0x80002324: nop

    func_800011DC(rdram, ctx);
        goto after_3;
    // 0x80002324: nop

    after_3:
    // 0x80002328: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8000232C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x80002330: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002334: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80002338: mflo        $t0
    ctx->r8 = lo;
    // 0x8000233C: addu        $s5, $s6, $t0
    ctx->r21 = ADD32(ctx->r22, ctx->r8);
    // 0x80002340: bnel        $v0, $zero, L_80002378
    if (ctx->r2 != 0) {
        // 0x80002344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002378;
    }
    goto skip_0;
    // 0x80002344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80002348: sw          $t1, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r9;
    // 0x8000234C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002350:
    // 0x80002350: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80002354: jal         0x80034020
    // 0x80002358: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80002358: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x8000235C: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80002360: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80002364: bnel        $s2, $t3, L_80002350
    if (ctx->r18 != ctx->r11) {
        // 0x80002368: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002350;
    }
    goto skip_1;
    // 0x80002368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8000236C: b           L_80002394
    // 0x80002370: nop

        goto L_80002394;
    // 0x80002370: nop

    // 0x80002374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80002378:
    // 0x80002378: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000237C: jal         0x80034020
    // 0x80002380: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80002380: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x80002384: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80002388: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x8000238C: bnel        $s3, $t5, L_80002378
    if (ctx->r19 != ctx->r13) {
        // 0x80002390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80002378;
    }
    goto skip_2;
    // 0x80002390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_80002394:
    // 0x80002394: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002398: lw          $a0, -0x4628($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4628);
    // 0x8000239C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800023A0: jal         0x80034200
    // 0x800023A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800023A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x800023A8: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800023AC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800023B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800023B4: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x800023B8: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800023BC: lhu         $t8, -0x4D20($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4D20);
    // 0x800023C0: beq         $t8, $at, L_800022FC
    if (ctx->r24 == ctx->r1) {
        // 0x800023C4: nop
    
            goto L_800022FC;
    }
    // 0x800023C4: nop

L_800023C8:
    // 0x800023C8: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800023CC: addiu       $s0, $s0, -0x4618
    ctx->r16 = ADD32(ctx->r16, -0X4618);
    // 0x800023D0: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x800023D4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800023D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800023DC:
    // 0x800023DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800023E0: jal         0x80034020
    // 0x800023E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800023E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800023E8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800023EC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800023F0: bnel        $s3, $t0, L_800023DC
    if (ctx->r19 != ctx->r8) {
        // 0x800023F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800023DC;
    }
    goto skip_3;
    // 0x800023F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x800023F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800023FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002400: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80002404: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80002408: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000240C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80002410: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80002414: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80002418: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000241C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80002420: jr          $ra
    // 0x80002424: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80002424: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800493EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800493EC: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800493F0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800493F4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800493F8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800493FC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80049400: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80049404: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80049408: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004940C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80049410: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80049414: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80049418: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004941C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80049420: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x80049424: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80049428: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x8004942C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80049430: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80049434: jalr        $t9
    // 0x80049438: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80049438: nop

    after_0:
    // 0x8004943C: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x80049440: lui         $t8, 0xC00
    ctx->r24 = S32(0XC00 << 16);
    // 0x80049444: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x80049448: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x8004944C: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x80049450: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x80049454: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80049458: ori         $t2, $t2, 0x6C0
    ctx->r10 = ctx->r10 | 0X6C0;
    // 0x8004945C: ori         $t8, $t8, 0xDA83
    ctx->r24 = ctx->r24 | 0XDA83;
    // 0x80049460: ori         $t4, $t4, 0x6C0
    ctx->r12 = ctx->r12 | 0X6C0;
    // 0x80049464: ori         $t3, $t3, 0x5A82
    ctx->r11 = ctx->r11 | 0X5A82;
    // 0x80049468: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8004946C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80049470: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80049474: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80049478: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x8004947C: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x80049480: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x80049484: addiu       $t5, $v0, 0x18
    ctx->r13 = ADD32(ctx->r2, 0X18);
    // 0x80049488: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8004948C: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x80049490: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80049494: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80049498: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8004949C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800494A0: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x800494A4: jal         0x80048C40
    // 0x800494A8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_80048C40(rdram, ctx);
        goto after_1;
    // 0x800494A8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x800494AC: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800494B0: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800494B4: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x800494B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800494BC: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x800494C0: lbu         $t9, 0x24($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X24);
    // 0x800494C4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800494C8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800494CC: blezl       $t9, L_800496AC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800494D0: lw          $v1, 0x1C($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X1C);
            goto L_800496AC;
    }
    goto skip_0;
    // 0x800494D0: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    skip_0:
    // 0x800494D4: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
L_800494D8:
    // 0x800494D8: lw          $t7, 0x20($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X20);
    // 0x800494DC: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x800494E0: addu        $t8, $t8, $s7
    ctx->r24 = ADD32(ctx->r24, ctx->r23);
    // 0x800494E4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800494E8: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x800494EC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800494F0: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x800494F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800494F8: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800494FC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80049500: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80049504: addu        $s4, $v0, $t4
    ctx->r20 = ADD32(ctx->r2, ctx->r12);
    // 0x80049508: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8004950C: bne         $s4, $v1, L_80049534
    if (ctx->r20 != ctx->r3) {
        // 0x80049510: addu        $fp, $v0, $t9
        ctx->r30 = ADD32(ctx->r2, ctx->r25);
            goto L_80049534;
    }
    // 0x80049510: addu        $fp, $v0, $t9
    ctx->r30 = ADD32(ctx->r2, ctx->r25);
    // 0x80049514: or          $t7, $s2, $zero
    ctx->r15 = ctx->r18 | 0;
    // 0x80049518: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x8004951C: sll         $s5, $t7, 16
    ctx->r21 = S32(ctx->r15 << 16);
    // 0x80049520: sra         $t2, $s5, 16
    ctx->r10 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80049524: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80049528: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x8004952C: b           L_8004954C
    // 0x80049530: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
        goto L_8004954C;
    // 0x80049530: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
L_80049534:
    // 0x80049534: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80049538: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8004953C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80049540: jal         0x80048DC8
    // 0x80049544: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80048DC8(rdram, ctx);
        goto after_2;
    // 0x80049544: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x80049548: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8004954C:
    // 0x8004954C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80049550: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80049554: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80049558: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8004955C: jal         0x80048F54
    // 0x80049560: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80048F54(rdram, ctx);
        goto after_3;
    // 0x80049560: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x80049564: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x80049568: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8004956C: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80049570: beq         $a0, $zero, L_800495C4
    if (ctx->r4 == 0) {
        // 0x80049574: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_800495C4;
    }
    // 0x80049574: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80049578: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x8004957C: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x80049580: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80049584: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80049588: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8004958C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80049590: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x80049594: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80049598: bnel        $t2, $zero, L_800495C8
    if (ctx->r10 != 0) {
        // 0x8004959C: lh          $v1, 0xA($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XA);
            goto L_800495C8;
    }
    goto skip_1;
    // 0x8004959C: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    skip_1:
    // 0x800495A0: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x800495A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800495A8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800495AC: bne         $t3, $zero, L_800495C4
    if (ctx->r11 != 0) {
        // 0x800495B0: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800495C4;
    }
    // 0x800495B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800495B4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800495B8: jal         0x80048C40
    // 0x800495BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80048C40(rdram, ctx);
        goto after_4;
    // 0x800495BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x800495C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800495C4:
    // 0x800495C4: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
L_800495C8:
    // 0x800495C8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800495CC: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800495D0: beq         $v1, $zero, L_80049610
    if (ctx->r3 == 0) {
        // 0x800495D4: andi        $t5, $v1, 0xFFFF
        ctx->r13 = ctx->r3 & 0XFFFF;
            goto L_80049610;
    }
    // 0x800495D4: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800495D8: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800495DC: andi        $t8, $s5, 0xFFFF
    ctx->r24 = ctx->r21 & 0XFFFF;
    // 0x800495E0: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x800495E4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800495E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800495EC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800495F0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800495F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800495F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800495FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80049600: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80049604: jal         0x80048C40
    // 0x80049608: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_80048C40(rdram, ctx);
        goto after_5;
    // 0x80049608: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x8004960C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80049610:
    // 0x80049610: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80049614: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80049618: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x8004961C: beql        $a0, $zero, L_80049634
    if (ctx->r4 == 0) {
        // 0x80049620: lw          $t3, 0x24($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X24);
            goto L_80049634;
    }
    goto skip_2;
    // 0x80049620: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    skip_2:
    // 0x80049624: jal         0x80048B88
    // 0x80049628: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80048B88(rdram, ctx);
        goto after_6;
    // 0x80049628: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x8004962C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80049630: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
L_80049634:
    // 0x80049634: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80049638: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x8004963C: bne         $t3, $zero, L_80049654
    if (ctx->r11 != 0) {
        // 0x80049640: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80049654;
    }
    // 0x80049640: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80049644: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x80049648: jal         0x80048C40
    // 0x8004964C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80048C40(rdram, ctx);
        goto after_7;
    // 0x8004964C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x80049650: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80049654:
    // 0x80049654: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x80049658: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8004965C: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x80049660: beq         $v1, $zero, L_8004968C
    if (ctx->r3 == 0) {
        // 0x80049664: sra         $s7, $t4, 16
        ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
            goto L_8004968C;
    }
    // 0x80049664: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80049668: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8004966C: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x80049670: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x80049674: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80049678: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x8004967C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80049680: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80049684: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80049688: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8004968C:
    // 0x8004968C: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x80049690: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x80049694: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80049698: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8004969C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800496A0: bne         $at, $zero, L_800494D8
    if (ctx->r1 != 0) {
        // 0x800496A4: addu        $v1, $v0, $t3
        ctx->r3 = ADD32(ctx->r2, ctx->r11);
            goto L_800494D8;
    }
    // 0x800496A4: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x800496A8: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
L_800496AC:
    // 0x800496AC: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x800496B0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800496B4: lw          $t3, 0x14($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X14);
    // 0x800496B8: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x800496BC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800496C0: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x800496C4: sltu        $at, $t4, $t8
    ctx->r1 = ctx->r12 < ctx->r24 ? 1 : 0;
    // 0x800496C8: beq         $at, $zero, L_800496D8
    if (ctx->r1 == 0) {
        // 0x800496CC: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_800496D8;
    }
    // 0x800496CC: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x800496D0: subu        $t5, $t8, $t2
    ctx->r13 = SUB32(ctx->r24, ctx->r10);
    // 0x800496D4: sw          $t5, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r13;
L_800496D8:
    // 0x800496D8: lui         $t6, 0xA00
    ctx->r14 = S32(0XA00 << 16);
    // 0x800496DC: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x800496E0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800496E4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800496E8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800496EC: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x800496F0: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800496F4: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800496F8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800496FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80049700: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80049704: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80049708: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8004970C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80049710: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80049714: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80049718: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004971C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80049720: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80049724: jr          $ra
    // 0x80049728: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80049728: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x8004972C: nop

;}
RECOMP_FUNC void func_800043C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800043C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800043C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800043CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800043D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800043D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800043D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800043DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800043E0: lwc1        $f12, 0x128($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X128);
    // 0x800043E4: lwc1        $f14, 0x12C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800043E8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800043EC: jal         0x80004E58
    // 0x800043F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_80004E58(rdram, ctx);
        goto after_0;
    // 0x800043F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x800043F4: addiu       $a0, $zero, 0xA01
    ctx->r4 = ADD32(0, 0XA01);
    // 0x800043F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800043FC: jal         0x80005748
    // 0x80004400: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80005748(rdram, ctx);
        goto after_1;
    // 0x80004400: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80004404: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x80004408: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000440C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80004410: bne         $t8, $zero, L_80004434
    if (ctx->r24 != 0) {
        // 0x80004414: sh          $t7, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r15;
            goto L_80004434;
    }
    // 0x80004414: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80004418: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000441C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80004420: lhu         $t9, 0x60($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X60);
    // 0x80004424: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x80004428: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
    // 0x8000442C: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80004430: sh          $t0, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r8;
L_80004434:
    // 0x80004434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004438: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000443C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80004440: jr          $ra
    // 0x80004444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80004444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_801028DC_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801028DC: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x801028E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801028E4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x801028E8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x801028EC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801028F0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801028F4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801028F8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801028FC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80102900: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80102904: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80102908: sw          $a0, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r4;
    // 0x8010290C: bne         $a0, $zero, L_80102934
    if (ctx->r4 != 0) {
        // 0x80102910: sw          $a1, 0x1AC($sp)
        MEM_W(0X1AC, ctx->r29) = ctx->r5;
            goto L_80102934;
    }
    // 0x80102910: sw          $a1, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r5;
    // 0x80102914: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80102918: lwc1        $f16, 0x6FA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6FA0);
    // 0x8010291C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102920: sb          $zero, 0x35C4($at)
    MEM_B(0X35C4, ctx->r1) = 0;
    // 0x80102924: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010292C: b           L_80103568
    // 0x80102930: swc1        $f16, 0x35AC($at)
    MEM_W(0X35AC, ctx->r1) = ctx->f16.u32l;
        goto L_80103568;
    // 0x80102930: swc1        $f16, 0x35AC($at)
    MEM_W(0X35AC, ctx->r1) = ctx->f16.u32l;
L_80102934:
    // 0x80102934: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80102938: lbu         $t7, 0x35C4($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X35C4);
    // 0x8010293C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80102940: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80102944: bne         $s0, $t7, L_80102954
    if (ctx->r16 != ctx->r15) {
        // 0x80102948: addiu       $v1, $v1, -0x4D04
        ctx->r3 = ADD32(ctx->r3, -0X4D04);
            goto L_80102954;
    }
    // 0x80102948: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8010294C: b           L_80103568
    // 0x80102950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80103568;
    // 0x80102950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80102954:
    // 0x80102954: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102958: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8010295C: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80102960: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102964: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102968: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010296C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102970: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102974: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80102978: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8010297C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102980: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80102984: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80102988: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010298C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102990: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102994: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80102998: addiu       $t7, $t7, 0x3640
    ctx->r15 = ADD32(ctx->r15, 0X3640);
    // 0x8010299C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801029A0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801029A4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801029A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801029AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801029B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801029B4: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x801029B8: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x801029BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801029C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801029C4: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x801029C8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x801029CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801029D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801029D4: lw          $t7, 0x35B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X35B0);
    // 0x801029D8: addiu       $at, $zero, 0x3570
    ctx->r1 = ADD32(0, 0X3570);
    // 0x801029DC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801029E0: bne         $t7, $at, L_80102A00
    if (ctx->r15 != ctx->r1) {
        // 0x801029E4: lui         $t6, 0x8010
        ctx->r14 = S32(0X8010 << 16);
            goto L_80102A00;
    }
    // 0x801029E4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x801029E8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801029EC: sb          $t8, 0x35BC($at)
    MEM_B(0X35BC, ctx->r1) = ctx->r24;
    // 0x801029F0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801029F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801029F8: b           L_80102A40
    // 0x801029FC: sb          $t9, 0x35C0($at)
    MEM_B(0X35C0, ctx->r1) = ctx->r25;
        goto L_80102A40;
    // 0x801029FC: sb          $t9, 0x35C0($at)
    MEM_B(0X35C0, ctx->r1) = ctx->r25;
L_80102A00:
    // 0x80102A00: lw          $t6, 0x35B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X35B0);
    // 0x80102A04: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80102A08: ldc1        $f4, 0x6FA8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X6FA8);
    // 0x80102A0C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80102A10: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102A14: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80102A18: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80102A1C: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    // 0x80102A20: c.eq.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d == ctx->f8.d;
    // 0x80102A24: nop

    // 0x80102A28: bc1f        L_80102A40
    if (!c1cs) {
        // 0x80102A2C: nop
    
            goto L_80102A40;
    }
    // 0x80102A2C: nop

    // 0x80102A30: jal         0x80026434
    // 0x80102A34: sb          $t7, 0x35C0($at)
    MEM_B(0X35C0, ctx->r1) = ctx->r15;
    func_80026434(rdram, ctx);
        goto after_0;
    // 0x80102A34: sb          $t7, 0x35C0($at)
    MEM_B(0X35C0, ctx->r1) = ctx->r15;
    after_0:
    // 0x80102A38: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80102A3C: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
L_80102A40:
    // 0x80102A40: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80102A44: lbu         $v0, 0x35BC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X35BC);
    // 0x80102A48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80102A4C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80102A50: beql        $v0, $zero, L_80102A78
    if (ctx->r2 == 0) {
        // 0x80102A54: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80102A78;
    }
    goto skip_0;
    // 0x80102A54: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x80102A58: beq         $v0, $at, L_80102A80
    if (ctx->r2 == ctx->r1) {
        // 0x80102A5C: nop
    
            goto L_80102A80;
    }
    // 0x80102A5C: nop

    // 0x80102A60: beq         $v0, $s0, L_80102A90
    if (ctx->r2 == ctx->r16) {
        // 0x80102A64: lui         $at, 0x8015
        ctx->r1 = S32(0X8015 << 16);
            goto L_80102A90;
    }
    // 0x80102A64: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80102A68: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80102A6C: b           L_80102A98
    // 0x80102A70: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80102A98;
    // 0x80102A70: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80102A74: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80102A78:
    // 0x80102A78: b           L_80102A98
    // 0x80102A7C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80102A98;
    // 0x80102A7C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80102A80:
    // 0x80102A80: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80102A84: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80102A88: b           L_80102A98
    // 0x80102A8C: lwc1        $f0, 0x6FB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FB0);
        goto L_80102A98;
    // 0x80102A8C: lwc1        $f0, 0x6FB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FB0);
L_80102A90:
    // 0x80102A90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80102A94: lwc1        $f0, 0x6FB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FB4);
L_80102A98:
    // 0x80102A98: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102A9C: lwc1        $f2, 0x35B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X35B4);
    // 0x80102AA0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80102AA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80102AA8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80102AAC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102AB0: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80102AB4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80102AB8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80102ABC: lui         $fp, 0xB300
    ctx->r30 = S32(0XB300 << 16);
    // 0x80102AC0: lui         $s7, 0xB400
    ctx->r23 = S32(0XB400 << 16);
    // 0x80102AC4: bc1fl       L_80102ADC
    if (!c1cs) {
        // 0x80102AC8: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80102ADC;
    }
    goto skip_1;
    // 0x80102AC8: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_1:
    // 0x80102ACC: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80102AD0: b           L_80102AF0
    // 0x80102AD4: sb          $zero, 0x35BC($at)
    MEM_B(0X35BC, ctx->r1) = 0;
        goto L_80102AF0;
    // 0x80102AD4: sb          $zero, 0x35BC($at)
    MEM_B(0X35BC, ctx->r1) = 0;
    // 0x80102AD8: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_80102ADC:
    // 0x80102ADC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102AE0: bc1f        L_80102AF0
    if (!c1cs) {
        // 0x80102AE4: nop
    
            goto L_80102AF0;
    }
    // 0x80102AE4: nop

    // 0x80102AE8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80102AEC: sb          $zero, 0x35BC($at)
    MEM_B(0X35BC, ctx->r1) = 0;
L_80102AF0:
    // 0x80102AF0: lw          $t8, 0x35B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X35B0);
    // 0x80102AF4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102AF8: swc1        $f2, 0x35B4($at)
    MEM_W(0X35B4, ctx->r1) = ctx->f2.u32l;
    // 0x80102AFC: slti        $at, $t8, 0x36D8
    ctx->r1 = SIGNED(ctx->r24) < 0X36D8 ? 1 : 0;
    // 0x80102B00: beq         $at, $zero, L_80102F80
    if (ctx->r1 == 0) {
        // 0x80102B04: lui         $t8, 0xFB00
        ctx->r24 = S32(0XFB00 << 16);
            goto L_80102F80;
    }
    // 0x80102B04: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80102B08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102B0C: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80102B10: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80102B14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102B18: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102B1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102B20: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102B24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102B28: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80102B2C: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80102B30: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102B34: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80102B38: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102B3C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80102B40: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80102B44: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102B48: lw          $t9, 0x1A8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1A8);
    // 0x80102B4C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80102B50: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102B54: addiu       $t7, $t7, 0x61C0
    ctx->r15 = ADD32(ctx->r15, 0X61C0);
    // 0x80102B58: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x80102B5C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80102B60: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80102B64: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x80102B68: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102B6C: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x80102B70: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102B74: sw          $t8, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r24;
    // 0x80102B78: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x80102B7C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102B80: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80102B84: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80102B88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102B8C: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80102B90: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80102B94: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102B98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80102B9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102BA0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102BA4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80102BA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102BAC: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x80102BB0: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80102BB4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102BB8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102BBC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102BC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102BC4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80102BC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102BCC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80102BD0: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x80102BD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102BD8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102BDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102BE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102BE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102BE8: lui         $t8, 0x73F
    ctx->r24 = S32(0X73F << 16);
    // 0x80102BEC: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x80102BF0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102BF4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80102BF8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102BFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102C00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102C04: swc1        $f2, 0x35B4($at)
    MEM_W(0X35B4, ctx->r1) = ctx->f2.u32l;
    // 0x80102C08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102C0C: lwc1        $f16, 0x35AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X35AC);
    // 0x80102C10: lw          $t3, 0x184($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X184);
    // 0x80102C14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102C18: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80102C1C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80102C20: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102C24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102C28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80102C2C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80102C30: addiu       $t6, $zero, 0x137
    ctx->r14 = ADD32(0, 0X137);
    // 0x80102C34: divu        $zero, $a2, $t3
    lo = S32(U32(ctx->r6) / U32(ctx->r11)); hi = S32(U32(ctx->r6) % U32(ctx->r11));
    // 0x80102C38: mfhi        $a0
    ctx->r4 = hi;
    // 0x80102C3C: addiu       $s3, $t3, -0x1
    ctx->r19 = ADD32(ctx->r11, -0X1);
    // 0x80102C40: andi        $t8, $s3, 0xFFF
    ctx->r24 = ctx->r19 & 0XFFF;
    // 0x80102C44: subu        $s4, $t6, $a0
    ctx->r20 = SUB32(ctx->r14, ctx->r4);
    // 0x80102C48: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80102C4C: or          $s3, $t8, $at
    ctx->r19 = ctx->r24 | ctx->r1;
    // 0x80102C50: sra         $t7, $s4, 3
    ctx->r15 = S32(SIGNED(ctx->r20) >> 3);
    // 0x80102C54: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80102C58: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80102C5C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80102C60: andi        $t7, $t0, 0xFFF
    ctx->r15 = ctx->r8 & 0XFFF;
    // 0x80102C64: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80102C68: or          $s4, $t9, $at
    ctx->r20 = ctx->r25 | ctx->r1;
    // 0x80102C6C: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80102C70: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80102C74: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80102C78: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80102C7C: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x80102C80: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80102C84: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80102C88: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80102C8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102C90: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x80102C94: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80102C98: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80102C9C: addiu       $s5, $a0, 0x7
    ctx->r21 = ADD32(ctx->r4, 0X7);
    // 0x80102CA0: sra         $t7, $s5, 3
    ctx->r15 = S32(SIGNED(ctx->r21) >> 3);
    // 0x80102CA4: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80102CA8: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x80102CAC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80102CB0: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80102CB4: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x80102CB8: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80102CBC: addiu       $t7, $zero, 0x130
    ctx->r15 = ADD32(0, 0X130);
    // 0x80102CC0: subu        $s6, $t7, $a0
    ctx->r22 = SUB32(ctx->r15, ctx->r4);
    // 0x80102CC4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80102CC8: or          $s5, $t9, $at
    ctx->r21 = ctx->r25 | ctx->r1;
    // 0x80102CCC: sll         $t8, $s6, 2
    ctx->r24 = S32(ctx->r22 << 2);
    // 0x80102CD0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80102CD4: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80102CD8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80102CDC: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x80102CE0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80102CE4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80102CE8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80102CEC: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80102CF0: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80102CF4: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80102CF8: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80102CFC: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80102D00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80102D04: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80102D08: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x80102D0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80102D10: bne         $t3, $zero, L_80102D1C
    if (ctx->r11 != 0) {
        // 0x80102D14: nop
    
            goto L_80102D1C;
    }
    // 0x80102D14: nop

    // 0x80102D18: break       7
    do_break(2148543768);
L_80102D1C:
    // 0x80102D1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102D20: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80102D24: sll         $a0, $t5, 2
    ctx->r4 = S32(ctx->r13 << 2);
    // 0x80102D28: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102D2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80102D30: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80102D34: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80102D38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102D3C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80102D40: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x80102D44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102D48: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102D4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102D50: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80102D54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102D58: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x80102D5C: lui         $at, 0x74B
    ctx->r1 = S32(0X74B << 16);
    // 0x80102D60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102D64: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80102D68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102D6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102D70: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102D74: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80102D78: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80102D7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102D80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102D84: andi        $t8, $a1, 0xFFF
    ctx->r24 = ctx->r5 & 0XFFF;
    // 0x80102D88: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80102D8C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80102D90: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80102D94: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102D98: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102D9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102DA0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80102DA4: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80102DA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102DAC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80102DB0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102DB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102DB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102DBC: lui         $at, 0x4B
    ctx->r1 = S32(0X4B << 16);
    // 0x80102DC0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80102DC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102DC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102DCC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102DD0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80102DD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102DD8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80102DDC: or          $t8, $a1, $at
    ctx->r24 = ctx->r5 | ctx->r1;
    // 0x80102DE0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102DE4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102DE8: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80102DEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102DF0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102DF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102DF8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80102DFC: sll         $a3, $ra, 2
    ctx->r7 = S32(ctx->r31 << 2);
    // 0x80102E00: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102E04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102E08: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x80102E0C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80102E10: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102E14: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80102E18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102E1C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80102E20: sll         $s0, $t5, 5
    ctx->r16 = S32(ctx->r13 << 5);
    // 0x80102E24: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102E28: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102E2C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102E30: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80102E34: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x80102E38: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80102E3C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80102E40: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102E44: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102E48: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80102E4C: ori         $t6, $t6, 0x400
    ctx->r14 = ctx->r14 | 0X400;
    // 0x80102E50: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80102E54: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80102E58: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102E5C: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80102E60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102E64: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80102E68: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80102E6C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102E70: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80102E74: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80102E78: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80102E7C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102E80: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80102E84: addiu       $ra, $ra, 0x6
    ctx->r31 = ADD32(ctx->r31, 0X6);
    // 0x80102E88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102E8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102E90: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102E94: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80102E98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102E9C: or          $t9, $a0, $at
    ctx->r25 = ctx->r4 | ctx->r1;
    // 0x80102EA0: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80102EA4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102EA8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80102EAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102EB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80102EB4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102EB8: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80102EBC: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80102EC0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102EC4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102EC8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102ECC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80102ED0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80102ED4: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80102ED8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80102EDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102EE0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80102EE4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80102EE8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102EEC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80102EF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102EF4: or          $t8, $a0, $at
    ctx->r24 = ctx->r4 | ctx->r1;
    // 0x80102EF8: lui         $at, 0xE44C
    ctx->r1 = S32(0XE44C << 16);
    // 0x80102EFC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102F00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80102F04: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80102F08: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80102F0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102F10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102F14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80102F18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102F1C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80102F20: or          $t8, $a3, $at
    ctx->r24 = ctx->r7 | ctx->r1;
    // 0x80102F24: addiu       $at, $zero, 0xE4
    ctx->r1 = ADD32(0, 0XE4);
    // 0x80102F28: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x80102F2C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80102F30: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102F34: or          $t9, $s6, $a0
    ctx->r25 = ctx->r22 | ctx->r4;
    // 0x80102F38: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102F3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80102F40: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80102F44: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80102F48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102F4C: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80102F50: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x80102F54: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80102F58: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80102F5C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80102F60: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80102F64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80102F68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80102F6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80102F70: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80102F74: bne         $ra, $at, L_80102D1C
    if (ctx->r31 != ctx->r1) {
        // 0x80102F78: sw          $fp, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r30;
            goto L_80102D1C;
    }
    // 0x80102F78: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x80102F7C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80102F80:
    // 0x80102F80: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80102F84: lbu         $v0, 0x35C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X35C0);
    // 0x80102F88: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102F8C: lwc1        $f16, 0x35AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X35AC);
    // 0x80102F90: lui         $s7, 0xB400
    ctx->r23 = S32(0XB400 << 16);
    // 0x80102F94: beq         $v0, $zero, L_80102FB8
    if (ctx->r2 == 0) {
        // 0x80102F98: lui         $fp, 0xB300
        ctx->r30 = S32(0XB300 << 16);
            goto L_80102FB8;
    }
    // 0x80102F98: lui         $fp, 0xB300
    ctx->r30 = S32(0XB300 << 16);
    // 0x80102F9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80102FA0: beq         $v0, $at, L_80102FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80102FA4: nop
    
            goto L_80102FC0;
    }
    // 0x80102FA4: nop

    // 0x80102FA8: beq         $v0, $s0, L_80102FCC
    if (ctx->r2 == ctx->r16) {
        // 0x80102FAC: lui         $at, 0x8015
        ctx->r1 = S32(0X8015 << 16);
            goto L_80102FCC;
    }
    // 0x80102FAC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80102FB0: b           L_80102FD0
    // 0x80102FB4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80102FD0;
    // 0x80102FB4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80102FB8:
    // 0x80102FB8: b           L_80102FD0
    // 0x80102FBC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80102FD0;
    // 0x80102FBC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80102FC0:
    // 0x80102FC0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80102FC4: b           L_80102FD0
    // 0x80102FC8: lwc1        $f0, 0x6FB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FB8);
        goto L_80102FD0;
    // 0x80102FC8: lwc1        $f0, 0x6FB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FB8);
L_80102FCC:
    // 0x80102FCC: lwc1        $f0, 0x6FBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6FBC);
L_80102FD0:
    // 0x80102FD0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102FD4: lwc1        $f2, 0x35B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X35B8);
    // 0x80102FD8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80102FDC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80102FE0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80102FE4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80102FE8: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80102FEC: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x80102FF0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80102FF4: nop

    // 0x80102FF8: bc1fl       L_80103010
    if (!c1cs) {
        // 0x80102FFC: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_80103010;
    }
    goto skip_2;
    // 0x80102FFC: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_2:
    // 0x80103000: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80103004: b           L_80103040
    // 0x80103008: sb          $zero, 0x35C0($at)
    MEM_B(0X35C0, ctx->r1) = 0;
        goto L_80103040;
    // 0x80103008: sb          $zero, 0x35C0($at)
    MEM_B(0X35C0, ctx->r1) = 0;
    // 0x8010300C: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_80103010:
    // 0x80103010: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80103014: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80103018: bc1f        L_80103040
    if (!c1cs) {
        // 0x8010301C: nop
    
            goto L_80103040;
    }
    // 0x8010301C: nop

    // 0x80103020: lbu         $t9, 0x35C4($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X35C4);
    // 0x80103024: sb          $zero, 0x35C0($at)
    MEM_B(0X35C0, ctx->r1) = 0;
    // 0x80103028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8010302C: bne         $t9, $at, L_80103040
    if (ctx->r25 != ctx->r1) {
        // 0x80103030: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_80103040;
    }
    // 0x80103030: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80103034: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80103038: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010303C: sb          $t6, 0x35C4($at)
    MEM_B(0X35C4, ctx->r1) = ctx->r14;
L_80103040:
    // 0x80103040: lw          $t7, 0x35B0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X35B0);
    // 0x80103044: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80103048: swc1        $f2, 0x35B8($at)
    MEM_W(0X35B8, ctx->r1) = ctx->f2.u32l;
    // 0x8010304C: slti        $at, $t7, 0x3570
    ctx->r1 = SIGNED(ctx->r15) < 0X3570 ? 1 : 0;
    // 0x80103050: bne         $at, $zero, L_801034C8
    if (ctx->r1 != 0) {
        // 0x80103054: lui         $t9, 0xE700
        ctx->r25 = S32(0XE700 << 16);
            goto L_801034C8;
    }
    // 0x80103054: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80103058: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010305C: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80103060: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80103064: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103068: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8010306C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103070: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80103074: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103078: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8010307C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80103080: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103084: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103088: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8010308C: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80103090: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80103094: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103098: lw          $t8, 0x1A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1A8);
    // 0x8010309C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x801030A0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x801030A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801030A8: addiu       $t6, $t6, 0x61C0
    ctx->r14 = ADD32(ctx->r14, 0X61C0);
    // 0x801030AC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x801030B0: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x801030B4: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x801030B8: lw          $t5, 0x14($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14);
    // 0x801030BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801030C0: lw          $s2, 0x10($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X10);
    // 0x801030C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801030C8: sw          $t7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r15;
    // 0x801030CC: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x801030D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801030D4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x801030D8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801030DC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801030E0: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x801030E4: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x801030E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801030EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801030F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801030F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801030F8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x801030FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103100: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80103104: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x80103108: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8010310C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103110: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80103114: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80103118: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010311C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80103120: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80103124: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103128: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010312C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103130: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103134: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103138: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8010313C: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80103140: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103144: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103148: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8010314C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103150: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103154: lw          $t3, 0x184($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X184);
    // 0x80103158: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8010315C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80103160: swc1        $f2, 0x35B8($at)
    MEM_W(0X35B8, ctx->r1) = ctx->f2.u32l;
    // 0x80103164: divu        $zero, $a2, $t3
    lo = S32(U32(ctx->r6) / U32(ctx->r11)); hi = S32(U32(ctx->r6) % U32(ctx->r11));
    // 0x80103168: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8010316C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103170: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80103174: mfhi        $a0
    ctx->r4 = hi;
    // 0x80103178: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010317C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103180: addiu       $t9, $zero, 0x137
    ctx->r25 = ADD32(0, 0X137);
    // 0x80103184: addiu       $s3, $t3, -0x1
    ctx->r19 = ADD32(ctx->r11, -0X1);
    // 0x80103188: andi        $t7, $s3, 0xFFF
    ctx->r15 = ctx->r19 & 0XFFF;
    // 0x8010318C: subu        $s4, $t9, $a0
    ctx->r20 = SUB32(ctx->r25, ctx->r4);
    // 0x80103190: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80103194: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103198: sra         $t6, $s4, 3
    ctx->r14 = S32(SIGNED(ctx->r20) >> 3);
    // 0x8010319C: or          $s3, $t7, $at
    ctx->r19 = ctx->r15 | ctx->r1;
    // 0x801031A0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x801031A4: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x801031A8: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x801031AC: andi        $t6, $t0, 0xFFF
    ctx->r14 = ctx->r8 & 0XFFF;
    // 0x801031B0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x801031B4: or          $s4, $t8, $at
    ctx->r20 = ctx->r24 | ctx->r1;
    // 0x801031B8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x801031BC: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x801031C0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x801031C4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801031C8: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x801031CC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x801031D0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x801031D4: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x801031D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801031DC: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x801031E0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x801031E4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x801031E8: addiu       $s5, $a0, 0x7
    ctx->r21 = ADD32(ctx->r4, 0X7);
    // 0x801031EC: sra         $t6, $s5, 3
    ctx->r14 = S32(SIGNED(ctx->r21) >> 3);
    // 0x801031F0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x801031F4: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x801031F8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x801031FC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80103200: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x80103204: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80103208: addiu       $t6, $zero, 0x130
    ctx->r14 = ADD32(0, 0X130);
    // 0x8010320C: subu        $s6, $t6, $a0
    ctx->r22 = SUB32(ctx->r14, ctx->r4);
    // 0x80103210: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80103214: or          $s5, $t8, $at
    ctx->r21 = ctx->r24 | ctx->r1;
    // 0x80103218: sll         $t7, $s6, 2
    ctx->r15 = S32(ctx->r22 << 2);
    // 0x8010321C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80103220: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80103224: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80103228: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x8010322C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80103230: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80103234: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80103238: or          $s6, $t9, $zero
    ctx->r22 = ctx->r25 | 0;
    // 0x8010323C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80103240: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80103244: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80103248: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8010324C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80103250: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80103254: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80103258: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8010325C: bne         $t3, $zero, L_80103268
    if (ctx->r11 != 0) {
        // 0x80103260: nop
    
            goto L_80103268;
    }
    // 0x80103260: nop

    // 0x80103264: break       7
    do_break(2148545124);
L_80103268:
    // 0x80103268: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010326C: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x80103270: sll         $a0, $t5, 2
    ctx->r4 = S32(ctx->r13 << 2);
    // 0x80103274: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103278: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010327C: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x80103280: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80103284: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103288: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8010328C: sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17 << 2);
    // 0x80103290: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103294: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103298: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8010329C: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x801032A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801032A4: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
    // 0x801032A8: lui         $at, 0x74B
    ctx->r1 = S32(0X74B << 16);
    // 0x801032AC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801032B0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801032B4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801032B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801032BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801032C0: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x801032C4: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x801032C8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801032CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801032D0: andi        $t7, $a1, 0xFFF
    ctx->r15 = ctx->r5 & 0XFFF;
    // 0x801032D4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x801032D8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x801032DC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x801032E0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801032E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801032E8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801032EC: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x801032F0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x801032F4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801032F8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801032FC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103300: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103304: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103308: lui         $at, 0x4B
    ctx->r1 = S32(0X4B << 16);
    // 0x8010330C: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80103310: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103314: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103318: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8010331C: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
    // 0x80103320: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103324: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80103328: or          $t7, $a1, $at
    ctx->r15 = ctx->r5 | ctx->r1;
    // 0x8010332C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103330: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103334: or          $t6, $t9, $a0
    ctx->r14 = ctx->r25 | ctx->r4;
    // 0x80103338: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8010333C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103340: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103344: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80103348: sll         $a3, $ra, 2
    ctx->r7 = S32(ctx->r31 << 2);
    // 0x8010334C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103350: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103354: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x80103358: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8010335C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103360: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80103364: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103368: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8010336C: sll         $s0, $t5, 5
    ctx->r16 = S32(ctx->r13 << 5);
    // 0x80103370: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80103374: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80103378: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8010337C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80103380: andi        $t9, $s0, 0xFFFF
    ctx->r25 = ctx->r16 & 0XFFFF;
    // 0x80103384: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80103388: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8010338C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80103390: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103394: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80103398: ori         $t9, $t9, 0x400
    ctx->r25 = ctx->r25 | 0X400;
    // 0x8010339C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801033A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801033A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801033A8: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x801033AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801033B0: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x801033B4: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x801033B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801033BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801033C0: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x801033C4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801033C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801033CC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x801033D0: addiu       $ra, $ra, 0x6
    ctx->r31 = ADD32(ctx->r31, 0X6);
    // 0x801033D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801033D8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801033DC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801033E0: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x801033E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801033E8: or          $t8, $a0, $at
    ctx->r24 = ctx->r4 | ctx->r1;
    // 0x801033EC: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801033F0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801033F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801033F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801033FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80103400: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103404: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80103408: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x8010340C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103410: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103414: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80103418: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8010341C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80103420: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x80103424: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80103428: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010342C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80103430: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80103434: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103438: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010343C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103440: or          $t7, $a0, $at
    ctx->r15 = ctx->r4 | ctx->r1;
    // 0x80103444: lui         $at, 0xE44C
    ctx->r1 = S32(0XE44C << 16);
    // 0x80103448: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8010344C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103450: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103454: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80103458: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010345C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103460: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103464: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103468: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8010346C: or          $t7, $a3, $at
    ctx->r15 = ctx->r7 | ctx->r1;
    // 0x80103470: addiu       $at, $zero, 0xE4
    ctx->r1 = ADD32(0, 0XE4);
    // 0x80103474: or          $t9, $t8, $a1
    ctx->r25 = ctx->r24 | ctx->r5;
    // 0x80103478: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8010347C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103480: or          $t8, $s6, $a0
    ctx->r24 = ctx->r22 | ctx->r4;
    // 0x80103484: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80103488: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8010348C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103490: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103494: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103498: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8010349C: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x801034A0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801034A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801034A8: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x801034AC: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x801034B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801034B4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801034B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801034BC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801034C0: bne         $ra, $at, L_80103268
    if (ctx->r31 != ctx->r1) {
        // 0x801034C4: sw          $fp, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r30;
            goto L_80103268;
    }
    // 0x801034C4: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
L_801034C8:
    // 0x801034C8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801034CC: lw          $t8, 0x35B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X35B0);
    // 0x801034D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x801034D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801034D8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801034DC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801034E0: sw          $t9, 0x35B0($at)
    MEM_W(0X35B0, ctx->r1) = ctx->r25;
    // 0x801034E4: lui         $at, 0x406E
    ctx->r1 = S32(0X406E << 16);
    // 0x801034E8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x801034EC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x801034F0: slti        $at, $t9, 0x35AC
    ctx->r1 = SIGNED(ctx->r25) < 0X35AC ? 1 : 0;
    // 0x801034F4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x801034F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801034FC: c.le.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d <= ctx->f10.d;
    // 0x80103500: nop

    // 0x80103504: bc1f        L_80103550
    if (!c1cs) {
        // 0x80103508: nop
    
            goto L_80103550;
    }
    // 0x80103508: nop

    // 0x8010350C: beq         $at, $zero, L_80103550
    if (ctx->r1 == 0) {
        // 0x80103510: lw          $t6, 0x184($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X184);
            goto L_80103550;
    }
    // 0x80103510: lw          $t6, 0x184($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X184);
    // 0x80103514: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80103518: lw          $t7, 0x1AC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1AC);
    // 0x8010351C: bgez        $t6, L_80103534
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80103520: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80103534;
    }
    // 0x80103520: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80103524: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80103528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010352C: nop

    // 0x80103530: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80103534:
    // 0x80103534: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80103538: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010353C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80103540: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80103544: sub.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80103548: b           L_80103568
    // 0x8010354C: swc1        $f16, 0x35AC($at)
    MEM_W(0X35AC, ctx->r1) = ctx->f16.u32l;
        goto L_80103568;
    // 0x8010354C: swc1        $f16, 0x35AC($at)
    MEM_W(0X35AC, ctx->r1) = ctx->f16.u32l;
L_80103550:
    // 0x80103550: lw          $t8, 0x35B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X35B0);
    // 0x80103554: addiu       $at, $zero, 0x35AC
    ctx->r1 = ADD32(0, 0X35AC);
    // 0x80103558: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8010355C: bne         $t8, $at, L_80103568
    if (ctx->r24 != ctx->r1) {
        // 0x80103560: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80103568;
    }
    // 0x80103560: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80103564: sb          $t9, 0x35C4($at)
    MEM_B(0X35C4, ctx->r1) = ctx->r25;
L_80103568:
    // 0x80103568: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010356C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103570: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80103574: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80103578: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010357C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80103580: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80103584: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80103588: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8010358C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80103590: jr          $ra
    // 0x80103594: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x80103594: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    // 0x80103598: nop

    // 0x8010359C: nop

;}
RECOMP_FUNC void func_80100000_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100008: jal         0x80100970
    // 0x8010000C: nop

    func_80100970_ovl_ending(rdram, ctx);
        goto after_0;
    // 0x8010000C: nop

    after_0:
    // 0x80100010: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80100014: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80100018: sw          $t6, 0x6FC0($at)
    MEM_W(0X6FC0, ctx->r1) = ctx->r14;
    // 0x8010001C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80100020: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80100024: sw          $t7, 0x6FC4($at)
    MEM_W(0X6FC4, ctx->r1) = ctx->r15;
    // 0x80100028: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8010002C: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x80100030: sw          $t8, 0x6FC8($at)
    MEM_W(0X6FC8, ctx->r1) = ctx->r24;
    // 0x80100034: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80100038: addiu       $t9, $zero, 0xDF
    ctx->r25 = ADD32(0, 0XDF);
    // 0x8010003C: sw          $t9, 0x6FCC($at)
    MEM_W(0X6FCC, ctx->r1) = ctx->r25;
    // 0x80100040: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80100044: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
    // 0x80100048: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8010004C: sw          $zero, 0x6FE0($at)
    MEM_W(0X6FE0, ctx->r1) = 0;
    // 0x80100050: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80100054: sw          $zero, 0x6FD0($at)
    MEM_W(0X6FD0, ctx->r1) = 0;
    // 0x80100058: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8010005C: sw          $zero, 0x6FD4($at)
    MEM_W(0X6FD4, ctx->r1) = 0;
    // 0x80100060: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80100064: sw          $zero, 0x6FE4($at)
    MEM_W(0X6FE4, ctx->r1) = 0;
    // 0x80100068: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8010006C: sw          $zero, 0x35A0($at)
    MEM_W(0X35A0, ctx->r1) = 0;
    // 0x80100070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100074: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80100078: sw          $zero, 0x35A4($at)
    MEM_W(0X35A4, ctx->r1) = 0;
    // 0x8010007C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80100080: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
    // 0x80100084: jr          $ra
    // 0x80100088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80100088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003265C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003265C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032660: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80032664: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80032668: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003266C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80032670: addiu       $a0, $a0, -0x3378
    ctx->r4 = ADD32(ctx->r4, -0X3378);
    // 0x80032674: jal         0x80032218
    // 0x80032678: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    func_80032218(rdram, ctx);
        goto after_0;
    // 0x80032678: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_0:
    // 0x8003267C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80032680: jal         0x80032560
    // 0x80032684: lhu         $a0, 0x2D1A($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2D1A);
    func_80032560(rdram, ctx);
        goto after_1;
    // 0x80032684: lhu         $a0, 0x2D1A($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2D1A);
    after_1:
    // 0x80032688: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8003268C: lbu         $v0, 0x2D0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D0E);
    // 0x80032690: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80032694: addiu       $a0, $a0, -0x1D78
    ctx->r4 = ADD32(ctx->r4, -0X1D78);
    // 0x80032698: beql        $v0, $zero, L_800326B4
    if (ctx->r2 == 0) {
        // 0x8003269C: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_800326B4;
    }
    goto skip_0;
    // 0x8003269C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    skip_0:
    // 0x800326A0: jal         0x80032218
    // 0x800326A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80032218(rdram, ctx);
        goto after_2;
    // 0x800326A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800326A8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800326AC: lbu         $v0, 0x2D0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D0E);
    // 0x800326B0: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
L_800326B4:
    // 0x800326B4: beq         $at, $zero, L_800326C8
    if (ctx->r1 == 0) {
        // 0x800326B8: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_800326C8;
    }
    // 0x800326B8: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x800326BC: addiu       $a0, $a0, -0x1D68
    ctx->r4 = ADD32(ctx->r4, -0X1D68);
    // 0x800326C0: jal         0x80032218
    // 0x800326C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80032218(rdram, ctx);
        goto after_3;
    // 0x800326C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_800326C8:
    // 0x800326C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800326CC: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_800326D0:
    // 0x800326D0: jal         0x8003232C
    // 0x800326D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003232C(rdram, ctx);
        goto after_4;
    // 0x800326D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800326D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800326DC: bne         $s0, $s1, L_800326D0
    if (ctx->r16 != ctx->r17) {
        // 0x800326E0: nop
    
            goto L_800326D0;
    }
    // 0x800326E0: nop

    // 0x800326E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800326E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800326EC: sw          $t6, 0x2D1C($at)
    MEM_W(0X2D1C, ctx->r1) = ctx->r14;
    // 0x800326F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800326F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800326F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800326FC: jr          $ra
    // 0x80032700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80032700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80014ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014ED4: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80014ED8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014EDC: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80014EE0: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80014EE4: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80014EE8: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x80014EEC: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x80014EF0: bnel        $t6, $at, L_80014F0C
    if (ctx->r14 != ctx->r1) {
        // 0x80014EF4: lwc1        $f10, 0x1C($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_80014F0C;
    }
    goto skip_0;
    // 0x80014EF4: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x80014EF8: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x80014EFC: lwc1        $f8, 0x94($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X94);
    // 0x80014F00: jr          $ra
    // 0x80014F04: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80014F04: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80014F08: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
L_80014F0C:
    // 0x80014F0C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014F10: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80014F14: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80014F18: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80014F1C: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80014F20: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80014F24: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80014F28: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80014F2C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80014F30: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80014F34: add.d       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f18.d + ctx->f10.d;
    // 0x80014F38: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80014F3C: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80014F40: jr          $ra
    // 0x80014F44: nop

    return;
    // 0x80014F44: nop

;}
RECOMP_FUNC void func_80101834_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101834: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101838: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8010183C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80101840: addiu       $t7, $t7, 0x6FE8
    ctx->r15 = ADD32(ctx->r15, 0X6FE8);
    // 0x80101844: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101848: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8010184C: lh          $t8, 0x34($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X34);
    // 0x80101850: lw          $t1, 0x38($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X38);
    // 0x80101854: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80101858: sh          $t9, 0x34($v0)
    MEM_H(0X34, ctx->r2) = ctx->r25;
    // 0x8010185C: lh          $t0, 0x34($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X34);
    // 0x80101860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101864: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80101868: bne         $at, $zero, L_80101878
    if (ctx->r1 != 0) {
        // 0x8010186C: nop
    
            goto L_80101878;
    }
    // 0x8010186C: nop

    // 0x80101870: jr          $ra
    // 0x80101874: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80101874: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101878:
    // 0x80101878: jr          $ra
    // 0x8010187C: nop

    return;
    // 0x8010187C: nop

;}
RECOMP_FUNC void func_8000FDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FDE0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000FDE4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8000FDE8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000FDEC: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x8000FDF0: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8000FDF4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000FDF8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000FDFC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000FE00: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000FE04: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000FE08: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8000FE0C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000FE10: lw          $v0, 0x4F1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4F1C);
    // 0x8000FE14: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8000FE18: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x8000FE1C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8000FE20: beq         $v1, $zero, L_8000FE3C
    if (ctx->r3 == 0) {
        // 0x8000FE24: nop
    
            goto L_8000FE3C;
    }
    // 0x8000FE24: nop

    // 0x8000FE28: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x8000FE2C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x8000FE30: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000FE34: beq         $t7, $zero, L_8000FE44
    if (ctx->r15 == 0) {
        // 0x8000FE38: nop
    
            goto L_8000FE44;
    }
    // 0x8000FE38: nop

L_8000FE3C:
    // 0x8000FE3C: b           L_8000FF30
    // 0x8000FE40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000FF30;
    // 0x8000FE40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000FE44:
    // 0x8000FE44: beq         $v1, $zero, L_8000FF2C
    if (ctx->r3 == 0) {
        // 0x8000FE48: lw          $s0, 0x4($v0)
        ctx->r16 = MEM_W(ctx->r2, 0X4);
            goto L_8000FF2C;
    }
    // 0x8000FE48: lw          $s0, 0x4($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X4);
    // 0x8000FE4C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8000FE50: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000FE54: addiu       $s1, $s1, 0x5358
    ctx->r17 = ADD32(ctx->r17, 0X5358);
L_8000FE58:
    // 0x8000FE58: jal         0x8000FFE8
    // 0x8000FE5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000FFE8(rdram, ctx);
        goto after_0;
    // 0x8000FE5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000FE60: beql        $v0, $zero, L_8000FF24
    if (ctx->r2 == 0) {
        // 0x8000FE64: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000FF24;
    }
    goto skip_0;
    // 0x8000FE64: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x8000FE68: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8000FE6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000FE70: sub.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x8000FE74: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x8000FE78: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8000FE7C: sub.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x8000FE80: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8000FE84: jal         0x800232F4
    // 0x8000FE88: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x8000FE88: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x8000FE8C: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8000FE90: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8000FE94: nop

    // 0x8000FE98: bc1fl       L_8000FEA8
    if (!c1cs) {
        // 0x8000FE9C: lwc1        $f2, 0x4($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
            goto L_8000FEA8;
    }
    goto skip_1;
    // 0x8000FE9C: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x8000FEA0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8000FEA4: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
L_8000FEA8:
    // 0x8000FEA8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8000FEAC: nop

    // 0x8000FEB0: bc1fl       L_8000FEC0
    if (!c1cs) {
        // 0x8000FEB4: lwc1        $f16, 0xC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8000FEC0;
    }
    goto skip_2;
    // 0x8000FEB4: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    skip_2:
    // 0x8000FEB8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8000FEBC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_8000FEC0:
    // 0x8000FEC0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8000FEC4: nop

    // 0x8000FEC8: bc1fl       L_8000FF24
    if (!c1cs) {
        // 0x8000FECC: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000FF24;
    }
    goto skip_3;
    // 0x8000FECC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_3:
    // 0x8000FED0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8000FED4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8000FED8: nop

    // 0x8000FEDC: bc1fl       L_8000FF24
    if (!c1cs) {
        // 0x8000FEE0: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8000FF24;
    }
    goto skip_4;
    // 0x8000FEE0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_4:
    // 0x8000FEE4: lhu         $t8, 0x14($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X14);
    // 0x8000FEE8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8000FEEC: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8000FEF0: bne         $t9, $zero, L_8000FF0C
    if (ctx->r25 != 0) {
        // 0x8000FEF4: nop
    
            goto L_8000FF0C;
    }
    // 0x8000FEF4: nop

    // 0x8000FEF8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8000FEFC: jal         0x8000FF54
    // 0x8000FF00: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_8000FF54(rdram, ctx);
        goto after_2;
    // 0x8000FF00: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x8000FF04: beql        $v0, $zero, L_8000FF30
    if (ctx->r2 == 0) {
        // 0x8000FF08: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_8000FF30;
    }
    goto skip_5;
    // 0x8000FF08: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_5:
L_8000FF0C:
    // 0x8000FF0C: jal         0x80010080
    // 0x8000FF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80010080(rdram, ctx);
        goto after_3;
    // 0x8000FF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8000FF14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000FF18: b           L_8000FF2C
    // 0x8000FF1C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
        goto L_8000FF2C;
    // 0x8000FF1C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x8000FF20: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8000FF24:
    // 0x8000FF24: bne         $s2, $zero, L_8000FE58
    if (ctx->r18 != 0) {
        // 0x8000FF28: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_8000FE58;
    }
    // 0x8000FF28: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
L_8000FF2C:
    // 0x8000FF2C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_8000FF30:
    // 0x8000FF30: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000FF34: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000FF38: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000FF3C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8000FF40: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000FF44: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000FF48: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000FF4C: jr          $ra
    // 0x8000FF50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8000FF50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8000C42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C42C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8000C430: lw          $t6, 0x4EE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4EE4);
    // 0x8000C434: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000C438: sw          $zero, -0x2D2C($at)
    MEM_W(-0X2D2C, ctx->r1) = 0;
    // 0x8000C43C: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8000C440: bne         $t6, $at, L_8000C4BC
    if (ctx->r14 != ctx->r1) {
        // 0x8000C444: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000C4BC;
    }
    // 0x8000C444: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000C448: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000C44C: lhu         $t7, 0x4E22($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X4E22);
    // 0x8000C450: addiu       $v0, $v0, 0x4E24
    ctx->r2 = ADD32(ctx->r2, 0X4E24);
    // 0x8000C454: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8000C458: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C45C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C460: addiu       $v1, $v1, 0x4E22
    ctx->r3 = ADD32(ctx->r3, 0X4E22);
    // 0x8000C464: sh          $t7, 0x4E24($at)
    MEM_H(0X4E24, ctx->r1) = ctx->r15;
    // 0x8000C468: lhu         $t8, -0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, -0X2);
    // 0x8000C46C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x8000C470: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8000C474: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
L_8000C478:
    // 0x8000C478: lhu         $t9, -0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, -0X2);
    // 0x8000C47C: lhu         $t0, -0x4($v1)
    ctx->r8 = MEM_HU(ctx->r3, -0X4);
    // 0x8000C480: lhu         $t1, -0x6($v1)
    ctx->r9 = MEM_HU(ctx->r3, -0X6);
    // 0x8000C484: lhu         $t2, -0x8($v1)
    ctx->r10 = MEM_HU(ctx->r3, -0X8);
    // 0x8000C488: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000C48C: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8000C490: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8000C494: sh          $t0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r8;
    // 0x8000C498: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x8000C49C: bne         $v0, $zero, L_8000C478
    if (ctx->r2 != 0) {
        // 0x8000C4A0: sh          $t2, 0x2($v1)
        MEM_H(0X2, ctx->r3) = ctx->r10;
            goto L_8000C478;
    }
    // 0x8000C4A0: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x8000C4A4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8000C4A8: addiu       $v0, $v0, 0x4ED0
    ctx->r2 = ADD32(ctx->r2, 0X4ED0);
    // 0x8000C4AC: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8000C4B0: lhu         $t3, 0x0($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X0);
    // 0x8000C4B4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000C4B8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_8000C4BC:
    // 0x8000C4BC: jr          $ra
    // 0x8000C4C0: nop

    return;
    // 0x8000C4C0: nop

;}
RECOMP_FUNC void func_8000F0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F0BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000F0C0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000F0C4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8000F0C8: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x8000F0CC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8000F0D0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8000F0D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000F0D8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000F0DC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8000F0E0: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x8000F0E4: lw          $t8, 0x4F24($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4F24);
    // 0x8000F0E8: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8000F0EC: subu        $t7, $t7, $a3
    ctx->r15 = SUB32(ctx->r15, ctx->r7);
    // 0x8000F0F0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000F0F4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8000F0F8: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000F0FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8000F100: ldc1        $f16, 0x1260($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1260);
    // 0x8000F104: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8000F108: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8000F10C: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8000F110: lh          $t9, 0x14($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X14);
    // 0x8000F114: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x8000F118: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8000F11C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8000F120: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000F124: lw          $t2, 0x4F28($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4F28);
    // 0x8000F128: sll         $t1, $t9, 5
    ctx->r9 = S32(ctx->r25 << 5);
    // 0x8000F12C: cvt.s.d     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f22.fl = CVT_S_D(ctx->f18.d);
    // 0x8000F130: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000F134: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8000F138: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8000F13C: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8000F140: c.eq.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl == ctx->f4.fl;
    // 0x8000F144: nop

    // 0x8000F148: bc1tl       L_8000F188
    if (c1cs) {
        // 0x8000F14C: lhu         $t3, 0x16($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0X16);
            goto L_8000F188;
    }
    goto skip_0;
    // 0x8000F14C: lhu         $t3, 0x16($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X16);
    skip_0:
    // 0x8000F150: swc1        $f20, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f20.u32l;
    // 0x8000F154: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x8000F158: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8000F15C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000F160: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000F164: jal         0x800232F4
    // 0x8000F168: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x8000F168: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x8000F16C: lwc1        $f20, 0x34($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000F170: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000F174: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F178: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000F17C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F180: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8000F184: lhu         $t3, 0x16($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X16);
L_8000F188:
    // 0x8000F188: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8000F18C: lhu         $a3, 0x5A($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X5A);
    // 0x8000F190: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8000F194: slti        $at, $t4, 0x10
    ctx->r1 = SIGNED(ctx->r12) < 0X10 ? 1 : 0;
    // 0x8000F198: beql        $at, $zero, L_8000F224
    if (ctx->r1 == 0) {
        // 0x8000F19C: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8000F224;
    }
    goto skip_1;
    // 0x8000F19C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_1:
    // 0x8000F1A0: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x8000F1A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8000F1A8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8000F1AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8000F1B0: jal         0x8000F238
    // 0x8000F1B4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8000F238(rdram, ctx);
        goto after_1;
    // 0x8000F1B4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8000F1B8: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8000F1BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8000F1C0: beq         $v0, $zero, L_8000F220
    if (ctx->r2 == 0) {
        // 0x8000F1C4: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8000F220;
    }
    // 0x8000F1C4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8000F1C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8000F1CC: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000F1D0: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8000F1D4: c.eq.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl == ctx->f16.fl;
    // 0x8000F1D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000F1DC: bc1t        L_8000F220
    if (c1cs) {
        // 0x8000F1E0: swc1        $f10, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
            goto L_8000F220;
    }
    // 0x8000F1E0: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8000F1E4: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8000F1E8: neg.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = -ctx->f22.fl;
    // 0x8000F1EC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8000F1F0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8000F1F4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000F1F8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8000F1FC: jal         0x800232F4
    // 0x8000F200: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x8000F200: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8000F204: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000F208: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8000F20C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000F210: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8000F214: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8000F218: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000F21C: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
L_8000F220:
    // 0x8000F220: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000F224:
    // 0x8000F224: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F228: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000F22C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000F230: jr          $ra
    // 0x8000F234: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000F234: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800188C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800188C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800188C8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800188CC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800188D0: sw          $zero, 0x7208($at)
    MEM_W(0X7208, ctx->r1) = 0;
    // 0x800188D4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800188D8: addiu       $v1, $v1, 0x7250
    ctx->r3 = ADD32(ctx->r3, 0X7250);
    // 0x800188DC: addiu       $a0, $a0, 0x7310
    ctx->r4 = ADD32(ctx->r4, 0X7310);
L_800188E0:
    // 0x800188E0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800188E4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800188E8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800188EC: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x800188F0: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800188F4: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x800188F8: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
    // 0x800188FC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80018900: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    // 0x80018904: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x80018908: bne         $v0, $zero, L_800188E0
    if (ctx->r2 != 0) {
        // 0x8001890C: addiu       $a0, $a0, 0x60
        ctx->r4 = ADD32(ctx->r4, 0X60);
            goto L_800188E0;
    }
    // 0x8001890C: addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    // 0x80018910: jr          $ra
    // 0x80018914: nop

    return;
    // 0x80018914: nop

;}
RECOMP_FUNC void func_8000BA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BA4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BA50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BA54: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000BA58: sll         $a2, $a3, 2
    ctx->r6 = S32(ctx->r7 << 2);
    // 0x8000BA5C: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x8000BA60: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000BA64: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BA68: lw          $v0, -0x5428($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5428);
    // 0x8000BA6C: addiu       $v1, $v1, -0x3690
    ctx->r3 = ADD32(ctx->r3, -0X3690);
    // 0x8000BA70: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
L_8000BA74:
    // 0x8000BA74: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8000BA78: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8000BA7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BA80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000BA84: bne         $a1, $zero, L_8000BA74
    if (ctx->r5 != 0) {
        // 0x8000BA88: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_8000BA74;
    }
    // 0x8000BA88: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x8000BA8C: lui         $v0, 0x803B
    ctx->r2 = S32(0X803B << 16);
    // 0x8000BA90: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000BA94: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8000BA98: lw          $v0, -0x5408($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5408);
    // 0x8000BA9C: addiu       $v1, $v1, -0x3A90
    ctx->r3 = ADD32(ctx->r3, -0X3A90);
    // 0x8000BAA0: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
L_8000BAA4:
    // 0x8000BAA4: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8000BAA8: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8000BAAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000BAB0: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x8000BAB4: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000BAB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000BABC: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x8000BAC0: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x8000BAC4: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x8000BAC8: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x8000BACC: bne         $a1, $zero, L_8000BAA4
    if (ctx->r5 != 0) {
        // 0x8000BAD0: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_8000BAA4;
    }
    // 0x8000BAD0: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
    // 0x8000BAD4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8000BAD8: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8000BADC: addiu       $a1, $a1, -0x2ED0
    ctx->r5 = ADD32(ctx->r5, -0X2ED0);
    // 0x8000BAE0: addiu       $t1, $t1, -0x2E34
    ctx->r9 = ADD32(ctx->r9, -0X2E34);
    // 0x8000BAE4: addiu       $t3, $t1, 0x6C
    ctx->r11 = ADD32(ctx->r9, 0X6C);
    // 0x8000BAE8: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_8000BAEC:
    // 0x8000BAEC: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8000BAF0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8000BAF4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8000BAF8: sw          $at, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r1;
    // 0x8000BAFC: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x8000BB00: sw          $at, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r1;
    // 0x8000BB04: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x8000BB08: bne         $t1, $t3, L_8000BAEC
    if (ctx->r9 != ctx->r11) {
        // 0x8000BB0C: sw          $at, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r1;
            goto L_8000BAEC;
    }
    // 0x8000BB0C: sw          $at, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r1;
    // 0x8000BB10: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000BB14: bne         $a3, $at, L_8000BB40
    if (ctx->r7 != ctx->r1) {
        // 0x8000BB18: sll         $t5, $a3, 3
        ctx->r13 = S32(ctx->r7 << 3);
            goto L_8000BB40;
    }
    // 0x8000BB18: sll         $t5, $a3, 3
    ctx->r13 = S32(ctx->r7 << 3);
    // 0x8000BB1C: lui         $at, 0xC1F8
    ctx->r1 = S32(0XC1F8 << 16);
    // 0x8000BB20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000BB24: lui         $at, 0x430B
    ctx->r1 = S32(0X430B << 16);
    // 0x8000BB28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000BB2C: lui         $at, 0xC3A4
    ctx->r1 = S32(0XC3A4 << 16);
    // 0x8000BB30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000BB34: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8000BB38: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8000BB3C: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
L_8000BB40:
    // 0x8000BB40: subu        $t5, $t5, $a3
    ctx->r13 = SUB32(ctx->r13, ctx->r7);
    // 0x8000BB44: lui         $t6, 0x803B
    ctx->r14 = S32(0X803B << 16);
    // 0x8000BB48: addiu       $t6, $t6, -0x6450
    ctx->r14 = ADD32(ctx->r14, -0X6450);
    // 0x8000BB4C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8000BB50: jal         0x80014434
    // 0x8000BB54: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    func_80014434(rdram, ctx);
        goto after_0;
    // 0x8000BB54: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_0:
    // 0x8000BB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BB5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000BB60: jr          $ra
    // 0x8000BB64: nop

    return;
    // 0x8000BB64: nop

;}
RECOMP_FUNC void func_8004165C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004165C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80041660: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80041664: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80041668: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8004166C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x80041670: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80041674: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x80041678: bne         $a2, $zero, L_80041688
    if (ctx->r6 != 0) {
        // 0x8004167C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_80041688;
    }
    // 0x8004167C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x80041680: b           L_80041854
    // 0x80041684: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_80041854;
    // 0x80041684: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_80041688:
    // 0x80041688: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x8004168C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80041690: beql        $t7, $zero, L_800416FC
    if (ctx->r15 == 0) {
        // 0x80041694: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_800416FC;
    }
    goto skip_0;
    // 0x80041694: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x80041698: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8004169C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800416A0: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800416A4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800416A8: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800416AC: jalr        $t9
    // 0x800416B0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800416B0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800416B4: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x800416B8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800416BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800416C0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800416C4: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800416C8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800416CC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800416D0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800416D4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800416D8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800416DC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800416E0: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800416E4: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800416E8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800416EC: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800416F0: b           L_80041850
    // 0x800416F4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_80041850;
    // 0x800416F4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800416F8: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_800416FC:
    // 0x800416FC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80041700: ldc1        $f4, 0x2068($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X2068);
    // 0x80041704: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80041708: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8004170C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80041710: nop

    // 0x80041714: bc1fl       L_8004172C
    if (!c1cs) {
        // 0x80041718: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_8004172C;
    }
    goto skip_1;
    // 0x80041718: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x8004171C: lwc1        $f8, 0x2070($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2070);
    // 0x80041720: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x80041724: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80041728: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_8004172C:
    // 0x8004172C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80041730: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80041734: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x80041738: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8004173C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80041740: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80041744: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80041748: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8004174C: nop

    // 0x80041750: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80041754: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80041758: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x8004175C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80041760: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80041764: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80041768: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x8004176C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80041770: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80041774: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80041778: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004177C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80041780: nop

    // 0x80041784: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80041788: nop

    // 0x8004178C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80041790: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80041794: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x80041798: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8004179C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800417A0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800417A4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800417A8: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800417AC: jalr        $t9
    // 0x800417B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800417B0: nop

    after_1:
    // 0x800417B4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800417B8: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x800417BC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800417C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800417C4: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800417C8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800417CC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800417D0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800417D4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800417D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800417DC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800417E0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800417E4: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800417E8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800417EC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800417F0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800417F4: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800417F8: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800417FC: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80041800: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80041804: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80041808: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x8004180C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80041810: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80041814: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x80041818: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8004181C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x80041820: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x80041824: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80041828: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8004182C: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x80041830: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x80041834: jal         0x80034DD0
    // 0x80041838: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80041838: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x8004183C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80041840: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80041844: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80041848: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x8004184C: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_80041850:
    // 0x80041850: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80041854:
    // 0x80041854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80041858: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8004185C: jr          $ra
    // 0x80041860: nop

    return;
    // 0x80041860: nop

    // 0x80041864: nop

    // 0x80041868: nop

    // 0x8004186C: nop

;}
RECOMP_FUNC void func_80031F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031F1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80031F20: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80031F24: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80031F28: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80031F2C: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80031F30: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80031F34: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80031F38: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80031F3C: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x80031F40: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80031F44: lw          $t3, 0x2D20($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2D20);
    // 0x80031F48: sh          $a0, 0x2D34($at)
    MEM_H(0X2D34, ctx->r1) = ctx->r4;
    // 0x80031F4C: sll         $t0, $t0, 6
    ctx->r8 = S32(ctx->r8 << 6);
    // 0x80031F50: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80031F54: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x80031F58: sh          $a1, 0x2D36($at)
    MEM_H(0X2D36, ctx->r1) = ctx->r5;
    // 0x80031F5C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80031F60: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80031F64: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80031F68: sw          $t4, 0x2D30($at)
    MEM_W(0X2D30, ctx->r1) = ctx->r12;
    // 0x80031F6C: jr          $ra
    // 0x80031F70: nop

    return;
    // 0x80031F70: nop

;}
RECOMP_FUNC void func_8001A268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A268: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001A26C: lhu         $t6, 0x75A8($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X75A8);
    // 0x8001A270: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A274: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x8001A278: beq         $t6, $zero, L_8001A298
    if (ctx->r14 == 0) {
        // 0x8001A27C: addiu       $v1, $v1, 0x75A8
        ctx->r3 = ADD32(ctx->r3, 0X75A8);
            goto L_8001A298;
    }
    // 0x8001A27C: addiu       $v1, $v1, 0x75A8
    ctx->r3 = ADD32(ctx->r3, 0X75A8);
    // 0x8001A280: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001A284:
    // 0x8001A284: beq         $v0, $zero, L_8001A298
    if (ctx->r2 == 0) {
        // 0x8001A288: addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
            goto L_8001A298;
    }
    // 0x8001A288: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x8001A28C: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x8001A290: bnel        $t7, $zero, L_8001A284
    if (ctx->r15 != 0) {
        // 0x8001A294: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001A284;
    }
    goto skip_0;
    // 0x8001A294: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
L_8001A298:
    // 0x8001A298: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001A29C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001A2A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A2A4: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x8001A2A8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8001A2AC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001A2B0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8001A2B4: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8001A2B8: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001A2BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001A2C0: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8001A2C4: swc1        $f8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f8.u32l;
    // 0x8001A2C8: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001A2CC: addiu       $t9, $t9, -0x4614
    ctx->r25 = ADD32(ctx->r25, -0X4614);
    // 0x8001A2D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001A2D4: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
    // 0x8001A2D8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001A2DC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001A2E0: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8001A2E4: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x8001A2E8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001A2EC: addiu       $t4, $t4, -0x4B20
    ctx->r12 = ADD32(ctx->r12, -0X4B20);
    // 0x8001A2F0: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8001A2F4: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x8001A2F8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001A2FC: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x8001A300: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8001A304: swc1        $f6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f6.u32l;
    // 0x8001A308: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
    // 0x8001A30C: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8001A310: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8001A314: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8001A318: sw          $at, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r1;
    // 0x8001A31C: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x8001A320: lhu         $a0, 0x3A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X3A);
    // 0x8001A324: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x8001A328: sw          $t2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r10;
    // 0x8001A32C: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x8001A330: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8001A334: sh          $a3, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r7;
    // 0x8001A338: sw          $at, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r1;
    // 0x8001A33C: sw          $t5, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r13;
    // 0x8001A340: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8001A344: sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // 0x8001A348: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8001A34C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001A350: addiu       $t8, $t8, -0x57D8
    ctx->r24 = ADD32(ctx->r24, -0X57D8);
    // 0x8001A354: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001A358: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x8001A35C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001A360: sh          $t6, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r14;
    // 0x8001A364: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8001A368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001A36C: sw          $at, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r1;
    // 0x8001A370: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8001A374: sw          $t0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r8;
    // 0x8001A378: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x8001A37C: sw          $at, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r1;
    // 0x8001A380: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8001A384: sw          $t0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r8;
    // 0x8001A388: lw          $at, 0x10($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X10);
    // 0x8001A38C: sw          $at, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r1;
    // 0x8001A390: jr          $ra
    // 0x8001A394: nop

    return;
    // 0x8001A394: nop

;}
RECOMP_FUNC void func_8002684C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002684C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80026850: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x80026854: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x80026858: addiu       $v0, $v0, 0x3B00
    ctx->r2 = ADD32(ctx->r2, 0X3B00);
    // 0x8002685C: addiu       $v1, $zero, 0x46
    ctx->r3 = ADD32(0, 0X46);
    // 0x80026860: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80026864:
    // 0x80026864: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80026868: bnel        $a0, $t6, L_80026888
    if (ctx->r4 != ctx->r14) {
        // 0x8002686C: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80026888;
    }
    goto skip_0;
    // 0x8002686C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x80026870: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80026874: beq         $a1, $a2, L_80026890
    if (ctx->r5 == ctx->r6) {
        // 0x80026878: nop
    
            goto L_80026890;
    }
    // 0x80026878: nop

    // 0x8002687C: beq         $t0, $a2, L_80026890
    if (ctx->r8 == ctx->r6) {
        // 0x80026880: nop
    
            goto L_80026890;
    }
    // 0x80026880: nop

    // 0x80026884: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80026888:
    // 0x80026888: bne         $v1, $zero, L_80026864
    if (ctx->r3 != 0) {
        // 0x8002688C: addiu       $v0, $v0, 0x6
        ctx->r2 = ADD32(ctx->r2, 0X6);
            goto L_80026864;
    }
    // 0x8002688C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
L_80026890:
    // 0x80026890: beq         $v1, $zero, L_800268CC
    if (ctx->r3 == 0) {
        // 0x80026894: lui         $a0, 0x8009
        ctx->r4 = S32(0X8009 << 16);
            goto L_800268CC;
    }
    // 0x80026894: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026898: addiu       $a0, $a0, -0x33F
    ctx->r4 = ADD32(ctx->r4, -0X33F);
    // 0x8002689C: lb          $t7, 0x0($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X0);
    // 0x800268A0: lb          $v1, 0x4($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X4);
    // 0x800268A4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800268A8: addiu       $v0, $v0, -0x33E
    ctx->r2 = ADD32(ctx->r2, -0X33E);
    // 0x800268AC: beq         $v1, $t7, L_800268CC
    if (ctx->r3 == ctx->r15) {
        // 0x800268B0: nop
    
            goto L_800268CC;
    }
    // 0x800268B0: nop

    // 0x800268B4: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x800268B8: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x800268BC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800268C0: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800268C4: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x800268C8: sh          $a3, -0x33C($at)
    MEM_H(-0X33C, ctx->r1) = ctx->r7;
L_800268CC:
    // 0x800268CC: jr          $ra
    // 0x800268D0: nop

    return;
    // 0x800268D0: nop

;}
