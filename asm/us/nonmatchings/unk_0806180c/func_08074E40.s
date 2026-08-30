.syntax unified
	.align 2, 0
	.global func_08074E40
	.thumb
	.thumb_func
	.type func_08074E40, %function
func_08074E40: @ 08074E40
	push {r4, lr}
	ldr r2, _08074E70 @ =0x09EE3FB4
	ldrb r1, [r0, #0x08]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldrb r2, [r1, #0x00]
	ldr r4, [r1, #0x04]
	ldrb r1, [r0, #0x09]
	lsls r1, r1, #0x05
	ldr r0, [r0, #0x0C]
	adds r0, r0, r1
	movs r1, #0x00
	cmp r1, r2
	bcs _08074E7E
	ldrb r3, [r0, #0x10]
_08074E60:
	lsls r0, r1, #0x03
	adds r0, r0, r4
	ldrb r0, [r0, #0x04]
	cmp r3, r0
	bne _08074E74
	adds r0, r1, #0x0
	b _08074E80
	.byte 0x00, 0x00
_08074E70: .4byte 0x09EE3FB4
_08074E74:
	adds r0, r1, #0x1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r2
	bcc _08074E60
_08074E7E:
	movs r0, #0xFF
_08074E80:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
