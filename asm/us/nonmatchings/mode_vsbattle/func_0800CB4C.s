.syntax unified
	.align 2, 0
	.global func_0800CB4C
	.thumb
	.thumb_func
	.type func_0800CB4C, %function
func_0800CB4C: @ 0800CB4C
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x3C
	bl func_0801AF08
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r4, r2
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
