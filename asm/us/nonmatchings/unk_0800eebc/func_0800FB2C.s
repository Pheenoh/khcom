.syntax unified
	.align 2, 0
	.global func_0800FB2C
	.thumb
	.thumb_func
	.type func_0800FB2C, %function
func_0800FB2C: @ 0800FB2C
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	cmp r5, #0x48
	bne _0800FB58
	ldr r3, _0800FB54 @ =0x02039BB0
	movs r1, #0x86
	lsls r1, r1, #0x01
	adds r0, r3, r1
	movs r1, #0x01
	negs r1, r1
	asrs r2, r1, #0x1F
	str r1, [r0, #0x00]
	str r2, [r0, #0x04]
	movs r4, #0x8A
	lsls r4, r4, #0x01
	adds r0, r3, r4
	str r1, [r0, #0x00]
	str r2, [r0, #0x04]
	b _0800FBC2
	.byte 0x00, 0x00
_0800FB54: .4byte 0x02039BB0
_0800FB58:
	adds r0, r5, #0x0
	bl func_0800FBCC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800FBC2
	cmp r5, #0x1E
	bhi _0800FB90
	ldr r6, _0800FB8C @ =0x02039BB0
	movs r0, #0x86
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r0, #0x01
	movs r1, #0x00
	adds r2, r5, #0x0
	bl __ashldi3
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	movs r2, #0x8E
	lsls r2, r2, #0x01
	b _0800FBB4
_0800FB8C: .4byte 0x02039BB0
_0800FB90:
	subs r5, #0x1F
	ldr r6, _0800FBC8 @ =0x02039BB0
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r0, #0x01
	movs r1, #0x00
	adds r2, r5, #0x0
	bl __ashldi3
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
	movs r2, #0x92
	lsls r2, r2, #0x01
_0800FBB4:
	adds r4, r6, r2
	ldr r2, [r4, #0x00]
	ldr r3, [r4, #0x04]
	orrs r2, r0
	orrs r3, r1
	str r2, [r4, #0x00]
	str r3, [r4, #0x04]
_0800FBC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0800FBC8: .4byte 0x02039BB0
.syntax divided
