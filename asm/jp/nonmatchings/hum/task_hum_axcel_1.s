.syntax unified
	.align 2, 0
	.global task_hum_axcel_1
	.thumb
	.thumb_func
	.type task_hum_axcel_1, %function
task_hum_axcel_1:
	.incbin "roms/B8CJ.gba", 0x52884, 0x187c
.syntax divided
