.syntax unified
	.align 2, 0
	.global task_bos_md_0
	.thumb
	.thumb_func
	.type task_bos_md_0, %function
task_bos_md_0: @ 080FC444
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x00C
	adds r7, r0, #0x0
	ldr r4, _080FC5B4 @ =0x02039B84
	ldr r0, [r4, #0x00]
	adds r0, #0x40
	ldr r1, _080FC5B8 @ =0x09EF8EC4
	ldr r2, _080FC5BC @ =0x099920E8
	bl func_08000E14
	ldr r3, [r4, #0x00]
	ldr r0, [r3, #0x68]
	ldr r1, [r3, #0x6C]
	ldr r2, _080FC5C0 @ =0xFFEFFFFF
	ands r0, r2
	str r0, [r3, #0x68]
	str r1, [r3, #0x6C]
	movs r0, #0x00
	str r0, [r7, #0x00]
	str r0, [r7, #0x04]
	strh r0, [r7, #0x14]
	str r0, [r7, #0x08]
	strh r0, [r7, #0x16]
	strh r0, [r7, #0x18]
	strh r0, [r7, #0x1A]
	movs r2, #0xDA
	lsls r2, r2, #0x01
	adds r1, r7, r2
	strh r0, [r1, #0x00]
	movs r0, #0x01
	strb r0, [r7, #0x1C]
	movs r6, #0x00
	adds r2, r7, #0x0
	adds r2, #0x10
	movs r3, #0x00
_080FC492:
	lsls r1, r6, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x02
	adds r0, r2, r0
	str r3, [r0, #0x00]
	adds r1, #0x01
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	cmp r1, #0x00
	ble _080FC492
	movs r6, #0x00
	movs r3, #0x2C
	adds r3, r3, r7
	mov r10, r3
	adds r0, r7, #0x0
	adds r0, #0x40
	str r0, [sp, #0x004]
	adds r1, r7, #0x0
	adds r1, #0x54
	str r1, [sp, #0x008]
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0x00
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r5, r7, r0
	movs r1, #0xC2
	lsls r1, r1, #0x01
	adds r4, r7, r1
	movs r2, #0xC4
	lsls r2, r2, #0x01
	mov r9, r2
_080FC4D6:
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x02
	mov r6, r8
	adds r1, r6, r0
	str r3, [r1, #0x00]
	adds r1, r5, r0
	str r3, [r1, #0x00]
	adds r1, r4, r0
	str r3, [r1, #0x00]
	adds r0, r7, r0
	mov r6, r9
	adds r1, r0, r6
	strh r3, [r1, #0x00]
	movs r1, #0xC5
	lsls r1, r1, #0x01
	adds r0, r0, r1
	strh r3, [r0, #0x00]
	adds r2, #0x01
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0x01
	ble _080FC4D6
	movs r0, #0x98
	lsls r0, r0, #0x04
	bl func_080038C8
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	ldr r0, _080FC5C4 @ =0x099D42FC
	movs r1, #0x95
	lsls r1, r1, #0x05
	bl func_080026A4
	movs r3, #0xC8
	lsls r3, r3, #0x01
	adds r1, r7, r3
	str r0, [r1, #0x00]
	ldr r0, _080FC5B4 @ =0x02039B84
	ldr r3, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xCC
	movs r0, #0x88
	lsls r0, r0, #0x09
	str r0, [r1, #0x00]
	adds r2, r3, #0x0
	adds r2, #0xD0
	movs r0, #0xA8
	lsls r0, r0, #0x09
	str r0, [r2, #0x00]
	adds r1, #0x08
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r0, #0xF0
	lsls r0, r0, #0x07
	ldr r1, [r2, #0x00]
	movs r2, #0x00
	bl func_0801BCC0
	movs r6, #0x00
	movs r0, #0x9C
	adds r0, r0, r7
	mov r9, r0
_080FC55E:
	lsls r6, r6, #0x10
	asrs r5, r6, #0x10
	lsls r0, r5, #0x04
	adds r0, r0, r5
	lsls r0, r0, #0x04
	mov r8, r0
	mov r4, r8
	adds r4, #0x68
	adds r4, r7, r4
	ldr r0, _080FC5B4 @ =0x02039B84
	ldr r1, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0xCC
	ldr r2, [r0, #0x00]
	adds r0, #0x04
	ldr r3, [r0, #0x00]
	adds r0, #0x04
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	ldr r1, _080FC5C8 @ =0x099920D8
	bl func_0801B37C
	adds r4, #0x40
	adds r0, r4, #0x0
	movs r1, #0x08
	movs r2, #0x10
	movs r3, #0x10
	bl func_080122AC
	cmp r5, #0x00
	bne _080FC5D4
	mov r2, r9
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x04]
	ldr r2, _080FC5CC @ =0x00000400
	ldr r3, _080FC5D0 @ =0x00000000
	orrs r0, r2
	mov r3, r9
	str r0, [r3, #0x00]
	str r1, [r3, #0x04]
	b _080FC5E8
	.byte 0x00, 0x00
_080FC5B4: .4byte 0x02039B84
_080FC5B8: .4byte 0x09EF8EC4
_080FC5BC: .4byte 0x099920E8
_080FC5C0: .4byte 0xFFEFFFFF
_080FC5C4: .4byte 0x099D42FC
_080FC5C8: .4byte 0x099920D8
_080FC5CC: .4byte 0x00000400
_080FC5D0: .4byte 0x00000000
_080FC5D4:
	mov r1, r8
	adds r0, r7, r1
	adds r0, #0x9C
	ldr r1, [r0, #0x00]
	ldr r2, [r0, #0x04]
	ldr r4, _080FC6C4 @ =0x00000000
	ldr r3, _080FC6C0 @ =0x00001000
	orrs r1, r3
	str r1, [r0, #0x00]
	str r2, [r0, #0x04]
_080FC5E8:
	asrs r5, r6, #0x10
	lsls r2, r5, #0x04
	adds r2, r2, r5
	lsls r2, r2, #0x04
	adds r2, r7, r2
	adds r2, #0x9C
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x04]
	movs r3, #0x04
	movs r4, #0x00
	orrs r0, r3
	str r0, [r2, #0x00]
	str r1, [r2, #0x04]
	adds r5, #0x01
	lsls r5, r5, #0x10
	lsrs r6, r5, #0x10
	cmp r5, #0x00
	ble _080FC55E
	adds r0, r7, #0x0
	movs r1, #0x00
	bl func_080FB930
	adds r0, r7, #0x0
	movs r1, #0x00
	bl func_080FBA14
	ldr r4, _080FC6C8 @ =0x09A3C97C
	movs r1, #0xA0
	lsls r1, r1, #0x13
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_08005BE8
	movs r0, #0x00
	movs r1, #0x01
	bl func_0801C298
	str r4, [r7, #0x28]
	adds r0, r4, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x20]
	ldrb r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x01
	bl func_0801C298
	ldr r0, _080FC6CC @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r7, #0x24]
	ldrb r0, [r0, #0x06]
	adds r0, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x01
	bl func_0801C298
	mov r0, r10
	movs r1, #0x06
	bl func_08000E64
	ldr r0, [sp, #0x004]
	movs r1, #0x01
	bl func_08000E64
	ldr r0, [sp, #0x008]
	movs r1, #0x08
	bl func_08000E64
	ldr r0, _080FC6D0 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x00]
	asrs r1, r1, #0x08
	adds r1, #0x48
	movs r3, #0xBC
	lsls r3, r3, #0x01
	adds r0, r7, r3
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [r2, #0x04]
	asrs r2, r2, #0x08
	adds r2, #0x30
	movs r6, #0xBD
	lsls r6, r6, #0x01
	adds r0, r7, r6
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	add sp, #0x00C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FC6C0: .4byte 0x00001000
_080FC6C4: .4byte 0x00000000
_080FC6C8: .4byte 0x09A3C97C
_080FC6CC: .4byte 0x08F69BC4
_080FC6D0: .4byte 0x02039B84
.syntax divided
