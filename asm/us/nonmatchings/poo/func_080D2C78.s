.syntax unified
	.align 2, 0
	.global func_080D2C78
	.thumb
	.thumb_func
	.type func_080D2C78, %function
func_080D2C78: @ 080D2C78
	push {lr}
	ldr r1, _080D2C88 @ =0x0203C470
	movs r0, #0x00
	str r0, [r1, #0x24]
	bl func_080D2C48
	pop {r0}
	bx r0
_080D2C88: .4byte 0x0203C470
.syntax divided
