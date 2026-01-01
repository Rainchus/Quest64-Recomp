#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8001459C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001459C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800145A0: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800145A4: ldc1        $f12, 0x1440($at)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r1, 0X1440);
    // 0x800145A8: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x800145AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800145B0: lwc1        $f6, -0x4524($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4524);
    // 0x800145B4: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800145B8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800145BC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800145C0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800145C4: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x800145C8: nop

    // 0x800145CC: bc1f        L_800145F4
    if (!c1cs) {
        // 0x800145D0: nop
    
            goto L_800145F4;
    }
    // 0x800145D0: nop

    // 0x800145D4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800145D8: ldc1        $f14, 0x1448($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X1448);
    // 0x800145DC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800145E0: ldc1        $f16, 0x1450($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1450);
    // 0x800145E4: add.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f2.d + ctx->f14.d;
    // 0x800145E8: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800145EC: b           L_8001461C
    // 0x800145F0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
        goto L_8001461C;
    // 0x800145F0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_800145F4:
    // 0x800145F4: ldc1        $f16, 0x1458($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1458);
    // 0x800145F8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800145FC: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80014600: nop

    // 0x80014604: bc1f        L_8001461C
    if (!c1cs) {
        // 0x80014608: nop
    
            goto L_8001461C;
    }
    // 0x80014608: nop

    // 0x8001460C: ldc1        $f14, 0x1460($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X1460);
    // 0x80014610: sub.d       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f2.d - ctx->f14.d;
    // 0x80014614: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80014618: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_8001461C:
    // 0x8001461C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80014620: ldc1        $f14, 0x1468($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, 0X1468);
    // 0x80014624: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80014628: ldc1        $f18, 0x1470($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1470);
    // 0x8001462C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80014630: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80014634: nop

    // 0x80014638: bc1f        L_80014648
    if (!c1cs) {
        // 0x8001463C: nop
    
            goto L_80014648;
    }
    // 0x8001463C: nop

    // 0x80014640: lwc1        $f0, 0x1478($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1478);
    // 0x80014644: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
L_80014648:
    // 0x80014648: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001464C: ldc1        $f4, 0x1480($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X1480);
    // 0x80014650: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80014654: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x80014658: nop

    // 0x8001465C: bc1fl       L_80014670
    if (!c1cs) {
        // 0x80014660: add.d       $f6, $f2, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f2.d + ctx->f16.d;
            goto L_80014670;
    }
    goto skip_0;
    // 0x80014660: add.d       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f2.d + ctx->f16.d;
    skip_0:
    // 0x80014664: lwc1        $f0, 0x1488($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1488);
    // 0x80014668: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001466C: add.d       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f2.d + ctx->f16.d;
L_80014670:
    // 0x80014670: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014674: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x80014678: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001467C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    // 0x80014680: nop

    // 0x80014684: bc1fl       L_8001469C
    if (!c1cs) {
        // 0x80014688: c.lt.d      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
            goto L_8001469C;
    }
    goto skip_1;
    // 0x80014688: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    skip_1:
    // 0x8001468C: add.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f2.d + ctx->f14.d;
    // 0x80014690: b           L_800146B0
    // 0x80014694: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_800146B0;
    // 0x80014694: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80014698: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
L_8001469C:
    // 0x8001469C: nop

    // 0x800146A0: bc1fl       L_800146B4
    if (!c1cs) {
        // 0x800146A4: swc1        $f0, 0x84($v0)
        MEM_W(0X84, ctx->r2) = ctx->f0.u32l;
            goto L_800146B4;
    }
    goto skip_2;
    // 0x800146A4: swc1        $f0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f0.u32l;
    skip_2:
    // 0x800146A8: sub.d       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f2.d - ctx->f14.d;
    // 0x800146AC: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800146B0:
    // 0x800146B0: swc1        $f0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f0.u32l;
L_800146B4:
    // 0x800146B4: lwc1        $f18, 0x537C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X537C);
    // 0x800146B8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800146BC: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x800146C0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800146C4: swc1        $f8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f8.u32l;
    // 0x800146C8: lwc1        $f10, 0x54($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800146CC: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
    // 0x800146D0: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x800146D4: nop

    // 0x800146D8: bc1fl       L_800146F4
    if (!c1cs) {
        // 0x800146DC: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800146F4;
    }
    goto skip_3;
    // 0x800146DC: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x800146E0: sub.d       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = ctx->f2.d - ctx->f14.d;
    // 0x800146E4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800146E8: b           L_8001470C
    // 0x800146EC: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
        goto L_8001470C;
    // 0x800146EC: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x800146F0: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800146F4:
    // 0x800146F4: nop

    // 0x800146F8: bc1fl       L_80014710
    if (!c1cs) {
        // 0x800146FC: lhu         $t6, 0x8($v0)
        ctx->r14 = MEM_HU(ctx->r2, 0X8);
            goto L_80014710;
    }
    goto skip_4;
    // 0x800146FC: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    skip_4:
    // 0x80014700: add.d       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f2.d + ctx->f14.d;
    // 0x80014704: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80014708: swc1        $f8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f8.u32l;
L_8001470C:
    // 0x8001470C: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
L_80014710:
    // 0x80014710: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80014714: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x80014718: jr          $ra
    // 0x8001471C: nop

    return;
    // 0x8001471C: nop

;}
RECOMP_FUNC void func_80002918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002918: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000291C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80002920: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80002924: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80002928: addiu       $v1, $v1, -0x43C0
    ctx->r3 = ADD32(ctx->r3, -0X43C0);
    // 0x8000292C: addiu       $v0, $v0, -0x4548
    ctx->r2 = ADD32(ctx->r2, -0X4548);
    // 0x80002930: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002934: lh          $t6, 0x64($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X64);
    // 0x80002938: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8000293C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002940: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80002944: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80002948: lw          $t8, 0x3D00($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3D00);
    // 0x8000294C: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80002950: sh          $zero, 0x124($v0)
    MEM_H(0X124, ctx->r2) = 0;
    // 0x80002954: lwc1        $f12, -0x45C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X45C0);
    // 0x80002958: swc1        $f14, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f14.u32l;
    // 0x8000295C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002960: swc1        $f12, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f12.u32l;
    // 0x80002964: lwc1        $f0, -0x45BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X45BC);
    // 0x80002968: swc1        $f14, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f14.u32l;
    // 0x8000296C: swc1        $f14, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f14.u32l;
    // 0x80002970: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002974: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80002978: lwc1        $f4, -0x45B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X45B8);
    // 0x8000297C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80002980: swc1        $f14, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f14.u32l;
    // 0x80002984: swc1        $f14, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f14.u32l;
    // 0x80002988: swc1        $f14, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f14.u32l;
    // 0x8000298C: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x80002990: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80002994: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80002998: jal         0x8000EE60
    // 0x8000299C: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    func_8000EE60(rdram, ctx);
        goto after_0;
    // 0x8000299C: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x800029A0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800029A4: addiu       $v1, $v1, -0x43C0
    ctx->r3 = ADD32(ctx->r3, -0X43C0);
    // 0x800029A8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800029AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800029B0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800029B4: swc1        $f6, -0x4530($at)
    MEM_W(-0X4530, ctx->r1) = ctx->f6.u32l;
    // 0x800029B8: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800029BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800029C0: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x800029C4: swc1        $f8, -0x4508($at)
    MEM_W(-0X4508, ctx->r1) = ctx->f8.u32l;
    // 0x800029C8: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800029CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800029D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800029D4: swc1        $f10, -0x4504($at)
    MEM_W(-0X4504, ctx->r1) = ctx->f10.u32l;
    // 0x800029D8: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800029DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800029E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800029E4: swc1        $f16, -0x4500($at)
    MEM_W(-0X4500, ctx->r1) = ctx->f16.u32l;
    // 0x800029E8: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x800029EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800029F0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x800029F4: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800029F8: beq         $t9, $zero, L_80002A0C
    if (ctx->r25 == 0) {
        // 0x800029FC: nop
    
            goto L_80002A0C;
    }
    // 0x800029FC: nop

    // 0x80002A00: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002A04: b           L_80002A10
    // 0x80002A08: sh          $zero, -0x44D2($at)
    MEM_H(-0X44D2, ctx->r1) = 0;
        goto L_80002A10;
    // 0x80002A08: sh          $zero, -0x44D2($at)
    MEM_H(-0X44D2, ctx->r1) = 0;
L_80002A0C:
    // 0x80002A0C: sh          $v0, -0x44D2($at)
    MEM_H(-0X44D2, ctx->r1) = ctx->r2;
L_80002A10:
    // 0x80002A10: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80002A14: lhu         $v0, -0x4542($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4542);
    // 0x80002A18: beq         $v0, $zero, L_80002A2C
    if (ctx->r2 == 0) {
        // 0x80002A1C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80002A2C;
    }
    // 0x80002A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80002A20: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002A24: b           L_80002A34
    // 0x80002A28: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
        goto L_80002A34;
    // 0x80002A28: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
L_80002A2C:
    // 0x80002A2C: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x80002A30: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80002A34:
    // 0x80002A34: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80002A38: jal         0x8001D8B0
    // 0x80002A3C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_8001D8B0(rdram, ctx);
        goto after_1;
    // 0x80002A3C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
    // 0x80002A40: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80002A44: addiu       $v1, $v1, -0x45B4
    ctx->r3 = ADD32(ctx->r3, -0X45B4);
    // 0x80002A48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80002A4C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80002A50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80002A54: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x80002A58: beq         $t2, $zero, L_80002A80
    if (ctx->r10 == 0) {
        // 0x80002A5C: sra         $a1, $v0, 8
        ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
            goto L_80002A80;
    }
    // 0x80002A5C: sra         $a1, $v0, 8
    ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80002A60: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002A64: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80002A68: sh          $t3, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r11;
    // 0x80002A6C: sh          $t4, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r12;
    // 0x80002A70: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002A74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80002A78: b           L_80002DF4
    // 0x80002A7C: sh          $t5, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r13;
        goto L_80002DF4;
    // 0x80002A7C: sh          $t5, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r13;
L_80002A80:
    // 0x80002A80: andi        $t6, $a1, 0x7
    ctx->r14 = ctx->r5 & 0X7;
    // 0x80002A84: beq         $t6, $at, L_80002AAC
    if (ctx->r14 == ctx->r1) {
        // 0x80002A88: lui         $a3, 0x8008
        ctx->r7 = S32(0X8008 << 16);
            goto L_80002AAC;
    }
    // 0x80002A88: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002A8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80002A90: beq         $t6, $at, L_80002B34
    if (ctx->r14 == ctx->r1) {
        // 0x80002A94: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_80002B34;
    }
    // 0x80002A94: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80002A98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80002A9C: beq         $t6, $at, L_80002D1C
    if (ctx->r14 == ctx->r1) {
        // 0x80002AA0: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_80002D1C;
    }
    // 0x80002AA0: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80002AA4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80002AA8: bne         $t6, $at, L_80002DF4
    if (ctx->r14 != ctx->r1) {
        // 0x80002AAC: lui         $at, 0x8008
        ctx->r1 = S32(0X8008 << 16);
            goto L_80002DF4;
    }
L_80002AAC:
    // 0x80002AAC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002AB0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80002AB4: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80002AB8: sh          $t7, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r15;
    // 0x80002ABC: sh          $t8, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r24;
    // 0x80002AC0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80002AC4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80002AC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80002ACC: addiu       $a1, $a3, -0x43D0
    ctx->r5 = ADD32(ctx->r7, -0X43D0);
    // 0x80002AD0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002AD4: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x80002AD8: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80002ADC: jal         0x800232F4
    // 0x80002AE0: lwc1        $f12, -0x4524($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4524);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_2;
    // 0x80002AE0: lwc1        $f12, -0x4524($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4524);
    after_2:
    // 0x80002AE4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002AE8: addiu       $a3, $a3, -0x43D0
    ctx->r7 = ADD32(ctx->r7, -0X43D0);
    // 0x80002AEC: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80002AF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002AF4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80002AF8: swc1        $f6, -0x4420($at)
    MEM_W(-0X4420, ctx->r1) = ctx->f6.u32l;
    // 0x80002AFC: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80002B00: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80002B04: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80002B08: swc1        $f8, -0x441C($at)
    MEM_W(-0X441C, ctx->r1) = ctx->f8.u32l;
    // 0x80002B0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002B10: sh          $t9, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r25;
    // 0x80002B14: jal         0x800268D4
    // 0x80002B18: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_3;
    // 0x80002B18: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_3:
    // 0x80002B1C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80002B20: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80002B24: jal         0x800268D4
    // 0x80002B28: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_4;
    // 0x80002B28: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_4:
    // 0x80002B2C: b           L_80002DF4
    // 0x80002B30: nop

        goto L_80002DF4;
    // 0x80002B30: nop

L_80002B34:
    // 0x80002B34: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80002B38: lw          $t1, -0x45B0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X45B0);
    // 0x80002B3C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80002B40: lw          $t3, 0x4F24($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4F24);
    // 0x80002B44: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80002B48: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80002B4C: ldc1        $f2, 0xF10($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0XF10);
    // 0x80002B50: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80002B54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002B58: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80002B5C: sh          $t0, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r8;
    // 0x80002B60: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80002B64: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80002B68: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002B6C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002B70: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80002B74: addiu       $a3, $a3, -0x43D0
    ctx->r7 = ADD32(ctx->r7, -0X43D0);
    // 0x80002B78: mul.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x80002B7C: addiu       $t6, $zero, 0x15
    ctx->r14 = ADD32(0, 0X15);
    // 0x80002B80: addiu       $t7, $zero, 0x55
    ctx->r15 = ADD32(0, 0X55);
    // 0x80002B84: addiu       $t9, $zero, 0x1F
    ctx->r25 = ADD32(0, 0X1F);
    // 0x80002B88: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80002B8C: swc1        $f0, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->f0.u32l;
    // 0x80002B90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002B94: swc1        $f0, -0x4414($at)
    MEM_W(-0X4414, ctx->r1) = ctx->f0.u32l;
    // 0x80002B98: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80002B9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002BA0: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80002BA4: beq         $t5, $zero, L_80002BE0
    if (ctx->r13 == 0) {
        // 0x80002BA8: nop
    
            goto L_80002BE0;
    }
    // 0x80002BA8: nop

    // 0x80002BAC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002BB0: sh          $t6, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r14;
    // 0x80002BB4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002BB8: sh          $t7, -0x44E0($at)
    MEM_H(-0X44E0, ctx->r1) = ctx->r15;
    // 0x80002BBC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80002BC0: lwc1        $f4, 0xF18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XF18);
    // 0x80002BC4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80002BC8: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80002BCC: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80002BD0: lwc1        $f6, 0xF1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XF1C);
    // 0x80002BD4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80002BD8: b           L_80002C3C
    // 0x80002BDC: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
        goto L_80002C3C;
    // 0x80002BDC: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
L_80002BE0:
    // 0x80002BE0: sh          $t9, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r25;
    // 0x80002BE4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002BE8: lwc1        $f8, -0x4414($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4414);
    // 0x80002BEC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80002BF0: ldc1        $f16, 0xF20($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0XF20);
    // 0x80002BF4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80002BF8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002BFC: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x80002C00: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80002C04: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002C08: addiu       $a3, $a3, -0x43D0
    ctx->r7 = ADD32(ctx->r7, -0X43D0);
    // 0x80002C0C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80002C10: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80002C14: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80002C18: swc1        $f4, -0x4414($at)
    MEM_W(-0X4414, ctx->r1) = ctx->f4.u32l;
    // 0x80002C1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002C20: sh          $t0, -0x44E0($at)
    MEM_H(-0X44E0, ctx->r1) = ctx->r8;
    // 0x80002C24: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80002C28: lwc1        $f6, 0xF28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XF28);
    // 0x80002C2C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80002C30: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x80002C34: lwc1        $f8, 0xF2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XF2C);
    // 0x80002C38: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
L_80002C3C:
    // 0x80002C3C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80002C40: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80002C44: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80002C48: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80002C4C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x80002C50: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80002C54: jal         0x800232F4
    // 0x80002C58: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_5;
    // 0x80002C58: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_5:
    // 0x80002C5C: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002C60: addiu       $a3, $a3, -0x43D0
    ctx->r7 = ADD32(ctx->r7, -0X43D0);
    // 0x80002C64: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002C68: lwc1        $f8, -0x4510($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4510);
    // 0x80002C6C: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80002C70: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80002C74: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002C78: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80002C7C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80002C80: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80002C84: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002C88: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80002C8C: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80002C90: swc1        $f18, -0x4534($at)
    MEM_W(-0X4534, ctx->r1) = ctx->f18.u32l;
    // 0x80002C94: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80002C98: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80002C9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002CA0: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80002CA4: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80002CA8: swc1        $f10, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->f10.u32l;
    // 0x80002CAC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002CB0: jal         0x80006720
    // 0x80002CB4: sh          $t2, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r10;
    func_80006720(rdram, ctx);
        goto after_6;
    // 0x80002CB4: sh          $t2, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r10;
    after_6:
    // 0x80002CB8: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80002CBC: lh          $t3, -0x44E2($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X44E2);
    // 0x80002CC0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80002CC4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002CC8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80002CCC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80002CD0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80002CD4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80002CD8: lw          $a2, -0x4510($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4510);
    // 0x80002CDC: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80002CE0: jal         0x8001D924
    // 0x80002CE4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    func_8001D924(rdram, ctx);
        goto after_7;
    // 0x80002CE4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_7:
    // 0x80002CE8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80002CEC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80002CF0: lw          $a2, -0x45B4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X45B4);
    // 0x80002CF4: lhu         $a1, -0x44E0($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X44E0);
    // 0x80002CF8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80002CFC: jal         0x8000DB7C
    // 0x80002D00: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_8000DB7C(rdram, ctx);
        goto after_8;
    // 0x80002D00: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80002D04: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x80002D08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80002D0C: jal         0x800268D4
    // 0x80002D10: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_9;
    // 0x80002D10: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_9:
    // 0x80002D14: b           L_80002DF4
    // 0x80002D18: nop

        goto L_80002DF4;
    // 0x80002D18: nop

L_80002D1C:
    // 0x80002D1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002D20: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80002D24: sh          $t6, -0x4548($at)
    MEM_H(-0X4548, ctx->r1) = ctx->r14;
    // 0x80002D28: sh          $t7, -0x4544($at)
    MEM_H(-0X4544, ctx->r1) = ctx->r15;
    // 0x80002D2C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80002D30: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80002D34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80002D38: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002D3C: addiu       $a1, $a3, -0x43D0
    ctx->r5 = ADD32(ctx->r7, -0X43D0);
    // 0x80002D40: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002D44: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x80002D48: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80002D4C: jal         0x800232F4
    // 0x80002D50: lwc1        $f12, -0x4524($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4524);
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_10;
    // 0x80002D50: lwc1        $f12, -0x4524($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X4524);
    after_10:
    // 0x80002D54: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80002D58: addiu       $a3, $a3, -0x43D0
    ctx->r7 = ADD32(ctx->r7, -0X43D0);
    // 0x80002D5C: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80002D60: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002D64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80002D68: swc1        $f8, -0x4420($at)
    MEM_W(-0X4420, ctx->r1) = ctx->f8.u32l;
    // 0x80002D6C: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80002D70: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002D74: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80002D78: swc1        $f16, -0x441C($at)
    MEM_W(-0X441C, ctx->r1) = ctx->f16.u32l;
    // 0x80002D7C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002D80: jal         0x80006720
    // 0x80002D84: sh          $t8, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r24;
    func_80006720(rdram, ctx);
        goto after_11;
    // 0x80002D84: sh          $t8, -0x44D4($at)
    MEM_H(-0X44D4, ctx->r1) = ctx->r24;
    after_11:
    // 0x80002D88: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80002D8C: lh          $t9, -0x44E2($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X44E2);
    // 0x80002D90: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80002D94: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80002D98: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80002D9C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80002DA0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80002DA4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80002DA8: lw          $a2, -0x4510($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4510);
    // 0x80002DAC: addiu       $a0, $a0, -0x4534
    ctx->r4 = ADD32(ctx->r4, -0X4534);
    // 0x80002DB0: jal         0x8001D924
    // 0x80002DB4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_8001D924(rdram, ctx);
        goto after_12;
    // 0x80002DB4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_12:
    // 0x80002DB8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80002DBC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80002DC0: lw          $a2, -0x45B4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X45B4);
    // 0x80002DC4: lhu         $a1, -0x44E0($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X44E0);
    // 0x80002DC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80002DCC: jal         0x8000DB7C
    // 0x80002DD0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_8000DB7C(rdram, ctx);
        goto after_13;
    // 0x80002DD0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x80002DD4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80002DD8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80002DDC: jal         0x800268D4
    // 0x80002DE0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_14;
    // 0x80002DE0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_14:
    // 0x80002DE4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80002DE8: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80002DEC: jal         0x800268D4
    // 0x80002DF0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_15;
    // 0x80002DF0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_15:
L_80002DF4:
    // 0x80002DF4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80002DF8: lw          $t2, 0x5370($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5370);
    // 0x80002DFC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002E00: sh          $zero, -0x4540($at)
    MEM_H(-0X4540, ctx->r1) = 0;
    // 0x80002E04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002E08: bne         $t2, $at, L_80002E1C
    if (ctx->r10 != ctx->r1) {
        // 0x80002E0C: lui         $t5, 0x8008
        ctx->r13 = S32(0X8008 << 16);
            goto L_80002E1C;
    }
    // 0x80002E0C: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80002E10: ori         $t4, $zero, 0x10
    ctx->r12 = 0 | 0X10;
    // 0x80002E14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002E18: sh          $t4, -0x4540($at)
    MEM_H(-0X4540, ctx->r1) = ctx->r12;
L_80002E1C:
    // 0x80002E1C: lw          $t5, -0x4D1C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4D1C);
    // 0x80002E20: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80002E24: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80002E28: andi        $t6, $t5, 0x800
    ctx->r14 = ctx->r13 & 0X800;
    // 0x80002E2C: beq         $t6, $zero, L_80002E5C
    if (ctx->r14 == 0) {
        // 0x80002E30: lui         $t2, 0x8008
        ctx->r10 = S32(0X8008 << 16);
            goto L_80002E5C;
    }
    // 0x80002E30: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80002E34: lw          $t8, -0x44D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X44D0);
    // 0x80002E38: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80002E3C: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80002E40: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x80002E44: lw          $t9, -0x44D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X44D0);
    // 0x80002E48: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80002E4C: lhu         $t0, 0xA($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XA);
    // 0x80002E50: sh          $t0, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r8;
    // 0x80002E54: lw          $t1, -0x44CC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X44CC);
    // 0x80002E58: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
L_80002E5C:
    // 0x80002E5C: lw          $t2, -0x44CC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X44CC);
    // 0x80002E60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80002E64: addiu       $v0, $v0, -0x43F4
    ctx->r2 = ADD32(ctx->r2, -0X43F4);
    // 0x80002E68: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x80002E6C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80002E70: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80002E74: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002E78: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80002E7C: swc1        $f10, -0x45A4($at)
    MEM_W(-0X45A4, ctx->r1) = ctx->f10.u32l;
    // 0x80002E80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002E84: sh          $zero, -0x43D8($at)
    MEM_H(-0X43D8, ctx->r1) = 0;
    // 0x80002E88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80002E8C: sw          $t3, -0x4590($at)
    MEM_W(-0X4590, ctx->r1) = ctx->r11;
    // 0x80002E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002E94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80002E98: jr          $ra
    // 0x80002E9C: nop

    return;
    // 0x80002E9C: nop

;}
RECOMP_FUNC void func_80011170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011170: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80011174: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80011178: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001117C: addiu       $t7, $t7, 0x59E8
    ctx->r15 = ADD32(ctx->r15, 0X59E8);
    // 0x80011180: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80011184: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80011188: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8001118C: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x80011190: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x80011194: sw          $a3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r7;
    // 0x80011198: sw          $a3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r7;
    // 0x8001119C: jr          $ra
    // 0x800111A0: nop

    return;
    // 0x800111A0: nop

;}
RECOMP_FUNC void func_80031FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031FBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031FC0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80031FC4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80031FC8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80031FCC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80031FD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031FD4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80031FD8: beq         $s0, $zero, L_8003200C
    if (ctx->r16 == 0) {
        // 0x80031FDC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8003200C;
    }
    // 0x80031FDC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80031FE0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80031FE4: beq         $v0, $zero, L_8003200C
    if (ctx->r2 == 0) {
        // 0x80031FE8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003200C;
    }
    // 0x80031FE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80031FEC:
    // 0x80031FEC: jal         0x80031DD4
    // 0x80031FF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_80031DD4(rdram, ctx);
        goto after_0;
    // 0x80031FF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80031FF4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80031FF8: beq         $s0, $zero, L_8003200C
    if (ctx->r16 == 0) {
        // 0x80031FFC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8003200C;
    }
    // 0x80031FFC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80032000: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80032004: bnel        $v0, $zero, L_80031FEC
    if (ctx->r2 != 0) {
        // 0x80032008: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80031FEC;
    }
    goto skip_0;
    // 0x80032008: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    skip_0:
L_8003200C:
    // 0x8003200C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80032010: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80032014: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80032018: jr          $ra
    // 0x8003201C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003201C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001D538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D538: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001D53C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8001D540: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001D544: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8001D548: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8001D54C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D550: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8001D554: lw          $a1, -0x3A9C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3A9C);
    // 0x8001D558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D55C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001D560: beq         $a1, $zero, L_8001D628
    if (ctx->r5 == 0) {
        // 0x8001D564: nop
    
            goto L_8001D628;
    }
    // 0x8001D564: nop

    // 0x8001D568: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8001D56C: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8001D570: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8001D574: beq         $v0, $zero, L_8001D5FC
    if (ctx->r2 == 0) {
        // 0x8001D578: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8001D5FC;
    }
    // 0x8001D578: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001D57C: lwc1        $f16, 0x1698($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1698);
    // 0x8001D580: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001D584: lwc1        $f14, 0x169C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X169C);
    // 0x8001D588: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
L_8001D58C:
    // 0x8001D58C: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x8001D590: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001D594: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001D598: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8001D59C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D5A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001D5A4: sub.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x8001D5A8: sub.s       $f2, $f10, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x8001D5AC: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001D5B0: nop

    // 0x8001D5B4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001D5B8: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8001D5BC: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x8001D5C0: nop

    // 0x8001D5C4: bc1f        L_8001D5E8
    if (!c1cs) {
        // 0x8001D5C8: nop
    
            goto L_8001D5E8;
    }
    // 0x8001D5C8: nop

    // 0x8001D5CC: c.le.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl <= ctx->f16.fl;
    // 0x8001D5D0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8001D5D4: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x8001D5D8: bc1fl       L_8001D5EC
    if (!c1cs) {
        // 0x8001D5DC: slti        $at, $a0, 0x6
        ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
            goto L_8001D5EC;
    }
    goto skip_0;
    // 0x8001D5DC: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    skip_0:
    // 0x8001D5E0: sw          $v1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r3;
    // 0x8001D5E4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8001D5E8:
    // 0x8001D5E8: slti        $at, $a0, 0x6
    ctx->r1 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
