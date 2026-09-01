.syntax unified
	.align 2, 0
	.global func_08000CF0
	.thumb
	.thumb_func
	.type func_08000CF0, %function
func_08000CF0: @ 08000CF0
	ldr r2, [r0, #0x04]
	cmp r2, #0x00
	beq _08000D08
	ldrh r1, [r2, #0x0C]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _08000D04
	adds r0, r2, #0x0
	b func_08000CF0
_08000D04:
	ldr r0, [r2, #0x00]
	b _08000D0A
_08000D08:
	movs r0, #0x00
_08000D0A:
	bx lr
.syntax divided
