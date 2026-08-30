.syntax unified
	.align 2, 0
	.global func_080D2D94
	.thumb
	.thumb_func
	.type func_080D2D94, %function
func_080D2D94: @ 080D2D94
	ldr r2, _080D2DA8 @ =0x0203C470
	movs r1, #0x01
	lsls r1, r0
	ldr r0, [r2, #0x24]
	ands r0, r1
	cmp r0, #0x00
	bne _080D2DAC
	movs r0, #0x00
	b _080D2DAE
	.byte 0x00, 0x00
_080D2DA8: .4byte 0x0203C470
_080D2DAC:
	movs r0, #0x01
_080D2DAE:
	bx lr
.syntax divided