L_8001D5EC:
    // 0x8001D5EC: beq         $at, $zero, L_8001D5FC
    if (ctx->r1 == 0) {
        // 0x8001D5F0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8001D5FC;
    }
    // 0x8001D5F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001D5F4: bnel        $v0, $zero, L_8001D58C
    if (ctx->r2 != 0) {
        // 0x8001D5F8: lh          $t6, 0x0($v1)
        ctx->r14 = MEM_H(ctx->r3, 0X0);
            goto L_8001D58C;
    }
    goto skip_1;
    // 0x8001D5F8: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    skip_1:
L_8001D5FC:
    // 0x8001D5FC: bne         $a0, $zero, L_8001D60C
    if (ctx->r4 != 0) {
        // 0x8001D600: nop
    
            goto L_8001D60C;
    }
    // 0x8001D600: nop

    // 0x8001D604: b           L_8001D628
    // 0x8001D608: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8001D628;
    // 0x8001D608: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001D60C:
    // 0x8001D60C: jal         0x80022FD0
    // 0x8001D610: nop

    get_rand(rdram, ctx);
        goto after_0;
    // 0x8001D610: nop

    after_0:
    // 0x8001D614: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8001D618: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8001D61C: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x8001D620: b           L_8001D628
    // 0x8001D624: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
        goto L_8001D628;
    // 0x8001D624: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
L_8001D628:
    // 0x8001D628: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001D62C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D630: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001D634: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8001D638: jr          $ra
    // 0x8001D63C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8001D63C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800149D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800149D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800149D4: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800149D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800149DC: srl         $v0, $a0, 8
    ctx->r2 = S32(U32(ctx->r4) >> 8);
    // 0x800149E0: andi        $t7, $v0, 0xF
    ctx->r15 = ctx->r2 & 0XF;
    // 0x800149E4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800149E8: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800149EC: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800149F0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800149F4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800149F8: lw          $t0, 0x1B14($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1B14);
    // 0x800149FC: lw          $t2, -0x4538($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4538);
    // 0x80014A00: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x80014A04: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80014A08: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80014A0C: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x80014A10: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x80014A14: lbu         $t4, 0x24($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X24);
    // 0x80014A18: lhu         $t5, 0x0($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X0);
    // 0x80014A1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80014A20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80014A24: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80014A28: beq         $at, $zero, L_80014A34
    if (ctx->r1 == 0) {
        // 0x80014A2C: lui         $t6, 0x8009
        ctx->r14 = S32(0X8009 << 16);
            goto L_80014A34;
    }
    // 0x80014A2C: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80014A30: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80014A34:
    // 0x80014A34: lhu         $t6, -0x3A6E($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X3A6E);
    // 0x80014A38: ori         $t0, $v1, 0x2
    ctx->r8 = ctx->r3 | 0X2;
    // 0x80014A3C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80014A40: beq         $t7, $zero, L_80014A50
    if (ctx->r15 == 0) {
        // 0x80014A44: nop
    
            goto L_80014A50;
    }
    // 0x80014A44: nop

    // 0x80014A48: b           L_80014A50
    // 0x80014A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80014A50;
    // 0x80014A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80014A50:
    // 0x80014A50: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x80014A54: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x80014A58: bnel        $t9, $zero, L_80014A68
    if (ctx->r25 != 0) {
        // 0x80014A5C: lhu         $t1, 0x4($a2)
        ctx->r9 = MEM_HU(ctx->r6, 0X4);
            goto L_80014A68;
    }
    goto skip_0;
    // 0x80014A5C: lhu         $t1, 0x4($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X4);
    skip_0:
    // 0x80014A60: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80014A64: lhu         $t1, 0x4($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X4);
L_80014A68:
    // 0x80014A68: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80014A6C: ori         $t4, $v1, 0x1
    ctx->r12 = ctx->r3 | 0X1;
    // 0x80014A70: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80014A74: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80014A78: lhu         $t3, 0x1B26($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X1B26);
    // 0x80014A7C: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80014A80: beql        $at, $zero, L_80014A90
    if (ctx->r1 == 0) {
        // 0x80014A84: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80014A90;
    }
    goto skip_1;
    // 0x80014A84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x80014A88: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x80014A8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80014A90:
    // 0x80014A90: jr          $ra
    // 0x80014A94: nop

    return;
    // 0x80014A94: nop

;}
RECOMP_FUNC void func_80013DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013DE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80013DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013DE8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80013DEC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80013DF0: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80013DF4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80013DF8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80013DFC: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80013E00: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80013E04: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80013E08: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80013E0C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80013E10: lhu         $t6, 0x8($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X8);
    // 0x80013E14: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80013E18: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x80013E1C: beql        $t7, $zero, L_80013EB0
    if (ctx->r15 == 0) {
        // 0x80013E20: lwc1        $f14, 0x3C($a0)
        ctx->f14.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_80013EB0;
    }
    goto skip_0;
    // 0x80013E20: lwc1        $f14, 0x3C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X3C);
    skip_0:
    // 0x80013E24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80013E28: jal         0x80023210
    // 0x80013E2C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x80013E2C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80013E30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80013E34: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013E38: ldc1        $f6, 0x1400($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1400);
    // 0x80013E3C: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80013E40: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80013E44: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013E48: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80013E4C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80013E50: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x80013E54: nop

    // 0x80013E58: bc1f        L_80013E74
    if (!c1cs) {
        // 0x80013E5C: nop
    
            goto L_80013E74;
    }
    // 0x80013E5C: nop

    // 0x80013E60: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013E64: ldc1        $f8, 0x1408($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X1408);
    // 0x80013E68: sub.d       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f2.d - ctx->f8.d;
    // 0x80013E6C: b           L_80013E98
    // 0x80013E70: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
        goto L_80013E98;
    // 0x80013E70: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_80013E74:
    // 0x80013E74: ldc1        $f16, 0x1410($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, 0X1410);
    // 0x80013E78: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80013E7C: c.lt.d      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.d < ctx->f16.d;
    // 0x80013E80: nop

    // 0x80013E84: bc1fl       L_80013E9C
    if (!c1cs) {
        // 0x80013E88: lwc1        $f6, 0x78($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
            goto L_80013E9C;
    }
    goto skip_1;
    // 0x80013E88: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    skip_1:
    // 0x80013E8C: ldc1        $f18, 0x1418($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X1418);
    // 0x80013E90: add.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f2.d + ctx->f18.d;
    // 0x80013E94: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_80013E98:
    // 0x80013E98: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
L_80013E9C:
    // 0x80013E9C: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80013EA0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80013EA4: b           L_80013EB0
    // 0x80013EA8: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
        goto L_80013EB0;
    // 0x80013EA8: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80013EAC: lwc1        $f14, 0x3C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X3C);
L_80013EB0:
    // 0x80013EB0: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80013EB4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013EB8: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x80013EBC: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80013EC0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80013EC4: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80013EC8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80013ECC: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80013ED0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80013ED4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80013ED8: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80013EDC: jal         0x800232F4
    // 0x80013EE0: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x80013EE0: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    after_1:
    // 0x80013EE4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80013EE8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013EEC: addiu       $a1, $a1, 0x6B90
    ctx->r5 = ADD32(ctx->r5, 0X6B90);
    // 0x80013EF0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80013EF4: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80013EF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80013EFC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80013F00: swc1        $f16, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f16.u32l;
    // 0x80013F04: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80013F08: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80013F0C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80013F10: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x80013F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013F18: jr          $ra
    // 0x80013F1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80013F1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80100634_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100634: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80100638: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8010063C: addiu       $v0, $v0, 0x6238
    ctx->r2 = ADD32(ctx->r2, 0X6238);
    // 0x80100640: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80100644: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80100648: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8010064C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80100650: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80100654: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80100658: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8010065C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80100660: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80100664: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80100668: bne         $t6, $zero, L_8010069C
    if (ctx->r14 != 0) {
        // 0x8010066C: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_8010069C;
    }
    // 0x8010066C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80100670: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80100674: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80100678: sw          $zero, 0x4CB4($at)
    MEM_W(0X4CB4, ctx->r1) = 0;
    // 0x8010067C: addiu       $a0, $a0, 0x6230
    ctx->r4 = ADD32(ctx->r4, 0X6230);
    // 0x80100680: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80100684: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80100688: sb          $zero, 0x4DE8($at)
    MEM_B(0X4DE8, ctx->r1) = 0;
    // 0x8010068C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80100690: sw          $zero, 0x4DE4($at)
    MEM_W(0X4DE4, ctx->r1) = 0;
    // 0x80100694: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80100698: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8010069C:
    // 0x8010069C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801006A0: addiu       $a0, $a0, 0x6230
    ctx->r4 = ADD32(ctx->r4, 0X6230);
    // 0x801006A4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801006A8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801006AC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x801006B0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801006B4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801006B8: lw          $t6, 0x4CB4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4CB4);
    // 0x801006BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801006C0: addiu       $v1, $v1, 0x6244
    ctx->r3 = ADD32(ctx->r3, 0X6244);
    // 0x801006C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801006C8: sw          $t7, 0x4CB4($at)
    MEM_W(0X4CB4, ctx->r1) = ctx->r15;
    // 0x801006CC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801006D0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801006D4: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x801006D8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801006DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801006E0: lw          $t6, 0x6248($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6248);
    // 0x801006E4: addiu       $s3, $s3, 0x623C
    ctx->r19 = ADD32(ctx->r19, 0X623C);
    // 0x801006E8: addiu       $s5, $zero, 0x28
    ctx->r21 = ADD32(0, 0X28);
    // 0x801006EC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801006F0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x801006F4: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x801006F8: addiu       $fp, $fp, -0x4CC8
    ctx->r30 = ADD32(ctx->r30, -0X4CC8);
    // 0x801006FC: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100700: addu        $t8, $fp, $t7
    ctx->r24 = ADD32(ctx->r30, ctx->r15);
    // 0x80100704: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80100708: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8010070C: mflo        $t7
    ctx->r15 = lo;
    // 0x80100710: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80100714: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80100718: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8010071C: bnel        $at, $zero, L_80100A2C
    if (ctx->r1 != 0) {
        // 0x80100720: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_80100A2C;
    }
    goto skip_0;
    // 0x80100720: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80100724: lh          $t9, 0x22($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X22);
    // 0x80100728: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8010072C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80100730: bnel        $t9, $at, L_80100A2C
    if (ctx->r25 != ctx->r1) {
        // 0x80100734: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_80100A2C;
    }
    goto skip_1;
    // 0x80100734: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x80100738: lw          $t7, 0x624C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X624C);
    // 0x8010073C: lui         $s7, 0x8016
    ctx->r23 = S32(0X8016 << 16);
    // 0x80100740: addiu       $s7, $s7, 0x6240
    ctx->r23 = ADD32(ctx->r23, 0X6240);
    // 0x80100744: bne         $t7, $zero, L_80100A28
    if (ctx->r15 != 0) {
        // 0x80100748: addiu       $s6, $zero, 0xC
        ctx->r22 = ADD32(0, 0XC);
            goto L_80100A28;
    }
    // 0x80100748: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x8010074C: lui         $s4, 0x8016
    ctx->r20 = S32(0X8016 << 16);
    // 0x80100750: addiu       $s4, $s4, 0x6234
    ctx->r20 = ADD32(ctx->r20, 0X6234);
L_80100754:
    // 0x80100754: jal         0x80101470
    // 0x80100758: nop

    func_80101470_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x80100758: nop

    after_0:
    // 0x8010075C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80100760: beq         $v0, $at, L_801009FC
    if (ctx->r2 == ctx->r1) {
        // 0x80100764: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_801009FC;
    }
    // 0x80100764: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80100768: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8010076C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80100770: lw          $t8, 0x6248($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6248);
    // 0x80100774: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100778: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x8010077C: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x80100780: addu        $t9, $fp, $t6
    ctx->r25 = ADD32(ctx->r30, ctx->r14);
    // 0x80100784: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x80100788: sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18 << 16);
    // 0x8010078C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80100790: mflo        $t8
    ctx->r24 = lo;
    // 0x80100794: addu        $t6, $s0, $t8
    ctx->r14 = ADD32(ctx->r16, ctx->r24);
    // 0x80100798: sh          $zero, 0x20($t6)
    MEM_H(0X20, ctx->r14) = 0;
    // 0x8010079C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x801007A0: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801007A4: mflo        $t7
    ctx->r15 = lo;
    // 0x801007A8: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x801007AC: sh          $v0, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r2;
    // 0x801007B0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x801007B4: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801007B8: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801007BC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x801007C0: mflo        $t9
    ctx->r25 = lo;
    // 0x801007C4: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x801007C8: lh          $t9, 0x20($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X20);
    // 0x801007CC: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x801007D0: lh          $a2, 0x8($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X8);
    // 0x801007D4: multu       $t9, $s6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801007D8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801007DC: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x801007E0: lw          $s1, 0x67E0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X67E0);
    // 0x801007E4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x801007E8: lh          $a3, 0xA($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XA);
    // 0x801007EC: mflo        $t7
    ctx->r15 = lo;
    // 0x801007F0: addu        $t0, $s1, $t7
    ctx->r8 = ADD32(ctx->r17, ctx->r15);
    // 0x801007F4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801007F8: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x801007FC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80100800: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80100804: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x80100808: or          $a1, $t6, $t9
    ctx->r5 = ctx->r14 | ctx->r25;
    // 0x8010080C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80100810: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80100814: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80100818: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x8010081C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80100820: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    // 0x80100824: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80100828: lh          $t8, 0x16($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X16);
    // 0x8010082C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80100830: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80100834: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80100838: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8010083C: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80100840: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80100844: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80100848: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8010084C: jal         0x80101080
    // 0x80100850: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    func_80101080_ovl_intro(rdram, ctx);
        goto after_1;
    // 0x80100850: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    after_1:
    // 0x80100854: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80100858: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8010085C: multu       $v1, $s5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100860: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80100864: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x80100868: mflo        $t7
    ctx->r15 = lo;
    // 0x8010086C: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x80100870: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80100874: bnel        $t8, $zero, L_801008A0
    if (ctx->r24 != 0) {
        // 0x80100878: sw          $v1, 0x0($s7)
        MEM_W(0X0, ctx->r23) = ctx->r3;
            goto L_801008A0;
    }
    goto skip_2;
    // 0x80100878: sw          $v1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r3;
    skip_2:
    // 0x8010087C: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80100880: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80100884: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80100888: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8010088C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80100890: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80100894: b           L_801008A0
    // 0x80100898: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
        goto L_801008A0;
    // 0x80100898: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x8010089C: sw          $v1, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r3;
L_801008A0:
    // 0x801008A0: lh          $t7, 0x20($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X20);
    // 0x801008A4: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801008A8: mflo        $t8
    ctx->r24 = lo;
    // 0x801008AC: addu        $t0, $s1, $t8
    ctx->r8 = ADD32(ctx->r17, ctx->r24);
    // 0x801008B0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x801008B4: andi        $t6, $a0, 0xC800
    ctx->r14 = ctx->r4 & 0XC800;
    // 0x801008B8: beql        $t6, $zero, L_80100948
    if (ctx->r14 == 0) {
        // 0x801008BC: andi        $t8, $a0, 0x1000
        ctx->r24 = ctx->r4 & 0X1000;
            goto L_80100948;
    }
    goto skip_3;
    // 0x801008BC: andi        $t8, $a0, 0x1000
    ctx->r24 = ctx->r4 & 0X1000;
    skip_3:
    // 0x801008C0: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x801008C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801008C8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x801008CC: bne         $t9, $zero, L_80100900
    if (ctx->r25 != 0) {
        // 0x801008D0: nop
    
            goto L_80100900;
    }
    // 0x801008D0: nop

    // 0x801008D4: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x801008D8: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x801008DC: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801008E0: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x801008E4: mflo        $t8
    ctx->r24 = lo;
    // 0x801008E8: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x801008EC: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    // 0x801008F0: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x801008F4: subu        $a3, $t6, $t9
    ctx->r7 = SUB32(ctx->r14, ctx->r25);
    // 0x801008F8: b           L_80100900
    // 0x801008FC: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
        goto L_80100900;
    // 0x801008FC: subu        $t1, $t7, $t8
    ctx->r9 = SUB32(ctx->r15, ctx->r24);
L_80100900:
    // 0x80100900: lh          $t6, 0x4($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X4);
    // 0x80100904: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x80100908: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010090C: addu        $a1, $t6, $a3
    ctx->r5 = ADD32(ctx->r14, ctx->r7);
    // 0x80100910: jal         0x80101CD8
    // 0x80100914: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    func_80101CD8_ovl_intro(rdram, ctx);
        goto after_2;
    // 0x80100914: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    after_2:
    // 0x80100918: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8010091C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80100920: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80100924: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80100928: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x8010092C: lh          $t6, 0x20($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X20);
    // 0x80100930: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80100934: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x80100938: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8010093C: addu        $t7, $s1, $t9
    ctx->r15 = ADD32(ctx->r17, ctx->r25);
    // 0x80100940: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80100944: andi        $t8, $a0, 0x1000
    ctx->r24 = ctx->r4 & 0X1000;
L_80100948:
    // 0x80100948: beql        $t8, $zero, L_80100988
    if (ctx->r24 == 0) {
        // 0x8010094C: lui         $at, 0x6000
        ctx->r1 = S32(0X6000 << 16);
            goto L_80100988;
    }
    goto skip_4;
    // 0x8010094C: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
    skip_4:
    // 0x80100950: jal         0x80102058
    // 0x80100954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80102058_ovl_intro(rdram, ctx);
        goto after_3;
    // 0x80100954: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80100958: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8010095C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80100960: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80100964: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80100968: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x8010096C: lh          $t7, 0x20($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X20);
    // 0x80100970: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80100974: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80100978: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010097C: addu        $t6, $s1, $t8
    ctx->r14 = ADD32(ctx->r17, ctx->r24);
    // 0x80100980: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80100984: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
L_80100988:
    // 0x80100988: and         $t9, $a0, $at
    ctx->r25 = ctx->r4 & ctx->r1;
    // 0x8010098C: beql        $t9, $zero, L_801009A4
    if (ctx->r25 == 0) {
        // 0x80100990: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_801009A4;
    }
    goto skip_5;
    // 0x80100990: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    skip_5:
    // 0x80100994: jal         0x80101818
    // 0x80100998: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101818_ovl_intro(rdram, ctx);
        goto after_4;
    // 0x80100998: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8010099C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x801009A0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
L_801009A4:
    // 0x801009A4: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x801009A8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x801009AC: lw          $t8, 0x6248($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6248);
    // 0x801009B0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x801009B4: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x801009B8: addu        $t9, $fp, $t6
    ctx->r25 = ADD32(ctx->r30, ctx->r14);
    // 0x801009BC: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x801009C0: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x801009C4: bne         $at, $zero, L_801009F0
    if (ctx->r1 != 0) {
        // 0x801009C8: nop
    
            goto L_801009F0;
    }
    // 0x801009C8: nop

    // 0x801009CC: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x801009D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801009D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801009D8: sw          $t8, 0x624C($at)
    MEM_W(0X624C, ctx->r1) = ctx->r24;
    // 0x801009DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801009E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801009E4: sw          $zero, 0x6244($at)
    MEM_W(0X6244, ctx->r1) = 0;
    // 0x801009E8: b           L_80100A28
    // 0x801009EC: addiu       $a0, $a0, 0x6230
    ctx->r4 = ADD32(ctx->r4, 0X6230);
        goto L_80100A28;
    // 0x801009EC: addiu       $a0, $a0, 0x6230
    ctx->r4 = ADD32(ctx->r4, 0X6230);
L_801009F0:
    // 0x801009F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801009F4: b           L_80100A08
    // 0x801009F8: sw          $zero, 0x6244($at)
    MEM_W(0X6244, ctx->r1) = 0;
        goto L_80100A08;
    // 0x801009F8: sw          $zero, 0x6244($at)
    MEM_W(0X6244, ctx->r1) = 0;
L_801009FC:
    // 0x801009FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80100A00: b           L_80100A28
    // 0x80100A04: addiu       $a0, $a0, 0x6230
    ctx->r4 = ADD32(ctx->r4, 0X6230);
        goto L_80100A28;
    // 0x80100A04: addiu       $a0, $a0, 0x6230
    ctx->r4 = ADD32(ctx->r4, 0X6230);
L_80100A08:
    // 0x80100A08: multu       $v1, $s5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100A0C: mflo        $t6
    ctx->r14 = lo;
    // 0x80100A10: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x80100A14: lh          $t7, 0x2($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X2);
    // 0x80100A18: beq         $t7, $zero, L_80100754
    if (ctx->r15 == 0) {
        // 0x80100A1C: nop
    
            goto L_80100754;
    }
    // 0x80100A1C: nop

    // 0x80100A20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80100A24: addiu       $a0, $a0, 0x6230
    ctx->r4 = ADD32(ctx->r4, 0X6230);
L_80100A28:
    // 0x80100A28: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_80100A2C:
    // 0x80100A2C: addiu       $at, $zero, 0x1E00
    ctx->r1 = ADD32(0, 0X1E00);
    // 0x80100A30: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80100A34: bne         $t8, $at, L_80100A44
    if (ctx->r24 != ctx->r1) {
        // 0x80100A38: nop
    
            goto L_80100A44;
    }
    // 0x80100A38: nop

    // 0x80100A3C: jal         0x80026434
    // 0x80100A40: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_80026434(rdram, ctx);
        goto after_5;
    // 0x80100A40: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_5:
L_80100A44:
    // 0x80100A44: jal         0x80102074
    // 0x80100A48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80102074_ovl_intro(rdram, ctx);
        goto after_6;
    // 0x80100A48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80100A4C: jal         0x80102074
    // 0x80100A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80102074_ovl_intro(rdram, ctx);
        goto after_7;
    // 0x80100A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80100A54: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x80100A58: lui         $s7, 0xFF7F
    ctx->r23 = S32(0XFF7F << 16);
    // 0x80100A5C: ori         $s7, $s7, 0xFFFF
    ctx->r23 = ctx->r23 | 0XFFFF;
    // 0x80100A60: addiu       $s3, $s3, 0x6250
    ctx->r19 = ADD32(ctx->r19, 0X6250);
    // 0x80100A64: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80100A68:
    // 0x80100A68: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80100A6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80100A70: sll         $t9, $t6, 0
    ctx->r25 = S32(ctx->r14 << 0);
    // 0x80100A74: bgezl       $t9, L_80100C78
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80100A78: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80100C78;
    }
    goto skip_6;
    // 0x80100A78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x80100A7C: jal         0x80101004
    // 0x80100A80: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    func_80101004_ovl_intro(rdram, ctx);
        goto after_8;
    // 0x80100A80: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    after_8:
    // 0x80100A84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80100A88: beq         $v0, $at, L_80100C74
    if (ctx->r2 == ctx->r1) {
        // 0x80100A8C: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80100C74;
    }
    // 0x80100A8C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80100A90: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100A94: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80100A98: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80100A9C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80100AA0: addu        $t6, $fp, $t8
    ctx->r14 = ADD32(ctx->r30, ctx->r24);
    // 0x80100AA4: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x80100AA8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80100AAC: addiu       $t6, $t6, 0x67E0
    ctx->r14 = ADD32(ctx->r14, 0X67E0);
    // 0x80100AB0: mflo        $t9
    ctx->r25 = lo;
    // 0x80100AB4: addu        $v1, $s0, $t9
    ctx->r3 = ADD32(ctx->r16, ctx->r25);
    // 0x80100AB8: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x80100ABC: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x80100AC0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80100AC4: addu        $a2, $t8, $t6
    ctx->r6 = ADD32(ctx->r24, ctx->r14);
    // 0x80100AC8: bgez        $t9, L_80100AD4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80100ACC: lw          $s1, 0x0($a2)
        ctx->r17 = MEM_W(ctx->r6, 0X0);
            goto L_80100AD4;
    }
    // 0x80100ACC: lw          $s1, 0x0($a2)
    ctx->r17 = MEM_W(ctx->r6, 0X0);
    // 0x80100AD0: and         $a0, $a0, $s7
    ctx->r4 = ctx->r4 & ctx->r23;
L_80100AD4:
    // 0x80100AD4: lh          $a1, 0x20($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X20);
    // 0x80100AD8: multu       $a1, $s6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100ADC: mflo        $t7
    ctx->r15 = lo;
    // 0x80100AE0: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80100AE4: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80100AE8: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x80100AEC: and         $t9, $t6, $a0
    ctx->r25 = ctx->r14 & ctx->r4;
    // 0x80100AF0: bnel        $t9, $zero, L_80100C78
    if (ctx->r25 != 0) {
        // 0x80100AF4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80100C78;
    }
    goto skip_7;
    // 0x80100AF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_7:
    // 0x80100AF8: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    // 0x80100AFC: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80100B00: lh          $t8, 0x20($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X20);
    // 0x80100B04: sltu        $at, $t8, $t6
    ctx->r1 = ctx->r24 < ctx->r14 ? 1 : 0;
    // 0x80100B08: bnel        $at, $zero, L_80100B34
    if (ctx->r1 != 0) {
        // 0x80100B0C: lw          $t6, 0x0($s3)
        ctx->r14 = MEM_W(ctx->r19, 0X0);
            goto L_80100B34;
    }
    goto skip_8;
    // 0x80100B0C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    skip_8:
    // 0x80100B10: jal         0x8010126C
    // 0x80100B14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8010126C_ovl_intro(rdram, ctx);
        goto after_9;
    // 0x80100B14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80100B18: multu       $s4, $s5
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100B1C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80100B20: mflo        $t7
    ctx->r15 = lo;
    // 0x80100B24: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80100B28: b           L_80100C74
    // 0x80100B2C: sh          $t9, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r25;
        goto L_80100C74;
    // 0x80100B2C: sh          $t9, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r25;
    // 0x80100B30: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
