.syntax unified
	.align 2, 0
	.global task_hum_laxene_knf_0
	.thumb
	.thumb_func
	.type task_hum_laxene_knf_0, %function
task_hum_laxene_knf_0: @ 08052414
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _0805245C @ =0x09618458
	movs r1, #0x20
	bl func_08002A14
	str r0, [r5, #0x04]
	ldr r0, _08052460 @ =0x08BD99F4
	movs r1, #0xB0
	lsls r1, r1, #0x02
	bl func_080026A4
	str r0, [r5, #0x00]
	adds r4, r5, #0x0
	adds r4, #0x08
	ldr r1, _08052464 @ =0x09EE1DB4
	ldr r2, _08052468 @ =0x09EE1DA4
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	movs r0, #0x12
	ldsh r1, [r6, r0]
	cmp r1, #0x00
	beq _0805246C
	adds r1, r5, #0x0
	adds r1, #0x2C
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _08052472
	.byte 0x00, 0x00
_0805245C: .4byte 0x09618458
_08052460: .4byte 0x08BD99F4
_08052464: .4byte 0x09EE1DB4
_08052468: .4byte 0x09EE1DA4
_0805246C:
	adds r0, r5, #0x0
	adds r0, #0x2C
	strb r1, [r0, #0x00]
_08052472:
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x28]
	movs r1, #0x00
	strh r1, [r5, #0x2E]
	adds r2, r5, #0x0
	adds r2, #0x2D
	movs r0, #0x01
	strb r0, [r2, #0x00]
	str r1, [r5, #0x3C]
	ldr r0, _080524C8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x7C]
	ldr r0, [r1, #0x04]
	str r0, [r5, #0x30]
	ldr r0, [r1, #0x08]
	str r0, [r5, #0x34]
	ldr r0, [r1, #0x0C]
	str r0, [r5, #0x38]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080524CC @ =0x00000381
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x04
	adds r0, r0, r1
	str r0, [r5, #0x40]
	movs r0, #0xA9
	lsls r0, r0, #0x02
	bl func_0811FE70
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080524C8: .4byte 0x02039B84
_080524CC: .4byte 0x00000381
.syntax divided
