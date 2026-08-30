.syntax unified
	.align 2, 0
	.global task_bos_md_hahen_3
	.thumb
	.thumb_func
	.type task_bos_md_hahen_3, %function
task_bos_md_hahen_3: @ 080FD9A0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x18]
	bl func_08002C10
	ldr r0, [r4, #0x1C]
	bl func_080028C0
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