L_80100B34:
    // 0x80100B34: and         $t9, $t6, $s7
    ctx->r25 = ctx->r14 & ctx->r23;
    // 0x80100B38: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80100B3C: lh          $t8, 0x20($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X20);
    // 0x80100B40: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100B44: mflo        $t6
    ctx->r14 = lo;
    // 0x80100B48: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80100B4C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80100B50: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80100B54: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80100B58: lh          $t7, 0x20($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X20);
    // 0x80100B5C: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100B60: mflo        $t9
    ctx->r25 = lo;
    // 0x80100B64: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x80100B68: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80100B6C: sw          $t6, 0x38($s3)
    MEM_W(0X38, ctx->r19) = ctx->r14;
    // 0x80100B70: lh          $t7, 0x20($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X20);
    // 0x80100B74: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100B78: mflo        $t9
    ctx->r25 = lo;
    // 0x80100B7C: addu        $t8, $s1, $t9
    ctx->r24 = ADD32(ctx->r17, ctx->r25);
    // 0x80100B80: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80100B84: andi        $t7, $t6, 0xC800
    ctx->r15 = ctx->r14 & 0XC800;
    // 0x80100B88: beq         $t7, $zero, L_80100C08
    if (ctx->r15 == 0) {
        // 0x80100B8C: nop
    
            goto L_80100C08;
    }
    // 0x80100B8C: nop

    // 0x80100B90: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x80100B94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80100B98: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80100B9C: bne         $t9, $zero, L_80100BD4
    if (ctx->r25 != 0) {
        // 0x80100BA0: nop
    
            goto L_80100BD4;
    }
    // 0x80100BA0: nop

    // 0x80100BA4: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80100BA8: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    // 0x80100BAC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80100BB0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80100BB4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80100BB8: addu        $a0, $s0, $t6
    ctx->r4 = ADD32(ctx->r16, ctx->r14);
    // 0x80100BBC: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x80100BC0: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x80100BC4: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x80100BC8: subu        $a3, $t7, $t9
    ctx->r7 = SUB32(ctx->r15, ctx->r25);
    // 0x80100BCC: b           L_80100BD4
    // 0x80100BD0: subu        $t1, $t8, $t6
    ctx->r9 = SUB32(ctx->r24, ctx->r14);
        goto L_80100BD4;
    // 0x80100BD0: subu        $t1, $t8, $t6
    ctx->r9 = SUB32(ctx->r24, ctx->r14);
L_80100BD4:
    // 0x80100BD4: multu       $s4, $s5
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100BD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80100BDC: mflo        $t7
    ctx->r15 = lo;
    // 0x80100BE0: addu        $t9, $s0, $t7
    ctx->r25 = ADD32(ctx->r16, ctx->r15);
    // 0x80100BE4: lh          $t8, 0x20($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X20);
    // 0x80100BE8: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100BEC: mflo        $t6
    ctx->r14 = lo;
    // 0x80100BF0: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80100BF4: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x80100BF8: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x80100BFC: addu        $a1, $t7, $a3
    ctx->r5 = ADD32(ctx->r15, ctx->r7);
    // 0x80100C00: jal         0x80101CD8
    // 0x80100C04: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    func_80101CD8_ovl_intro(rdram, ctx);
        goto after_10;
    // 0x80100C04: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    after_10:
L_80100C08:
    // 0x80100C08: multu       $s4, $s5
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100C0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80100C10: mflo        $t8
    ctx->r24 = lo;
    // 0x80100C14: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x80100C18: lh          $t6, 0x20($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X20);
    // 0x80100C1C: multu       $t6, $s6
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80100C20: mflo        $t7
    ctx->r15 = lo;
    // 0x80100C24: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x80100C28: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80100C2C: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x80100C30: beql        $t8, $zero, L_80100C60
    if (ctx->r24 == 0) {
        // 0x80100C34: lui         $at, 0x6000
        ctx->r1 = S32(0X6000 << 16);
            goto L_80100C60;
    }
    goto skip_9;
    // 0x80100C34: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
    skip_9:
    // 0x80100C38: jal         0x80102058
    // 0x80100C3C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    func_80102058_ovl_intro(rdram, ctx);
        goto after_11;
    // 0x80100C3C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    after_11:
    // 0x80100C40: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80100C44: lh          $t6, 0x20($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X20);
    // 0x80100C48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80100C4C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80100C50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80100C54: addu        $t9, $s1, $t7
    ctx->r25 = ADD32(ctx->r17, ctx->r15);
    // 0x80100C58: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80100C5C: lui         $at, 0x6000
    ctx->r1 = S32(0X6000 << 16);
L_80100C60:
    // 0x80100C60: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80100C64: beql        $t8, $zero, L_80100C78
    if (ctx->r24 == 0) {
        // 0x80100C68: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80100C78;
    }
    goto skip_10;
    // 0x80100C68: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
    // 0x80100C6C: jal         0x80101818
    // 0x80100C70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101818_ovl_intro(rdram, ctx);
        goto after_12;
    // 0x80100C70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
L_80100C74:
    // 0x80100C74: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80100C78:
    // 0x80100C78: slti        $at, $s2, 0x96
    ctx->r1 = SIGNED(ctx->r18) < 0X96 ? 1 : 0;
    // 0x80100C7C: bne         $at, $zero, L_80100A68
    if (ctx->r1 != 0) {
        // 0x80100C80: addiu       $s3, $s3, 0x50
        ctx->r19 = ADD32(ctx->r19, 0X50);
            goto L_80100A68;
    }
    // 0x80100C80: addiu       $s3, $s3, 0x50
    ctx->r19 = ADD32(ctx->r19, 0X50);
    // 0x80100C84: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x80100C88: lhu         $t6, 0x2876($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2876);
    // 0x80100C8C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80100C90: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x80100C94: beq         $t7, $zero, L_80100CA4
    if (ctx->r15 == 0) {
        // 0x80100C98: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80100CA4;
    }
    // 0x80100C98: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80100C9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80100CA0: sb          $t9, 0x4DE8($at)
    MEM_B(0X4DE8, ctx->r1) = ctx->r25;
L_80100CA4:
    // 0x80100CA4: lbu         $t8, 0x4DE8($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4DE8);
    // 0x80100CA8: beq         $t8, $zero, L_80100F7C
    if (ctx->r24 == 0) {
        // 0x80100CAC: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_80100F7C;
    }
    // 0x80100CAC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80100CB0: lw          $t6, 0x4DE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4DE4);
    // 0x80100CB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80100CB8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80100CBC: addiu       $t7, $t6, 0xA
    ctx->r15 = ADD32(ctx->r14, 0XA);
    // 0x80100CC0: sw          $t7, 0x4DE4($at)
    MEM_W(0X4DE4, ctx->r1) = ctx->r15;
    // 0x80100CC4: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x80100CC8: bne         $at, $zero, L_80100CDC
    if (ctx->r1 != 0) {
        // 0x80100CCC: addiu       $v1, $v1, -0x4D04
        ctx->r3 = ADD32(ctx->r3, -0X4D04);
            goto L_80100CDC;
    }
    // 0x80100CCC: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80100CD0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80100CD4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80100CD8: sw          $t9, 0x4DE4($at)
    MEM_W(0X4DE4, ctx->r1) = ctx->r25;
L_80100CDC:
    // 0x80100CDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100CE0: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x80100CE4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80100CE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100CEC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80100CF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100CF4: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80100CF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100CFC: addiu       $t9, $t9, 0x62B0
    ctx->r25 = ADD32(ctx->r25, 0X62B0);
    // 0x80100D00: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80100D04: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100D08: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80100D0C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100D10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100D14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100D18: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80100D1C: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x80100D20: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100D24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80100D28: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80100D2C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80100D30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80100D34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100D38: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x80100D3C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80100D40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100D44: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80100D48: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80100D4C: ori         $t6, $t6, 0x4240
    ctx->r14 = ctx->r14 | 0X4240;
    // 0x80100D50: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100D54: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100D58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100D5C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80100D60: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80100D64: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100D68: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80100D6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100D70: lw          $t8, 0x4DE4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4DE4);
    // 0x80100D74: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80100D78: lui         $s4, 0x700
    ctx->r20 = S32(0X700 << 16);
    // 0x80100D7C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80100D80: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80100D84: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80100D88: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100D8C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80100D90: addiu       $t6, $t6, -0x4330
    ctx->r14 = ADD32(ctx->r14, -0X4330);
    // 0x80100D94: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100D98: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80100D9C: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80100DA0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100DA4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100DA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100DAC: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x80100DB0: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x80100DB4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100DB8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80100DBC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100DC0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100DC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100DC8: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x80100DCC: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x80100DD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100DD4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80100DD8: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x80100DDC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80100DE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100DE4: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x80100DE8: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80100DEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100DF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80100DF4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100DF8: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80100DFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100E00: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x80100E04: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80100E08: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100E0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80100E10: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100E14: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80100E18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100E1C: lui         $s7, 0x74F
    ctx->r23 = S32(0X74F << 16);
    // 0x80100E20: lui         $s2, 0xFD48
    ctx->r18 = S32(0XFD48 << 16);
    // 0x80100E24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100E28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80100E2C: lui         $s0, 0xF548
    ctx->r16 = S32(0XF548 << 16);
    // 0x80100E30: ori         $s0, $s0, 0x5000
    ctx->r16 = ctx->r16 | 0X5000;
    // 0x80100E34: ori         $s2, $s2, 0x13F
    ctx->r18 = ctx->r18 | 0X13F;
    // 0x80100E38: ori         $s7, $s7, 0xC014
    ctx->r23 = ctx->r23 | 0XC014;
    // 0x80100E3C: addiu       $s1, $s1, -0x4130
    ctx->r17 = ADD32(ctx->r17, -0X4130);
    // 0x80100E40: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80100E44: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80100E48: lui         $s6, 0xF400
    ctx->r22 = S32(0XF400 << 16);
    // 0x80100E4C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100E50: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_80100E54:
    // 0x80100E54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100E58: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x80100E5C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100E60: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80100E64: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x80100E68: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80100E6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100E70: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100E74: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80100E78: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x80100E7C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80100E80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100E84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100E88: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80100E8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100E90: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80100E94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100E98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100E9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80100EA0: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x80100EA4: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x80100EA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100EAC: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80100EB0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80100EB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80100EB8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100EBC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x80100EC0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100EC4: lui         $t9, 0x4F
    ctx->r25 = S32(0X4F << 16);
    // 0x80100EC8: ori         $t9, $t9, 0xC014
    ctx->r25 = ctx->r25 | 0XC014;
    // 0x80100ECC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100ED0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80100ED4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100ED8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80100EDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100EE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80100EE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80100EE8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80100EEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80100EF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100EF4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80100EF8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80100EFC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100F00: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80100F04: sll         $t8, $ra, 2
    ctx->r24 = S32(ctx->r31 << 2);
    // 0x80100F08: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80100F0C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80100F10: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100F14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80100F18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100F1C: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80100F20: addiu       $at, $zero, 0xF6
    ctx->r1 = ADD32(0, 0XF6);
    // 0x80100F24: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80100F28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80100F2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80100F30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80100F34: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80100F38: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80100F3C: addiu       $t5, $t5, 0x6
    ctx->r13 = ADD32(ctx->r13, 0X6);
    // 0x80100F40: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80100F44: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80100F48: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80100F4C: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80100F50: addiu       $ra, $ra, 0x6
    ctx->r31 = ADD32(ctx->r31, 0X6);
    // 0x80100F54: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80100F58: bne         $t5, $at, L_80100E54
    if (ctx->r13 != ctx->r1) {
        // 0x80100F5C: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_80100E54;
    }
    // 0x80100F5C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80100F60: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80100F64: lw          $t9, 0x4DE4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4DE4);
    // 0x80100F68: slti        $at, $t9, 0xFF
    ctx->r1 = SIGNED(ctx->r25) < 0XFF ? 1 : 0;
    // 0x80100F6C: bne         $at, $zero, L_80100F7C
    if (ctx->r1 != 0) {
        // 0x80100F70: nop
    
            goto L_80100F7C;
    }
    // 0x80100F70: nop

    // 0x80100F74: b           L_80100FD4
    // 0x80100F78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80100FD4;
    // 0x80100F78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80100F7C:
    // 0x80100F7C: jal         0x801013C0
    // 0x80100F80: nop

    func_801013C0_ovl_intro(rdram, ctx);
        goto after_13;
    // 0x80100F80: nop

    after_13:
    // 0x80100F84: bne         $v0, $zero, L_80100FD0
    if (ctx->r2 != 0) {
        // 0x80100F88: lui         $t8, 0x8016
        ctx->r24 = S32(0X8016 << 16);
            goto L_80100FD0;
    }
    // 0x80100F88: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80100F8C: lw          $t8, 0x624C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X624C);
    // 0x80100F90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100F94: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80100F98: beq         $t8, $zero, L_80100FD0
    if (ctx->r24 == 0) {
        // 0x80100F9C: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_80100FD0;
    }
    // 0x80100F9C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80100FA0: lw          $t6, 0x6248($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6248);
    // 0x80100FA4: lw          $t9, -0x4CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4CC0);
    // 0x80100FA8: sw          $zero, 0x624C($at)
    MEM_W(0X624C, ctx->r1) = 0;
    // 0x80100FAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100FB0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80100FB4: sw          $t7, 0x6248($at)
    MEM_W(0X6248, ctx->r1) = ctx->r15;
    // 0x80100FB8: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x80100FBC: bne         $at, $zero, L_80100FD0
    if (ctx->r1 != 0) {
        // 0x80100FC0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80100FD0;
    }
    // 0x80100FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100FC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80100FC8: b           L_80100FD4
    // 0x80100FCC: sw          $zero, 0x6248($at)
    MEM_W(0X6248, ctx->r1) = 0;
        goto L_80100FD4;
    // 0x80100FCC: sw          $zero, 0x6248($at)
    MEM_W(0X6248, ctx->r1) = 0;
L_80100FD0:
    // 0x80100FD0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80100FD4:
    // 0x80100FD4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80100FD8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80100FDC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80100FE0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80100FE4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80100FE8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80100FEC: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80100FF0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80100FF4: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80100FF8: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80100FFC: jr          $ra
    // 0x80101000: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80101000: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_80018684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018684: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80018688: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001868C: addiu       $v1, $v1, 0x7210
    ctx->r3 = ADD32(ctx->r3, 0X7210);
L_80018690:
    // 0x80018690: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80018694: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80018698: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8001869C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x800186A0: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x800186A4: bne         $v0, $zero, L_80018690
    if (ctx->r2 != 0) {
        // 0x800186A8: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_80018690;
    }
    // 0x800186A8: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800186AC: jr          $ra
    // 0x800186B0: nop

    return;
    // 0x800186B0: nop

;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035C30: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80035C34: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80035C38: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80035C3C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80035C40: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80035C44: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80035C48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80035C4C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80035C50: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80035C54: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80035C58: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80035C5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80035C60: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80035C64: jal         0x80035A00
    // 0x80035C68: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x80035C68: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80035C6C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80035C70: jal         0x80035200
    // 0x80035C74: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80035C74: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x80035C78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80035C7C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80035C80: jr          $ra
    // 0x80035C84: nop

    return;
    // 0x80035C84: nop

    // 0x80035C88: nop

    // 0x80035C8C: nop

;}
RECOMP_FUNC void func_80036620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036620: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80036624: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x80036628: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x8003662C: beq         $v1, $v0, L_8003663C
    if (ctx->r3 == ctx->r2) {
        // 0x80036630: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_8003663C;
    }
    // 0x80036630: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x80036634: b           L_80036640
    // 0x80036638: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_80036640;
    // 0x80036638: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8003663C:
    // 0x8003663C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_80036640:
    // 0x80036640: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80036644: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80036648: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8003664C: jr          $ra
    // 0x80036650: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x80036650: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80036654: nop

    // 0x80036658: nop

    // 0x8003665C: nop

;}
RECOMP_FUNC void func_800165E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800165E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800165E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800165EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800165F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800165F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800165F8: lhu         $t6, 0x5E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5E);
    // 0x800165FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80016600: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016604: beql        $t7, $zero, L_800166CC
    if (ctx->r15 == 0) {
        // 0x80016608: lw          $v0, 0x2C($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X2C);
            goto L_800166CC;
    }
    goto skip_0;
    // 0x80016608: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    skip_0:
    // 0x8001660C: jal         0x8000B140
    // 0x80016610: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_8000B140(rdram, ctx);
        goto after_0;
    // 0x80016610: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80016614: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80016618: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001661C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80016620: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80016624: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80016628: addiu       $t9, $t9, -0x3668
    ctx->r25 = ADD32(ctx->r25, -0X3668);
    // 0x8001662C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80016630: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80016634: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80016638: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001663C: sw          $t0, 0x71DC($at)
    MEM_W(0X71DC, ctx->r1) = ctx->r8;
    // 0x80016640: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80016644: lw          $t3, 0x2C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X2C);
    // 0x80016648: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8001664C: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x80016650: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x80016654: multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016658: mflo        $a3
    ctx->r7 = lo;
    // 0x8001665C: nop

    // 0x80016660: nop

    // 0x80016664: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x80016668: mflo        $t5
    ctx->r13 = lo;
    // 0x8001666C: andi        $a1, $t5, 0xFFFF
    ctx->r5 = ctx->r13 & 0XFFFF;
    // 0x80016670: sra         $a0, $a1, 2
    ctx->r4 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80016674: jal         0x80022FD0
    // 0x80016678: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    get_rand(rdram, ctx);
        goto after_1;
    // 0x80016678: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001667C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80016680: addiu       $a2, $a2, 0x71DC
    ctx->r6 = ADD32(ctx->r6, 0X71DC);
    // 0x80016684: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80016688: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8001668C: lhu         $t8, 0xA($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XA);
    // 0x80016690: addu        $a3, $a1, $v0
    ctx->r7 = ADD32(ctx->r5, ctx->r2);
    // 0x80016694: andi        $t7, $a3, 0xFFFF
    ctx->r15 = ctx->r7 & 0XFFFF;
    // 0x80016698: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8001669C: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
    // 0x800166A0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800166A4: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x800166A8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800166AC: lhu         $t1, 0xA($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0XA);
    // 0x800166B0: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    // 0x800166B4: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800166B8: beql        $at, $zero, L_8001677C
    if (ctx->r1 == 0) {
        // 0x800166BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001677C;
    }
    goto skip_1;
    // 0x800166BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800166C0: b           L_80016778
    // 0x800166C4: sh          $a0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r4;
        goto L_80016778;
    // 0x800166C4: sh          $a0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r4;
    // 0x800166C8: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
L_800166CC:
    // 0x800166CC: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x800166D0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800166D4: lhu         $t9, 0xC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XC);
    // 0x800166D8: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x800166DC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800166E0: lw          $t3, -0x4538($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4538);
    // 0x800166E4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800166E8: lbu         $t2, 0x6($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X6);
    // 0x800166EC: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x800166F0: lbu         $t5, 0x24($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X24);
    // 0x800166F4: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800166F8: mflo        $t0
    ctx->r8 = lo;
    // 0x800166FC: nop

    // 0x80016700: nop

    // 0x80016704: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80016708: mflo        $t1
    ctx->r9 = lo;
    // 0x8001670C: addu        $a3, $t6, $t1
    ctx->r7 = ADD32(ctx->r14, ctx->r9);
    // 0x80016710: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x80016714: sra         $a0, $a1, 2
    ctx->r4 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80016718: jal         0x80022FD0
    // 0x8001671C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    get_rand(rdram, ctx);
        goto after_2;
    // 0x8001671C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80016720: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x80016724: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80016728: lhu         $a2, 0x4($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X4);
    // 0x8001672C: lhu         $t4, 0x6($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X6);
    // 0x80016730: addu        $a3, $a1, $v0
    ctx->r7 = ADD32(ctx->r5, ctx->r2);
    // 0x80016734: andi        $t2, $a3, 0xFFFF
    ctx->r10 = ctx->r7 & 0XFFFF;
    // 0x80016738: beq         $t4, $a2, L_80016778
    if (ctx->r12 == ctx->r6) {
        // 0x8001673C: or          $a3, $t2, $zero
        ctx->r7 = ctx->r10 | 0;
            goto L_80016778;
    }
    // 0x8001673C: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80016740: addu        $t5, $a2, $t2
    ctx->r13 = ADD32(ctx->r6, ctx->r10);
    // 0x80016744: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
    // 0x80016748: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x8001674C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016750: lhu         $a0, 0x6($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X6);
    // 0x80016754: lhu         $t7, 0x4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X4);
    // 0x80016758: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001675C: beq         $at, $zero, L_80016768
    if (ctx->r1 == 0) {
        // 0x80016760: nop
    
            goto L_80016768;
    }
    // 0x80016760: nop

    // 0x80016764: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
L_80016768:
    // 0x80016768: lw          $v0, -0x4538($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4538);
    // 0x8001676C: lhu         $t8, 0x2A($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2A);
    // 0x80016770: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80016774: sh          $t9, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r25;
L_80016778:
    // 0x80016778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001677C:
    // 0x8001677C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80016780: jal         0x80018DF4
    // 0x80016784: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80018DF4(rdram, ctx);
        goto after_3;
    // 0x80016784: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_3:
    // 0x80016788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001678C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016790: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80016794: jr          $ra
    // 0x80016798: nop

    return;
    // 0x80016798: nop

