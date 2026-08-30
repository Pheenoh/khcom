.syntax unified
	.align 2, 0
	.global func_0805A7D0
	.thumb
	.thumb_func
	.type func_0805A7D0, %function
func_0805A7D0: @ 0805A7D0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	ldr r4, _0805A848 @ =0x02034934
	ldr r1, [r4, #0x00]
	ldr r2, _0805A84C @ =0x00000C72
	adds r0, r1, r2
	ldr r3, _0805A850 @ =0x00000C74
	adds r1, r1, r3
	ldrh r0, [r0, #0x00]
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	bl func_0805A484
	ldr r5, [r4, #0x00]
	ldr r4, _0805A854 @ =0x00000CB8
	adds r0, r5, r4
	ldr r6, [r0, #0x00]
	cmp r6, #0x00
	beq _0805A868
	ldr r1, _0805A858 @ =0x00000C78
	adds r0, r5, r1
	movs r2, #0x00
	ldsh r0, [r0, r2]
	ldr r3, _0805A85C @ =0x00000C76
	adds r1, r5, r3
	movs r4, #0x00
	ldsh r1, [r1, r4]
	adds r3, #0x3E
	adds r2, r5, r3
	lsls r3, r7, #0x10
	asrs r3, r3, #0x10
	lsls r4, r3, #0x02
	ldr r2, [r2, #0x00]
	adds r2, r2, r4
	lsls r3, r3, #0x01
	adds r3, r6, r3
	movs r4, #0x00
	str r4, [sp, #0x000]
	ldr r6, _0805A860 @ =0x00000CAE
	adds r4, r5, r6
	movs r6, #0x00
	ldsh r4, [r4, r6]
	str r4, [sp, #0x004]
	movs r6, #0xCB
	lsls r6, r6, #0x04
	adds r4, r5, r6
	movs r6, #0x00
	ldsh r4, [r4, r6]
	str r4, [sp, #0x008]
	ldr r6, _0805A864 @ =0x00000CB2
	adds r4, r5, r6
	movs r5, #0x00
	ldsh r4, [r4, r5]
	str r4, [sp, #0x00C]
	bl func_0805A698
	b _0805A8B6
	.byte 0x00, 0x00
_0805A848: .4byte 0x02034934
_0805A84C: .4byte 0x00000C72
_0805A850: .4byte 0x00000C74
_0805A854: .4byte 0x00000CB8
_0805A858: .4byte 0x00000C78
_0805A85C: .4byte 0x00000C76
_0805A860: .4byte 0x00000CAE
_0805A864: .4byte 0x00000CB2
_0805A868:
	ldr r6, _0805A8C0 @ =0x00000C78
	adds r0, r5, r6
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _0805A8C4 @ =0x00000C76
	adds r1, r5, r2
	movs r3, #0x00
	ldsh r1, [r1, r3]
	ldr r4, _0805A8C8 @ =0x00000CB4
	adds r2, r5, r4
	lsls r4, r7, #0x10
	asrs r4, r4, #0x10
	lsls r3, r4, #0x02
	ldr r2, [r2, #0x00]
	adds r2, r2, r3
	adds r6, #0x44
	adds r3, r5, r6
	lsls r4, r4, #0x01
	ldr r3, [r3, #0x00]
	adds r3, r3, r4
	str r3, [sp, #0x000]
	ldr r4, _0805A8CC @ =0x00000CAE
	adds r3, r5, r4
	movs r6, #0x00
	ldsh r3, [r3, r6]
	str r3, [sp, #0x004]
	adds r4, #0x02
	adds r3, r5, r4
	movs r6, #0x00
	ldsh r3, [r3, r6]
	str r3, [sp, #0x008]
	adds r4, #0x02
	adds r3, r5, r4
	movs r5, #0x00
	ldsh r3, [r3, r5]
	str r3, [sp, #0x00C]
	movs r3, #0x00
	bl func_0805A698
_0805A8B6:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805A8C0: .4byte 0x00000C78
_0805A8C4: .4byte 0x00000C76
_0805A8C8: .4byte 0x00000CB4
_0805A8CC: .4byte 0x00000CAE
.syntax divided
