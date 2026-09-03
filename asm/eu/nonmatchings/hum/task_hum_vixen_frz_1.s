.syntax unified
	.text
	.align 2, 0
	.global task_hum_vixen_frz_1
	.thumb
	.thumb_func
	.type task_hum_vixen_frz_1, %function
task_hum_vixen_frz_1:
	.incbin "roms/B8CP.gba", 0x59ea8, 0x360
.syntax divided
