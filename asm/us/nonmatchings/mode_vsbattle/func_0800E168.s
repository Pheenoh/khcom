.syntax unified
	.align 2, 0
	.global func_0800E168
	.thumb
	.thumb_func
	.type func_0800E168, %function
func_0800E168: @ 0800E168
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r9, r1
	movs r0, #0x40
	adds r0, r0, r6
	mov r8, r0
	movs r2, #0xA0
	lsls r2, r2, #0x09
	ldr r3, _0800E2EC @ =0x00018100
	movs r7, #0x00
	adds r1, #0x0C
	str r7, [sp, #0x000]
	bl func_0801B37C
	movs r1, #0x87
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strh r7, [r0, #0x00]
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r7, [r0, #0x00]
	adds r1, #0x04
	adds r0, r6, r1
	strh r7, [r0, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xF2
	movs r2, #0x01
	mov r10, r2
	mov r1, r10
	strh r1, [r0, #0x00]
	mov r2, r8
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ldr r2, _0800E2F0 @ =0x00000000
	ldr r3, _0800E2F4 @ =0x00400000
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	orrs r5, r3
	mov r0, r8
	str r4, [r0, #0x34]
	str r5, [r0, #0x38]
	ldr r1, _0800E2F8 @ =0x02039B84
	ldr r0, [r1, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r0, #0x04]
	mov r2, r8
	ldr r0, [r2, #0x04]
	cmp r1, r0
	bge _0800E1E6
	movs r2, #0x04
	movs r3, #0x00
	adds r0, r4, #0x0
	orrs r0, r2
	adds r1, r5, #0x0
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
_0800E1E6:
	mov r0, r9
	str r0, [r6, #0x00]
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x15
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r6, #0x04]
	mov r1, r9
	ldr r0, [r1, #0x04]
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x08]
	movs r2, #0xBC
	lsls r2, r2, #0x01
	adds r1, r6, r2
	mov r2, r9
	ldr r0, [r2, #0x04]
	str r0, [r1, #0x00]
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strh r7, [r0, #0x00]
	movs r2, #0xA9
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r7, [r0, #0x00]
	adds r1, #0x04
	adds r0, r6, r1
	str r7, [r0, #0x00]
	adds r2, #0x06
	adds r0, r6, r2
	str r7, [r0, #0x00]
	subs r1, #0x0C
	adds r0, r6, r1
	str r7, [r0, #0x00]
	subs r2, #0x0C
	adds r0, r6, r2
	str r7, [r0, #0x00]
	adds r1, #0x14
	adds r0, r6, r1
	str r7, [r0, #0x00]
	adds r2, #0x14
	adds r0, r6, r2
	str r7, [r0, #0x00]
	adds r1, #0x08
	adds r0, r6, r1
	str r7, [r0, #0x00]
	adds r2, #0x14
	adds r1, r6, r2
	ldr r0, _0800E2FC @ =0x0000FFF0
	strh r0, [r1, #0x00]
	movs r1, #0xBE
	lsls r1, r1, #0x01
	adds r0, r6, r1
	mov r2, r10
	strh r2, [r0, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x14
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	adds r4, r6, #0x0
	adds r4, #0x2C
	adds r0, r4, #0x0
	movs r1, #0x03
	bl TaskPoolInit
	ldr r1, _0800E300 @ =0x09EDAE88
	adds r0, r4, #0x0
	mov r2, r8
	bl TaskCreate
	ldr r1, _0800E304 @ =0x09EDB3F8
	adds r0, r4, #0x0
	mov r2, r8
	bl TaskCreate
	movs r0, #0xB8
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0x0C
	str r0, [r1, #0x00]
	movs r1, #0xB4
	lsls r1, r1, #0x01
	adds r0, r6, r1
	subs r1, #0x68
	str r1, [r0, #0x00]
	movs r2, #0xB6
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r1, [r0, #0x00]
	str r7, [r6, #0x0C]
	str r7, [r6, #0x10]
	adds r1, #0x84
	adds r0, r6, r1
	str r7, [r0, #0x00]
	ldr r0, _0800E308 @ =0x02039B9C
	ldr r1, [r0, #0x00]
	mov r2, r8
	str r2, [r1, #0x7C]
	ldr r2, _0800E2F8 @ =0x02039B84
	ldr r0, [r2, #0x00]
	adds r0, #0xA8
	mov r2, r8
	str r2, [r0, #0x00]
	movs r2, #0x92
	lsls r2, r2, #0x01
	adds r0, r6, r2
	str r1, [r0, #0x00]
	mov r2, r8
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	ldr r2, _0800E30C @ =0x00000000
	ldr r3, _0800E310 @ =0x00000240
	orrs r1, r3
	mov r2, r8
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800E2EC: .4byte 0x00018100
_0800E2F0: .4byte 0x00000000
_0800E2F4: .4byte 0x00400000
_0800E2F8: .4byte 0x02039B84
_0800E2FC: .4byte 0x0000FFF0
_0800E300: .4byte 0x09EDAE88
_0800E304: .4byte 0x09EDB3F8
_0800E308: .4byte 0x02039B9C
_0800E30C: .4byte 0x00000000
_0800E310: .4byte 0x00000240
.syntax divided
