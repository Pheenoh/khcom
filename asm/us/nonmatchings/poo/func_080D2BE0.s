.syntax unified
	.align 2, 0
	.global func_080D2BE0
	.thumb
	.thumb_func
	.type func_080D2BE0, %function
func_080D2BE0: @ 080D2BE0
	ldr r0, _080D2BF4 @ =0x0203C470
	movs r2, #0x00
	movs r1, #0x03
	adds r0, #0x38
_080D2BE8:
	str r2, [r0, #0x00]
	subs r0, #0x04
	subs r1, #0x01
	cmp r1, #0x00
	bge _080D2BE8
	bx lr
_080D2BF4: .4byte 0x0203C470
.syntax divided
