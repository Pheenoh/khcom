.syntax unified
	.align 2, 0
	.global task_bos_tm_clb_2
	.thumb
	.thumb_func
	.type task_bos_tm_clb_2, %function
task_bos_tm_clb_2:
	.incbin "roms/B8CJ.gba", 0xbb408, 0xbc
.syntax divided