;}
RECOMP_FUNC void func_80026F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026F34: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80026F38: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80026F3C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80026F40: addiu       $t1, $t1, -0x4D04
    ctx->r9 = ADD32(ctx->r9, -0X4D04);
    // 0x80026F44: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80026F48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80026F4C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80026F50: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80026F54: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80026F58: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80026F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80026F60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80026F64: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80026F68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80026F6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80026F70: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80026F74: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80026F78: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80026F7C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80026F80: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80026F84: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80026F88: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80026F8C: addiu       $t3, $zero, 0x98
    ctx->r11 = ADD32(0, 0X98);
    // 0x80026F90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80026F94: addiu       $a1, $s2, 0x28
    ctx->r5 = ADD32(ctx->r18, 0X28);
    // 0x80026F98: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80026F9C: jal         0x80029B58
    // 0x80026FA0: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    func_80029B58(rdram, ctx);
        goto after_0;
    // 0x80026FA0: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_0:
    // 0x80026FA4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80026FA8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80026FAC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80026FB0: addiu       $a1, $s2, 0x2B
    ctx->r5 = ADD32(ctx->r18, 0X2B);
    // 0x80026FB4: addiu       $a2, $zero, 0xB7
    ctx->r6 = ADD32(0, 0XB7);
    // 0x80026FB8: jal         0x80029B58
    // 0x80026FBC: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    func_80029B58(rdram, ctx);
        goto after_1;
    // 0x80026FBC: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_1:
    // 0x80026FC0: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x80026FC4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80026FC8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80026FCC: addiu       $a1, $s2, 0x119
    ctx->r5 = ADD32(ctx->r18, 0X119);
    // 0x80026FD0: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x80026FD4: jal         0x80029B58
    // 0x80026FD8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80029B58(rdram, ctx);
        goto after_2;
    // 0x80026FD8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80026FDC: addiu       $s0, $s2, 0x27
    ctx->r16 = ADD32(ctx->r18, 0X27);
    // 0x80026FE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80026FE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80026FE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80026FEC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80026FF0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80026FF4: jal         0x80029B58
    // 0x80026FF8: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_3;
    // 0x80026FF8: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_3:
    // 0x80026FFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80027000: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80027004: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027008: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002700C: addiu       $a2, $zero, 0xB6
    ctx->r6 = ADD32(0, 0XB6);
    // 0x80027010: jal         0x80029B58
    // 0x80027014: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    func_80029B58(rdram, ctx);
        goto after_4;
    // 0x80027014: addiu       $a3, $zero, 0xF2
    ctx->r7 = ADD32(0, 0XF2);
    after_4:
    // 0x80027018: addiu       $t8, $zero, 0x9A
    ctx->r24 = ADD32(0, 0X9A);
    // 0x8002701C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027020: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027024: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027028: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x8002702C: jal         0x80029B58
    // 0x80027030: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_5;
    // 0x80027030: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80027034: addiu       $t9, $zero, 0x9A
    ctx->r25 = ADD32(0, 0X9A);
    // 0x80027038: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002703C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80027040: addiu       $a1, $s2, 0x118
    ctx->r5 = ADD32(ctx->r18, 0X118);
    // 0x80027044: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80027048: jal         0x80029B58
    // 0x8002704C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_6;
    // 0x8002704C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80027050: addiu       $s0, $s2, 0x29
    ctx->r16 = ADD32(ctx->r18, 0X29);
    // 0x80027054: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80027058: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002705C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027060: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80027064: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80027068: jal         0x80029B58
    // 0x8002706C: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    func_80029B58(rdram, ctx);
        goto after_7;
    // 0x8002706C: addiu       $a3, $zero, 0xED
    ctx->r7 = ADD32(0, 0XED);
    after_7:
    // 0x80027070: addiu       $t3, $zero, 0x95
    ctx->r11 = ADD32(0, 0X95);
    // 0x80027074: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027078: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x8002707C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027080: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80027084: jal         0x80029B58
    // 0x80027088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_8;
    // 0x80027088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8002708C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80027090: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80027094: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80027098: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002709C: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    // 0x800270A0: jal         0x80029B58
    // 0x800270A4: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    func_80029B58(rdram, ctx);
        goto after_9;
    // 0x800270A4: addiu       $a3, $zero, 0xEE
    ctx->r7 = ADD32(0, 0XEE);
    after_9:
    // 0x800270A8: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x800270AC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800270B0: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x800270B4: addiu       $a1, $s2, 0x116
    ctx->r5 = ADD32(ctx->r18, 0X116);
    // 0x800270B8: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x800270BC: jal         0x80029B58
    // 0x800270C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80029B58(rdram, ctx);
        goto after_10;
    // 0x800270C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x800270C4: addiu       $t6, $zero, 0x98
    ctx->r14 = ADD32(0, 0X98);
    // 0x800270C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800270CC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800270D0: addiu       $a1, $s2, 0x3A
    ctx->r5 = ADD32(ctx->r18, 0X3A);
    // 0x800270D4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x800270D8: jal         0x80029B58
    // 0x800270DC: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    func_80029B58(rdram, ctx);
        goto after_11;
    // 0x800270DC: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    after_11:
    // 0x800270E0: addiu       $a1, $s2, 0x5D
    ctx->r5 = ADD32(ctx->r18, 0X5D);
    // 0x800270E4: addiu       $s0, $zero, 0x4B
    ctx->r16 = ADD32(0, 0X4B);
    // 0x800270E8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x800270EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800270F0:
    // 0x800270F0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800270F4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800270F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800270FC: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x80027100: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80027104: jal         0x80029B58
    // 0x80027108: addiu       $a3, $zero, 0xA7
    ctx->r7 = ADD32(0, 0XA7);
    func_80029B58(rdram, ctx);
        goto after_12;
    // 0x80027108: addiu       $a3, $zero, 0xA7
    ctx->r7 = ADD32(0, 0XA7);
    after_12:
    // 0x8002710C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027110: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80027114: bne         $at, $zero, L_800270F0
    if (ctx->r1 != 0) {
        // 0x80027118: addiu       $s0, $s0, 0x21
        ctx->r16 = ADD32(ctx->r16, 0X21);
            goto L_800270F0;
    }
    // 0x80027118: addiu       $s0, $s0, 0x21
    ctx->r16 = ADD32(ctx->r16, 0X21);
    // 0x8002711C: addiu       $a1, $s2, 0x63
    ctx->r5 = ADD32(ctx->r18, 0X63);
    // 0x80027120: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80027124: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80027128: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8002712C:
    // 0x8002712C: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x80027130: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80027134: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027138: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8002713C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80027140: jal         0x80029B58
    // 0x80027144: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    func_80029B58(rdram, ctx);
        goto after_13;
    // 0x80027144: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_13:
    // 0x80027148: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002714C: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80027150: bne         $at, $zero, L_8002712C
    if (ctx->r1 != 0) {
        // 0x80027154: addiu       $s0, $s0, 0x21
        ctx->r16 = ADD32(ctx->r16, 0X21);
            goto L_8002712C;
    }
    // 0x80027154: addiu       $s0, $s0, 0x21
    ctx->r16 = ADD32(ctx->r16, 0X21);
    // 0x80027158: addiu       $a1, $s2, 0xC3
    ctx->r5 = ADD32(ctx->r18, 0XC3);
    // 0x8002715C: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
    // 0x80027160: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80027164: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80027168:
    // 0x80027168: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8002716C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80027170: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027174: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80027178: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002717C: jal         0x80029B58
    // 0x80027180: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    func_80029B58(rdram, ctx);
        goto after_14;
    // 0x80027180: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    after_14:
    // 0x80027184: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027188: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8002718C: bne         $at, $zero, L_80027168
    if (ctx->r1 != 0) {
        // 0x80027190: addiu       $s0, $s0, 0x21
        ctx->r16 = ADD32(ctx->r16, 0X21);
            goto L_80027168;
    }
    // 0x80027190: addiu       $s0, $s0, 0x21
    ctx->r16 = ADD32(ctx->r16, 0X21);
    // 0x80027194: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x80027198: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002719C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x800271A0: addiu       $a1, $s2, 0x38
    ctx->r5 = ADD32(ctx->r18, 0X38);
    // 0x800271A4: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x800271A8: jal         0x80029B58
    // 0x800271AC: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    func_80029B58(rdram, ctx);
        goto after_15;
    // 0x800271AC: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_15:
    // 0x800271B0: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x800271B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800271B8: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x800271BC: addiu       $a1, $s2, 0x37
    ctx->r5 = ADD32(ctx->r18, 0X37);
    // 0x800271C0: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    // 0x800271C4: jal         0x80029B58
    // 0x800271C8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_16;
    // 0x800271C8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_16:
    // 0x800271CC: addiu       $s0, $s2, 0x35
    ctx->r16 = ADD32(ctx->r18, 0X35);
    // 0x800271D0: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x800271D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800271D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800271DC: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800271E0: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x800271E4: jal         0x80029B58
    // 0x800271E8: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    func_80029B58(rdram, ctx);
        goto after_17;
    // 0x800271E8: addiu       $a3, $zero, 0x24
    ctx->r7 = ADD32(0, 0X24);
    after_17:
    // 0x800271EC: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    // 0x800271F0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800271F4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800271F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800271FC: addiu       $a2, $zero, 0x99
    ctx->r6 = ADD32(0, 0X99);
    // 0x80027200: jal         0x80029B58
    // 0x80027204: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    func_80029B58(rdram, ctx);
        goto after_18;
    // 0x80027204: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_18:
    // 0x80027208: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8002720C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027210: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80027214: addiu       $a1, $s2, 0x45
    ctx->r5 = ADD32(ctx->r18, 0X45);
    // 0x80027218: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8002721C: jal         0x80029B58
    // 0x80027220: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_19;
    // 0x80027220: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_19:
    // 0x80027224: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80027228: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002722C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80027230: addiu       $a1, $s2, 0xF3
    ctx->r5 = ADD32(ctx->r18, 0XF3);
    // 0x80027234: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80027238: jal         0x80029B58
    // 0x8002723C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_20;
    // 0x8002723C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_20:
    // 0x80027240: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x80027244: lw          $s1, -0x2F0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X2F0);
    // 0x80027248: lui         $at, 0x8006
    ctx->r1 = S32(0X8006 << 16);
    // 0x8002724C: addiu       $t2, $zero, 0xB
    ctx->r10 = ADD32(0, 0XB);
    // 0x80027250: sra         $t8, $s1, 2
    ctx->r24 = S32(SIGNED(ctx->r17) >> 2);
    // 0x80027254: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80027258: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002725C: lb          $s1, -0xF40($at)
    ctx->r17 = MEM_B(ctx->r1, -0XF40);
    // 0x80027260: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80027264: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80027268: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x8002726C: addiu       $a1, $a1, 0x36
    ctx->r5 = ADD32(ctx->r5, 0X36);
    // 0x80027270: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80027274: jal         0x80029B58
    // 0x80027278: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80029B58(rdram, ctx);
        goto after_21;
    // 0x80027278: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_21:
    // 0x8002727C: subu        $a1, $s2, $s1
    ctx->r5 = SUB32(ctx->r18, ctx->r17);
    // 0x80027280: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80027284: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027288: addiu       $a1, $a1, 0xFB
    ctx->r5 = ADD32(ctx->r5, 0XFB);
    // 0x8002728C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80027290: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80027294: jal         0x80029B58
    // 0x80027298: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    func_80029B58(rdram, ctx);
        goto after_22;
    // 0x80027298: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    after_22:
    // 0x8002729C: addiu       $s0, $s2, 0x79
    ctx->r16 = ADD32(ctx->r18, 0X79);
    // 0x800272A0: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800272A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800272A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800272AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800272B0: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // 0x800272B4: jal         0x80029B58
    // 0x800272B8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_23;
    // 0x800272B8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_23:
    // 0x800272BC: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x800272C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800272C4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800272C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800272CC: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    // 0x800272D0: jal         0x80029B58
    // 0x800272D4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_24;
    // 0x800272D4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_24:
    // 0x800272D8: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x800272DC: addiu       $s0, $s2, 0x80
    ctx->r16 = ADD32(ctx->r18, 0X80);
    // 0x800272E0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800272E4: lhu         $a3, -0x457A($s1)
    ctx->r7 = MEM_HU(ctx->r17, -0X457A);
    // 0x800272E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800272EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800272F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800272F4: jal         0x8002AB64
    // 0x800272F8: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    func_8002AB64(rdram, ctx);
        goto after_25;
    // 0x800272F8: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    after_25:
    // 0x800272FC: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80027300: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80027304: lhu         $a3, -0x4576($s1)
    ctx->r7 = MEM_HU(ctx->r17, -0X4576);
    // 0x80027308: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002730C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80027310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027314: jal         0x8002AB64
    // 0x80027318: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    func_8002AB64(rdram, ctx);
        goto after_26;
    // 0x80027318: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    after_26:
    // 0x8002731C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80027320: addiu       $a1, $s2, 0x64
    ctx->r5 = ADD32(ctx->r18, 0X64);
    // 0x80027324: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80027328: lhu         $a3, -0x457C($s1)
    ctx->r7 = MEM_HU(ctx->r17, -0X457C);
    // 0x8002732C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027330: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80027334: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80027338: jal         0x8002AB64
    // 0x8002733C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    func_8002AB64(rdram, ctx);
        goto after_27;
    // 0x8002733C: addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    after_27:
    // 0x80027340: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80027344: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80027348: lhu         $a3, -0x4578($s1)
    ctx->r7 = MEM_HU(ctx->r17, -0X4578);
    // 0x8002734C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027350: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80027354: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80027358: jal         0x8002AB64
    // 0x8002735C: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    func_8002AB64(rdram, ctx);
        goto after_28;
    // 0x8002735C: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    after_28:
    // 0x80027360: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80027364: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80027368: lhu         $a3, -0x4572($s1)
    ctx->r7 = MEM_HU(ctx->r17, -0X4572);
    // 0x8002736C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80027370: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80027374: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027378: jal         0x8002AB64
    // 0x8002737C: addiu       $a2, $zero, 0x77
    ctx->r6 = ADD32(0, 0X77);
    func_8002AB64(rdram, ctx);
        goto after_29;
    // 0x8002737C: addiu       $a2, $zero, 0x77
    ctx->r6 = ADD32(0, 0X77);
    after_29:
    // 0x80027380: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80027384: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80027388: lhu         $a3, -0x4574($s1)
    ctx->r7 = MEM_HU(ctx->r17, -0X4574);
    // 0x8002738C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80027390: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80027394: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027398: jal         0x8002AB64
    // 0x8002739C: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    func_8002AB64(rdram, ctx);
        goto after_30;
    // 0x8002739C: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    after_30:
    // 0x800273A0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800273A4: lhu         $t6, -0x4558($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4558);
    // 0x800273A8: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x800273AC: lbu         $t4, -0x4550($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X4550);
    // 0x800273B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800273B4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800273B8: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x800273BC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800273C0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800273C4: addu        $s1, $s1, $t5
    ctx->r17 = ADD32(ctx->r17, ctx->r13);
    // 0x800273C8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800273CC: lhu         $s1, 0x3ECC($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3ECC);
    // 0x800273D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800273D4: addiu       $s0, $s2, 0xDA
    ctx->r16 = ADD32(ctx->r18, 0XDA);
    // 0x800273D8: div         $zero, $t7, $s1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r17)));
    // 0x800273DC: mflo        $a3
    ctx->r7 = lo;
    // 0x800273E0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800273E4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800273E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800273EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800273F0: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x800273F4: bne         $s1, $zero, L_80027400
    if (ctx->r17 != 0) {
        // 0x800273F8: nop
    
            goto L_80027400;
    }
    // 0x800273F8: nop

    // 0x800273FC: break       7
    do_break(2147644412);
L_80027400:
    // 0x80027400: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80027404: bne         $s1, $at, L_80027418
    if (ctx->r17 != ctx->r1) {
        // 0x80027408: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80027418;
    }
    // 0x80027408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002740C: bne         $t7, $at, L_80027418
    if (ctx->r15 != ctx->r1) {
        // 0x80027410: nop
    
            goto L_80027418;
    }
    // 0x80027410: nop

    // 0x80027414: break       6
    do_break(2147644436);
L_80027418:
    // 0x80027418: jal         0x8002AB64
    // 0x8002741C: nop

    func_8002AB64(rdram, ctx);
        goto after_31;
    // 0x8002741C: nop

    after_31:
    // 0x80027420: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80027424: lbu         $t9, -0x454F($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X454F);
    // 0x80027428: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8002742C: lhu         $t4, -0x4556($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X4556);
    // 0x80027430: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80027434: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80027438: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
    // 0x8002743C: lhu         $s1, 0x3ECC($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3ECC);
    // 0x80027440: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80027444: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80027448: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002744C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80027450: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80027454: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80027458: div         $zero, $t5, $t3
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r11)));
    // 0x8002745C: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x80027460: mflo        $a3
    ctx->r7 = lo;
    // 0x80027464: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80027468: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002746C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80027470: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027474: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x80027478: bne         $s1, $zero, L_80027484
    if (ctx->r17 != 0) {
        // 0x8002747C: nop
    
            goto L_80027484;
    }
    // 0x8002747C: nop

    // 0x80027480: break       7
    do_break(2147644544);
L_80027484:
    // 0x80027484: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80027488: bne         $s1, $at, L_8002749C
    if (ctx->r17 != ctx->r1) {
        // 0x8002748C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002749C;
    }
    // 0x8002748C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027490: bne         $t5, $at, L_8002749C
    if (ctx->r13 != ctx->r1) {
        // 0x80027494: nop
    
            goto L_8002749C;
    }
    // 0x80027494: nop

    // 0x80027498: break       6
    do_break(2147644568);
L_8002749C:
    // 0x8002749C: jal         0x8002AB64
    // 0x800274A0: nop

    func_8002AB64(rdram, ctx);
        goto after_32;
    // 0x800274A0: nop

    after_32:
    // 0x800274A4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800274A8: lbu         $t7, -0x454D($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X454D);
    // 0x800274AC: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800274B0: lhu         $t2, -0x4552($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4552);
    // 0x800274B4: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x800274B8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800274BC: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x800274C0: lhu         $s1, 0x3ECC($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3ECC);
    // 0x800274C4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800274C8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800274CC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800274D0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800274D4: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x800274D8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800274DC: div         $zero, $t3, $t9
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r25)));
    // 0x800274E0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800274E4: mflo        $a3
    ctx->r7 = lo;
    // 0x800274E8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x800274EC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800274F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800274F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800274F8: addiu       $a2, $zero, 0x7D
    ctx->r6 = ADD32(0, 0X7D);
    // 0x800274FC: bne         $s1, $zero, L_80027508
    if (ctx->r17 != 0) {
        // 0x80027500: nop
    
            goto L_80027508;
    }
    // 0x80027500: nop

    // 0x80027504: break       7
    do_break(2147644676);
L_80027508:
    // 0x80027508: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002750C: bne         $s1, $at, L_80027520
    if (ctx->r17 != ctx->r1) {
        // 0x80027510: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80027520;
    }
    // 0x80027510: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027514: bne         $t3, $at, L_80027520
    if (ctx->r11 != ctx->r1) {
        // 0x80027518: nop
    
            goto L_80027520;
    }
    // 0x80027518: nop

    // 0x8002751C: break       6
    do_break(2147644700);
L_80027520:
    // 0x80027520: jal         0x8002AB64
    // 0x80027524: nop

    func_8002AB64(rdram, ctx);
        goto after_33;
    // 0x80027524: nop

    after_33:
    // 0x80027528: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8002752C: lhu         $t7, -0x4554($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X4554);
    // 0x80027530: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80027534: lbu         $t5, -0x454E($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X454E);
    // 0x80027538: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002753C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80027540: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80027544: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80027548: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8002754C: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x80027550: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80027554: lhu         $s1, 0x3ECC($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X3ECC);
    // 0x80027558: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002755C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80027560: div         $zero, $t8, $s1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r17))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r17)));
    // 0x80027564: mflo        $a3
    ctx->r7 = lo;
    // 0x80027568: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002756C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80027570: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80027574: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    // 0x80027578: bne         $s1, $zero, L_80027584
    if (ctx->r17 != 0) {
        // 0x8002757C: nop
    
            goto L_80027584;
    }
    // 0x8002757C: nop

    // 0x80027580: break       7
    do_break(2147644800);
L_80027584:
    // 0x80027584: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80027588: bne         $s1, $at, L_8002759C
    if (ctx->r17 != ctx->r1) {
        // 0x8002758C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002759C;
    }
    // 0x8002758C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027590: bne         $t8, $at, L_8002759C
    if (ctx->r24 != ctx->r1) {
        // 0x80027594: nop
    
            goto L_8002759C;
    }
    // 0x80027594: nop

    // 0x80027598: break       6
    do_break(2147644824);
L_8002759C:
    // 0x8002759C: jal         0x8002AB64
    // 0x800275A0: nop

    func_8002AB64(rdram, ctx);
        goto after_34;
    // 0x800275A0: nop

    after_34:
    // 0x800275A4: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800275A8: lhu         $t2, -0x457C($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X457C);
    // 0x800275AC: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x800275B0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800275B4: bgez        $t2, L_800275CC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800275B8: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800275CC;
    }
    // 0x800275B8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800275BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800275C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800275C4: nop

    // 0x800275C8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800275CC:
    // 0x800275CC: lhu         $t3, -0x457A($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X457A);
    // 0x800275D0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800275D4: bgez        $t3, L_800275EC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800275D8: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800275EC;
    }
    // 0x800275D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800275DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800275E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800275E4: nop

    // 0x800275E8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800275EC:
    // 0x800275EC: div.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800275F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800275F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800275F8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800275FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80027600: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80027604: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80027608: addiu       $a2, $zero, 0x41
    ctx->r6 = ADD32(0, 0X41);
    // 0x8002760C: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80027610: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027614: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80027618: jal         0x80029B58
    // 0x8002761C: nop

    func_80029B58(rdram, ctx);
        goto after_35;
    // 0x8002761C: nop

    after_35:
    // 0x80027620: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80027624: lhu         $t6, -0x4578($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4578);
    // 0x80027628: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8002762C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80027630: bgez        $t6, L_80027648
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80027634: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80027648;
    }
    // 0x80027634: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027638: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002763C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027640: nop

    // 0x80027644: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80027648:
    // 0x80027648: lhu         $t7, -0x4576($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X4576);
    // 0x8002764C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80027650: bgez        $t7, L_80027668
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80027654: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80027668;
    }
    // 0x80027654: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80027658: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002765C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027660: nop

    // 0x80027664: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_80027668:
    // 0x80027668: div.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8002766C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80027670: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027674: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80027678: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002767C: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80027680: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80027684: addiu       $a2, $zero, 0x62
    ctx->r6 = ADD32(0, 0X62);
    // 0x80027688: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8002768C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027690: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80027694: jal         0x80029B58
    // 0x80027698: nop

    func_80029B58(rdram, ctx);
        goto after_36;
    // 0x80027698: nop

    after_36:
    // 0x8002769C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x800276A0: lhu         $t2, -0x4572($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4572);
    // 0x800276A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800276A8: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800276AC: bgez        $t2, L_800276C0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800276B0: cvt.s.w     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800276C0;
    }
    // 0x800276B0: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800276B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800276B8: nop

    // 0x800276BC: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
L_800276C0:
    // 0x800276C0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800276C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800276C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800276CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800276D0: div.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800276D4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800276D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800276DC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800276E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800276E4: addiu       $a2, $zero, 0x83
    ctx->r6 = ADD32(0, 0X83);
    // 0x800276E8: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800276EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800276F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800276F4: jal         0x80029B58
    // 0x800276F8: nop

    func_80029B58(rdram, ctx);
        goto after_37;
    // 0x800276F8: nop

    after_37:
    // 0x800276FC: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80027700: lhu         $t5, -0x4574($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X4574);
    // 0x80027704: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80027708: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8002770C: bgez        $t5, L_80027720
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80027710: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80027720;
    }
    // 0x80027710: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80027714: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80027718: nop

    // 0x8002771C: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80027720:
    // 0x80027720: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80027724: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027728: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8002772C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027730: div.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80027734: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80027738: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8002773C: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80027740: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80027744: addiu       $a2, $zero, 0xA4
    ctx->r6 = ADD32(0, 0XA4);
    // 0x80027748: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8002774C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80027750: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80027754: jal         0x80029B58
    // 0x80027758: nop

    func_80029B58(rdram, ctx);
        goto after_38;
    // 0x80027758: nop

    after_38:
    // 0x8002775C: addiu       $s0, $s2, 0xF6
    ctx->r16 = ADD32(ctx->r18, 0XF6);
    // 0x80027760: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80027764: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80027768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002776C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80027770: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x80027774: jal         0x80029B58
    // 0x80027778: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_39;
    // 0x80027778: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_39:
    // 0x8002777C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80027780: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80027784: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80027788: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002778C: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x80027790: jal         0x80029B58
    // 0x80027794: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_40;
    // 0x80027794: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_40:
    // 0x80027798: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002779C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800277A0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800277A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800277A8: addiu       $a2, $zero, 0x7D
    ctx->r6 = ADD32(0, 0X7D);
    // 0x800277AC: jal         0x80029B58
    // 0x800277B0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_41;
    // 0x800277B0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_41:
    // 0x800277B4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x800277B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800277BC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x800277C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800277C4: addiu       $a2, $zero, 0x9E
    ctx->r6 = ADD32(0, 0X9E);
    // 0x800277C8: jal         0x80029B58
    // 0x800277CC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_80029B58(rdram, ctx);
        goto after_42;
    // 0x800277CC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_42:
    // 0x800277D0: addiu       $t4, $zero, 0x12
    ctx->r12 = ADD32(0, 0X12);
    // 0x800277D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800277D8: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x800277DC: addiu       $a1, $s2, 0x87
    ctx->r5 = ADD32(ctx->r18, 0X87);
    // 0x800277E0: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x800277E4: jal         0x80029B58
    // 0x800277E8: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    func_80029B58(rdram, ctx);
        goto after_43;
    // 0x800277E8: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_43:
    // 0x800277EC: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x800277F0: addiu       $t0, $t0, -0x2F4
    ctx->r8 = ADD32(ctx->r8, -0X2F4);
    // 0x800277F4: lhu         $a3, 0x0($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X0);
    // 0x800277F8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800277FC: andi        $t5, $a3, 0x2000
    ctx->r13 = ctx->r7 & 0X2000;
    // 0x80027800: bnel        $t5, $zero, L_8002789C
    if (ctx->r13 != 0) {
        // 0x80027804: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8002789C;
    }
    goto skip_0;
    // 0x80027804: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80027808: lb          $v0, 0x2871($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2871);
    // 0x8002780C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80027810: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80027814: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80027818: beq         $at, $zero, L_80027834
    if (ctx->r1 == 0) {
        // 0x8002781C: ori         $t8, $a3, 0x2000
        ctx->r24 = ctx->r7 | 0X2000;
            goto L_80027834;
    }
    // 0x8002781C: ori         $t8, $a3, 0x2000
    ctx->r24 = ctx->r7 | 0X2000;
    // 0x80027820: lhu         $v1, 0x2876($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X2876);
    // 0x80027824: slti        $at, $v0, -0x14
    ctx->r1 = SIGNED(ctx->r2) < -0X14 ? 1 : 0;
    // 0x80027828: andi        $t6, $v1, 0x10
    ctx->r14 = ctx->r3 & 0X10;
    // 0x8002782C: beq         $t6, $zero, L_80027860
    if (ctx->r14 == 0) {
        // 0x80027830: nop
    
            goto L_80027860;
    }
    // 0x80027830: nop

L_80027834:
    // 0x80027834: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027838: sw          $t7, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = ctx->r15;
    // 0x8002783C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027840: sw          $zero, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = 0;
    // 0x80027844: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x80027848: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002784C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80027850: jal         0x800268D4
    // 0x80027854: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_44;
    // 0x80027854: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_44:
    // 0x80027858: b           L_8002789C
    // 0x8002785C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8002789C;
    // 0x8002785C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80027860:
    // 0x80027860: bne         $at, $zero, L_8002786C
    if (ctx->r1 != 0) {
        // 0x80027864: andi        $t9, $v1, 0x2000
        ctx->r25 = ctx->r3 & 0X2000;
            goto L_8002786C;
    }
    // 0x80027864: andi        $t9, $v1, 0x2000
    ctx->r25 = ctx->r3 & 0X2000;
    // 0x80027868: beq         $t9, $zero, L_80027898
    if (ctx->r25 == 0) {
        // 0x8002786C: lui         $at, 0x8009
        ctx->r1 = S32(0X8009 << 16);
            goto L_80027898;
    }
L_8002786C:
    // 0x8002786C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027870: sw          $zero, -0x2FC($at)
    MEM_W(-0X2FC, ctx->r1) = 0;
    // 0x80027874: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80027878: addiu       $t2, $zero, -0x140
    ctx->r10 = ADD32(0, -0X140);
    // 0x8002787C: sw          $t2, -0x2F8($at)
    MEM_W(-0X2F8, ctx->r1) = ctx->r10;
    // 0x80027880: ori         $t3, $a3, 0x3000
    ctx->r11 = ctx->r7 | 0X3000;
    // 0x80027884: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x80027888: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002788C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80027890: jal         0x800268D4
    // 0x80027894: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    func_800268D4(rdram, ctx);
        goto after_45;
    // 0x80027894: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_45:
L_80027898:
    // 0x80027898: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8002789C:
    // 0x8002789C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800278A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800278A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800278A8: jr          $ra
    // 0x800278AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800278AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80103524_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103524: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80103528: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x8010352C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103538: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8010353C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80103540: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80103544: addiu       $t8, $t8, 0x6240
    ctx->r24 = ADD32(ctx->r24, 0X6240);
    // 0x80103548: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8010354C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80103550: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80103554: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80103558: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x8010355C: lui         $t2, 0xFFFC
    ctx->r10 = S32(0XFFFC << 16);
    // 0x80103560: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80103564: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80103568: ori         $t2, $t2, 0xFA7D
    ctx->r10 = ctx->r10 | 0XFA7D;
    // 0x8010356C: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80103570: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80103574: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80103578: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010357C: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x80103580: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x80103584: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80103588: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8010358C: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x80103590: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x80103594: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80103598: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8010359C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801035A0: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x801035A4: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x801035A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801035AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801035B0: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x801035B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801035B8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x801035BC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801035C0: jal         0x8010421C
    // 0x801035C4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    func_8010421C_ovl_intro(rdram, ctx);
        goto after_0;
    // 0x801035C4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    after_0:
    // 0x801035C8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x801035CC: addiu       $v1, $v1, 0x6200
    ctx->r3 = ADD32(ctx->r3, 0X6200);
    // 0x801035D0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x801035D4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x801035D8: addiu       $a1, $a1, 0x6224
    ctx->r5 = ADD32(ctx->r5, 0X6224);
    // 0x801035DC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x801035E0: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x801035E4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801035E8: addiu       $t0, $t0, 0x6220
    ctx->r8 = ADD32(ctx->r8, 0X6220);
    // 0x801035EC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x801035F0: beq         $a0, $zero, L_80103614
    if (ctx->r4 == 0) {
        // 0x801035F4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80103614;
    }
    // 0x801035F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801035F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801035FC: beq         $v0, $at, L_80103644
    if (ctx->r2 == ctx->r1) {
        // 0x80103600: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80103644;
    }
    // 0x80103600: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80103604: beql        $v0, $at, L_80103668
    if (ctx->r2 == ctx->r1) {
        // 0x80103608: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_80103668;
    }
    goto skip_0;
    // 0x80103608: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x8010360C: b           L_80103684
    // 0x80103610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103684;
    // 0x80103610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103614:
    // 0x80103614: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80103618: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8010361C: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    // 0x80103620: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80103624: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x80103628: bne         $at, $zero, L_80103680
    if (ctx->r1 != 0) {
        // 0x8010362C: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_80103680;
    }
    // 0x8010362C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80103630: addiu       $t8, $zero, 0x73
    ctx->r24 = ADD32(0, 0X73);
    // 0x80103634: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80103638: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8010363C: b           L_80103680
    // 0x80103640: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_80103680;
    // 0x80103640: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80103644:
    // 0x80103644: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80103648: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x8010364C: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80103650: bnel        $t9, $zero, L_80103684
    if (ctx->r25 != 0) {
        // 0x80103654: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80103684;
    }
    goto skip_1;
    // 0x80103654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80103658: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8010365C: b           L_80103680
    // 0x80103660: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_80103680;
    // 0x80103660: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80103664: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_80103668:
    // 0x80103668: addiu       $t4, $t3, -0x8
    ctx->r12 = ADD32(ctx->r11, -0X8);
    // 0x8010366C: bgez        $t4, L_80103680
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80103670: sw          $t4, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r12;
            goto L_80103680;
    }
    // 0x80103670: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80103674: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80103678: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8010367C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80103680:
    // 0x80103680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103684:
    // 0x80103684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103688: jr          $ra
    // 0x8010368C: nop

    return;
    // 0x8010368C: nop

