.syntax unified
	.align 2, 0
	.global func_0801CCB4
	.thumb
	.thumb_func
	.type func_0801CCB4, %function
func_0801CCB4: @ 0801CCB4
	push {r4, lr}
	movs r0, #0x00
	movs r1, #0x00
	bl func_080DFAF4
	ldr r4, _0801CD18 @ =0x02039BB0
	movs r0, #0xBD
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0801CD1C @ =0x0000E7FF
	strh r0, [r1, #0x00]
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x80
	strh r0, [r1, #0x00]
	movs r0, #0x00
	bl _08085D04
	ldr r0, [r4, #0x08]
	movs r1, #0x08
	orrs r0, r1
	adds r1, #0xF8
	orrs r0, r1
	str r0, [r4, #0x08]
	movs r0, #0x00
	bl func_0800FDD0
	movs r0, #0x15
	bl func_0800FDD0
	movs r0, #0xED
	bl func_0800FDD0
	movs r0, #0x11
	bl func_0800FDD0
	movs r0, #0x16
	bl func_0800FDD0
	movs r0, #0xEF
	bl func_0800FDD0
	movs r0, #0xF3
	bl func_0800FDD0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801CD18: .4byte 0x02039BB0
_0801CD1C: .4byte 0x0000E7FF
.syntax divided
