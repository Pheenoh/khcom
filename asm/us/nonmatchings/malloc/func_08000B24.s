.syntax unified
	.align 2, 0
	.global func_08000B24
	.thumb
	.thumb_func
	.type func_08000B24, %function
func_08000B24: @ 08000B24
	push {lr}
	cmp r3, #0x00
	beq _08000B3E
	str r3, [r0, #0x04]
	ldr r1, [r3, #0x08]
	str r1, [r0, #0x08]
	str r0, [r3, #0x08]
	cmp r1, #0x00
	beq _08000B3A
	str r0, [r1, #0x04]
	b _08000B42
_08000B3A:
	str r0, [r2, #0x00]
	b _08000B42
_08000B3E:
	bl func_08000B08
_08000B42:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
