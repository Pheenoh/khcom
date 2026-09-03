.syntax unified
	.text
	.align 2, 0
	.global task_hum_hades_1
	.thumb
	.thumb_func
	.type task_hum_hades_1, %function
task_hum_hades_1:
	.incbin "roms/B8CP.gba", 0x529f0, 0x10f4
.syntax divided
