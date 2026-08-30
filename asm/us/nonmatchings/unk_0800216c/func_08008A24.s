.syntax unified
	.align 2, 0
	.global func_08008A24
	.thumb
	.thumb_func
	.type func_08008A24, %function
func_08008A24: @ 08008A24
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r1, #0x00
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	cmp r1, r2
	bge _08008A4E
	adds r3, r2, #0x0
_08008A36:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r2, r4, r0
	adds r1, r5, r0
	ldrb r1, [r1, #0x00]
	strb r1, [r2, #0x00]
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r3
	blt _08008A36
_08008A4E:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
