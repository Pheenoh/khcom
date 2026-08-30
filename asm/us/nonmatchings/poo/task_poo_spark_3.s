.syntax unified
	.align 2, 0
	.global task_poo_spark_3
	.thumb
	.thumb_func
	.type task_poo_spark_3, %function
task_poo_spark_3: @ 080D09FC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x28]
	bl func_080028C0
	ldr r0, [r4, #0x2C]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
