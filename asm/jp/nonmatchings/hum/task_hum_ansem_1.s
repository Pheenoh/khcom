.syntax unified
	.text
	.align 2, 0
	.global task_hum_ansem_1
	.thumb
	.thumb_func
	.type task_hum_ansem_1, %function
task_hum_ansem_1:
	.incbin "roms/B8CJ.gba", 0x4d140, 0x1264
.syntax divided
