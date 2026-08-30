.syntax unified
	.align 2, 0
	.global func_080B2FC0
	.thumb
	.thumb_func
	.type func_080B2FC0, %function
func_080B2FC0: @ 080B2FC0
	push {r4, r5, lr}
	ldr r4, _080B2FE4 @ =0x02039810
	ldrh r0, [r4, #0x00]
	ldr r5, _080B2FE8 @ =0x00000ACD
	cmp r0, r5
	bne _080B2FD2
	ldrh r0, [r4, #0x0C]
	bl func_080B2FEC
_080B2FD2:
	ldrh r0, [r4, #0x02]
	cmp r0, r5
	bne _080B2FDE
	ldrh r0, [r4, #0x0E]
	bl func_080B2FEC
_080B2FDE:
	pop {r4, r5}
	pop {r0}
	bx r0
_080B2FE4: .4byte 0x02039810
_080B2FE8: .4byte 0x00000ACD
.syntax divided
