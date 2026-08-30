.syntax unified
	.align 2, 0
	.global func_081161DC
	.thumb
	.thumb_func
	.type func_081161DC, %function
func_081161DC: @ 081161DC
	movs r2, #0x00
	ldrh r1, [r0, #0x28]
	ldrh r0, [r0, #0x2A]
	cmp r1, r0
	bne _081161E8
	movs r2, #0x01
_081161E8:
	adds r0, r2, #0x0
	bx lr
.syntax divided
