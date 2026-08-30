.syntax unified
	.align 2, 0
	.global task_bos_md_fire_3
	.thumb
	.thumb_func
	.type task_bos_md_fire_3, %function
task_bos_md_fire_3: @ 080FD3F0
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x78
	bl func_08012304
	adds r0, r4, #0x0
	adds r0, #0x38
	bl func_0801B7D8
	ldr r0, [r4, #0x0C]
	bl func_08002C10
	ldr r0, [r4, #0x10]
	bl func_08002C10
	ldr r0, [r4, #0x14]
	bl func_080028C0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
