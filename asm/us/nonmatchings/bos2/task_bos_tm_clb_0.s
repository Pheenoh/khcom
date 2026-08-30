.syntax unified
	.align 2, 0
	.global task_bos_tm_clb_0
	.thumb
	.thumb_func
	.type task_bos_tm_clb_0, %function
task_bos_tm_clb_0: @ 080BB228
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _080BB260 @ =0x09652E84
	movs r1, #0xEC
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r4, #0x04]
	ldr r0, _080BB264 @ =0x096FB2A4
	movs r1, #0x60
	bl func_08002A14
	str r0, [r4, #0x08]
	str r5, [r4, #0x00]
	ldr r1, [r5, #0x08]
	ldrh r0, [r1, #0x0C]
	strh r0, [r4, #0x0C]
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x10]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x14]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x18]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080BB260: .4byte 0x09652E84
_080BB264: .4byte 0x096FB2A4
.syntax divided
