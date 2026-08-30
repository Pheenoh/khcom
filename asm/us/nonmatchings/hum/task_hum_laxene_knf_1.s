.syntax unified
	.align 2, 0
	.global task_hum_laxene_knf_1
	.thumb
	.thumb_func
	.type task_hum_laxene_knf_1, %function
task_hum_laxene_knf_1: @ 080524D0
	push {r4, r5, r6, r7, lr}
	add sp, #-0x00C
	adds r5, r0, #0x0
	ldr r4, _08052500 @ =0x02039B84
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _080525AA
	adds r0, r5, #0x0
	adds r0, #0x2D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080525AA
	ldr r6, [r5, #0x3C]
	cmp r6, #0x00
	beq _08052504
	cmp r6, #0x01
	beq _08052564
	b _080525B2
_08052500: .4byte 0x02039B84
_08052504:
	ldr r0, _0805253C @ =0x00000133
	ldr r1, [r5, #0x20]
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #0x28]
	movs r7, #0x01
	str r7, [sp, #0x000]
	movs r4, #0x06
	str r4, [sp, #0x004]
	movs r4, #0x02
	str r4, [sp, #0x008]
	bl func_08011F78
	cmp r0, #0x00
	beq _08052544
	ldr r0, _08052540 @ =0x000002A3
	bl func_0811FE70
	strh r6, [r5, #0x2E]
	str r7, [r5, #0x3C]
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	ldr r2, [r5, #0x28]
	movs r3, #0x80
	lsls r3, r3, #0x05
	adds r2, r2, r3
	bl func_08013994
	b _080525B2
_0805253C: .4byte 0x00000133
_08052540: .4byte 0x000002A3
_08052544:
	adds r0, r5, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08052556
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x40]
	subs r0, r0, r1
	b _0805255C
_08052556:
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x40]
	adds r0, r0, r1
_0805255C:
	str r0, [r5, #0x20]
	ldrh r0, [r5, #0x2E]
	adds r0, #0x01
	b _080525B0
_08052564:
	movs r1, #0x2E
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	bne _08052578
	adds r0, r5, #0x0
	adds r0, #0x08
	movs r1, #0x01
	movs r2, #0x00
	bl func_080059A4
_08052578:
	ldr r0, [r4, #0x00]
	ldr r2, [r0, #0x7C]
	ldr r1, [r2, #0x04]
	ldr r0, [r5, #0x30]
	subs r1, r1, r0
	ldr r0, [r5, #0x20]
	adds r0, r0, r1
	str r0, [r5, #0x20]
	ldr r1, [r2, #0x08]
	ldr r0, [r5, #0x34]
	subs r1, r1, r0
	ldr r0, [r5, #0x24]
	adds r0, r0, r1
	str r0, [r5, #0x24]
	ldr r1, [r2, #0x0C]
	ldr r0, [r5, #0x38]
	subs r1, r1, r0
	ldr r0, [r5, #0x28]
	adds r0, r0, r1
	str r0, [r5, #0x28]
	ldrh r1, [r5, #0x2E]
	movs r2, #0x2E
	ldsh r0, [r5, r2]
	cmp r0, #0x1E
	ble _080525AE
_080525AA:
	movs r0, #0x00
	b _080525CE
_080525AE:
	adds r0, r1, #0x1
_080525B0:
	strh r0, [r5, #0x2E]
_080525B2:
	adds r0, r5, #0x0
	adds r0, #0x08
	bl func_08005A64
	ldr r0, _080525D8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x7C]
	ldr r0, [r1, #0x04]
	str r0, [r5, #0x30]
	ldr r0, [r1, #0x08]
	str r0, [r5, #0x34]
	ldr r0, [r1, #0x0C]
	str r0, [r5, #0x38]
	movs r0, #0x01
_080525CE:
	add sp, #0x00C
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080525D8: .4byte 0x02039B84
.syntax divided
