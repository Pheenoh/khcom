.syntax unified
	.align 2, 0
	.global task_poo_trap_0
	.thumb
	.thumb_func
	.type task_poo_trap_0, %function
task_poo_trap_0: @ 080CBB8C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x0C]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x10]
	movs r5, #0x00
	str r5, [r4, #0x14]
	ldr r0, _080CBBD0 @ =0x0972BD8C
	movs r1, #0x80
	lsls r1, r1, #0x01
	bl LoadObjTiles
	str r0, [r4, #0x00]
	ldr r0, _080CBBD4 @ =0x09849AB8
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	ldr r0, _080CBBD8 @ =0x0972BD78
	str r0, [r4, #0x08]
	adds r0, r4, #0x0
	adds r0, #0x1C
	ldr r1, [r4, #0x0C]
	ldr r2, [r4, #0x10]
	ldr r3, [r4, #0x14]
	bl func_08012324
	adds r4, #0x8C
	strb r5, [r4, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CBBD0: .4byte 0x0972BD8C
_080CBBD4: .4byte 0x09849AB8
_080CBBD8: .4byte 0x0972BD78
.syntax divided
