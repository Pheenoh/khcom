.syntax unified
	.align 2, 0
	.global task_bos_tm_body_0
	.thumb
	.thumb_func
	.type task_bos_tm_body_0, %function
task_bos_tm_body_0: @ 080B9660
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _080B97CC @ =0x09652E84
	movs r1, #0xEC
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r6, #0x04]
	ldr r0, _080B97D0 @ =0x096FB2A4
	movs r1, #0x60
	bl func_08002A14
	str r0, [r6, #0x08]
	ldr r0, _080B97D4 @ =0x08F69BC4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x0C]
	movs r0, #0x92
	lsls r0, r0, #0x01
	adds r1, r6, r0
	ldr r0, _080B97D8 @ =0x09EF3950
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r2, #0x90
	lsls r2, r2, #0x02
	adds r1, r6, r2
	ldr r0, _080B97DC @ =0x09EF3958
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r3, #0xD7
	lsls r3, r3, #0x02
	adds r1, r6, r3
	ldr r0, _080B97E0 @ =0x09EF397C
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	movs r4, #0x8F
	lsls r4, r4, #0x03
	adds r1, r6, r4
	ldr r0, _080B97E4 @ =0x09EF3960
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	str r5, [r6, #0x00]
	ldr r2, [r6, #0x04]
	ldrh r1, [r2, #0x06]
	adds r0, r5, #0x0
	adds r0, #0x40
	movs r3, #0x00
	movs r4, #0x00
	strh r1, [r0, #0x00]
	adds r5, #0x42
	ldrh r0, [r2, #0x08]
	ldrh r1, [r5, #0x00]
	adds r0, r0, r1
	strh r0, [r5, #0x00]
	ldr r0, [r6, #0x00]
	ldr r1, [r6, #0x08]
	ldrh r1, [r1, #0x06]
	adds r0, #0x44
	strh r1, [r0, #0x00]
	movs r2, #0x90
	lsls r2, r2, #0x03
	adds r0, r6, r2
	strh r4, [r0, #0x00]
	ldr r1, _080B97E8 @ =0x00000482
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	adds r2, #0x04
	adds r0, r6, r2
	strh r4, [r0, #0x00]
	adds r1, #0x04
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	movs r2, #0x94
	lsls r2, r2, #0x01
	adds r0, r6, r2
	strb r3, [r0, #0x00]
	movs r1, #0x91
	lsls r1, r1, #0x02
	adds r0, r6, r1
	strb r3, [r0, #0x00]
	movs r2, #0xD8
	lsls r2, r2, #0x02
	adds r0, r6, r2
	strb r3, [r0, #0x00]
	ldr r1, _080B97EC @ =0x0000047C
	adds r0, r6, r1
	strb r3, [r0, #0x00]
	movs r2, #0x91
	lsls r2, r2, #0x03
	adds r0, r6, r2
	strb r3, [r0, #0x00]
	ldr r3, _080B97F0 @ =0x0000048A
	adds r0, r6, r3
	adds r1, #0x98
	strh r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r6, r2
	strh r1, [r0, #0x00]
	adds r3, #0x04
	adds r0, r6, r3
	strh r4, [r0, #0x00]
	movs r0, #0x92
	lsls r0, r0, #0x03
	adds r1, r6, r0
	movs r0, #0x0A
	strb r0, [r1, #0x00]
	ldr r1, _080B97F4 @ =0x00000492
	adds r0, r6, r1
	strh r4, [r0, #0x00]
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x28]
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080B97F8
	adds r0, r6, #0x0
	adds r0, #0x10
	ldrh r1, [r3, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r4, #0x02
	ldsh r2, [r3, r4]
	ldrh r3, [r3, #0x04]
	subs r3, #0x22
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080B83A4
	movs r1, #0x96
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r3, [r6, #0x00]
	movs r2, #0x00
	ldsh r1, [r3, r2]
	movs r4, #0x02
	ldsh r2, [r3, r4]
	ldrh r3, [r3, #0x04]
	adds r3, #0x09
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080B83A4
	movs r1, #0x92
	lsls r1, r1, #0x02
	adds r0, r6, r1
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	adds r1, #0x0C
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	adds r2, #0x01
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x21
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080B83A4
	movs r2, #0xD9
	lsls r2, r2, #0x02
	adds r0, r6, r2
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	subs r2, #0x04
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x1E
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080B83A4
	b _080B9886
_080B97CC: .4byte 0x09652E84
_080B97D0: .4byte 0x096FB2A4
_080B97D4: .4byte 0x08F69BC4
_080B97D8: .4byte 0x09EF3950
_080B97DC: .4byte 0x09EF3958
_080B97E0: .4byte 0x09EF397C
_080B97E4: .4byte 0x09EF3960
_080B97E8: .4byte 0x00000482
_080B97EC: .4byte 0x0000047C
_080B97F0: .4byte 0x0000048A
_080B97F4: .4byte 0x00000492
_080B97F8:
	adds r0, r6, #0x0
	adds r0, #0x10
	ldrh r1, [r3, #0x00]
	adds r1, #0x04
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r4, #0x02
	ldsh r2, [r3, r4]
	ldrh r3, [r3, #0x04]
	subs r3, #0x22
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080B83A4
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r4, r6, r0
	ldr r0, [r6, #0x00]
	movs r2, #0x00
	ldsh r1, [r0, r2]
	movs r3, #0x02
	ldsh r2, [r0, r3]
	ldrh r3, [r0, #0x04]
	subs r3, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	adds r0, r4, #0x0
	bl func_080B8334
	movs r1, #0x92
	lsls r1, r1, #0x02
	adds r0, r6, r1
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	adds r1, #0x0C
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	adds r2, #0x01
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x21
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080B83A4
	movs r2, #0xD9
	lsls r2, r2, #0x02
	adds r0, r6, r2
	ldr r3, [r6, #0x00]
	ldrh r1, [r3, #0x00]
	subs r1, #0x01
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r3, #0x02]
	subs r2, #0x04
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldrh r3, [r3, #0x04]
	subs r3, #0x1E
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	bl func_080B83A4
	ldr r0, _080B988C @ =0x0203AB50
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r1, r4, #0x0
	bl _0811F030
_080B9886:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B988C: .4byte 0x0203AB50
.syntax divided
