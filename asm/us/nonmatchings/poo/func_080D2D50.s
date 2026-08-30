.syntax unified
	.align 2, 0
	.global func_080D2D50
	.thumb
	.thumb_func
	.type func_080D2D50, %function
func_080D2D50: @ 080D2D50
	ldr r1, _080D2D64 @ =0x0203C470
	ldrh r1, [r1, #0x28]
	asrs r1, r0
	movs r0, #0x01
	ands r1, r0
	cmp r1, #0x00
	bne _080D2D68
	movs r0, #0x00
	b _080D2D6A
	.byte 0x00, 0x00
_080D2D64: .4byte 0x0203C470
_080D2D68:
	movs r0, #0x01
_080D2D6A:
	bx lr
.syntax divided
