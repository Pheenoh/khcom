.syntax unified
	.align 2, 0
	.global task_hum_vixen_ndl_0
	.thumb
	.thumb_func
	.type task_hum_vixen_ndl_0, %function
task_hum_vixen_ndl_0: @ 080554A4
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _08055520 @ =0x08F6DCA4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	ldr r0, [r5, #0x18]
	str r0, [r6, #0x00]
	adds r4, r6, #0x0
	adds r4, #0x08
	ldr r1, _08055524 @ =0x09EE26B0
	ldr r2, _08055528 @ =0x09EE2690
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	ldrh r1, [r5, #0x12]
	adds r0, r6, #0x0
	adds r0, #0x2C
	movs r4, #0x00
	strb r1, [r0, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r6, #0x20]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x0B
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x08
	ldr r1, _0805552C @ =0xFFFFFB00
	adds r0, r0, r1
	ldr r1, [r5, #0x04]
	adds r1, r1, r0
	str r1, [r6, #0x24]
	ldr r0, [r5, #0x08]
	str r0, [r6, #0x28]
	adds r0, r6, #0x0
	adds r0, #0x2D
	strb r4, [r0, #0x00]
	ldr r0, _08055530 @ =0x00000286
	bl func_0811FE70
	bl func_080065A4
	movs r1, #0x01
	ands r1, r0
	cmp r1, #0x00
	beq _08055534
	adds r1, r6, #0x0
	adds r1, #0x2E
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _0805553A
_08055520: .4byte 0x08F6DCA4
_08055524: .4byte 0x09EE26B0
_08055528: .4byte 0x09EE2690
_0805552C: .4byte 0xFFFFFB00
_08055530: .4byte 0x00000286
_08055534:
	adds r0, r6, #0x0
	adds r0, #0x2E
	strb r1, [r0, #0x00]
_0805553A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
