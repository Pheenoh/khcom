.syntax unified
	.align 2, 0
	.global func_080058FC
	.thumb
	.thumb_func
	.type func_080058FC, %function
func_080058FC: @ 080058FC
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r4, [r5, #0x00]
	subs r0, r1, r4
	cmp r2, #0x00
	bne _0800590E
	movs r2, #0x01
_0800590E:
	adds r1, r2, #0x0
	bl __divsi3
	adds r0, r4, r0
	str r0, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
