.syntax unified
	.text
	.align 2, 0
	.global task_hum_riku_1
	.thumb
	.thumb_func
	.type task_hum_riku_1, %function
task_hum_riku_1:
	.incbin "roms/B8CP.gba", 0x5c560, 0x1720
.syntax divided
