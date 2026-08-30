.syntax unified
	.align 2, 0
	.global task_bos_pc_flt_3
	.thumb
	.thumb_func
	.type task_bos_pc_flt_3, %function
task_bos_pc_flt_3: @ 0810BEF8
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x40
	bl func_08012304
	ldr r0, [r4, #0x34]
	bl func_080028C0
	ldr r0, [r4, #0x38]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47, 0x01, 0x1C, 0x41, 0x43, 0x08, 0x1C, 0x70, 0x47
.syntax divided
