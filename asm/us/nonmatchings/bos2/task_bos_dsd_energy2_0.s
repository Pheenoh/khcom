.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy2_0
	.thumb
	.thumb_func
	.type task_bos_dsd_energy2_0, %function
task_bos_dsd_energy2_0: @ 080C4DB0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x008
	adds r6, r0, #0x0
	str r1, [r6, #0x00]
	movs r0, #0xBC
	lsls r0, r0, #0x08
	str r0, [r6, #0x04]
	movs r0, #0xB4
	lsls r0, r0, #0x09
	str r0, [r6, #0x08]
	ldr r0, _080C4E28 @ =0xFFFFD400
	str r0, [r6, #0x0C]
	movs r1, #0x00
	movs r5, #0x00
	strh r5, [r6, #0x2C]
	strh r5, [r6, #0x2E]
	strh r5, [r6, #0x30]
	movs r0, #0x0F
	strh r0, [r6, #0x32]
	movs r0, #0x80
	str r0, [r6, #0x10]
	str r0, [r6, #0x14]
	str r5, [r6, #0x20]
	str r5, [r6, #0x24]
	ldr r0, _080C4E2C @ =0xFFFFFB00
	str r0, [r6, #0x28]
	adds r0, r6, #0x0
	adds r0, #0x34
	strb r1, [r0, #0x00]
	adds r0, #0x08
	strb r1, [r0, #0x00]
	ldr r0, _080C4E30 @ =0x08B22CBC
	str r0, [r6, #0x38]
	ldr r0, [r6, #0x04]
	ldr r1, [r6, #0x08]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x10]
	movs r7, #0x32
	ldsh r4, [r6, r7]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	bl func_08014588
	movs r0, #0xB0
	lsls r0, r0, #0x02
	bl m4aSongNumStart
	ldr r0, [r6, #0x00]
	ldr r1, _080C4E34 @ =0x0000035A
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080C4E38
	cmp r0, #0x01
	ble _080C4E48
	cmp r0, #0x02
	beq _080C4E40
	b _080C4E48
_080C4E28: .4byte 0xFFFFD400
_080C4E2C: .4byte 0xFFFFFB00
_080C4E30: .4byte 0x08B22CBC
_080C4E34: .4byte 0x0000035A
_080C4E38:
	adds r1, r6, #0x0
	adds r1, #0x35
	movs r0, #0x05
	b _080C4E4E
_080C4E40:
	adds r1, r6, #0x0
	adds r1, #0x35
	movs r0, #0x07
	b _080C4E4E
_080C4E48:
	adds r1, r6, #0x0
	adds r1, #0x35
	movs r0, #0x03
_080C4E4E:
	strb r0, [r1, #0x00]
	add sp, #0x008
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
