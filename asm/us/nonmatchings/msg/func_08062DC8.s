.syntax unified
	.align 2, 0
	.global func_08062DC8
	.thumb
	.thumb_func
	.type func_08062DC8, %function
func_08062DC8: @ 08062DC8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r3, r0, #0x0
	mov r8, r2
	movs r4, #0x00
	ldr r6, _08062F04 @ =0x02034A90
	ldrb r0, [r6, #0x00]
	cmp r0, #0x2C
	bls _08062DE0
	b _08062EF6
_08062DE0:
	ldr r0, _08062F08 @ =0x02034A80
	mov r9, r0
	ldr r2, [r0, #0x00]
	cmp r2, #0x00
	bne _08062DEC
	b _08062EF6
_08062DEC:
	ldrb r0, [r6, #0x00]
	movs r5, #0x58
	muls r0, r5
	adds r0, r0, r2
	str r3, [r0, #0x00]
	ldrb r0, [r6, #0x00]
	muls r0, r5
	adds r0, r0, r2
	str r1, [r0, #0x04]
	ldrb r0, [r6, #0x00]
	muls r0, r5
	adds r0, r0, r2
	adds r0, #0x51
	strb r4, [r0, #0x00]
	mov r0, r8
	bl func_0809D280
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0x0F
	bls _08062E18
	movs r7, #0x10
_08062E18:
	ldrb r0, [r6, #0x00]
	mov r2, r9
	ldr r1, [r2, #0x00]
	muls r0, r5
	adds r0, r0, r1
	adds r0, #0x50
	strb r7, [r0, #0x00]
	movs r5, #0x00
	cmp r5, r7
	bcs _08062ED8
_08062E2C:
	movs r0, #0x20
	bl func_080038C8
	ldr r1, _08062F04 @ =0x02034A90
	ldrb r3, [r1, #0x00]
	ldr r1, _08062F08 @ =0x02034A80
	ldr r2, [r1, #0x00]
	movs r1, #0x58
	muls r1, r3
	adds r1, r1, r2
	lsls r2, r5, #0x02
	adds r1, #0x08
	adds r1, r1, r2
	str r0, [r1, #0x00]
	mov r0, r8
	adds r1, r0, r5
	ldrb r3, [r1, #0x00]
	adds r0, r3, #0x0
	subs r0, #0x30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r2, #0x0
	cmp r0, #0x09
	bhi _08062E5E
	adds r4, r0, #0x0
_08062E5E:
	adds r0, r3, #0x0
	subs r0, #0x41
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x19
	bhi _08062E72
	adds r0, r3, #0x0
	subs r0, #0x37
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08062E72:
	adds r0, r3, #0x0
	cmp r0, #0x2F
	bne _08062E7A
	movs r4, #0x24
_08062E7A:
	cmp r0, #0x2D
	bne _08062E80
	movs r4, #0x25
_08062E80:
	cmp r0, #0x5F
	bne _08062E86
	movs r4, #0x26
_08062E86:
	cmp r0, #0x2E
	bne _08062E8C
	movs r4, #0x27
_08062E8C:
	cmp r0, #0x2B
	bne _08062E92
	movs r4, #0x28
_08062E92:
	cmp r0, #0x21
	bne _08062E98
	movs r4, #0x29
_08062E98:
	cmp r0, #0x3F
	bne _08062E9E
	movs r4, #0x2A
_08062E9E:
	cmp r0, #0x23
	bne _08062EA4
	movs r4, #0x2B
_08062EA4:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x25
	bne _08062EAC
	movs r4, #0x2C
_08062EAC:
	ldr r0, _08062F04 @ =0x02034A90
	ldrb r2, [r0, #0x00]
	ldr r0, _08062F08 @ =0x02034A80
	ldr r1, [r0, #0x00]
	movs r0, #0x58
	muls r0, r2
	adds r0, r0, r1
	adds r0, #0x08
	adds r0, r0, r6
	ldr r0, [r0, #0x00]
	ldr r2, _08062F0C @ =0x09EEC538
	lsls r1, r4, #0x02
	adds r1, r1, r2
	ldr r1, [r1, #0x00]
	ldr r2, _08062F10 @ =0x090D4180
	bl func_080038E4
	adds r0, r5, #0x1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r7
	bcc _08062E2C
_08062ED8:
	ldr r0, _08062F14 @ =0x08F69BE4
	movs r1, #0x20
	bl LoadObjPalette
	ldr r2, _08062F04 @ =0x02034A90
	ldrb r4, [r2, #0x00]
	ldr r1, _08062F08 @ =0x02034A80
	ldr r3, [r1, #0x00]
	movs r1, #0x58
	muls r1, r4
	adds r1, r1, r3
	str r0, [r1, #0x48]
	ldrb r0, [r2, #0x00]
	adds r0, #0x01
	strb r0, [r2, #0x00]
_08062EF6:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08062F04: .4byte 0x02034A90
_08062F08: .4byte 0x02034A80
_08062F0C: .4byte 0x09EEC538
_08062F10: .4byte 0x090D4180
_08062F14: .4byte 0x08F69BE4
.syntax divided
