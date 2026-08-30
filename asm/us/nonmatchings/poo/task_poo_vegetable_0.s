.syntax unified
	.align 2, 0
	.global task_poo_vegetable_0
	.thumb
	.thumb_func
	.type task_poo_vegetable_0, %function
task_poo_vegetable_0: @ 080CFCD4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	movs r0, #0xD6
	lsls r0, r0, #0x09
	str r0, [r4, #0x24]
	movs r0, #0xC0
	lsls r0, r0, #0x09
	str r0, [r4, #0x28]
	movs r5, #0x00
	str r5, [r4, #0x2C]
	str r5, [r4, #0x30]
	ldr r0, _080CFD10 @ =0x09EF602C
	movs r1, #0x01
	bl func_08003524
	strh r0, [r4, #0x34]
	str r5, [r4, #0x04]
	ldr r0, _080CFD14 @ =0x09756C50
	str r0, [r4, #0x08]
	adds r0, r4, #0x0
	adds r0, #0x38
	ldr r1, [r4, #0x24]
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x2C]
	bl func_08012324
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CFD10: .4byte 0x09EF602C
_080CFD14: .4byte 0x09756C50
.syntax divided
