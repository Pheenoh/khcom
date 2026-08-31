.syntax unified
	.align 2, 0
	.global task_hum_axcel_3
	.thumb
	.thumb_func
	.type task_hum_axcel_3, %function
task_hum_axcel_3:
	.incbin "roms/B8CJ.gba", 0x541cc, 0x3c
.syntax divided
