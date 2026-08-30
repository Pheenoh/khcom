.syntax unified
	.align 2, 0
	.global func_08004E64
	.thumb
	.thumb_func
	.type func_08004E64, %function
func_08004E64: @ 08004E64
	push {r4, lr}
	add sp, #-0x008
	ldr r2, _08004EF0 @ =0x03007500
	ldrh r1, [r2, #0x00]
	ldr r0, _08004EF4 @ =0x0000FFF8
	ands r0, r1
	movs r3, #0x01
	orrs r0, r3
	strh r0, [r2, #0x00]
	ldr r1, _08004EF8 @ =0x0300750C
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r0, _08004EFC @ =0x03007508
	strh r3, [r0, #0x00]
	ldr r1, _08004F00 @ =0x030074DC
	movs r0, #0x82
	strh r0, [r1, #0x00]
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x07
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x01
	movs r2, #0x0F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x02
	movs r1, #0x02
	movs r2, #0x17
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl func_080054EC
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x00
	bl func_080054EC
	movs r3, #0x80
	lsls r3, r3, #0x01
	movs r0, #0x00
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	movs r0, #0x02
	movs r1, #0x00
	adds r2, r3, #0x0
	bl func_08005690
	movs r2, #0x00
	ldr r4, _08004F04 @ =0x030074D4
	movs r3, #0x00
_08004ED8:
	ldr r0, [r4, #0x00]
	lsls r1, r2, #0x04
	adds r0, #0x04
	adds r0, r0, r1
	str r3, [r0, #0x00]
	adds r2, #0x01
	cmp r2, #0x03
	ble _08004ED8
	add sp, #0x008
	pop {r4}
	pop {r0}
	bx r0
_08004EF0: .4byte 0x03007500
_08004EF4: .4byte 0x0000FFF8
_08004EF8: .4byte 0x0300750C
_08004EFC: .4byte 0x03007508
_08004F00: .4byte 0x030074DC
_08004F04: .4byte 0x030074D4
.syntax divided