;}
RECOMP_FUNC void func_80038EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038EDC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80038EE0: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x80038EE4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80038EE8: bne         $t6, $zero, L_80038EF8
    if (ctx->r14 != 0) {
        // 0x80038EEC: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_80038EF8;
    }
    // 0x80038EEC: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80038EF0: jr          $ra
    // 0x80038EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80038EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038EF8:
    // 0x80038EF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80038EFC: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80038F00: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_80038F04:
    // 0x80038F04: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x80038F08: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x80038F0C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80038F10: beql        $t8, $zero, L_80038F54
    if (ctx->r24 == 0) {
        // 0x80038F14: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80038F54;
    }
    goto skip_0;
    // 0x80038F14: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x80038F18: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80038F1C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80038F20: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80038F24: beql        $t3, $zero, L_80038F40
    if (ctx->r11 == 0) {
        // 0x80038F28: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_80038F40;
    }
    goto skip_1;
    // 0x80038F28: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x80038F2C: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x80038F30: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80038F34: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x80038F38: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80038F3C: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_80038F40:
    // 0x80038F40: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80038F44: beql        $at, $zero, L_80038F54
    if (ctx->r1 == 0) {
        // 0x80038F48: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80038F54;
    }
    goto skip_2;
    // 0x80038F48: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x80038F4C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80038F50: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80038F54:
    // 0x80038F54: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80038F58: beq         $t8, $zero, L_80038F98
    if (ctx->r24 == 0) {
        // 0x80038F5C: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_80038F98;
    }
    // 0x80038F5C: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x80038F60: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80038F64: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80038F68: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80038F6C: beql        $t3, $zero, L_80038F88
    if (ctx->r11 == 0) {
        // 0x80038F70: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_80038F88;
    }
    goto skip_3;
    // 0x80038F70: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x80038F74: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x80038F78: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80038F7C: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x80038F80: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80038F84: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_80038F88:
    // 0x80038F88: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80038F8C: beql        $at, $zero, L_80038F9C
    if (ctx->r1 == 0) {
        // 0x80038F90: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80038F9C;
    }
    goto skip_4;
    // 0x80038F90: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x80038F94: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80038F98:
    // 0x80038F98: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80038F9C:
    // 0x80038F9C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80038FA0: beq         $t8, $zero, L_80038FE0
    if (ctx->r24 == 0) {
        // 0x80038FA4: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_80038FE0;
    }
    // 0x80038FA4: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x80038FA8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80038FAC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80038FB0: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80038FB4: beql        $t3, $zero, L_80038FD0
    if (ctx->r11 == 0) {
        // 0x80038FB8: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_80038FD0;
    }
    goto skip_5;
    // 0x80038FB8: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x80038FBC: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x80038FC0: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80038FC4: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x80038FC8: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80038FCC: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_80038FD0:
    // 0x80038FD0: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80038FD4: beql        $at, $zero, L_80038FE4
    if (ctx->r1 == 0) {
        // 0x80038FD8: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_80038FE4;
    }
    goto skip_6;
    // 0x80038FD8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x80038FDC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80038FE0:
    // 0x80038FE0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_80038FE4:
    // 0x80038FE4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80038FE8: beql        $t8, $zero, L_80039028
    if (ctx->r24 == 0) {
        // 0x80038FEC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80039028;
    }
    goto skip_7;
    // 0x80038FEC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x80038FF0: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80038FF4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80038FF8: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x80038FFC: beql        $t3, $zero, L_80039014
    if (ctx->r11 == 0) {
        // 0x80039000: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_80039014;
    }
    goto skip_8;
    // 0x80039000: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x80039004: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x80039008: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x8003900C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x80039010: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_80039014:
    // 0x80039014: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80039018: beql        $at, $zero, L_80039028
    if (ctx->r1 == 0) {
        // 0x8003901C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80039028;
    }
    goto skip_9;
    // 0x8003901C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x80039020: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80039024: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80039028:
    // 0x80039028: bnel        $a2, $t2, L_80038F04
    if (ctx->r6 != ctx->r10) {
        // 0x8003902C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_80038F04;
    }
    goto skip_10;
    // 0x8003902C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x80039030: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80039034: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x80039038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003903C: jr          $ra
    // 0x80039040: nop

    return;
    // 0x80039040: nop

    // 0x80039044: nop

    // 0x80039048: nop

    // 0x8003904C: nop

;}
RECOMP_FUNC void func_8010126C_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010126C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80101270: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101274: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80101278: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x8010127C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80101280: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80101284: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010128C: sh          $zero, 0x30($v0)
    MEM_H(0X30, ctx->r2) = 0;
    // 0x80101290: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80101294: lh          $t9, 0x30($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X30);
    // 0x80101298: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8010129C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801012A0: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x801012A4: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x801012A8: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x801012AC: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x801012B0: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x801012B4: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x801012B8: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x801012BC: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x801012C0: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x801012C4: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x801012C8: sh          $t8, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r24;
    // 0x801012CC: sh          $zero, 0x32($v0)
    MEM_H(0X32, ctx->r2) = 0;
    // 0x801012D0: sh          $zero, 0x24($v0)
    MEM_H(0X24, ctx->r2) = 0;
    // 0x801012D4: sh          $zero, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = 0;
    // 0x801012D8: sh          $zero, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = 0;
    // 0x801012DC: sh          $zero, 0x26($v0)
    MEM_H(0X26, ctx->r2) = 0;
    // 0x801012E0: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x801012E4: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x801012E8: sh          $zero, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = 0;
    // 0x801012EC: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x801012F0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x801012F4: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x801012F8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801012FC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80101300: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x80101304: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80101308: jr          $ra
    // 0x8010130C: sh          $t9, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r25;
    return;
    // 0x8010130C: sh          $t9, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_80041898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041898: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x8004189C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800418A0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800418A4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800418A8: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x800418AC: nop

    // 0x800418B0: bc1fl       L_800418C4
    if (!c1cs) {
        // 0x800418B4: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800418C4;
    }
    goto skip_0;
    // 0x800418B4: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_0:
    // 0x800418B8: jr          $ra
    // 0x800418BC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800418BC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800418C0: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800418C4:
    // 0x800418C4: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800418C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800418CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800418D0: bc1fl       L_800418E4
    if (!c1cs) {
        // 0x800418D4: neg.d       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
            goto L_800418E4;
    }
    goto skip_1;
    // 0x800418D4: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
    skip_1:
    // 0x800418D8: b           L_800418E4
    // 0x800418DC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800418E4;
    // 0x800418DC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800418E0: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
L_800418E4:
    // 0x800418E4: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800418E8: nop

    // 0x800418EC: bc1fl       L_80041924
    if (!c1cs) {
        // 0x800418F0: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80041924;
    }
    goto skip_2;
    // 0x800418F0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_2:
    // 0x800418F4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800418F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800418FC: nop

L_80041900:
    // 0x80041900: mul.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x80041904: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80041908: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8004190C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80041910: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x80041914: nop

    // 0x80041918: bc1t        L_80041900
    if (c1cs) {
        // 0x8004191C: nop
    
            goto L_80041900;
    }
    // 0x8004191C: nop

    // 0x80041920: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_80041924:
    // 0x80041924: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80041928: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8004192C: nop

    // 0x80041930: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x80041934: nop

    // 0x80041938: bc1fl       L_80041960
    if (!c1cs) {
        // 0x8004193C: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_80041960;
    }
    goto skip_3;
    // 0x8004193C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x80041940: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
L_80041944:
    // 0x80041944: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80041948: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x8004194C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80041950: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80041954: bc1tl       L_80041944
    if (c1cs) {
        // 0x80041958: add.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
            goto L_80041944;
    }
    goto skip_4;
    // 0x80041958: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    skip_4:
    // 0x8004195C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_80041960:
    // 0x80041960: nop

    // 0x80041964: bc1fl       L_80041978
    if (!c1cs) {
        // 0x80041968: neg.d       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
            goto L_80041978;
    }
    goto skip_5;
    // 0x80041968: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
    skip_5:
    // 0x8004196C: b           L_80041978
    // 0x80041970: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
        goto L_80041978;
    // 0x80041970: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x80041974: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
L_80041978:
    // 0x80041978: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x8004197C: jr          $ra
    // 0x80041980: nop

    return;
    // 0x80041980: nop

;}
RECOMP_FUNC void func_80019A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019A98: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80019A9C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80019AA0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80019AA4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80019AA8: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80019AAC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80019AB0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80019AB4: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80019AB8: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80019ABC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80019AC0: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80019AC4: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80019AC8: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80019ACC: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80019AD0: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80019AD4: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80019AD8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80019ADC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80019AE0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80019AE4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80019AE8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80019AEC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80019AF0: addiu       $v0, $v0, -0x7F58
    ctx->r2 = ADD32(ctx->r2, -0X7F58);
    // 0x80019AF4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80019AF8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80019AFC:
    // 0x80019AFC: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80019B00: beql        $t7, $zero, L_80019B18
    if (ctx->r15 == 0) {
        // 0x80019B04: lui         $at, 0xC044
        ctx->r1 = S32(0XC044 << 16);
            goto L_80019B18;
    }
    goto skip_0;
    // 0x80019B04: lui         $at, 0xC044
    ctx->r1 = S32(0XC044 << 16);
    skip_0:
    // 0x80019B08: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80019B0C: bne         $s5, $v1, L_80019AFC
    if (ctx->r21 != ctx->r3) {
        // 0x80019B10: addiu       $v0, $v0, 0xD0
        ctx->r2 = ADD32(ctx->r2, 0XD0);
            goto L_80019AFC;
    }
    // 0x80019B10: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, 0XD0);
    // 0x80019B14: lui         $at, 0xC044
    ctx->r1 = S32(0XC044 << 16);
L_80019B18:
    // 0x80019B18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019B1C: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x80019B20: sh          $a0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r4;
    // 0x80019B24: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80019B28: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80019B2C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80019B30: ldc1        $f28, 0x15C0($at)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r1, 0X15C0);
    // 0x80019B34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019B38: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80019B3C: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80019B40: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x80019B44: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80019B48: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80019B4C: addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
    // 0x80019B50: addiu       $s0, $v0, 0x70
    ctx->r16 = ADD32(ctx->r2, 0X70);
    // 0x80019B54: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80019B58: addiu       $s2, $s2, -0x7C00
    ctx->r18 = ADD32(ctx->r18, -0X7C00);
    // 0x80019B5C: addiu       $s3, $s3, -0x7C10
    ctx->r19 = ADD32(ctx->r19, -0X7C10);
    // 0x80019B60: addiu       $s6, $s6, -0x4548
    ctx->r22 = ADD32(ctx->r22, -0X4548);
    // 0x80019B64: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
L_80019B68:
    // 0x80019B68: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80019B6C: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x80019B70: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80019B74: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80019B78: jal         0x800232F4
    // 0x80019B7C: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_0;
    // 0x80019B7C: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
    after_0:
    // 0x80019B80: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80019B84: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80019B88: addiu       $a3, $zero, 0xA00
    ctx->r7 = ADD32(0, 0XA00);
    // 0x80019B8C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80019B90: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x80019B94: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80019B98: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80019B9C: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80019BA0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80019BA4: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    // 0x80019BA8: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80019BAC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80019BB0: jal         0x8000EE60
    // 0x80019BB4: lwc1        $f14, 0x18($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X18);
    func_8000EE60(rdram, ctx);
        goto after_1;
    // 0x80019BB4: lwc1        $f14, 0x18($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X18);
    after_1:
    // 0x80019BB8: lhu         $t9, 0x18($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X18);
    // 0x80019BBC: cvt.d.s     $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f18.d = CVT_D_S(ctx->f22.fl);
    // 0x80019BC0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80019BC4: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80019BC8: beq         $t0, $zero, L_80019BE4
    if (ctx->r8 == 0) {
        // 0x80019BCC: add.d       $f4, $f18, $f28
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f28.d); 
    ctx->f4.d = ctx->f18.d + ctx->f28.d;
            goto L_80019BE4;
    }
    // 0x80019BCC: add.d       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f28.d); 
    ctx->f4.d = ctx->f18.d + ctx->f28.d;
    // 0x80019BD0: swc1        $f24, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f24.u32l;
    // 0x80019BD4: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x80019BD8: swc1        $f26, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f26.u32l;
    // 0x80019BDC: b           L_80019C50
    // 0x80019BE0: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
        goto L_80019C50;
    // 0x80019BE0: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
L_80019BE4:
    // 0x80019BE4: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80019BE8: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x80019BEC: sub.s       $f2, $f12, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x80019BF0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80019BF4: c.lt.d      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.d < ctx->f30.d;
    // 0x80019BF8: nop

    // 0x80019BFC: bc1tl       L_80019C24
    if (c1cs) {
        // 0x80019C00: swc1        $f24, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->f24.u32l;
            goto L_80019C24;
    }
    goto skip_1;
    // 0x80019C00: swc1        $f24, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f24.u32l;
    skip_1:
    // 0x80019C04: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80019C08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80019C0C: nop

    // 0x80019C10: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80019C14: nop

    // 0x80019C18: bc1fl       L_80019C38
    if (!c1cs) {
        // 0x80019C1C: swc1        $f12, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->f12.u32l;
            goto L_80019C38;
    }
    goto skip_2;
    // 0x80019C1C: swc1        $f12, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f12.u32l;
    skip_2:
    // 0x80019C20: swc1        $f24, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f24.u32l;
L_80019C24:
    // 0x80019C24: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x80019C28: swc1        $f26, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f26.u32l;
    // 0x80019C2C: b           L_80019C50
    // 0x80019C30: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
        goto L_80019C50;
    // 0x80019C30: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x80019C34: swc1        $f12, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f12.u32l;
L_80019C38:
    // 0x80019C38: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80019C3C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80019C40: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80019C44: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80019C48: lwc1        $f16, 0x14($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80019C4C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80019C50:
    // 0x80019C50: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
    // 0x80019C54: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80019C58: bne         $s4, $zero, L_80019B68
    if (ctx->r20 != 0) {
        // 0x80019C5C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80019B68;
    }
    // 0x80019C5C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80019C60: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80019C64: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80019C68: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80019C6C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80019C70: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80019C74: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80019C78: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80019C7C: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80019C80: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80019C84: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80019C88: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80019C8C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80019C90: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80019C94: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80019C98: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80019C9C: jr          $ra
    // 0x80019CA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80019CA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80031800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031800: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80031804: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80031808: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x8003180C: addiu       $t7, $t7, 0x2A38
    ctx->r15 = ADD32(ctx->r15, 0X2A38);
    // 0x80031810: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80031814: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80031818: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x8003181C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80031820: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80031824:
    // 0x80031824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003182C: addiu       $a1, $v1, 0x1A
    ctx->r5 = ADD32(ctx->r3, 0X1A);
    // 0x80031830: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_80031834:
    // 0x80031834: lb          $t8, 0x2($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X2);
    // 0x80031838: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003183C: bne         $a1, $t8, L_8003184C
    if (ctx->r5 != ctx->r24) {
        // 0x80031840: nop
    
            goto L_8003184C;
    }
    // 0x80031840: nop

    // 0x80031844: b           L_80031854
    // 0x80031848: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80031854;
    // 0x80031848: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8003184C:
    // 0x8003184C: bne         $v0, $t0, L_80031834
    if (ctx->r2 != ctx->r8) {
        // 0x80031850: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80031834;
    }
    // 0x80031850: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80031854:
    // 0x80031854: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80031858: bne         $at, $zero, L_80031870
    if (ctx->r1 != 0) {
        // 0x8003185C: nop
    
            goto L_80031870;
    }
    // 0x8003185C: nop

    // 0x80031860: beq         $a0, $zero, L_80031870
    if (ctx->r4 == 0) {
        // 0x80031864: nop
    
            goto L_80031870;
    }
    // 0x80031864: nop

    // 0x80031868: b           L_80031878
    // 0x8003186C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80031878;
    // 0x8003186C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80031870:
    // 0x80031870: beql        $a0, $zero, L_80031824
    if (ctx->r4 == 0) {
        // 0x80031874: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80031824;
    }
    goto skip_0;
    // 0x80031874: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80031878:
    // 0x80031878: bnel        $a0, $zero, L_80031888
    if (ctx->r4 != 0) {
        // 0x8003187C: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_80031888;
    }
    goto skip_1;
    // 0x8003187C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    skip_1:
    // 0x80031880: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80031884: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_80031888:
    // 0x80031888: jr          $ra
    // 0x8003188C: nop

    return;
    // 0x8003188C: nop

;}
RECOMP_FUNC void func_80041A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041A64: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80041A68: bne         $a0, $zero, L_80041A98
    if (ctx->r4 != 0) {
        // 0x80041A6C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80041A98;
    }
    // 0x80041A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041A70: c.le.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d <= ctx->f14.d;
    // 0x80041A74: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80041A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041A7C: bc1f        L_80041A90
    if (!c1cs) {
        // 0x80041A80: nop
    
            goto L_80041A90;
    }
    // 0x80041A80: nop

    // 0x80041A84: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x80041A88: b           L_80041C24
    // 0x80041A8C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_80041C24;
    // 0x80041A8C: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_80041A90:
    // 0x80041A90: b           L_80041C24
    // 0x80041A94: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
        goto L_80041C24;
    // 0x80041A94: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_80041A98:
    // 0x80041A98: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80041A9C: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x80041AA0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80041AA4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80041AA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80041AAC: c.lt.d      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.d < ctx->f22.d;
    // 0x80041AB0: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x80041AB4: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x80041AB8: addiu       $t7, $t7, 0xD80
    ctx->r15 = ADD32(ctx->r15, 0XD80);
    // 0x80041ABC: bc1f        L_80041AC8
    if (!c1cs) {
        // 0x80041AC0: or          $t6, $s2, $zero
        ctx->r14 = ctx->r18 | 0;
            goto L_80041AC8;
    }
    // 0x80041AC0: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x80041AC4: mov.d       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.d = ctx->f22.d;
L_80041AC8:
    // 0x80041AC8: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x80041ACC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80041AD0: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x80041AD4: bc1f        L_80041AE8
    if (!c1cs) {
        // 0x80041AD8: nop
    
            goto L_80041AE8;
    }
    // 0x80041AD8: nop

    // 0x80041ADC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80041AE0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80041AE4: nop

L_80041AE8:
    // 0x80041AE8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80041AEC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80041AF0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80041AF4: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80041AF8: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80041AFC: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80041B00: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80041B04: bne         $t7, $t9, L_80041AE8
    if (ctx->r15 != ctx->r25) {
        // 0x80041B08: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80041AE8;
    }
    // 0x80041B08: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x80041B0C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x80041B10: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x80041B14: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80041B18: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80041B1C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80041B20: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x80041B24: cvt.d.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.d = CVT_D_W(ctx->f6.u32l);
    // 0x80041B28: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80041B2C: div.d       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f22.d, ctx->f10.d);
    // 0x80041B30: div.d       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f16.d);
    // 0x80041B34: mul.d       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x80041B38: trunc.w.d   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80041B3C: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x80041B40: jal         0x80041898
    // 0x80041B44: nop

    func_80041898(rdram, ctx);
        goto after_0;
    // 0x80041B44: nop

    after_0:
    // 0x80041B48: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80041B4C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80041B50: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80041B54: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80041B58: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80041B5C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80041B60: mul.d       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x80041B64: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80041B68: ldc1        $f8, 0x2080($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X2080);
    // 0x80041B6C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80041B70: trunc.w.d   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80041B74: mov.d       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.d = ctx->f22.d;
    // 0x80041B78: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80041B7C: nop

    // 0x80041B80: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80041B84: addu        $t7, $s2, $t9
    ctx->r15 = ADD32(ctx->r18, ctx->r25);
    // 0x80041B88: ldc1        $f6, -0x40($t7)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r15, -0X40);
    // 0x80041B8C: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x80041B90: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80041B94: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80041B98: mul.d       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x80041B9C: nop

    // 0x80041BA0: mul.d       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x80041BA4: div.d       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f14.d);
    // 0x80041BA8: beq         $s0, $zero, L_80041BD0
    if (ctx->r16 == 0) {
        // 0x80041BAC: add.d       $f0, $f22, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
            goto L_80041BD0;
    }
    // 0x80041BAC: add.d       $f0, $f22, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
L_80041BB0:
    // 0x80041BB0: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x80041BB4: beq         $t8, $zero, L_80041BC4
    if (ctx->r24 == 0) {
        // 0x80041BB8: sra         $t9, $s0, 1
        ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
            goto L_80041BC4;
    }
    // 0x80041BB8: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80041BBC: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x80041BC0: nop

L_80041BC4:
    // 0x80041BC4: mul.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x80041BC8: bne         $t9, $zero, L_80041BB0
    if (ctx->r25 != 0) {
        // 0x80041BCC: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_80041BB0;
    }
    // 0x80041BCC: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_80041BD0:
    // 0x80041BD0: mul.d       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80041BD4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80041BD8: mul.d       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x80041BDC: nop

    // 0x80041BE0: mul.d       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f12.d);
    // 0x80041BE4: trunc.w.d   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80041BE8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80041BEC: nop

    // 0x80041BF0: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80041BF4: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80041BF8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80041BFC: nop

    // 0x80041C00: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041C04: ldc1        $f4, 0x2088($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X2088);
    // 0x80041C08: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80041C0C: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x80041C10: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x80041C14: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x80041C18: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80041C1C: nop

    // 0x80041C20: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_80041C24:
    // 0x80041C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041C28: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x80041C2C: jr          $ra
    // 0x80041C30: nop

    return;
    // 0x80041C30: nop

;}
RECOMP_FUNC void func_8001A620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A620: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8001A624: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x8001A628: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8001A62C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001A630: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x8001A634: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001A638: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8001A63C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8001A640: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8001A644: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8001A648: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8001A64C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8001A650: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001A654: sw          $zero, -0x3A20($at)
    MEM_W(-0X3A20, ctx->r1) = 0;
    // 0x8001A658: lhu         $t6, 0x8($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X8);
    // 0x8001A65C: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x8001A660: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001A664: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8001A668: beq         $t7, $zero, L_8001A6F4
    if (ctx->r15 == 0) {
        // 0x8001A66C: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_8001A6F4;
    }
    // 0x8001A66C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001A670: lw          $a1, 0x28($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X28);
    // 0x8001A674: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    // 0x8001A678: jal         0x80023A08
    // 0x8001A67C: lw          $a3, 0x30($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X30);
    func_80023A08(rdram, ctx);
        goto after_0;
    // 0x8001A67C: lw          $a3, 0x30($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X30);
    after_0:
    // 0x8001A680: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001A684: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001A688: ldc1        $f0, 0x15C8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X15C8);
    // 0x8001A68C: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x8001A690: lwc1        $f6, 0x10($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8001A694: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001A698: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8001A69C: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8001A6A0: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x8001A6A4: lwc1        $f10, 0x1C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8001A6A8: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    // 0x8001A6AC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001A6B0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001A6B4: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x8001A6B8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001A6BC: lwc1        $f18, 0x24($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8001A6C0: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8001A6C4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8001A6C8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8001A6CC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8001A6D0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8001A6D4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8001A6D8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8001A6DC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001A6E0: jal         0x80023DF4
    // 0x8001A6E4: nop

    func_80023DF4(rdram, ctx);
        goto after_1;
    // 0x8001A6E4: nop

    after_1:
    // 0x8001A6E8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001A6EC: b           L_8001A74C
    // 0x8001A6F0: ldc1        $f0, 0x15D0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X15D0);
        goto L_8001A74C;
    // 0x8001A6F0: ldc1        $f0, 0x15D0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X15D0);
L_8001A6F4:
    // 0x8001A6F4: lwc1        $f10, 0x15D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15D8);
    // 0x8001A6F8: lw          $a2, 0x18($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X18);
    // 0x8001A6FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001A700: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8001A704: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001A708: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x8001A70C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8001A710: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8001A714: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8001A718: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001A71C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001A720: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8001A724: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8001A728: jal         0x80023360
    // 0x8001A72C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_80023360(rdram, ctx);
        goto after_2;
    // 0x8001A72C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8001A730: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001A734: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x8001A738: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x8001A73C: jal         0x80023DF4
    // 0x8001A740: lw          $a3, 0x24($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X24);
    func_80023DF4(rdram, ctx);
        goto after_3;
    // 0x8001A740: lw          $a3, 0x24($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X24);
    after_3:
    // 0x8001A744: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001A748: ldc1        $f0, 0x15E0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, 0X15E0);
L_8001A74C:
    // 0x8001A74C: lwc1        $f6, 0x1C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8001A750: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001A754: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x8001A758: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001A75C: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8001A760: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8001A764: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8001A768: lwc1        $f18, 0x20($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X20);
    // 0x8001A76C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8001A770: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8001A774: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8001A778: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8001A77C: lwc1        $f10, 0x24($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X24);
    // 0x8001A780: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001A784: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x8001A788: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001A78C: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x8001A790: lh          $v0, 0x38($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X38);
    // 0x8001A794: lw          $s4, 0x3C($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X3C);
    // 0x8001A798: lw          $s5, 0x34($s2)
    ctx->r21 = MEM_W(ctx->r18, 0X34);
    // 0x8001A79C: beq         $v0, $zero, L_8001A808
    if (ctx->r2 == 0) {
        // 0x8001A7A0: or          $s0, $s4, $zero
        ctx->r16 = ctx->r20 | 0;
            goto L_8001A808;
    }
    // 0x8001A7A0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_8001A7A4:
    // 0x8001A7A4: lb          $t8, 0x14($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X14);
    // 0x8001A7A8: bnel        $t8, $zero, L_8001A7FC
    if (ctx->r24 != 0) {
        // 0x8001A7AC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001A7FC;
    }
    goto skip_0;
    // 0x8001A7AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8001A7B0: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x8001A7B4: addiu       $t1, $s2, 0x38
    ctx->r9 = ADD32(ctx->r18, 0X38);
    // 0x8001A7B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001A7BC: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x8001A7C0: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x8001A7C4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8001A7C8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001A7CC: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x8001A7D0: sw          $s7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r23;
    // 0x8001A7D4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001A7D8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8001A7DC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8001A7E0: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8001A7E4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001A7E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001A7EC: jal         0x8001DC78
    // 0x8001A7F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    func_8001DC78(rdram, ctx);
        goto after_4;
    // 0x8001A7F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_4:
    // 0x8001A7F4: lh          $v0, 0x38($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X38);
    // 0x8001A7F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001A7FC:
    // 0x8001A7FC: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8001A800: bne         $at, $zero, L_8001A7A4
    if (ctx->r1 != 0) {
        // 0x8001A804: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_8001A7A4;
    }
    // 0x8001A804: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_8001A808:
    // 0x8001A808: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8001A80C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8001A810: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8001A814: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A818: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8001A81C: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8001A820: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8001A824: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x8001A828: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8001A82C: jr          $ra
    // 0x8001A830: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8001A830: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80004448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004448: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000444C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80004450: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80004454: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80004458: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000445C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80004460: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004464: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80004468: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x8000446C: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80004470: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x80004474: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80004478: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000447C: bne         $t8, $zero, L_800045DC
    if (ctx->r24 != 0) {
        // 0x80004480: sh          $t7, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r15;
            goto L_800045DC;
    }
    // 0x80004480: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80004484: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x80004488: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000448C: jal         0x80006A74
    // 0x80004490: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80006A74(rdram, ctx);
        goto after_0;
    // 0x80004490: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_0:
    // 0x80004494: beql        $v0, $zero, L_80004584
    if (ctx->r2 == 0) {
        // 0x80004498: lhu         $t4, 0x2($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X2);
            goto L_80004584;
    }
    goto skip_0;
    // 0x80004498: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    skip_0:
    // 0x8000449C: jal         0x80006B1C
    // 0x800044A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80006B1C(rdram, ctx);
        goto after_1;
    // 0x800044A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800044A4: lhu         $a2, 0x11E($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X11E);
    // 0x800044A8: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    // 0x800044AC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800044B0: sra         $t0, $a2, 8
    ctx->r8 = S32(SIGNED(ctx->r6) >> 8);
    // 0x800044B4: andi        $a2, $t0, 0xF
    ctx->r6 = ctx->r8 & 0XF;
    // 0x800044B8: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x800044BC: ori         $a3, $zero, 0x8004
    ctx->r7 = 0 | 0X8004;
    // 0x800044C0: jal         0x8000ACC0
    // 0x800044C4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_8000ACC0(rdram, ctx);
        goto after_2;
    // 0x800044C4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_2:
    // 0x800044C8: beql        $v0, $zero, L_80004570
    if (ctx->r2 == 0) {
        // 0x800044CC: lw          $v0, 0x10($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X10);
            goto L_80004570;
    }
    goto skip_1;
    // 0x800044CC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x800044D0: lw          $v1, 0x64($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X64);
    // 0x800044D4: lhu         $t2, 0x8($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X8);
    // 0x800044D8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800044DC: sh          $t3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r11;
    // 0x800044E0: lw          $v1, 0x64($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X64);
    // 0x800044E4: lhu         $a0, 0xA($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XA);
    // 0x800044E8: lhu         $t4, 0x8($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X8);
    // 0x800044EC: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800044F0: beql        $at, $zero, L_80004500
    if (ctx->r1 == 0) {
        // 0x800044F4: lhu         $t5, 0x80($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X80);
            goto L_80004500;
    }
    goto skip_2;
    // 0x800044F4: lhu         $t5, 0x80($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X80);
    skip_2:
    // 0x800044F8: sh          $a0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r4;
    // 0x800044FC: lhu         $t5, 0x80($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X80);
