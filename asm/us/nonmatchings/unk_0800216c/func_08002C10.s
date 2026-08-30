.syntax unified
	.align 2, 0
	.global func_08002C10
	.thumb
	.thumb_func
	.type func_08002C10, %function
func_08002C10: @ 08002C10
	push {lr}
	cmp r0, #0x00
	beq _08002C22
	ldr r1, [r0, #0x24]
	cmp r1, r0
	bne _08002C22
	adds r0, r1, #0x0
	bl func_08002BCC
_08002C22:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
