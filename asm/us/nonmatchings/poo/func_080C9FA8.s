.syntax unified
	.align 2, 0
	.global func_080C9FA8
	.thumb
	.thumb_func
	.type func_080C9FA8, %function
func_080C9FA8: @ 080C9FA8
	ldr r2, _080C9FB4 @ =0x0203C404
	str r0, [r2, #0x00]
	ldr r0, _080C9FB8 @ =0x0203C400
	str r1, [r0, #0x00]
	bx lr
	.byte 0x00, 0x00
_080C9FB4: .4byte 0x0203C404
_080C9FB8: .4byte 0x0203C400
.syntax divided
