.syntax unified
	.align 2, 0
	.global func_08083B20
	.thumb
	.thumb_func
	.type func_08083B20, %function
func_08083B20: @ 08083B20
	push {r4, lr}
	adds r2, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r3, r2, #0x0
	adds r3, #0x32
	ldrb r0, [r3, #0x00]
	cmp r0, #0x01
	bne _08083B70
	ldrh r0, [r2, #0x2C]
	subs r0, #0x33
	strh r0, [r2, #0x2C]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	bgt _08083B8A
	movs r0, #0x02
	strh r0, [r2, #0x2C]
	movs r0, #0x00
	strb r0, [r3, #0x00]
	cmp r1, #0x00
	bne _08083B60
	ldr r4, _08083B6C @ =0x02039DD8
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x09
	bl __umodsi3
	adds r0, #0x01
	strb r0, [r4, #0x00]
_08083B60:
	ldr r0, _08083B6C @ =0x02039DD8
	ldrb r0, [r0, #0x00]
	bl func_08091B38
	b _08083B8A
	.byte 0x00, 0x00
_08083B6C: .4byte 0x02039DD8
_08083B70:
	ldrh r0, [r2, #0x2C]
	adds r0, #0x33
	strh r0, [r2, #0x2C]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xFF
	ble _08083B8A
	movs r0, #0x80
	lsls r0, r0, #0x01
	strh r0, [r2, #0x2C]
	movs r0, #0x01
	strb r0, [r3, #0x00]
	b _08083B8C
_08083B8A:
	movs r0, #0x00
_08083B8C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
