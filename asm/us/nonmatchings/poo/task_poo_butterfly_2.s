.syntax unified
	.align 2, 0
	.global task_poo_butterfly_2
	.thumb
	.thumb_func
	.type task_poo_butterfly_2, %function
task_poo_butterfly_2: @ 080D22B4
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0xD0
	ldr r1, [r5, #0x00]
	bl func_080D220C
	adds r4, #0x68
	ldr r1, [r5, #0x00]
	adds r0, r4, #0x0
	bl func_080D220C
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
