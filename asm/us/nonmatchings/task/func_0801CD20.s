.syntax unified
	.align 2, 0
	.global func_0801CD20
	.thumb
	.thumb_func
	.type func_0801CD20, %function
func_0801CD20: @ 0801CD20
	push {r4, lr}
	ldr r4, _0801CD70 @ =0x02039BB0
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x03
	strh r0, [r1, #0x00]
	bl func_08085C3C
	ldr r0, [r4, #0x08]
	movs r1, #0x09
	negs r1, r1
	ands r0, r1
	str r0, [r4, #0x08]
	movs r0, #0x11
	bl func_0800FDD0
	movs r0, #0x12
	bl func_0800FDD0
	movs r0, #0x13
	bl func_0800FDD0
	movs r0, #0x14
	bl func_0800FDD0
	movs r0, #0x15
	bl func_0800FDD0
	movs r0, #0x16
	bl func_0800FDD0
	movs r0, #0x00
	movs r1, #0x0A
	bl func_080DFAF4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801CD70: .4byte 0x02039BB0
.syntax divided
