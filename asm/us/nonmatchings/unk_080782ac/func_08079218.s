.syntax unified
	.align 2, 0
	.global func_08079218
	.thumb
	.thumb_func
	.type func_08079218, %function
func_08079218: @ 08079218
	push {r4, r5, r6, lr}
	mov r12, r0
	ldr r0, _0807925C @ =0x02039DD4
	ldr r0, [r0, #0x00]
	adds r0, #0xC2
	ldrb r3, [r0, #0x00]
	ldr r0, _08079260 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x90
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080792A4
	ldr r0, _08079264 @ =0x02039B9C
	ldr r1, [r0, #0x00]
	adds r1, #0xF4
	ldr r1, [r1, #0x00]
	adds r6, r0, #0x0
	cmp r1, #0x30
	bne _080792A4
	mov r0, r12
	adds r0, #0xBA
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0807929A
	movs r4, #0x00
	mov r0, r12
	adds r0, #0xB9
	adds r5, r0, #0x0
	b _08079294
_0807925C: .4byte 0x02039DD4
_08079260: .4byte 0x02039B84
_08079264: .4byte 0x02039B9C
_08079268:
	lsls r0, r4, #0x02
	mov r1, r12
	adds r1, #0x28
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xA5
	ldrb r0, [r2, #0x00]
	cmp r0, r3
	bls _08079282
	subs r0, r0, r3
	strb r0, [r2, #0x00]
	b _0807929A
_08079282:
	ldrb r1, [r2, #0x00]
	subs r1, r3, r1
	movs r0, #0x00
	strb r0, [r2, #0x00]
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08079294:
	ldrb r0, [r5, #0x00]
	cmp r4, r0
	bcc _08079268
_0807929A:
	ldr r1, [r6, #0x00]
	adds r1, #0xF8
	ldrh r0, [r1, #0x00]
	subs r0, #0x01
	strh r0, [r1, #0x00]
_080792A4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
