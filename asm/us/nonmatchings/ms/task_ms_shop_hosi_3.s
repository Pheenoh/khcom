.syntax unified
	.align 2, 0
	.global task_ms_shop_hosi_3
	.thumb
	.thumb_func
	.type task_ms_shop_hosi_3, %function
task_ms_shop_hosi_3: @ 08109614
	push {lr}
	ldr r0, [r0, #0x1C]
	bl func_080028C0
	pop {r0}
	bx r0
.syntax divided
