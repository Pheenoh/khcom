.syntax unified
	.text
	.align 2, 0
	.global task_btl_riku_1
	.thumb
	.thumb_func
	.type task_btl_riku_1, %function
task_btl_riku_1:
	.incbin "roms/B8CP.gba", 0x2c4b0, 0x60cc
.syntax divided
