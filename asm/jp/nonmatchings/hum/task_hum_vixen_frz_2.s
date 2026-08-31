.syntax unified
	.align 2, 0
	.global task_hum_vixen_frz_2
	.thumb
	.thumb_func
	.type task_hum_vixen_frz_2, %function
task_hum_vixen_frz_2:
	.incbin "roms/B8CJ.gba", 0x55dac, 0x74
.syntax divided
