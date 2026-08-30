.syntax unified
	.align 2, 0
	.global func_0800216C
	.thumb
	.thumb_func
	.type func_0800216C, %function
func_0800216C: @ 0800216C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r2, #0x0
	mov r8, r3
	ldr r2, [sp, #0x020]
	ldr r3, [sp, #0x024]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r7, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r12, r3
	ldr r0, [sp, #0x018]
	cmp r0, #0x00
	beq _08002196
	cmp r5, #0x00
	bne _0800219A
_08002196:
	movs r0, #0x00
	b _080022A6
_0800219A:
	ldr r0, _080022B0 @ =0x030074C8
	ldr r2, [r0, #0x00]
	ldr r1, _080022B4 @ =0x000028A8
	adds r3, r2, r1
	ldrh r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r2, r0
	ldr r1, _080022B8 @ =0x00001AB8
	adds r0, r0, r1
	strh r4, [r0, #0x00]
	ldrh r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r2, r0
	ldr r4, _080022BC @ =0x00001ABA
	adds r0, r0, r4
	strh r6, [r0, #0x00]
	ldrh r0, [r3, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	subs r4, #0x12
	adds r0, r2, r4
	adds r0, r0, r1
	mov r1, r8
	str r1, [r0, #0x00]
	ldrh r0, [r3, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r4, #0x04
	adds r0, r2, r4
	adds r0, r0, r1
	ldr r1, [sp, #0x018]
	str r1, [r0, #0x00]
	ldrh r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r4, #0x04
	adds r1, r2, r4
	adds r1, r1, r0
	ldr r0, [sp, #0x01C]
	str r0, [r1, #0x00]
	ldrh r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r2, r0
	ldr r1, _080022C0 @ =0x00001ABE
	adds r0, r0, r1
	strh r7, [r0, #0x00]
	ldrh r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r0, r2, r0
	adds r4, #0x0C
	adds r0, r0, r4
	mov r1, r12
	strh r1, [r0, #0x00]
	ldrh r1, [r3, #0x00]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	subs r4, #0x08
	adds r2, r2, r4
	adds r2, r2, r0
	str r5, [r2, #0x00]
	mov r1, r8
	ldr r0, [r1, #0x20]
	cmp r0, r5
	beq _0800227E
	str r5, [r1, #0x20]
	ldrh r0, [r5, #0x00]
	adds r5, #0x02
	movs r7, #0x00
	cmp r0, #0x00
	beq _0800227E
	adds r6, r0, #0x0
_08002240:
	ldrh r0, [r5, #0x00]
	ldrh r1, [r5, #0x02]
	bl func_08001DB0
	adds r4, r0, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r0, [r5, #0x04]
	ldr r2, _080022C4 @ =0x000003FF
	adds r1, r2, #0x0
	ands r1, r0
	lsls r1, r1, #0x05
	mov r2, r8
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	ldrh r1, [r2, #0x06]
	adds r1, r1, r7
	lsls r1, r1, #0x05
	ldr r2, _080022C8 @ =0x06010000
	adds r1, r1, r2
	lsls r2, r4, #0x15
	lsrs r2, r2, #0x10
	bl func_080043B4
	adds r4, r7, r4
	lsls r4, r4, #0x10
	lsrs r7, r4, #0x10
	adds r5, #0x06
	subs r6, #0x01
	cmp r6, #0x00
	bne _08002240
_0800227E:
	ldr r0, _080022B0 @ =0x030074C8
	ldr r3, [r0, #0x00]
	ldr r5, _080022B4 @ =0x000028A8
	adds r4, r3, r5
	ldrh r1, [r4, #0x00]
	lsls r0, r1, #0x02
	ldr r5, _080022CC @ =0x000026A8
	adds r2, r3, r5
	adds r2, r2, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080022D0 @ =0x00001AA8
	adds r0, r0, r1
	adds r3, r3, r0
	str r3, [r2, #0x00]
	ldrh r0, [r4, #0x00]
	adds r0, #0x01
	strh r0, [r4, #0x00]
	movs r0, #0x01
_080022A6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080022B0: .4byte 0x030074C8
_080022B4: .4byte 0x000028A8
_080022B8: .4byte 0x00001AB8
_080022BC: .4byte 0x00001ABA
_080022C0: .4byte 0x00001ABE
_080022C4: .4byte 0x000003FF
_080022C8: .4byte 0x06010000
_080022CC: .4byte 0x000026A8
_080022D0: .4byte 0x00001AA8
.syntax divided
