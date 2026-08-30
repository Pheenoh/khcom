.syntax unified
	.align 2, 0
	.global func_080CFFF0
	.thumb
	.thumb_func
	.type func_080CFFF0, %function
func_080CFFF0: @ 080CFFF0
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, [r4, #0x00]
	ldr r1, [r5, #0x00]
	movs r2, #0xA0
	lsls r2, r2, #0x07
	adds r0, r0, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	movs r1, #0x05
	bl __divsi3
	str r0, [r4, #0x00]
	lsls r0, r0, #0x01
	movs r1, #0xA0
	lsls r1, r1, #0x06
	subs r1, r1, r0
	str r1, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
