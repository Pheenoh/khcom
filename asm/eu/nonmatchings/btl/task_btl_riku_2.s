.syntax unified
	.text
	.align 2, 0
	.global task_btl_riku_2
	.thumb
	.thumb_func
	.type task_btl_riku_2, %function
task_btl_riku_2:
	.incbin "roms/B8CP.gba", 0x3257c, 0x368
.syntax divided
