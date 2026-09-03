.syntax unified
	.align 2, 0
	.global func_08065B54
	.thumb
	.thumb_func
	.type func_08065B54, %function
func_08065B54: @ 08065B54
	movs r2, #0x00
	adds r1, r0, #0x0
	b _08065B62
_08065B5A:
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r1, #0x02
_08065B62:
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08065B5A
	adds r0, r2, #0x0
	bx lr
.syntax divided
