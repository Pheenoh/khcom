.syntax unified
	.align 2, 0
	.global task_hum_axcel_2
	.thumb
	.thumb_func
	.type task_hum_axcel_2, %function
task_hum_axcel_2:
	.incbin "roms/B8CJ.gba", 0x54198, 0x34
.syntax divided
