.syntax unified
	.align 2, 0
	.global func_0805A048
	.thumb
	.thumb_func
	.type func_0805A048, %function
func_0805A048: @ 0805A048
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r4, _0805A0D0 @ =0x02039BB0
	ldr r0, [r4, #0x08]
	str r0, [r5, #0x00]
	ldrh r0, [r4, #0x32]
	adds r1, r5, #0x0
	adds r1, #0x8E
	strh r0, [r1, #0x00]
	adds r1, r4, #0x0
	adds r1, #0xF8
	adds r0, r5, #0x4
	movs r2, #0x88
	bl memcpy
	movs r1, #0xC0
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x8C
	strh r1, [r0, #0x00]
	ldrb r1, [r4, #0x0E]
	adds r0, #0x04
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x0C]
	adds r1, r5, #0x0
	adds r1, #0x91
	strb r0, [r1, #0x00]
	adds r1, #0x03
	movs r2, #0xEE
	lsls r2, r2, #0x01
	adds r6, r4, r2
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x98
	bl func_080E92B8
	movs r1, #0xBB
	lsls r1, r1, #0x02
	adds r0, r5, r1
	bl func_080A3370
	ldr r0, [r4, #0x08]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _0805A0D4
	ldrb r1, [r4, #0x0E]
	movs r2, #0xEA
	lsls r2, r2, #0x01
	adds r0, r4, r2
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x0C]
	adds r2, #0x01
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	adds r2, #0x01
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	movs r0, #0xEC
	lsls r0, r0, #0x01
	b _0805A0F8
_0805A0D0: .4byte 0x02039BB0
_0805A0D4:
	ldrb r1, [r4, #0x0E]
	movs r2, #0xE6
	lsls r2, r2, #0x01
	adds r0, r4, r2
	strb r1, [r0, #0x00]
	ldrb r0, [r4, #0x0C]
	adds r2, #0x01
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	adds r2, #0x01
	adds r1, r4, r2
	strb r0, [r1, #0x00]
	movs r0, #0xE8
	lsls r0, r0, #0x01
_0805A0F8:
	adds r1, r4, r0
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
