.syntax unified
	.align 2, 0
	.global task_btl_riku_2
	.thumb
	.thumb_func
	.type task_btl_riku_2, %function
task_btl_riku_2:
	.incbin "roms/B8CJ.gba", 0x2e5d0, 0x368
.syntax divided
