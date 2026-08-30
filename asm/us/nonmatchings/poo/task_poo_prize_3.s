.syntax unified
	.align 2, 0
	.global task_poo_prize_3
	.thumb
	.thumb_func
	.type task_poo_prize_3, %function
task_poo_prize_3: @ 080D1E88
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x6C]
	bl func_080028C0
	ldr r0, [r4, #0x70]
	bl func_08002C10
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08012304
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
