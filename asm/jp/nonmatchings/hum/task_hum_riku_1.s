.syntax unified
	.align 2, 0
	.global task_hum_riku_1
	.thumb
	.thumb_func
	.type task_hum_riku_1, %function
task_hum_riku_1:
	.incbin "roms/B8CJ.gba", 0x580d4, 0x1720
.syntax divided
