.syntax unified
	.align 2, 0
	.global func_08008A54
	.thumb
	.thumb_func
	.type func_08008A54, %function
func_08008A54: @ 08008A54
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	movs r1, #0x00
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	cmp r1, r2
	bge _08008A84
_08008A64:
	lsls r0, r1, #0x10
	asrs r3, r0, #0x10
	adds r0, r5, r3
	adds r1, r4, r3
	ldrb r0, [r0, #0x00]
	ldrb r1, [r1, #0x00]
	cmp r0, r1
	beq _08008A78
	movs r0, #0x00
	b _08008A86
_08008A78:
	adds r0, r3, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	blt _08008A64
_08008A84:
	movs r0, #0x01
_08008A86:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
