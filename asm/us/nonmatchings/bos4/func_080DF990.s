.syntax unified
	.align 2, 0
	.global func_080DF990
	.thumb
	.thumb_func
	.type func_080DF990, %function
func_080DF990: @ 080DF990
	push {lr}
	ldr r1, _080DF9A4 @ =0x02039BB0
	strb r0, [r1, #0x0E]
	movs r0, #0xFE
	movs r1, #0x00
	bl func_080DF8C0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DF9A4: .4byte 0x02039BB0
.syntax divided
