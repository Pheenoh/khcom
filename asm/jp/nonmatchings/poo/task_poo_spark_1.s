.syntax unified
	.align 2, 0
	.global task_poo_spark_1
	.thumb
	.thumb_func
	.type task_poo_spark_1, %function
task_poo_spark_1:
	.incbin "roms/B8CJ.gba", 0xd0a24, 0x24
.syntax divided
