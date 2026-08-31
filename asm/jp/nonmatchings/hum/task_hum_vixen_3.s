.syntax unified
	.align 2, 0
	.global task_hum_vixen_3
	.thumb
	.thumb_func
	.type task_hum_vixen_3, %function
task_hum_vixen_3:
	.incbin "roms/B8CJ.gba", 0x55464, 0x40
.syntax divided
