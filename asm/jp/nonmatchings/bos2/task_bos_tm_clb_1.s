.syntax unified
	.align 2, 0
	.global task_bos_tm_clb_1
	.thumb
	.thumb_func
	.type task_bos_tm_clb_1, %function
task_bos_tm_clb_1:
	.incbin "roms/B8CJ.gba", 0xbb31c, 0xec
.syntax divided