L_80004500:
    // 0x80004500: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80004504: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80004508: beql        $t6, $zero, L_80004570
    if (ctx->r14 == 0) {
        // 0x8000450C: lw          $v0, 0x10($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X10);
            goto L_80004570;
    }
    goto skip_3;
    // 0x8000450C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    skip_3:
    // 0x80004510: lw          $v1, 0x64($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X64);
    // 0x80004514: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80004518: sra         $t7, $a0, 2
    ctx->r15 = S32(SIGNED(ctx->r4) >> 2);
    // 0x8000451C: lhu         $t9, 0x4($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X4);
    // 0x80004520: addiu       $a0, $t7, 0x1
    ctx->r4 = ADD32(ctx->r15, 0X1);
    // 0x80004524: andi        $a2, $a0, 0xFFFF
    ctx->r6 = ctx->r4 & 0XFFFF;
    // 0x80004528: addu        $t0, $t9, $a2
    ctx->r8 = ADD32(ctx->r25, ctx->r6);
    // 0x8000452C: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    // 0x80004530: lw          $v1, 0x64($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X64);
    // 0x80004534: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004538: lhu         $a1, 0x6($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X6);
    // 0x8000453C: lhu         $t1, 0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X4);
    // 0x80004540: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80004544: beq         $at, $zero, L_80004550
    if (ctx->r1 == 0) {
        // 0x80004548: nop
    
            goto L_80004550;
    }
    // 0x80004548: nop

    // 0x8000454C: sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
L_80004550:
    // 0x80004550: jal         0x80018DF4
    // 0x80004554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80018DF4(rdram, ctx);
        goto after_3;
    // 0x80004554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80004558: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000455C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80004560: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80004564: jal         0x8001FCF8
    // 0x80004568: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_8001FCF8(rdram, ctx);
        goto after_4;
    // 0x80004568: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_4:
    // 0x8000456C: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_80004570:
    // 0x80004570: lhu         $t2, 0x28($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X28);
    // 0x80004574: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80004578: b           L_800045AC
    // 0x8000457C: sh          $t3, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r11;
        goto L_800045AC;
    // 0x8000457C: sh          $t3, 0x28($v0)
    MEM_H(0X28, ctx->r2) = ctx->r11;
    // 0x80004580: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
L_80004584:
    // 0x80004584: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80004588: addiu       $t7, $t7, -0x3668
    ctx->r15 = ADD32(ctx->r15, -0X3668);
    // 0x8000458C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80004590: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80004594: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80004598: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8000459C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800045A0: addiu       $t6, $t5, -0x104
    ctx->r14 = ADD32(ctx->r13, -0X104);
    // 0x800045A4: jal         0x8000B110
    // 0x800045A8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    func_8000B110(rdram, ctx);
        goto after_5;
    // 0x800045A8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_5:
L_800045AC:
    // 0x800045AC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800045B0: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x800045B4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800045B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800045BC: lh          $t0, 0x7A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X7A);
    // 0x800045C0: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800045C4: addiu       $t1, $t0, -0x14
    ctx->r9 = ADD32(ctx->r8, -0X14);
    // 0x800045C8: jal         0x800073CC
    // 0x800045CC: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    func_800073CC(rdram, ctx);
        goto after_6;
    // 0x800045CC: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    after_6:
    // 0x800045D0: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800045D4: jal         0x8001D358
    // 0x800045D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001D358(rdram, ctx);
        goto after_7;
    // 0x800045D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
L_800045DC:
    // 0x800045DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800045E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800045E4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800045E8: jr          $ra
    // 0x800045EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800045EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044AF0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80044AF4: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x80044AF8: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80044AFC: blez        $a1, L_80044B40
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80044B00: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_80044B40;
    }
    // 0x80044B00: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_80044B04:
    // 0x80044B04: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80044B08: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x80044B0C: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x80044B10: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80044B14: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80044B18: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80044B1C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80044B20: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x80044B24: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80044B28: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80044B2C: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x80044B30: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80044B34: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x80044B38: bne         $at, $zero, L_80044B04
    if (ctx->r1 != 0) {
        // 0x80044B3C: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_80044B04;
    }
    // 0x80044B3C: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_80044B40:
    // 0x80044B40: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x80044B44: jr          $ra
    // 0x80044B48: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80044B48: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80038630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038630: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80038634: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80038638: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003863C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80038640: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80038644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038648: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003864C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x80038650: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80038654: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80038658: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x8003865C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_80038660:
    // 0x80038660: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x80038664: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80038668: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8003866C: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x80038670: lw          $t1, 0x4C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4C);
    // 0x80038674: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80038678: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8003867C: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x80038680: lbu         $t2, 0x8C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8C);
    // 0x80038684: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80038688: sb          $t2, 0x96($a3)
    MEM_B(0X96, ctx->r7) = ctx->r10;
    // 0x8003868C: lbu         $t3, 0x9A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9A);
    // 0x80038690: sb          $t3, 0xA6($a3)
    MEM_B(0XA6, ctx->r7) = ctx->r11;
    // 0x80038694: lw          $t4, 0xA4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA4);
    // 0x80038698: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x8003869C: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800386A0: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x800386A4: lw          $t6, 0x48($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X48);
    // 0x800386A8: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
    // 0x800386AC: lbu         $t7, 0x8B($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8B);
    // 0x800386B0: sb          $t7, 0x97($a3)
    MEM_B(0X97, ctx->r7) = ctx->r15;
    // 0x800386B4: lbu         $t8, 0x9B($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9B);
    // 0x800386B8: sb          $t8, 0xA7($a3)
    MEM_B(0XA7, ctx->r7) = ctx->r24;
    // 0x800386BC: lw          $t9, 0xA8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA8);
    // 0x800386C0: bne         $v0, $a0, L_80038660
    if (ctx->r2 != ctx->r4) {
        // 0x800386C4: sw          $t9, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->r25;
            goto L_80038660;
    }
    // 0x800386C4: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x800386C8: jr          $ra
    // 0x800386CC: nop

    return;
    // 0x800386CC: nop

;}
RECOMP_FUNC void func_80048B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048B88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80048B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048B90: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x80048B94: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x80048B98: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80048B9C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x80048BA0: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x80048BA4: lui         $t2, 0xB00
    ctx->r10 = S32(0XB00 << 16);
    // 0x80048BA8: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x80048BAC: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x80048BB0: ori         $t2, $t2, 0x20
    ctx->r10 = ctx->r10 | 0X20;
    // 0x80048BB4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80048BB8: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x80048BBC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80048BC0: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x80048BC4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80048BC8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80048BCC: jal         0x80034DD0
    // 0x80048BD0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80048BD0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x80048BD4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80048BD8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80048BDC: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x80048BE0: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x80048BE4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80048BE8: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x80048BEC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80048BF0: lw          $t4, 0x2C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X2C);
    // 0x80048BF4: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x80048BF8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80048BFC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80048C00: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80048C04: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80048C08: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x80048C0C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80048C10: lw          $a0, 0x28($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X28);
    // 0x80048C14: jal         0x80034DD0
    // 0x80048C18: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80048C18: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80048C1C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80048C20: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80048C24: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80048C28: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x80048C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048C30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80048C34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80048C38: jr          $ra
    // 0x80048C3C: nop

    return;
    // 0x80048C3C: nop

;}
RECOMP_FUNC void func_80101558_ovl_intro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101558: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8010155C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80101560: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80101564: addiu       $t7, $t7, 0x6250
    ctx->r15 = ADD32(ctx->r15, 0X6250);
    // 0x80101568: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8010156C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80101570: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80101574: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80101578: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8010157C: sll         $t9, $t8, 0
    ctx->r25 = S32(ctx->r24 << 0);
    // 0x80101580: bltz        $t9, L_80101590
    if (SIGNED(ctx->r25) < 0) {
        // 0x80101584: andi        $a2, $a3, 0x100
        ctx->r6 = ctx->r7 & 0X100;
            goto L_80101590;
    }
    // 0x80101584: andi        $a2, $a3, 0x100
    ctx->r6 = ctx->r7 & 0X100;
    // 0x80101588: jr          $ra
    // 0x8010158C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x8010158C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80101590:
    // 0x80101590: lhu         $t0, 0x4C($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X4C);
    // 0x80101594: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x80101598: lh          $a1, 0xA($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XA);
    // 0x8010159C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801015A0: beq         $a2, $zero, L_8010160C
    if (ctx->r6 == 0) {
        // 0x801015A4: sh          $t1, 0x4C($v1)
        MEM_H(0X4C, ctx->r3) = ctx->r9;
            goto L_8010160C;
    }
    // 0x801015A4: sh          $t1, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r9;
    // 0x801015A8: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x801015AC: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801015B0: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801015B4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x801015B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801015BC: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x801015C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801015C4: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801015C8: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801015CC: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x801015D0: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x801015D4: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x801015D8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801015DC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x801015E0: nop

    // 0x801015E4: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x801015E8: beq         $at, $zero, L_801015F8
    if (ctx->r1 == 0) {
        // 0x801015EC: slt         $at, $t3, $a3
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_801015F8;
    }
    // 0x801015EC: slt         $at, $t3, $a3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801015F0: bnel        $at, $zero, L_80101600
    if (ctx->r1 != 0) {
        // 0x801015F4: lh          $t4, 0x2E($v1)
        ctx->r12 = MEM_H(ctx->r3, 0X2E);
            goto L_80101600;
    }
    goto skip_0;
    // 0x801015F4: lh          $t4, 0x2E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2E);
    skip_0:
L_801015F8:
    // 0x801015F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801015FC: lh          $t4, 0x2E($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2E);
L_80101600:
    // 0x80101600: sw          $v0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r2;
    // 0x80101604: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x80101608: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8010160C:
    // 0x8010160C: bnel        $a2, $zero, L_80101680
    if (ctx->r6 != 0) {
        // 0x80101610: lhu         $t2, 0x4C($v1)
        ctx->r10 = MEM_HU(ctx->r3, 0X4C);
            goto L_80101680;
    }
    goto skip_1;
    // 0x80101610: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
    skip_1:
    // 0x80101614: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80101618: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x8010161C: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80101620: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80101624: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80101628: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010162C: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80101630: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80101634: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
    // 0x80101638: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8010163C: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x80101640: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80101644: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80101648: nop

    // 0x8010164C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80101650: beql        $at, $zero, L_8010166C
    if (ctx->r1 == 0) {
        // 0x80101654: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8010166C;
    }
    goto skip_2;
    // 0x80101654: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_2:
    // 0x80101658: lhu         $t8, 0x4C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X4C);
    // 0x8010165C: slt         $at, $t8, $a3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80101660: bnel        $at, $zero, L_80101670
    if (ctx->r1 != 0) {
        // 0x80101664: lh          $t9, 0x30($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X30);
            goto L_80101670;
    }
    goto skip_3;
    // 0x80101664: lh          $t9, 0x30($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X30);
    skip_3:
    // 0x80101668: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8010166C:
    // 0x8010166C: lh          $t9, 0x30($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X30);
L_80101670:
    // 0x80101670: sw          $v0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r2;
    // 0x80101674: subu        $t0, $t9, $v0
    ctx->r8 = SUB32(ctx->r25, ctx->r2);
    // 0x80101678: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8010167C: lhu         $t2, 0x4C($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X4C);
L_80101680:
    // 0x80101680: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80101684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80101688: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8010168C: bne         $at, $zero, L_801016B4
    if (ctx->r1 != 0) {
        // 0x80101690: nop
    
            goto L_801016B4;
    }
    // 0x80101690: nop

    // 0x80101694: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101698: sh          $zero, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = 0;
    // 0x8010169C: sh          $zero, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = 0;
    // 0x801016A0: sh          $zero, 0x30($v1)
    MEM_H(0X30, ctx->r3) = 0;
    // 0x801016A4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801016A8: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x801016AC: jr          $ra
    // 0x801016B0: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x801016B0: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
L_801016B4:
    // 0x801016B4: jr          $ra
    // 0x801016B8: nop

    return;
    // 0x801016B8: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035300: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80035304: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80035308: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003530C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80035310: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80035314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035318: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8003531C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80035320: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80035324:
    // 0x80035324: bnel        $v0, $zero, L_80035338
    if (ctx->r2 != 0) {
        // 0x80035328: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80035338;
    }
    goto skip_0;
    // 0x80035328: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x8003532C: b           L_80035338
    // 0x80035330: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_80035338;
    // 0x80035330: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80035334: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80035338:
    // 0x80035338: bnel        $v0, $a0, L_8003534C
    if (ctx->r2 != ctx->r4) {
        // 0x8003533C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_8003534C;
    }
    goto skip_1;
    // 0x8003533C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x80035340: b           L_8003534C
    // 0x80035344: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_8003534C;
    // 0x80035344: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80035348: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_8003534C:
    // 0x8003534C: bnel        $v0, $a1, L_80035360
    if (ctx->r2 != ctx->r5) {
        // 0x80035350: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_80035360;
    }
    goto skip_2;
    // 0x80035350: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x80035354: b           L_80035360
    // 0x80035358: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_80035360;
    // 0x80035358: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8003535C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_80035360:
    // 0x80035360: bnel        $v0, $a2, L_80035374
    if (ctx->r2 != ctx->r6) {
        // 0x80035364: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_80035374;
    }
    goto skip_3;
    // 0x80035364: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x80035368: b           L_80035374
    // 0x8003536C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_80035374;
    // 0x8003536C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80035370: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_80035374:
    // 0x80035374: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80035378: bne         $v0, $a3, L_80035324
    if (ctx->r2 != ctx->r7) {
        // 0x8003537C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80035324;
    }
    // 0x8003537C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80035380: jr          $ra
    // 0x80035384: nop

    return;
    // 0x80035384: nop

;}
RECOMP_FUNC void func_80016D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016D98: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80016D9C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80016DA0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80016DA4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80016DA8: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80016DAC: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80016DB0: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80016DB4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80016DB8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80016DBC: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80016DC0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80016DC4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80016DC8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80016DCC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80016DD0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80016DD4: lw          $s3, 0x24($s5)
    ctx->r19 = MEM_W(ctx->r21, 0X24);
    // 0x80016DD8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80016DDC: addiu       $t8, $t8, -0x4534
    ctx->r24 = ADD32(ctx->r24, -0X4534);
    // 0x80016DE0: lhu         $t6, 0x5E($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X5E);
    // 0x80016DE4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016DE8: beql        $t7, $zero, L_80016DFC
    if (ctx->r15 == 0) {
        // 0x80016DEC: lw          $t9, 0x2C($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X2C);
            goto L_80016DFC;
    }
    goto skip_0;
    // 0x80016DEC: lw          $t9, 0x2C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X2C);
    skip_0:
    // 0x80016DF0: b           L_80016F4C
    // 0x80016DF4: sw          $t8, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r24;
        goto L_80016F4C;
    // 0x80016DF4: sw          $t8, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r24;
    // 0x80016DF8: lw          $t9, 0x2C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X2C);
L_80016DFC:
    // 0x80016DFC: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x80016E00: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80016E04: beql        $t1, $zero, L_80016E50
    if (ctx->r9 == 0) {
        // 0x80016E08: mtc1        $zero, $f30
        ctx->f30.u32l = 0;
            goto L_80016E50;
    }
    goto skip_1;
    // 0x80016E08: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    skip_1:
    // 0x80016E0C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80016E10: lwc1        $f12, 0x18($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X18);
    // 0x80016E14: c.eq.s      $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f30.fl == ctx->f12.fl;
    // 0x80016E18: nop

    // 0x80016E1C: bc1f        L_80016E38
    if (!c1cs) {
        // 0x80016E20: nop
    
            goto L_80016E38;
    }
    // 0x80016E20: nop

    // 0x80016E24: lwc1        $f4, 0x20($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X20);
    // 0x80016E28: c.eq.s      $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f30.fl == ctx->f4.fl;
    // 0x80016E2C: nop

    // 0x80016E30: bc1tl       L_80016E50
    if (c1cs) {
        // 0x80016E34: mtc1        $zero, $f30
        ctx->f30.u32l = 0;
            goto L_80016E50;
    }
    goto skip_2;
    // 0x80016E34: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    skip_2:
L_80016E38:
    // 0x80016E38: jal         0x80023210
    // 0x80016E3C: lwc1        $f14, 0x20($s5)
    ctx->f14.u32l = MEM_W(ctx->r21, 0X20);
    func_80023210(rdram, ctx);
        goto after_0;
    // 0x80016E3C: lwc1        $f14, 0x20($s5)
    ctx->f14.u32l = MEM_W(ctx->r21, 0X20);
    after_0:
    // 0x80016E40: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x80016E44: b           L_80016E54
    // 0x80016E48: lw          $s3, 0x24($s5)
    ctx->r19 = MEM_W(ctx->r21, 0X24);
        goto L_80016E54;
    // 0x80016E48: lw          $s3, 0x24($s5)
    ctx->r19 = MEM_W(ctx->r21, 0X24);
    // 0x80016E4C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
L_80016E50:
    // 0x80016E50: lwc1        $f28, 0x10($s3)
    ctx->f28.u32l = MEM_W(ctx->r19, 0X10);
L_80016E54:
    // 0x80016E54: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80016E58: lw          $s2, -0x3670($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X3670);
    // 0x80016E5C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016E60: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80016E64: lwc1        $f26, 0x14B0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X14B0);
    // 0x80016E68: beq         $s2, $zero, L_80016F4C
    if (ctx->r18 == 0) {
        // 0x80016E6C: addiu       $s1, $s1, -0x3668
        ctx->r17 = ADD32(ctx->r17, -0X3668);
            goto L_80016F4C;
    }
    // 0x80016E6C: addiu       $s1, $s1, -0x3668
    ctx->r17 = ADD32(ctx->r17, -0X3668);
    // 0x80016E70: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016E74: ldc1        $f24, 0x14B8($at)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r1, 0X14B8);
    // 0x80016E78: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016E7C: ldc1        $f22, 0x14C0($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, 0X14C0);
    // 0x80016E80: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80016E84: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80016E88: addiu       $s0, $s0, 0x71D0
    ctx->r16 = ADD32(ctx->r16, 0X71D0);
    // 0x80016E8C: ldc1        $f20, 0x14C8($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, 0X14C8);
    // 0x80016E90: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80016E94:
    // 0x80016E94: lh          $t2, 0x74($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X74);
    // 0x80016E98: beq         $s4, $t2, L_80016F44
    if (ctx->r20 == ctx->r10) {
        // 0x80016E9C: nop
    
            goto L_80016F44;
    }
    // 0x80016E9C: nop

    // 0x80016EA0: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80016EA4: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80016EA8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x80016EAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80016EB0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80016EB4: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80016EB8: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80016EBC: lwc1        $f16, 0x2C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80016EC0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80016EC4: jal         0x800232F4
    // 0x80016EC8: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    rotateCoordinatesByAngle(rdram, ctx);
        goto after_1;
    // 0x80016EC8: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80016ECC: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80016ED0: jal         0x80023210
    // 0x80016ED4: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    func_80023210(rdram, ctx);
        goto after_2;
    // 0x80016ED4: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x80016ED8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80016EDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80016EE0: c.lt.d      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.d < ctx->f2.d;
    // 0x80016EE4: addiu       $t3, $s1, 0x24
    ctx->r11 = ADD32(ctx->r17, 0X24);
    // 0x80016EE8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80016EEC: bc1fl       L_80016F04
    if (!c1cs) {
        // 0x80016EF0: c.lt.d      $f2, $f24
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.d < ctx->f24.d;
            goto L_80016F04;
    }
    goto skip_3;
    // 0x80016EF0: c.lt.d      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.d < ctx->f24.d;
    skip_3:
    // 0x80016EF4: sub.d       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = ctx->f2.d - ctx->f20.d;
    // 0x80016EF8: b           L_80016F18
    // 0x80016EFC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
        goto L_80016F18;
    // 0x80016EFC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80016F00: c.lt.d      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.d < ctx->f24.d;
L_80016F04:
    // 0x80016F04: nop

    // 0x80016F08: bc1fl       L_80016F1C
    if (!c1cs) {
        // 0x80016F0C: c.lt.s      $f12, $f30
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f12.fl < ctx->f30.fl;
            goto L_80016F1C;
    }
    goto skip_4;
    // 0x80016F0C: c.lt.s      $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f12.fl < ctx->f30.fl;
    skip_4:
    // 0x80016F10: add.d       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = ctx->f2.d + ctx->f20.d;
    // 0x80016F14: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
L_80016F18:
    // 0x80016F18: c.lt.s      $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f12.fl < ctx->f30.fl;
L_80016F1C:
    // 0x80016F1C: nop

    // 0x80016F20: bc1fl       L_80016F30
    if (!c1cs) {
        // 0x80016F24: c.lt.s      $f12, $f26
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
            goto L_80016F30;
    }
    goto skip_5;
    // 0x80016F24: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
    skip_5:
    // 0x80016F28: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80016F2C: c.lt.s      $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f12.fl < ctx->f26.fl;
L_80016F30:
    // 0x80016F30: nop

    // 0x80016F34: bc1f        L_80016F44
    if (!c1cs) {
        // 0x80016F38: nop
    
            goto L_80016F44;
    }
    // 0x80016F38: nop

    // 0x80016F3C: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x80016F40: sw          $t3, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r11;
L_80016F44:
    // 0x80016F44: bne         $s2, $zero, L_80016E94
    if (ctx->r18 != 0) {
        // 0x80016F48: addiu       $s1, $s1, 0x128
        ctx->r17 = ADD32(ctx->r17, 0X128);
            goto L_80016E94;
    }
    // 0x80016F48: addiu       $s1, $s1, 0x128
    ctx->r17 = ADD32(ctx->r17, 0X128);
L_80016F4C:
    // 0x80016F4C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80016F50: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80016F54: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80016F58: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80016F5C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80016F60: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80016F64: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80016F68: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80016F6C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80016F70: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80016F74: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80016F78: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80016F7C: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80016F80: jr          $ra
    // 0x80016F84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80016F84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80004AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004AB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004ABC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80004AC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80004AC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80004AC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80004ACC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80004AD0: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x80004AD4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80004AD8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80004ADC: bne         $t8, $zero, L_80004B4C
    if (ctx->r24 != 0) {
        // 0x80004AE0: sh          $t7, 0x4($s0)
        MEM_H(0X4, ctx->r16) = ctx->r15;
            goto L_80004B4C;
    }
    // 0x80004AE0: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80004AE4: lbu         $a0, 0x118($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X118);
    // 0x80004AE8: jal         0x800213D8
    // 0x80004AEC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800213D8(rdram, ctx);
        goto after_0;
    // 0x80004AEC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80004AF0: lbu         $t9, 0x118($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X118);
    // 0x80004AF4: lui         $t1, 0x803B
    ctx->r9 = S32(0X803B << 16);
    // 0x80004AF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80004AFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80004B00: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80004B04: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80004B08: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80004B0C: lhu         $t1, -0x6E0E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X6E0E);
    // 0x80004B10: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80004B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004B18: bne         $t1, $at, L_80004B3C
    if (ctx->r9 != ctx->r1) {
        // 0x80004B1C: nop
    
            goto L_80004B3C;
    }
    // 0x80004B1C: nop

    // 0x80004B20: jal         0x800073CC
    // 0x80004B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800073CC(rdram, ctx);
        goto after_1;
    // 0x80004B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80004B28: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80004B2C: jal         0x8001D358
    // 0x80004B30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8001D358(rdram, ctx);
        goto after_2;
    // 0x80004B30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80004B34: b           L_80004BC0
    // 0x80004B38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80004BC0;
    // 0x80004B38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80004B3C:
    // 0x80004B3C: jal         0x800073CC
    // 0x80004B40: sh          $t2, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r10;
    func_800073CC(rdram, ctx);
        goto after_3;
    // 0x80004B40: sh          $t2, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r10;
    after_3:
    // 0x80004B44: b           L_80004BC0
    // 0x80004B48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80004BC0;
    // 0x80004B48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80004B4C:
    // 0x80004B4C: lhu         $t3, 0x120($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X120);
    // 0x80004B50: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80004B54: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80004B58: bne         $t5, $zero, L_80004BBC
    if (ctx->r13 != 0) {
        // 0x80004B5C: sh          $t4, 0x120($s0)
        MEM_H(0X120, ctx->r16) = ctx->r12;
            goto L_80004BBC;
    }
    // 0x80004B5C: sh          $t4, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r12;
    // 0x80004B60: jal         0x80015B50
    // 0x80004B64: nop

    func_80015B50(rdram, ctx);
        goto after_4;
    // 0x80004B64: nop

    after_4:
    // 0x80004B68: beq         $v0, $zero, L_80004B7C
    if (ctx->r2 == 0) {
        // 0x80004B6C: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80004B7C;
    }
    // 0x80004B6C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80004B70: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80004B74: b           L_80004BBC
    // 0x80004B78: sh          $t6, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r14;
        goto L_80004BBC;
    // 0x80004B78: sh          $t6, 0x120($s0)
    MEM_H(0X120, ctx->r16) = ctx->r14;
