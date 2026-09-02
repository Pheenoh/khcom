.syntax unified
	.align 2, 0
	.global func_080165DC
	.thumb
	.thumb_func
	.type func_080165DC, %function
func_080165DC: @ 080165DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x008
	adds r7, r0, #0x0
	adds r5, r1, #0x0
	adds r6, r2, #0x0
	movs r0, #0x00
	bl func_080126E4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x00
	bne _08016662
	bl func_08012674
	ldr r0, _08016670 @ =0x02034928
	mov r8, r0
	ldr r0, [r0, #0x00]
	str r7, [r0, #0x10]
	str r5, [r0, #0x14]
	str r6, [r0, #0x18]
	str r6, [r0, #0x30]
	strh r4, [r0, #0x26]
	movs r1, #0x32
	strh r1, [r0, #0x0A]
	mov r4, sp
	adds r4, #0x06
	str r6, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r4, #0x0
	adds r2, r7, #0x0
	adds r3, r5, #0x0
	bl WorldToScreen
	ldr r0, _08016674 @ =0x09EDAA20
	add r1, sp, #0x004
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r3, #0x00
	ldsh r2, [r4, r3]
	bl func_08006778
	mov r0, r8
	ldr r1, [r0, #0x00]
	movs r0, #0x59
	str r0, [r1, #0x1C]
	str r0, [r1, #0x20]
	ldr r0, _08016678 @ =0x08016469
	str r0, [r1, #0x04]
	ldr r0, _0801667C @ =0x00000297
	bl m4aSongNumStart
	ldr r0, _08016680 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xB3
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	movs r2, #0x08
	bl func_08006238
	mov r1, r8
	ldr r2, [r1, #0x00]
	ldrh r1, [r2, #0x34]
	movs r0, #0x08
	orrs r0, r1
	strh r0, [r2, #0x34]
_08016662:
	add sp, #0x008
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08016670: .4byte 0x02034928
_08016674: .4byte 0x09EDAA20
_08016678: .4byte 0x08016469
_0801667C: .4byte 0x00000297
_08016680: .4byte 0x02039B84
.syntax divided
