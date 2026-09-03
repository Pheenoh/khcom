.syntax unified
	.text
	.align 2, 0
	.global task_hum_hades_1
	.thumb
	.thumb_func
	.type task_hum_hades_1, %function
task_hum_hades_1:
	.incbin "roms/B8CJ.gba", 0x4e590, 0x1148
.syntax divided