L_80004B7C:
    // 0x80004B7C: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80004B80: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80004B84: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x80004B88: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80004B8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80004B90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80004B94: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80004B98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80004B9C: lw          $a3, -0x43D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X43D4);
    // 0x80004BA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80004BA4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80004BA8: jal         0x8001D8B0
    // 0x80004BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001D8B0(rdram, ctx);
        goto after_5;
    // 0x80004BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80004BB0: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80004BB4: jal         0x8001D358
    // 0x80004BB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8001D358(rdram, ctx);
        goto after_6;
    // 0x80004BB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
L_80004BBC:
    // 0x80004BBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80004BC0:
    // 0x80004BC0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80004BC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80004BC8: jr          $ra
    // 0x80004BCC: nop

    return;
    // 0x80004BCC: nop

;}
RECOMP_FUNC void func_800263A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800263A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800263AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800263B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800263B4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800263B8: lw          $t6, 0x3978($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3978);
    // 0x800263BC: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800263C0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800263C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800263C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800263CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800263D0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800263D4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800263D8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800263DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800263E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800263E4: lw          $t8, -0x640($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X640);
    // 0x800263E8: bne         $t8, $zero, L_8002640C
    if (ctx->r24 != 0) {
        // 0x800263EC: nop
    
            goto L_8002640C;
    }
    // 0x800263EC: nop

    // 0x800263F0: jal         0x800252D8
    // 0x800263F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800252D8(rdram, ctx);
        goto after_0;
    // 0x800263F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800263F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800263FC: jal         0x800252D8
    // 0x80026400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800252D8(rdram, ctx);
        goto after_1;
    // 0x80026400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80026404: b           L_80026424
    // 0x80026408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80026424;
    // 0x80026408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002640C:
    // 0x8002640C: jal         0x800390C0
    // 0x80026410: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    func_800390C0(rdram, ctx);
        goto after_2;
    // 0x80026410: addiu       $a0, $a0, -0x66C
    ctx->r4 = ADD32(ctx->r4, -0X66C);
    after_2:
    // 0x80026414: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80026418: jal         0x800390C0
    // 0x8002641C: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    func_800390C0(rdram, ctx);
        goto after_3;
    // 0x8002641C: addiu       $a0, $a0, -0x4D0
    ctx->r4 = ADD32(ctx->r4, -0X4D0);
    after_3:
    // 0x80026420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80026424:
    // 0x80026424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002642C: jr          $ra
    // 0x80026430: nop

    return;
    // 0x80026430: nop

;}
RECOMP_FUNC void func_8001D8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D8B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001D8B4: beq         $a1, $v0, L_8001D8FC
    if (ctx->r5 == ctx->r2) {
        // 0x8001D8B8: nop
    
            goto L_8001D8FC;
    }
    // 0x8001D8B8: nop

    // 0x8001D8BC: lh          $t6, 0x52($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X52);
    // 0x8001D8C0: beql        $a1, $t6, L_8001D8E4
    if (ctx->r5 == ctx->r14) {
        // 0x8001D8C4: sh          $a2, 0x58($a0)
        MEM_H(0X58, ctx->r4) = ctx->r6;
            goto L_8001D8E4;
    }
    goto skip_0;
    // 0x8001D8C4: sh          $a2, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r6;
    skip_0:
    // 0x8001D8C8: lhu         $t7, 0x60($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X60);
    // 0x8001D8CC: sh          $a1, 0x52($a0)
    MEM_H(0X52, ctx->r4) = ctx->r5;
    // 0x8001D8D0: ori         $t9, $t7, 0x400
    ctx->r25 = ctx->r15 | 0X400;
    // 0x8001D8D4: sh          $t9, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r25;
    // 0x8001D8D8: andi        $t0, $t9, 0xFDFF
    ctx->r8 = ctx->r25 & 0XFDFF;
    // 0x8001D8DC: sh          $t0, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r8;
    // 0x8001D8E0: sh          $a2, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r6;
L_8001D8E4:
    // 0x8001D8E4: lhu         $t1, 0x16($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X16);
    // 0x8001D8E8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8001D8EC: beq         $t2, $zero, L_8001D8FC
    if (ctx->r10 == 0) {
        // 0x8001D8F0: nop
    
            goto L_8001D8FC;
    }
    // 0x8001D8F0: nop

    // 0x8001D8F4: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
    // 0x8001D8F8: sh          $zero, 0x54($a0)
    MEM_H(0X54, ctx->r4) = 0;
L_8001D8FC:
    // 0x8001D8FC: beq         $a3, $v0, L_8001D91C
    if (ctx->r7 == ctx->r2) {
        // 0x8001D900: nop
    
            goto L_8001D91C;
    }
    // 0x8001D900: nop

    // 0x8001D904: lh          $t4, 0x5A($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X5A);
    // 0x8001D908: beql        $a3, $t4, L_8001D918
    if (ctx->r7 == ctx->r12) {
        // 0x8001D90C: lw          $t5, 0x10($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X10);
            goto L_8001D918;
    }
    goto skip_1;
    // 0x8001D90C: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    skip_1:
    // 0x8001D910: sh          $a3, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r7;
    // 0x8001D914: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
L_8001D918:
    // 0x8001D918: sh          $t5, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r13;
L_8001D91C:
    // 0x8001D91C: jr          $ra
    // 0x8001D920: nop

    return;
    // 0x8001D920: nop

;}
RECOMP_FUNC void func_80020D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020D18: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80020D1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80020D20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80020D24: beql        $v0, $zero, L_80020D44
    if (ctx->r2 == 0) {
        // 0x80020D28: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80020D44;
    }
    goto skip_0;
    // 0x80020D28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80020D2C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80020D30:
    // 0x80020D30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80020D34: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80020D38: bnel        $v0, $zero, L_80020D30
    if (ctx->r2 != 0) {
        // 0x80020D3C: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80020D30;
    }
    goto skip_1;
    // 0x80020D3C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80020D40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80020D44:
    // 0x80020D44: jr          $ra
    // 0x80020D48: nop

    return;
    // 0x80020D48: nop

;}
RECOMP_FUNC void alSeqpGetState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800390F0: jr          $ra
    // 0x800390F4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    return;
    // 0x800390F4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
;}
RECOMP_FUNC void func_80039100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039108: jal         0x80034160
    // 0x8003910C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8003910C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80039110: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80039114: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80039118: beq         $s0, $zero, L_80039164
    if (ctx->r16 == 0) {
        // 0x8003911C: nop
    
            goto L_80039164;
    }
    // 0x8003911C: nop

L_80039120:
    // 0x80039120: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80039124: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80039128: bne         $s3, $t6, L_8003915C
    if (ctx->r19 != ctx->r14) {
        // 0x8003912C: nop
    
            goto L_8003915C;
    }
    // 0x8003912C: nop

    // 0x80039130: beq         $s1, $zero, L_80039148
    if (ctx->r17 == 0) {
        // 0x80039134: nop
    
            goto L_80039148;
    }
    // 0x80039134: nop

    // 0x80039138: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8003913C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80039140: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80039144: sw          $t9, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r25;
L_80039148:
    // 0x80039148: jal         0x80036820
    // 0x8003914C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036820(rdram, ctx);
        goto after_1;
    // 0x8003914C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80039150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039154: jal         0x80036850
    // 0x80039158: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80036850(rdram, ctx);
        goto after_2;
    // 0x80039158: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_8003915C:
    // 0x8003915C: bne         $s1, $zero, L_80039120
    if (ctx->r17 != 0) {
        // 0x80039160: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80039120;
    }
    // 0x80039160: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80039164:
    // 0x80039164: jal         0x80034160
    // 0x80039168: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80039168: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x8003916C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039174: jr          $ra
    // 0x80039178: nop

    return;
    // 0x80039178: nop

    // 0x8003917C: jr          $ra
    // 0x80039180: nop

    return;
    // 0x80039180: nop

    // 0x80039184: jr          $ra
    // 0x80039188: nop

    return;
    // 0x80039188: nop

;}
RECOMP_FUNC void func_80044010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044018: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004401C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80044020: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80044024: jal         0x80034160
    // 0x80044028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80044028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004402C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80044030: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80044034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80044038: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x8004403C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x80044040: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80044044: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80044048: jal         0x80034160
    // 0x8004404C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8004404C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x80044050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044058: jr          $ra
    // 0x8004405C: nop

    return;
    // 0x8004405C: nop

;}
RECOMP_FUNC void func_800169C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800169C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800169CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800169D0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x800169D4: lhu         $t6, 0x4EE0($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X4EE0);
    // 0x800169D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800169DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800169E0: bne         $t6, $at, L_80016A7C
    if (ctx->r14 != ctx->r1) {
        // 0x800169E4: nop
    
            goto L_80016A7C;
    }
    // 0x800169E4: nop

    // 0x800169E8: lw          $v0, 0x4EF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4EF8);
    // 0x800169EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800169F0: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800169F4: beq         $v0, $at, L_80016A7C
    if (ctx->r2 == ctx->r1) {
        // 0x800169F8: nop
    
            goto L_80016A7C;
    }
    // 0x800169F8: nop

    // 0x800169FC: lw          $t7, 0x4F1C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4F1C);
    // 0x80016A00: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016A04: addiu       $a0, $a0, 0x5368
    ctx->r4 = ADD32(ctx->r4, 0X5368);
    // 0x80016A08: lhu         $t8, 0x14($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X14);
    // 0x80016A0C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80016A10: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80016A14: andi        $t9, $t8, 0x4
    ctx->r25 = ctx->r24 & 0X4;
    // 0x80016A18: bne         $t9, $zero, L_80016A7C
    if (ctx->r25 != 0) {
        // 0x80016A1C: nop
    
            goto L_80016A7C;
    }
    // 0x80016A1C: nop

    // 0x80016A20: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80016A24: lw          $t0, 0x4EFC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4EFC);
    // 0x80016A28: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80016A2C: addiu       $t2, $zero, 0x108
    ctx->r10 = ADD32(0, 0X108);
    // 0x80016A30: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80016A34: lw          $t1, 0x4F00($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4F00);
    // 0x80016A38: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016A3C: addiu       $a1, $a1, -0x4548
    ctx->r5 = ADD32(ctx->r5, -0X4548);
    // 0x80016A40: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x80016A44: sw          $t2, -0x45B4($at)
    MEM_W(-0X45B4, ctx->r1) = ctx->r10;
    // 0x80016A48: lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X10);
    // 0x80016A4C: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x80016A50: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80016A54: lhu         $t3, 0x2A($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2A);
    // 0x80016A58: addiu       $a2, $a2, -0x4D1C
    ctx->r6 = ADD32(ctx->r6, -0X4D1C);
    // 0x80016A5C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016A60: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80016A64: sh          $t4, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r12;
    // 0x80016A68: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80016A6C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80016A70: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80016A74: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80016A78: sw          $t7, -0x4D14($at)
    MEM_W(-0X4D14, ctx->r1) = ctx->r15;
L_80016A7C:
    // 0x80016A7C: jr          $ra
    // 0x80016A80: nop

    return;
    // 0x80016A80: nop

;}
RECOMP_FUNC void func_800175D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800175D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800175D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800175DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800175E0: lhu         $t6, 0x5E($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X5E);
    // 0x800175E4: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x800175E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800175EC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800175F0: beq         $t7, $zero, L_8001762C
    if (ctx->r15 == 0) {
        // 0x800175F4: addiu       $t2, $t2, -0x3230
        ctx->r10 = ADD32(ctx->r10, -0X3230);
            goto L_8001762C;
    }
    // 0x800175F4: addiu       $t2, $t2, -0x3230
    ctx->r10 = ADD32(ctx->r10, -0X3230);
    // 0x800175F8: jal         0x8000B140
    // 0x800175FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8000B140(rdram, ctx);
        goto after_0;
    // 0x800175FC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80017600: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80017604: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80017608: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001760C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80017610: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80017614: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80017618: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8001761C: lw          $t9, -0x3648($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3648);
    // 0x80017620: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80017624: b           L_80017690
    // 0x80017628: lhu         $v1, 0x2A($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X2A);
        goto L_80017690;
    // 0x80017628: lhu         $v1, 0x2A($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X2A);
L_8001762C:
    // 0x8001762C: lbu         $a0, 0x6($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X6);
    // 0x80017630: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80017634: addiu       $a1, $a1, -0x4580
    ctx->r5 = ADD32(ctx->r5, -0X4580);
    // 0x80017638: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8001763C: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80017640: lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X0);
    // 0x80017644: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x80017648: addu        $t3, $a1, $a0
    ctx->r11 = ADD32(ctx->r5, ctx->r4);
    // 0x8001764C: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x80017650: lbu         $t6, 0x24($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X24);
    // 0x80017654: lhu         $t4, 0x4($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X4);
    // 0x80017658: lbu         $v1, 0x24($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X24);
    // 0x8001765C: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x80017660: lbu         $t1, 0x24($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X24);
    // 0x80017664: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x80017668: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8001766C: lbu         $t6, 0x24($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X24);
    // 0x80017670: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80017674: sra         $t2, $t1, 3
    ctx->r10 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80017678: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x8001767C: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80017680: addu        $v1, $t3, $t7
    ctx->r3 = ADD32(ctx->r11, ctx->r15);
    // 0x80017684: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80017688: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001768C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80017690:
    // 0x80017690: lhu         $t9, 0xC($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0XC);
    // 0x80017694: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80017698: andi        $a1, $v1, 0x3
    ctx->r5 = ctx->r3 & 0X3;
    // 0x8001769C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800176A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800176A4: bgez        $t9, L_800176BC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800176A8: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_800176BC;
    }
    // 0x800176A8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800176AC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800176B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800176B4: nop

    // 0x800176B8: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_800176BC:
    // 0x800176BC: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800176C0: ldc1        $f10, 0x14D0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, 0X14D0);
    // 0x800176C4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800176C8: ldc1        $f4, 0x14D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X14D8);
    // 0x800176CC: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800176D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800176D4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800176D8: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
    // 0x800176DC: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x800176E0: mul.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800176E4: beq         $v1, $zero, L_80017768
    if (ctx->r3 == 0) {
        // 0x800176E8: cvt.s.d     $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
            goto L_80017768;
    }
    // 0x800176E8: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800176EC: beq         $a1, $zero, L_80017718
    if (ctx->r5 == 0) {
        // 0x800176F0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80017718;
    }
    // 0x800176F0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800176F4: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x800176F8: ldc1        $f2, 0x14E0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X14E0);
L_800176FC:
    // 0x800176FC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80017700: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80017704: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x80017708: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001770C: bne         $v1, $v0, L_800176FC
    if (ctx->r3 != ctx->r2) {
        // 0x80017710: cvt.s.d     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
            goto L_800176FC;
    }
    // 0x80017710: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80017714: beq         $v0, $a0, L_80017768
    if (ctx->r2 == ctx->r4) {
        // 0x80017718: lui         $at, 0x8007
        ctx->r1 = S32(0X8007 << 16);
            goto L_80017768;
    }
L_80017718:
    // 0x80017718: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x8001771C: ldc1        $f2, 0x14E8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, 0X14E8);
L_80017720:
    // 0x80017720: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80017724: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80017728: mul.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x8001772C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80017730: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
    // 0x80017734: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80017738: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8001773C: mul.d       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80017740: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80017744: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80017748: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8001774C: mul.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x80017750: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x80017754: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80017758: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8001775C: mul.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x80017760: bne         $v0, $a0, L_80017720
    if (ctx->r2 != ctx->r4) {
        // 0x80017764: cvt.s.d     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
            goto L_80017720;
    }
    // 0x80017764: cvt.s.d     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f0.fl = CVT_S_D(ctx->f18.d);
L_80017768:
    // 0x80017768: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8001776C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80017770: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80017774: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80017778: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8001777C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80017780: nop

    // 0x80017784: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80017788: beql        $v0, $zero, L_800177D8
    if (ctx->r2 == 0) {
        // 0x8001778C: mfc1        $v0, $f4
        ctx->r2 = (int32_t)ctx->f4.u32l;
            goto L_800177D8;
    }
    goto skip_0;
    // 0x8001778C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80017790: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80017794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80017798: sub.s       $f4, $f12, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8001779C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800177A0: nop

    // 0x800177A4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800177A8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800177AC: nop

    // 0x800177B0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800177B4: bne         $v0, $zero, L_800177CC
    if (ctx->r2 != 0) {
        // 0x800177B8: nop
    
            goto L_800177CC;
    }
    // 0x800177B8: nop

    // 0x800177BC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800177C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800177C4: b           L_800177E4
    // 0x800177C8: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800177E4;
    // 0x800177C8: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800177CC:
    // 0x800177CC: b           L_800177E4
    // 0x800177D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800177E4;
    // 0x800177D0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800177D4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
L_800177D8:
    // 0x800177D8: nop

    // 0x800177DC: bltz        $v0, L_800177CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800177E0: nop
    
            goto L_800177CC;
    }
    // 0x800177E0: nop

L_800177E4:
    // 0x800177E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800177E8: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x800177EC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800177F0: jr          $ra
    // 0x800177F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800177F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001829C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001829C: lw          $v0, 0x68($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X68);
    // 0x800182A0: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800182A4: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x800182A8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800182AC: lhu         $t8, -0x328C($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X328C);
    // 0x800182B0: lhu         $t6, 0x8C($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8C);
    // 0x800182B4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800182B8: sh          $t9, 0x8C($v0)
    MEM_H(0X8C, ctx->r2) = ctx->r25;
    // 0x800182BC: jr          $ra
    // 0x800182C0: nop

    return;
    // 0x800182C0: nop

;}
RECOMP_FUNC void func_80029B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B58: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80029B5C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80029B60: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80029B64: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x80029B68: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x80029B6C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80029B70: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80029B74: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80029B78: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80029B7C: lw          $t7, -0xF30($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XF30);
    // 0x80029B80: addiu       $t9, $t9, -0xFEC
    ctx->r25 = ADD32(ctx->r25, -0XFEC);
    // 0x80029B84: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x80029B88: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80029B8C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80029B90: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x80029B94: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x80029B98: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x80029B9C: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x80029BA0: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80029BA4: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x80029BA8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80029BAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80029BB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029BB4: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x80029BB8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80029BBC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80029BC0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80029BC4: sw          $zero, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = 0;
    // 0x80029BC8: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x80029BCC: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x80029BD0: blez        $a0, L_80029BFC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80029BD4: sw          $t1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r9;
            goto L_80029BFC;
    }
    // 0x80029BD4: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x80029BD8: addiu       $t7, $a0, -0x37
    ctx->r15 = ADD32(ctx->r4, -0X37);
    // 0x80029BDC: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80029BE0: beq         $at, $zero, L_80029C4C
    if (ctx->r1 == 0) {
        // 0x80029BE4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80029C4C;
    }
    // 0x80029BE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80029BE8: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80029BEC: addu        $at, $at, $t7
    gpr jr_addend_80029BF4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80029BF0: lw          $t7, 0x1730($at)
    ctx->r15 = ADD32(ctx->r1, 0X1730);
    // 0x80029BF4: jr          $t7
    // 0x80029BF8: nop

    switch (jr_addend_80029BF4 >> 2) {
        case 0: goto L_80029C3C; break;
        case 1: goto L_80029C3C; break;
        case 2: goto L_80029C3C; break;
        case 3: goto L_80029C4C; break;
        case 4: goto L_80029C4C; break;
        case 5: goto L_80029C24; break;
        case 6: goto L_80029C48; break;
        case 7: goto L_80029C34; break;
        default: switch_error(__func__, 0x80029BF4, 0x80071730);
    }
    // 0x80029BF8: nop

L_80029BFC:
    // 0x80029BFC: bne         $a0, $zero, L_80029C4C
    if (ctx->r4 != 0) {
        // 0x80029C00: andi        $t8, $s0, 0xF
        ctx->r24 = ctx->r16 & 0XF;
            goto L_80029C4C;
    }
    // 0x80029C00: andi        $t8, $s0, 0xF
    ctx->r24 = ctx->r16 & 0XF;
    // 0x80029C04: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x80029C08: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80029C0C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80029C10: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x80029C14: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80029C18: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x80029C1C: b           L_80029C4C
    // 0x80029C20: sll         $t5, $t6, 5
    ctx->r13 = S32(ctx->r14 << 5);
        goto L_80029C4C;
    // 0x80029C20: sll         $t5, $t6, 5
    ctx->r13 = S32(ctx->r14 << 5);
L_80029C24:
    // 0x80029C24: addiu       $t0, $zero, -0x80
    ctx->r8 = ADD32(0, -0X80);
    // 0x80029C28: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80029C2C: b           L_80029C4C
    // 0x80029C30: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
        goto L_80029C4C;
    // 0x80029C30: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
L_80029C34:
    // 0x80029C34: b           L_80029C4C
    // 0x80029C38: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
        goto L_80029C4C;
    // 0x80029C38: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
L_80029C3C:
    // 0x80029C3C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80029C40: b           L_80029C4C
    // 0x80029C44: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
        goto L_80029C4C;
    // 0x80029C44: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
L_80029C48:
    // 0x80029C48: sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
L_80029C4C:
    // 0x80029C4C: bgez        $s0, L_80029C88
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80029C50: lw          $t8, 0xE4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XE4);
            goto L_80029C88;
    }
    // 0x80029C50: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80029C54: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80029C58: bgez        $t9, L_80029C68
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80029C5C: negu        $v1, $s0
        ctx->r3 = SUB32(0, ctx->r16);
            goto L_80029C68;
    }
    // 0x80029C5C: negu        $v1, $s0
    ctx->r3 = SUB32(0, ctx->r16);
    // 0x80029C60: b           L_80029C88
    // 0x80029C64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80029C88;
    // 0x80029C64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029C68:
    // 0x80029C68: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80029C6C: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x80029C70: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x80029C74: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x80029C78: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80029C7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80029C80: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x80029C84: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
L_80029C88:
    // 0x80029C88: slti        $at, $s0, 0x141
    ctx->r1 = SIGNED(ctx->r16) < 0X141 ? 1 : 0;
    // 0x80029C8C: bne         $at, $zero, L_80029C9C
    if (ctx->r1 != 0) {
        // 0x80029C90: lw          $t7, 0xE4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XE4);
            goto L_80029C9C;
    }
    // 0x80029C90: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80029C94: b           L_80029CB4
    // 0x80029C98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80029CB4;
    // 0x80029C98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029C9C:
    // 0x80029C9C: addu        $t4, $s0, $t7
    ctx->r12 = ADD32(ctx->r16, ctx->r15);
    // 0x80029CA0: slti        $at, $t4, 0x141
    ctx->r1 = SIGNED(ctx->r12) < 0X141 ? 1 : 0;
    // 0x80029CA4: bne         $at, $zero, L_80029CB4
    if (ctx->r1 != 0) {
        // 0x80029CA8: subu        $t8, $t7, $t4
        ctx->r24 = SUB32(ctx->r15, ctx->r12);
            goto L_80029CB4;
    }
    // 0x80029CA8: subu        $t8, $t7, $t4
    ctx->r24 = SUB32(ctx->r15, ctx->r12);
    // 0x80029CAC: addiu       $t9, $t8, 0x140
    ctx->r25 = ADD32(ctx->r24, 0X140);
    // 0x80029CB0: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
L_80029CB4:
    // 0x80029CB4: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80029CB8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80029CBC: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x80029CC0: blez        $t6, L_80029CD0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80029CC4: addiu       $v1, $v1, -0x4D04
        ctx->r3 = ADD32(ctx->r3, -0X4D04);
            goto L_80029CD0;
    }
    // 0x80029CC4: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80029CC8: bgtzl       $t7, L_80029CD8
    if (SIGNED(ctx->r15) > 0) {
        // 0x80029CCC: sw          $t2, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->r10;
            goto L_80029CD8;
    }
    goto skip_0;
    // 0x80029CCC: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
    skip_0:
L_80029CD0:
    // 0x80029CD0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80029CD4: sw          $t2, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r10;
L_80029CD8:
    // 0x80029CD8: sw          $t3, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r11;
    // 0x80029CDC: bltz        $v0, L_8002A0AC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80029CE0: sw          $t5, 0xB4($sp)
        MEM_W(0XB4, ctx->r29) = ctx->r13;
            goto L_8002A0AC;
    }
    // 0x80029CE0: sw          $t5, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r13;
    // 0x80029CE4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80029CE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029CEC: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80029CF0: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x80029CF4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029CF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029CFC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029D00: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80029D04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029D08: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x80029D0C: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x80029D10: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80029D14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80029D18: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80029D1C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80029D20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029D24: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x80029D28: ori         $t9, $t9, 0xC02
    ctx->r25 = ctx->r25 | 0XC02;
    // 0x80029D2C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029D30: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029D34: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x80029D38: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80029D3C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029D40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029D44: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80029D48: addiu       $t5, $t5, -0x2F4
    ctx->r13 = ADD32(ctx->r13, -0X2F4);
    // 0x80029D4C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029D50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029D54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029D58: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80029D5C: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80029D60: bne         $t0, $zero, L_80029D90
    if (ctx->r8 != 0) {
        // 0x80029D64: addu        $t4, $s0, $t8
        ctx->r12 = ADD32(ctx->r16, ctx->r24);
            goto L_80029D90;
    }
    // 0x80029D64: addu        $t4, $s0, $t8
    ctx->r12 = ADD32(ctx->r16, ctx->r24);
    // 0x80029D68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029D6C: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80029D70: addiu       $t7, $t7, -0xDD8
    ctx->r15 = ADD32(ctx->r15, -0XDD8);
    // 0x80029D74: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80029D78: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80029D7C: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80029D80: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80029D84: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80029D88: b           L_80029DEC
    // 0x80029D8C: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
        goto L_80029DEC;
    // 0x80029D8C: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
L_80029D90:
    // 0x80029D90: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029D94: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x80029D98: addiu       $t6, $t6, -0xDC0
    ctx->r14 = ADD32(ctx->r14, -0XDC0);
    // 0x80029D9C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029DA0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029DA4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80029DA8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029DAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80029DB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029DB4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80029DB8: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x80029DBC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029DC0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029DC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029DC8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80029DCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029DD0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80029DD4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80029DD8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029DDC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029DE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80029DE4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029DE8: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
