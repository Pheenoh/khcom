.syntax unified
	.align 2, 0
	.global sub_08116B10
	.thumb
	.thumb_func
	.type sub_08116B10, %function
sub_08116B10:
	adds r1, r0, #0x0
	ldr r0, [r1, #0x4C]
	cmp r0, #0x00
	bne _08116B1A
	ldr r0, [r1, #0x54]
_08116B1A:
	bx lr
.syntax divided
