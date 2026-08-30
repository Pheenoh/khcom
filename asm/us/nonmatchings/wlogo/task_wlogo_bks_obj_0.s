.syntax unified
	.align 2, 0
	.global task_wlogo_bks_obj_0
	.thumb
	.thumb_func
	.type task_wlogo_bks_obj_0, %function
task_wlogo_bks_obj_0: @ 080B7C98
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	adds r6, #0x29
	movs r2, #0x00
	strb r1, [r6, #0x00]
	ldr r1, _080B7D50 @ =0x09EF1CB6
	movs r0, #0x00
	ldsb r0, [r6, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x08
	str r0, [r5, #0x2C]
	movs r0, #0x00
	ldsb r0, [r6, r0]
	lsls r0, r0, #0x02
	adds r1, #0x02
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	str r0, [r5, #0x30]
	ldr r1, _080B7D54 @ =0x09EF1C7E
	movs r0, #0x00
	ldsb r0, [r6, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	movs r3, #0x00
	ldsh r0, [r0, r3]
	lsls r0, r0, #0x08
	str r0, [r5, #0x34]
	movs r0, #0x00
	ldsb r0, [r6, r0]
	lsls r0, r0, #0x02
	adds r1, #0x02
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x08
	str r0, [r5, #0x38]
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r5, #0x3C]
	str r0, [r5, #0x40]
	movs r4, #0x00
	strh r2, [r5, #0x24]
	movs r0, #0x1E
	strh r0, [r5, #0x26]
	adds r0, r5, #0x0
	adds r0, #0x28
	strb r4, [r0, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x46
	movs r0, #0x0A
	strh r0, [r1, #0x00]
	ldr r0, _080B7D58 @ =0x09628DC0
	movs r1, #0x80
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r5, #0x00]
	ldr r0, _080B7D5C @ =0x096FB0A4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	ldr r2, _080B7D60 @ =0x09EF380C
	ldr r1, _080B7D64 @ =0x09EF1C70
	movs r0, #0x00
	ldsb r0, [r6, r0]
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x08]
	ldr r1, _080B7D68 @ =0x09EF1D0A
	movs r0, #0x00
	ldsb r0, [r6, r0]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x48
	strh r1, [r0, #0x00]
	subs r0, #0x04
	strb r4, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B7D50: .4byte 0x09EF1CB6
_080B7D54: .4byte 0x09EF1C7E
_080B7D58: .4byte 0x09628DC0
_080B7D5C: .4byte 0x096FB0A4
_080B7D60: .4byte 0x09EF380C
_080B7D64: .4byte 0x09EF1C70
_080B7D68: .4byte 0x09EF1D0A
.syntax divided
