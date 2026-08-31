.syntax unified
	.align 2, 0
	.global task_bos_pc_fld_0
	.thumb
	.thumb_func
	.type task_bos_pc_fld_0, %function
task_bos_pc_fld_0: @ 0810B524
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	ldr r1, [r4, #0x00]
	ldrh r2, [r4, #0x04]
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, [r4, #0x08]
	ldrh r2, [r4, #0x0C]
	movs r0, #0x00
	bl LoadBgPalette
	adds r4, #0x10
	movs r0, #0x00
	adds r1, r4, #0x0
	movs r2, #0x02
	movs r3, #0x03
	bl func_0800516C
	ldr r4, _0810B5D0 @ =0x02039B84
	ldr r0, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	movs r2, #0x8A
	lsls r2, r2, #0x09
	str r2, [r0, #0x08]
	ldr r1, _0810B5D4 @ =0x00015300
	str r1, [r0, #0x0C]
	str r2, [r0, #0x00]
	str r1, [r0, #0x04]
	str r2, [r0, #0x10]
	str r1, [r0, #0x14]
	str r2, [r0, #0x1C]
	str r1, [r0, #0x20]
	movs r2, #0x00
	movs r6, #0x00
	movs r1, #0x0F
	strh r1, [r0, #0x1A]
	strb r2, [r0, #0x18]
	bl func_0802F1C8
	bl func_0810B3E4
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	ldr r2, [r0, #0x04]
	lsls r2, r2, #0x08
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	adds r0, r5, #0x0
	bl func_0810B4A8
	adds r0, r5, #0x0
	bl func_0810B4B4
	str r6, [r5, #0x08]
	str r6, [r5, #0x0C]
	adds r5, #0x10
	adds r0, r5, #0x0
	movs r1, #0x06
	movs r2, #0x28
	movs r3, #0x08
	bl func_080122AC
	movs r1, #0xBA
	lsls r1, r1, #0x09
	movs r2, #0xAA
	lsls r2, r2, #0x09
	adds r0, r5, #0x0
	movs r3, #0x00
	bl func_08012324
	adds r0, r5, #0x0
	movs r1, #0x01
	bl func_08012614
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0810B5D0: .4byte 0x02039B84
_0810B5D4: .4byte 0x00015300
.syntax divided
