.syntax unified
	.align 2, 0
	.global func_08018F28
	.thumb
	.thumb_func
	.type func_08018F28, %function
func_08018F28: @ 08018F28
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08018FCA
	bl func_08012674
	ldr r7, _08018F84 @ =0x02034928
	ldr r0, [r7, #0x00]
	str r4, [r0, #0x10]
	str r5, [r0, #0x14]
	str r6, [r0, #0x18]
	ldr r0, _08018F88 @ =0x000002C1
	bl m4aSongNumStart
	mov r4, sp
	adds r4, #0x06
	ldr r0, [r7, #0x00]
	ldr r2, [r0, #0x10]
	ldr r3, [r0, #0x14]
	ldr r0, [r0, #0x18]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	bl WorldToScreen
	bl GetRandom
	ldr r2, [r7, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	strh r0, [r2, #0x26]
	ldrh r0, [r2, #0x26]
	cmp r0, #0x00
	beq _08018F8C
	cmp r0, #0x01
	beq _08018FA4
	b _08018FC2
_08018F84: .4byte 0x02034928
_08018F88: .4byte 0x000002C1
_08018F8C:
	ldr r0, _08018FA0 @ =0x09EDAD98
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	b _08018FC2
	.byte 0x00, 0x00
_08018FA0: .4byte 0x09EDAD98
_08018FA4:
	ldr r0, _08018FD4 @ =0x09EDAD98
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	ldr r2, [r7, #0x00]
	ldrh r0, [r2, #0x34]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x34]
	ldr r0, _08018FD8 @ =0xFFFFFF00
	str r0, [r2, #0x1C]
_08018FC2:
	ldr r0, _08018FDC @ =0x02034928
	ldr r1, [r0, #0x00]
	ldr r0, _08018FE0 @ =0x08018CC5
	str r0, [r1, #0x04]
_08018FCA:
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08018FD4: .4byte 0x09EDAD98
_08018FD8: .4byte 0xFFFFFF00
_08018FDC: .4byte 0x02034928
_08018FE0: .4byte 0x08018CC5
.syntax divided
