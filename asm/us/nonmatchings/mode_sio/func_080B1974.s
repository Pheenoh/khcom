.syntax unified
	.align 2, 0
	.global func_080B1974
	.thumb
	.thumb_func
	.type func_080B1974, %function
func_080B1974: @ 080B1974
	push {r4, r5, lr}
	ldr r1, _080B19F4 @ =0x096F8464
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x02
	bl func_0800510C
	movs r5, #0xC8
	lsls r5, r5, #0x04
	ldr r1, _080B19F8 @ =0x091CF5D4
	adds r0, r5, #0x0
	bl func_080028F8
	ldr r4, _080B19FC @ =0x02034B44
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x08]
	ldr r0, _080B1A00 @ =0x09EEE4C8
	ldr r0, [r0, #0x18]
	str r0, [r1, #0x18]
	ldr r1, _080B1A04 @ =0x088B6560
	adds r0, r5, #0x0
	bl func_080028F8
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x0C]
	ldr r0, _080B1A08 @ =0x09EDE8CC
	ldr r0, [r0, #0x48]
	str r0, [r1, #0x1C]
	ldr r0, _080B1A0C @ =0x0962D196
	movs r1, #0xC0
	lsls r1, r1, #0x03
	bl func_080026A4
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x28]
	ldr r0, _080B1A10 @ =0x096FBE04
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x30]
	ldr r0, _080B1A14 @ =0x09EF38E4
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x38]
	ldr r0, _080B1A18 @ =0x0962CAFC
	movs r1, #0xD0
	lsls r1, r1, #0x03
	bl func_080026A4
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x2C]
	ldr r0, _080B1A1C @ =0x096FBDE4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r4, #0x00]
	str r0, [r1, #0x34]
	ldr r0, _080B1A20 @ =0x09EF38DC
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x3C]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B19F4: .4byte 0x096F8464
_080B19F8: .4byte 0x091CF5D4
_080B19FC: .4byte 0x02034B44
_080B1A00: .4byte 0x09EEE4C8
_080B1A04: .4byte 0x088B6560
_080B1A08: .4byte 0x09EDE8CC
_080B1A0C: .4byte 0x0962D196
_080B1A10: .4byte 0x096FBE04
_080B1A14: .4byte 0x09EF38E4
_080B1A18: .4byte 0x0962CAFC
_080B1A1C: .4byte 0x096FBDE4
_080B1A20: .4byte 0x09EF38DC
.syntax divided
