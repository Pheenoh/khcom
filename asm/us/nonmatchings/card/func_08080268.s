.syntax unified
	.align 2, 0
	.global func_08080268
	.thumb
	.thumb_func
	.type func_08080268, %function
func_08080268: @ 08080268
	push {r4, r5, r6, lr}
	adds r2, r0, #0x0
	ldr r0, _080802A8 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xC2
	ldrb r3, [r0, #0x00]
	ldr r1, _080802AC @ =0x02039B84
	ldr r0, [r1, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	adds r6, r1, #0x0
	cmp r0, #0x30
	bne _080802D0
	adds r0, r2, #0x0
	adds r0, #0xBA
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080802C6
	movs r4, #0x00
	adds r5, r2, #0x0
	adds r5, #0x28
_08080292:
	lsls r0, r4, #0x02
	adds r0, r5, r0
	ldr r0, [r0, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xA5
	ldrb r0, [r2, #0x00]
	cmp r0, r3
	bls _080802B0
	subs r0, r0, r3
	strb r0, [r2, #0x00]
	b _080802C6
_080802A8: .4byte 0x02039DD4
_080802AC: .4byte 0x02039B84
_080802B0:
	ldrb r1, [r2, #0x00]
	subs r1, r3, r1
	movs r0, #0x00
	strb r0, [r2, #0x00]
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x02
	bls _08080292
_080802C6:
	ldr r1, [r6, #0x00]
	adds r1, #0xF8
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_080802D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
