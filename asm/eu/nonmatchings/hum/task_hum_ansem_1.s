.syntax unified
	.text
	.align 2, 0
	.global task_hum_ansem_1
	.thumb
	.thumb_func
	.type task_hum_ansem_1, %function
task_hum_ansem_1:
	.incbin "roms/B8CP.gba", 0x515a0, 0x1264
.syntax divided
