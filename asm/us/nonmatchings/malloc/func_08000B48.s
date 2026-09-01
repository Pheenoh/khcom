.syntax unified
	.align 2, 0
	.global func_08000B48
	.thumb
	.thumb_func
	.type func_08000B48, %function
func_08000B48: @ 08000B48
	push {lr}
	cmp r3, #0x00
	beq _08000B62
	str r3, [r0, #0x08]
	ldr r2, [r3, #0x04]
	str r2, [r0, #0x04]
	str r0, [r3, #0x04]
	cmp r2, #0x00
	beq _08000B5E
	str r0, [r2, #0x08]
	b _08000B66
_08000B5E:
	str r0, [r1, #0x00]
	b _08000B66
_08000B62:
	bl func_08000B08
_08000B66:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
