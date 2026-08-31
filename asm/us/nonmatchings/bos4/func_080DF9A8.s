.syntax unified
	.align 2, 0
	.global func_080DF9A8
	.thumb
	.thumb_func
	.type func_080DF9A8, %function
func_080DF9A8: @ 080DF9A8
	push {lr}
	ldr r1, _080DF9C0 @ =0x02039BB0
	ldrb r0, [r1, #0x0E]
	adds r0, #0x01
	strb r0, [r1, #0x0E]
	movs r0, #0xFE
	movs r1, #0x01
	bl func_080DF8C0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DF9C0: .4byte 0x02039BB0
.syntax divided
