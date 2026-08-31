.syntax unified
	.align 2, 0
	.global task_bos_boogie_disk_1
	.thumb
	.thumb_func
	.type task_bos_boogie_disk_1, %function
task_bos_boogie_disk_1: @ 080DADF4
	push {r4, r5, r6, lr}
	add sp, #-0x00C
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	adds r5, #0x40
	adds r0, r5, #0x0
	bl func_0801ADAC
	subs r0, #0x01
	cmp r0, #0x07
	bhi _080DAE3E
	lsls r0, r0, #0x02
	ldr r1, _080DAE14 @ =0x080DAE18
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_080DAE14: .4byte 0x080DAE18
	.byte 0x4E, 0xAE, 0x0D, 0x08, 0x3E, 0xAE, 0x0D, 0x08, 0x4E, 0xAE, 0x0D, 0x08, 0x4E, 0xAE, 0x0D, 0x08
	.byte 0x38, 0xAE, 0x0D, 0x08, 0x4E, 0xAE, 0x0D, 0x08, 0x4E, 0xAE, 0x0D, 0x08, 0x4E, 0xAE, 0x0D, 0x08
	.byte 0x00, 0x20, 0x30, 0x60, 0x0D, 0xE0
_080DAE3E:
	movs r0, #0x00
	bl func_0801C1C0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DAE5C
	bl func_080D9A58
	ldr r0, [r6, #0x00]
	cmp r0, #0x01
	beq _080DAE5C
	movs r0, #0x01
	str r0, [r6, #0x00]
	movs r0, #0x00
	strh r0, [r6, #0x04]
_080DAE5C:
	ldr r1, [r6, #0x00]
	cmp r1, #0x01
	beq _080DAEF8
	cmp r1, #0x01
	bcc _080DAE6C
	cmp r1, #0x02
	beq _080DAF50
	b _080DAF62
_080DAE6C:
	movs r0, #0xAC
	lsls r0, r0, #0x01
	adds r4, r6, r0
	ldr r0, [r5, #0x08]
	ldr r1, [r4, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x08]
	adds r0, r5, #0x4
	adds r1, r5, #0x0
	adds r1, #0x08
	movs r3, #0x10
	negs r3, r3
	ldr r2, [r5, #0x0C]
	str r2, [sp, #0x000]
	movs r2, #0x20
	bl func_080DABFC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DAE9A
	ldr r0, [r4, #0x00]
	negs r0, r0
	str r0, [r4, #0x00]
_080DAE9A:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r6, r0
	ldr r1, [r5, #0x04]
	ldr r0, [r2, #0x00]
	adds r1, r1, r0
	str r1, [r5, #0x04]
	ldr r0, [r2, #0x00]
	cmp r0, #0x00
	ble _080DAEB8
	movs r0, #0xC8
	lsls r0, r0, #0x09
	cmp r1, r0
	bgt _080DAF02
	b _080DAEBE
_080DAEB8:
	ldr r0, _080DAEE8 @ =0x00005FFF
	cmp r1, r0
	ble _080DAF02
_080DAEBE:
	ldr r0, _080DAEEC @ =0x00000105
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	movs r4, #0x20
	str r4, [sp, #0x000]
	movs r4, #0x10
	str r4, [sp, #0x004]
	movs r4, #0x01
	str r4, [sp, #0x008]
	bl func_08011F78
	adds r1, r0, #0x0
	cmp r1, #0x01
	bne _080DAF62
	ldr r0, _080DAEF0 @ =0x0203C56C
	strb r1, [r0, #0x00]
	ldr r0, _080DAEF4 @ =0x0000022F
	bl m4aSongNumStart
	b _080DAF62
_080DAEE8: .4byte 0x00005FFF
_080DAEEC: .4byte 0x00000105
_080DAEF0: .4byte 0x0203C56C
_080DAEF4: .4byte 0x0000022F
_080DAEF8:
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _080DAF10
	ldr r0, _080DAF0C @ =0x0203C570
	strb r1, [r0, #0x00]
_080DAF02:
	adds r0, r5, #0x0
	bl func_0801AF08
	movs r0, #0x00
	b _080DAF82
_080DAF0C: .4byte 0x0203C570
_080DAF10:
	ldrh r0, [r6, #0x04]
	adds r0, #0x01
	strh r0, [r6, #0x04]
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r0, [r5, #0x04]
	ldr r1, [r1, #0x00]
	subs r0, r0, r1
	str r0, [r5, #0x04]
	movs r0, #0xAE
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldrb r0, [r1, #0x00]
	adds r0, #0x19
	strb r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r2, r6, r0
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldr r0, [r2, #0x00]
	adds r0, #0x42
	str r0, [r2, #0x00]
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	ble _080DAF62
	movs r0, #0x00
	str r0, [r5, #0x0C]
	b _080DAF62
_080DAF50:
	ldrh r1, [r6, #0x04]
	movs r2, #0x04
	ldsh r0, [r6, r2]
	cmp r0, #0x1E
	ble _080DAF5E
	movs r0, #0x00
	b _080DAF82
_080DAF5E:
	adds r0, r1, #0x1
	strh r0, [r6, #0x04]
_080DAF62:
	adds r0, r6, #0x0
	adds r0, #0x14
	bl AnimUpdate
	adds r0, r5, #0x0
	adds r0, #0x40
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x0C]
	bl func_08012324
	adds r0, r6, #0x0
	adds r0, #0x2C
	bl TaskPoolUpdate
	movs r0, #0x01
_080DAF82:
	add sp, #0x00C
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
