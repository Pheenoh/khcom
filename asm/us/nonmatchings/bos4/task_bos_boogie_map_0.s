.syntax unified
	.align 2, 0
	.global task_bos_boogie_map_0
	.thumb
	.thumb_func
	.type task_bos_boogie_map_0, %function
task_bos_boogie_map_0: @ 080DAA28
	push {r4, lr}
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
	movs r3, #0x02
	bl func_0800516C
	ldr r4, _080DAA98 @ =0x02039B84
	ldr r0, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	movs r2, #0xF8
	lsls r2, r2, #0x08
	str r2, [r0, #0x08]
	movs r1, #0x84
	lsls r1, r1, #0x0A
	str r1, [r0, #0x0C]
	str r2, [r0, #0x00]
	str r1, [r0, #0x04]
	str r2, [r0, #0x10]
	str r1, [r0, #0x14]
	str r2, [r0, #0x1C]
	str r1, [r0, #0x20]
	movs r2, #0x00
	movs r1, #0x0F
	strh r1, [r0, #0x1A]
	strb r2, [r0, #0x18]
	bl func_0802F1C8
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	ldr r2, [r0, #0x04]
	lsls r2, r2, #0x08
	lsrs r2, r2, #0x10
	movs r0, #0x00
	bl func_08005244
	pop {r4}
	pop {r0}
	bx r0
_080DAA98: .4byte 0x02039B84
.syntax divided
