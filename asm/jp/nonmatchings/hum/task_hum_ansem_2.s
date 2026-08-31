.syntax unified
	.align 2, 0
	.global task_hum_ansem_2
	.thumb
	.thumb_func
	.type task_hum_ansem_2, %function
task_hum_ansem_2:
	.incbin "roms/B8CJ.gba", 0x4e3a4, 0xc
.syntax divided
