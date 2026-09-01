.syntax unified
	.align 2, 0
	.global func_080B1064
	.thumb
	.thumb_func
	.type func_080B1064, %function
func_080B1064: @ 080B1064
	push {r4, r5, lr}
	add sp, #-0x004
	ldr r0, _080B1078 @ =0x02039828
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080B1084
	ldr r2, _080B107C @ =0x02039B58
	ldr r3, _080B1080 @ =0x0203AA58
	ldrb r1, [r3, #0x00]
	b _080B108A
_080B1078: .4byte 0x02039828
_080B107C: .4byte 0x02039B58
_080B1080: .4byte 0x0203AA58
_080B1084:
	ldr r2, _080B1120 @ =0x02039B58
	ldr r3, _080B1124 @ =0x0203AA58
	ldrb r1, [r3, #0x01]
_080B108A:
	movs r0, #0x0F
	ands r0, r1
	lsls r0, r0, #0x04
	ldrh r1, [r2, #0x04]
	orrs r0, r1
	strh r0, [r2, #0x04]
	adds r5, r3, #0x0
	mov r4, sp
	ldr r3, _080B1128 @ =0x02039810
	ldrh r2, [r3, #0x08]
	movs r1, #0xF0
	adds r0, r1, #0x0
	ands r0, r2
	lsrs r0, r0, #0x04
	strb r0, [r4, #0x00]
	mov r2, sp
	ldrh r0, [r3, #0x0A]
	ands r1, r0
	lsrs r1, r1, #0x04
	strb r1, [r2, #0x01]
	mov r0, sp
	ldrb r2, [r0, #0x00]
	subs r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _080B112C @ =0x02034B40
	cmp r0, #0x0A
	bhi _080B10D4
	ldr r0, [r3, #0x00]
	movs r1, #0x85
	lsls r1, r1, #0x02
	adds r0, r0, r1
	strb r2, [r0, #0x00]
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	strb r0, [r5, #0x00]
_080B10D4:
	mov r0, sp
	ldrb r2, [r0, #0x01]
	subs r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0A
	bhi _080B10F2
	ldr r0, [r3, #0x00]
	ldr r1, _080B1130 @ =0x00000215
	adds r0, r0, r1
	strb r2, [r0, #0x00]
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	strb r0, [r5, #0x01]
_080B10F2:
	ldr r1, [r3, #0x00]
	movs r2, #0x85
	lsls r2, r2, #0x02
	adds r0, r1, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, #0x01
	adds r1, r1, r2
	ldrb r1, [r1, #0x00]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl _080B1134
	add sp, #0x004
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B1120: .4byte 0x02039B58
_080B1124: .4byte 0x0203AA58
_080B1128: .4byte 0x02039810
_080B112C: .4byte 0x02034B40
_080B1130: .4byte 0x00000215
_080B1134:
.syntax divided
