.syntax unified
	.text
	.align 2, 0
	.global task_btl_hpenm_2
	.thumb
	.thumb_func
	.type task_btl_hpenm_2, %function
task_btl_hpenm_2:
	.incbin "roms/B8CP.gba", 0x33f74, 0x3d4
.syntax divided
