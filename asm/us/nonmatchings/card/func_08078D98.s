.syntax unified
	.align 2, 0
	.global func_08078D98
	.thumb
	.thumb_func
	.type func_08078D98, %function
func_08078D98: @ 08078D98
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r0, #0x79
	bl func_0811FE70
	lsls r5, r5, #0x04
	adds r5, #0x54
	adds r4, r4, r5
	adds r0, r4, #0x0
	bl func_08000C8C
	b _08078E20
_08078DBA:
	adds r0, r4, #0x0
	adds r0, #0xA4
	movs r1, #0x00
	ldsb r1, [r0, r1]
	adds r3, r0, #0x0
	cmp r1, #0x01
	beq _08078DDE
	cmp r1, #0x01
	bgt _08078DD2
	cmp r1, #0x00
	beq _08078DD8
	b _08078DE4
_08078DD2:
	cmp r1, #0x02
	beq _08078DDE
	b _08078DE4
_08078DD8:
	ldrb r0, [r3, #0x00]
	adds r0, #0x01
	b _08078DE2
_08078DDE:
	ldrb r0, [r3, #0x00]
	subs r0, #0x01
_08078DE2:
	strb r0, [r3, #0x00]
_08078DE4:
	adds r2, r4, #0x0
	adds r2, #0x80
	ldr r1, _08078E2C @ =0x09033FA8
	movs r0, #0x00
	ldsb r0, [r3, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r2, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x9C
	strh r6, [r0, #0x00]
	ldr r1, [r4, #0x78]
	movs r0, #0x05
	negs r0, r0
	ands r1, r0
	str r1, [r4, #0x78]
	movs r0, #0x00
	ldsb r0, [r3, r0]
	cmp r0, #0x01
	bne _08078E18
	ldr r0, _08078E30 @ =0x02034A98
	str r4, [r0, #0x00]
	movs r0, #0x04
	orrs r1, r0
	str r1, [r4, #0x78]
_08078E18:
	adds r0, r4, #0x0
	adds r0, #0x64
	bl func_08000CD4
_08078E20:
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _08078DBA
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08078E2C: .4byte 0x09033FA8
_08078E30: .4byte 0x02034A98
.syntax divided
