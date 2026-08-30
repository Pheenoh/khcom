.syntax unified
	.align 2, 0
	.global func_080D6280
	.thumb
	.thumb_func
	.type func_080D6280, %function
func_080D6280: @ 080D6280
	ldr r0, _080D628C @ =0x02034E98
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bhi _080D6290
	movs r0, #0x00
	b _080D6292
_080D628C: .4byte 0x02034E98
_080D6290:
	movs r0, #0x01
_080D6292:
	bx lr
.syntax divided
