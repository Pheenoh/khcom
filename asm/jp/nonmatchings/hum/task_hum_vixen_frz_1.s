.syntax unified
	.align 2, 0
	.global task_hum_vixen_frz_1
	.thumb
	.thumb_func
	.type task_hum_vixen_frz_1, %function
task_hum_vixen_frz_1:
	.incbin "roms/B8CJ.gba", 0x55a4c, 0x360
.syntax divided
