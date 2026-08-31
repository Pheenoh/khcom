.syntax unified
	.align 2, 0
	.global task_hum_vixen_frz_0
	.thumb
	.thumb_func
	.type task_hum_vixen_frz_0, %function
task_hum_vixen_frz_0: @ 08055990
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	ldr r0, _080559D4 @ =0x08F6DCA4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r5, #0x04]
	ldr r0, _080559D8 @ =0x02039B84
	ldr r2, [r0, #0x00]
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r2, r1
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x00]
	ldr r0, _080559DC @ =0x02039BB0
	ldr r1, [r0, #0x08]
	movs r0, #0x08
	ands r1, r0
	cmp r1, #0x00
	beq _080559E6
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x08
	movs r0, #0x00
	ands r1, r2
	orrs r0, r1
	cmp r0, #0x00
	beq _080559E0
	movs r0, #0x02
	strh r0, [r5, #0x32]
	b _080559E8
_080559D4: .4byte 0x08F6DCA4
_080559D8: .4byte 0x02039B84
_080559DC: .4byte 0x02039BB0
_080559E0:
	movs r0, #0x01
	strh r0, [r5, #0x32]
	b _080559E8
_080559E6:
	strh r1, [r5, #0x32]
_080559E8:
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	ldr r0, _08055A24 @ =0x0813F91C
	ldr r1, [r5, #0x00]
	str r1, [sp, #0x000]
	adds r1, r4, #0x0
	movs r2, #0x00
	movs r3, #0x00
	bl func_08019068
	movs r3, #0x00
	str r3, [r5, #0x2C]
	ldr r0, _08055A28 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08055A2C
	strh r3, [r5, #0x34]
	b _08055A30
_08055A24: .4byte 0x0813F91C
_08055A28: .4byte 0x02039B84
_08055A2C:
	movs r0, #0x01
	strh r0, [r5, #0x34]
_08055A30:
	movs r0, #0xFF
	lsls r0, r0, #0x01
	bl m4aSongNumStart
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x20]
	ldr r0, [r6, #0x04]
	str r0, [r5, #0x24]
	ldr r0, [r6, #0x08]
	str r0, [r5, #0x28]
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
