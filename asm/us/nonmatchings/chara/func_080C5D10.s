.syntax unified
	.align 2, 0
	.global func_080C5D10
	.thumb
	.thumb_func
	.type func_080C5D10, %function
func_080C5D10: @ 080C5D10
	ldr r1, _080C5D20 @ =0x02039B58
	movs r2, #0x00
	adds r0, r1, #0x6
_080C5D16:
	strh r2, [r0, #0x00]
	subs r0, #0x02
	cmp r0, r1
	bge _080C5D16
	bx lr
_080C5D20: .4byte 0x02039B58
.syntax divided
