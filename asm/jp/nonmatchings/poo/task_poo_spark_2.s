.syntax unified
	.align 2, 0
	.global task_poo_spark_2
	.thumb
	.thumb_func
	.type task_poo_spark_2, %function
task_poo_spark_2:
	.incbin "roms/B8CJ.gba", 0xd0a48, 0x68
.syntax divided
