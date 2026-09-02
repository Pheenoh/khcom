.syntax unified
	.align 2, 0
	.global func_08002488
	.thumb
	.thumb_func
	.type func_08002488, %function
func_08002488: @ 08002488
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r2
	adds r7, r3, #0x0
	ldr r2, [sp, #0x01C]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r12, r2
	ldr r0, _08002568 @ =0x030074C8
	ldr r5, [r0, #0x00]
	ldr r0, _0800256C @ =0x000028A8
	adds r4, r5, r0
	ldrh r0, [r4, #0x00]
	cmp r0, #0x7F
	bhi _0800255E
	adds r1, r0, #0x0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r5, r0
	ldr r1, _08002570 @ =0x00001AB8
	adds r0, r0, r1
	movs r2, #0x00
	strh r3, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r5, r0
	ldr r1, _08002574 @ =0x00001ABA
	adds r0, r0, r1
	strh r6, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r3, _08002578 @ =0x00001AA8
	adds r0, r5, r3
	adds r0, r0, r1
	str r7, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r6, _0800257C @ =0x00001AAC
	adds r1, r5, r6
	adds r1, r1, r0
	ldr r0, [sp, #0x018]
	str r0, [r1, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r6, #0x04
	adds r0, r5, r6
	adds r0, r0, r1
	str r2, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r5, r0
	ldr r1, _08002580 @ =0x00001ABE
	adds r0, r0, r1
	mov r6, r12
	strh r6, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r5, r0
	ldr r1, _08002584 @ =0x00001ABC
	adds r0, r0, r1
	strh r2, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r2, _08002588 @ =0x00001AB4
	adds r0, r5, r2
	adds r0, r0, r1
	mov r6, r8
	str r6, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x02
	ldr r6, _0800258C @ =0x000026A8
	adds r2, r5, r6
	adds r2, r2, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r3
	adds r0, r5, r0
	str r0, [r2, #0x00]
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	ldr r0, _08002590 @ =0x000028AA
	adds r1, r5, r0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_0800255E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08002568: .4byte 0x030074C8
_0800256C: .4byte 0x000028A8
_08002570: .4byte 0x00001AB8
_08002574: .4byte 0x00001ABA
_08002578: .4byte 0x00001AA8
_0800257C: .4byte 0x00001AAC
_08002580: .4byte 0x00001ABE
_08002584: .4byte 0x00001ABC
_08002588: .4byte 0x00001AB4
_0800258C: .4byte 0x000026A8
_08002590: .4byte 0x000028AA
.syntax divided
