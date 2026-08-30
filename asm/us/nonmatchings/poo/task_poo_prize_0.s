.syntax unified
	.align 2, 0
	.global task_poo_prize_0
	.thumb
	.thumb_func
	.type task_poo_prize_0, %function
task_poo_prize_0: @ 080D1C40
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, [r5, #0x04]
	str r0, [r6, #0x00]
	ldr r0, [r5, #0x08]
	str r0, [r6, #0x04]
	ldr r0, [r5, #0x0C]
	str r0, [r6, #0x08]
	movs r0, #0x00
	str r0, [r6, #0x0C]
	bl func_080065A4
	adds r4, r6, #0x0
	adds r4, #0x84
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D1CD4 @ =0x00000301
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x02
	adds r0, r0, r1
	negs r0, r0
	str r0, [r4, #0x00]
	bl func_080065A4
	adds r4, #0x04
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x9B
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x99
	str r0, [r4, #0x00]
	bl func_080065A4
	adds r1, r6, #0x0
	adds r1, #0x8C
	strb r0, [r1, #0x00]
	ldr r0, _080D1CD8 @ =0x098A5CF4
	movs r1, #0xB0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r6, #0x6C]
	ldr r0, _080D1CDC @ =0x08F69BE4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x70]
	ldrh r1, [r5, #0x14]
	adds r0, r6, #0x0
	adds r0, #0x80
	strh r1, [r0, #0x00]
	ldrh r0, [r0, #0x00]
	cmp r0, #0x01
	beq _080D1CF4
	cmp r0, #0x01
	ble _080D1D04
	cmp r0, #0x02
	beq _080D1CE4
	cmp r0, #0x03
	bne _080D1D04
	ldr r0, _080D1CE0 @ =0x098A5CAE
	str r0, [r6, #0x74]
	adds r1, r6, #0x0
	adds r1, #0x94
	movs r0, #0x0A
	b _080D1D0E
_080D1CD4: .4byte 0x00000301
_080D1CD8: .4byte 0x098A5CF4
_080D1CDC: .4byte 0x08F69BE4
_080D1CE0: .4byte 0x098A5CAE
_080D1CE4:
	ldr r0, _080D1CF0 @ =0x098A5CA4
	str r0, [r6, #0x74]
	adds r1, r6, #0x0
	adds r1, #0x94
	movs r0, #0x04
	b _080D1D0E
_080D1CF0: .4byte 0x098A5CA4
_080D1CF4:
	ldr r0, _080D1D00 @ =0x098A5C9A
	str r0, [r6, #0x74]
	adds r1, r6, #0x0
	adds r1, #0x94
	movs r0, #0x0A
	b _080D1D0E
_080D1D00: .4byte 0x098A5C9A
_080D1D04:
	ldr r0, _080D1D64 @ =0x098A5C90
	str r0, [r6, #0x74]
	adds r1, r6, #0x0
	adds r1, #0x94
	movs r0, #0x03
_080D1D0E:
	strh r0, [r1, #0x00]
	ldr r0, _080D1D68 @ =0x098A5CB8
	str r0, [r6, #0x78]
	adds r0, r6, #0x0
	adds r0, #0x97
	movs r1, #0x00
	strb r1, [r0, #0x00]
	adds r2, r6, #0x0
	adds r2, #0x96
	movs r0, #0x01
	strb r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x82
	strh r1, [r0, #0x00]
	ldr r0, _080D1D6C @ =0x080D19C5
	str r0, [r6, #0x7C]
	adds r1, r6, #0x0
	adds r1, #0x90
	movs r0, #0x80
	lsls r0, r0, #0x01
	str r0, [r1, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	movs r1, #0x05
	movs r2, #0x10
	movs r3, #0x32
	bl func_080122AC
	ldr r1, [r6, #0x00]
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	adds r0, r4, #0x0
	bl func_08012324
	adds r0, r4, #0x0
	movs r1, #0x01
	bl func_08012614
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D1D64: .4byte 0x098A5C90
_080D1D68: .4byte 0x098A5CB8
_080D1D6C: .4byte 0x080D19C5
.syntax divided
