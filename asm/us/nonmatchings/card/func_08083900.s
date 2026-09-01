.syntax unified
	.align 2, 0
	.global func_08083900
	.thumb
	.thumb_func
	.type func_08083900, %function
func_08083900: @ 08083900
	ldr r2, _0808390C @ =0x02039DDC
	movs r1, #0x01
	strb r1, [r2, #0x00]
	ldr r1, _08083910 @ =0x02039DD8
	strb r0, [r1, #0x00]
	bx lr
_0808390C: .4byte 0x02039DDC
_08083910: .4byte 0x02039DD8
.syntax divided
