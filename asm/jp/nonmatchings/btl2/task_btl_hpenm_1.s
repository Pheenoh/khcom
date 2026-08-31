.syntax unified
	.align 2, 0
	.global task_btl_hpenm_1
	.thumb
	.thumb_func
	.type task_btl_hpenm_1, %function
task_btl_hpenm_1:
	.incbin "roms/B8CJ.gba", 0x2fe94, 0x1a4
.syntax divided
