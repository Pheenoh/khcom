.syntax unified
	.align 2, 0
	.global func_080280BC
	.thumb
	.thumb_func
	.type func_080280BC, %function
func_080280BC: @ 080280BC
	push {lr}
	adds r2, r0, #0x0
	str r1, [r2, #0x3C]
	movs r0, #0xAD
	lsls r0, r0, #0x01
	adds r1, r2, r0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	movs r3, #0xAC
	lsls r3, r3, #0x01
	adds r1, r2, r3
	strh r0, [r1, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x44
	bl func_0801AF08
	pop {r0}
	bx r0
.syntax divided
