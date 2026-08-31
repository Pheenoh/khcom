.syntax unified
	.align 2, 0
	.global task_hum_axcel_ptc_1
	.thumb
	.thumb_func
	.type task_hum_axcel_ptc_1, %function
task_hum_axcel_ptc_1:
	.incbin "roms/B8CJ.gba", 0x54294, 0x28
.syntax divided
