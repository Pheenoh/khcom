.syntax unified
	.align 2, 0
	.global func_08000D0C
	.thumb
	.thumb_func
	.type func_08000D0C, %function
func_08000D0C: @ 08000D0C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08000D16
	movs r0, #0x00
	b _08000D18
_08000D16:
	ldr r0, [r0, #0x00]
_08000D18:
	bx lr
	.byte 0x00, 0x00
.syntax divided
