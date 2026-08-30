.syntax unified
	.align 2, 0
	.global task_bos_jf_borderline_1
	.thumb
	.thumb_func
	.type task_bos_jf_borderline_1, %function
task_bos_jf_borderline_1: @ 080C1558
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r4, [r5, #0x00]
	bl func_080C1A48
	adds r2, r5, #0x0
	adds r2, #0x98
	adds r1, r5, #0x0
	adds r1, #0xA4
	ldr r0, [r4, #0x04]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r2, #0x04
	adds r1, r5, #0x0
	adds r1, #0xA8
	ldr r0, [r4, #0x08]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x1C
	bl func_08005A64
	str r0, [r5, #0x0C]
	adds r0, r5, #0x0
	adds r0, #0x34
	bl func_08005A64
	str r0, [r5, #0x10]
	adds r0, r5, #0x0
	adds r0, #0x4C
	bl func_08005A64
	str r0, [r5, #0x14]
	adds r0, r5, #0x0
	adds r0, #0x64
	bl func_08005A64
	str r0, [r5, #0x18]
	adds r0, r5, #0x0
	adds r0, #0x80
	bl func_08005A64
	str r0, [r5, #0x7C]
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
