.syntax unified
	.align 2, 0
	.global task_hum_vixen_frg_1
	.thumb
	.thumb_func
	.type task_hum_vixen_frg_1, %function
task_hum_vixen_frg_1:
	.incbin "roms/B8CJ.gba", 0x55f38, 0xc4
.syntax divided
