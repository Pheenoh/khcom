.syntax unified
	.align 2, 0
	.global func_080D62A8
	.thumb
	.thumb_func
	.type func_080D62A8, %function
func_080D62A8: @ 080D62A8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _080D62E0 @ =0x0976E9F4
	movs r1, #0x90
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x00]
	ldr r0, _080D62E4 @ =0x09EF659C
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x08]
	ldr r0, _080D62E8 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080D62FC
	ldr r0, _080D62EC @ =0x09776076
	ldr r1, _080D62F0 @ =0x000043C0
	bl func_080026A4
	str r0, [r5, #0x0C]
	ldr r0, _080D62F4 @ =0x09EF669C
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x14]
	ldr r0, _080D62F8 @ =0x0984AA18
	b _080D630E
_080D62E0: .4byte 0x0976E9F4
_080D62E4: .4byte 0x09EF659C
_080D62E8: .4byte 0x02039BB0
_080D62EC: .4byte 0x09776076
_080D62F0: .4byte 0x000043C0
_080D62F4: .4byte 0x09EF669C
_080D62F8: .4byte 0x0984AA18
_080D62FC:
	ldr r0, _080D63AC @ =0x0976EC54
	movs r1, #0xE0
	bl func_080026A4
	str r0, [r5, #0x0C]
	ldr r0, _080D63B0 @ =0x09EF65A4
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x14]
	ldr r0, _080D63B4 @ =0x0984A6D8
_080D630E:
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x10]
	ldr r0, _080D63B8 @ =0x0976ED5A
	movs r1, #0xE0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x18]
	ldr r0, _080D63BC @ =0x09EF65AC
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x20]
	ldr r0, _080D63C0 @ =0x0976F0F6
	movs r1, #0xC0
	bl func_080026A4
	str r0, [r5, #0x24]
	ldr r0, _080D63C4 @ =0x09EF65B4
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x2C]
	ldr r0, _080D63C8 @ =0x0976F1F0
	movs r1, #0xAC
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r5, #0x30]
	ldr r0, _080D63CC @ =0x09EF65BC
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x38]
	ldr r0, _080D63D0 @ =0x0976FD96
	movs r1, #0x8A
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r5, #0x3C]
	ldr r0, _080D63D4 @ =0x09EF65C4
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x44]
	ldr r0, _080D63D8 @ =0x0984A6B8
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	ldr r4, _080D63DC @ =0x0984A6F8
	adds r0, r4, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x1C]
	adds r0, r4, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x28]
	ldr r0, _080D63E0 @ =0x0984A718
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x34]
	ldr r0, _080D63E4 @ =0x0984A738
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x40]
	movs r2, #0x00
	str r2, [r5, #0x4C]
	movs r0, #0xC0
	lsls r0, r0, #0x04
	str r0, [r5, #0x48]
	adds r0, r5, #0x0
	adds r0, #0x50
	movs r1, #0x00
	strh r2, [r0, #0x00]
	ldr r0, _080D63E8 @ =0x02034ECC
	strb r1, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D63AC: .4byte 0x0976EC54
_080D63B0: .4byte 0x09EF65A4
_080D63B4: .4byte 0x0984A6D8
_080D63B8: .4byte 0x0976ED5A
_080D63BC: .4byte 0x09EF65AC
_080D63C0: .4byte 0x0976F0F6
_080D63C4: .4byte 0x09EF65B4
_080D63C8: .4byte 0x0976F1F0
_080D63CC: .4byte 0x09EF65BC
_080D63D0: .4byte 0x0976FD96
_080D63D4: .4byte 0x09EF65C4
_080D63D8: .4byte 0x0984A6B8
_080D63DC: .4byte 0x0984A6F8
_080D63E0: .4byte 0x0984A718
_080D63E4: .4byte 0x0984A738
_080D63E8: .4byte 0x02034ECC
.syntax divided
