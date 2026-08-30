.syntax unified
	.align 2, 0
	.global task_hum_hook_bomb_1
	.thumb
	.thumb_func
	.type task_hum_hook_bomb_1, %function
task_hum_hook_bomb_1: @ 0804CCCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x00C
	adds r6, r0, #0x0
	ldr r0, _0804CD5C @ =0x02039B84
	mov r8, r0
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	movs r7, #0x00
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0804CCF0
	b _0804CED0
_0804CCF0:
	ldr r0, [r6, #0x38]
	cmp r0, #0x00
	bne _0804CDD6
	ldr r3, _0804CD60 @ =0x08121400
	adds r4, r6, #0x0
	adds r4, #0x34
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, [r6, #0x50]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x20]
	adds r0, r0, r1
	str r0, [r6, #0x20]
	ldrb r0, [r4, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r3, #0x00
	ldsh r0, [r0, r3]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x24]
	adds r0, r0, r1
	str r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	ldr r0, [r6, #0x30]
	adds r1, r1, r0
	str r1, [r6, #0x28]
	adds r0, #0x40
	str r0, [r6, #0x30]
	cmp r1, #0x00
	ble _0804CDB4
	str r7, [r6, #0x28]
	adds r1, r6, #0x0
	adds r1, #0x4A
	adds r0, r6, #0x0
	adds r0, #0x4C
	movs r5, #0x00
	ldsh r2, [r1, r5]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	adds r5, r1, #0x0
	cmp r2, r0
	blt _0804CD64
	strh r7, [r6, #0x3C]
	b _0804CDD0
	.byte 0x00, 0x00
_0804CD5C: .4byte 0x02039B84
_0804CD60: .4byte 0x08121400
_0804CD64:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0804CDA4 @ =0x00000301
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r7, #0x80
	lsls r7, r7, #0x02
	adds r0, r0, r7
	negs r0, r0
	str r0, [r6, #0x30]
	adds r0, r6, #0x0
	adds r0, #0x4E
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0804CDA8
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	mov r2, r8
	ldr r3, [r2, #0x00]
	subs r7, #0xD0
	adds r2, r3, r7
	ldr r2, [r2, #0x00]
	adds r7, #0x04
	adds r3, r3, r7
	ldr r3, [r3, #0x00]
	bl func_0801CB6C
	b _0804CDAC
_0804CDA4: .4byte 0x00000301
_0804CDA8:
	bl func_080065A4
_0804CDAC:
	strb r0, [r4, #0x00]
	ldrh r0, [r5, #0x00]
	adds r0, #0x01
	strh r0, [r5, #0x00]
_0804CDB4:
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x28]
	movs r3, #0x02
	str r3, [sp, #0x000]
	str r3, [sp, #0x004]
	bl func_08011E3C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0804CDCC
	b _0804CED8
_0804CDCC:
	movs r0, #0x00
	strh r0, [r6, #0x3C]
_0804CDD0:
	movs r0, #0x01
	str r0, [r6, #0x38]
	b _0804CEDE
_0804CDD6:
	movs r1, #0x3C
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	bne _0804CDEA
	adds r0, r6, #0x0
	adds r0, #0x08
	movs r1, #0x01
	movs r2, #0x00
	bl func_080059A4
_0804CDEA:
	movs r2, #0x3C
	ldsh r0, [r6, r2]
	cmp r0, #0x11
	bgt _0804CE80
	ldr r3, _0804CE78 @ =0x08121400
	adds r4, r6, #0x0
	adds r4, #0x34
	ldrb r0, [r4, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r5, #0x00
	ldsh r0, [r0, r5]
	ldr r2, [r6, #0x50]
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x20]
	adds r0, r0, r1
	str r0, [r6, #0x20]
	ldrb r0, [r4, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r3
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r2
	asrs r1, r1, #0x08
	ldr r0, [r6, #0x24]
	adds r0, r0, r1
	str r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	ldr r0, [r6, #0x30]
	adds r1, r1, r0
	str r1, [r6, #0x28]
	adds r0, #0x40
	str r0, [r6, #0x30]
	cmp r1, #0x00
	ble _0804CEBE
	str r7, [r6, #0x28]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0804CE7C @ =0x00000301
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r0, r2
	negs r0, r0
	str r0, [r6, #0x30]
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	mov r5, r8
	ldr r3, [r5, #0x00]
	movs r7, #0x98
	lsls r7, r7, #0x01
	adds r2, r3, r7
	ldr r2, [r2, #0x00]
	movs r5, #0x9A
	lsls r5, r5, #0x01
	adds r3, r3, r5
	ldr r3, [r3, #0x00]
	bl func_0801CB6C
	strb r0, [r4, #0x00]
	b _0804CEBE
_0804CE78: .4byte 0x08121400
_0804CE7C: .4byte 0x00000301
_0804CE80:
	cmp r0, #0x12
	bne _0804CE9A
	bl func_08019A30
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x28]
	bl func_08014020
	adds r0, r6, #0x0
	adds r0, #0x48
	strb r7, [r0, #0x00]
	b _0804CEBE
_0804CE9A:
	cmp r0, #0x12
	ble _0804CEBE
	ldr r0, _0804CED4 @ =0x00000117
	ldr r1, [r6, #0x20]
	ldr r2, [r6, #0x24]
	ldr r3, [r6, #0x28]
	movs r4, #0x18
	str r4, [sp, #0x000]
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	bl func_08011F78
	cmp r0, #0x00
	beq _0804CEBE
	movs r0, #0x99
	lsls r0, r0, #0x02
	bl func_0811FE70
_0804CEBE:
	movs r7, #0x3C
	ldsh r0, [r6, r7]
	cmp r0, #0x11
	ble _0804CED8
	bl func_080128EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0804CED8
_0804CED0:
	movs r0, #0x00
	b _0804CF16
_0804CED4: .4byte 0x00000117
_0804CED8:
	ldrh r0, [r6, #0x3C]
	adds r0, #0x01
	strh r0, [r6, #0x3C]
_0804CEDE:
	adds r0, r6, #0x0
	adds r0, #0x20
	adds r1, r6, #0x0
	adds r1, #0x24
	movs r2, #0x00
	movs r3, #0x00
	bl func_0801A8A4
	cmp r0, #0x00
	beq _0804CF0C
	bl func_080065A4
	adds r5, r6, #0x0
	adds r5, #0x34
	ldrb r4, [r5, #0x00]
	adds r4, #0x76
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x15
	bl func_0811D7CC
	adds r0, r0, r4
	strb r0, [r5, #0x00]
_0804CF0C:
	adds r0, r6, #0x0
	adds r0, #0x08
	bl func_08005A64
	movs r0, #0x01
_0804CF16:
	add sp, #0x00C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
