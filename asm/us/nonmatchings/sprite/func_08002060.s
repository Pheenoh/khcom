.syntax unified
	.align 2, 0
	.global func_08002060
	.thumb
	.thumb_func
	.type func_08002060, %function
func_08002060: @ 08002060
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r12, r2
	adds r7, r3, #0x0
	ldr r2, [sp, #0x020]
	ldr r3, [sp, #0x024]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r8, r3
	ldr r0, [sp, #0x018]
	cmp r0, #0x00
	beq _08002160
	mov r1, r12
	cmp r1, #0x00
	beq _08002160
	ldr r0, _0800213C @ =0x030074C8
	ldr r3, [r0, #0x00]
	ldr r0, _08002140 @ =0x000028A8
	adds r4, r3, r0
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r1, _08002144 @ =0x00001AB8
	adds r0, r0, r1
	strh r5, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r1, _08002148 @ =0x00001ABA
	adds r0, r0, r1
	strh r6, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r5, _0800214C @ =0x00001AA8
	adds r0, r3, r5
	adds r0, r0, r1
	str r7, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r6, _08002150 @ =0x00001AAC
	adds r0, r3, r6
	adds r0, r0, r1
	ldr r1, [sp, #0x018]
	str r1, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r6, #0x04
	adds r1, r3, r6
	adds r1, r1, r0
	ldr r0, [sp, #0x01C]
	str r0, [r1, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r1, _08002154 @ =0x00001ABE
	adds r0, r0, r1
	strh r2, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r3, r0
	ldr r2, _08002158 @ =0x00001ABC
	adds r0, r0, r2
	mov r6, r8
	strh r6, [r0, #0x00]
	ldrh r0, [r4, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	subs r2, #0x08
	adds r0, r3, r2
	adds r0, r0, r1
	mov r6, r12
	str r6, [r0, #0x00]
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x02
	ldr r6, _0800215C @ =0x000026A8
	adds r2, r3, r6
	adds r2, r2, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r0, r5
	adds r3, r3, r0
	str r3, [r2, #0x00]
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	movs r0, #0x01
	b _08002162
_0800213C: .4byte 0x030074C8
_08002140: .4byte 0x000028A8
_08002144: .4byte 0x00001AB8
_08002148: .4byte 0x00001ABA
_0800214C: .4byte 0x00001AA8
_08002150: .4byte 0x00001AAC
_08002154: .4byte 0x00001ABE
_08002158: .4byte 0x00001ABC
_0800215C: .4byte 0x000026A8
_08002160:
	movs r0, #0x00
_08002162:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
