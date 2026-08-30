.syntax unified
	.align 2, 0
	.global func_0801B7D8
	.thumb
	.thumb_func
	.type func_0801B7D8, %function
func_0801B7D8: @ 0801B7D8
	push {r4, r5, lr}
	adds r1, r0, #0x0
	adds r1, #0xDC
	ldr r4, [r1, #0x00]
	cmp r4, r0
	bne _0801B80E
	adds r0, r4, #0x0
	adds r0, #0xB8
	ldr r5, _0801B814 @ =0x02039B84
	ldr r1, [r5, #0x00]
	adds r1, #0x80
	bl func_08000D90
	ldrh r1, [r4, #0x3C]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	bne _0801B804
	adds r0, r4, #0x0
	adds r0, #0x40
	bl func_08012304
_0801B804:
	ldr r1, [r5, #0x00]
	adds r1, #0xEE
	ldrb r0, [r1, #0x00]
	subs r0, #0x01
	strb r0, [r1, #0x00]
_0801B80E:
	pop {r4, r5}
	pop {r0}
	bx r0
_0801B814: .4byte 0x02039B84
.syntax divided
