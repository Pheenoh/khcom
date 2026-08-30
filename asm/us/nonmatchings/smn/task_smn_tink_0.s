.syntax unified
	.align 2, 0
	.global task_smn_tink_0
	.thumb
	.thumb_func
	.type task_smn_tink_0, %function
task_smn_tink_0: @ 080426B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x004
	adds r6, r0, #0x0
	mov r8, r1
	adds r7, r6, #0x0
	adds r7, #0x38
	ldrb r1, [r1, #0x02]
	cmp r1, #0x00
	beq _080426FC
	ldr r0, _080426EC @ =0x00000153
	adds r1, r6, r0
	movs r0, #0x01
	strb r0, [r1, #0x00]
	ldr r0, _080426F0 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _080426F4 @ =0x00200000
	ldr r3, _080426F8 @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	movs r2, #0x8A
	lsls r2, r2, #0x01
	adds r4, r4, r2
	ldr r0, [r4, #0x00]
	b _08042722
_080426EC: .4byte 0x00000153
_080426F0: .4byte 0x02039B84
_080426F4: .4byte 0x00200000
_080426F8: .4byte 0x00000000
_080426FC:
	ldr r3, _08042750 @ =0x00000153
	adds r0, r6, r3
	strb r1, [r0, #0x00]
	ldr r0, _08042754 @ =0x02039B9C
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _08042758 @ =0x00200000
	ldr r3, _0804275C @ =0x00000000
	orrs r0, r2
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	ldr r1, [r4, #0x7C]
	ldr r0, _08042760 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r5, #0x8A
	lsls r5, r5, #0x01
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
_08042722:
	str r0, [r6, #0x00]
	ldr r0, [r1, #0x14]
	str r0, [r7, #0x04]
	ldr r0, [r1, #0x18]
	str r0, [r7, #0x08]
	ldr r0, [r1, #0x1C]
	ldr r2, _08042764 @ =0xFFFFD000
	adds r0, r0, r2
	str r0, [r7, #0x0C]
	ldr r0, [r1, #0x1C]
	str r0, [r7, #0x10]
	ldr r0, [r1, #0x34]
	ldr r1, [r1, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08042770
	ldr r0, _08042768 @ =0x00080004
	ldr r1, _0804276C @ =0x00000000
	b _08042774
	.byte 0x00, 0x00
_08042750: .4byte 0x00000153
_08042754: .4byte 0x02039B9C
_08042758: .4byte 0x00200000
_0804275C: .4byte 0x00000000
_08042760: .4byte 0x02039B84
_08042764: .4byte 0xFFFFD000
_08042768: .4byte 0x00080004
_0804276C: .4byte 0x00000000
_08042770:
	ldr r1, _08042800 @ =0x00000000
	ldr r0, _080427FC @ =0x00080000
_08042774:
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	mov r3, r8
	ldrh r0, [r3, #0x00]
	movs r5, #0xA9
	lsls r5, r5, #0x01
	adds r1, r6, r5
	movs r4, #0x00
	strb r0, [r1, #0x00]
	ldr r0, _08042804 @ =0x09618098
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	adds r5, r6, #0x0
	adds r5, #0x08
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_08005968
	ldr r0, _08042808 @ =0x0813EA08
	ldr r1, [r6, #0x00]
	str r1, [sp, #0x000]
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x01
	bl func_08019068
	str r4, [r6, #0x34]
	movs r1, #0xA4
	lsls r1, r1, #0x01
	adds r0, r6, r1
	movs r2, #0x00
	strh r4, [r0, #0x00]
	movs r3, #0xA5
	lsls r3, r3, #0x01
	adds r0, r6, r3
	strh r4, [r0, #0x00]
	movs r5, #0xA6
	lsls r5, r5, #0x01
	adds r1, r6, r5
	movs r0, #0x0A
	str r0, [r1, #0x00]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	strb r2, [r0, #0x00]
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strh r4, [r0, #0x00]
	adds r3, #0x22
	adds r0, r6, r3
	strh r4, [r0, #0x00]
	adds r5, #0x24
	adds r0, r6, r5
	strh r4, [r0, #0x00]
	subs r1, #0x01
	adds r0, r6, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08042810
	adds r2, #0x2C
	adds r1, r6, r2
	ldr r0, _0804280C @ =0x02039B84
	b _08042818
	.byte 0x00, 0x00
_080427FC: .4byte 0x00080000
_08042800: .4byte 0x00000000
_08042804: .4byte 0x09618098
_08042808: .4byte 0x0813EA08
_0804280C: .4byte 0x02039B84
_08042810:
	movs r3, #0xBE
	lsls r3, r3, #0x01
	adds r1, r6, r3
	ldr r0, _08042858 @ =0x02039B9C
_08042818:
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	str r0, [r1, #0x00]
	movs r0, #0xAB
	bl func_0811FE70
	movs r5, #0xBC
	lsls r5, r5, #0x01
	adds r1, r6, r5
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldr r0, [r0, #0x00]
	movs r3, #0x2C
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x08
	str r0, [r1, #0x00]
	mov r5, r8
	ldrh r0, [r5, #0x00]
	cmp r0, #0x01
	beq _0804285C
	cmp r0, #0x01
	bgt _0804286A
	cmp r0, #0x00
	bne _0804286A
	movs r3, #0x4C
	movs r0, #0xB7
	lsls r0, r0, #0x01
	adds r1, r6, r0
	movs r0, #0xB4
	b _08042878
	.byte 0x00, 0x00
_08042858: .4byte 0x02039B9C
_0804285C:
	movs r3, #0x99
	movs r2, #0xB7
	lsls r2, r2, #0x01
	adds r1, r6, r2
	movs r0, #0x96
	lsls r0, r0, #0x01
	b _08042878
_0804286A:
	movs r3, #0x80
	lsls r3, r3, #0x01
	movs r5, #0xB7
	lsls r5, r5, #0x01
	adds r1, r6, r5
	movs r0, #0xD2
	lsls r0, r0, #0x01
_08042878:
	strh r0, [r1, #0x00]
	movs r0, #0xBE
	lsls r0, r0, #0x01
	adds r4, r6, r0
	ldr r1, [r4, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xE4
	ldr r0, [r0, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	cmp r0, #0x27
	bne _08042898
	movs r0, #0xA6
	lsls r0, r0, #0x01
	muls r0, r3
	asrs r3, r0, #0x08
_08042898:
	movs r5, #0xBA
	lsls r5, r5, #0x01
	adds r2, r6, r5
	movs r5, #0x2E
	ldsh r0, [r1, r5]
	adds r1, r0, #0x0
	muls r1, r3
	movs r3, #0xBC
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r0, [r0, #0x00]
	adds r1, r1, r0
	str r1, [r2, #0x00]
	ldr r0, [r4, #0x00]
	movs r5, #0x2E
	ldsh r0, [r0, r5]
	lsls r0, r0, #0x08
	cmp r1, r0
	ble _080428C0
	str r0, [r2, #0x00]
_080428C0:
	adds r4, r6, #0x0
	adds r4, #0x20
	adds r0, r4, #0x0
	movs r1, #0x0F
	bl func_08000E64
	ldr r1, _080428E4 @ =0x09EDAE88
	adds r0, r4, #0x0
	adds r2, r7, #0x0
	bl func_08000E14
	add sp, #0x004
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080428E4: .4byte 0x09EDAE88
.syntax divided
