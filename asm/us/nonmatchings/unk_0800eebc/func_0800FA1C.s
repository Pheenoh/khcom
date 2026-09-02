.syntax unified
	.align 2, 0
	.global func_0800FA1C
	.thumb
	.thumb_func
	.type func_0800FA1C, %function
func_0800FA1C: @ 0800FA1C
	push {lr}
	ldr r3, _0800FA38 @ =0x02039CA8
	ldrb r0, [r3, #0x10]
	ldr r1, _0800FA3C @ =0x02039B84
	ldr r1, [r1, #0x00]
	adds r1, #0xFA
	ldrb r2, [r1, #0x00]
	adds r0, r0, r2
	adds r0, #0x01
	cmp r0, #0x63
	ble _0800FA40
	movs r0, #0x00
	b _0800FA52
	.byte 0x00, 0x00
_0800FA38: .4byte 0x02039CA8
_0800FA3C: .4byte 0x02039B84
_0800FA40:
	adds r0, r2, #0x1
	strb r0, [r1, #0x00]
	ldrb r0, [r3, #0x10]
	adds r0, #0x01
	strb r0, [r3, #0x10]
	adds r0, r3, #0x0
	bl func_0800F988
	movs r0, #0x01
_0800FA52:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
