.syntax unified
	.align 2, 0
	.global task_emy_08_0
	.thumb
	.thumb_func
	.type task_emy_08_0, %function
task_emy_08_0: @ 08038298
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _080382CC @ =0x0813D804
	bl func_0800C778
	ldr r0, _080382D0 @ =0x08F698C4
	movs r1, #0x20
	bl LoadObjPalette
	movs r2, #0xC2
	lsls r2, r2, #0x01
	adds r1, r4, r2
	str r0, [r1, #0x00]
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, [r4, #0x04]
	str r0, [r1, #0x00]
	adds r2, #0x08
	adds r1, r4, r2
	movs r0, #0x00
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080382CC: .4byte 0x0813D804
_080382D0: .4byte 0x08F698C4
.syntax divided
