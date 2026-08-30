.syntax unified
	.align 2, 0
	.global task_wlogo_bks_obj_1
	.thumb
	.thumb_func
	.type task_wlogo_bks_obj_1, %function
task_wlogo_bks_obj_1: @ 080B7D6C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r1, r4, #0x0
	adds r1, #0x28
	movs r5, #0x00
	ldsb r5, [r1, r5]
	cmp r5, #0x00
	beq _080B7D82
	cmp r5, #0x01
	beq _080B7DDC
	b _080B7E08
_080B7D82:
	movs r2, #0x26
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	ble _080B7DD0
	adds r0, r4, #0x0
	adds r0, #0x2C
	ldr r1, [r4, #0x34]
	ldrh r2, [r4, #0x26]
	bl func_080058FC
	adds r0, r4, #0x0
	adds r0, #0x30
	ldr r1, [r4, #0x38]
	ldrh r2, [r4, #0x26]
	bl func_080058FC
	ldrh r0, [r4, #0x26]
	subs r0, #0x01
	strh r0, [r4, #0x26]
	adds r1, r4, #0x0
	adds r1, #0x46
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	ble _080B7DBC
	strh r5, [r1, #0x00]
_080B7DBC:
	ldr r0, _080B7DCC @ =0x09EF180C
	movs r3, #0x00
	ldsh r1, [r1, r3]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x3C]
	b _080B7E08
_080B7DCC: .4byte 0x09EF180C
_080B7DD0:
	strh r5, [r4, #0x24]
	strh r5, [r4, #0x26]
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	b _080B7E08
_080B7DDC:
	ldr r1, _080B7E00 @ =0x09EF1CEE
	adds r0, r4, #0x0
	adds r0, #0x29
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r2, [r4, #0x24]
	movs r3, #0x24
	ldsh r1, [r4, r3]
	movs r3, #0x00
	ldsh r0, [r0, r3]
	cmp r1, r0
	blt _080B7E04
	movs r0, #0x00
	b _080B7E0A
	.byte 0x00, 0x00
_080B7E00: .4byte 0x09EF1CEE
_080B7E04:
	adds r0, r2, #0x1
	strh r0, [r4, #0x24]
_080B7E08:
	movs r0, #0x01
_080B7E0A:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
