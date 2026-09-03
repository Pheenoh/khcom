.syntax unified
	.text
	.align 2, 0
	.global task_btl_riku_1
	.thumb
	.thumb_func
	.type task_btl_riku_1, %function
task_btl_riku_1:
	.incbin "roms/B8CJ.gba", 0x28514, 0x60bc
.syntax divided
