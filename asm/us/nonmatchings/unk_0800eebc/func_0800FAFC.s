.syntax unified
	.align 2, 0
	.global func_0800FAFC
	.thumb
	.thumb_func
	.type func_0800FAFC, %function
func_0800FAFC: @ 0800FAFC
	ldr r0, _0800FB0C @ =0x02039CA8
	ldr r1, [r0, #0x08]
	ldr r0, [r0, #0x0C]
	cmp r1, r0
	bcs _0800FB10
	movs r0, #0x00
	b _0800FB12
	.byte 0x00, 0x00
_0800FB0C: .4byte 0x02039CA8
_0800FB10:
	movs r0, #0x01
_0800FB12:
	bx lr
.syntax divided
