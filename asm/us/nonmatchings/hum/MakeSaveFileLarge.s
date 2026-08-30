.syntax unified
	.align 2, 0
	.global MakeSaveFileLarge
	.thumb
	.thumb_func
	.type MakeSaveFileLarge, %function
MakeSaveFileLarge: @ 08059F68
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r4, _0805A00C @ =0x02039BB0
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
	bl func_080A324C
	ldr r2, _0805A010 @ =0x00000E6C
	adds r0, r5, r2
	bl func_080C700C
	movs r1, #0xE7
	lsls r1, r1, #0x04
	adds r0, r5, r1
	bl func_080DDEB0
	ldr r2, _0805A014 @ =0x00000EB4
	adds r0, r5, r2
	bl func_0810962C
	ldr r0, [r4, #0x08]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0x00
	beq _0805A018
	ldrb r1, [r4, #0x0E]
	movs r2, #0xE2
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
	movs r0, #0xE4
	lsls r0, r0, #0x01
	b _0805A03C
	.byte 0x00, 0x00
_0805A00C: .4byte 0x02039BB0
_0805A010: .4byte 0x00000E6C
_0805A014: .4byte 0x00000EB4
_0805A018:
	ldrb r1, [r4, #0x0E]
	movs r2, #0xDE
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
	movs r0, #0xE0
	lsls r0, r0, #0x01
_0805A03C:
	adds r1, r4, r0
	ldr r0, [r6, #0x00]
	str r0, [r1, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
