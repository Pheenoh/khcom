.syntax unified
	.align 2, 0
	.global task_wlogo_tt_line_1
	.thumb
	.thumb_func
	.type task_wlogo_tt_line_1, %function
task_wlogo_tt_line_1: @ 080B7768
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	movs r2, #0x04
	ldsb r2, [r5, r2]
	cmp r2, #0x00
	beq _080B777E
	cmp r2, #0x01
	beq _080B77F8
	movs r0, #0x00
	b _080B7818
_080B777E:
	ldr r4, _080B77EC @ =0x09EF1B68
	movs r0, #0x02
	ldsh r1, [r5, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x01
	adds r1, r4, #0x4
	adds r0, r0, r1
	ldrh r3, [r5, #0x00]
	movs r6, #0x00
	ldsh r1, [r5, r6]
	movs r6, #0x00
	ldsh r0, [r0, r6]
	cmp r1, r0
	bne _080B77F4
	strh r2, [r5, #0x00]
	movs r0, #0x02
	ldsh r1, [r5, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	str r0, [sp, #0x000]
	movs r2, #0x02
	ldsh r1, [r5, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x01
	adds r1, r4, #0x2
	adds r0, r0, r1
	movs r6, #0x00
	ldsh r0, [r0, r6]
	lsls r0, r0, #0x08
	str r0, [sp, #0x004]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _080B77F0 @ =0x09EF1B50
	adds r0, r4, #0x0
	mov r2, sp
	bl TaskCreate
	ldrh r0, [r5, #0x02]
	adds r0, #0x01
	strh r0, [r5, #0x02]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1F
	bne _080B7810
	ldrb r0, [r5, #0x04]
	adds r0, #0x01
	strb r0, [r5, #0x04]
	b _080B7810
_080B77EC: .4byte 0x09EF1B68
_080B77F0: .4byte 0x09EF1B50
_080B77F4:
	adds r0, r3, #0x1
	b _080B780A
_080B77F8:
	ldrh r1, [r5, #0x00]
	movs r2, #0x00
	ldsh r0, [r5, r2]
	cmp r0, #0x1D
	ble _080B7808
	ldrb r0, [r5, #0x04]
	adds r0, #0x01
	strb r0, [r5, #0x04]
_080B7808:
	adds r0, r1, #0x1
_080B780A:
	strh r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x08
_080B7810:
	adds r0, r4, #0x0
	bl TaskPoolUpdate
	movs r0, #0x01
_080B7818:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
