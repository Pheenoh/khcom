.syntax unified
	.align 2, 0
	.global func_08004DB0
	.thumb
	.thumb_func
	.type func_08004DB0, %function
func_08004DB0: @ 08004DB0
	push {r4, lr}
	ldr r2, _08004E48 @ =0x03007500
	ldrh r1, [r2, #0x00]
	ldr r0, _08004E4C @ =0x0000FFF8
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _08004E50 @ =0x0300750C
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, _08004E54 @ =0x03007508
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r1, _08004E58 @ =0x030074DC
	movs r0, #0x02
	strh r0, [r1, #0x00]
	ldr r1, _08004E5C @ =0x0300753C
	movs r0, #0x03
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x07
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x01
	movs r2, #0x0F
	movs r3, #0x04
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x02
	movs r2, #0x17
	movs r3, #0x08
	bl func_08005074
	movs r0, #0x03
	movs r1, #0x03
	movs r2, #0x1F
	movs r3, #0x0C
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_080054EC
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x00
	bl func_080054EC
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x00
	bl func_080054EC
	movs r0, #0x03
	movs r1, #0x00
	movs r2, #0x00
	bl func_080054EC
	movs r2, #0x00
	ldr r4, _08004E60 @ =0x030074D4
	movs r3, #0x00
_08004E32:
	ldr r0, [r4, #0x00]
	lsls r1, r2, #0x04
	adds r0, #0x04
	adds r0, r0, r1
	str r3, [r0, #0x00]
	adds r2, #0x01
	cmp r2, #0x03
	ble _08004E32
	pop {r4}
	pop {r0}
	bx r0
_08004E48: .4byte 0x03007500
_08004E4C: .4byte 0x0000FFF8
_08004E50: .4byte 0x0300750C
_08004E54: .4byte 0x03007508
_08004E58: .4byte 0x030074DC
_08004E5C: .4byte 0x0300753C
_08004E60: .4byte 0x030074D4
.syntax divided