L_80029DEC:
    // 0x80029DEC: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x80029DF0: bnel        $t9, $zero, L_80029EC0
    if (ctx->r25 != 0) {
        // 0x80029DF4: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80029EC0;
    }
    goto skip_1;
    // 0x80029DF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80029DF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029DFC: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x80029E00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80029E04: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80029E08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029E0C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80029E10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029E14: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80029E18: addiu       $t9, $t9, 0x138
    ctx->r25 = ADD32(ctx->r25, 0X138);
    // 0x80029E1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029E20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029E24: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80029E28: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80029E2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029E30: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x80029E34: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x80029E38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80029E3C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80029E40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029E44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80029E48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029E4C: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x80029E50: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80029E54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029E58: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029E5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80029E60: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029E64: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029E68: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80029E6C: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x80029E70: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029E74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029E78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029E7C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80029E80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029E84: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x80029E88: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x80029E8C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80029E90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80029E94: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80029E98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80029E9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029EA0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029EA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029EA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029EAC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80029EB0: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x80029EB4: ori         $t6, $t9, 0x10
    ctx->r14 = ctx->r25 | 0X10;
    // 0x80029EB8: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
    // 0x80029EBC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80029EC0:
    // 0x80029EC0: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80029EC4: lui         $at, 0xFD48
    ctx->r1 = S32(0XFD48 << 16);
    // 0x80029EC8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80029ECC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80029ED0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80029ED4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80029ED8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80029EDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80029EE0: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x80029EE4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80029EE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029EEC: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x80029EF0: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80029EF4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80029EF8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80029EFC: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80029F00: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80029F04: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80029F08: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x80029F0C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80029F10: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x80029F14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80029F18: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80029F1C: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80029F20: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80029F24: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x80029F28: sll         $t0, $t8, 14
    ctx->r8 = S32(ctx->r24 << 14);
    // 0x80029F2C: andi        $t6, $t1, 0xF
    ctx->r14 = ctx->r9 & 0XF;
    // 0x80029F30: sll         $t1, $t6, 4
    ctx->r9 = S32(ctx->r14 << 4);
    // 0x80029F34: or          $t8, $t0, $at
    ctx->r24 = ctx->r8 | ctx->r1;
    // 0x80029F38: or          $t9, $t8, $t1
    ctx->r25 = ctx->r24 | ctx->r9;
    // 0x80029F3C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80029F40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029F44: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80029F48: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80029F4C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80029F50: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029F54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80029F58: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029F5C: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x80029F60: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80029F64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029F68: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029F6C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80029F70: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x80029F74: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80029F78: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80029F7C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80029F80: sll         $t2, $t7, 12
    ctx->r10 = S32(ctx->r15 << 12);
    // 0x80029F84: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80029F88: andi        $t5, $t9, 0xFFF
    ctx->r13 = ctx->r25 & 0XFFF;
    // 0x80029F8C: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x80029F90: or          $t8, $t7, $t5
    ctx->r24 = ctx->r15 | ctx->r13;
    // 0x80029F94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80029F98: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029F9C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80029FA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80029FA4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80029FA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80029FAC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80029FB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029FB4: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x80029FB8: or          $t8, $t0, $t1
    ctx->r24 = ctx->r8 | ctx->r9;
    // 0x80029FBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80029FC0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80029FC4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80029FC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80029FCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029FD0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80029FD4: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x80029FD8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80029FDC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80029FE0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80029FE4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80029FE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80029FEC: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x80029FF0: lw          $t6, 0xE8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE8);
    // 0x80029FF4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80029FF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80029FFC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002A000: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002A004: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002A008: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8002A00C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8002A010: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8002A014: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8002A018: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8002A01C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002A020: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8002A024: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8002A028: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8002A02C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8002A030: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002A034: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8002A038: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002A03C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A040: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A044: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8002A048: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A04C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A050: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8002A054: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8002A058: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8002A05C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8002A060: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8002A064: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8002A068: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A06C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A070: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8002A074: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8002A078: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002A07C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002A080: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x8002A084: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8002A088: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8002A08C: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8002A090: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002A094: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8002A098: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002A09C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8002A0A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8002A0A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002A0A8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8002A0AC:
    // 0x8002A0AC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8002A0B0: jr          $ra
    // 0x8002A0B4: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8002A0B4: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8010082C_ovl_ending(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010082C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80100830: lw          $v0, 0x61B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X61B8);
    // 0x80100834: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80100838: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8010083C: beq         $v0, $zero, L_8010089C
    if (ctx->r2 == 0) {
        // 0x80100840: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8010089C;
    }
    // 0x80100840: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80100844: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80100848: addiu       $a1, $a1, 0x61B0
    ctx->r5 = ADD32(ctx->r5, 0X61B0);
L_8010084C:
    // 0x8010084C: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x80100850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80100854: beql        $a2, $zero, L_80100890
    if (ctx->r6 == 0) {
        // 0x80100858: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80100890;
    }
    goto skip_0;
    // 0x80100858: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8010085C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
L_80100860:
    // 0x80100860: lh          $t6, 0x22($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X22);
    // 0x80100864: bnel        $a3, $t6, L_80100880
    if (ctx->r7 != ctx->r14) {
        // 0x80100868: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80100880;
    }
    goto skip_1;
    // 0x80100868: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x8010086C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80100870: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80100874: jr          $ra
    // 0x80100878: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    return;
    // 0x80100878: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8010087C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80100880:
    // 0x80100880: sltu        $at, $a0, $a2
    ctx->r1 = ctx->r4 < ctx->r6 ? 1 : 0;
    // 0x80100884: bne         $at, $zero, L_80100860
    if (ctx->r1 != 0) {
        // 0x80100888: addiu       $t0, $t0, 0x28
        ctx->r8 = ADD32(ctx->r8, 0X28);
            goto L_80100860;
    }
    // 0x80100888: addiu       $t0, $t0, 0x28
    ctx->r8 = ADD32(ctx->r8, 0X28);
    // 0x8010088C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80100890:
    // 0x80100890: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80100894: bne         $at, $zero, L_8010084C
    if (ctx->r1 != 0) {
        // 0x80100898: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_8010084C;
    }
    // 0x80100898: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_8010089C:
    // 0x8010089C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801008A0: jr          $ra
    // 0x801008A4: nop

    return;
    // 0x801008A4: nop

;}
RECOMP_FUNC void func_800386D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800386D0: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800386D4: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800386D8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800386DC: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800386E0: beql        $t6, $zero, L_80038718
    if (ctx->r14 == 0) {
        // 0x800386E4: lw          $a3, 0x18($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X18);
            goto L_80038718;
    }
    goto skip_0;
    // 0x800386E4: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x800386E8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800386EC: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800386F0: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800386F4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800386F8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800386FC: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x80038700: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x80038704: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80038708: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x8003870C: jr          $ra
    // 0x80038710: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80038710: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80038714: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
L_80038718:
    // 0x80038718: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x8003871C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80038720: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x80038724: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x80038728: bne         $t0, $v1, L_8003878C
    if (ctx->r8 != ctx->r3) {
        // 0x8003872C: nop
    
            goto L_8003878C;
    }
    // 0x8003872C: nop

    // 0x80038730: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80038734: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80038738: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x8003873C: beq         $t0, $a0, L_8003878C
    if (ctx->r8 == ctx->r4) {
        // 0x80038740: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_8003878C;
    }
    // 0x80038740: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80038744: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x80038748: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x8003874C: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x80038750: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80038754: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x80038758: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x8003875C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80038760: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80038764: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x80038768: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x8003876C: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x80038770: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x80038774: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x80038778: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x8003877C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x80038780: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x80038784: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80038788: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_8003878C:
    // 0x8003878C: jr          $ra
    // 0x80038790: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80038790: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80040830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80040834: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80040838: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004083C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80040840: sll         $s1, $t6, 2
    ctx->r17 = S32(ctx->r14 << 2);
    // 0x80040844: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040848: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004084C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80040850: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x80040854: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80040858: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8004085C: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x80040860: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80040864: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80040868: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004086C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x80040870: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80040874: jal         0x800403F0
    // 0x80040878: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    alFxNew(rdram, ctx);
        goto after_0;
    // 0x80040878: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8004087C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80040880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80040884: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x80040888: jal         0x800493D4
    // 0x8004088C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    func_800493D4(rdram, ctx);
        goto after_1;
    // 0x8004088C: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x80040890: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x80040894: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80040898: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8004089C: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x800408A0: jal         0x800408D0
    // 0x800408A4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    func_800408D0(rdram, ctx);
        goto after_2;
    // 0x800408A4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x800408A8: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x800408AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800408B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800408B4: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x800408B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800408BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800408C0: jr          $ra
    // 0x800408C4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x800408C4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800408C8: nop

    // 0x800408CC: nop

;}
RECOMP_FUNC void func_8000DC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DC4C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000DC50: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000DC54: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000DC58: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000DC5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000DC60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000DC64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000DC68: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000DC6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000DC70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000DC74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000DC78: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8000DC7C: lui         $fp, 0x8005
    ctx->r30 = S32(0X8005 << 16);
    // 0x8000DC80: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8000DC84: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8000DC88: addiu       $s0, $s0, 0x4E60
    ctx->r16 = ADD32(ctx->r16, 0X4E60);
    // 0x8000DC8C: addiu       $s3, $s3, 0x2C48
    ctx->r19 = ADD32(ctx->r19, 0X2C48);
    // 0x8000DC90: addiu       $fp, $fp, 0x6368
    ctx->r30 = ADD32(ctx->r30, 0X6368);
    // 0x8000DC94: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8000DC98: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8000DC9C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8000DCA0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000DCA4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
L_8000DCA8:
    // 0x8000DCA8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000DCAC: beql        $v1, $zero, L_8000DD74
    if (ctx->r3 == 0) {
        // 0x8000DCB0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8000DD74;
    }
    goto skip_0;
    // 0x8000DCB0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x8000DCB4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8000DCB8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8000DCBC: beq         $v0, $zero, L_8000DCD4
    if (ctx->r2 == 0) {
        // 0x8000DCC0: nop
    
            goto L_8000DCD4;
    }
    // 0x8000DCC0: nop

    // 0x8000DCC4: beql        $v0, $s4, L_8000DCF8
    if (ctx->r2 == ctx->r20) {
        // 0x8000DCC8: lw          $a0, 0xC($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XC);
            goto L_8000DCF8;
    }
    goto skip_1;
    // 0x8000DCC8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x8000DCCC: b           L_8000DD74
    // 0x8000DCD0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_8000DD74;
    // 0x8000DCD0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8000DCD4:
    // 0x8000DCD4: bne         $t6, $zero, L_8000DD70
    if (ctx->r14 != 0) {
        // 0x8000DCD8: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_8000DD70;
    }
    // 0x8000DCD8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8000DCDC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8000DCE0: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x8000DCE4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000DCE8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8000DCEC: b           L_8000DD70
    // 0x8000DCF0: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
        goto L_8000DD70;
    // 0x8000DCF0: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x8000DCF4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
L_8000DCF8:
    // 0x8000DCF8: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8000DCFC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8000DD00: sra         $v0, $a0, 8
    ctx->r2 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8000DD04: andi        $t2, $v0, 0xF
    ctx->r10 = ctx->r2 & 0XF;
    // 0x8000DD08: beq         $t2, $s5, L_8000DD28
    if (ctx->r10 == ctx->r21) {
        // 0x8000DD0C: andi        $t3, $a0, 0x1
        ctx->r11 = ctx->r4 & 0X1;
            goto L_8000DD28;
    }
    // 0x8000DD0C: andi        $t3, $a0, 0x1
    ctx->r11 = ctx->r4 & 0X1;
    // 0x8000DD10: beq         $t2, $s6, L_8000DD28
    if (ctx->r10 == ctx->r22) {
        // 0x8000DD14: nop
    
            goto L_8000DD28;
    }
    // 0x8000DD14: nop

    // 0x8000DD18: beql        $t2, $s7, L_8000DD48
    if (ctx->r10 == ctx->r23) {
        // 0x8000DD1C: or          $s2, $fp, $zero
        ctx->r18 = ctx->r30 | 0;
            goto L_8000DD48;
    }
    goto skip_2;
    // 0x8000DD1C: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
    skip_2:
    // 0x8000DD20: b           L_8000DD4C
    // 0x8000DD24: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
        goto L_8000DD4C;
    // 0x8000DD24: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
L_8000DD28:
    // 0x8000DD28: beq         $t3, $zero, L_8000DD3C
    if (ctx->r11 == 0) {
        // 0x8000DD2C: lui         $s2, 0x8005
        ctx->r18 = S32(0X8005 << 16);
            goto L_8000DD3C;
    }
    // 0x8000DD2C: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x8000DD30: lui         $s2, 0x8005
    ctx->r18 = S32(0X8005 << 16);
    // 0x8000DD34: b           L_8000DD48
    // 0x8000DD38: addiu       $s2, $s2, 0x62E0
    ctx->r18 = ADD32(ctx->r18, 0X62E0);
        goto L_8000DD48;
    // 0x8000DD38: addiu       $s2, $s2, 0x62E0
    ctx->r18 = ADD32(ctx->r18, 0X62E0);
L_8000DD3C:
    // 0x8000DD3C: b           L_8000DD48
    // 0x8000DD40: addiu       $s2, $s2, 0x5D58
    ctx->r18 = ADD32(ctx->r18, 0X5D58);
        goto L_8000DD48;
    // 0x8000DD40: addiu       $s2, $s2, 0x5D58
    ctx->r18 = ADD32(ctx->r18, 0X5D58);
    // 0x8000DD44: or          $s2, $fp, $zero
    ctx->r18 = ctx->r30 | 0;
L_8000DD48:
    // 0x8000DD48: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
L_8000DD4C:
    // 0x8000DD4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000DD50: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000DD54: addiu       $t4, $a2, 0x1
    ctx->r12 = ADD32(ctx->r6, 0X1);
    // 0x8000DD58: jal         0x80022B40
    // 0x8000DD5C: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    func_80022B40(rdram, ctx);
        goto after_0;
    // 0x8000DD5C: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    after_0:
    // 0x8000DD60: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8000DD64: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8000DD68: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000DD6C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_8000DD70:
    // 0x8000DD70: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8000DD74:
    // 0x8000DD74: bne         $s1, $zero, L_8000DCA8
    if (ctx->r17 != 0) {
        // 0x8000DD78: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_8000DCA8;
    }
    // 0x8000DD78: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8000DD7C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8000DD80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DD84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DD88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DD8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000DD90: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000DD94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000DD98: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DD9C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000DDA0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000DDA4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000DDA8: jr          $ra
    // 0x8000DDAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000DDAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80049948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049948: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8004994C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80049950: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80049954: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80049958: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004995C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80049960: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80049964: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80049968: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8004996C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80049970: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80049974: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80049978: bne         $a2, $zero, L_80049998
    if (ctx->r6 != 0) {
        // 0x8004997C: sw          $s2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r18;
            goto L_80049998;
    }
    // 0x8004997C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80049980: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80049984: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x80049988: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8004998C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x80049990: b           L_80049A3C
    // 0x80049994: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_80049A3C;
    // 0x80049994: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_80049998:
    // 0x80049998: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8004999C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800499A0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x800499A4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800499A8: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x800499AC: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x800499B0: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x800499B4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800499B8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800499BC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x800499C0: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x800499C4: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800499C8: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
    // 0x800499CC: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
L_800499D0:
    // 0x800499D0: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x800499D4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800499D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800499DC: jal         0x800497C4
    // 0x800499E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800497C4(rdram, ctx);
        goto after_0;
    // 0x800499E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800499E4: lh          $t1, 0x50($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X50);
    // 0x800499E8: bnel        $t1, $s3, L_80049A04
    if (ctx->r9 != ctx->r19) {
        // 0x800499EC: lw          $v0, 0xC($s0)
        ctx->r2 = MEM_W(ctx->r16, 0XC);
            goto L_80049A04;
    }
    goto skip_0;
    // 0x800499EC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800499F0: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    // 0x800499F4: lh          $s5, 0x1A($s0)
    ctx->r21 = MEM_H(ctx->r16, 0X1A);
    // 0x800499F8: b           L_80049A10
    // 0x800499FC: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
        goto L_80049A10;
    // 0x800499FC: lw          $s6, 0xC($s0)
    ctx->r22 = MEM_W(ctx->r16, 0XC);
    // 0x80049A00: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
L_80049A04:
    // 0x80049A04: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x80049A08: bnel        $at, $zero, L_800499D0
    if (ctx->r1 != 0) {
        // 0x80049A0C: lw          $s4, 0x8($s0)
        ctx->r20 = MEM_W(ctx->r16, 0X8);
            goto L_800499D0;
    }
    goto skip_1;
    // 0x80049A0C: lw          $s4, 0x8($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_80049A10:
    // 0x80049A10: sw          $s4, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r20;
    // 0x80049A14: sh          $s5, 0xC($s7)
    MEM_H(0XC, ctx->r23) = ctx->r21;
    // 0x80049A18: sw          $s6, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r22;
    // 0x80049A1C: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80049A20: sw          $t2, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r10;
    // 0x80049A24: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80049A28: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x80049A2C: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x80049A30: sh          $t4, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r12;
    // 0x80049A34: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80049A38: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
L_80049A3C:
    // 0x80049A3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80049A40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80049A44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80049A48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80049A4C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80049A50: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80049A54: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80049A58: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80049A5C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80049A60: jr          $ra
    // 0x80049A64: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80049A64: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void rotateCoordinatesByAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800232F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800232F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800232FC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80023300: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80023304: jal         0x80035680
    // 0x80023308: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80023308: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002330C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80023310: jal         0x800361F0
    // 0x80023314: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80023314: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80023318: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8002331C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80023320: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80023324: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80023328: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8002332C: nop

    // 0x80023330: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80023334: nop

    // 0x80023338: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8002333C: nop

    // 0x80023340: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80023344: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80023348: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8002334C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80023350: swc1        $f18, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f18.u32l;
    // 0x80023354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023358: jr          $ra
    // 0x8002335C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002335C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80025488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025488: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002548C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80025490: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80025494: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80025498: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8002549C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800254A0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800254A4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800254A8: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800254AC: addiu       $s3, $s3, -0xDC0
    ctx->r19 = ADD32(ctx->r19, -0XDC0);
    // 0x800254B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800254B4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x800254B8: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800254BC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800254C0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800254C4: subu        $s0, $s1, $s2
    ctx->r16 = SUB32(ctx->r17, ctx->r18);
    // 0x800254C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800254CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800254D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800254D4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800254D8: jal         0x80036660
    // 0x800254DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800254DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800254E0: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x800254E4: addiu       $s1, $s1, 0x38EC
    ctx->r17 = ADD32(ctx->r17, 0X38EC);
    // 0x800254E8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800254EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800254F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800254F4: jal         0x80024690
    // 0x800254F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80024690(rdram, ctx);
        goto after_1;
    // 0x800254F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800254FC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80025500: addiu       $a1, $a1, -0x988
    ctx->r5 = ADD32(ctx->r5, -0X988);
    // 0x80025504: lui         $s7, 0x8009
    ctx->r23 = S32(0X8009 << 16);
    // 0x80025508: addiu       $s7, $s7, -0x9E0
    ctx->r23 = ADD32(ctx->r23, -0X9E0);
    // 0x8002550C: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80025510: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80025514: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80025518: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8002551C: sw          $s3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r19;
    // 0x80025520: jal         0x800396D4
    // 0x80025524: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800396D4(rdram, ctx);
        goto after_2;
    // 0x80025524: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_2:
    // 0x80025528: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002552C: jal         0x80038404
    // 0x80025530: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alBnkfNew(rdram, ctx);
        goto after_3;
    // 0x80025530: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x80025534: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80025538: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8002553C: addiu       $v0, $v0, -0x978
    ctx->r2 = ADD32(ctx->r2, -0X978);
    // 0x80025540: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80025544: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80025548: addiu       $s6, $s6, -0x97C
    ctx->r22 = ADD32(ctx->r22, -0X97C);
    // 0x8002554C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80025550: lw          $t1, 0xC($t9)
    ctx->r9 = MEM_W(ctx->r25, 0XC);
    // 0x80025554: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80025558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002555C: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x80025560: lh          $t3, 0xE($t1)
    ctx->r11 = MEM_H(ctx->r9, 0XE);
    // 0x80025564: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80025568: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002556C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80025570: jal         0x80036660
    // 0x80025574: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    alHeapDBAlloc(rdram, ctx);
        goto after_4;
    // 0x80025574: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x80025578: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x8002557C: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x80025580: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x80025584: addiu       $s4, $s4, -0x970
    ctx->r20 = ADD32(ctx->r20, -0X970);
    // 0x80025588: addiu       $s3, $s3, -0x974
    ctx->r19 = ADD32(ctx->r19, -0X974);
    // 0x8002558C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80025590: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x80025594: lh          $t5, 0xE($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XE);
    // 0x80025598: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8002559C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800255A0: beq         $t5, $zero, L_80025608
    if (ctx->r13 == 0) {
        // 0x800255A4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80025608;
    }
    // 0x800255A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800255A8: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x800255AC: addu        $t6, $v1, $s1
    ctx->r14 = ADD32(ctx->r3, ctx->r17);
L_800255B0:
    // 0x800255B0: lw          $a1, 0x10($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X10);
    // 0x800255B4: jal         0x80039810
    // 0x800255B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80039810(rdram, ctx);
        goto after_5;
    // 0x800255B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_5:
    // 0x800255BC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800255C0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800255C4: sh          $v0, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r2;
    // 0x800255C8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800255CC: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x800255D0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800255D4: beql        $s5, $t1, L_800255EC
    if (ctx->r21 == ctx->r9) {
        // 0x800255D8: lw          $v1, 0x0($s6)
        ctx->r3 = MEM_W(ctx->r22, 0X0);
            goto L_800255EC;
    }
    goto skip_0;
    // 0x800255D8: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    skip_0:
    // 0x800255DC: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x800255E0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800255E4: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800255E8: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
L_800255EC:
    // 0x800255EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800255F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800255F4: lh          $t4, 0xE($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XE);
    // 0x800255F8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800255FC: sltu        $at, $s2, $t4
    ctx->r1 = ctx->r18 < ctx->r12 ? 1 : 0;
    // 0x80025600: bnel        $at, $zero, L_800255B0
    if (ctx->r1 != 0) {
        // 0x80025604: addu        $t6, $v1, $s1
        ctx->r14 = ADD32(ctx->r3, ctx->r17);
            goto L_800255B0;
    }
    goto skip_1;
    // 0x80025604: addu        $t6, $v1, $s1
    ctx->r14 = ADD32(ctx->r3, ctx->r17);
    skip_1:
L_80025608:
    // 0x80025608: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002560C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80025610: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80025614: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80025618: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8002561C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80025620: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80025624: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80025628: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8002562C: jr          $ra
    // 0x80025630: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80025630: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8001A238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A238: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A23C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8001A240: addiu       $v1, $v1, 0x75A8
    ctx->r3 = ADD32(ctx->r3, 0X75A8);
L_8001A244:
    // 0x8001A244: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8001A248: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8001A24C: sh          $zero, 0x58($v1)
    MEM_H(0X58, ctx->r3) = 0;
    // 0x8001A250: sh          $zero, 0xB0($v1)
    MEM_H(0XB0, ctx->r3) = 0;
    // 0x8001A254: sh          $zero, 0x108($v1)
    MEM_H(0X108, ctx->r3) = 0;
    // 0x8001A258: bne         $v0, $zero, L_8001A244
    if (ctx->r2 != 0) {
        // 0x8001A25C: addiu       $v1, $v1, 0x160
        ctx->r3 = ADD32(ctx->r3, 0X160);
            goto L_8001A244;
    }
    // 0x8001A25C: addiu       $v1, $v1, 0x160
    ctx->r3 = ADD32(ctx->r3, 0X160);
    // 0x8001A260: jr          $ra
    // 0x8001A264: nop

    return;
    // 0x8001A264: nop

;}
RECOMP_FUNC void func_80017470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017478: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001747C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80017480: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80017484: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80017488: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8001748C: lw          $v0, 0x68($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X68);
    // 0x80017490: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80017494: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x80017498: ori         $t8, $t7, 0x200
    ctx->r24 = ctx->r15 | 0X200;
    // 0x8001749C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800174A0: jal         0x8001FCF8
    // 0x800174A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8001FCF8(rdram, ctx);
        goto after_0;
    // 0x800174A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x800174A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800174AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800174B0: jr          $ra
    // 0x800174B4: nop

    return;
    // 0x800174B4: nop

;}
RECOMP_FUNC void func_80030BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030BF0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80030BF4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80030BF8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80030BFC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80030C00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80030C04: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80030C08: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80030C0C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80030C10: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80030C14: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80030C18: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80030C1C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80030C20: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030C24: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80030C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80030C2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030C30: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030C34: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030C38: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030C3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030C40: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80030C44: addiu       $t2, $zero, -0x34
    ctx->r10 = ADD32(0, -0X34);
    // 0x80030C48: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80030C4C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80030C50: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80030C54: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80030C58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80030C5C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80030C60: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80030C64: jal         0x800307D8
    // 0x80030C68: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800307D8(rdram, ctx);
        goto after_0;
    // 0x80030C68: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // 0x80030C6C: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x80030C70: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80030C74: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030C78: addiu       $a2, $s2, 0x2
    ctx->r6 = ADD32(ctx->r18, 0X2);
    // 0x80030C7C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80030C80: jal         0x800307D8
    // 0x80030C84: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800307D8(rdram, ctx);
        goto after_1;
    // 0x80030C84: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_1:
    // 0x80030C88: addu        $a2, $s2, $s3
    ctx->r6 = ADD32(ctx->r18, ctx->r19);
    // 0x80030C8C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80030C90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80030C94: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80030C98: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030C9C: addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // 0x80030CA0: jal         0x800307D8
    // 0x80030CA4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800307D8(rdram, ctx);
        goto after_2;
    // 0x80030CA4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x80030CA8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80030CAC: addiu       $v1, $v1, -0x4D04
    ctx->r3 = ADD32(ctx->r3, -0X4D04);
    // 0x80030CB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030CB4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80030CB8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030CBC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80030CC0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80030CC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80030CC8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80030CCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80030CD0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80030CD4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80030CD8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80030CDC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80030CE0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80030CE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030CE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80030CEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80030CF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80030CF4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80030CF8: jal         0x800307D8
    // 0x80030CFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800307D8(rdram, ctx);
        goto after_3;
    // 0x80030CFC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x80030D00: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80030D04: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80030D08: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80030D0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030D10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80030D14: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80030D18: jal         0x800307D8
    // 0x80030D1C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_800307D8(rdram, ctx);
        goto after_4;
    // 0x80030D1C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_4:
    // 0x80030D20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030D24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80030D28: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80030D2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80030D30: jal         0x800307D8
    // 0x80030D34: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800307D8(rdram, ctx);
        goto after_5;
    // 0x80030D34: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_5:
    // 0x80030D38: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80030D3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80030D40: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80030D44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80030D48: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80030D4C: jal         0x800307D8
    // 0x80030D50: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    func_800307D8(rdram, ctx);
        goto after_6;
    // 0x80030D50: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_6:
    // 0x80030D54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80030D58: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80030D5C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80030D60: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80030D64: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80030D68: jr          $ra
    // 0x80030D6C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80030D6C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80036920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036920: jr          $ra
    // 0x80036924: nop

    return;
    // 0x80036924: nop

;}
