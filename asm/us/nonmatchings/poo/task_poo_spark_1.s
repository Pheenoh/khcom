.syntax unified
	.align 2, 0
	.global task_poo_spark_1
	.thumb
	.thumb_func
	.type task_poo_spark_1, %function
task_poo_spark_1: @ 080D0970
	push {r4, lr}
	adds r4, r0, #0x0
	adds r4, #0x10
	adds r0, r4, #0x0
	bl func_08005A64
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D098C
	movs r0, #0x01
	b _080D098E
_080D098C:
	movs r0, #0x00
_080D098E:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
