.syntax unified
	.align 2, 0
	.global task_emy_83_s_0
	.thumb
	.thumb_func
	.type task_emy_83_s_0, %function
task_emy_83_s_0: @ 0803EB20
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _0803EB70 @ =0x08F69B84
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r0, _0803EB74 @ =0x08B1D846
	movs r1, #0x40
	bl func_080026A4
	str r0, [r4, #0x00]
	ldr r0, [r5, #0x00]
	str r0, [r4, #0x08]
	ldr r0, [r5, #0x04]
	str r0, [r4, #0x0C]
	ldr r0, [r5, #0x08]
	str r0, [r4, #0x10]
	movs r0, #0x00
	str r0, [r4, #0x14]
	strh r0, [r4, #0x22]
	movs r1, #0x12
	ldsh r0, [r5, r1]
	cmp r0, #0x00
	beq _0803EB80
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803EB78 @ =0x000004CE
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803EB7C @ =0x00000133
	adds r0, r0, r1
	negs r0, r0
	b _0803EB96
	.byte 0x00, 0x00
_0803EB70: .4byte 0x08F69B84
_0803EB74: .4byte 0x08B1D846
_0803EB78: .4byte 0x000004CE
_0803EB7C: .4byte 0x00000133
_0803EB80:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803EBBC @ =0x000004CE
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803EBC0 @ =0x00000133
	adds r0, r0, r1
_0803EB96:
	str r0, [r4, #0x18]
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803EBC4 @ =0x00000201
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0803EBC8 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r4, #0x1C]
	ldrh r0, [r5, #0x14]
	strh r0, [r4, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803EBBC: .4byte 0x000004CE
_0803EBC0: .4byte 0x00000133
_0803EBC4: .4byte 0x00000201
_0803EBC8: .4byte 0xFFFFFF00
.syntax divided
