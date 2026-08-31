.syntax unified
	.align 2, 0
	.global mode_vsbattle_1
	.thumb
	.thumb_func
	.type mode_vsbattle_1, %function
mode_vsbattle_1: @ 0800C5F8
	push {r4, r5, lr}
	ldr r4, _0800C624 @ =0x02039B84
	ldr r0, [r4, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C660
	bl func_08010CC8
	ldr r2, [r4, #0x00]
	adds r1, r2, #0x0
	adds r1, #0x72
	ldrh r3, [r1, #0x00]
	movs r4, #0x00
	ldsh r0, [r1, r4]
	cmp r0, #0x00
	bgt _0800C628
	adds r0, r2, #0x0
	adds r0, #0x2C
	bl TaskPoolUpdate
	b _0800C62C
_0800C624: .4byte 0x02039B84
_0800C628:
	subs r0, r3, #0x1
	strh r0, [r1, #0x00]
_0800C62C:
	bl func_08012824
	bl func_080125A4
	ldr r4, _0800C670 @ =0x02039B84
	ldr r0, [r4, #0x00]
	adds r0, #0x40
	bl TaskPoolDraw
	ldr r5, [r4, #0x00]
	ldr r3, [r5, #0x68]
	ldr r4, [r5, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x10
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800C660
	ldr r2, _0800C674 @ =0xFF7FFFFF
	adds r0, r3, #0x0
	ands r0, r2
	adds r1, r4, #0x0
	str r0, [r5, #0x68]
	str r1, [r5, #0x6C]
_0800C660:
	ldr r0, _0800C670 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	bl TaskPoolDraw
	pop {r4, r5}
	pop {r0}
	bx r0
_0800C670: .4byte 0x02039B84
_0800C674: .4byte 0xFF7FFFFF
.syntax divided
