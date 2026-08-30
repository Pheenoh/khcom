.syntax unified
	.align 2, 0
	.global func_080D7B94
	.thumb
	.thumb_func
	.type func_080D7B94, %function
func_080D7B94: @ 080D7B94
	ldr r0, _080D7BA0 @ =0x0203C550
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	beq _080D7BA4
	movs r0, #0x00
	b _080D7BA6
_080D7BA0: .4byte 0x0203C550
_080D7BA4:
	movs r0, #0x01
_080D7BA6:
	bx lr
.syntax divided
